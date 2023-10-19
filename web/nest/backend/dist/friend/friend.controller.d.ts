import { FriendService } from './friend.service';
import { Request } from 'express';
export declare class FriendController {
    private friendservice;
    constructor(friendservice: FriendService);
    signup(body: any, request: Request): Promise<string>;
}
