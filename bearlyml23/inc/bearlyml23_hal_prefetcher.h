/**
 * @file hal_rcc.h
 * @author -T.K.- / t_k_233@outlook.com
 * @brief 
 * @version 0.1
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __BEARLYML23_HAL_PREFETCHER_H
#define __BEARLYML23_HAL_PREFETCHER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "bearlyml23_hal.h"


typedef struct {
  __IO uint32_t EN;
} PREFETCHER_TypeDef;

#ifdef __cplusplus
}
#endif

#endif /* __BEARLYML23_HAL_PREFETCHER_H */