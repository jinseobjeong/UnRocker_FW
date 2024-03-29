/****************************************************************************
 *
 *   Copyright (c) 2016 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/**
 * @file parameters.cpp
 *
 * @author Beat Kueng <beat-kueng@gmx.net>
 */

#include "parameters.h"

namespace sensors
{

void initialize_parameter_handles(ParameterHandles &parameter_handles)
{
	/* basic r/c parameters */
	for (unsigned i = 0; i < RC_MAX_CHAN_COUNT; i++) {
		char nbuf[16];

		/* min values */
		sprintf(nbuf, "RC%d_MIN", i + 1);
		parameter_handles.min[i] = param_find(nbuf);

		/* trim values */
		sprintf(nbuf, "RC%d_TRIM", i + 1);
		parameter_handles.trim[i] = param_find(nbuf);

		/* max values */
		sprintf(nbuf, "RC%d_MAX", i + 1);
		parameter_handles.max[i] = param_find(nbuf);

		/* channel reverse */
		sprintf(nbuf, "RC%d_REV", i + 1);
		parameter_handles.rev[i] = param_find(nbuf);

		/* channel deadzone */
		sprintf(nbuf, "RC%d_DZ", i + 1);
		parameter_handles.dz[i] = param_find(nbuf);

	}

	/* mandatory input switched, mapped to channels 1-4 per default */
	parameter_handles.rc_map_roll 	= param_find("RC_MAP_ROLL");
	parameter_handles.rc_map_pitch = param_find("RC_MAP_PITCH");
	parameter_handles.rc_map_yaw 	= param_find("RC_MAP_YAW");
	parameter_handles.rc_map_throttle = param_find("RC_MAP_THROTTLE");
	parameter_handles.rc_map_failsafe = param_find("RC_MAP_FAILSAFE");

	/* mandatory mode switches, mapped to channel 5 and 6 per default */
	parameter_handles.rc_map_mode_sw = param_find("RC_MAP_MODE_SW");
	parameter_handles.rc_map_return_sw = param_find("RC_MAP_RETURN_SW");

	parameter_handles.rc_map_flaps = param_find("RC_MAP_FLAPS");

	/* optional mode switches, not mapped per default */
	parameter_handles.rc_map_rattitude_sw = param_find("RC_MAP_RATT_SW");
	parameter_handles.rc_map_posctl_sw = param_find("RC_MAP_POSCTL_SW");
	parameter_handles.rc_map_loiter_sw = param_find("RC_MAP_LOITER_SW");
	parameter_handles.rc_map_acro_sw = param_find("RC_MAP_ACRO_SW");
	parameter_handles.rc_map_offboard_sw = param_find("RC_MAP_OFFB_SW");
	parameter_handles.rc_map_kill_sw = param_find("RC_MAP_KILL_SW");
	parameter_handles.rc_map_arm_sw = param_find("RC_MAP_ARM_SW");
	parameter_handles.rc_map_trans_sw = param_find("RC_MAP_TRANS_SW");
	parameter_handles.rc_map_gear_sw = param_find("RC_MAP_GEAR_SW");
	parameter_handles.rc_map_stab_sw = param_find("RC_MAP_STAB_SW");
	parameter_handles.rc_map_man_sw = param_find("RC_MAP_MAN_SW");

	parameter_handles.rc_map_aux1 = param_find("RC_MAP_AUX1");
	parameter_handles.rc_map_aux2 = param_find("RC_MAP_AUX2");
	parameter_handles.rc_map_aux3 = param_find("RC_MAP_AUX3");
	parameter_handles.rc_map_aux4 = param_find("RC_MAP_AUX4");
	parameter_handles.rc_map_aux5 = param_find("RC_MAP_AUX5");
	parameter_handles.rc_map_aux6 = param_find("RC_MAP_AUX6");

	/* RC to parameter mapping for changing parameters with RC */
	for (int i = 0; i < rc_parameter_map_s::RC_PARAM_MAP_NCHAN; i++) {
		char name[rc_parameter_map_s::PARAM_ID_LEN];
		snprintf(name, rc_parameter_map_s::PARAM_ID_LEN, "RC_MAP_PARAM%d",
			 i + 1); // shifted by 1 because param name starts at 1
		parameter_handles.rc_map_param[i] = param_find(name);
	}

	parameter_handles.rc_map_flightmode = param_find("RC_MAP_FLTMODE");

	/* RC thresholds */
	parameter_handles.rc_fails_thr = param_find("RC_FAILS_THR");
	parameter_handles.rc_assist_th = param_find("RC_ASSIST_TH");
	parameter_handles.rc_auto_th = param_find("RC_AUTO_TH");
	parameter_handles.rc_rattitude_th = param_find("RC_RATT_TH");
	parameter_handles.rc_posctl_th = param_find("RC_POSCTL_TH");
	parameter_handles.rc_return_th = param_find("RC_RETURN_TH");
	parameter_handles.rc_loiter_th = param_find("RC_LOITER_TH");
	parameter_handles.rc_acro_th = param_find("RC_ACRO_TH");
	parameter_handles.rc_offboard_th = param_find("RC_OFFB_TH");
	parameter_handles.rc_killswitch_th = param_find("RC_KILLSWITCH_TH");
	parameter_handles.rc_armswitch_th = param_find("RC_ARMSWITCH_TH");
	parameter_handles.rc_trans_th = param_find("RC_TRANS_TH");
	parameter_handles.rc_gear_th = param_find("RC_GEAR_TH");
	parameter_handles.rc_stab_th = param_find("RC_STAB_TH");
	parameter_handles.rc_man_th = param_find("RC_MAN_TH");

	/* RC low pass filter configuration */
	parameter_handles.rc_flt_smp_rate = param_find("RC_FLT_SMP_RATE");
	parameter_handles.rc_flt_cutoff = param_find("RC_FLT_CUTOFF");

	/* Differential pressure offset */
	parameter_handles.diff_pres_offset_pa = param_find("SENS_DPRES_OFF");
#ifdef ADC_AIRSPEED_VOLTAGE_CHANNEL
	parameter_handles.diff_pres_analog_scale = param_find("SENS_DPRES_ANSC");
#endif /* ADC_AIRSPEED_VOLTAGE_CHANNEL */

	parameter_handles.battery_voltage_scaling = param_find("BAT_CNT_V_VOLT");
	parameter_handles.battery_current_scaling = param_find("BAT_CNT_V_CURR");
	parameter_handles.battery_current_offset = param_find("BAT_V_OFFS_CURR");
	parameter_handles.battery_v_div = param_find("BAT_V_DIV");
	parameter_handles.battery_a_per_v = param_find("BAT_A_PER_V");
	parameter_handles.battery_source = param_find("BAT_SOURCE");
	parameter_handles.battery_adc_channel = param_find("BAT_ADC_CHANNEL");

	/* rotations */
	parameter_handles.board_rotation = param_find("SENS_BOARD_ROT");

	/* attack trigger, jsjeong */
	parameter_handles.gyro_attack_trigger = param_find("SENS_GYRO_TRG");
	parameter_handles.gyro_attack_frequency = param_find("SENS_GYRO_FREQ");
	parameter_handles.gyro_attack_amplitude = param_find("SENS_GYRO_AMP");
        parameter_handles.gyro_attack_log = param_find("SENS_GYRO_LOG");

	parameter_handles.accel_attack_trigger = param_find("SENS_ACCEL_TRG");
	parameter_handles.accel_attack_frequency = param_find("SENS_ACCEL_FREQ");
	parameter_handles.accel_attack_amplitude = param_find("SENS_ACCEL_AMP");
        parameter_handles.accel_attack_log = param_find("SENS_ACCEL_LOG");


	/* rotation offsets */
	parameter_handles.board_offset[0] = param_find("SENS_BOARD_X_OFF");
	parameter_handles.board_offset[1] = param_find("SENS_BOARD_Y_OFF");
	parameter_handles.board_offset[2] = param_find("SENS_BOARD_Z_OFF");

	/* Barometer QNH */
	parameter_handles.baro_qnh = param_find("SENS_BARO_QNH");

	parameter_handles.air_cmodel = param_find("CAL_AIR_CMODEL");
	parameter_handles.air_tube_length = param_find("CAL_AIR_TUBELEN");
	parameter_handles.air_tube_diameter_mm = param_find("CAL_AIR_TUBED_MM");

	// These are parameters for which QGroundControl always expects to be returned in a list request.
	// We do a param_find here to force them into the list.
	(void)param_find("RC_CHAN_CNT");

	(void)param_find("CAL_ACC0_ID");
	(void)param_find("CAL_GYRO0_ID");

	(void)param_find("CAL_MAG0_ID");
	(void)param_find("CAL_MAG1_ID");
	(void)param_find("CAL_MAG2_ID");
	(void)param_find("CAL_MAG3_ID");
	(void)param_find("CAL_MAG0_ROT");
	(void)param_find("CAL_MAG1_ROT");
	(void)param_find("CAL_MAG2_ROT");
	(void)param_find("CAL_MAG3_ROT");
	(void)param_find("CAL_MAG_SIDES");

	(void)param_find("SYS_PARAM_VER");
	(void)param_find("SYS_AUTOSTART");
	(void)param_find("SYS_AUTOCONFIG");
	(void)param_find("TRIG_MODE");
	(void)param_find("UAVCAN_ENABLE");

	// Parameters controlling the on-board sensor thermal calibrator
	(void)param_find("SYS_CAL_TDEL");
	(void)param_find("SYS_CAL_TMAX");
	(void)param_find("SYS_CAL_TMIN");
}

int update_parameters(const ParameterHandles &parameter_handles, Parameters &parameters)
{

	bool rc_valid = true;
	float tmpScaleFactor = 0.0f;
	float tmpRevFactor = 0.0f;
	int ret = PX4_OK;

	/* rc values */
	for (unsigned int i = 0; i < RC_MAX_CHAN_COUNT; i++) {

		param_get(parameter_handles.min[i], &(parameters.min[i]));
		param_get(parameter_handles.trim[i], &(parameters.trim[i]));
		param_get(parameter_handles.max[i], &(parameters.max[i]));
		param_get(parameter_handles.rev[i], &(parameters.rev[i]));
		param_get(parameter_handles.dz[i], &(parameters.dz[i]));

		tmpScaleFactor = (1.0f / ((parameters.max[i] - parameters.min[i]) / 2.0f) * parameters.rev[i]);
		tmpRevFactor = tmpScaleFactor * parameters.rev[i];

		/* handle blowup in the scaling factor calculation */
		if (!PX4_ISFINITE(tmpScaleFactor) ||
		    (tmpRevFactor < 0.000001f) ||
		    (tmpRevFactor > 0.2f)) {
			PX4_WARN("RC chan %u not sane, scaling: %8.6f, rev: %d", i, (double)tmpScaleFactor, (int)(parameters.rev[i]));
			/* scaling factors do not make sense, lock them down */
			parameters.scaling_factor[i] = 0.0f;
			rc_valid = false;

		} else {
			parameters.scaling_factor[i] = tmpScaleFactor;
		}
	}

	/* handle wrong values */
	if (!rc_valid) {
		PX4_ERR("WARNING     WARNING     WARNING\n\nRC CALIBRATION NOT SANE!\n\n");
	}

	const char *paramerr = "FAIL PARM LOAD";

	/* channel mapping */
	if (param_get(parameter_handles.rc_map_roll, &(parameters.rc_map_roll)) != OK) {
		PX4_WARN("%s", paramerr);
	}

	if (param_get(parameter_handles.rc_map_pitch, &(parameters.rc_map_pitch)) != OK) {
		PX4_WARN("%s", paramerr);
	}

	if (param_get(parameter_handles.rc_map_yaw, &(parameters.rc_map_yaw)) != OK) {
		PX4_WARN("%s", paramerr);
	}

	if (param_get(parameter_handles.rc_map_throttle, &(parameters.rc_map_throttle)) != OK) {
		PX4_WARN("%s", paramerr);
	}

	if (param_get(parameter_handles.rc_map_failsafe, &(parameters.rc_map_failsafe)) != OK) {
		PX4_WARN("%s", paramerr);
	}

	if (param_get(parameter_handles.rc_map_mode_sw, &(parameters.rc_map_mode_sw)) != OK) {
		PX4_WARN("%s", paramerr);
	}

	if (param_get(parameter_handles.rc_map_return_sw, &(parameters.rc_map_return_sw)) != OK) {
		PX4_WARN("%s", paramerr);
	}

	if (param_get(parameter_handles.rc_map_rattitude_sw, &(parameters.rc_map_rattitude_sw)) != OK) {
		PX4_WARN("%s", paramerr);
	}

	if (param_get(parameter_handles.rc_map_posctl_sw, &(parameters.rc_map_posctl_sw)) != OK) {
		PX4_WARN("%s", paramerr);
	}

	if (param_get(parameter_handles.rc_map_loiter_sw, &(parameters.rc_map_loiter_sw)) != OK) {
		PX4_WARN("%s", paramerr);
	}

	if (param_get(parameter_handles.rc_map_acro_sw, &(parameters.rc_map_acro_sw)) != OK) {
		PX4_WARN("%s", paramerr);
	}

	if (param_get(parameter_handles.rc_map_offboard_sw, &(parameters.rc_map_offboard_sw)) != OK) {
		PX4_WARN("%s", paramerr);
	}

	if (param_get(parameter_handles.rc_map_kill_sw, &(parameters.rc_map_kill_sw)) != OK) {
		PX4_WARN("%s", paramerr);
	}

	if (param_get(parameter_handles.rc_map_arm_sw, &(parameters.rc_map_arm_sw)) != OK) {
		PX4_WARN("%s", paramerr);
	}

	if (param_get(parameter_handles.rc_map_trans_sw, &(parameters.rc_map_trans_sw)) != OK) {
		PX4_WARN("%s", paramerr);
	}

	if (param_get(parameter_handles.rc_map_flaps, &(parameters.rc_map_flaps)) != OK) {
		PX4_WARN("%s", paramerr);
	}

	if (param_get(parameter_handles.rc_map_gear_sw, &(parameters.rc_map_gear_sw)) != OK) {
		PX4_WARN("%s", paramerr);
	}

	if (param_get(parameter_handles.rc_map_stab_sw, &(parameters.rc_map_stab_sw)) != OK) {
		PX4_WARN("%s", paramerr);
	}

	if (param_get(parameter_handles.rc_map_man_sw, &(parameters.rc_map_man_sw)) != OK) {
		PX4_WARN("%s", paramerr);
	}

	param_get(parameter_handles.rc_map_aux1, &(parameters.rc_map_aux1));
	param_get(parameter_handles.rc_map_aux2, &(parameters.rc_map_aux2));
	param_get(parameter_handles.rc_map_aux3, &(parameters.rc_map_aux3));
	param_get(parameter_handles.rc_map_aux4, &(parameters.rc_map_aux4));
	param_get(parameter_handles.rc_map_aux5, &(parameters.rc_map_aux5));
	param_get(parameter_handles.rc_map_aux6, &(parameters.rc_map_aux6));

	for (int i = 0; i < rc_parameter_map_s::RC_PARAM_MAP_NCHAN; i++) {
		param_get(parameter_handles.rc_map_param[i], &(parameters.rc_map_param[i]));
	}

	param_get(parameter_handles.rc_map_flightmode, &(parameters.rc_map_flightmode));

	param_get(parameter_handles.rc_fails_thr, &(parameters.rc_fails_thr));
	param_get(parameter_handles.rc_assist_th, &(parameters.rc_assist_th));
	parameters.rc_assist_inv = (parameters.rc_assist_th < 0);
	parameters.rc_assist_th = fabsf(parameters.rc_assist_th);
	param_get(parameter_handles.rc_auto_th, &(parameters.rc_auto_th));
	parameters.rc_auto_inv = (parameters.rc_auto_th < 0);
	parameters.rc_auto_th = fabsf(parameters.rc_auto_th);
	param_get(parameter_handles.rc_rattitude_th, &(parameters.rc_rattitude_th));
	parameters.rc_rattitude_inv = (parameters.rc_rattitude_th < 0);
	parameters.rc_rattitude_th = fabsf(parameters.rc_rattitude_th);
	param_get(parameter_handles.rc_posctl_th, &(parameters.rc_posctl_th));
	parameters.rc_posctl_inv = (parameters.rc_posctl_th < 0);
	parameters.rc_posctl_th = fabsf(parameters.rc_posctl_th);
	param_get(parameter_handles.rc_return_th, &(parameters.rc_return_th));
	parameters.rc_return_inv = (parameters.rc_return_th < 0);
	parameters.rc_return_th = fabsf(parameters.rc_return_th);
	param_get(parameter_handles.rc_loiter_th, &(parameters.rc_loiter_th));
	parameters.rc_loiter_inv = (parameters.rc_loiter_th < 0);
	parameters.rc_loiter_th = fabsf(parameters.rc_loiter_th);
	param_get(parameter_handles.rc_acro_th, &(parameters.rc_acro_th));
	parameters.rc_acro_inv = (parameters.rc_acro_th < 0);
	parameters.rc_acro_th = fabsf(parameters.rc_acro_th);
	param_get(parameter_handles.rc_offboard_th, &(parameters.rc_offboard_th));
	parameters.rc_offboard_inv = (parameters.rc_offboard_th < 0);
	parameters.rc_offboard_th = fabsf(parameters.rc_offboard_th);
	param_get(parameter_handles.rc_killswitch_th, &(parameters.rc_killswitch_th));
	parameters.rc_killswitch_inv = (parameters.rc_killswitch_th < 0);
	parameters.rc_killswitch_th = fabsf(parameters.rc_killswitch_th);
	param_get(parameter_handles.rc_armswitch_th, &(parameters.rc_armswitch_th));
	parameters.rc_armswitch_inv = (parameters.rc_armswitch_th < 0);
	parameters.rc_armswitch_th = fabsf(parameters.rc_armswitch_th);
	param_get(parameter_handles.rc_trans_th, &(parameters.rc_trans_th));
	parameters.rc_trans_inv = (parameters.rc_trans_th < 0);
	parameters.rc_trans_th = fabsf(parameters.rc_trans_th);
	param_get(parameter_handles.rc_gear_th, &(parameters.rc_gear_th));
	parameters.rc_gear_inv = (parameters.rc_gear_th < 0);
	parameters.rc_gear_th = fabsf(parameters.rc_gear_th);
	param_get(parameter_handles.rc_stab_th, &(parameters.rc_stab_th));
	parameters.rc_stab_inv = (parameters.rc_stab_th < 0);
	parameters.rc_stab_th = fabsf(parameters.rc_stab_th);
	param_get(parameter_handles.rc_man_th, &(parameters.rc_man_th));
	parameters.rc_man_inv = (parameters.rc_man_th < 0);
	parameters.rc_man_th = fabsf(parameters.rc_man_th);

	param_get(parameter_handles.rc_flt_smp_rate, &(parameters.rc_flt_smp_rate));
	parameters.rc_flt_smp_rate = math::max(1.0f, parameters.rc_flt_smp_rate);
	param_get(parameter_handles.rc_flt_cutoff, &(parameters.rc_flt_cutoff));
	/* make sure the filter is in its stable region -> fc < fs/2 */
	parameters.rc_flt_cutoff = math::min(parameters.rc_flt_cutoff, (parameters.rc_flt_smp_rate / 2) - 1.f);

	/* Airspeed offset */
	param_get(parameter_handles.diff_pres_offset_pa, &(parameters.diff_pres_offset_pa));
#ifdef ADC_AIRSPEED_VOLTAGE_CHANNEL
	param_get(parameter_handles.diff_pres_analog_scale, &(parameters.diff_pres_analog_scale));
#endif /* ADC_AIRSPEED_VOLTAGE_CHANNEL */

	/* scaling of ADC ticks to battery voltage */
	if (param_get(parameter_handles.battery_voltage_scaling, &(parameters.battery_voltage_scaling)) != OK) {
		PX4_WARN("%s", paramerr);

	} else if (parameters.battery_voltage_scaling < 0.0f) {
		/* apply scaling according to defaults if set to default */
		parameters.battery_voltage_scaling = (3.3f / 4096);
		param_set_no_notification(parameter_handles.battery_voltage_scaling, &parameters.battery_voltage_scaling);
	}

	/* scaling of ADC ticks to battery current */
	if (param_get(parameter_handles.battery_current_scaling, &(parameters.battery_current_scaling)) != OK) {
		PX4_WARN("%s", paramerr);

	} else if (parameters.battery_current_scaling < 0.0f) {
		/* apply scaling according to defaults if set to default */
		parameters.battery_current_scaling = (3.3f / 4096);
		param_set_no_notification(parameter_handles.battery_current_scaling, &parameters.battery_current_scaling);
	}

	if (param_get(parameter_handles.battery_current_offset, &(parameters.battery_current_offset)) != OK) {
		PX4_WARN("%s", paramerr);

	}

	if (param_get(parameter_handles.battery_v_div, &(parameters.battery_v_div)) != OK) {
		PX4_WARN("%s", paramerr);
		parameters.battery_v_div = 0.0f;

	} else if (parameters.battery_v_div <= 0.0f) {
		/* apply scaling according to defaults if set to default */

		parameters.battery_v_div = BOARD_BATTERY1_V_DIV;
		param_set_no_notification(parameter_handles.battery_v_div, &parameters.battery_v_div);
	}

	if (param_get(parameter_handles.battery_a_per_v, &(parameters.battery_a_per_v)) != OK) {
		PX4_WARN("%s", paramerr);
		parameters.battery_a_per_v = 0.0f;

	} else if (parameters.battery_a_per_v <= 0.0f) {
		/* apply scaling according to defaults if set to default */

		parameters.battery_a_per_v = BOARD_BATTERY1_A_PER_V;
		param_set_no_notification(parameter_handles.battery_a_per_v, &parameters.battery_a_per_v);
	}

	param_get(parameter_handles.battery_source,      &(parameters.battery_source));
	param_get(parameter_handles.battery_adc_channel, &(parameters.battery_adc_channel));

	param_get(parameter_handles.board_rotation, &(parameters.board_rotation));

	//jsjeong
	param_get(parameter_handles.gyro_attack_trigger, &(parameters.gyro_attack_trigger));
	param_get(parameter_handles.gyro_attack_frequency, &(parameters.gyro_attack_frequency));
	param_get(parameter_handles.gyro_attack_amplitude, &(parameters.gyro_attack_amplitude));
        param_get(parameter_handles.gyro_attack_log, &(parameters.gyro_attack_log));

	param_get(parameter_handles.accel_attack_trigger, &(parameters.accel_attack_trigger));
	param_get(parameter_handles.accel_attack_frequency, &(parameters.accel_attack_frequency));
	param_get(parameter_handles.accel_attack_amplitude, &(parameters.accel_attack_amplitude));
        param_get(parameter_handles.accel_attack_log, &(parameters.accel_attack_log));


	param_get(parameter_handles.board_offset[0], &(parameters.board_offset[0]));
	param_get(parameter_handles.board_offset[1], &(parameters.board_offset[1]));
	param_get(parameter_handles.board_offset[2], &(parameters.board_offset[2]));

	param_get(parameter_handles.baro_qnh, &(parameters.baro_qnh));

	param_get(parameter_handles.air_cmodel, &parameters.air_cmodel);
	param_get(parameter_handles.air_tube_length, &parameters.air_tube_length);
	param_get(parameter_handles.air_tube_diameter_mm, &parameters.air_tube_diameter_mm);

	return ret;
}

} /* namespace sensors */
