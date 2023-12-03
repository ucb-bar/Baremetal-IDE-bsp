#ifndef __HAL_PWM_H
#define __HAL_PWM_H

#ifdef __cplusplus
extern "C" {
#endif

#include "rv_common.h"
#include "ll_pwm.h"


// struct pwm_config {
//     uint32_t scale       : 4;   // Bit 0 to 3
//     uint32_t sticky      : 1;   // Bit 8
//     uint32_t zero_cmp    : 1;   // Bit 9
//     uint32_t deglitch    : 1;   // Bit 10
//     uint32_t reserved1   : 2;   // Bits 11 to 12 (reserved bits)
//     uint32_t en_always   : 1;   // Bit 12
//     uint32_t en_once     : 1;   // Bit 13
//     uint32_t reserved2   : 2;   // Bits 14 to 15 (reserved bits)
//     uint32_t center      : 1;   // Bit 16
//     uint32_t reserved3   : 7;   // Bits 17 to 23 (reserved bits)
//     uint32_t gang        : 1;   // Bit 24
//     uint32_t reserved4   : 3;   // Bits 25 to 27 (reserved bits)
//     uint32_t ip          : 1;   // Bit 28
//     uint32_t reserved5   : 3;   // Bits 29 to 31 (reserved bits)
// };

static inline void HAL_PWM_enable(PWM_TypeDef* pwm) {
    SET_BITS(pwm->PWM_CFG, PWM_PWMENALWAYS_MSK);
}

static inline void HAL_PWM_disable(PWM_TypeDef* pwm) {
    CLEAR_BITS(pwm->PWM_CFG, PWM_PWMENALWAYS_MSK);
}

static inline void HAL_PWM_set_pwm_scale(PWM_TypeDef* pwm, uint32_t val) {
   WRITE_BITS(pwm->PWM_CFG, PWM_PWMSCALE_MSK, val << PWM_PWMSCALE_POS);
}

static inline void HAL_PWM_set_cmp_val(PWM_TypeDef* pwm, uint32_t idx, uint32_t val) {
    switch(idx) {
        case 0: pwm->PWM_CMP0 = val; break;
        case 1: pwm->PWM_CMP1 = val; break;
        case 2: pwm->PWM_CMP2 = val; break;
        case 3: pwm->PWM_CMP3 = val; break;
    }
}

static inline void HAL_PWM_trigger_oneshot(PWM_TypeDef* pwm, uint32_t idx) {
    SET_BITS(pwm->PWM_CFG, PWM_PWMENONESHOT_MSK);
}

void HAL_PWM_init_pwm(PWM_TypeDef* pwm);
void HAL_PWM_set_freq(PWM_TypeDef* pwm, uint32_t idx, uint32_t freq);
uint32_t HAL_PWM_get_freq(PWM_TypeDef* pwm, uint32_t idx);

void HAL_PWM_set_duty(PWM_TypeDef* pwm, uint32_t idx, uint32_t duty, int phase_corr);
uint32_t HAL_PWM_get_duty(PWM_TypeDef* pwm, uint32_t idx);

void HAL_PWM_trigger(PWM_TypeDef* pwm, uint32_t idx);
void HAL_PWM_stop(PWM_TypeDef* pwm, uint32_t idx);

#ifdef __cplusplus
}
#endif

#endif /* __HAL_PWM_H */ 