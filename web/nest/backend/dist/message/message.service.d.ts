import { Message } from '@prisma/client';
import { ChannelService } from 'src/channel/channel.service';
import { PrismaService } from 'src/prisma/prisma.service';
import { UserService } from 'src/user/user.service';
export declare class MessageService {
    private prisma;
    private channelService;
    private userService;
    constructor(prisma: PrismaService, channelService: ChannelService, userService: UserService);
    createMessage(content: string, senderLogin: string, channelName: string): Promise<Message>;
}
