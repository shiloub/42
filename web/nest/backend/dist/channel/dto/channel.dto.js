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
exports.idDto = exports.ChannelDto = void 0;
const class_validator_1 = require("class-validator");
var ChannelType;
(function (ChannelType) {
    ChannelType["PRIVATE"] = "PRIVATE";
    ChannelType["PROTECTED"] = "PROTECTED";
    ChannelType["PUBLIC"] = "PUBLIC";
    ChannelType["DIRECT"] = "DIRECT";
})(ChannelType || (ChannelType = {}));
class ChannelDto {
}
exports.ChannelDto = ChannelDto;
__decorate([
    (0, class_validator_1.IsNotEmpty)(),
    (0, class_validator_1.IsString)(),
    __metadata("design:type", String)
], ChannelDto.prototype, "name", void 0);
__decorate([
    (0, class_validator_1.IsEnum)(ChannelType),
    __metadata("design:type", String)
], ChannelDto.prototype, "type", void 0);
__decorate([
    (0, class_validator_1.IsOptional)(),
    (0, class_validator_1.IsString)(),
    __metadata("design:type", String)
], ChannelDto.prototype, "password", void 0);
class idDto {
}
exports.idDto = idDto;
__decorate([
    (0, class_validator_1.IsNumber)(),
    __metadata("design:type", Number)
], idDto.prototype, "id", void 0);
//# sourceMappingURL=channel.dto.js.map