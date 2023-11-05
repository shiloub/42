"use strict";
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (this && this.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.idDto = exports.DirectCreaDto = exports.UserloginDto = exports.ChannelJoinDto = exports.NameDto = exports.ChannelCreaDto = exports.SetAdminDto = exports.ChangePasswordDto = void 0;
const class_validator_1 = require("class-validator");
var ChannelType;
(function (ChannelType) {
    ChannelType["PRIVATE"] = "PRIVATE";
    ChannelType["PUBLIC"] = "PUBLIC";
    ChannelType["DIRECT"] = "DIRECT";
})(ChannelType || (ChannelType = {}));
class ChangePasswordDto {
}
exports.ChangePasswordDto = ChangePasswordDto;
__decorate([
    (0, class_validator_1.IsNotEmpty)(),
    (0, class_validator_1.IsString)(),
    __metadata("design:type", String)
], ChangePasswordDto.prototype, "name", void 0);
__decorate([
    (0, class_validator_1.IsString)(),
    __metadata("design:type", String)
], ChangePasswordDto.prototype, "password", void 0);
class SetAdminDto {
}
exports.SetAdminDto = SetAdminDto;
__decorate([
    (0, class_validator_1.IsNotEmpty)(),
    (0, class_validator_1.IsString)(),
    __metadata("design:type", String)
], SetAdminDto.prototype, "name", void 0);
__decorate([
    (0, class_validator_1.IsNotEmpty)(),
    (0, class_validator_1.IsString)(),
    __metadata("design:type", String)
], SetAdminDto.prototype, "login", void 0);
class ChannelCreaDto {
}
exports.ChannelCreaDto = ChannelCreaDto;
__decorate([
    (0, class_validator_1.IsNotEmpty)(),
    (0, class_validator_1.IsString)(),
    __metadata("design:type", String)
], ChannelCreaDto.prototype, "name", void 0);
__decorate([
    (0, class_validator_1.IsEnum)(ChannelType),
    __metadata("design:type", String)
], ChannelCreaDto.prototype, "type", void 0);
__decorate([
    (0, class_validator_1.IsOptional)(),
    (0, class_validator_1.IsString)(),
    __metadata("design:type", String)
], ChannelCreaDto.prototype, "password", void 0);
__decorate([
    (0, class_validator_1.IsString)(),
    (0, class_validator_1.IsNotEmpty)(),
    __metadata("design:type", String)
], ChannelCreaDto.prototype, "creatorLogin", void 0);
class NameDto {
}
exports.NameDto = NameDto;
__decorate([
    (0, class_validator_1.IsNotEmpty)(),
    (0, class_validator_1.IsString)(),
    __metadata("design:type", String)
], NameDto.prototype, "name", void 0);
class ChannelJoinDto {
}
exports.ChannelJoinDto = ChannelJoinDto;
__decorate([
    (0, class_validator_1.IsNotEmpty)(),
    (0, class_validator_1.IsString)(),
    __metadata("design:type", String)
], ChannelJoinDto.prototype, "name", void 0);
__decorate([
    (0, class_validator_1.IsNotEmpty)(),
    (0, class_validator_1.IsString)(),
    __metadata("design:type", String)
], ChannelJoinDto.prototype, "login", void 0);
__decorate([
    (0, class_validator_1.IsOptional)(),
    (0, class_validator_1.IsString)(),
    __metadata("design:type", String)
], ChannelJoinDto.prototype, "password", void 0);
class UserloginDto {
}
exports.UserloginDto = UserloginDto;
__decorate([
    (0, class_validator_1.IsString)(),
    (0, class_validator_1.IsNotEmpty)(),
    __metadata("design:type", String)
], UserloginDto.prototype, "login", void 0);
class DirectCreaDto {
}
exports.DirectCreaDto = DirectCreaDto;
__decorate([
    (0, class_validator_1.IsString)(),
    (0, class_validator_1.IsNotEmpty)(),
    __metadata("design:type", String)
], DirectCreaDto.prototype, "starterLogin", void 0);
__decorate([
    (0, class_validator_1.IsString)(),
    (0, class_validator_1.IsNotEmpty)(),
    __metadata("design:type", String)
], DirectCreaDto.prototype, "targetLogin", void 0);
__decorate([
    (0, class_validator_1.IsEnum)(ChannelType),
    __metadata("design:type", String)
], DirectCreaDto.prototype, "type", void 0);
class idDto {
}
exports.idDto = idDto;
__decorate([
    (0, class_validator_1.IsNumber)(),
    __metadata("design:type", Number)
], idDto.prototype, "id", void 0);
//# sourceMappingURL=channel.dto.js.map