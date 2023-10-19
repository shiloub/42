import { MyGateway } from 'src/gateway/gateway';
import { PrismaService } from 'src/prisma/prisma.service';
export declare class FriendService {
    private prisma;
    private Gateway;
    constructor(prisma: PrismaService, Gateway: MyGateway);
    sendRequest(body: any, sender: any): Promise<string>;
}
