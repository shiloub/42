import { Injectable } from '@nestjs/common';
import { PrismaService } from 'src/prisma/prisma.service';

@Injectable()
export class UserService {
    constructor(private prisma: PrismaService)  {}

    async getIdByLogin(login: string): Promise<number> {
        const user = await this.prisma.user.findFirst({
            where : {
                login,
            }
        })
        return (user.id);
    }
}
