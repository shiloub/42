/// <reference types="passport" />
import { Request } from 'express';
import { UserService } from './user.service';
import { AddFriendDto } from './dto/user.dto';
export declare class UserController {
    private userService;
    constructor(userService: UserService);
    getme(req: Request): Express.User;
    getLogin(req: any): any;
    getuser(login: string): Promise<{
        user: {
            id: number;
            createdAt: Date;
            updatedAt: Date;
            login: string;
            username: string;
            sessionId: string;
            twoFaEnabled: boolean;
            twoFaSecret: string;
        };
        error?: undefined;
    } | {
        error: string;
        user?: undefined;
    }>;
    getFriends(login: string): Promise<{
        users: string[];
        error?: undefined;
    } | {
        error: string;
        users?: undefined;
    }>;
    getBlocked(req: any): Promise<{
        users: string[];
        error?: undefined;
    } | {
        error: string;
        users?: undefined;
    }>;
    addFriend(dto: AddFriendDto): Promise<{
        added: {
            id: number;
            createdAt: Date;
            updatedAt: Date;
            login: string;
            username: string;
            sessionId: string;
            twoFaEnabled: boolean;
            twoFaSecret: string;
        };
        error?: undefined;
    } | {
        error: string;
        added?: undefined;
    }>;
    delFriend(dto: AddFriendDto): Promise<{
        added: {
            id: number;
            createdAt: Date;
            updatedAt: Date;
            login: string;
            username: string;
            sessionId: string;
            twoFaEnabled: boolean;
            twoFaSecret: string;
        };
        error?: undefined;
    } | {
        error: string;
        added?: undefined;
    }>;
    blockUser(dto: AddFriendDto): Promise<{
        blocked: {
            id: number;
            createdAt: Date;
            updatedAt: Date;
            login: string;
            username: string;
            sessionId: string;
            twoFaEnabled: boolean;
            twoFaSecret: string;
        };
        error?: undefined;
    } | {
        error: string;
        blocked?: undefined;
    }>;
    unblockUser(dto: AddFriendDto): Promise<{
        blocked: {
            id: number;
            createdAt: Date;
            updatedAt: Date;
            login: string;
            username: string;
            sessionId: string;
            twoFaEnabled: boolean;
            twoFaSecret: string;
        };
        error?: undefined;
    } | {
        error: string;
        blocked?: undefined;
    }>;
}
