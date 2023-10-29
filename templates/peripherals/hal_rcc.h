/**
 * @file hal_rcc.h
 * @author -T.K.- / t_k_233@outlook.com
 * @brief 
 * @version 0.1
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __{{ chipname | upper }}_HAL_RCC_H
#define __{{ chipname | upper }}_HAL_RCC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "{{ chipname }}_hal.h"

void HAL_RCC_InitSystemClock();

#ifdef __cplusplus
}
#endif

#endif /* __{{ chipname | upper }}_HAL_RCC_H */
