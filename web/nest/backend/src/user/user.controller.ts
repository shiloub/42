import { Controller, Get, Req, UseGuards } from '@nestjs/common';
import { Request } from 'express';
import { jwtGuard } from 'src/auth/guard';

@UseGuards(jwtGuard)
@Controller('users')
export class UserController {
    @Get('me')
    getme(@Req() req: Request) {
        return (req.user);
    }
}
