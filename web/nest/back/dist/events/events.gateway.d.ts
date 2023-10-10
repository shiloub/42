import { OnGatewayConnection } from "@nestjs/websockets";
import { Server, Socket } from "socket.io";
export declare class eventsGateway implements OnGatewayConnection {
    server: Server;
    handleConnection(client: Socket): void;
    handleEvent(data: string, client: Socket): string;
}
