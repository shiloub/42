import { PrismaService } from "src/prisma/prisma.service";
import { AuthDto } from "./dto";
import { JwtService } from "@nestjs/jwt";
import { ConfigService } from "@nestjs/config";
export declare class AuthService {
    private prisma;
    private jwt;
    private config;
    constructor(prisma: PrismaService, jwt: JwtService, config: ConfigService);
    signup(dto: AuthDto): Promise<{
        id: number;
        createdAt: Date;
        updatedAt: Date;
        hash: string;
        login: string;
        socket: string;
    }>;
    signtoken(userid: number, email: string): Promise<{
        access_token: string;
    }>;
}
