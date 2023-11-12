/**
 * @file hal.h
 * @author -T.K.- / t_k_233@outlook.com
 * @brief 
 * @version 0.1
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __BEARLYML_HAL_H
#define __BEARLYML_HAL_H


#ifdef __cplusplus
extern "C" {
#endif

#include "bearlyml.h"
#include "bearlyml_hal_rcc.h"
#include "../../common/inc/rv_arch.h"
#include "../../common/inc/rv_common.h"
#include "../../common/inc/hal_core.h"
#include "../../common/inc/hal_clint.h"
#include "../../common/inc/hal_gpio.h"
#include "../../common/inc/hal_i2c.h"
#include "../../common/inc/hal_plic.h"
#include "../../common/inc/hal_uart.h"


#define HXTAL_FREQ     20000000                   // Hz
// #define HXTAL_FREQ    100000000                   // Hz
#define SYS_CLK_FREQ  HXTAL_FREQ / 2              // Hz
#define MTIME_FREQ    (SYS_CLK_FREQ / 100000)     // tick per milliseconds

void HAL_init();

uint64_t HAL_getTick();

void HAL_delay(uint64_t time);

#ifdef __cplusplus
}
#endif

#endif /* __BEARLYML_HAL_H */