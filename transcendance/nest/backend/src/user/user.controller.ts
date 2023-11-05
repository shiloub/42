import { Body, Controller, Get, Post, Query, Req, UseGuards } from '@nestjs/common';
import { Request } from 'express';
// import { jwtGuard } from 'src/auth/guard';
import { UserService } from './user.service';
import { AddFriendDto } from './dto/user.dto';

// @UseGuards(jwtGuard)
@Controller('users')
export class UserController {
    constructor(private userService: UserService){}
    @Get('me')
    getme(@Req() req: Request) {
        return (req.user);
    }
    @Get('other')
    async getuser(@Query('login') login: string)
    {
        try {
            const user = await this.userService.getUser(login);
            return ({user});
        }
        catch {
            return {error: "404 User not found"}
        }
    }

    @Get('friends')
    async getFriends(@Query('login') login: string)
    {
        try {
            const users = await this.userService.getFriends(login);
            return {users};
        }
        catch {
            return {error: "404 User not found"}
        }
    }

    @Get('blocked')
    async getBlocked(@Query('login') login: string)
    {
        try {
            const users = await this.userService.getBlocked(login);
            return ({users});
        }
        catch {
            return {error: "404 User not found"}
        }
    }

    @Post('addFriend')
    async addFriend(@Body() dto: AddFriendDto) {
        try {
          const added = await this.userService.addFriend(dto.login, dto.target);
          return ({added})
        } 
        catch (error) {
          return { error: `you cant add this user`};
        }
    }

    @Post('delFriend')
    async delFriend(@Body() dto: AddFriendDto) {
        try {
          const added = await this.userService.delFriend(dto.login, dto.target);
          return ({added})
        } 
        catch (error) {
          return { error: `you cant add this user`};
        }
    }

    @Post('blockUser')
    async blockUser(@Body() dto: AddFriendDto) {
        try {
         const blocked = await this.userService.blockUser(dto.login, dto.target);
         return ({blocked});
        } 
        catch (error) {
          return { error: `you cant block this user`};
        }
    }

    @Post('unblockUser')
    async unblockUser(@Body() dto: AddFriendDto) {
        try {
         const blocked = await this.userService.unblockUser(dto.login, dto.target);
         return ({blocked});
        } 
        catch (error) {
          return { error: `you cant block this user`};
        }
    }

}
