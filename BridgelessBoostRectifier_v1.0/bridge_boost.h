/*
 * bridge_boost.h
 *
 *  Created on: 8 sty 2019
 *      Author: rafal
 */

#ifndef BRIDGE_BOOST_H_
#define BRIDGE_BOOST_H_

#define BOOSTRECT_PWM_MAX           160
#define BOOSTRECT_PWM_MAX_DUTY      144     // max 90%

typedef struct BoostRect{
    unsigned int pwm;
    unsigned int pwm_max;
    unsigned int pwm_freq_value;

    volatile unsigned int *T1_pwm_register;
    volatile unsigned int *T2_pwm_register;
    volatile unsigned int *pwm_register;

    unsigned int oV_actual;         // output voltage
    unsigned int oV_setpoint;       // output voltage setpoint
    unsigned int regulator_Kp;
    unsigned int regulator_Ki;
    signed long integral;
}BoostRect;

inline void BoostRect_PositiveSign(BoostRect *boostRect);
inline void BoostRect_NegativeSign(BoostRect *boostRect);
inline void BoostRect_ChangePwmParams(BoostRect *boostRect,unsigned int pwm, unsigned int pwm_max);
inline void BoostRect_ChangePwmFreqParam(BoostRect *boostRect, unsigned int pwm_freq_value);
inline unsigned int BoostRect_Regulator(BoostRect *boostRect);
inline void BoostRect_RegulatorSetSetpoint(BoostRect *boostRect, unsigned int setPoint);

#endif /* BRIDGE_BOOST_H_ */
