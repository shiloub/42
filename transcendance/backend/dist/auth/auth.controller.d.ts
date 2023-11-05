import { AuthService } from "./auth.service";
import { PrismaService } from "src/prisma/prisma.service";
export declare class AuthController {
    private authService;
    private prisma;
    constructor(authService: AuthService, prisma: PrismaService);
    shouldnt_be_called(): void;
    bar(req: any, response: any): Promise<void>;
    getqr(response: any, request: any): Promise<any>;
    turnOnTwoFactorAuthentication(request: any, body: any, response: any): Promise<void>;
    twoFaAuthentication(request: any, body: any, response: any): Promise<void>;
    check1(): void;
    check3(req: any): void;
    just_a_simple_test(): void;
    check_2fa_activation(request: any): Promise<void>;
    checkIsSigned(): void;
}
