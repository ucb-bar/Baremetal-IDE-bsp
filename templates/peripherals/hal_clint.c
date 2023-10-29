/**
 * @file hal_clint.c
 * @author -T.K.- / t_k_233@outlook.com
 * @brief 
 * @version 0.1
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "{{ chipname }}_hal_clint.h"
hi

// void HAL_CLINT_triggerSoftwareInterrupt(uint32_t hartid) {
//   SET_BITS(CLINT->MSIP0, 1U << (hartid));
// }

uint64_t HAL_CLINT_getTime() {
  uint32_t time_lo;
  uint32_t time_hi;

  do {
    time_hi = *((volatile uint32_t *)(&CLINT->MTIME) + 1);
    time_lo = *((volatile uint32_t *)(&CLINT->MTIME));
  } while (*((volatile uint32_t *)(&CLINT->MTIME) + 1) != time_hi);

  return (((uint64_t)time_hi) << 32U) | time_lo;
}

void HAL_CLINT_setTimerInterruptTarget(uint32_t hartid, uint64_t time) {
  *((volatile uint32_t *)(&CLINT->MTIMECMP0) + 4 * hartid + 1) = 0xffffffff;
  *((volatile uint32_t *)(&CLINT->MTIMECMP0) + 4 * hartid) = (uint32_t)time;
  *((volatile uint32_t *)(&CLINT->MTIMECMP0) + 4 * hartid + 1) = (uint32_t)(time >> 32);
}
