/**
 * @file hal_plic.c
 * @author -T.K.- / t_k_233@outlook.com
 * @brief 
 * @version 0.1
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "hal_plic.h"


void HAL_PLIC_disable(PLIC_TypeDef *PLIC, PLIC_ContextControl_TypeDef *PLIC_CC, uint32_t hart_id, uint32_t irq_id) {
  uint32_t bit_index = irq_id & 0x1F;
  CLEAR_BITS(PLIC->enables[hart_id], 1 << bit_index);
}

void HAL_PLIC_enable(PLIC_TypeDef *PLIC, PLIC_ContextControl_TypeDef *PLIC_CC, uint32_t hart_id, uint32_t irq_id) {
  uint32_t bit_index = irq_id & 0x1F;
  SET_BITS(PLIC->enables[hart_id], 1 << bit_index);
}

void HAL_PLIC_setPriority(PLIC_TypeDef *PLIC, PLIC_ContextControl_TypeDef *PLIC_CC, uint32_t irq_id, uint32_t priority) {
  PLIC->priorities[irq_id] = priority;
}

void HAL_PLIC_setPriorityThreshold(PLIC_TypeDef *PLIC, PLIC_ContextControl_TypeDef *PLIC_CC, uint32_t hart_id, uint32_t priority) {
  PLIC_CC->context_controls[hart_id].priority_threshold = priority;
}

uint32_t HAL_PLIC_claimIRQ(PLIC_TypeDef *PLIC, PLIC_ContextControl_TypeDef *PLIC_CC, uint32_t hart_id) {
  return PLIC_CC->context_controls[hart_id].claim_complete;
}

void HAL_PLIC_completeIRQ(PLIC_TypeDef *PLIC, PLIC_ContextControl_TypeDef *PLIC_CC, uint32_t hart_id, uint32_t irq_id) {
  PLIC_CC->context_controls[hart_id].claim_complete = irq_id;
}
