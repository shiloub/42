import { OnModuleInit } from "@nestjs/common";
import { MessageBody, SubscribeMessage, WebSocketGateway, WebSocketServer } from "@nestjs/websockets";
import { PrismaService } from "src/prisma/prisma.service";
import { Server, Socket } from "socket.io";

@WebSocketGateway({ cors: {
  origin: 'http://localhost:3000',
  methods: ['GET', 'POST'],
  credentials: true,
} })
export class MyGateway implements OnModuleInit{
    constructor(
        private prisma: PrismaService,
    ){}

    @WebSocketServer()
    server: Server;

    onModuleInit() {
        this.server.on('connection', (socket: Socket) => {
            const jwt = require('jsonwebtoken');
            const secretKey='banana'
            socket.on('authenticate', async (data) => {
                const {token, email} = data;
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
                } catch (error) {
                    console.log('erreur dauthentification du token');
                }
            })
        })
    }

    sendNotification(socketId: string, data: any)
    {
        this.server.to(socketId).emit('notification', data);
    }


    @SubscribeMessage('newMessage')
    onNewMessage(@MessageBody() body: any){
        console.log(body);
        this.server.emit('onMessage', { 
            msg: 'New message',
            content: body,
        })
    }

}  