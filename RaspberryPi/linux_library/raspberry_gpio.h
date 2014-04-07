#ifndef _LINUX_GPIO_H
#define _LINUX_GPIO_H

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

#include "raspberry_gpio_explorer.h"

class RaspberryGPIO : public RaspberryGPIOExporter
{
public:
	RaspberryGPIO(int number)
		: RaspberryGPIOExporter(number)
	{
	}

	void SetValue(bool value)
	{
		char szFN[128];
		snprintf(szFN, sizeof(szFN),
			"/sys/class/gpio/gpio%d/value", m_Number);
		LinuxFile(szFN).Write(value ? "1" : "0");
	}

	bool GetValue()
	{
		char szFN[128];
		snprintf(szFN, sizeof(szFN),
			"/sys/class/gpio/gpio%d/value", m_Number);

		char data[2];
		if (LinuxFile(szFN).Read(data, 1) > 0)
		{
			return data[0] == '1';
		}

		return false;
	}

	void SetDirection(bool isOutput)
	{
		char szFN[128];
		snprintf(szFN, sizeof(szFN),
			"/sys/class/gpio/gpio%d/direction", m_Number);
		LinuxFile(szFN).Write(isOutput ? "out" : "in");
	}
};

#endif