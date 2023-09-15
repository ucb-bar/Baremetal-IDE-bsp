/**
 * @file hal_rcc.h
 * @author -T.K.- / t_k_233@outlook.com
 * @brief 
 * @version 0.1
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __EAGLEX_HAL_RCC_H
#define __EAGLEX_HAL_RCC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "eaglex_hal.h"

static inline void HAL_RCC_disableCluster(uint32_t cluster_id) {
  SET_BITS(RCC->CLUSTER_RESETS, 1U << cluster_id);
}

static inline void HAL_RCC_enableCluster(uint32_t cluster_id) {
  CLEAR_BITS(RCC->CLUSTER_RESETS, 1U << cluster_id);
}

void HAL_RCC_initSystemClock();


#ifdef __cplusplus
}
#endif

#endif /* __EAGLEX_HAL_RCC_H */