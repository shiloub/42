import { Module } from '@nestjs/common';
import { AuthModule } from 'src/auth/auth.module';
import { UserModule } from './user/user.module';
import { BookmarkModule } from './bookmark/bookmark.module';
import { PrismaModule } from './prisma/prisma.module';
import { ConfigModule } from '@nestjs/config';
import { EventsModule } from './events/events.module';

@Module({
  imports: [AuthModule,
     UserModule, 
     BookmarkModule, 
     PrismaModule, 
     ConfigModule.forRoot({
      isGlobal: true,
     }), 
     EventsModule,
    ],
  controllers: [],
  providers: [],
})
export class AppModule {}
