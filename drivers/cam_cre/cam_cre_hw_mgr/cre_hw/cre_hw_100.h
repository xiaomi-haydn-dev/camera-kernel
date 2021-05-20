/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2021, The Linux Foundation. All rights reserved.
 */

#ifndef CAM_CRE_HW_100_H
#define CAM_CRE_HW_100_H

#include "cre_hw.h"

#define CRE_BUS_RD_TYPE            0x1
#define CRE_BUS_WR_TYPE            0x2

static struct cam_cre_top_reg top_reg = {
	.hw_version            =  0xFA000,
	.hw_cap                =  0xFA004,
	.debug_0               =  0xFA080,
	.debug_1               =  0xFA084,
	.debug_cfg             =  0xFA0DC,
	.testbus_ctrl          =  0xFA1F4,
	.scratch_0             =  0xFA1F8,
	.irq_status            =  0xFA00C,
	.irq_mask              =  0xFA010,
	.irq_clear             =  0xFA014,
	.irq_set               =  0xFA018,
	.irq_cmd               =  0xFA01C,
	.reset_cmd             =  0xFA008,
	.core_clk_cfg_ctrl_0   =  0xFA020,
	.core_clk_cfg_ctrl_1   =  0xFA024,
	.top_spare             =  0xFA1FC,
};

struct cam_cre_top_reg_val top_reg_value = {
	.hw_version = 0x10000000,
	.hw_cap = 0x4000,
	.irq_mask = 0xf,
	.irq_clear = 0xf,
	.irq_set = 0xf,
	.irq_cmd_set = 0xf,
	.irq_cmd_clear = 0xf,
	.idle = 0x8,
	.fe_done = 0x4,
	.we_done = 0x2,
	.rst_done = 0x1,
	.sw_reset_cmd = 0x2,
	.hw_reset_cmd = 0x1,
};

struct cam_cre_bus_rd_reg bus_rd_reg = {
	.hw_version     = 0xFA400,
	.irq_mask       = 0xFA404,
	.irq_clear      = 0xFA408,
	.irq_cmd        = 0xFA40C,
	.irq_status     = 0xFA410,
	.input_if_cmd   = 0xFA414,
	.irq_set        = 0xFA418,
	.misr_reset     = 0xFA41C,
	.security_cfg   = 0xFA420,
	.iso_cfg        = 0xFA424,
	.iso_seed       = 0xFA428,
	.test_bus_ctrl  = 0xFA42C,
	.num_clients    = 1,
	.rd_clients[0]  = {
		.core_cfg               = 0xFA450,
		.ccif_meta_data         = 0xFA454,
		.img_addr               = 0xFA458,
		.rd_width               = 0xFA45C,
		.rd_height              = 0xFA460,
		.rd_stride              = 0xFA464,
		.unpacker_cfg           = 0xFA468,
		.latency_buf_allocation = 0xFA47C,
		.misr_cfg_0             = 0xFA484,
		.misr_cfg_1             = 0xFA488,
		.misr_rd_val            = 0xFA48C,
		.debug_status_cfg       = 0xFA490,
		.debug_status_0         = 0xFA494,
		.debug_status_1         = 0xFA498,
		.read_buff_cfg          = 0xFA4A0,
		.addr_cfg               = 0xFA4A4,
		.spare                  = 0xFA430,
		.cons_violation         = 0xFA434,
	},
};

struct cam_cre_bus_wr_reg_val bus_wr_reg_value = {
	.hw_version                   = 0x30000000,
	.cgc_override                 = 0x1,
	.irq_mask_0                   = 0xd0000101,
	.irq_set_0                    = 0xd0000101,
	.irq_clear_0                  = 0xd0000101,
	.img_size_violation           = 0x80000000,
	.violation                    = 0x40000000,
	.cons_violation               = 0x10000000,
	.comp_buf_done                = 0x100,
	.comp_rup_done                = 0x1,
	.irq_mask_1                   = 0x1,
	.irq_set_1                    = 0x1,
	.irq_clear_1                  = 0x1,
	.irq_status_1                 = 0x1,
	.irq_cmd_set                  = 0x10,
	.irq_cmd_clear                = 0x1,
	.client_buf_done              = 0x1,
	.iso_en                       = 0x1,
	.iso_en_mask                  = 0x1,
	.misr_0_en                    = 0x1,
	.misr_0_en_mask               = 0x1,
	.misr_0_samp_mode             = 0x1,
	.misr_0_samp_mode_mask        = 0x10000,
	.misr_0_id_mask               = 0xff,
	.misr_rd_misr_sel_mask        = 0xf,
	.misr_rd_word_sel_mask        = 0x70,
	.num_clients = 1,
	.wr_clients[0] = {
		.client_en                = 0x1,
		.client_en_mask           = 0x1,
		.client_en_shift          = 0x0,
		.auto_recovery_en         = 0x1,
		.auto_recovery_en_mask    = 0x1,
		.auto_recovery_en_shift   = 0x4,
		.mode_mask                = 0x3,
		.mode_shift               = 0x10,
		.width_mask               = 0xffff,
		.width_shift              = 0x0,
		.height_mask              = 0xffff,
		.height_shift             = 0x10,
		.x_init_mask              = 0xff,
		.stride_mask              = 0xffffff,
		.format_mask              = 0xf,
		.format_shift             = 0x0,
		.alignment_mask           = 0x1,
		.alignment_shift          = 0x5,
		.bw_limit_en              = 0x1,
		.bw_limit_en_mask         = 0x1,
		.bw_limit_counter_mask    = 0x1fe,
		.output_port_id           = CAM_CRE_OUTPUT_IMAGE,
		.wm_port_id               = 1,
	},
};

struct cam_cre_bus_rd_reg_val bus_rd_reg_value = {
	.hw_version              = 0x30000000,
	.irq_mask                = 0x7,
	.rd_buf_done             = 0x4,
	.rup_done                = 0x2,
	.cons_violation          = 0x1,
	.irq_cmd_set             = 0x10,
	.irq_cmd_clear           = 0x1,
	.static_prg              = 0x8,
	.static_prg_mask         = 0x8,
	.ica_en                  = 0x1,
	.ica_en_mask             = 0x2,
	.go_cmd                  = 0x1,
	.go_cmd_mask             = 0x1,
	.irq_set                 = 0x7,
	.irq_clear               = 0x7,
	.misr_reset              = 0x1,
	.security_cfg            = 0x1,
	.iso_bpp_select_mask     = 0x60,
	.iso_pattern_select_mask = 0x6,
	.iso_en                  = 0x1,
	.iso_en_mask             = 0x1,
	.num_clients = 1,
	.rd_clients[0] = {
		.client_en               = 0x1,
		.ai_en                   = 0x1,
		.ai_en_mask              = 0x1000,
		.ai_en_shift             = 0xc,
		.pix_pattern_mask        = 0xfc,
		.pix_pattern_shift       = 0x2,
		.stripe_location_mask    = 0x3,
		.stripe_location_shift   = 0x0,
		.alignment_mask          = 0x1,
		.alignment_shift         = 0x5,
		.mode_mask               = 0x1f,
		.mode_shift              = 0x0,
		.latency_buf_size_mask   = 0xffff,
		.misr_cfg_en_mask        = 0x4,
		.misr_cfg_samp_mode_mask = 0x3,
		.x_int_mask              = 0xffff,
		.byte_offset_mask        = 0xff,
		.input_port_id           = CAM_CRE_INPUT_IMAGE,
		.rm_port_id              = 0x0,
	},
};

struct cam_cre_bus_wr_reg bus_wr_reg = {
	.hw_version                   = 0xFA700,
	.cgc_override                 = 0xFA708,
	.irq_mask_0                   = 0xFA718,
	.irq_mask_1                   = 0xFA71C,
	.irq_clear_0                  = 0xFA720,
	.irq_clear_1                  = 0xFA724,
	.irq_status_0                 = 0xFA728,
	.irq_status_1                 = 0xFA72C,
	.irq_cmd                      = 0xFA730,
	.frame_header_cfg_0           = 0x0,
	.local_frame_header_cfg_0     = 0xFA74C,
	.irq_set_0                    = 0xFA750,
	.irq_set_1                    = 0xFA754,
	.iso_cfg                      = 0xFA75C,
	.violation_status             = 0xFA764,
	.image_size_violation_status  = 0xFA770,
	.perf_count_cfg_0             = 0xFA774,
	.perf_count_cfg_1             = 0xFA778,
	.perf_count_cfg_2             = 0xFA77C,
	.perf_count_cfg_3             = 0xFA780,
	.perf_count_val_0             = 0xFA794,
	.perf_count_val_1             = 0xFA798,
	.perf_count_val_2             = 0xFA79C,
	.perf_count_val_3             = 0xFA7A0,
	.perf_count_status            = 0xFA7B4,
	.misr_cfg_0                   = 0xFA7B8,
	.misr_cfg_1                   = 0xFA7BC,
	.misr_rd_sel                  = 0xFA7C8,
	.misr_reset                   = 0xFA7CC,
	.misr_val                     = 0xFA7D0,
	.wr_clients[0]             = {
		.client_cfg           = 0xFA900,
		.img_addr             = 0xFA904,
		.img_cfg_0            = 0xFA90C,
		.img_cfg_1            = 0xFA910,
		.img_cfg_2            = 0xFA914,
		.bw_limit             = 0xFA918,
		.packer_cfg           = 0xFA91C,
		.addr_cfg             = 0xFA970,
		.debug_status_cfg     = 0xFA984,
		.debug_status_0       = 0xFA988,
		.debug_status_1       = 0xFA98C,
	},
};

static struct cam_cre_hw cre_hw_100 = {
	.top_reg_offset    = &top_reg,
	.top_reg_val       = &top_reg_value,
	.bus_wr_reg_offset = &bus_wr_reg,
	.bus_wr_reg_val    = &bus_wr_reg_value,
	.bus_rd_reg_offset = &bus_rd_reg,
	.bus_rd_reg_val    = &bus_rd_reg_value,
};
#endif // CAM_CRE_HW_100_H