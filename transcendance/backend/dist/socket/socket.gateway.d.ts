import { ModuleRef } from '@nestjs/core';
import { OnGatewayConnection, OnGatewayDisconnect } from '@nestjs/websockets';
import { Server, Socket } from 'socket.io';
import { PrismaService } from 'src/prisma/prisma.service';
export declare class SocketGateway implements OnGatewayConnection, OnGatewayDisconnect {
    private moduleRef;
    private prismaService;
    constructor(moduleRef: ModuleRef, prismaService: PrismaService);
    server: Server;
    private connectedClients;
    handleConnection(client: Socket): void;
    handleDisconnect(client: Socket): void;
    sendEvent(login: string, eventName: string, data: any): void;
    handleMessage(client: Socket, payload: any): Promise<void>;
}
