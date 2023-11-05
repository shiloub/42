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
exports.FortyTwoStrategy = void 0;
const common_1 = require("@nestjs/common");
const passport_1 = require("@nestjs/passport");
const passport_42_1 = require("passport-42");
const config_1 = require("@nestjs/config");
const prisma_service_1 = require("../../prisma/prisma.service");
let FortyTwoStrategy = class FortyTwoStrategy extends (0, passport_1.PassportStrategy)(passport_42_1.Strategy, '42strat') {
    constructor(config, prisma) {
        super({
            clientID: config.get('UID'),
            clientSecret: config.get('SECRET'),
            callbackURL: "http://localhost:3001/auth/42/callback"
        });
        this.prisma = prisma;
    }
    async validate(accessToken, refreshToken, profile, cb) {
        console.log('42 API strategy :');
        const user = await this.prisma.user.findUnique({ where: { username: profile.username } });
        if (!user) {
            console.log('the user ', profile.username, ' dont exist');
            console.log(' ----- user creation in process -----');
            const user = await this.prisma.user.create({
                data: {
                    login: profile.username,
                    sessionId: getRandomSessionId(),
                    username: profile.username,
                },
            });
            console.log(' ------ user successfully created -----');
            return user;
        }
        else {
            console.log(' the user ', profile.username, ' already exist :');
            console.dir(user, { depth: null });
            const updatedUser = await this.prisma.user.update({
                where: { username: profile.username },
                data: { sessionId: getRandomSessionId() }
            });
            return updatedUser;
        }
    }
};
exports.FortyTwoStrategy = FortyTwoStrategy;
exports.FortyTwoStrategy = FortyTwoStrategy = __decorate([
    (0, common_1.Injectable)(),
    __metadata("design:paramtypes", [config_1.ConfigService, prisma_service_1.PrismaService])
], FortyTwoStrategy);
function getRandomSessionId() {
    let result = '';
    const chain = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789';
    const chainLength = chain.length;
    for (let counter = 0; counter < 16; counter++)
        result += chain.charAt(Math.floor(Math.random() * chainLength));
    return result;
}
//# sourceMappingURL=42.strategy.js.map