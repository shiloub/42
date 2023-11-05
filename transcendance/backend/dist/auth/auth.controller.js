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
var __param = (this && this.__param) || function (paramIndex, decorator) {
    return function (target, key) { decorator(target, key, paramIndex); }
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.AuthController = void 0;
const common_1 = require("@nestjs/common");
const auth_service_1 = require("./auth.service");
const passport_1 = require("@nestjs/passport");
const public_decorator_1 = require("../decorators/public.decorator");
const qrcode_1 = require("qrcode");
const prisma_service_1 = require("../prisma/prisma.service");
const avoidtwofa_decorator_1 = require("../decorators/avoidtwofa.decorator");
let AuthController = class AuthController {
    constructor(authService, prisma) {
        this.authService = authService;
        this.prisma = prisma;
    }
    shouldnt_be_called() {
        throw new common_1.HttpException('[auth.controller] [login42]: le handler de la route login42 ne devrait pas etre appelle', common_1.HttpStatus.INTERNAL_SERVER_ERROR);
    }
    async bar(req, response) {
        const token = await this.authService.generateJwt(req.user, 'basic_auth');
        response.cookie('AUTH_TOKEN', token, { httpOnly: false });
        response.redirect('http://localhost:3000/home');
    }
    async getqr(response, request) {
        const { otpAuthUrl, secret } = await this.authService.launchTwoFa(request.user);
        const result = await (0, qrcode_1.toDataURL)(otpAuthUrl);
        const updatedUser = await this.prisma.user.update({
            where: { username: request.user.username },
            data: { twoFaSecret: secret }
        });
        return (response.json(result));
    }
    async turnOnTwoFactorAuthentication(request, body, response) {
        const isCodeValid = await this.authService.twoFaActivate(request.user, body.twoFactorCode);
        if (!isCodeValid) {
            throw new common_1.HttpException('[auth.controller] [2fa activate]: mauvais code', common_1.HttpStatus.UNAUTHORIZED);
        }
        await this.prisma.user.update({
            where: { username: request.user.username },
            data: { twoFaEnabled: true }
        });
        const token = await this.authService.generateJwt(request.user, 'twofa');
        response.cookie('TWOFA_TOKEN', token, { httpOnly: false });
        response.send();
    }
    async twoFaAuthentication(request, body, response) {
        const isCodeValid = await this.authService.twoFaAuthenticate(request.user, body.twoFactorCode);
        if (!isCodeValid) {
            throw new common_1.HttpException('[auth.controller] [2fa activate]: mauvais code', common_1.HttpStatus.UNAUTHORIZED);
        }
        const token = await this.authService.generateJwt(request.user, 'twofa');
        response.cookie('TWOFA_TOKEN', token, { httpOnly: false });
        response.send();
    }
    check1() {
    }
    check3(req) {
    }
    just_a_simple_test() {
    }
    async check_2fa_activation(request) {
        const currentUser = await this.prisma.user.findUnique({
            where: { username: request.user.username },
        });
        if (!currentUser.twoFaEnabled)
            throw new common_1.HttpException('[auth.controller] [check_2fa_validation]: 2FA INACTIF', common_1.HttpStatus.UNAUTHORIZED);
    }
    checkIsSigned() {
    }
};
exports.AuthController = AuthController;
__decorate([
    (0, public_decorator_1.Public)(),
    (0, common_1.UseGuards)((0, passport_1.AuthGuard)('42strat')),
    (0, common_1.Get)('login42'),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", []),
    __metadata("design:returntype", void 0)
], AuthController.prototype, "shouldnt_be_called", null);
__decorate([
    (0, public_decorator_1.Public)(),
    (0, common_1.UseGuards)((0, passport_1.AuthGuard)('42strat')),
    (0, common_1.Get)('42/callback'),
    __param(0, (0, common_1.Req)()),
    __param(1, (0, common_1.Res)()),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [Object, Object]),
    __metadata("design:returntype", Promise)
], AuthController.prototype, "bar", null);
__decorate([
    (0, common_1.Get)('2fa_getqr'),
    __param(0, (0, common_1.Res)()),
    __param(1, (0, common_1.Req)()),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [Object, Object]),
    __metadata("design:returntype", Promise)
], AuthController.prototype, "getqr", null);
__decorate([
    (0, common_1.Post)('2fa_activate'),
    __param(0, (0, common_1.Req)()),
    __param(1, (0, common_1.Body)()),
    __param(2, (0, common_1.Res)()),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [Object, Object, Object]),
    __metadata("design:returntype", Promise)
], AuthController.prototype, "turnOnTwoFactorAuthentication", null);
__decorate([
    (0, avoidtwofa_decorator_1.AvoidTwoFa)(),
    (0, common_1.Post)('2fa_authenticate'),
    __param(0, (0, common_1.Req)()),
    __param(1, (0, common_1.Body)()),
    __param(2, (0, common_1.Res)()),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [Object, Object, Object]),
    __metadata("design:returntype", Promise)
], AuthController.prototype, "twoFaAuthentication", null);
__decorate([
    (0, avoidtwofa_decorator_1.AvoidTwoFa)(),
    (0, common_1.Get)('check_auth_cookie'),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", []),
    __metadata("design:returntype", void 0)
], AuthController.prototype, "check1", null);
__decorate([
    (0, common_1.Get)('check_2fa_cookie'),
    __param(0, (0, common_1.Req)()),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [Object]),
    __metadata("design:returntype", void 0)
], AuthController.prototype, "check3", null);
__decorate([
    (0, common_1.Get)('simple_test'),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", []),
    __metadata("design:returntype", void 0)
], AuthController.prototype, "just_a_simple_test", null);
__decorate([
    (0, avoidtwofa_decorator_1.AvoidTwoFa)(),
    (0, common_1.Get)('check_2fa_activation'),
    __param(0, (0, common_1.Req)()),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [Object]),
    __metadata("design:returntype", Promise)
], AuthController.prototype, "check_2fa_activation", null);
__decorate([
    (0, avoidtwofa_decorator_1.AvoidTwoFa)(),
    (0, common_1.Get)('check_is_signed'),
    (0, common_1.HttpCode)(200),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", []),
    __metadata("design:returntype", void 0)
], AuthController.prototype, "checkIsSigned", null);
exports.AuthController = AuthController = __decorate([
    (0, common_1.Controller)('auth'),
    __metadata("design:paramtypes", [auth_service_1.AuthService, prisma_service_1.PrismaService])
], AuthController);
//# sourceMappingURL=auth.controller.js.map