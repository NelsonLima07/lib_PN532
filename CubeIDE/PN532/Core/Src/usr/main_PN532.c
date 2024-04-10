#include "usr/main_PN532.h"
#include "usr/J3_PN532.h"

#include "i2c.h"


#define TEMPO_LED_EXTERNO 3000 /* Tempo definido em milisegundos ms  */


int SendI2C(uint8_t _endereco, uint8_t *_msg, uint8_t tam)
{
  char rxBuffer[63];
  //  HAL_I2C_Master_Transmit_IT(&hi2c1, _endereco, _msg, tam);
  HAL_I2C_Master_Transmit(&hi2c1, _endereco, _msg, tam, 100);

  HAL_I2C_Master_Receive(&hi2c1, _endereco, rxBuffer, 10, 500);

  printf(rxBuffer);


  /*

  HAL_GPIO_TogglePin(LED_EXTERNO_GPIO_Port, LED_EXTERNO_Pin);
  HAL_Delay(200);
  HAL_GPIO_TogglePin(LED_EXTERNO_GPIO_Port, LED_EXTERNO_Pin);
  HAL_Delay(200);
  HAL_GPIO_TogglePin(LED_EXTERNO_GPIO_Port, LED_EXTERNO_Pin);
  HAL_Delay(200);
  HAL_GPIO_TogglePin(LED_EXTERNO_GPIO_Port, LED_EXTERNO_Pin);
  HAL_Delay(200);
  HAL_GPIO_TogglePin(LED_EXTERNO_GPIO_Port, LED_EXTERNO_Pin);
  HAL_Delay(200);
  HAL_GPIO_TogglePin(LED_EXTERNO_GPIO_Port, LED_EXTERNO_Pin);
  HAL_Delay(200);
  HAL_GPIO_TogglePin(LED_EXTERNO_GPIO_Port, LED_EXTERNO_Pin);
  HAL_Delay(200);
  HAL_GPIO_TogglePin(LED_EXTERNO_GPIO_Port, LED_EXTERNO_Pin);
  HAL_Delay(200);
  HAL_GPIO_TogglePin(LED_EXTERNO_GPIO_Port, LED_EXTERNO_Pin);
  */

  return 0;
}



int main_PN532 (void)
{
  uint32_t tmrLED = HAL_GetTick();
  TPN532* pn532;


  pn532 = j3_PN532_new(PN532_ADDRESS);
  j3_PN532_SetSendFunction(pn532, &SendI2C);

  j3_PN532_GravaTag(pn532, "0x00", 1);


  while(1)
    {
      //tmrLED = HAL_GetTick();
      if (HAL_GetTick() - tmrLED >= TEMPO_LED_EXTERNO)
      {
	tmrLED = HAL_GetTick();
	HAL_GPIO_TogglePin(LED_EXTERNO_GPIO_Port, LED_EXTERNO_Pin);
	tmrLED = HAL_GetTick();
      }
    }

  //HAL_Delay(1000);

}

/*
void HAL_I2C_MasterTxCpltCallback (I2C_HandleTypeDef * hi2c)
{
  // TX Done .. Do Something!

  HAL_GPIO_TogglePin(LED_EXTERNO_GPIO_Port, LED_EXTERNO_Pin);
  HAL_Delay(200);
  HAL_GPIO_TogglePin(LED_EXTERNO_GPIO_Port, LED_EXTERNO_Pin);
  HAL_Delay(200);
  HAL_GPIO_TogglePin(LED_EXTERNO_GPIO_Port, LED_EXTERNO_Pin);
  HAL_Delay(200);
  HAL_GPIO_TogglePin(LED_EXTERNO_GPIO_Port, LED_EXTERNO_Pin);
  HAL_Delay(200);
  HAL_GPIO_TogglePin(LED_EXTERNO_GPIO_Port, LED_EXTERNO_Pin);
  HAL_Delay(200);
  HAL_GPIO_TogglePin(LED_EXTERNO_GPIO_Port, LED_EXTERNO_Pin);
  HAL_Delay(200);
  HAL_GPIO_TogglePin(LED_EXTERNO_GPIO_Port, LED_EXTERNO_Pin);
  HAL_Delay(200);
  HAL_GPIO_TogglePin(LED_EXTERNO_GPIO_Port, LED_EXTERNO_Pin);
  HAL_Delay(200);
  HAL_GPIO_TogglePin(LED_EXTERNO_GPIO_Port, LED_EXTERNO_Pin);

}
*/


