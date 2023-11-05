declare enum ChannelType {
    PRIVATE = "PRIVATE",
    PUBLIC = "PUBLIC",
    DIRECT = "DIRECT"
}
export declare class ChangePasswordDto {
    name: string;
    password: string;
}
export declare class SetAdminDto {
    name: string;
    login: string;
}
export declare class ChannelCreaDto {
    name: string;
    type: ChannelType;
    password: string;
    creatorLogin: string;
}
export declare class NameDto {
    name: string;
}
export declare class ChannelJoinDto {
    name: string;
    login: string;
    password: string;
}
export declare class UserloginDto {
    login: string;
}
export declare class DirectCreaDto {
    starterLogin: string;
    targetLogin: string;
    type: ChannelType;
}
export declare class idDto {
    id: number;
}
export {};
