import { ExecutionContext } from '@nestjs/common';
import { Reflector } from '@nestjs/core';
declare const TwoFaAuthGuard_base: import("@nestjs/passport").Type<import("@nestjs/passport").IAuthGuard>;
export declare class TwoFaAuthGuard extends TwoFaAuthGuard_base {
    private reflector;
    constructor(reflector: Reflector);
    canActivate(context: ExecutionContext): boolean | Promise<boolean> | import("rxjs").Observable<boolean>;
}
export {};
