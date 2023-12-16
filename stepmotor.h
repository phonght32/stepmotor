// MIT License

// Copyright (c) 2023 phonght32

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef __STEPMOTOR_H__
#define __STEPMOTOR_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "err_code.h"

typedef err_code_t (*stepmotor_func_set_pwm)(float duty);
typedef err_code_t (*stepmotor_func_start_pwm)(void);
typedef err_code_t (*stepmotor_func_stop_pwm)(void);

typedef struct stepmotor* stepmotor_handle_t;


/**
 * @brief   Configuration structure.
 */
typedef struct {
	bool                		dir;            /*!< Direction */
	uint32_t            		freq_hz;        /*!< PWM frequency in Hz */
	float 						duty;			/*!< PWM duty cycle */
	stepmotor_func_set_pwm 		set_pwm;		/*!< Function set PWM */
	stepmotor_func_start_pwm 	start_pwm;		/*!< Function start PWM */
	stepmotor_func_stop_pwm 	stop_pwm;		/*!< Function stop PWM */
} stepmotor_cfg_t;

/*
 * @brief   Initialize step motor with default parameters.
 *
 * @note    This function must be called first.
 *
 * @param   None.
 *
 * @return
 *      - Handle structure: Success.
 *      - Others:           Fail.
 */
stepmotor_handle_t stepmotor_init(void);

/*
 * @brief   Set configuration parameters.
 *
 * @param 	handle Handle structure.
 * @param   config Configuration structure.
 *
 * @return
 *      - ERR_CODE_SUCCESS: Success.
 *      - Others:           Fail.
 */
err_code_t stepmotor_set_config(stepmotor_handle_t handle, stepmotor_cfg_t config);

/*
 * @brief   Configure step motor to run.
 *
 * @param 	handle Handle structure.
 *
 * @return
 *      - ERR_CODE_SUCCESS: Success.
 *      - Others:           Fail.
 */
err_code_t stepmotor_config(stepmotor_handle_t handle);

/*
 * @brief   Start step motor.
 *
 * @param 	handle Handle structure.
 *
 * @return
 *      - ERR_CODE_SUCCESS: Success.
 *      - Others:           Fail.
 */
err_code_t stepmotor_start(stepmotor_handle_t handle);

/*
 * @brief   Stop step motor.
 *
 * @param 	handle Handle structure.
 *
 * @return
 *      - ERR_CODE_SUCCESS: Success.
 *      - Others:           Fail.
 */
err_code_t stepmotor_stop(stepmotor_handle_t handle);

/*
 * @brief   Set PWM duty cycle.
 *
 * @param 	handle Handle structure.
 * @param 	duty PWM duty cycle.
 *
 * @return
 *      - ERR_CODE_SUCCESS: Success.
 *      - Others:           Fail.
 */
err_code_t stepmotor_set_pwm_duty(stepmotor_handle_t handle, float duty);

/*
 * @brief   Destroy step motor.
 *
 * @param 	handle Handle structure.
 *
 * @return
 *      - ERR_CODE_SUCCESS: Success.
 *      - Others:           Fail.
 */
err_code_t stepmotor_destroy(stepmotor_handle_t handle);


#ifdef __cplusplus
}
#endif

#endif /* __STEPMOTOR_H__ */