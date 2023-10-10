import { Module } from '@nestjs/common';
import { eventsGateway } from './events.gateway';

@Module({
    providers: [eventsGateway],
})
export class EventsModule {}
