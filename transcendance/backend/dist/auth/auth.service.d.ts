import { PrismaService } from '../prisma/prisma.service';
import { JwtService } from '@nestjs/jwt';
import { ConfigService } from '@nestjs/config';
export declare class AuthService {
    private prisma;
    private jwt;
    private config;
    constructor(prisma: PrismaService, jwt: JwtService, config: ConfigService);
    generateJwt(user: any, cookie_type: string): Promise<{
        access_token: string;
    }>;
    launchTwoFa(userInfos: any): Promise<{
        otpAuthUrl: string;
        secret: string;
    }>;
    twoFaActivate(user: any, twoFactorCode: string): Promise<boolean>;
    twoFaAuthenticate(user: any, twoFactorCode: string): Promise<boolean>;
}
