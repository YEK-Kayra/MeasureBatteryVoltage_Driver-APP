# ReadBatteryVoltage
> [!NOTE]
> We use the ADC module of STM32F4 to read the battery voltage value.
> 
> The ADC module of STM32F4 can read 12 bits (To calculate the resolution).
>
> For configuration
> 1. Firstly We choose the STM32F407VGT6 model via CubeMX.(If you have an different module you choose your module)
> 2. We enable pin PA0 of ADC1.(Some module errata sheet tell us that adc pins and channels problem. For example adc1 channel 2 can shows wrong value)
> 3. We activate the external oscillator and set the debug mode to serial wire.
> 4. We open the codes by clicking Generate Code.







1.Block of code where constants are determined
```
#define CriticalVoltageLimit 3.5               // ( Critical Voltage Limit of STM32F4, about the maximumpin value that can be measured)
#define ConstantOfVoltage 1.272                // ( ConstantOfVoltage = Battery voltage/3.3 = 4.2/3.3 = 1.272)
#define ConstantOfReferanceVoltage 3.3         // (Reference voltage value of STM32F4)
#define ResolationValueOfBits 4095             // (Resolution of ADC= 2'12=4096 so ADC can read values ​​ 0-4095)

```
2.Block of code where battery voltage value is calculated
``` 
Value_ADC = HAL_ADC_GetValue(hadc);
BatteryVoltage = (Value_ADC * (ConstantOfReferanceVoltage / ResolationValueOfBits)  *  ConstantOfVoltage ) ;
```
![formül](https://github.com/nilsuhyt/ReadBatteryVoltage/assets/158216829/a0e4d2fe-e6e9-4a85-b184-1c96f3e65337)
