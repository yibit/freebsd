/*-
 * Copyright (C) 2012-2013 Intel Corporation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $FreeBSD$
 */

#ifndef __NVMECONTROL_H__
#define __NVMECONTROL_H__

#include <dev/nvme/nvme.h>

#define DEVLIST_USAGE							       \
"       nvmecontrol devlist\n"

#define IDENTIFY_USAGE							       \
"       nvmecontrol identify <controller id|namespace id>\n"

#define PERFTEST_USAGE							       \
"       nvmecontrol perftest <-n num_threads> <-o read|write>\n"	       \
"                            <-s size_in_bytes> <-t time_in_seconds>\n"	       \
"                            <-i intr|wait> [-f refthread] [-p]\n"	       \
"                            <namespace id>\n"

#define RESET_USAGE							       \
"       nvmecontrol reset <controller id>\n"

int open_dev(const char *str, int *fd, int show_error, int exit_on_error);
void read_controller_data(int fd, struct nvme_controller_data *cdata);
void read_namespace_data(int fd, int nsid, struct nvme_namespace_data *nsdata);

void devlist(int argc, char *argv[]);

#endif

