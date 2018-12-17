/*
 * bridge_boost_rect.c
 *
 *  Created on: 20 pa� 2018
 *      Author: rafal
 */
#include "bridge_boost_rect.h"


inline void BoostRect_PositiveSign(BoostRect *boostRect){
	*(boostRect->T1_pwm_register) = boostRect->pwm_max+1;
	*(boostRect->T2_pwm_register) = boostRect->pwm;
}

inline void BoostRect_NegativeSign(BoostRect *boostRect){
    *(boostRect->T1_pwm_register) = boostRect->pwm;
    *(boostRect->T2_pwm_register) = boostRect->pwm_max+1;
}

inline void BoostRect_ChangePwmParams(BoostRect *boostRect,unsigned int pwm, unsigned int pwm_max){
    *(boostRect->pwm_register) = pwm_max;
    boostRect->pwm_max = pwm_max;
    boostRect->pwm = pwm;

    if(*(boostRect->T1_pwm_register) == boostRect->pwm_max+1){
        *(boostRect->T1_pwm_register) = boostRect->pwm;
        *(boostRect->T2_pwm_register) = boostRect->pwm_max+1;
    }else{
        *(boostRect->T1_pwm_register) = boostRect->pwm;
        *(boostRect->T2_pwm_register) = boostRect->pwm_max+1;
    }

}
