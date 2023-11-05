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
exports.ChannelController = void 0;
const common_1 = require("@nestjs/common");
const channel_service_1 = require("./channel.service");
const channel_dto_1 = require("./dto/channel.dto");
const user_service_1 = require("../user/user.service");
const socket_gateway_1 = require("../socket/socket.gateway");
const core_1 = require("@nestjs/core");
let ChannelController = class ChannelController {
    constructor(channelService, userService, socketRef) {
        this.channelService = channelService;
        this.userService = userService;
        this.socketRef = socketRef;
    }
    async createChannel(channelcreaDto) {
        try {
            const creatorId = await this.userService.getIdByLogin(channelcreaDto.creatorLogin);
            const channel = await this.channelService.createChannel(channelcreaDto.name, channelcreaDto.password, channelcreaDto.type, creatorId);
            return { channel };
        }
        catch (error) {
            return { error: `server cant create the channel` };
        }
    }
    async createDirect(directcreaDto) {
        try {
            const channelName = (directcreaDto.starterLogin > directcreaDto.targetLogin) ? (directcreaDto.starterLogin + "-" + directcreaDto.targetLogin) : (directcreaDto.targetLogin + "-" + directcreaDto.starterLogin);
            const starterId = await this.userService.getIdByLogin(directcreaDto.starterLogin);
            const targetId = await this.userService.getIdByLogin(directcreaDto.targetLogin);
            if (starterId === targetId)
                throw new Error;
            const channel = await this.channelService.createChannel(channelName, "", directcreaDto.type, starterId);
            await this.channelService.joinChannel(channelName, targetId, "");
            return { channel };
        }
        catch (error) {
            return { error: "server cant create direct chat" };
        }
    }
    async setPassword(dto) {
        const channelId = await this.channelService.getIdByName(dto.name);
        try {
            await this.channelService.setPassword(channelId, dto.password);
        }
        catch {
            return ({ error: "server cant change password" });
        }
    }
    async joinChannel(channeljoinDto) {
        try {
            const joinerId = await this.userService.getIdByLogin(channeljoinDto.login);
            const channel = await this.channelService.joinChannel(channeljoinDto.name, joinerId, channeljoinDto.password);
            return { channel };
        }
        catch (error) {
            return { error: `you cant join this channel` };
        }
    }
    async leaveChannel(channelLeaveDto) {
        try {
            const leaverId = await this.userService.getIdByLogin(channelLeaveDto.login);
            const channelId = await this.channelService.getIdByName(channelLeaveDto.name);
            await this.channelService.leaveChan(leaverId, channelId, channelLeaveDto.login);
        }
        catch (error) {
            return { error: `you cant leave this channel` };
        }
    }
    async kickUser(channelLeaveDto) {
        try {
            const leaverId = await this.userService.getIdByLogin(channelLeaveDto.login);
            const channelId = await this.channelService.getIdByName(channelLeaveDto.name);
            await this.channelService.leaveChan(leaverId, channelId, channelLeaveDto.login);
            const socketService = this.socketRef.get(socket_gateway_1.SocketGateway, { strict: false });
            socketService.sendEvent(channelLeaveDto.login, "kicked", null);
        }
        catch (error) {
            return { error: `you cant kicked this user` };
        }
    }
    async banUser(channelLeaveDto) {
        try {
            const leaverId = await this.userService.getIdByLogin(channelLeaveDto.login);
            const channelId = await this.channelService.getIdByName(channelLeaveDto.name);
            await this.channelService.leaveChan(leaverId, channelId, channelLeaveDto.login);
            await this.channelService.banUser(channelId, leaverId);
            const socketService = this.socketRef.get(socket_gateway_1.SocketGateway, { strict: false });
            socketService.sendEvent(channelLeaveDto.login, "kicked", null);
        }
        catch (error) {
            return { error: `you cant kicked this user` };
        }
    }
    async inviteUser(inviteDto) {
        try {
            const invitedId = await this.userService.getIdByLogin(inviteDto.login);
            const channelId = await this.channelService.getIdByName(inviteDto.name);
            await this.channelService.inviteUser(channelId, invitedId);
            const socketService = this.socketRef.get(socket_gateway_1.SocketGateway, { strict: false });
        }
        catch (error) {
            return { error: `you cant invite this user` };
        }
    }
    async MuteUser(channelLeaveDto) {
        try {
            const leaverId = await this.userService.getIdByLogin(channelLeaveDto.login);
            const channelId = await this.channelService.getIdByName(channelLeaveDto.name);
            await this.channelService.muteUser(leaverId, channelId);
        }
        catch (error) {
            return { error: `you cant kicked this user` };
        }
    }
    async setAdmin(dto) {
        try {
            const userId = await this.userService.getIdByLogin(dto.login);
            const channelId = await this.channelService.getIdByName(dto.name);
            await this.channelService.setNewAdmin(userId, channelId);
        }
        catch (error) {
            return { error: `you cant set this user as admin` };
        }
    }
    async deleteChannel(nameDto) {
        try {
            const channelId = await this.channelService.getIdByName(nameDto.name);
            await this.channelService.deleteChan(channelId);
        }
        catch (error) {
            return { error: `cant destroy this channel` };
        }
    }
    async getChannels() {
        try {
            const channels = await this.channelService.getChannels();
            return { channels };
        }
        catch (error) {
            return { error: `Une erreur s\'est produite lors de la recupération des channels: ${error}` };
        }
    }
    async getUserChannels(userlogin) {
        try {
            const userId = await this.userService.getIdByLogin(userlogin);
            const channels = await this.channelService.getUserChannels(userId);
            return { channels };
        }
        catch (error) {
            return { error: `Une erreur s\'est produite lors de la recupération des channels: ${error}` };
        }
    }
    async getchannelUser(name) {
        try {
            const channelId = await this.channelService.getIdByName(name);
            const users = await this.channelService.getChannelUsers(channelId);
            return { users };
        }
        catch (error) {
            return { error: `Une erreur s\'est produite lors de la recupération des users` };
        }
    }
    async getchanneldefault(name) {
        try {
            const channelId = await this.channelService.getIdByName(name);
            const users = await this.channelService.getChannelDefaultUsers(channelId);
            return { users };
        }
        catch (error) {
            return { error: `Une erreur s\'est produite lors de la recupération des users` };
        }
    }
    async getchanneldefaultadmin(name) {
        try {
            const channelId = await this.channelService.getIdByName(name);
            const users = await this.channelService.getChannelDefaultAdminUsers(channelId);
            return { users };
        }
        catch (error) {
            return { error: `Une erreur s\'est produite lors de la recupération des users` };
        }
    }
    async getUserDirect(userlogin) {
        try {
            const userId = await this.userService.getIdByLogin(userlogin);
            const channels = await this.channelService.getUserDirect(userId);
            return { channels };
        }
        catch (error) {
            return { error: `Une erreur s\'est produite lors de la recupération des directs: ${error}` };
        }
    }
    async getChannelMessage(channelName) {
        try {
            const channelId = await this.channelService.getIdByName(channelName);
            const messages = await this.channelService.getChannelMessages(channelId);
            return { messages };
        }
        catch (error) {
            return { error: `Une erreur s\'est produite lors de la recupération des messages: ${error}` };
        }
    }
    async getRole(channelName, login) {
        try {
            const channelId = await this.channelService.getIdByName(channelName);
            const userId = await this.userService.getIdByLogin(login);
            const role = await this.channelService.getChanRole(userId, channelId);
            return { role };
        }
        catch (error) {
            return { error: `Une erreur s\'est produite lors de la recupération des messages: ${error}` };
        }
    }
};
exports.ChannelController = ChannelController;
__decorate([
    (0, common_1.Post)('create'),
    __param(0, (0, common_1.Body)()),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [channel_dto_1.ChannelCreaDto]),
    __metadata("design:returntype", Promise)
], ChannelController.prototype, "createChannel", null);
__decorate([
    (0, common_1.Post)('createDirect'),
    __param(0, (0, common_1.Body)()),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [channel_dto_1.DirectCreaDto]),
    __metadata("design:returntype", Promise)
], ChannelController.prototype, "createDirect", null);
__decorate([
    (0, common_1.Post)('setPassword'),
    __param(0, (0, common_1.Body)()),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [channel_dto_1.ChangePasswordDto]),
    __metadata("design:returntype", Promise)
], ChannelController.prototype, "setPassword", null);
__decorate([
    (0, common_1.Post)('join'),
    __param(0, (0, common_1.Body)()),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [channel_dto_1.ChannelJoinDto]),
    __metadata("design:returntype", Promise)
], ChannelController.prototype, "joinChannel", null);
__decorate([
    (0, common_1.Post)('leave'),
    __param(0, (0, common_1.Body)()),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [channel_dto_1.ChannelJoinDto]),
    __metadata("design:returntype", Promise)
], ChannelController.prototype, "leaveChannel", null);
__decorate([
    (0, common_1.Post)('kick'),
    __param(0, (0, common_1.Body)()),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [channel_dto_1.ChannelJoinDto]),
    __metadata("design:returntype", Promise)
], ChannelController.prototype, "kickUser", null);
__decorate([
    (0, common_1.Post)('ban'),
    __param(0, (0, common_1.Body)()),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [channel_dto_1.ChannelJoinDto]),
    __metadata("design:returntype", Promise)
], ChannelController.prototype, "banUser", null);
__decorate([
    (0, common_1.Post)('invite'),
    __param(0, (0, common_1.Body)()),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [channel_dto_1.ChannelJoinDto]),
    __metadata("design:returntype", Promise)
], ChannelController.prototype, "inviteUser", null);
__decorate([
    (0, common_1.Post)('mute'),
    __param(0, (0, common_1.Body)()),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [channel_dto_1.ChannelJoinDto]),
    __metadata("design:returntype", Promise)
], ChannelController.prototype, "MuteUser", null);
__decorate([
    (0, common_1.Post)('setAdmin'),
    __param(0, (0, common_1.Body)()),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [channel_dto_1.SetAdminDto]),
    __metadata("design:returntype", Promise)
], ChannelController.prototype, "setAdmin", null);
__decorate([
    (0, common_1.Post)('delete'),
    __param(0, (0, common_1.Body)()),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [channel_dto_1.NameDto]),
    __metadata("design:returntype", Promise)
], ChannelController.prototype, "deleteChannel", null);
__decorate([
    (0, common_1.Get)(),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", []),
    __metadata("design:returntype", Promise)
], ChannelController.prototype, "getChannels", null);
__decorate([
    (0, common_1.Get)('mine'),
    __param(0, (0, common_1.Query)('login')),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [String]),
    __metadata("design:returntype", Promise)
], ChannelController.prototype, "getUserChannels", null);
__decorate([
    (0, common_1.Get)('users'),
    __param(0, (0, common_1.Query)('name')),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [String]),
    __metadata("design:returntype", Promise)
], ChannelController.prototype, "getchannelUser", null);
__decorate([
    (0, common_1.Get)('default'),
    __param(0, (0, common_1.Query)('name')),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [String]),
    __metadata("design:returntype", Promise)
], ChannelController.prototype, "getchanneldefault", null);
__decorate([
    (0, common_1.Get)('all'),
    __param(0, (0, common_1.Query)('name')),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [String]),
    __metadata("design:returntype", Promise)
], ChannelController.prototype, "getchanneldefaultadmin", null);
__decorate([
    (0, common_1.Get)('direct'),
    __param(0, (0, common_1.Query)('login')),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [String]),
    __metadata("design:returntype", Promise)
], ChannelController.prototype, "getUserDirect", null);
__decorate([
    (0, common_1.Get)('messages'),
    __param(0, (0, common_1.Query)('name')),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [String]),
    __metadata("design:returntype", Promise)
], ChannelController.prototype, "getChannelMessage", null);
__decorate([
    (0, common_1.Get)('role'),
    __param(0, (0, common_1.Query)('name')),
    __param(1, (0, common_1.Query)('login')),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [String, String]),
    __metadata("design:returntype", Promise)
], ChannelController.prototype, "getRole", null);
exports.ChannelController = ChannelController = __decorate([
    (0, common_1.Controller)('channel'),
    __metadata("design:paramtypes", [channel_service_1.ChannelService,
        user_service_1.UserService,
        core_1.ModuleRef])
], ChannelController);
//# sourceMappingURL=channel.controller.js.map