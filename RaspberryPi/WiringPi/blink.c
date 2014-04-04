//
//  blink.c
//  ctest
//
//  Created by Mamunul Mazid on 4/2/14.
//  Copyright (c) 2014 Mamunul Mazid. All rights reserved.
//

#include <stdio.h>
#include <wiringPi.h>

#define LED     8

int main (void)
{
    printf ("Raspberry Pi Quick2Wire blink\n") ;
    
    wiringPiSetup () ;
    pinMode (LED, OUTPUT) ;
    
    for (;;)
    {
        digitalWrite (LED, HIGH) ;  // On
        delay (500) ;               // mS
        digitalWrite (LED, LOW) ;   // Off
        delay (500) ;
    }
    return 0 ;
}