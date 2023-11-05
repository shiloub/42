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
exports.ChannelService = void 0;
const common_1 = require("@nestjs/common");
const prisma_service_1 = require("../prisma/prisma.service");
const console_1 = require("console");
var ChannelRole;
(function (ChannelRole) {
    ChannelRole["DEFAULT"] = "DEFAULT";
    ChannelRole["ADMIN"] = "ADMIN";
    ChannelRole["OWNER"] = "OWNER";
})(ChannelRole || (ChannelRole = {}));
var ChannelType;
(function (ChannelType) {
    ChannelType["PRIVATE"] = "PRIVATE";
    ChannelType["PUBLIC"] = "PUBLIC";
    ChannelType["DIRECT"] = "DIRECT";
})(ChannelType || (ChannelType = {}));
let ChannelService = class ChannelService {
    constructor(prisma) {
        this.prisma = prisma;
    }
    async createChannel(name, password, type, creatorId) {
        const createdChannel = await this.prisma.channel.create({
            data: {
                name,
                password,
                type,
            },
        });
        this.createChannelco(creatorId, createdChannel.id, ChannelRole.OWNER);
        return (createdChannel);
    }
    async joinChannel(name, joinerId, password) {
        const channel = await this.prisma.channel.findUnique({
            where: {
                name,
            }
        });
        if (!channel) {
            console.log(`channel ${name} introuvable`);
            throw new console_1.error("cant find channel");
        }
        if (channel.banned.includes(joinerId))
            throw new console_1.error("User banned");
        if (channel.type === 'PRIVATE' && !channel.invited.includes(joinerId))
            throw new console_1.error("User not invited");
        const chanco = await this.prisma.channelConnection.findFirst({
            where: {
                channelId: channel.id,
                userId: joinerId,
            }
        });
        if (chanco)
            throw new console_1.error("already in chan");
        if (channel.password && channel.password !== "" && channel.password !== password)
            throw new console_1.error("wrong password");
        this.createChannelco(joinerId, channel.id, ChannelRole.DEFAULT);
        return (channel);
    }
    async setNewAdmin(userId, channelId) {
        try {
            const chanco = await this.prisma.channelConnection.updateMany({
                where: {
                    userId,
                    channelId,
                },
                data: {
                    role: ChannelRole.ADMIN
                }
            });
        }
        catch {
            throw ({ error: "cant set this user as Administrator" });
        }
    }
    async createChannelco(userId, channelId, role) {
        try {
            const newChanCo = await this.prisma.channelConnection.create({
                data: {
                    userId,
                    channelId,
                    role,
                    muted: 0,
                }
            });
        }
        catch (error) {
            console.log(`error dans createchannelco: ${error}`);
        }
    }
    async getIdByName(name) {
        const user = await this.prisma.channel.findFirst({
            where: {
                name,
            }
        });
        return (user.id);
    }
    async getChannels() {
        return this.prisma.channel.findMany({
            where: {},
        });
    }
    async getChannelMessages(channelId) {
        try {
            const channel = await this.prisma.channel.findUnique({
                where: {
                    id: channelId,
                },
                include: {
                    messages: {}
                },
            });
            return (channel.messages);
        }
        catch (error) {
            throw new Error(`Error fetching channel_message: ${error.message}`);
        }
        finally {
            await this.prisma.$disconnect();
        }
    }
    async getChannelUsers(channelId) {
        try {
            const channel = await this.prisma.channel.findUnique({
                where: {
                    id: channelId,
                },
                include: {
                    channelConnections: {
                        select: {
                            user: true,
                        }
                    },
                },
            });
            const users = channel.channelConnections.map((connection) => connection.user);
            return (users);
        }
        catch (error) {
            throw new Error(`Error fetching user channels: ${error.message}`);
        }
        finally {
            await this.prisma.$disconnect();
        }
    }
    async banUser(channelId, userId) {
        try {
            const channel = await this.prisma.channel.findUnique({
                where: {
                    id: channelId,
                },
            });
            const temp = channel.banned;
            temp.push(userId);
            const updatechan = await this.prisma.channel.update({
                where: {
                    id: channelId,
                },
                data: {
                    banned: temp,
                },
            });
        }
        catch (error) {
            throw new Error(`Error banning user: ${error.message}`);
        }
    }
    async inviteUser(channelId, userId) {
        try {
            const channel = await this.prisma.channel.findUnique({
                where: {
                    id: channelId,
                },
            });
            const temp = channel.invited;
            temp.push(userId);
            const updatechan = await this.prisma.channel.update({
                where: {
                    id: channelId,
                },
                data: {
                    invited: temp,
                },
            });
        }
        catch (error) {
            throw new Error(`Error inviting user: ${error.message}`);
        }
    }
    async muteUser(userId, channelId) {
        try {
            const chanco = await this.prisma.channelConnection.updateMany({
                where: {
                    userId,
                    channelId,
                },
                data: {
                    muted: (Math.floor(new Date().getTime() / 1000)) + 300
                }
            });
        }
        catch (error) {
            throw error;
        }
    }
    async getChannelDefaultUsers(channelId) {
        try {
            const channel = await this.prisma.channel.findUnique({
                where: {
                    id: channelId,
                },
                include: {
                    channelConnections: {
                        where: {
                            role: 'DEFAULT'
                        },
                        select: {
                            user: true,
                        }
                    },
                },
            });
            const users = channel.channelConnections.map((connection) => connection.user);
            return (users);
        }
        catch (error) {
            throw new Error(`Error fetching user channels: ${error.message}`);
        }
        finally {
            await this.prisma.$disconnect();
        }
    }
    async getChannelDefaultAdminUsers(channelId) {
        try {
            const channel = await this.prisma.channel.findUnique({
                where: {
                    id: channelId,
                },
                include: {
                    channelConnections: {
                        where: {
                            OR: [
                                { role: 'DEFAULT' },
                                { role: 'ADMIN' },
                            ],
                        },
                        select: {
                            user: true,
                        }
                    },
                },
            });
            const users = channel.channelConnections.map((connection) => connection.user);
            return (users);
        }
        catch (error) {
            throw new Error(`Error fetching user channels: ${error.message}`);
        }
        finally {
            await this.prisma.$disconnect();
        }
    }
    async getUserChannels(userId) {
        try {
            const user = await this.prisma.user.findUnique({
                where: {
                    id: userId,
                },
                include: {
                    channelConnections: {
                        select: {
                            channel: true,
                        }
                    },
                },
            });
            const filteredChannels = user.channelConnections
                .map((connection) => connection.channel)
                .filter((channel) => channel.type !== 'DIRECT');
            return (filteredChannels);
        }
        catch (error) {
            throw new Error(`Error fetching user channels: ${error.message}`);
        }
        finally {
            await this.prisma.$disconnect();
        }
    }
    async getUserDirect(userId) {
        try {
            const user = await this.prisma.user.findUnique({
                where: {
                    id: userId,
                },
                include: {
                    channelConnections: {
                        select: {
                            channel: true,
                        }
                    },
                },
            });
            const filteredChannels = user.channelConnections
                .map((connection) => connection.channel)
                .filter((channel) => channel.type === 'DIRECT');
            return (filteredChannels);
        }
        catch (error) {
            throw new Error(`Error fetching user channels: ${error.message}`);
        }
        finally {
            await this.prisma.$disconnect();
        }
    }
    async getChanRole(userId, channelId) {
        try {
            const chanco = await this.prisma.channelConnection.findFirst({
                where: {
                    userId,
                    channelId,
                }
            });
            return (chanco.role);
        }
        catch {
            return ({ error: "erreur lors de la recup du chanco" });
        }
    }
    async leaveChan(userId, channelId, userLogin) {
        try {
            const deletedChannelConnection = await this.prisma.channelConnection.deleteMany({
                where: {
                    userId: userId,
                    channelId: channelId,
                },
            });
            if (deletedChannelConnection) {
                console.log(`Le lien entre l'utilisateur ${userId} et le canal ${channelId} a été supprimé.`);
            }
            else {
                console.log(`Aucun lien trouvé entre l'utilisateur ${userId} et le canal ${channelId}.`);
            }
        }
        catch (error) {
            console.error(`Une erreur s'est produite lors de la suppression du lien : ${error}`);
        }
    }
    async setPassword(channelId, password) {
        try {
            const channel = await this.prisma.channel.update({
                where: {
                    id: channelId,
                },
                data: {
                    password: password,
                }
            });
            console.log(`mot de passe du channel changé: '${channel.password}'`);
        }
        catch {
            console.log("erreur lors du changement de password");
        }
    }
    async deleteChan(channelId) {
        try {
            await this.prisma.channel.delete({
                where: {
                    id: channelId,
                }
            });
        }
        catch {
            console.error("erreur lors de la suppression d'un channel");
        }
    }
    async getChannel(dto) {
        return this.prisma.channel.findUnique({
            where: {
                id: dto.id,
            },
        });
    }
};
exports.ChannelService = ChannelService;
exports.ChannelService = ChannelService = __decorate([
    (0, common_1.Injectable)(),
    __metadata("design:paramtypes", [prisma_service_1.PrismaService])
], ChannelService);
//# sourceMappingURL=channel.service.js.map