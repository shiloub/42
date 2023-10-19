import { Module } from '@nestjs/common';
import { FriendService } from './friend.service';
import { FriendController } from './friend.controller';
import { MyGateway } from 'src/gateway/gateway';

@Module({
  providers: [FriendService, MyGateway],
  controllers: [FriendController]
})
export class FriendModule {}
