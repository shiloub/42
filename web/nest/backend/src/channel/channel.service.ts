import { Injectable } from '@nestjs/common';
import { PrismaService } from 'src/prisma/prisma.service';
import { Channel } from '@prisma/client';
import { ChannelDto, idDto } from './dto';
import { promises } from 'dns';

@Injectable()
export class ChannelService {
    constructor(private prisma: PrismaService) {}

    async createChannel(channelDto : ChannelDto): Promise<Channel> {
        if (this.prisma.channel.findFirst({
            where : {
                name: channelDto.name,
            }
        })) {
            console.log("je throw");
            throw ("Channel name already token");
        }
        // else {
        //     console.log(this.prisma.channel.findFirst({
        //         where : {
        //             name: channelDto.name,
        //         }
        //     }))
        // }
        return this.prisma.channel.create({
                data : {
                    name: channelDto.name,
                    password: channelDto.password,
                    type: channelDto.type,
                },
            });
    
    }

    async getChannels() : Promise<Channel[]> {
        return this.prisma.channel.findMany({
            where : {},
        });
    }

    async getChannel(dto: idDto) : Promise<Channel> {
        return this.prisma.channel.findUnique({
            where: {
                id: dto.id,
            },
        })
    }
}
