/**
 * @file hal_clint.h
 * @author -T.K.- / t_k_233@outlook.com
 * @brief 
 * @version 0.1
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __HAL_CLINT_H
#define __HAL_CLINT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "rv_common.h"


/* Peripheral Struct Definition */
typedef struct {
  __IO uint32_t MSIP0;                          /** MSIP Registers (1 bit wide) */
  __IO uint32_t MSIP1;                          /** MSIP Registers (1 bit wide) */
  __IO uint32_t MSIP2;                          /** MSIP Registers (1 bit wide) */
  __IO uint32_t MSIP3;                          /** MSIP Registers (1 bit wide) */
  uint32_t RESERVED0[4092];
  __IO uint64_t MTIMECMP0;                      /** MTIMECMP Registers */
  uint32_t RESERVED1[8188];
  __IO uint64_t MTIME;                          /** Timer Register */
} CLINT_TypeDef;


static inline void HAL_CLINT_clearSoftwareInterrupt(uint32_t hartid) {
  CLEAR_BITS(*(volatile uint32_t *)((&CLINT->MSIP0) + 4 * hartid), 1U);
}

static inline void HAL_CLINT_triggerSoftwareInterrupt(uint32_t hartid) {
  SET_BITS(*(volatile uint32_t *)((&CLINT->MSIP0) + 4 * hartid), 1U);
}

uint64_t HAL_CLINT_getTime();

void HAL_CLINT_setTimerInterruptTarget(uint32_t hartid, uint64_t time);

#ifdef __cplusplus
}
#endif

#endif /* __HAL_CLINT_H */
