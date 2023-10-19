import { AuthService } from "./auth.service";
import { AuthDto } from "./dto";
export declare class AuthController {
    private authservice;
    constructor(authservice: AuthService);
    signup(dto: AuthDto): Promise<{
        id: number;
        createdAt: Date;
        updatedAt: Date;
        email: string;
        hash: string;
        login: string;
        socket: string;
    }>;
    signin(dto: AuthDto): Promise<{
        access_token: string;
    }>;
}
