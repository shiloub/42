import { ChannelService } from './channel.service';
import { ChannelDto } from './dto/channel.dto';
export declare class ChannelController {
    private readonly channelService;
    constructor(channelService: ChannelService);
    createChannel(channelDto: ChannelDto): Promise<{
        channel: {
            id: number;
            createdAt: Date;
            name: string;
            password: string;
            type: import(".prisma/client").$Enums.ChannelType;
        };
        error?: undefined;
    } | {
        error: string;
        channel?: undefined;
    }>;
    getChannels(): Promise<{
        channels: {
            id: number;
            createdAt: Date;
            name: string;
            password: string;
            type: import(".prisma/client").$Enums.ChannelType;
        }[];
        error?: undefined;
    } | {
        error: string;
        channels?: undefined;
    }>;
}
