import { PrismaService } from 'src/prisma/prisma.service';
import { Channel, Message, User } from '@prisma/client';
import { idDto } from './dto';
declare enum ChannelRole {
    DEFAULT = "DEFAULT",
    ADMIN = "ADMIN",
    OWNER = "OWNER"
}
declare enum ChannelType {
    PRIVATE = "PRIVATE",
    PUBLIC = "PUBLIC",
    DIRECT = "DIRECT"
}
export declare class ChannelService {
    private prisma;
    constructor(prisma: PrismaService);
    createChannel(name: string, password: string, type: ChannelType, creatorId: number): Promise<Channel>;
    joinChannel(name: string, joinerId: number, password: string): Promise<Channel>;
    setNewAdmin(userId: number, channelId: number): Promise<void>;
    createChannelco(userId: number, channelId: number, role: ChannelRole): Promise<void>;
    getIdByName(name: string): Promise<number>;
    getChannels(): Promise<Channel[]>;
    getChannelMessages(channelId: number): Promise<Message[]>;
    getChannelUsers(channelId: number): Promise<User[]>;
    banUser(channelId: number, userId: number): Promise<void>;
    inviteUser(channelId: number, userId: number): Promise<void>;
    muteUser(userId: number, channelId: number): Promise<void>;
    getChannelDefaultUsers(channelId: number): Promise<User[]>;
    getChannelDefaultAdminUsers(channelId: number): Promise<User[]>;
    getUserChannels(userId: number): Promise<Channel[]>;
    getUserDirect(userId: number): Promise<Channel[]>;
    getChanRole(userId: number, channelId: number): Promise<"DEFAULT" | "OWNER" | "ADMIN" | {
        error: string;
    }>;
    leaveChan(userId: number, channelId: number, userLogin: string): Promise<void>;
    setPassword(channelId: number, password: string): Promise<void>;
    deleteChan(channelId: number): Promise<void>;
    getChannel(dto: idDto): Promise<Channel>;
}
export {};
