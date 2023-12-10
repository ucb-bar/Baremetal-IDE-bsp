#ifndef __HAL_PWM_H
#define __HAL_PWM_H

#ifdef __cplusplus
extern "C" {
#endif

#include "rv_common.h"
#include "ll_pwm.h"

typedef struct {
  uint pwmscale        : 4;
  uint RESERVED        : 4;
  uint pwmsticky       : 1;
  uint pwmzerocmp      : 1;
  uint pwmdeglitch     : 1;
  uint RESERVED1       : 1;
  uint pwmenalways     : 1;
  uint pwmenoneshot    : 1;
  uint RESERVED2       : 2;
  uint pwmcmp0center   : 1;
  uint pwmcmp1center   : 1;
  uint pwmcmp2center   : 1;
  uint pwmcmp3center   : 1;
  uint RESERVED3       : 4;
  uint pwmcmp0gang     : 1;
  uint pwmcmp1gang     : 1;
  uint pwmcmp2gang     : 1;
  uint pwmcmp3gang     : 1;
  uint pwmcmp0ip       : 1;
  uint pwmcmp1ip       : 1;
  uint pwmcmp2ip       : 1;
  uint pwmcmp3ip       : 1;
} PWM_InitTypeDef;

static inline void HAL_PWM_enable(PWM_TypeDef *PWMx) {
  SET_BITS(PWMx->PWM_CFG, PWM_PWMENALWAYS_MSK);
}

static inline void HAL_PWM_disable(PWM_TypeDef *PWMx) {
  CLEAR_BITS(PWMx->PWM_CFG, PWM_PWMENALWAYS_MSK);
}

static inline void HAL_PWM_setScale(PWM_TypeDef *PWMx, uint32_t value) {
  WRITE_BITS(PWMx->PWM_CFG, PWM_PWMSCALE_MSK, value << PWM_PWMSCALE_POS);
}

static inline void HAL_PWM_setCompareValue(PWM_TypeDef *PWMx, uint32_t idx,
                                       uint32_t value) {
  switch (idx) {
  case 0:
    PWMx->PWM_CMP0 = value;
    break;
  case 1:
    PWMx->PWM_CMP1 = value;
    break;
  case 2:
    PWMx->PWM_CMP2 = value;
    break;
  case 3:
    PWMx->PWM_CMP3 = value;
    break;
  }
}

static inline void HAL_PWM_trigger_oneshot(PWM_TypeDef *PWMx, uint32_t idx) {
  SET_BITS(PWMx->PWM_CFG, PWM_PWMENONESHOT_MSK);
}

void HAL_PWM_init(PWM_TypeDef *PWMx, PWM_InitTypeDef *PWM_init);

void HAL_PWM_stop(PWM_TypeDef *PWMx, uint32_t idx);

void HAL_PWM_setFrequency(PWM_TypeDef *PWMx, uint32_t idx, uint32_t freq);

uint32_t HAL_PWM_getFrequency(PWM_TypeDef *PWMx, uint32_t idx);

void HAL_PWM_setDutyCycle(PWM_TypeDef *PWMx, uint32_t idx, uint32_t duty, int phase_corr);

uint32_t HAL_PWM_getDutyCycle(PWM_TypeDef *PWMx, uint32_t idx);

void HAL_PWM_trigger(PWM_TypeDef *PWMx, uint32_t idx);


#ifdef __cplusplus
}
#endif

#endif /* __HAL_PWM_H */