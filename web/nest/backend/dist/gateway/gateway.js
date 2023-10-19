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
exports.MyGateway = void 0;
const websockets_1 = require("@nestjs/websockets");
const prisma_service_1 = require("../prisma/prisma.service");
const socket_io_1 = require("socket.io");
let MyGateway = class MyGateway {
    constructor(prisma) {
        this.prisma = prisma;
    }
    onModuleInit() {
        this.server.on('connection', (socket) => {
            const jwt = require('jsonwebtoken');
            const secretKey = 'banana';
            socket.on('authenticate', async (data) => {
                const { token, email } = data;
                try {
                    const decoded = jwt.verify(token, secretKey);
                    const user = await this.prisma.user.findUnique({
                        where: {
                            email: email,
                        },
                    });
                    if (user) {
                        await this.prisma.user.update({
                            where: {
                                id: user.id,
                            },
                            data: {
                                socket: socket.id,
                            },
                        });
                    }
                }
                catch (error) {
                    console.log('erreur dauthentification du token');
                }
            });
        });
    }
    sendNotification(socketId, data) {
        this.server.to(socketId).emit('notification', data);
    }
    onNewMessage(body) {
        console.log(body);
        this.server.emit('onMessage', {
            msg: 'New message',
            content: body,
        });
    }
};
exports.MyGateway = MyGateway;
__decorate([
    (0, websockets_1.WebSocketServer)(),
    __metadata("design:type", socket_io_1.Server)
], MyGateway.prototype, "server", void 0);
__decorate([
    (0, websockets_1.SubscribeMessage)('newMessage'),
    __param(0, (0, websockets_1.MessageBody)()),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [Object]),
    __metadata("design:returntype", void 0)
], MyGateway.prototype, "onNewMessage", null);
exports.MyGateway = MyGateway = __decorate([
    (0, websockets_1.WebSocketGateway)({ cors: {
            origin: 'http://localhost:3000',
            methods: ['GET', 'POST'],
            credentials: true,
        } }),
    __metadata("design:paramtypes", [prisma_service_1.PrismaService])
], MyGateway);
//# sourceMappingURL=gateway.js.map