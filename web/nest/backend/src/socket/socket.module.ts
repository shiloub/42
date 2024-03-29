import { Module } from '@nestjs/common';
import { ChannelService } from 'src/channel/channel.service';
import { MessageService } from 'src/message/message.service';
import { UserService } from 'src/user/user.service';
import { SocketGateway } from './socket.gateway';
import { SocketService } from './socket.service';
import { UserModule } from 'src/user/user.module';
import { ChannelModule } from 'src/channel/channel.module';
import { MessageModule } from 'src/message/message.module';
import { PrismaService } from 'src/prisma/prisma.service';

@Module({
    imports : [MessageModule],
    providers: [
        // MessageService,
        // UserService,
        // ChannelService,
        SocketGateway,
        SocketService,
    ],
    exports: [],
})
export class SocketModule {}
