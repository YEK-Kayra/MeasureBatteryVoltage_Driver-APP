/**
 * ReadingBatteryVoltage_APP.c
 *
 *  Created on: Jul 13, 2023
 *      Author: TAISAT MARM-99
 */
/** Include header files*/
#include "ReadingBatteryVoltage_APP.h"

/** Define constant variables */
#define CriticalVoltageLimit 3.5
#define ConstantOfVoltage 1.448
#define ConstantOfReferanceVoltage 3.3
#define ResolationValueOfBits 4095

/** Define changeable variables*/
uint16_t Value_ADC;
float BatteryVoltage;


/**
 * @fn float ReadingBatteryVoltage(ADC_HandleTypeDef *hadc)
 * @brief Read value of battery voltage by using ADC
 * @param hadc
 * @retval Value of Battery Voltage
 */
float ReadingBatteryVoltage(ADC_HandleTypeDef *hadc){

	HAL_ADC_Start(hadc);

	if(HAL_ADC_PollForConversion(hadc, 10000)==HAL_OK)
	{

		Value_ADC = HAL_ADC_GetValue(hadc);
		BatteryVoltage = (Value_ADC * (ConstantOfReferanceVoltage / ResolationValueOfBits)  *  ConstantOfVoltage ) ;

	}

	HAL_ADC_Stop(hadc);
	return BatteryVoltage;
}
