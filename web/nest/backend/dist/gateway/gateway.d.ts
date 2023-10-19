import { OnModuleInit } from "@nestjs/common";
import { PrismaService } from "src/prisma/prisma.service";
import { Server } from "socket.io";
export declare class MyGateway implements OnModuleInit {
    private prisma;
    constructor(prisma: PrismaService);
    server: Server;
    onModuleInit(): void;
    sendNotification(socketId: string, data: any): void;
    onNewMessage(body: any): void;
}
