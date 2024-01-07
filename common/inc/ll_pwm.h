#ifndef __LL_PWM_H
#define __LL_PWM_H

#ifdef __cplusplus
extern "C" {
#endif

#include "rv_common.h"

#define PWM_PWMSCALE_POS                        (0U)
#define PWM_PWMSCALE_MSK                        (0x7U << PWM_PWMSCALE_POS)
#define PWM_PWMSTICKY_POS                       (8U)
#define PWM_PWMSTICKY_MSK                       (0x1U << PWM_PWMSTICKY_POS)
#define PWM_PWMZEROCMP_POS                      (9U)
#define PWM_PWMZEROCMP_MSK                      (0x1U << PWM_PWMZEROCMP_POS)
#define PWM_PWMDEGLITCH_POS                     (10U)
#define PWM_PWMDEGLITCH_MSK                     (0x1U << PWM_PWMDEGLITCH_POS)
#define PWM_PWMENALWAYS_POS                     (12U)
#define PWM_PWMENALWAYS_MSK                     (0x1U << PWM_PWMENALWAYS_POS)
#define PWM_PWMENONESHOT_POS                    (13U)
#define PWM_PWMENONESHOT_MSK                    (0x1U << PWM_PWMENONESHOT_POS)
#define PWM_PWMCMP0CENTER_POS                   (16U)
#define PWM_PWMCMP0CENTER_MSK                   (0x1U << PWM_PWMCMP0CENTER_POS)
#define PWM_PWMCMP1CENTER_POS                   (17U)
#define PWM_PWMCMP1CENTER_MSK                   (0x1U << PWM_PWMCMP1CENTER_POS)
#define PWM_PWMCMP2CENTER_POS                   (18U)
#define PWM_PWMCMP2CENTER_MSK                   (0x1U << PWM_PWMCMP2CENTER_POS)
#define PWM_PWMCMP3CENTER_POS                   (19U)
#define PWM_PWMCMP3CENTER_MSK                   (0x1U << PWM_PWMCMP3CENTER_POS)
#define PWM_PWMCMP0GANG_POS                     (24U)
#define PWM_PWMCMP0GANG_MSK                     (0x1U << PWM_PWMCMP0GANG_POS)
#define PWM_PWMCMP1GANG_POS                     (25U)
#define PWM_PWMCMP1GANG_MSK                     (0x1U << PWM_PWMCMP1GANG_POS)
#define PWM_PWMCMP2GANG_POS                     (26U)
#define PWM_PWMCMP2GANG_MSK                     (0x1U << PWM_PWMCMP2GANG_POS)
#define PWM_PWMCMP3GANG_POS                     (27U)
#define PWM_PWMCMP3GANG_MSK                     (0x1U << PWM_PWMCMP3GANG_POS)
#define PWM_PWMCMP0IP_POS                       (28U)
#define PWM_PWMCMP0IP_MSK                       (0x1U << PWM_PWMCMP0IP_POS)
#define PWM_PWMCMP1IP_POS                       (29U)
#define PWM_PWMCMP1IP_MSK                       (0x1U << PWM_PWMCMP1IP_POS)
#define PWM_PWMCMP2IP_POS                       (30U)
#define PWM_PWMCMP2IP_MSK                       (0x1U << PWM_PWMCMP2IP_POS)
#define PWM_PWMCMP3IP_POS                       (31U)
#define PWM_PWMCMP3IP_MSK                       (0x1U << PWM_PWMCMP3IP_POS)

#define PWM_CMP_REG_POS                         (0U)
#define PWM_CMP_REG_MSK                         (0xFFFFU << PWM_PWMCMP3IP_POS)


typedef struct {
  __IO uint32_t PWM_CFG;
  uint32_t RESERVED0;
  __IO uint32_t PWM_CTR;
  uint32_t RESERVED1;
  __IO uint32_t PWM_PWMS;
  uint32_t RESERVED2[3];
  __IO uint32_t PWM_CMP0;
  __IO uint32_t PWM_CMP1;
  __IO uint32_t PWM_CMP2;
  __IO uint32_t PWM_CMP3;
} PWM_TypeDef;


#ifdef __cplusplus
}
#endif

#endif /* __LL_PWM_H */
