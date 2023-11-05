import { ChannelService } from './channel.service';
import { ChangePasswordDto, ChannelCreaDto, ChannelJoinDto, DirectCreaDto, NameDto, SetAdminDto } from './dto/channel.dto';
import { UserService } from 'src/user/user.service';
import { ModuleRef } from '@nestjs/core';
export declare class ChannelController {
    private readonly channelService;
    private userService;
    private socketRef;
    constructor(channelService: ChannelService, userService: UserService, socketRef: ModuleRef);
    createChannel(channelcreaDto: ChannelCreaDto): Promise<{
        channel: {
            id: number;
            banned: number[];
            invited: number[];
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
    createDirect(directcreaDto: DirectCreaDto): Promise<{
        channel: {
            id: number;
            banned: number[];
            invited: number[];
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
    setPassword(dto: ChangePasswordDto): Promise<{
        error: string;
    }>;
    joinChannel(channeljoinDto: ChannelJoinDto): Promise<{
        channel: {
            id: number;
            banned: number[];
            invited: number[];
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
    leaveChannel(channelLeaveDto: ChannelJoinDto): Promise<{
        error: string;
    }>;
    kickUser(channelLeaveDto: ChannelJoinDto): Promise<{
        error: string;
    }>;
    banUser(channelLeaveDto: ChannelJoinDto): Promise<{
        error: string;
    }>;
    inviteUser(inviteDto: ChannelJoinDto): Promise<{
        error: string;
    }>;
    MuteUser(channelLeaveDto: ChannelJoinDto): Promise<{
        error: string;
    }>;
    setAdmin(dto: SetAdminDto): Promise<{
        error: string;
    }>;
    deleteChannel(nameDto: NameDto): Promise<{
        error: string;
    }>;
    getChannels(): Promise<{
        channels: {
            id: number;
            banned: number[];
            invited: number[];
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
    getUserChannels(userlogin: string): Promise<{
        channels: {
            id: number;
            banned: number[];
            invited: number[];
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
    getchannelUser(name: string): Promise<{
        users: {
            id: number;
            createdAt: Date;
            updatedAt: Date;
            hash: string;
            login: string;
            socket: string;
        }[];
        error?: undefined;
    } | {
        error: string;
        users?: undefined;
    }>;
    getchanneldefault(name: string): Promise<{
        users: {
            id: number;
            createdAt: Date;
            updatedAt: Date;
            hash: string;
            login: string;
            socket: string;
        }[];
        error?: undefined;
    } | {
        error: string;
        users?: undefined;
    }>;
    getchanneldefaultadmin(name: string): Promise<{
        users: {
            id: number;
            createdAt: Date;
            updatedAt: Date;
            hash: string;
            login: string;
            socket: string;
        }[];
        error?: undefined;
    } | {
        error: string;
        users?: undefined;
    }>;
    getUserDirect(userlogin: string): Promise<{
        channels: {
            id: number;
            banned: number[];
            invited: number[];
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
    getChannelMessage(channelName: string): Promise<{
        messages: {
            id: number;
            senderId: number;
            senderLogin: string;
            channelId: number;
            content: string;
        }[];
        error?: undefined;
    } | {
        error: string;
        messages?: undefined;
    }>;
    getRole(channelName: string, login: string): Promise<{
        role: "DEFAULT" | "OWNER" | "ADMIN" | {
            error: string;
        };
        error?: undefined;
    } | {
        error: string;
        role?: undefined;
    }>;
}
