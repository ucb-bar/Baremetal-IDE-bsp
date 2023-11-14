/**
 * @file hal_plic.h
 * @author -T.K.- / t_k_233@outlook.com
 * @brief 
 * @version 0.1
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __HAL_PLIC_H
#define __HAL_PLIC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "rv_common.h"

#define PLIC_BASE               0x0C000000U
#define PLIC                    ((PLIC_TypeDef *)PLIC_BASE)
#define PLIC_EXTRA              ((PLIC_Extra_TypeDef *)(PLIC_BASE + 0x00200000U))

/* Peripheral Struct Definition */
typedef struct {
  __IO uint32_t priorities[1024];
  __I  uint32_t pendings[1024];
  __IO uint32_t enables[1024];
} PLIC_TypeDef;

// because the maximum struct size is 65535, we need to split PLIC content
typedef struct {
  PLIC_ContextControl_TypeDef context_controls[1024];
} PLIC_Extra_TypeDef;

typedef struct {
  __IO uint32_t priority_threshold;
  __IO uint32_t claim_complete;
} PLIC_ContextControl_TypeDef;


void HAL_PLIC_disable(uint32_t hart_id, uint32_t irq_id);

void HAL_PLIC_enable(uint32_t hart_id, uint32_t irq_id);

void HAL_PLIC_setPriority(uint32_t irq_id, uint32_t priority);

void HAL_PLIC_setPriorityThreshold(uint32_t hart_id, uint32_t priority);

uint32_t HAL_PLIC_claimIRQ(uint32_t hart_id);

void HAL_PLIC_completeIRQ(uint32_t hart_id, uint32_t irq_id);


#ifdef __cplusplus
}
#endif

#endif /* __HAL_PLIC_H */