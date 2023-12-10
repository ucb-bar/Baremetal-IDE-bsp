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

void HAL_PWM_init(PWM_TypeDef *PWMx, PWM_InitTypeDef *PWM_init) {
  PWMx->PWM_CFG = *((uint32_t*) PWM_init);
}

void HAL_PWM_stop(PWM_TypeDef *PWMx, uint32_t idx) {
  // TODO: implementation
}

void HAL_PWM_setFrequency(PWM_TypeDef *PWMx, uint32_t idx, uint32_t freq) {
  // TODO: implementation
}

uint32_t HAL_PWM_getFrequency(PWM_TypeDef *PWMx, uint32_t idx) {
  // TODO: implementation
  return 0;
}

void HAL_PWM_setDutyCycle(PWM_TypeDef *PWMx, uint32_t idx, uint32_t duty, int phase_corr) {
  // TODO: implementation
}

uint32_t HAL_PWM_getDutyCycle(PWM_TypeDef *PWMx, uint32_t idx) {
  // TODO: implementation
  return 0; 
}

void HAL_PWM_trigger(PWM_TypeDef *PWMx, uint32_t idx) {
  // TODO: implementation
}