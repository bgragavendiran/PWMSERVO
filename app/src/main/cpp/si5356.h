//
// Created by johnd on 13-10-2021.
//

#ifndef PWMSERVO_SI5356_H
#define PWMSERVO_SI5356_H

#include "i2c6.h"
#include<android/log.h>

#define SI5356_ADDRESS  0x70
#define LOCK_MASK 0x15
#define LOS_MASK 0x04

typedef struct Reg_Data{
    unsigned char Reg_Addr;
    unsigned char Reg_Val;
    unsigned char Reg_Mask;
} Reg_Data;

Reg_Data const Reg_Store[] = {
        {  0,0x00,0x00},
        {  1,0x00,0x00},
        {  2,0x00,0x00},
        {  3,0x00,0x00},
        {  4,0x00,0x00},
        {  5,0x00,0x00},
        {  6,0x08,0x1D},
        {  7,0x00,0x00},
        {  8,0x70,0x00},
        {  9,0x0F,0x00},
        { 10,0x00,0x00},
        { 11,0x00,0x00},
        { 12,0x00,0x00},
        { 13,0x00,0x00},
        { 14,0x00,0x00},
        { 15,0x00,0x00},
        { 16,0x00,0x00},
        { 17,0x00,0x00},
        { 18,0x00,0x00},
        { 19,0x00,0x00},
        { 20,0x00,0x00},
        { 21,0x00,0x00},
        { 22,0x00,0x00},
        { 23,0x00,0x00},
        { 24,0x00,0x00},
        { 25,0x00,0x00},
        { 26,0x00,0x00},
        { 27,0x70,0x80},
        { 28,0x37,0xFF},
        { 29,0x80,0xFF},
        { 30,0xA0,0xFF},
        { 31,0xC0,0xFF},
        { 32,0xC0,0xFF},
        { 33,0xC0,0xFF},
        { 34,0xC0,0xFF},
        { 35,0x00,0xFF},
        { 36,0x13,0x1F},
        { 37,0x13,0x1F},
        { 38,0x13,0x1F},
        { 39,0x13,0x1F},
        { 40,0xF7,0xFF},
        { 41,0x5E,0x7F},
        { 42,0x37,0x3F},
        { 43,0x00,0x00},
        { 44,0x00,0x00},
        { 45,0x00,0x00},
        { 46,0x00,0x00},
        { 47,0x14,0x3C},
        { 48,0x38,0x7F},
        { 49,0x90,0x7F},
        { 50,0xDE,0xC0},
        { 51,0x07,0x00},
        { 52,0x10,0x0C},
        { 53,0x00,0xFF},
        { 54,0x2A,0xFF},
        { 55,0x00,0xFF},
        { 56,0x00,0xFF},
        { 57,0x00,0xFF},
        { 58,0x00,0xFF},
        { 59,0x01,0xFF},
        { 60,0x00,0xFF},
        { 61,0x00,0xFF},
        { 62,0x00,0x3F},
        { 63,0x10,0x0C},
        { 64,0x00,0xFF},
        { 65,0x2A,0xFF},
        { 66,0x00,0xFF},
        { 67,0x00,0xFF},
        { 68,0x00,0xFF},
        { 69,0x00,0xFF},
        { 70,0x01,0xFF},
        { 71,0x00,0xFF},
        { 72,0x00,0xFF},
        { 73,0x00,0x3F},
        { 74,0x10,0x0C},
        { 75,0x00,0xFF},
        { 76,0x2A,0xFF},
        { 77,0x00,0xFF},
        { 78,0x00,0xFF},
        { 79,0x00,0xFF},
        { 80,0x00,0xFF},
        { 81,0x01,0xFF},
        { 82,0x00,0xFF},
        { 83,0x00,0xFF},
        { 84,0x00,0x3F},
        { 85,0x10,0x0C},
        { 86,0x00,0xFF},
        { 87,0x2A,0xFF},
        { 88,0x00,0xFF},
        { 89,0x00,0xFF},
        { 90,0x00,0xFF},
        { 91,0x00,0xFF},
        { 92,0x01,0xFF},
        { 93,0x00,0xFF},
        { 94,0x00,0xFF},
        { 95,0x00,0x3F},
        { 96,0x10,0x00},
        { 97,0x00,0xFF},
        { 98,0x2A,0xFF},
        { 99,0x00,0xFF},
        {100,0x00,0xFF},
        {101,0x00,0xFF},
        {102,0x00,0xFF},
        {103,0x01,0xFF},
        {104,0x00,0xFF},
        {105,0x00,0xFF},
        {106,0x80,0x3F},
        {107,0x00,0xFF},
        {108,0x00,0x7F},
        {109,0x00,0x00},
        {110,0x80,0xC0},
        {111,0x00,0xFF},
        {112,0x00,0x7F},
        {113,0x00,0x00},
        {114,0x80,0xC0},
        {115,0x00,0xFF},
        {116,0x80,0x7F},
        {117,0x00,0x00},
        {118,0x80,0xC0},
        {119,0x00,0xFF},
        {120,0x00,0xFF},
        {121,0x00,0x00},
        {122,0x80,0xC0},
        {123,0x00,0x00},
        {124,0x00,0x00},
        {125,0x00,0x00},
        {126,0x00,0x00},
        {127,0x00,0x00},
        {128,0x00,0x00},
        {129,0x00,0x0F},
        {130,0x00,0x0F},
        {131,0x00,0x00},
        {132,0x00,0x00},
        {133,0x00,0x00},
        {134,0x00,0x00},
        {135,0x00,0x00},
        {136,0x00,0x00},
        {137,0x00,0x00},
        {138,0x00,0x00},
        {139,0x00,0x00},
        {140,0x00,0x00},
        {141,0x00,0x00},
        {142,0x00,0x00},
        {143,0x00,0x00},
        {144,0x00,0x80},
        {145,0x00,0x00},
        {146,0xFF,0x00},
        {147,0x00,0x00},
        {148,0x00,0x00},
        {149,0x00,0x00},
        {150,0x00,0x00},
        {151,0x00,0x00},
        {152,0x00,0x00},
        {153,0x00,0x00},
        {154,0x00,0x00},
        {155,0x00,0x00},
        {156,0x00,0x00},
        {157,0x00,0x00},
        {158,0x00,0x0F},
        {159,0x00,0x0F},
        {160,0x00,0x00},
        {161,0x00,0x00},
        {162,0x00,0x00},
        {163,0x00,0x00},
        {164,0x00,0x00},
        {165,0x00,0x00},
        {166,0x00,0x00},
        {167,0x00,0x00},
        {168,0x00,0x00},
        {169,0x00,0x00},
        {170,0x00,0x00},
        {171,0x00,0x00},
        {172,0x00,0x00},
        {173,0x00,0x00},
        {174,0x00,0x00},
        {175,0x00,0x00},
        {176,0x00,0x00},
        {177,0x00,0x00},
        {178,0x00,0x00},
        {179,0x00,0x00},
        {180,0x00,0x00},
        {181,0x00,0x0F},
        {182,0x00,0x00},
        {183,0x00,0x00},
        {184,0x00,0x00},
        {185,0x00,0x00},
        {186,0x00,0x00},
        {187,0x00,0x00},
        {188,0x00,0x00},
        {189,0x00,0x00},
        {190,0x00,0x00},
        {191,0x00,0x00},
        {192,0x00,0x00},
        {193,0x00,0x00},
        {194,0x00,0x00},
        {195,0x00,0x00},
        {196,0x00,0x00},
        {197,0x00,0x00},
        {198,0x00,0x00},
        {199,0x00,0x00},
        {200,0x00,0x00},
        {201,0x00,0x00},
        {202,0x00,0x00},
        {203,0x00,0x0F},
        {204,0x00,0x00},
        {205,0x00,0x00},
        {206,0x00,0x00},
        {207,0x00,0x00},
        {208,0x00,0x00},
        {209,0x00,0x00},
        {210,0x00,0x00},
        {211,0x00,0x00},
        {212,0x00,0x00},
        {213,0x00,0x00},
        {214,0x00,0x00},
        {215,0x00,0x00},
        {216,0x00,0x00},
        {217,0x00,0x00},
        {218,0x00,0x00},
        {219,0x00,0x00},
        {220,0x00,0x00},
        {221,0x0D,0x00},
        {222,0x00,0x00},
        {223,0x00,0x00},
        {224,0xF4,0x00},
        {225,0xF0,0x00},
        {226,0x00,0x00},
        {227,0x00,0x00},
        {228,0x00,0x00},
        {229,0x00,0x00},
        {231,0x00,0x00},
        {232,0x00,0x00},
        {233,0x00,0x00},
        {234,0x00,0x00},
        {235,0x00,0x00},
        {236,0x00,0x00},
        {237,0x00,0x00},
        {238,0x14,0x00},
        {239,0x00,0x00},
        {240,0x00,0x00},
        {242,0x02,0x00},
        {243,0xF0,0x00},
        {244,0x00,0x00},
        {245,0x00,0x00},
        {247,0x00,0x00},
        {248,0x00,0x00},
        {249,0xA8,0x00},
        {250,0x00,0x00},
        {251,0x84,0x00},
        {252,0x00,0x00},
        {253,0x00,0x00},
        {254,0x00,0x00},
        {255, 1, 0xFF}, // set page bit to 1
        {  0,0x00,0x00},
        {  1,0x00,0x00},
        {  2,0x00,0x00},
        {  3,0x00,0x00},
        {  4,0x00,0x00},
        {  5,0x00,0x00},
        {  6,0x00,0x00},
        {  7,0x00,0x00},
        {  8,0x00,0x00},
        {  9,0x00,0x00},
        { 10,0x00,0x00},
        { 11,0x00,0x00},
        { 12,0x00,0x00},
        { 13,0x00,0x00},
        { 14,0x00,0x00},
        { 15,0x00,0x00},
        { 16,0x00,0x00},
        { 17,0x01,0x00},
        { 18,0x00,0x00},
        { 19,0x00,0x00},
        { 20,0x90,0x00},
        { 21,0x31,0x00},
        { 22,0x00,0x00},
        { 23,0x00,0x00},
        { 24,0x01,0x00},
        { 25,0x00,0x00},
        { 26,0x00,0x00},
        { 27,0x00,0x00},
        { 28,0x00,0x00},
        { 29,0x00,0x00},
        { 30,0x00,0x00},
        { 31,0x00,0xFF},
        { 32,0x00,0xFF},
        { 33,0x01,0xFF},
        { 34,0x00,0xFF},
        { 35,0x00,0xFF},
        { 36,0x90,0xFF},
        { 37,0x31,0xFF},
        { 38,0x00,0xFF},
        { 39,0x00,0xFF},
        { 40,0x01,0xFF},
        { 41,0x00,0xFF},
        { 42,0x00,0xFF},
        { 43,0x00,0x0F},
        { 44,0x00,0x00},
        { 45,0x00,0x00},
        { 46,0x00,0x00},
        { 47,0x00,0xFF},
        { 48,0x00,0xFF},
        { 49,0x01,0xFF},
        { 50,0x00,0xFF},
        { 51,0x00,0xFF},
        { 52,0x90,0xFF},
        { 53,0x31,0xFF},
        { 54,0x00,0xFF},
        { 55,0x00,0xFF},
        { 56,0x01,0xFF},
        { 57,0x00,0xFF},
        { 58,0x00,0xFF},
        { 59,0x00,0x0F},
        { 60,0x00,0x00},
        { 61,0x00,0x00},
        { 62,0x00,0x00},
        { 63,0x00,0xFF},
        { 64,0x00,0xFF},
        { 65,0x01,0xFF},
        { 66,0x00,0xFF},
        { 67,0x00,0xFF},
        { 68,0x90,0xFF},
        { 69,0x31,0xFF},
        { 70,0x00,0xFF},
        { 71,0x00,0xFF},
        { 72,0x01,0xFF},
        { 73,0x00,0xFF},
        { 74,0x00,0xFF},
        { 75,0x00,0x0F},
        { 76,0x00,0x00},
        { 77,0x00,0x00},
        { 78,0x00,0x00},
        { 79,0x00,0xFF},
        { 80,0x00,0xFF},
        { 81,0x00,0xFF},
        { 82,0x00,0xFF},
        { 83,0x00,0xFF},
        { 84,0x90,0xFF},
        { 85,0x31,0xFF},
        { 86,0x00,0xFF},
        { 87,0x00,0xFF},
        { 88,0x01,0xFF},
        { 89,0x00,0xFF},
        { 90,0x00,0xFF},
        { 91,0x00,0x0F},
        { 92,0x00,0x00},
        { 93,0x00,0x00},
        { 94,0x00,0x00},
        {255, 0, 0xFF} };

uint8_t si5356_read(uint8_t reg_addr)
{
    opendevice();
    uint8_t buf;
    read_i2c_device_8(SI5356_ADDRESS, reg_addr, &buf);
    closedevice();
    return buf;
}
int si5356_write(uint8_t reg_addr,uint8_t buf)
{
    opendevice();
    write_i2c_device_8(SI5356_ADDRESS, reg_addr, &buf);
    closedevice();
    return 0;
}
void si5356_init() {
    si5356_write(255, 0x00); //Page 1
    si5356_write(230, 0x10); //OEB_ALL = 1
    si5356_write(241, 0xE5); //DIS_LOL = 1
    while(si5356_read(2)!=0x38) {
        si5356_write(255, 0x00); //Page 1
        si5356_write(28, 0x37); //Set the clock
        si5356_write(29, 0x80); //Set the clock
        si5356_write(30, 0xA0); //Set the clock
    }
    for (int i = 0; i < ARRAY_SIZE(Reg_Store); i++) {
        uint8_t addr = Reg_Store[i].Reg_Addr;
        uint8_t valu = Reg_Store[i].Reg_Val;
        uint8_t mask = Reg_Store[i].Reg_Mask;
        if (mask != 0x00) {
            if (mask == 0xFF) {
                si5356_write(addr, valu);
            } else {
                si5356_write(addr, (valu & mask) | (si5356_read(addr) & (~mask)));
            }
        }
    }
    while ((si5356_read(218) & LOS_MASK) != 0);
    si5356_write(246, 0x02); //SOFT_RESET
    usleep(25000);
    si5356_write(241, 0x65); //DIS_LOL = 0
    while ((si5356_read(218) & LOCK_MASK) != 0);
    __android_log_print(ANDROID_LOG_ERROR,"si5356","si5356_read(%d)=0x%x",0,si5356_read(0));
    __android_log_print(ANDROID_LOG_ERROR,"si5356","si5356_read(%d)=0x%x",1,si5356_read(1));
    __android_log_print(ANDROID_LOG_ERROR,"si5356","si5356_read(%d)=0x%x",2,si5356_read(2));
    __android_log_print(ANDROID_LOG_ERROR,"si5356","si5356_read(%d)=0x%x",3,si5356_read(3));
    __android_log_print(ANDROID_LOG_ERROR,"si5356","si5356_read(%d)=0x%x",4,si5356_read(4));
    __android_log_print(ANDROID_LOG_ERROR,"si5356","si5356_read(%d)=0x%x",5,si5356_read(5));
    __android_log_print(ANDROID_LOG_ERROR,"si5356","si5356_read(%d)=0x%x",218,si5356_read(218));
}
void si5356_ledon_365nm()
{
    //clk1 - Reg 110, Mask 0xCO, Value 0x40
    uint8_t valu = 0x40;
    uint8_t mask = 0xC0;
    uint8_t addr = 110;
    si5356_write(255, 0x00); //Page 1
    si5356_write(addr, (valu & mask) | (si5356_read(addr) & (~mask)));
    while ((si5356_read(218) & LOS_MASK) != 0);
    si5356_write(246, 0x02); //SOFT_RESET
    usleep(25000);
    si5356_write(241, 0x65); //DIS_LOL = 0
    while ((si5356_read(218) & LOCK_MASK) != 0);
}
void si5356_ledon_395nm()
{
    //clk3 - Reg 114, Mask 0xCO, Value 0x40
    uint8_t valu = 0x40;
    uint8_t mask = 0xC0;
    uint8_t addr = 114;
    si5356_write(255, 0x00); //Page 1
    si5356_write(addr, (valu & mask) | (si5356_read(addr) & (~mask)));
    while ((si5356_read(218) & LOS_MASK) != 0);
    si5356_write(246, 0x02); //SOFT_RESET
    usleep(25000);
    si5356_write(241, 0x65); //DIS_LOL = 0
    while ((si5356_read(218) & LOCK_MASK) != 0);
}
void si5356_ledon_415nm()
{
    //clk5 - Reg 118, Mask 0xCO, Value 0x40
    uint8_t valu = 0x40;
    uint8_t mask = 0xC0;
    uint8_t addr = 118;
    si5356_write(255, 0x00); //Page 1
    si5356_write(addr, (valu & mask) | (si5356_read(addr) & (~mask)));
    while ((si5356_read(218) & LOS_MASK) != 0);
    si5356_write(246, 0x02); //SOFT_RESET
    usleep(25000);
    si5356_write(241, 0x65); //DIS_LOL = 0
    while ((si5356_read(218) & LOCK_MASK) != 0);
}
void si5356_ledon_whinm()
{
    //clk7 - Reg 122, Mask 0xCO, Value 0x40
    uint8_t valu = 0x40;
    uint8_t mask = 0xC0;
    uint8_t addr = 122;
    si5356_write(255, 0x00); //Page 1
    si5356_write(addr, (valu & mask) | (si5356_read(addr) & (~mask)));
    while ((si5356_read(218) & LOS_MASK) != 0);
    si5356_write(246, 0x02); //SOFT_RESET
    usleep(25000);
    si5356_write(241, 0x65); //DIS_LOL = 0
    while ((si5356_read(218) & LOCK_MASK) != 0);
}
void si5356_ledoff_365nm()
{
    //clk1 - Reg 110, Mask 0xCO, Value 0x40
    uint8_t valu = 0x80;
    uint8_t mask = 0xC0;
    uint8_t addr = 110;
    si5356_write(255, 0x00); //Page 1
    si5356_write(addr, (valu & mask) | (si5356_read(addr) & (~mask)));
    while ((si5356_read(218) & LOS_MASK) != 0);
    si5356_write(246, 0x02); //SOFT_RESET
    usleep(25000);
    si5356_write(241, 0x65); //DIS_LOL = 0
    while ((si5356_read(218) & LOCK_MASK) != 0);
}
void si5356_ledoff_395nm()
{
    //clk3 - Reg 114, Mask 0xCO, Value 0x40
    uint8_t valu = 0x80;
    uint8_t mask = 0xC0;
    uint8_t addr = 114;
    si5356_write(255, 0x00); //Page 1
    si5356_write(addr, (valu & mask) | (si5356_read(addr) & (~mask)));
    while ((si5356_read(218) & LOS_MASK) != 0);
    si5356_write(246, 0x02); //SOFT_RESET
    usleep(25000);
    si5356_write(241, 0x65); //DIS_LOL = 0
    while ((si5356_read(218) & LOCK_MASK) != 0);
}
void si5356_ledoff_415nm()
{
    //clk5 - Reg 118, Mask 0xCO, Value 0x40
    uint8_t valu = 0x80;
    uint8_t mask = 0xC0;
    uint8_t addr = 118;
    si5356_write(255, 0x00); //Page 1
    si5356_write(addr, (valu & mask) | (si5356_read(addr) & (~mask)));
    while ((si5356_read(218) & LOS_MASK) != 0);
    si5356_write(246, 0x02); //SOFT_RESET
    usleep(25000);
    si5356_write(241, 0x65); //DIS_LOL = 0
    while ((si5356_read(218) & LOCK_MASK) != 0);
}
void si5356_ledoff_whinm()
{
    //clk7 - Reg 122, Mask 0xCO, Value 0x40
    uint8_t valu = 0x80;
    uint8_t mask = 0xC0;
    uint8_t addr = 122;
    si5356_write(255, 0x00); //Page 1
    si5356_write(addr, (valu & mask) | (si5356_read(addr) & (~mask)));
    while ((si5356_read(218) & LOS_MASK) != 0);
    si5356_write(246, 0x02); //SOFT_RESET
    usleep(25000);
    si5356_write(241, 0x65); //DIS_LOL = 0
    while ((si5356_read(218) & LOCK_MASK) != 0);
}
#endif //PWMSERVO_SI5356_H