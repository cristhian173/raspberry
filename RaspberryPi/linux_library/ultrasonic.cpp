#include "ultrasonic.h"
#include <sys/time.h>
#include <time.h>

#define NULL 0

#include "linux_gpio.h"

ultrasonic::ultrasonic()
{
	_speedOfSound = 340;
	InitializePins();
}

ultrasonic::ultrasonic(int speedOfSound)
{
	_speedOfSound = speedOfSound;
	InitializePins();
}

ultrasonic::~ultrasonic()
{
}

void ultrasonic::InitializePins(){
	_outputPin = new LinuxGPIO(17);
	_outputPin->SetDirection(true);

	_triggerPin = new LinuxGPIO(22);
	_triggerPin->SetDirection(true);

	_echoPin = new LinuxGPIO(27);
	_echoPin->SetDirection(false);
}

double ultrasonic::MilliSecondToInch(double ms){
	return ((_speedOfSound * ms * 3937) / 200000.0);
}

int ultrasonic::GetDistanceInInch(){
	struct timespec rqtp;
	rqtp.tv_sec = 0;
	rqtp.tv_nsec = 10000;

	struct timespec rem;
	rem.tv_sec = 0;
	rem.tv_nsec = 0;

	struct timeval tv;
	struct timeval start_tv;
	double elapsed = 0.0;

	struct timespec delay;
	delay.tv_sec = 0;
	delay.tv_nsec = 1000;

	printf("Sending trigger...\n");
	//SendTrigger();
	_triggerPin->SetValue(false);
	_triggerPin->SetValue(true);
	//delay for time
	nanosleep(&rqtp, NULL);
	_triggerPin->SetValue(false);
	printf("Trigger sent...\n");

	printf("Waiting for echo...\n");
	long counter = 0;
	bool echoFound = true;
	while (true) // Wait until rising edge detected
	{
		counter++;
		if (_echoPin->GetValue())
		{
			break;
		}

		if (counter > 1000){
			echoFound = false;
			break;
		}

		nanosleep(&delay, NULL);
	}

	if (!echoFound)
	{
		printf("Echo lost...\n\n\n");
		sleep(1);
		return -1;
	}

	_outputPin->SetValue(true);
	gettimeofday(&start_tv, NULL);
	elapsed = 0.0;

	while (_echoPin->GetValue());// Wait until falling edge detected
	_outputPin->SetValue(false);

	gettimeofday(&tv, NULL);
	elapsed = (tv.tv_sec - start_tv.tv_sec) +
		(tv.tv_usec - start_tv.tv_usec) / 1000.0;

	printf("Echo received...\n");
	printf("Total time %lf ms\n", elapsed);

	double totalInch = MilliSecondToInch(elapsed);
	int fullFeet = (int)totalInch / 12;
	double inch = totalInch - (fullFeet * 12);
	printf("Distance %d feet %.2lf inch\n\n\n", fullFeet, inch);

	return 0;
}