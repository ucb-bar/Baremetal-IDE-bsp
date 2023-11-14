/**
 * @file hal_rcc.h
 * @author -T.K.- / t_k_233@outlook.com
 * @brief 
 * @version 0.1
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __BEARLYML23_HAL_RCC_H
#define __BEARLYML23_HAL_RCC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "bearlyml23_hal.h"


typedef struct {
  __IO uint32_t TILE0_RESET;      /** RocketTile 0 */   // 0x00
  __IO uint32_t TILE1_RESET;      /** RocketTile 1 */   // 0x04
  __IO uint32_t TILE2_RESET;      /** RocketTile 2 */   // 0x08
  __IO uint32_t TILE3_RESET;      /** RocketTile 3 */   // 0x0C
  uint32_t RESERVED0[1020];
  __IO uint32_t TILE0_CLKGATE;    /** RocketTile 0 */   // 0x1000
  __IO uint32_t TILE1_CLKGATE;    /** RocketTile 1 */   // 0x1004
  __IO uint32_t TILE2_CLKGATE;    /** RocketTile 2 */   // 0x1008
  __IO uint32_t TILE3_CLKGATE;    /** RocketTile 3 */   // 0x100C
  uint32_t RESERVED1[1020];
  __IO uint32_t CLK_SEL;          /** Selects the system clock. 0: External slow clock, 1: PLL clock */
  __IO uint32_t DEBUG_CLK_EN;                           // 0x2004
  __IO uint32_t DEBUG_CLK_SEL;                          // 0x2008
  __IO uint32_t DEBUG_CLK_DIV;                          // 0x200C
  uint32_t RESERVED2[1020];
  __IO uint32_t FBUS_CLK_DIV;                           // 0x3000
  __IO uint32_t UNCORE_CLK_DIV;                         // 0x3004
  __IO uint32_t TILE0_CLK_DIV;                          // 0x3008
  __IO uint32_t TILE1_CLK_DIV;                          // 0x300C
  __IO uint32_t TILE2_CLK_DIV;                          // 0x3010
  __IO uint32_t TILE3_CLK_DIV;                          // 0x3014
} RCC_TypeDef;

typedef struct {
  __IO uint32_t FZ_TIGHT_LOOPB;                         // 0x00
  __IO uint32_t FZ_LOCKFORCE;                           // 0x04
  __IO uint32_t FZ_LOCKCNT;                             // 0x08
  __IO uint32_t FZ_LOCKTHRESH;                          // 0x0C
  __IO uint32_t FZ_PFD_PW;                              // 0x10
  __IO uint32_t FZ_DCA_CTRL;                            // 0x14
  __IO uint32_t FZ_DCA_CB;                              // 0x18
  __IO uint32_t FZ_IREFGEN;                             // 0x1c
  __IO uint32_t FZ_STARTUP;                             // 0x20
  __IO uint32_t FZ_CP1TRIM;                             // 0x24
  __IO uint32_t FZ_CP2TRIM;                             // 0x28
  __IO uint32_t FZ_NOPFDPWRGATE;                        // 0x2c
  __IO uint32_t FZ_PFDDLY;                              // 0X30
  __IO uint32_t FZ_CPNBIAS;                             // 0X34
  __IO uint32_t FZ_VCOTRIM;                             // 0X38
  __IO uint32_t FZ_SKADJ;                               // 0X3C
  __IO uint32_t FZ_VCOSEL;                              // 0X40
  __IO uint32_t FZ_SPARE;                               // 0X44
  __IO uint32_t FZ_LDO_FASTSTART;                       // 0x48
  __IO uint32_t FZ_LDO_BYPASS;                          // 0x4C
  __IO uint32_t FZ_LDO_VINVOLTSEL;                      // 0x50
  __IO uint32_t FZ_LDO_FBTRIM;                          // 0x54
  __IO uint32_t FZ_LDO_REFTRIM;                         // 0x58
  __IO uint32_t POWERGOOD_VNN;                          // 0x5C
  __IO uint32_t PLLEN;                                  // 0x60
  __IO uint32_t LDO_ENABLE;                             // 0x64
  __IO uint32_t BYPASS;                                 // 0x68
  __IO uint32_t RATIO;                                  // 0x6C
  __IO uint32_t FRACTION;                               // 0x70
  __IO uint32_t MDIV_RATIO;                             // 0x74
  __IO uint32_t ZDIV0_RATIO;                            // 0x78
  __IO uint32_t ZDIV0_RATIO_P5;                         // 0x7C
  __IO uint32_t ZDIV1_RATIO;                            // 0x80
  __IO uint32_t ZDIV1_RATIO_P5;                         // 0x84
  __IO uint32_t VCODIV_RATIO;                           // 0x88
  __IO uint32_t FZ_LDO_EXTREFSEL;                       // 0x8C
  __IO uint32_t SSC_FRAC_STEP;                          // 0x90
  __IO uint32_t SSC_CYC_TO_PEAK_M1;                     // 0x94
  __IO uint32_t SSC_EN;                                 // 0x98
  __IO uint32_t MASH_ORDER_PLUS_ONE;                    // 0x9C
  __IO uint32_t FZ_LOCKSTICKYB;                         // 0xA0
  __IO uint32_t FZ_LPFCLKSEL;                           // 0xA4
  __IO uint32_t IDVDISABLE_BI;                          // 0xA8
  __IO uint32_t IDVFREQAI;                              // 0xAC
  __IO uint32_t IDVFREQBI;                              // 0xB0
  __IO uint32_t IDVPULSEI;                              // 0xB4
  __IO uint32_t IDVTCLKI;                               // 0xB8
  __IO uint32_t IDVTCTRLI;                              // 0xBC
  __IO uint32_t IDVTDI;                                 // 0xC0
  __IO uint32_t IDVTRESI;                               // 0xC4
  __IO uint32_t IDFX_FSCAN_SDI;                         // 0xC8
  __IO uint32_t IDFX_FSCAN_MODE;                        // 0xCC
  __IO uint32_t IDFX_FSCAN_SHIFTEN;                     // 0xD0
  __IO uint32_t IDFX_FSCAN_RSTBYPEN;                    // 0xD4
  __IO uint32_t IDFX_FSCAN_BYPRSTB;                     // 0xD8
  __IO uint32_t IDFX_FSCAN_CLKUNGATE;                   // 0xDC
  __IO uint32_t TCK;                                    // 0xE0
  __IO uint32_t TCAPTUREDR; 		                        // 0xE4
  __IO uint32_t TDI;                                    // 0xE8
  __IO uint32_t TREG_EN; 		                            // 0xEC
  __IO uint32_t TRST_N; 		                            // 0xF0
  __IO uint32_t TSHIFTDR;                               // 0xF4
  __IO uint32_t TUPDATEDR;                              // 0xF8
  __IO uint32_t LDO_VREF;                               // 0xFC
  __IO uint32_t PLLFWEN_B;                              // 0x100
} PLL_TypeDef;

void HAL_RCC_InitSystemClock();

#ifdef __cplusplus
}
#endif

#endif /* __BEARLYML23_HAL_RCC_H */