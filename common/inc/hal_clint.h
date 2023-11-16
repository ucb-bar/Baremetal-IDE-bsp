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
#include "ll_clint.h"


static inline void HAL_CLINT_clearSoftwareInterrupt(CLINT_TypeDef *CLINT, uint32_t hartid) {
  CLEAR_BITS(*(volatile uint32_t *)((CLINT->MSIP0) + 4 * hartid), 1U);
}

static inline void HAL_CLINT_triggerSoftwareInterrupt(CLINT_TypeDef *CLINT, uint32_t hartid) {
  SET_BITS(*(volatile uint32_t *)((CLINT->MSIP0) + 4 * hartid), 1U);
}

uint64_t HAL_CLINT_getTime(CLINT_TypeDef *CLINT);

void HAL_CLINT_setTimerInterruptTarget(CLINT_TypeDef *CLINT, uint32_t hartid, uint64_t time);

#ifdef __cplusplus
}
#endif

#endif /* __HAL_CLINT_H */
