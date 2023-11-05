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
var __param = (this && this.__param) || function (paramIndex, decorator) {
    return function (target, key) { decorator(target, key, paramIndex); }
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.UserController = void 0;
const common_1 = require("@nestjs/common");
const user_service_1 = require("./user.service");
const user_dto_1 = require("./dto/user.dto");
let UserController = class UserController {
    constructor(userService) {
        this.userService = userService;
    }
    getme(req) {
        return (req.user);
    }
    getLogin(req) {
        return (req.user.login);
    }
    async getuser(login) {
        try {
            const user = await this.userService.getUser(login);
            return ({ user });
        }
        catch {
            return { error: "404 User not found" };
        }
    }
    async getFriends(login) {
        try {
            const users = await this.userService.getFriends(login);
            return { users };
        }
        catch {
            return { error: "404 User not found" };
        }
    }
    async getBlocked(req) {
        try {
            const users = await this.userService.getBlocked(req.user.login);
            return ({ users });
        }
        catch {
            return { error: "404 User not found" };
        }
    }
    async addFriend(dto) {
        try {
            const added = await this.userService.addFriend(dto.login, dto.target);
            return ({ added });
        }
        catch (error) {
            return { error: `you cant add this user` };
        }
    }
    async delFriend(dto) {
        try {
            const added = await this.userService.delFriend(dto.login, dto.target);
            return ({ added });
        }
        catch (error) {
            return { error: `you cant add this user` };
        }
    }
    async blockUser(dto) {
        try {
            const blocked = await this.userService.blockUser(dto.login, dto.target);
            return ({ blocked });
        }
        catch (error) {
            return { error: `you cant block this user` };
        }
    }
    async unblockUser(dto) {
        try {
            const blocked = await this.userService.unblockUser(dto.login, dto.target);
            return ({ blocked });
        }
        catch (error) {
            return { error: `you cant block this user` };
        }
    }
};
exports.UserController = UserController;
__decorate([
    (0, common_1.Get)('me'),
    __param(0, (0, common_1.Req)()),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [Object]),
    __metadata("design:returntype", void 0)
], UserController.prototype, "getme", null);
__decorate([
    (0, common_1.Get)('getLogin'),
    __param(0, (0, common_1.Req)()),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [Object]),
    __metadata("design:returntype", void 0)
], UserController.prototype, "getLogin", null);
__decorate([
    (0, common_1.Get)('other'),
    __param(0, (0, common_1.Query)('login')),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [String]),
    __metadata("design:returntype", Promise)
], UserController.prototype, "getuser", null);
__decorate([
    (0, common_1.Get)('friends'),
    __param(0, (0, common_1.Query)('login')),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [String]),
    __metadata("design:returntype", Promise)
], UserController.prototype, "getFriends", null);
__decorate([
    (0, common_1.Get)('blocked'),
    __param(0, (0, common_1.Req)()),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [Object]),
    __metadata("design:returntype", Promise)
], UserController.prototype, "getBlocked", null);
__decorate([
    (0, common_1.Post)('addFriend'),
    __param(0, (0, common_1.Body)()),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [user_dto_1.AddFriendDto]),
    __metadata("design:returntype", Promise)
], UserController.prototype, "addFriend", null);
__decorate([
    (0, common_1.Post)('delFriend'),
    __param(0, (0, common_1.Body)()),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [user_dto_1.AddFriendDto]),
    __metadata("design:returntype", Promise)
], UserController.prototype, "delFriend", null);
__decorate([
    (0, common_1.Post)('blockUser'),
    __param(0, (0, common_1.Body)()),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [user_dto_1.AddFriendDto]),
    __metadata("design:returntype", Promise)
], UserController.prototype, "blockUser", null);
__decorate([
    (0, common_1.Post)('unblockUser'),
    __param(0, (0, common_1.Body)()),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [user_dto_1.AddFriendDto]),
    __metadata("design:returntype", Promise)
], UserController.prototype, "unblockUser", null);
exports.UserController = UserController = __decorate([
    (0, common_1.Controller)('users'),
    __metadata("design:paramtypes", [user_service_1.UserService])
], UserController);
//# sourceMappingURL=user.controller.js.map