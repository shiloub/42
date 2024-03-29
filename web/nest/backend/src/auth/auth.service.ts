import { ForbiddenException, Injectable } from "@nestjs/common";
import { PrismaService } from "src/prisma/prisma.service";
import { AuthDto } from "./dto";
import * as argon from "argon2"
import { PrismaClientKnownRequestError } from "@prisma/client/runtime/library";
import { JwtService } from "@nestjs/jwt";
import { config } from "process";
import { ConfigModule, ConfigService } from "@nestjs/config";
import { promises } from "dns";

@Injectable()
export class AuthService {
    constructor(
        private prisma : PrismaService, 
        private jwt: JwtService,
        private config: ConfigService,
        ){}
    async signup(dto: AuthDto) {
        const hash = await argon.hash(dto.password);
        try {
            const user = await this.prisma.user.create({
                data: {
                    login: dto.login,
                    // email: dto.email,
                    hash,
                },
            });
            delete user.hash;
            return (user);
        }
        catch (error){
            if (error instanceof PrismaClientKnownRequestError) {
                if (error.code === 'P2002')
                    throw (new ForbiddenException('Credentials taken'));
            }
            else
                throw(error);
        }
    }

    // async signin(dto : AuthDto) {
    //     const user = await this.prisma.user.findUnique({
    //         where: {
    //             email: dto.email,
    //         },
    //     });
    //     if (!user)
    //         throw (new ForbiddenException('Credentials incorrect'));
    //     const pwdMatches = await argon.verify(user.hash, dto.password);
    //     if (!pwdMatches) throw(new ForbiddenException('password missmatch'));
    //     return (this.signtoken(user.id, user.email));
    // }

    async signtoken(userid: number, email: string): Promise<{access_token: string}>{
        const payload = {
            sub: userid,
            email,
        };
        const token = await this.jwt.signAsync(payload, {
            expiresIn: '1h',
            secret: this.config.get('JWT_SECRET'),
    });
        return  ({
            access_token: token,
        })
    }
}