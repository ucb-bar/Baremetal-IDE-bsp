/**
 * @file hal_core.c
 * @author -T.K.- / t_k_233@outlook.com
 * @brief 
 * @version 0.1
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include "hal_core.h"


// void HAL_CORE_disableGlobalInterrupt() {
//   // Clear MPIE
//   uint32_t mask = (1U << 3U);
//   asm volatile("csrc mstatus, %0" :: "r"(mask));
// }

// void HAL_CORE_enableGlobalInterrupt() {
//   // Set MPIE
//   uint32_t mask = (1U << 3U);
//   asm volatile("csrs mstatus, %0" :: "r"(mask));
// }

// void HAL_CORE_disableIRQ(IRQn_Type IRQn) {
//   uint32_t mask = (1U << (uint32_t)IRQn);
//   asm volatile("csrc mie, %0" :: "r"(mask));
// }

// void HAL_CORE_enableIRQ(IRQn_Type IRQn) {
//   uint32_t mask = (1U << (uint32_t)IRQn);
//   asm volatile("csrs mie, %0" :: "r"(mask));
// }

// void HAL_CORE_clearIRQ(IRQn_Type IRQn) {
//   uint32_t mask = (1U << (uint32_t)IRQn);
//   asm volatile("csrc mip, %0" :: "r"(mask));
// }

uint64_t HAL_getTick() {
  return HAL_CLINT_getTime();
}

void HAL_delay(uint64_t time) {
  uint64_t target_tick = HAL_getTick() + (time * MTIME_FREQ);
  while (HAL_getTick() < target_tick) {
    // asm("nop");
  }
}

