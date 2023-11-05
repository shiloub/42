import { IsEmail, IsNotEmpty, IsString } from "class-validator"

export class AuthDto {
    @IsString()
    @IsNotEmpty()
    password :string;

    @IsString()
    @IsNotEmpty()
    login: string;
}