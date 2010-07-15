/*
 * config.h: project-wide definitions
 *
 * Copyright (c) 2006-2010, Intel Corporation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the Intel Corporation nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __CONFIG_H__
#define __CONFIG_H__

/*
 * build/support flags
 */

/* address tboot will load and execute at */
#define TBOOT_BASE_ADDR              0x0803000


/* address that tboot will do s3 resume at */
/* (must be in lower 1MB (real mode) and less than Xen trampoline @ 0x8c000) */
#define TBOOT_S3_WAKEUP_ADDR         0x8a000


/* these addrs must be in low memory so that they are mapped by the */
/* kernel at startup */

/* address/size for memory-resident serial log (when enabled) */
#define TBOOT_SERIAL_LOG_ADDR        0x60000
#define TBOOT_SERIAL_LOG_SIZE        0x08000

/* address/size for modified e820 table */
#define TBOOT_E820_COPY_ADDR         (TBOOT_SERIAL_LOG_ADDR + \
				      TBOOT_SERIAL_LOG_SIZE)
#define TBOOT_E820_COPY_SIZE         0x01800

/* address/size for modified VMM/kernel command line */
#define TBOOT_KERNEL_CMDLINE_ADDR    (TBOOT_E820_COPY_ADDR + \
				      TBOOT_E820_COPY_SIZE)
#define TBOOT_KERNEL_CMDLINE_SIZE    0x0400


#ifndef NR_CPUS
#define NR_CPUS     64
#endif

#ifdef __ASSEMBLY__
#define ENTRY(name)                             \
  .globl name;                                  \
  .align 16,0x90;                               \
  name:
#endif


#define COMPILE_TIME_ASSERT(e)                 \
{                                              \
    struct tmp {                               \
        int a : ((e) ? 1 : -1);                \
    };                                         \
}


#define __data     __attribute__ ((__section__ (".data")))
#define __text     __attribute__ ((__section__ (".text")))

#define __packed   __attribute__ ((packed))

#endif /* __CONFIG_H__ */


/*
 * Local variables:
 * mode: C
 * c-set-style: "BSD"
 * c-basic-offset: 4
 * tab-width: 4
 * indent-tabs-mode: nil
 * End:
 */
