import { PrismaService } from 'src/prisma/prisma.service';
import { Channel } from '@prisma/client';
import { ChannelDto, idDto } from './dto';
export declare class ChannelService {
    private prisma;
    constructor(prisma: PrismaService);
    createChannel(channelDto: ChannelDto): Promise<Channel>;
    getChannels(): Promise<Channel[]>;
    getChannel(dto: idDto): Promise<Channel>;
}
