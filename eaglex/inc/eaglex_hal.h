/**
 * @file hal.h
 * @author -T.K.- / t_k_233@outlook.com
 * @brief 
 * @version 0.1
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __EAGLEX_HAL_H
#define __EAGLEX_HAL_H


#ifdef __cplusplus
extern "C" {
#endif

#include "rv_arch.h"
#include "rv_common.h"
#include "eaglex.h"
#include "eaglex_hal_core.h"
#include "eaglex_hal_clint.h"
#include "eaglex_hal_gpio.h"
#include "eaglex_hal_i2c.h"
#include "eaglex_hal_plic.h"
#include "eaglex_hal_rcc.h"
#include "eaglex_hal_spi.h"
#include "eaglex_hal_uart.h"

#define HXTAL_FREQ    100000000                         // Hz
#define SYS_CLK_FREQ  HXTAL_FREQ                        // Hz
#define MTIME_FREQ    (SYS_CLK_FREQ / 100000)           // tick per milliseconds

void HAL_init();

uint64_t HAL_getTick();

void HAL_delay(uint64_t time);

#ifdef __cplusplus
}
#endif

#endif /* __EAGLEX_HAL_H */