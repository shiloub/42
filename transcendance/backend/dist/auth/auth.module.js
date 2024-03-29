"use strict";
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.AuthModule = void 0;
const common_1 = require("@nestjs/common");
const auth_controller_1 = require("./auth.controller");
const auth_service_1 = require("./auth.service");
const jwt_1 = require("@nestjs/jwt");
const strategy_1 = require("./strategy");
const _42_strategy_1 = require("./strategy/42.strategy");
const user_module_1 = require("../user/user.module");
const prisma_service_1 = require("../prisma/prisma.service");
const user_service_1 = require("../user/user.service");
const _2fa_jwt_strategy_1 = require("./strategy/2fa.jwt.strategy");
let AuthModule = class AuthModule {
};
exports.AuthModule = AuthModule;
exports.AuthModule = AuthModule = __decorate([
    (0, common_1.Module)({
        imports: [jwt_1.JwtModule.register({}), user_module_1.UserModule],
        controllers: [auth_controller_1.AuthController],
        providers: [auth_service_1.AuthService, strategy_1.JwtStrategy, _42_strategy_1.FortyTwoStrategy, prisma_service_1.PrismaService, user_service_1.UserService, _2fa_jwt_strategy_1.TwoFaJwtStrategy],
        exports: [auth_service_1.AuthService, strategy_1.JwtStrategy, _2fa_jwt_strategy_1.TwoFaJwtStrategy],
    })
], AuthModule);
//# sourceMappingURL=auth.module.js.map