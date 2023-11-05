"use strict";
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (this && this.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.UserService = void 0;
const common_1 = require("@nestjs/common");
const prisma_service_1 = require("../prisma/prisma.service");
let UserService = class UserService {
    constructor(prisma) {
        this.prisma = prisma;
    }
    async findOneByUsername(username) {
        return this.prisma.user.findUnique({ where: { username: username } });
    }
    async getIdByLogin(login) {
        const user = await this.prisma.user.findFirst({
            where: {
                login,
            }
        });
        return (user.id);
    }
    async getLoginById(id) {
        const user = await this.prisma.user.findUniqueOrThrow({
            where: {
                id,
            }
        });
        return (user.login);
    }
    async getUser(login) {
        const user = await this.prisma.user.findUniqueOrThrow({
            where: {
                login: login,
            }
        });
        return (user);
    }
    async addFriend(login, target) {
        const senderId = await this.getIdByLogin(login);
        const targetId = await this.getIdByLogin(target);
        const test = await this.prisma.userConnection.findMany({
            where: {
                targetId,
                fromId: senderId,
                followed: 1,
            }
        });
        if (test.length > 0) {
            console.log("already friends: throw");
            throw new Error("Already friend");
        }
        const userco = await this.prisma.userConnection.updateMany({
            where: {
                targetId,
                fromId: senderId,
            },
            data: {
                followed: 1
            }
        });
        console.log(userco.count);
        if (!userco.count) {
            console.log("je cree un userco !");
            const newUserCo = await this.prisma.userConnection.create({
                data: {
                    targetId,
                    fromId: senderId,
                    blocked: 0,
                    followed: 1,
                }
            });
        }
        const added = await this.prisma.user.findUniqueOrThrow({
            where: {
                login: target,
            }
        });
        return (added);
    }
    async delFriend(login, target) {
        const senderId = await this.getIdByLogin(login);
        const targetId = await this.getIdByLogin(target);
        const test = await this.prisma.userConnection.findMany({
            where: {
                targetId,
                fromId: senderId,
                followed: 0,
            }
        });
        if (test.length > 0) {
            console.log("already not friends: throw");
            throw new Error("Already  not friend");
        }
        const userco = await this.prisma.userConnection.updateMany({
            where: {
                targetId,
                fromId: senderId,
            },
            data: {
                followed: 0,
            }
        });
        const added = await this.prisma.user.findUniqueOrThrow({
            where: {
                login: target,
            }
        });
        return (added);
    }
    async blockUser(login, target) {
        const senderId = await this.getIdByLogin(login);
        const targetId = await this.getIdByLogin(target);
        const test = await this.prisma.userConnection.findMany({
            where: {
                targetId,
                fromId: senderId,
                blocked: 1,
            }
        });
        if (test.length > 0) {
            console.log("already blocked: throw");
            throw new Error("Already blocked");
        }
        const userco = await this.prisma.userConnection.updateMany({
            where: {
                targetId,
                fromId: senderId,
            },
            data: {
                blocked: 1
            }
        });
        if (!userco) {
            const newUserCo = await this.prisma.userConnection.create({
                data: {
                    targetId,
                    fromId: senderId,
                    blocked: 1,
                    followed: 0,
                }
            });
        }
        const blocked = await this.prisma.user.findUniqueOrThrow({
            where: {
                login: target,
            }
        });
        return (blocked);
    }
    async unblockUser(login, target) {
        const senderId = await this.getIdByLogin(login);
        const targetId = await this.getIdByLogin(target);
        const test = await this.prisma.userConnection.findMany({
            where: {
                targetId,
                fromId: senderId,
                blocked: 0,
            }
        });
        if (test.length > 0) {
            console.log("already unblocked: throw");
            throw new Error("Already unblocked");
        }
        const userco = await this.prisma.userConnection.updateMany({
            where: {
                targetId,
                fromId: senderId,
            },
            data: {
                blocked: 0
            }
        });
        const blocked = await this.prisma.user.findUniqueOrThrow({
            where: {
                login: target,
            }
        });
        return (blocked);
    }
    async getFriends(login) {
        const user = await this.prisma.user.findUniqueOrThrow({
            where: {
                login,
            },
            include: {
                userConnections: {
                    where: {
                        followed: 1
                    },
                    select: {
                        targetId: true,
                    }
                }
            }
        });
        const usersPromises = user.userConnections.map(async (connection) => {
            const targetId = connection.targetId;
            return this.getLoginById(targetId);
        });
        const users = await Promise.all(usersPromises);
        return (users);
    }
    async getBlocked(login) {
        const user = await this.prisma.user.findUniqueOrThrow({
            where: {
                login,
            },
            include: {
                userConnections: {
                    where: {
                        blocked: 1
                    },
                    select: {
                        targetId: true,
                    }
                }
            }
        });
        const usersPromises = user.userConnections.map(async (connection) => {
            const targetId = connection.targetId;
            return this.getLoginById(targetId);
        });
        const users = await Promise.all(usersPromises);
        return (users);
    }
};
exports.UserService = UserService;
exports.UserService = UserService = __decorate([
    (0, common_1.Injectable)(),
    __metadata("design:paramtypes", [prisma_service_1.PrismaService])
], UserService);
//# sourceMappingURL=user.service.js.map