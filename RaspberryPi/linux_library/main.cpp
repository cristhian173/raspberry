#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/time.h>
#include <time.h>
#include "blink.h"

//#define NULL 0

//#include "ultrasonic.h"
//using namespace std;


int main(int argc, char *argv[])
{
    
    Blink* bl=new Blink();
    
//    int d = 0;
    
//    scanf("&d",d);
    
//    printf("d=%d",d);
    
    bl->startToBlink(1000);
    


    
//	bool on = true;
//	ultrasonic us(332);
//	for (;;)
//	{
//		sleep(1);
//		us.GetDistanceInInch();
//	}
    
    
}