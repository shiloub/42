/// <reference types="passport" />
import { Request } from 'express';
import { UserService } from './user.service';
import { AddFriendDto } from './dto/user.dto';
export declare class UserController {
    private userService;
    constructor(userService: UserService);
    getme(req: Request): Express.User;
    getuser(login: string): Promise<{
        user: {
            id: number;
            createdAt: Date;
            updatedAt: Date;
            hash: string;
            login: string;
            socket: string;
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
    getBlocked(login: string): Promise<{
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
            hash: string;
            login: string;
            socket: string;
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
            hash: string;
            login: string;
            socket: string;
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
            hash: string;
            login: string;
            socket: string;
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
            hash: string;
            login: string;
            socket: string;
        };
        error?: undefined;
    } | {
        error: string;
        blocked?: undefined;
    }>;
}
