import { Strategy } from 'passport-jwt';
import { ConfigService } from '@nestjs/config';
import { UserService } from 'src/user/user.service';
declare const JwtStrategy_base: new (...args: any[]) => Strategy;
export declare class JwtStrategy extends JwtStrategy_base {
    private readonly user;
    constructor(config: ConfigService, user: UserService);
    validate(payload: any): Promise<{
        id: number;
        createdAt: Date;
        updatedAt: Date;
        login: string;
        username: string;
        sessionId: string;
        twoFaEnabled: boolean;
        twoFaSecret: string;
    }>;
}
export {};
