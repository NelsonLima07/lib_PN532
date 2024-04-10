/* */
#ifndef __MAIN_J3_PN532_H
#define __MAIN_J3_PN532_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
//#include "i2c.h"

#define PN532_ADDRESS 0x24

#define PN532_CMD_VERSION         0x00
#define PN532_DATA_PACKET_SIZE     64

typedef int TfuncSend_I2C(uint8_t _endereco, uint8_t *_msg, uint8_t _tam);

struct TPN532{
    //I2C_HandleTypeDef* i2c;
    uint8_t address;
    uint8_t *buffer;
    TfuncSend_I2C *ptrFuncSend_I2C;
};
typedef struct TPN532 TPN532;


//TPN532* j3_PN532_new(I2C_HandleTypeDef* _i2c, uint8_t _i2c_address); /* Retorna um ponteiro para um PN532 */
TPN532* j3_PN532_new(uint8_t _i2c_address);/* Retorna um ponteiro para um PN532 */
uint8_t j3_PN532_SetSendFunction(TPN532 *_pn532, TfuncSend_I2C *_ptrFuncSend_I2C);

uint8_t j3_PN532_GravaTag(TPN532 *_pn532, uint8_t *_msg, uint8_t _tam); /*  */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_J3_PN532_H */
