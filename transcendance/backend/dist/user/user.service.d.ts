import { User } from '@prisma/client';
import { PrismaService } from 'src/prisma/prisma.service';
export declare class UserService {
    private prisma;
    constructor(prisma: PrismaService);
    findOneByUsername(username: string): Promise<{
        id: number;
        createdAt: Date;
        updatedAt: Date;
        login: string;
        username: string;
        sessionId: string;
        twoFaEnabled: boolean;
        twoFaSecret: string;
    }>;
    getIdByLogin(login: string): Promise<number>;
    getUsernameByLogin(login: string): Promise<string>;
    getLoginById(id: number): Promise<string>;
    getUser(login: string): Promise<User>;
    addFriend(login: string, target: string): Promise<User>;
    delFriend(login: string, target: string): Promise<User>;
    blockUser(login: string, target: string): Promise<User>;
    unblockUser(login: string, target: string): Promise<User>;
    getFriends(login: string): Promise<string[]>;
    getBlocked(login: string): Promise<string[]>;
}
