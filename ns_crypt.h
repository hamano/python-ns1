/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License (the "License").
 * You may not use this file except in compliance with the License.
 *
 * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
 * or http://www.opensolaris.org/os/licensing.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file at usr/src/OPENSOLARIS.LICENSE.
 * If applicable, add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your own identifying
 * information: Portions Copyright [yyyy] [name of copyright owner]
 *
 * CDDL HEADER END
 */

/*
 * Copyright (c) 1999, 2010, Oracle and/or its affiliates. All rights reserved.
 */

/*
 * Copyright (C) 2011 Tsukasa Hamano <hamano@osstech.co.jp>
 */

#ifndef	_NS_CRYPT_H
#define	_NS_CRYPT_H

#ifdef __cplusplus
extern "C" {
#endif

#define	TRUE			1
#define	FALSE			0
#define	ROTORSIZE		256
#define	MASK			0377
#define	CRYPTMARK		"{NS1}"
#define	NS_DOMESTIC	1
#define B_FALSE 0
#define B_TRUE 1

typedef unsigned int uint_t;
typedef unsigned short uint16_t;
typedef unsigned char boolean_t;

char	*dvalue(char *);
char	*evalue(char *);

#ifdef __cplusplus
}
#endif

#endif /* _NS_CRYPT_H */
