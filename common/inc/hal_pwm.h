#ifndef __HAL_PWM_H
#define __HAL_PWM_H

#ifdef __cplusplus
extern "C" {
#endif

#include "rv_common.h"
#include "ll_pwm.h"

typedef struct {
  // TODO: add PWM configuration parameters
} PWM_InitTypeDef;

static inline void HAL_PWM_enable(PWM_TypeDef *PWMx) {
  SET_BITS(pwm->PWM_CFG, PWM_PWMENALWAYS_MSK);
}

static inline void HAL_PWM_disable(PWM_TypeDef *PWMx) {
  CLEAR_BITS(pwm->PWM_CFG, PWM_PWMENALWAYS_MSK);
}

static inline void HAL_PWM_set_pwm_scale(PWM_TypeDef *PWMx, uint32_t value) {
  WRITE_BITS(pwm->PWM_CFG, PWM_PWMSCALE_MSK, value << PWM_PWMSCALE_POS);
}

static inline void HAL_PWM_set_cmp_val(PWM_TypeDef *PWMx, uint32_t idx,
                                       uint32_t value) {
  switch (idx) {
  case 0:
    pwm->PWM_CMP0 = value;
    break;
  case 1:
    pwm->PWM_CMP1 = value;
    break;
  case 2:
    pwm->PWM_CMP2 = value;
    break;
  case 3:
    pwm->PWM_CMP3 = value;
    break;
  }
}

static inline void HAL_PWM_trigger_oneshot(PWM_TypeDef *PWMx, uint32_t idx) {
  SET_BITS(pwm->PWM_CFG, PWM_PWMENONESHOT_MSK);
}

void HAL_PWM_init(PWM_TypeDef *PWMx, PWM_InitTypeDef *PWM_init);

void HAL_PWM_setFrequency(PWM_TypeDef *PWMx, uint32_t idx, uint32_t freq);

uint32_t HAL_PWM_getFrequency(PWM_TypeDef *PWMx, uint32_t idx);

void HAL_PWM_setDutyCycle(PWM_TypeDef *PWMx, uint32_t idx, uint32_t duty,
                      int phase_corr);

uint32_t HAL_PWM_getDutyCycle(PWM_TypeDef *PWMx, uint32_t idx);

void HAL_PWM_trigger(PWM_TypeDef *PWMx, uint32_t idx);

void HAL_PWM_stop(PWM_TypeDef *PWMx, uint32_t idx);

#ifdef __cplusplus
}
#endif

#endif /* __HAL_PWM_H */