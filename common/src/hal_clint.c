/**
 * @file hal_clint.c
 * @author -T.K.- / t_k_233@outlook.com
 * @brief 
 * @version 0.1
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "hal_clint.h"

/**
 * @brief Get current time
 * 
 * This function returns the current time as stated in the mtime register.
 * 
 * @param CLINTx CLINT peripheral
 * @return uint64_t current time
 */
uint64_t HAL_CLINT_getTime(CLINT_TypeDef *CLINTx) {
  #if __riscv_xlen == 32
  uint32_t time_lo;
  uint32_t time_hi;

  do {
    time_hi = *((__IO uint32_t *)(&CLINTx->MTIME) + 1);
    time_lo = *((__IO uint32_t *)(&CLINTx->MTIME));
  } while (*((__IO uint32_t *)(&CLINTx->MTIME) + 1) != time_hi);

  return (((uint64_t)time_hi) << 32U) | time_lo;
  #else
  return CLINTx->MTIME;
  #endif
}

/**
 * @brief Set target interrupt time
 * 
 * This function sets the target interrupt time for the given hart.
 * 
 * @param CLINTx CLINT peripheral
 * @param hartid hart ID
 * @param time time to set
 */
void HAL_CLINT_setTimerInterruptTarget(CLINT_TypeDef *CLINTx, uint32_t hartid, uint64_t time) {
  #if __riscv_xlen == 32
  *((__IO uint32_t *)(&CLINTx->MTIMECMP[hartid] + 1)) = 0xFFFFFFFF;
  *((__IO uint32_t *)(&CLINTx->MTIMECMP[hartid])) = (uint32_t)time;
  *((__IO uint32_t *)(&CLINTx->MTIMECMP[hartid])) = (uint32_t)(time >> 32);
  #else
  CLINTx->MTIMECMP[hartid] = time;
  #endif
}