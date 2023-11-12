/**
 * @file hal_gpio.h
 * @author -T.K.- / t_k_233@outlook.com
 * @brief 
 * @version 0.1
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __HAL_GPIO_H
#define __HAL_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

#include "rv_common.h"

typedef enum {
  GPIO_PIN_0 = 0b0001U,
  GPIO_PIN_1 = 0b0010U,
  GPIO_PIN_2 = 0b0100U,
  GPIO_PIN_3 = 0b1000U,
} GPIO_PIN;

typedef enum {
  GPIO_MODE_INPUT,
  GPIO_MODE_OUTPUT,
  GPIO_MODE_INOUT,
  GPIO_MODE_ALTERNATE_FUNCTION
} GPIO_Mode;

typedef enum {
  GPIO_PULL_NONE,
  GPIO_PULL_UP
} GPIO_Pull;

typedef enum {
  GPIO_DS_WEAK,
  GPIO_DS_STRONG
} GPIO_DriveStrength;

typedef struct {
  GPIO_Mode mode;
  GPIO_Pull pull;
  GPIO_DriveStrength drive_strength;
} GPIO_InitTypeDef;

typedef struct {
  __I  uint32_t INPUT_VAL;                      /** pin value */
  __IO uint32_t INPUT_EN;                       /** pin input enable */
  __IO uint32_t OUTPUT_EN;                      /** Pin output enable */
  __IO uint32_t OUTPUT_VAL;                     /** Output value */
  __IO uint32_t PUE;                            /** Internal pull-up enable */
  __IO uint32_t DS;                             /** Pin drive strength */
  __IO uint32_t RISE_IE;                        /** Rise interrupt enable */
  __IO uint32_t RISE_IP;                        /** Rise interrupt pending */
  __IO uint32_t FALL_IE;                        /** Fall interrupt enable */
  __IO uint32_t FALL_IP;                        /** Fall interrupt pending */
  __IO uint32_t HIGH_IE;                        /** High interrupt pending */
  __IO uint32_t HIGH_IP;                        /** High interrupt pending */
  __IO uint32_t LOW_IE;                         /** Low interrupt pending */
  __IO uint32_t LOW_IP;                         /** Low interrupt pending */
  __IO uint32_t OUT_XOR;                        /** Output XOR (invert) */
} GPIO_TypeDef;

void HAL_GPIO_init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_init, GPIO_PIN pin);

uint8_t HAL_GPIO_readPin(GPIO_TypeDef *GPIOx, GPIO_PIN pin);

void HAL_GPIO_writePin(GPIO_TypeDef *GPIOx, GPIO_PIN pin, uint8_t value);

#ifdef __cplusplus
}
#endif

#endif /* __HAL_GPIO_H */