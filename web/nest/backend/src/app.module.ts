import { Module } from '@nestjs/common';
import { AuthModule } from 'src/auth/auth.module';
import { UserModule } from './user/user.module';
import { PrismaModule } from './prisma/prisma.module';
import { ConfigModule } from '@nestjs/config';
import { GatewayModule } from './gateway/gateway.module';
import { FriendModule } from './friend/friend.module';
import { ChannelModule } from './channel/channel.module';

@Module({
  imports: [
    GatewayModule,
    AuthModule,
     UserModule, 
     PrismaModule, 
     ConfigModule.forRoot({
      isGlobal: true,
     }), FriendModule, ChannelModule, 
    ],
  controllers: [],
  providers: [],
})
export class AppModule {}
