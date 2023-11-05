import { ConfigService } from '@nestjs/config';
import { PrismaService } from 'src/prisma/prisma.service';
declare const FortyTwoStrategy_base: new (...args: any[]) => any;
export declare class FortyTwoStrategy extends FortyTwoStrategy_base {
    private prisma;
    constructor(config: ConfigService, prisma: PrismaService);
    validate(accessToken: string, refreshToken: string, profile: any, cb: Function): Promise<{
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
