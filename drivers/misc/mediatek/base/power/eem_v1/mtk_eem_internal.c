
/*
* Copyright (C) 2016 MediaTek Inc.
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 2 as
* published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
* See http://www.gnu.org/licenses/gpl-2.0.html for more details.
*/

/**
 * @file	mtk_eem_internal.c
 * @brief   Driver for EEM
 *
 */
#define __MTK_EEM_INTERNAL_C__

#include "mtk_eem_config.h"
#include "mtk_eem.h"

#if !(EEM_ENABLE_TINYSYS_SSPM)
	#include "mtk_eem_internal_ap.h"
#else
	#include "mtk_eem_internal_sspm.h"
#endif

#include "mtk_eem_internal.h"

/**
 * EEM controllers
 */
struct eem_ctrl eem_ctrls[NR_EEM_CTRL] = {
	[EEM_CTRL_BIG] = {
		.name = __stringify(EEM_CTRL_BIG),
		.det_id = EEM_DET_BIG,
	},

	[EEM_CTRL_CCI] = {
		.name = __stringify(EEM_CTRL_CCI),
		.det_id = EEM_DET_CCI,
	},

	[EEM_CTRL_GPU] = {
		.name = __stringify(EEM_CTRL_GPU),
		.det_id = EEM_DET_GPU,
	},

	[EEM_CTRL_2L] = {
		.name = __stringify(EEM_CTRL_2L),
		.det_id = EEM_DET_2L,
	},

	[EEM_CTRL_L] = {
		.name = __stringify(EEM_CTRL_L),
		.det_id = EEM_DET_L,
	},

	[EEM_CTRL_BANK5] = {
		.name = __stringify(EEM_CTRL_BANK5),
		.det_id = EEM_DET_BANK5,
	},

	[EEM_CTRL_SOC] = {
		.name = __stringify(EEM_CTRL_SOC),
		.det_id = EEM_DET_SOC,
	},

};

#define BASE_OP(fn)	.fn = base_ops_ ## fn
struct eem_det_ops eem_det_base_ops = {
	#if !(EEM_ENABLE_TINYSYS_SSPM)
	BASE_OP(enable),
	BASE_OP(disable),
	BASE_OP(disable_locked),
	BASE_OP(switch_bank),

	BASE_OP(init01),
	BASE_OP(init02),
	BASE_OP(mon_mode),

	BASE_OP(get_status),
	BASE_OP(dump_status),

	BASE_OP(set_phase),

	BASE_OP(get_temp),

	BASE_OP(get_volt),
	BASE_OP(set_volt),
	BASE_OP(restore_default_volt),
	BASE_OP(get_freq_table),
	BASE_OP(get_orig_volt_table),
	#endif
	/* platform independent code */
	BASE_OP(volt_2_pmic),
	BASE_OP(volt_2_eem),
	BASE_OP(pmic_2_volt),
	BASE_OP(eem_2_pmic),
};

struct eem_det eem_detectors[NR_EEM_DET] = {
	[EEM_DET_BIG] = {
		.name		= __stringify(EEM_DET_BIG),
		.ops		= &big_det_ops,
		#if (!(EEM_ENABLE_TINYSYS_SSPM) || defined EEM_OFFSET_PROC_SHOW)
		.volt_offset	= 0,
		#endif
		.ctrl_id	= EEM_CTRL_BIG,
		#ifdef CONFIG_BIG_OFF
		.features	= 0,
		#else
		.features	= FEA_INIT01 | FEA_INIT02 | FEA_MON,
		#endif
		.max_freq_khz	= 2548000,/* 2496Mhz */
		.VBOOT		= VBOOT_VAL,
		.VMAX		= VMAX_VAL,
		.VMIN		= VMIN_VAL,
		.eem_v_base	= EEM_V_BASE,
		.eem_step   = EEM_STEP,
		.pmic_base	= CPU_PMIC_BASE,
		.pmic_step	= CPU_PMIC_STEP,
		.DETWINDOW	= DETWINDOW_VAL,
		.DTHI		= DTHI_VAL,
		.DTLO		= DTLO_VAL,
		.DETMAX		= DETMAX_VAL,
		.AGECONFIG	= AGECONFIG_VAL,
		.AGEM		= AGEM_VAL,
		.DVTFIXED	= DVTFIXED_VAL,
		.VCO		= VCO_VAL,
		.DCCONFIG	= DCCONFIG_VAL,
	},

	[EEM_DET_CCI] = {
		.name		= __stringify(EEM_DET_CCI),
		.ops		= &cci_det_ops,
		#if (!(EEM_ENABLE_TINYSYS_SSPM) || defined EEM_OFFSET_PROC_SHOW)
		.volt_offset = 0,
		#endif
		.ctrl_id	= EEM_CTRL_CCI,
		.features	= FEA_INIT01 | FEA_INIT02 | FEA_MON,
		.max_freq_khz	= 1391000,/* 1118 MHz */
		.VBOOT		= VBOOT_VAL, /* 10uV */
		.VMAX		= VMAX_VAL,
		.VMIN		= VMIN_VAL,
		.eem_v_base	= EEM_V_BASE,
		.eem_step   = EEM_STEP,
		.pmic_base	= CPU_PMIC_BASE,
		.pmic_step	= CPU_PMIC_STEP,
		.DETWINDOW	= DETWINDOW_VAL,
		.DTHI		= DTHI_VAL,
		.DTLO		= DTLO_VAL,
		.DETMAX		= DETMAX_VAL,
		.AGECONFIG	= AGECONFIG_VAL,
		.AGEM		= AGEM_VAL,
		.DVTFIXED	= DVTFIXED_VAL,
		.VCO		= VCO_VAL,
		.DCCONFIG	= DCCONFIG_VAL,
	},

	[EEM_DET_GPU] = {
		.name		= __stringify(EEM_DET_GPU),
		.ops		= &gpu_det_ops,
		#if (!(EEM_ENABLE_TINYSYS_SSPM) || defined EEM_OFFSET_PROC_SHOW)
		.volt_offset	= 0,
		#endif
		.ctrl_id	= EEM_CTRL_GPU,
		.features	= FEA_INIT01 | FEA_INIT02 | FEA_MON,
		.max_freq_khz	= 850000,/* 850 MHz */
		.VBOOT		= VBOOT_VAL_GPU, /* 10uV */
		.VMAX		= VMAX_VAL_GPU,
		.VMIN		= VMIN_VAL_GPU,
		.eem_v_base	= EEM_V_BASE,
		.eem_step	= EEM_STEP,
		.pmic_base	= GPU_PMIC_BASE,
		.pmic_step	= GPU_PMIC_STEP,
		.DETWINDOW	= DETWINDOW_VAL,
		.DTHI		= DTHI_VAL,
		.DTLO		= DTLO_VAL,
		.DETMAX		= DETMAX_VAL,
		.AGECONFIG	= AGECONFIG_VAL,
		.AGEM		= AGEM_VAL,
		.DVTFIXED	= DVTFIXED_VAL_GPU,
		.VCO		= VCO_VAL_GPU,
		.DCCONFIG	= DCCONFIG_VAL,

	},

	[EEM_DET_2L] = {
		.name		= __stringify(EEM_DET_2L),
		.ops		= &dual_little_det_ops,
		#if (!(EEM_ENABLE_TINYSYS_SSPM) || defined EEM_OFFSET_PROC_SHOW)
		.volt_offset	= 0,
		#endif
		.ctrl_id	= EEM_CTRL_2L,
		.features	= FEA_INIT01 | FEA_INIT02 | FEA_MON,
		.max_freq_khz	= 1638000,/* 1599 MHz */
		.VBOOT		= VBOOT_VAL, /* 10uV */
		.VMAX		= VMAX_VAL,
		.VMIN		= VMIN_VAL,
		.eem_v_base	= EEM_V_BASE,
		.eem_step   = EEM_STEP,
		.pmic_base	= CPU_PMIC_BASE,
		.pmic_step	= CPU_PMIC_STEP,
		.DETWINDOW	= DETWINDOW_VAL,
		.DTHI		= DTHI_VAL,
		.DTLO		= DTLO_VAL,
		.DETMAX		= DETMAX_VAL,
		.AGECONFIG	= AGECONFIG_VAL,
		.AGEM		= AGEM_VAL,
		.DVTFIXED	= DVTFIXED_VAL,
		.VCO		= VCO_VAL,
		.DCCONFIG	= DCCONFIG_VAL,
	},

	[EEM_DET_L] = {
		.name		= __stringify(EEM_DET_L),
		.ops		= &little_det_ops,
		#if (!(EEM_ENABLE_TINYSYS_SSPM) || defined EEM_OFFSET_PROC_SHOW)
		.volt_offset	= 0,
		#endif
		.ctrl_id	= EEM_CTRL_L,
		.features	= FEA_INIT01 | FEA_INIT02 | FEA_MON,
		.max_freq_khz	= 2340000,/* 2249 MHz */
		.VBOOT		= VBOOT_VAL, /* 10uV */
		.VMAX		= VMAX_VAL_L,
		.VMIN		= VMIN_VAL,
		.eem_v_base	= EEM_V_BASE,
		.eem_step   = EEM_STEP,
		.pmic_base	= CPU_PMIC_BASE,
		.pmic_step	= CPU_PMIC_STEP,
		.DETWINDOW	= DETWINDOW_VAL,
		.DTHI		= DTHI_VAL,
		.DTLO		= DTLO_VAL,
		.DETMAX		= DETMAX_VAL,
		.AGECONFIG	= AGECONFIG_VAL,
		.AGEM		= AGEM_VAL,
		.DVTFIXED	= DVTFIXED_VAL,
		.VCO		= VCO_VAL,
		.DCCONFIG	= DCCONFIG_VAL,
	},

	[EEM_DET_BANK5] = {
		.name		= __stringify(EEM_DET_BANK5),
		.ops		= &dmy_det_ops,
		#if (!(EEM_ENABLE_TINYSYS_SSPM) || defined EEM_OFFSET_PROC_SHOW)
		.volt_offset	= 0,
		#endif
		.ctrl_id	= EEM_CTRL_BANK5,
		.features	= 0,
		.max_freq_khz	= 2249000,/* 2249 MHz */
		.VBOOT		= VBOOT_VAL, /* 10uV */
		.VMAX		= VMAX_VAL,
		.VMIN		= VMIN_VAL,
		.eem_v_base	= EEM_V_BASE,
		.eem_step   = EEM_STEP,
		.pmic_base	= CPU_PMIC_BASE,
		.pmic_step	= CPU_PMIC_STEP,
		.DETWINDOW	= DETWINDOW_VAL,
		.DTHI		= DTHI_VAL,
		.DTLO		= DTLO_VAL,
		.DETMAX		= DETMAX_VAL,
		.AGECONFIG	= AGECONFIG_VAL,
		.AGEM		= AGEM_VAL,
		.DVTFIXED	= DVTFIXED_VAL,
		.VCO		= VCO_VAL,
		.DCCONFIG	= DCCONFIG_VAL,
	},

	[EEM_DET_SOC] = {
		.name		= __stringify(EEM_DET_SOC),
		.ops		= &soc_det_ops,
		#if (!(EEM_ENABLE_TINYSYS_SSPM) || defined EEM_OFFSET_PROC_SHOW)
		.volt_offset	= 0,
		#endif
		.ctrl_id	= EEM_CTRL_SOC,
		#if DVT
		.features	= FEA_INIT01 | FEA_INIT02 | FEA_MON,
		#else
		/* .features	= FEA_INIT01 | FEA_INIT02, */
		.features	= 0,
		#endif
		.max_freq_khz	= 100,/* 800 MHz */
		.VBOOT		= VBOOT_VAL_SOC, /* 10uV */
		.VMAX		= VMAX_VAL_SOC,
		.VMIN		= VMIN_VAL,
		.eem_v_base	= EEM_V_BASE,
		.eem_step   = EEM_STEP,
		.pmic_base	= VCORE_PMIC_BASE,
		.pmic_step	= VCORE_PMIC_STEP,
		.DETWINDOW	= DETWINDOW_VAL,
		.DTHI		= DTHI_VAL,
		.DTLO		= DTLO_VAL,
		.DETMAX		= DETMAX_VAL,
		.AGECONFIG	= AGECONFIG_VAL,
		.AGEM		= AGEM_VAL,
		.DVTFIXED	= DVTFIXED_VAL,
		.VCO		= VCO_VAL,
		.DCCONFIG	= DCCONFIG_VAL,
	}

};

#if DUMP_DATA_TO_DE
const unsigned int reg_dump_addr_off[101] = {
	0x0000,
	0x0004,
	0x0008,
	0x000C,
	0x0010,
	0x0014,
	0x0018,
	0x001c,
	0x0024,
	0x0028,
	0x002c,
	0x0030,
	0x0034,
	0x0038,
	0x003c,
	0x0040,
	0x0044,
	0x0048,
	0x004c,
	0x0050,
	0x0054,
	0x0058,
	0x005c,
	0x0060,
	0x0064,
	0x0068,
	0x006c,
	0x0070,
	0x0074,
	0x0078,
	0x007c,
	0x0080,
	0x0084,
	0x0088,
	0x008c,
	0x0090,
	0x0094,
	0x0098,
	0x00a0,
	0x00a4,
	0x00a8,
	0x00B0,
	0x00B4,
	0x00B8,
	0x00BC,
	0x00C0,
	0x00C4,
	0x00C8,
	0x00CC,
	0x00F0,
	0x00F4,
	0x00F8,
	0x00FC,
	0x0200,
	0x0204,
	0x0208,
	0x020C,
	0x0210,
	0x0214,
	0x0218,
	0x021C,
	0x0220,
	0x0224,
	0x0228,
	0x022C,
	0x0230,
	0x0234,
	0x0238,
	0x023C,
	0x0240,
	0x0244,
	0x0248,
	0x024C,
	0x0250,
	0x0254,
	0x0258,
	0x025C,
	0x0260,
	0x0264,
	0x0268,
	0x026C,
	0x0270,
	0x0274,
	0x0278,
	0x027C,
	0x0280,
	0x0284,
	0x0288,
	0x0400,
	0x0404,
	0x0408,
	0x040C,
	0x0410,
	0x0414,
	0x0418,
	0x041C,
	0x0420,
	0x0424,
	0x0428,
	0x042C,
	0x0430,
};
#endif
#undef __MT_EEM_INTERNAL_C__
