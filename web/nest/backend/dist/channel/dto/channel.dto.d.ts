declare enum ChannelType {
    PRIVATE = "PRIVATE",
    PROTECTED = "PROTECTED",
    PUBLIC = "PUBLIC",
    DIRECT = "DIRECT"
}
export declare class ChannelDto {
    name: string;
    type: ChannelType;
    password: string;
}
export declare class idDto {
    id: number;
}
export {};
