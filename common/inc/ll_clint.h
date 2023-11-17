#ifndef __LL_CLINT_H
#define __LL_CLINT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "rv_common.h"


/* Peripheral Struct Definition */
typedef struct {
  __IO uint32_t MSIP0;                          /** MSIP Registers (1 bit wide) */
  __IO uint32_t MSIP1;                          /** MSIP Registers (1 bit wide) */
  __IO uint32_t MSIP2;                          /** MSIP Registers (1 bit wide) */
  __IO uint32_t MSIP3;                          /** MSIP Registers (1 bit wide) */
  uint32_t RESERVED0[4092];
  __IO uint64_t MTIMECMP0;                      /** MTIMECMP Registers */
  uint32_t RESERVED1[8188];
  __IO uint64_t MTIME;                          /** Timer Register */
} CLINT_TypeDef;


#ifdef __cplusplus
}
#endif

#endif /* __LL_CLINT_H */
