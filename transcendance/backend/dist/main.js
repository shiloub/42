"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const core_1 = require("@nestjs/core");
const app_module_1 = require("./app.module");
const common_1 = require("@nestjs/common");
const cookieParser = require("cookie-parser");
const jwt_global_1 = require("./auth/strategy/jwt.global");
const _2fa_global_1 = require("./auth/strategy/2fa.global");
async function bootstrap() {
    const app = await core_1.NestFactory.create(app_module_1.AppModule);
    app.enableCors({
        origin: 'http://localhost:3000',
        methods: 'GET,HEAD,PUT,PATCH,POST,DELETE',
        credentials: true,
    });
    app.useGlobalPipes(new common_1.ValidationPipe({
        whitelist: true,
    }));
    app.use(cookieParser());
    const reflect = app.get(core_1.Reflector);
    app.useGlobalGuards(new jwt_global_1.JwtAuthGuard(reflect));
    app.useGlobalGuards(new _2fa_global_1.TwoFaAuthGuard(reflect));
    await app.listen(3001);
}
bootstrap();
//# sourceMappingURL=main.js.map