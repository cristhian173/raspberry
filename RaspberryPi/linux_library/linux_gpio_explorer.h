#ifndef _LINUX_GPIO_EXPORTER_H_
#define _LINUX_GPIO_EXPORTER_H_

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

#include "linux_file.h"

class LinuxGPIOExporter
{
protected:
	int m_Number;

public:
	LinuxGPIOExporter(int number)
		: m_Number(number)
	{
		LinuxFile("/sys/class/gpio/export", O_WRONLY).Write(number);
	}

	~LinuxGPIOExporter()
	{
		LinuxFile("/sys/class/gpio/unexport",
			O_WRONLY).Write(m_Number);
	}
};

#endif