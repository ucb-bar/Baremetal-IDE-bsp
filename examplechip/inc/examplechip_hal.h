/**
 * @file hal.h
 * @author -T.K.- / t_k_233@outlook.com
 * @brief 
 * @version 0.1
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __EXAMPLECHIP_HAL_H
#define __EXAMPLECHIP_HAL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "examplechip.h"

/**
 * This section controls which peripheral device is included in the application program.
 * To save the memory space, the unused peripheral device can be commented out.
 */
#include "hal_core.h"
#include "hal_clint.h"
#include "hal_gpio.h"
#include "hal_i2c.h"
#include "hal_plic.h"
#include "hal_uart.h"
#include "examplechip_hal_rcc.h"

/**
 * System Clock Configuration
 */
#define HXTAL_FREQ    32000000                          // Hz
#define SYS_CLK_FREQ  HXTAL_FREQ                        // Hz
#define MTIME_FREQ    (SYS_CLK_FREQ / 200000)           // tick per milliseconds

/**
 * Chip initialization routine
 */
void HAL_init();


#ifdef __cplusplus
}
#endif

#endif /* __EXAMPLECHIP_HAL_H */