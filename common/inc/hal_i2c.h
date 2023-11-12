/**
 * @file hal_i2c.h
 * @author -T.K.- / t_k_233@outlook.com
 * @brief 
 * @version 0.1
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __HAL_I2C_H
#define __HAL_I2C_H

#ifdef __cplusplus
extern "C" {
#endif

#include "rv_common.h"

#define I2C_CTRL_IEN_POS                        (6U)
#define I2C_CTRL_IEN_MSK                        (0x1U << I2C_CTRL_IEN_POS)
#define I2C_CTRL_EN_POS                         (7U)
#define I2C_CTRL_EN_MSK                         (0x1U << I2C_CTRL_EN_POS)
#define I2C_STAT_CMD_IF_POS                     (0U)
#define I2C_STAT_CMD_IF_MSK                     (0x1U << I2C_STAT_CMD_IF_POS)
#define I2C_STAT_CMD_TIP_POS                    (1U)
#define I2C_STAT_CMD_TIP_MSK                    (0x1U << I2C_STAT_CMD_TIP_POS)
#define I2C_STAT_CMD_ACK_POS                    (3U)
#define I2C_STAT_CMD_ACK_MSK                    (0x1U << I2C_STAT_CMD_ACK_POS)
#define I2C_STAT_CMD_WR_POS                     (4U)
#define I2C_STAT_CMD_WR_MSK                     (0x1U << I2C_STAT_CMD_WR_POS)
#define I2C_STAT_CMD_RD_POS                     (5U)
#define I2C_STAT_CMD_RD_MSK                     (0x1U << I2C_STAT_CMD_RD_POS)
#define I2C_STAT_CMD_BUSY_STO_POS               (6U)
#define I2C_STAT_CMD_BUSY_STO_MSK               (0x1U << I2C_STAT_CMD_BUSY_STO_POS)
#define I2C_STAT_CMD_RXACK_STA_POS              (7U)
#define I2C_STAT_CMD_RXACK_STA_MSK              (0x1U << I2C_STAT_CMD_RXACK_STA_POS)

typedef struct {
  uint16_t clock;
} I2C_InitTypeDef;

typedef struct {
  __IO uint32_t PRESCAL_LO;                     /** Upper part of the prescaler value */
  __IO uint32_t PRESCAL_HI;                     /** Lower part of the prescaler value */
  __IO uint32_t CTRL;                           /** Control */
  __IO uint32_t DATA;                           /** Data */
  __IO uint32_t STAT_CMD;                       /** Status & command */
} I2C_TypeDef;

typedef enum {
  I2C_FLAG_IF = I2C_STAT_CMD_IF_MSK,
  I2C_FLAG_TIP = I2C_STAT_CMD_TIP_MSK,
  I2C_FLAG_BUSY = I2C_STAT_CMD_BUSY_STO_MSK,
  I2C_FLAG_RXACK = I2C_STAT_CMD_RXACK_STA_MSK,
} I2C_Flag;

#define I2C_DATA_WRITE        0b0U
#define I2C_DATA_READ         0b1U

static inline void HAL_I2C_disable(I2C_TypeDef *I2Cx) {
  CLEAR_BITS(I2Cx->CTRL, I2C_CTRL_EN_MSK);
}

static inline void HAL_I2C_enable(I2C_TypeDef *I2Cx) {
  SET_BITS(I2Cx->CTRL, I2C_CTRL_EN_MSK);
}

static inline State HAL_I2C_getFlag(I2C_TypeDef *I2Cx, I2C_Flag flag) {
  return READ_BITS(I2Cx->STAT_CMD, flag) ? SET : RESET;
}

void HAL_I2C_init(I2C_TypeDef *I2Cx, I2C_InitTypeDef *I2C_init);

Status HAL_I2C_waitForFlag(I2C_TypeDef *I2Cx, I2C_Flag flag, State state, uint32_t timestart, uint32_t timeout);

Status HAL_I2C_waitForTransaction(I2C_TypeDef *I2Cx, uint32_t timestart, uint32_t timeout);

Status HAL_I2C_masterReceive(I2C_TypeDef *I2Cx, uint16_t device_addr, uint8_t *buffer, uint16_t size, uint64_t timeout);

Status HAL_I2C_masterTransmit(I2C_TypeDef *I2Cx, uint16_t device_addr, uint8_t *buffer, uint16_t size, uint64_t timeout);

Status HAL_I2C_readMemory(I2C_TypeDef *I2Cx, uint16_t device_addr, uint8_t mem_addr, uint8_t *buffer, uint16_t size, uint64_t timeout);

Status HAL_I2C_writeMemory(I2C_TypeDef *I2Cx, uint16_t device_addr, uint8_t mem_addr, uint8_t *buffer, uint16_t size, uint32_t timeout);

#ifdef __cplusplus
}
#endif

#endif /* __HAL_I2C_H */