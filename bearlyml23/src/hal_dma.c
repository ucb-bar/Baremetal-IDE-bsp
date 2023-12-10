#include "hal_dma.h"

static DMA_Status get_status(DMA_TypeDef* DMAX) {
  if (DMAX->STATUS & DMA_BADMODE_MSK)
    return DMA_BADMODE;
  else if (DMAX->STATUS & DMA_SRCALIGN_MSK)
    return DMA_SRCALIGN;
  else if (DMAX->STATUS & DMA_STRALIGN_MSK)
    return DMA_DSTALIGN;
  else if (DMAX->STATUS & DMA_STRALIGN_MSK)
    return DMA_STRALIGN;
  else if (DMAX->STATUS & DMA_CNTERR_MSK)
    return DMA_CNTERR;
  else if (DMAX->STATUS & DMA_DENYR_MSK)
    return DMA_DENYR;
  else if (DMAX->STATUS & DMA_CORRUPTR_MSK)
    return DMA_CORRUPTR;
  else if (DMAX->STATUS & DMA_DENYW_MSK)
    return DMA_DENYW;
  return DMA_OK;
}

void HAL_DMA_init_memcpy(DMA_TypeDef* DMAX, void* src, void* dst, uint64_t src_stride, uint32_t count) {
  while (HAL_DMA_operation_inprogress(DMAX));
  
  DMAX->SRC_ADDR = (uint64_t) src;
  DMAX->DEST_ADDR = (uint64_t) dst;
  DMAX->SRCSTRIDE = src_stride;
  DMAX->MODE = MODE_COPY;
  DMAX->COUNT = count;
}

void HAL_DMA_init_MAC(DMA_TypeDef* DMAX, void* src, int8_t* operand, uint64_t src_stride, uint32_t count) {
  while (HAL_DMA_operation_inprogress(DMAX));

  uint64_t* op = (uint64_t*) operand;
  for (size_t i = 0; i < 8; i++)
    DMAX->OPERAND_REG[i] = op[i];
  DMAX->SRC_ADDR = (uint64_t) src;
  DMAX->SRCSTRIDE = src_stride;
  DMAX->MODE = MODE_MAC;
  DMAX->COUNT = count;

}
DMA_Status HAL_DMA_await_result(DMA_TypeDef* DMAX) {
  while (!HAL_DMA_operation_complete(DMAX) && !HAL_DMA_operation_errored(DMAX));
  if (HAL_DMA_operation_complete(DMAX))
    return DMA_OK;
  else
    return get_status(DMAX);
}

DMA_Status HAL_DMA_get_MAC_result(DMA_TypeDef* DMAX, int16_t* dst, uint32_t count) {
  while (!HAL_DMA_operation_complete(DMAX) && !HAL_DMA_operation_errored(DMAX));
  if (count > 32)
    count = 32;
  
  if (HAL_DMA_operation_complete(DMAX)){
    for (size_t i = 0; i < count; i++)
      dst[i] = DMAX->DEST_REG[i];
    return DMA_OK;
  }
  else {
    for (size_t i = 0; i < count; i++)
        dst[i] = -1;
    return get_status(DMAX);
  }
}
