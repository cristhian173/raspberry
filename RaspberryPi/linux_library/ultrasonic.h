#ifndef _ULTRASONIC_H_
#define _ULTRASONIC_H_

#include "linux_gpio.h"
class ultrasonic
{
	LinuxGPIO* _outputPin;
	LinuxGPIO* _triggerPin;
	LinuxGPIO* _echoPin;

	int _speedOfSound;
	void InitializePins();
	double MilliSecondToInch(double ms);
public:
	ultrasonic();
	ultrasonic(int sppedOfSound);
	~ultrasonic();

	int GetDistanceInInch();
};

#endif