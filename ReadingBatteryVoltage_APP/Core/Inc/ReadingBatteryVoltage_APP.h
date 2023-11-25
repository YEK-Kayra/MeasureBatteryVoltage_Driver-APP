/*
 * ReadingBatteryVoltage_APP.h
 *
 *  Created on: Jul 13, 2023
 *
 * @Author: TAISAT MARM-99
 * @brief :  Reading battery voltage by using ADC functions.
 *
 * @attention :  These parameters are for 1S LiPo battery.
 */




#ifndef INC_READINGBATTERYVOLTAGE_APP_H_
#define INC_READINGBATTERYVOLTAGE_APP_H_

#include "main.h"

float ReadingBatteryVoltage(ADC_HandleTypeDef *hadc);

#endif /* INC_READINGBATTERYVOLTAGE_APP_H_ */
