import { IsEmail, IsEnum, IsNotEmpty, IsNumber, IsOptional, IsString, isNotEmpty, isNumber } from "class-validator"

enum ChannelType {
    PRIVATE = 'PRIVATE',
    PROTECTED = 'PROTECTED',
    PUBLIC = 'PUBLIC',
    DIRECT = 'DIRECT',
}

export class ChannelDto {
   @IsNotEmpty()
   @IsString()
   name: string;

   @IsEnum(ChannelType)
   type: ChannelType;

   @IsOptional()
   @IsString()
   password: string;
}

export class idDto {
    @IsNumber()
    id: number;
}