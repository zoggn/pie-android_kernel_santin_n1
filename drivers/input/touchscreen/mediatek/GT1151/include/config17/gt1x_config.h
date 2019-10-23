/* drivers/input/touchscreen/gt1x_generic.h
 *
 * 2010 - 2014 Goodix Technology.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be a reference
 * to you, when you are integrating the GOODiX's CTP IC into your system,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * Version: 1.0
 * Revision Record:
 *      V1.0:  first release. 2014/09/28.
 *
 */
#ifndef _GT1X_CONFIG_H_
#define _GT1X_CONFIG_H_
/***************************PART2:TODO define**********************************/
/* TODO define your config for Sensor_ID == 0 here, if needed */
#define GTP_CFG_GROUP0 {\
0x0C, 0x38, 0x04, 0x80, 0x07, 0x05, 0x3D, 0x08, 0x00, 0x08, \
0x00, 0x7F, 0x46, 0x37, 0x5E, 0x00, 0x11, 0x00, 0x11, 0x24, \
0x1E, 0x78, 0x87, 0xA5, 0xC8, 0x0A, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x87, 0x27, 0x18, 0x39, \
0x3B, 0xD3, 0x08, 0x08, 0x6D, 0x38, 0x2D, 0x03, 0x24, 0x00, \
0x03, 0x19, 0x78, 0x80, 0x94, 0x02, 0x05, 0x03, 0x04, 0xED, \
0x28, 0xAD, 0x38, 0x8F, 0x48, 0x7F, 0x58, 0x78, 0x68, 0x75, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x14, 0x03, \
0x0F, 0x14, 0x20, 0x95, 0x0F, 0x07, 0x0F, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, \
0x12, 0x13, 0x1F, 0x1E, 0x1D, 0x1C, 0x1B, 0x1A, 0x19, 0x18, \
0x17, 0x16, 0x15, 0x14, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, \
0xFF, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, \
0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0xFF, 0xFF, 0xFF, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xD9, 0x33, 0x01, \
}
/* TODO define your config for Sensor_ID == 1 here, if needed */
#define GTP_CFG_GROUP1 {\
}
/* TODO define your config for Sensor_ID == 2 here, if needed */
#define GTP_CFG_GROUP2 {\
}
/* TODO define your config for Sensor_ID == 3 here, if needed */
#define GTP_CFG_GROUP3 {\
}
/* TODO define your config for Sensor_ID == 4 here, if needed */
#define GTP_CFG_GROUP4 {\
}
/* TODO define your config for Sensor_ID == 5 here, if needed */
#define GTP_CFG_GROUP5 {\
}
/*
 *         Charger Configs
 */
/* TODO define your config for Sensor_ID == 0 here, if needed */
#define GTP_CHARGER_CFG_GROUP0 {\
0x41, 0x38, 0x04, 0x80, 0x07, 0x05, 0x34, 0x00, 0x01, 0x0F, 0x23, 0x0F, \
0x50, 0x3C, 0x03, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17, \
0x19, 0x1D, 0x14, 0x8B, 0x2B, 0x0E, 0x24, 0x22, 0x31, 0x0D, 0x00, 0x00, \
0x00, 0x03, 0x33, 0x1C, 0x00, 0x01, 0x00, 0x00, 0x00, 0x03, 0xFF, 0xFF, \
0x00, 0x46, 0x1E, 0x14, 0x50, 0x94, 0xC5, 0x02, 0x00, 0x00, 0x00, 0x04, \
0xAC, 0x17, 0x00, 0x8E, 0x1E, 0x00, 0x75, 0x28, 0x00, 0x64, 0x35, 0x00, \
0x59, 0x46, 0x00, 0x59, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x14, 0x08, 0x03, 0x10, \
0x24, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x02, 0x04, 0x06, 0x08, 0x0A, 0x0C, 0x0E, 0x10, \
0x12, 0x14, 0x16, 0x18, 0x1A, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, \
0x04, 0x06, 0x08, 0x0A, 0x0C, 0x0F, 0x10, 0x12, 0x13, 0x16, 0x18, 0x1C, \
0x1D, 0x1E, 0x1F, 0x20, 0x21, 0x22, 0x24, 0x26, 0xFF, 0xFF, 0xFF, 0xFF, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0xDA, 0x01\
}
/* TODO define your config for Sensor_ID == 1 here, if needed */
#define GTP_CHARGER_CFG_GROUP1 {\
}
/* TODO define your config for Sensor_ID == 2 here, if needed */
#define GTP_CHARGER_CFG_GROUP2 {\
}
/* TODO define your config for Sensor_ID == 3 here, if needed */
#define GTP_CHARGER_CFG_GROUP3 {\
}
/* TODO define your config for Sensor_ID == 4 here, if needed */
#define GTP_CHARGER_CFG_GROUP4 {\
}
/* TODO define your config for Sensor_ID == 5 here, if needed */
#define GTP_CHARGER_CFG_GROUP5 {\
}
/*
 *         Smart Cover Configs
 */
/* TODO define your config for Sensor_ID == 0 here, if needed */
#define GTP_SMART_COVER_CFG_GROUP0 {\
0x41, 0x38, 0x04, 0x80, 0x07, 0x05, 0x34, 0x00, 0x01, 0x0F, 0x23, 0x0F, \
0x50, 0x3C, 0x03, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17, \
0x19, 0x1D, 0x14, 0x8B, 0x2B, 0x0E, 0x24, 0x22, 0x31, 0x0D, 0x00, 0x00, \
0x00, 0x03, 0x33, 0x1C, 0x00, 0x01, 0x00, 0x00, 0x00, 0x03, 0xFF, 0xFF, \
0x00, 0x46, 0x1E, 0x14, 0x50, 0x94, 0xC5, 0x02, 0x00, 0x00, 0x00, 0x04, \
0xAC, 0x17, 0x00, 0x8E, 0x1E, 0x00, 0x75, 0x28, 0x00, 0x64, 0x35, 0x00, \
0x59, 0x46, 0x00, 0x59, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x14, 0x08, 0x03, 0x10, \
0x24, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x02, 0x04, 0x06, 0x08, 0x0A, 0x0C, 0x0E, 0x10, \
0x12, 0x14, 0x16, 0x18, 0x1A, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, \
0x04, 0x06, 0x08, 0x0A, 0x0C, 0x0F, 0x10, 0x12, 0x13, 0x16, 0x18, 0x1C, \
0x1D, 0x1E, 0x1F, 0x20, 0x21, 0x22, 0x24, 0x26, 0xFF, 0xFF, 0xFF, 0xFF, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,\
0x00, 0x00, 0x00, 0x00, 0xDA, 0x01\
}
/* TODO define your config for Sendor_ID == 0 here, if needed */
#define GTP_SMART_COVER_CFG_GROUP1 {\
}
/* TODO define your config for Sendor_ID == 0 here, if needed */
#define GTP_SMART_COVER_CFG_GROUP2 {\
}
/* TODO define your config for Sendor_ID == 0 here, if needed */
#define GTP_SMART_COVER_CFG_GROUP3 {\
}
/* TODO define your config for Sendor_ID == 0 here, if needed */
#define GTP_SMART_COVER_CFG_GROUP4 {\
}
/* TODO define your config for Sendor_ID == 0 here, if needed */
#define GTP_SMART_COVER_CFG_GROUP5 {\
}
#endif /* _GT1X_CONFIG_H_ */
