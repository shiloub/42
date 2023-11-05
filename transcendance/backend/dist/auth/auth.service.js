"use strict";
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (this && this.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.AuthService = void 0;
const common_1 = require("@nestjs/common");
const prisma_service_1 = require("../prisma/prisma.service");
const jwt_1 = require("@nestjs/jwt");
const config_1 = require("@nestjs/config");
const otplib_1 = require("otplib");
let AuthService = class AuthService {
    constructor(prisma, jwt, config) {
        this.prisma = prisma;
        this.jwt = jwt;
        this.config = config;
    }
    async generateJwt(user, cookie_type) {
        const payload = {
            id: user.id,
            sessionId: user.sessionId,
            username: user.username,
            cookie_type: cookie_type
        };
        const secret = this.config.get('JWT_SECRET');
        try {
            const token = await this.jwt.signAsync(payload, { secret: secret });
            return { access_token: token };
        }
        catch (err) {
            throw new common_1.HttpException('[auth.service] [generateJwt] : jwt.signAsync : error catched', common_1.HttpStatus.INTERNAL_SERVER_ERROR);
        }
    }
    async launchTwoFa(userInfos) {
        const secret = otplib_1.authenticator.generateSecret();
        const otpAuthUrl = otplib_1.authenticator.keyuri(userInfos.username, 'TRANSCENDANCE', secret);
        return { otpAuthUrl, secret };
    }
    async twoFaActivate(user, twoFactorCode) {
        if (otplib_1.authenticator.verify({ token: twoFactorCode, secret: user.twoFaSecret }) === false)
            return false;
        return true;
    }
    async twoFaAuthenticate(user, twoFactorCode) {
        if (otplib_1.authenticator.verify({ token: twoFactorCode, secret: user.twoFaSecret }) === false)
            return false;
        return true;
    }
};
exports.AuthService = AuthService;
exports.AuthService = AuthService = __decorate([
    (0, common_1.Injectable)(),
    __metadata("design:paramtypes", [prisma_service_1.PrismaService, jwt_1.JwtService, config_1.ConfigService])
], AuthService);
//# sourceMappingURL=auth.service.js.map