#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/time.h>
#include <time.h>

#define NULL 0

#include "ultrasonic.h"

int main(int argc, char *argv[])
{
	bool on = true;
	ultrasonic us(332);
	for (;;)
	{
		sleep(1);
		us.GetDistanceInInch();
	}
}