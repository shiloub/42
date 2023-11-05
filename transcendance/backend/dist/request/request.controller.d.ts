import { RequestService } from './request.service';
export declare class RequestController {
    private readonly requestService;
    constructor(requestService: RequestService);
    get_all(req: any): any;
    get_username(req: any): any;
    get_id(req: any): any;
}
