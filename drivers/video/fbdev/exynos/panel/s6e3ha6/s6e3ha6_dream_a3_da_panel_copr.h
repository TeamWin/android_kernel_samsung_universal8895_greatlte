/*
 * linux/drivers/video/fbdev/exynos/panel/s6e3ha6/s6e3ha6_dream_a3_da_panel_copr.h
 *
 * Header file for COPR Driver
 *
 * Copyright (c) 2016 Samsung Electronics
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
*/

#ifndef __S6E3HA6_DREAM_A3_DA_PANEL_COPR_H__
#define __S6E3HA6_DREAM_A3_DA_PANEL_COPR_H__

#include "../panel.h"
#include "../copr.h"
#include "s6e3ha6_dream_a3_da_panel.h"

#define S6E3HA6_DREAM_A3_DA_COPR_GAMMA	(1)		/* 0 : GAMMA_1, 1 : GAMMA_2_2 */
#define S6E3HA6_DREAM_A3_DA_COPR_ER		(0x5D)
#define S6E3HA6_DREAM_A3_DA_COPR_EG		(0x6E)
#define S6E3HA6_DREAM_A3_DA_COPR_EB		(0xB5)

static struct pktinfo PKTINFO(dream_a3_da_level2_key_enable);
static struct pktinfo PKTINFO(dream_a3_da_level2_key_disable);

/* ===================================================================================== */
/* ============================== [S6E3HA6 MAPPING TABLE] ============================== */
/* ===================================================================================== */
struct maptbl dream_a3_da_copr_maptbl[] = {
	[COPR_MAPTBL] = DEFINE_0D_MAPTBL(dream_a3_da_copr_table, init_common_table, NULL, copy_copr_maptbl),
};

/* ===================================================================================== */
/* ============================== [S6E3HA6 COMMAND TABLE] ============================== */
/* ===================================================================================== */
u8 DREAM_A3_DA_COPR[] = {
	0xE1, 0x03, 0x5D, 0x6E, 0xB5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

DEFINE_VARIABLE_PACKET(dream_a3_da_copr, DSI_PKT_TYPE_WR, DREAM_A3_DA_COPR, &dream_a3_da_copr_maptbl[COPR_MAPTBL], 1);

static void *dream_a3_da_set_copr_cmdtbl[] = {
	&PKTINFO(dream_a3_da_level2_key_enable),
	&PKTINFO(dream_a3_da_copr),
	&PKTINFO(dream_a3_da_level2_key_disable),
};

static void *dream_a3_da_get_copr_cmdtbl[] = {
	&s6e3ha6_restbl[RES_COPR],
};

static struct seqinfo dream_a3_da_copr_seqtbl[MAX_COPR_SEQ] = {
	[COPR_SET_SEQ] = SEQINFO_INIT("set-copr-seq", dream_a3_da_set_copr_cmdtbl),
	[COPR_GET_SEQ] = SEQINFO_INIT("get-copr-seq", dream_a3_da_get_copr_cmdtbl),
};

static struct panel_copr_data s6e3ha6_dream_a3_da_copr_data = {
	.seqtbl = dream_a3_da_copr_seqtbl,
	.nr_seqtbl = ARRAY_SIZE(dream_a3_da_copr_seqtbl),
	.maptbl = (struct maptbl *)dream_a3_da_copr_maptbl,
	.nr_maptbl = (sizeof(dream_a3_da_copr_maptbl) / sizeof(struct maptbl)),
	.reg = {
		.copr_en = true,
		.copr_gamma = S6E3HA6_DREAM_A3_DA_COPR_GAMMA,
		.copr_er = S6E3HA6_DREAM_A3_DA_COPR_ER,
		.copr_eg = S6E3HA6_DREAM_A3_DA_COPR_EG,
		.copr_eb = S6E3HA6_DREAM_A3_DA_COPR_EB,
		.roi_on = false,
		.roi_xs = 0,
		.roi_ys = 0,
		.roi_xe = 0,
		.roi_ye = 0,
	},
};
#endif /* __S6E3HA6_DREAM_A3_DA_PANEL_COPR_H__ */
