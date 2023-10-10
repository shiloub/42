import { Injectable } from "@nestjs/common";
import { ConnectedSocket, MessageBody, OnGatewayConnection, SubscribeMessage, WebSocketGateway, WebSocketServer} from "@nestjs/websockets";
import { Server, Socket } from "socket.io";

@Injectable()
@WebSocketGateway(3000)
export class eventsGateway implements OnGatewayConnection{

    @WebSocketServer() server: Server;
    handleConnection(client: Socket) {
        console.log('client ${client.id} connected');
    }

    @SubscribeMessage('event')
    handleEvent(@MessageBody() data: string, @ConnectedSocket() client: Socket) :string {
        return data;
    }
}
