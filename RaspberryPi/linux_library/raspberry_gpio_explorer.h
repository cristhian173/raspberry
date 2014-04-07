#ifndef _LINUX_GPIO_EXPORTER_H_
#define _LINUX_GPIO_EXPORTER_H_

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

#include "linux_file.h"

class RaspberryGPIOExporter
{
protected:
	int m_Number;

public:
	RaspberryGPIOExporter(int number)
		: m_Number(number)
	{
		LinuxFile("/sys/class/gpio/export", O_WRONLY).Write(number);
	}

	~RaspberryGPIOExporter()
	{
		LinuxFile("/sys/class/gpio/unexport",
			O_WRONLY).Write(m_Number);
	}
};

#endif