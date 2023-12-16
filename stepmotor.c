#include "stdbool.h"
#include "stdlib.h"
#include "stepmotor.h"

typedef struct stepmotor {
	bool                		dir;            /*!< Direction */
	uint32_t            		freq_hz;        /*!< PWM frequency in Hz */
	float 						duty;			/*!< PWM duty cycle */
	uint8_t 					is_run;			/*!< Running status */
	stepmotor_func_set_pwm 		set_pwm;		/*!< Function set PWM */
	stepmotor_func_start_pwm 	start_pwm;		/*!< Function start PWM */
	stepmotor_func_stop_pwm 	stop_pwm;		/*!< Function stop PWM */
} stepmotor_t;

stepmotor_handle_t stepmotor_init(void)
{
	stepmotor_handle_t handle = calloc(1, sizeof(stepmotor_t));
	if (handle == NULL)
	{
		return NULL;
	}

	return handle;
}

err_code_t stepmotor_set_config(stepmotor_handle_t handle, stepmotor_cfg_t config)
{
	/* Check if handle structure is NULL */
	if (handle == NULL)
	{
		return ERR_CODE_NULL_PTR;
	}

	handle->dir = config.dir;
	handle->duty = config.duty;
	handle->freq_hz = config.freq_hz;
	handle->is_run = 0;
	handle->set_pwm = config.set_pwm;
	handle->start_pwm = config.start_pwm;
	handle->stop_pwm = config.stop_pwm;

	return ERR_CODE_SUCCESS;
}

err_code_t stepmotor_config(stepmotor_handle_t handle)
{
	/* Check if handle structure is NULL */
	if (handle == NULL)
	{
		return ERR_CODE_NULL_PTR;
	}

	/* Nothing to do */

	return ERR_CODE_SUCCESS;
}

err_code_t stepmotor_start(stepmotor_handle_t handle)
{
	/* Check if handle structure is NULL */
	if (handle == NULL)
	{
		return ERR_CODE_NULL_PTR;
	}

	handle->start_pwm();
	handle->is_run = 1;

	return ERR_CODE_SUCCESS;
}

err_code_t stepmotor_stop(stepmotor_handle_t handle)
{
	/* Check if handle structure is NULL */
	if (handle == NULL)
	{
		return ERR_CODE_NULL_PTR;
	}

	handle->stop_pwm();
	handle->is_run = 0;

	return ERR_CODE_SUCCESS;
}

err_code_t stepmotor_set_pwm_duty(stepmotor_handle_t handle, float duty)
{
	/* Check if handle structure is NULL */
	if (handle == NULL)
	{
		return ERR_CODE_NULL_PTR;
	}

	handle->set_pwm(duty);
	handle->duty = duty;

	return ERR_CODE_SUCCESS;
}

err_code_t stepmotor_destroy(stepmotor_handle_t handle)
{
	if (handle != NULL)
	{
		free(handle);
	}

	return ERR_CODE_SUCCESS;
}