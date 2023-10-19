import { Controller, Post, Body, UseGuards, Get } from '@nestjs/common';
import { ChannelService } from './channel.service';
import { ChannelDto } from './dto/channel.dto';
// import { JwtAuthGuard } from 'src/auth/jwt-auth.guard'; // Assurez-vous d'importer votre propre JwtAuthGuard

@Controller('channel')
// @UseGuards(JwtAuthGuard) // Vous pouvez appliquer votre propre stratégie d'authentification ici
export class ChannelController {
  constructor(private readonly channelService: ChannelService) {}

  @Post()
  async createChannel(@Body() channelDto: ChannelDto) {
    try {
      const channel = await this.channelService.createChannel(channelDto);
      return { channel };
    } catch (error) {
      return { error: `Une erreur s\'est produite lors de la création du canal: ${error}`};
    }
  }

  @Get()
  async getChannels () {
    try {
      const channels = await this.channelService.getChannels();
      return {channels} ;

    }
    catch (error) {
      return { error: `Une erreur s\'est produite lors de la recupération des channels: ${error}`};
    }
  }
}