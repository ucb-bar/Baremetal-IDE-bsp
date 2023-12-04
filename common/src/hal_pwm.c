/**
 * @file hal_pwm.c
 * @author -Ethan Gao / eygao@berkeley.edu
 * @brief 
 * @version 0.1
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "hal_pwm.h"

void HAL_PWM_init(PWM_TypeDef *PWMx) {
    HAL_PWM_set_pwm_scale(pwm, 0x0);
    CLEAR_BITS(PWMx->PWM_CFG, PWM_PWMSTICKY_MSK);
    CLEAR_BITS(PWMx->PWM_CFG, PWM_PWMZEROCMP_MSK);
    SET_BITS(PWMx->PWM_CFG, PWM_PWMDEGLITCH_MSK);
    CLEAR_BITS(PWMx->PWM_CFG, PWM_PWMCMP0CENTER_MSK);
    CLEAR_BITS(PWMx->PWM_CFG, PWM_PWMCMP1CENTER_MSK);
    CLEAR_BITS(PWMx->PWM_CFG, PWM_PWMCMP2CENTER_MSK);
    CLEAR_BITS(PWMx->PWM_CFG, PWM_PWMCMP3CENTER_MSK);
    CLEAR_BITS(PWMx->PWM_CFG, PWM_PWMCMP0GANG_MSK);
    CLEAR_BITS(PWMx->PWM_CFG, PWM_PWMCMP1GANG_MSK);
    CLEAR_BITS(PWMx->PWM_CFG, PWM_PWMCMP2GANG_MSK);
    CLEAR_BITS(PWMx->PWM_CFG, PWM_PWMCMP3GANG_MSK);
    CLEAR_BITS(PWMx->PWM_CFG, PWM_PWMCMP0IP_MSK);
    CLEAR_BITS(PWMx->PWM_CFG, PWM_PWMCMP1IP_MSK);
    CLEAR_BITS(PWMx->PWM_CFG, PWM_PWMCMP2IP_MSK);
    CLEAR_BITS(PWMx->PWM_CFG, PWM_PWMCMP3IP_MSK);

    WRITE_BITS(PWMx->PWM_CMP0, PWM_CMP_REG_MSK, 0x0);
    WRITE_BITS(PWMx->PWM_CMP1, PWM_CMP_REG_MSK, 0x0);
    WRITE_BITS(PWMx->PWM_CMP2, PWM_CMP_REG_MSK, 0x0);
    WRITE_BITS(PWMx->PWM_CMP3, PWM_CMP_REG_MSK, 0x0);

}

// void HAL_PWM_set_freq(PWM_TypeDef* pwm, uint32_t idx, uint32_t freq) {

// }

// uint32_t HAL_PWM_setFrequency(PWM_TypeDef* pwm, uint32_t idx) {
//     return 0;
// }

// void HAL_PWM_setDutyCycle(PWM_TypeDef* pwm, uint32_t idx, uint32_t duty, int phase_corr) {

// }

// uint32_t HAL_PWM_getDutyCycle(PWM_TypeDef* pwm, uint32_t idx) {
//     return 0;
// }

void HAL_PWM_trigger(PWM_TypeDef *PWMx, uint32_t idx) {
    
}

void HAL_PWM_stop(PWM_TypeDef *PWMx, uint32_t idx) {

}