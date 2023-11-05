import { SocketGateway } from './socket.gateway';
export declare class SocketService {
    private socketGateway;
    constructor(socketGateway: SocketGateway);
    sendEvent(login: string, eventName: string, data: any): void;
}
