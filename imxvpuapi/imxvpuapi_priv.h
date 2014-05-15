/* imxvpuapi internals
 * Copyright (C) 2014 Carlos Rafael Giani
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301
 * USA
 */


#ifndef IMXVPUAPI_PRIV_H
#define IMXVPUAPI_PRIV_H

#include "imxvpuapi.h"


#ifdef __cplusplus
extern "C" {
#endif


#define IMXVPUAPI_UNUSED_PARAM(x) ((void)(x))


#define IMX_VPU_ALIGN_VAL_TO(LENGTH, ALIGN_SIZE)  ( ((uintptr_t)(((uint8_t*)(LENGTH)) + (ALIGN_SIZE) - 1) / (ALIGN_SIZE)) * (ALIGN_SIZE) )


#define IMX_VPU_ALLOC(SIZE) imx_vpu_cur_heap_alloc_fn((SIZE), imx_vpu_cur_heap_alloc_context)
#define IMX_VPU_FREE(PTR, SIZE) imx_vpu_cur_heap_free_fn((PTR), (SIZE), imx_vpu_cur_heap_alloc_context)

extern void *imx_vpu_cur_heap_alloc_context;
extern ImxVpuHeapAllocFunc imx_vpu_cur_heap_alloc_fn;
extern ImxVpuHeapFreeFunc imx_vpu_cur_heap_free_fn;


#define IMX_VPU_ERROR(...)   do { if (imx_vpu_cur_log_level_threshold >= IMX_VPU_LOG_LEVEL_ERROR)   { imx_vpu_cur_logging_fn(IMX_VPU_LOG_LEVEL_ERROR,   __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__); } } while(0)
#define IMX_VPU_WARNING(...) do { if (imx_vpu_cur_log_level_threshold >= IMX_VPU_LOG_LEVEL_WARNING) { imx_vpu_cur_logging_fn(IMX_VPU_LOG_LEVEL_WARNING, __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__); } } while(0)
#define IMX_VPU_INFO(...)    do { if (imx_vpu_cur_log_level_threshold >= IMX_VPU_LOG_LEVEL_INFO)    { imx_vpu_cur_logging_fn(IMX_VPU_LOG_LEVEL_INFO,    __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__); } } while(0)
#define IMX_VPU_DEBUG(...)   do { if (imx_vpu_cur_log_level_threshold >= IMX_VPU_LOG_LEVEL_DEBUG)   { imx_vpu_cur_logging_fn(IMX_VPU_LOG_LEVEL_DEBUG,   __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__); } } while(0)
#define IMX_VPU_LOG(...)     do { if (imx_vpu_cur_log_level_threshold >= IMX_VPU_LOG_LEVEL_LOG)     { imx_vpu_cur_logging_fn(IMX_VPU_LOG_LEVEL_LOG,     __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__); } } while(0)
#define IMX_VPU_TRACE(...)   do { if (imx_vpu_cur_log_level_threshold >= IMX_VPU_LOG_LEVEL_TRACE)   { imx_vpu_cur_logging_fn(IMX_VPU_LOG_LEVEL_TRACE,   __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__); } } while(0)

extern ImxVpuLogLevel imx_vpu_cur_log_level_threshold;
extern ImxVpuLoggingFunc imx_vpu_cur_logging_fn;


#ifdef __cplusplus
}
#endif


#endif
