/*
 * J3_PN532.c
 *
 *  Created on: Mar 31, 2024
 *      Author: Nelson Lima
 */
#include "usr/J3_PN532.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void j3_PN532_Send(TPN532* _pn532, uint8_t _cmd,  uint8_t *_msg,  uint8_t _tam)
{
  uint8_t packet[PN532_DATA_PACKET_SIZE];

   // Prepara o pacote de comando
  packet[0] = PN532_DATA_PACKET_SIZE - 1; // Tamanho total do pacote (sem CRC)
  packet[1] = _cmd;                 // Comando
  packet[2] = _tam;            // Tamanho dos dados (se houver)

  // Copia os dados para o pacote (se houver)
  if (_tam > 0) {
    memcpy(&packet[3], _msg, _tam);
  }

   // Envia o pacote I2C
   (_pn532->ptrFuncSend_I2C)(_pn532->address, packet, PN532_DATA_PACKET_SIZE);
}



//TPN532* j3_PN532_new(I2C_HandleTypeDef* _i2c, uint8_t _i2c_address)
TPN532* j3_PN532_new(uint8_t _i2c_address)
{
  TPN532* auxPN532;

  auxPN532 = malloc(sizeof(TPN532));
  auxPN532->address = _i2c_address;
  //auxPN532->i2c = _i2c;
  auxPN532->buffer = malloc(128 * 8 * sizeof(uint8_t));
  memset(auxPN532->buffer, 0x00, 128 * 8 * sizeof(uint8_t));



  return auxPN532;
}

uint8_t j3_PN532_SetSendFunction(TPN532 *_pn532, TfuncSend_I2C *_ptrFuncSend_I2C)
{
  _pn532->ptrFuncSend_I2C = _ptrFuncSend_I2C;
  return 0;
}

uint8_t j3_PN532_GravaTag(TPN532 *_pn532, uint8_t *_msg, uint8_t _tam)
{
  j3_PN532_Send(_pn532, PN532_CMD_VERSION, _msg, _tam);
  return 0;
}

