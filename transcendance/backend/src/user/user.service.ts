import { Injectable } from '@nestjs/common';
import { User } from '@prisma/client';
import { send } from 'process';
import { PrismaService } from 'src/prisma/prisma.service';

@Injectable()
export class UserService {
    constructor(private prisma: PrismaService)  {}


    async findOneByUsername(username: string) {
		return this.prisma.user.findUnique({ where: { username: username } });
	}
    
    async getIdByLogin(login: string): Promise<number> {
        const user = await this.prisma.user.findFirst({
            where : {
                login,
            }
        })
        return (user.id);
    }

    async getUsernameByLogin(login: string): Promise<string> {
        const user = await this.prisma.user.findFirst({
            where : {
                login,
            }
        })
        return (user.username);
    }

    async getLoginById(id: number): Promise<string> {
        const user = await this.prisma.user.findUniqueOrThrow({
            where : {
                id,
            }
        })
        return (user.login);
    }

    async getUser(login: string): Promise<User> {
        const user = await this.prisma.user.findUniqueOrThrow({
            where: {
                login: login,
            }
        })
        return (user);
    }

    async addFriend(login: string, target: string): Promise<User> {
        const senderId = await this.getIdByLogin(login);
        const targetId = await this.getIdByLogin(target);

        const test = await this.prisma.userConnection.findMany({
            where : {
                targetId,
                fromId: senderId,
                followed: 1,
            }
        })

        if (test.length > 0)
        {
            console.log("already friends: throw");
            throw new Error("Already friend");
        }

        const userco = await this.prisma.userConnection.updateMany({
            where :{
                targetId,
                fromId: senderId,
            },
            data : {
                followed: 1
            }
        })
        console.log(userco.count);
        if (!userco.count){
            console.log("je cree un userco !");
            const newUserCo = await this.prisma.userConnection.create({
                data: {
                    targetId,
                    fromId: senderId,
                    blocked: 0,
                    followed: 1,
                }
            })
        }
        const added = await this.prisma.user.findUniqueOrThrow({
            where : {
                login: target,
            }
        })
        return (added)
    }


    async delFriend(login: string, target: string): Promise<User> {
        const senderId = await this.getIdByLogin(login);
        const targetId = await this.getIdByLogin(target);

        const test = await this.prisma.userConnection.findMany({
            where : {
                targetId,
                fromId: senderId,
                followed: 0,
            }
        })

        if (test.length > 0)
        {
            console.log("already not friends: throw");
            throw new Error("Already  not friend");
        }

        const userco = await this.prisma.userConnection.updateMany({
            where :{
                targetId,
                fromId: senderId,
            },
            data : {
                followed: 0,
            }
        })
        const added = await this.prisma.user.findUniqueOrThrow({
            where : {
                login: target,
            }
        })
        return (added)
    }

    async blockUser(login: string, target: string): Promise<User> {
        const senderId = await this.getIdByLogin(login);
        const targetId = await this.getIdByLogin(target);

        const test = await this.prisma.userConnection.findMany({
            where : {
                targetId,
                fromId: senderId,
                blocked: 1,
            }
        })

        if (test.length > 0)
        {
            console.log("already blocked: throw");
            throw new Error("Already blocked");
        }

        const userco = await this.prisma.userConnection.updateMany({
            where :{
                targetId,
                fromId: senderId,
            },
            data : {
                blocked: 1
            }
        })
        if (!userco){
            const newUserCo = await this.prisma.userConnection.create({
                data: {
                    targetId,
                    fromId: senderId,
                    blocked: 1,
                    followed: 0,
                }
            })
        }
        const blocked = await this.prisma.user.findUniqueOrThrow({
            where : {
                login: target,
            }
        })
        return (blocked)
    }
    async unblockUser(login: string, target: string): Promise<User> {
        const senderId = await this.getIdByLogin(login);
        const targetId = await this.getIdByLogin(target);

        const test = await this.prisma.userConnection.findMany({
            where : {
                targetId,
                fromId: senderId,
                blocked: 0,
            }
        })

        if (test.length > 0)
        {
            console.log("already unblocked: throw");
            throw new Error("Already unblocked");
        }

        const userco = await this.prisma.userConnection.updateMany({
            where :{
                targetId,
                fromId: senderId,
            },
            data : {
                blocked: 0
            }
        })
        const blocked = await this.prisma.user.findUniqueOrThrow({
            where : {
                login: target,
            }
        })
        return (blocked)
    }

    async getFriends(login:string) : Promise<string[]>{
        const user = await this.prisma.user.findUniqueOrThrow({
            where : {
                login,
            },
            include: {
                userConnections :{
                    where : {
                        followed: 1
                    },
                    select : {
                        targetId: true,
                    }
                }
            }
        })
        const usersPromises = user.userConnections.map(async (connection) => {
            const targetId = connection.targetId;
            return this.getLoginById(targetId);
        });
    
        const users = await Promise.all(usersPromises);
        return (users);
    }

    async getBlocked(login:string) : Promise<string[]>{
        const user = await this.prisma.user.findUniqueOrThrow({
            where : {
                login,
            },
            include: {
                userConnections :{
                    where : {
                        blocked: 1
                    },
                    select : {
                        targetId: true,
                    }
                }
            }
        })
        const usersPromises = user.userConnections.map(async (connection) => {
            const targetId = connection.targetId;
            return this.getLoginById(targetId);
        });
    
        const users = await Promise.all(usersPromises);
        return (users);
    }
} 
