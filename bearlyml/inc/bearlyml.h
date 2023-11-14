
#ifndef __BEARLYML_H
#define __BEARLYML_H

#ifdef __cplusplus
extern "C" {
#endif

#include "rv_arch.h"
#include "rv_common.h"
#include "ll_i2c.h"
#include "ll_spi.h"
#include "ll_uart.h"


/* ================================ IRQ Definition ================================ */
typedef enum {
  UserSoftwareInterrupt         = 0,
  SupervisorSoftwareInterrupt   = 1,
  HypervisorSoftwareInterrupt   = 2,
  MachineSoftwareInterrupt      = 3,
  UserTimerInterrupt            = 4,
  SupervisorTimerInterrupt      = 5,
  HypervisorTimerInterrupt      = 6,
  MachineTimerInterrupt         = 7,
  UserExternalInterrupt         = 8,
  SupervisorExternalInterrupt   = 9,
  HypervisorExternalInterrupt   = 10,
  MachineExternalInterrupt      = 11,
} InterruptType;

typedef enum {
  UART0_IRQn                ,
} PLIC_IRQn_Type;


/* ================================ Memory Map Definition ================================ */
/* Peripheral Address Definition */
#define DEBUG_CONTROLLER_BASE   0x00000000U
#define ERROR_DEVICE_BASE       0x00003000U
#define BOOTSEL_BASE            0x00004000U
#define BOOT_SELECT_BASE        0x00004000U
#define BOOTROM_BASE            0x00010000U
#define LIBIF_ROM_BASE          0x00020000U
#define LIBIF_RAW_BASE          0x00030000U
#define RCC_BASE                0x00100000U
#define CLINT_BASE              0x02000000U
#define CACHE_CONTROLLER_BASE   0x02010000U
#define SCRATCH_BASE            0x08000000U
#define PLIC_BASE               0x0C000000U
#define GPIO_BASE               0x10012000U
#define UART_BASE               0x1001A000U
#define QSPI_BASE               0x10020000U
#define I2C_BASE                0x10024000U
#define QSPI_FLASH_BASE         0x20000000U
#define DRAM_BASE               0x80000000U

/* Peripheral Pointer Definition */
#define GPIOA_BASE              (GPIO_BASE)
#define UART0_BASE              (UART_BASE)
#define QSPI0_BASE              (QSPI_BASE)
#define SPI1_BASE               (QSPI_BASE + 0x1000U)
#define I2C0_BASE               (I2C_BASE)
#define I2C1_BASE               (I2C_BASE + 0x1000U)

/* Peripheral Structure Definition */
#define DEBUG_CONTROLLER        ((DEBUG_CONTROLLER_TypeDef *)DEBUG_CONTROLLER_BASE)
#define ERROR_DEVICE            ((ERROR_DEVICE_TypeDef *)ERROR_DEVICE_BASE)
#define BOOTSEL                 ((BOOTSEL_TypeDef *)BOOTSEL_BASE)
#define RCC                     ((RCC_TypeDef *)RCC_BASE)
#define PLL                     ((PLL_TypeDef *)PLL_BASE)
#define CLINT                   ((CLINT_TypeDef *)CLINT_BASE)
// #define CACHE_CONTROLLER        ((CACHE_TypeDef *)CACHE_CONTROLLER_BASE)
#define PLIC                    ((PLIC_TypeDef *)PLIC_BASE)
#define PLIC_EXTRA              ((PLIC_Extra_TypeDef *)(PLIC_BASE + 0x00200000U))
#define GPIOA                   ((GPIO_TypeDef *)GPIOA_BASE)
#define UART0                   ((UART_TypeDef *)UART0_BASE)
#define QSPI0                   ((QSPI_TypeDef *)QSPI0_BASE)
#define SPI1                    ((SPI_TypeDef *)SPI1_BASE)
#define I2C0                    ((I2C_TypeDef *)I2C0_BASE)
#define I2C1                    ((I2C_TypeDef *)I2C1_BASE)


#ifdef __cplusplus
}
#endif

#endif /* __BEARLYML_H */