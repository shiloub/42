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
exports.SocketGateway = void 0;
const core_1 = require("@nestjs/core");
const websockets_1 = require("@nestjs/websockets");
const socket_io_1 = require("socket.io");
const channel_service_1 = require("../channel/channel.service");
const message_service_1 = require("../message/message.service");
const prisma_service_1 = require("../prisma/prisma.service");
const user_service_1 = require("../user/user.service");
let SocketGateway = class SocketGateway {
    constructor(moduleRef, prismaService) {
        this.moduleRef = moduleRef;
        this.prismaService = prismaService;
        this.connectedClients = new Map();
    }
    handleConnection(client) {
        console.log('je connecte un client ! ');
        const login = client.handshake.query.login;
        this.connectedClients.set(login, client);
    }
    handleDisconnect(client) {
        for (const [userLogin, socket] of this.connectedClients) {
            if (socket === client) {
                this.connectedClients.delete(userLogin);
                break;
            }
        }
    }
    sendEvent(login, eventName, data) {
        const socket = this.connectedClients.get(login);
        if (socket)
            socket.emit(eventName, data);
    }
    async handleMessage(client, payload) {
        const channelService = this.moduleRef.get(channel_service_1.ChannelService, { strict: false });
        const userService = this.moduleRef.get(user_service_1.UserService, { strict: false });
        const channelId = await channelService.getIdByName(payload.channelName);
        const userId = await userService.getIdByLogin(payload.senderLogin);
        try {
            const chanco = await this.prismaService.channelConnection.findFirstOrThrow({
                where: {
                    userId,
                    channelId,
                }
            });
            if (chanco.muted < (Math.floor(new Date().getTime() / 1000))) {
                console.log("user " + payload.senderLogin + " is no muted until " + chanco.muted + '/' + Math.floor(new Date().getTime() / 1000));
                const messageservice = this.moduleRef.get(message_service_1.MessageService, { strict: false });
                const message = await messageservice.createMessage(payload.content, payload.senderLogin, payload.channelName);
                console.log('jenvoie le message');
                payload.userList.map((user) => {
                    this.connectedClients.get(user.login).emit('message', message);
                });
            }
            else {
                console.log("userid " + chanco.userId + " is muted on chan " + chanco.channelId);
            }
        }
        catch (error) {
            console.log("erroooooor");
            throw (error);
        }
    }
};
exports.SocketGateway = SocketGateway;
__decorate([
    (0, websockets_1.WebSocketServer)(),
    __metadata("design:type", socket_io_1.Server)
], SocketGateway.prototype, "server", void 0);
__decorate([
    (0, websockets_1.SubscribeMessage)('message'),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [socket_io_1.Socket, Object]),
    __metadata("design:returntype", Promise)
], SocketGateway.prototype, "handleMessage", null);
exports.SocketGateway = SocketGateway = __decorate([
    (0, websockets_1.WebSocketGateway)({ cors: {
            origin: 'http://localhost:3000',
            methods: ['GET', 'POST'],
            credentials: true,
        } }),
    __metadata("design:paramtypes", [core_1.ModuleRef, prisma_service_1.PrismaService])
], SocketGateway);
//# sourceMappingURL=socket.gateway.js.map