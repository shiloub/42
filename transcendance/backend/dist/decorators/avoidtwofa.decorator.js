"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.AvoidTwoFa = exports.IS_AVOIDTWOFA_KEY = void 0;
const common_1 = require("@nestjs/common");
exports.IS_AVOIDTWOFA_KEY = 'avoidTwoFa';
const AvoidTwoFa = () => (0, common_1.SetMetadata)(exports.IS_AVOIDTWOFA_KEY, true);
exports.AvoidTwoFa = AvoidTwoFa;
//# sourceMappingURL=avoidtwofa.decorator.js.map