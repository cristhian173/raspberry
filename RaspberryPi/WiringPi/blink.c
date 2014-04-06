//
//  blink.c
//  ctest
//
//  Created by Mamunul Mazid on 4/2/14.
//  Copyright (c) 2014 Mamunul Mazid. All rights reserved.
//

#include <stdio.h>
#include <wiringPi.h>

#define LED1     1
#define LED2    2
#define LED3     3
#define LED4     4
#define LED5     5
#define LED6     6
#define LED7     7
#define LED8     8
#define LED9     9
#define LED10     10
#define LED11     11
#define LED12     12
#define LED13     13
#define LED14     14
#define LED15     15
#define LED16     16
#define LED17     17
#define LED18     18
#define LED19     19
#define LED20     20
#define LED21     21
#define LED22     22
#define LED23     23
#define LED24     24
#define LED25     25

int main (void)
{
    printf ("Raspberry Pi Quick2Wire blink\n") ;
    
    wiringPiSetup () ;
    pinMode (LED1, OUTPUT) ;
    pinMode (LED2, OUTPUT) ;
    pinMode (LED3, OUTPUT) ;
    pinMode (LED4, OUTPUT) ;
    pinMode (LED5, OUTPUT) ;
    pinMode (LED6, OUTPUT) ;
    pinMode (LED7, OUTPUT) ;
    pinMode (LED8, OUTPUT) ;
    pinMode (LED9, OUTPUT) ;
    pinMode (LED10, OUTPUT) ;
    pinMode (LED11, OUTPUT) ;
    pinMode (LED12, OUTPUT) ;
    pinMode (LED13, OUTPUT) ;
    pinMode (LED14, OUTPUT) ;
    pinMode (LED15, OUTPUT) ;
    pinMode (LED16, OUTPUT) ;
    pinMode (LED17, OUTPUT) ;
    pinMode (LED18, OUTPUT) ;
    pinMode (LED19, OUTPUT) ;
    pinMode (LED20, OUTPUT) ;
    pinMode (LED21, OUTPUT) ;
    pinMode (LED22, OUTPUT) ;
    pinMode (LED23, OUTPUT) ;
    pinMode (LED24, OUTPUT) ;
    pinMode (LED25, OUTPUT) ;
    
    for (;;)
    {
        digitalWrite (LED1, HIGH) ;  // On
        digitalWrite (LED2, HIGH) ;  // On
        digitalWrite (LED3, HIGH) ;  // On
        digitalWrite (LED4, HIGH) ;  // On
        digitalWrite (LED5, HIGH) ;  // On
        digitalWrite (LED6, HIGH) ;  // On
        digitalWrite (LED7, HIGH) ;  // On
        digitalWrite (LED8, HIGH) ;  // On
        digitalWrite (LED9, HIGH) ;  // On
        digitalWrite (LED10, HIGH) ;  // On
        digitalWrite (LED11, HIGH) ;  // On
        digitalWrite (LED12, HIGH) ;  // On
        digitalWrite (LED13, HIGH) ;  // On
        digitalWrite (LED14, HIGH) ;  // On
        digitalWrite (LED15, HIGH) ;  // On
        digitalWrite (LED16, HIGH) ;  // On
        digitalWrite (LED17, HIGH) ;  // On
        digitalWrite (LED18, HIGH) ;  // On
        digitalWrite (LED19, HIGH) ;  // On
        digitalWrite (LED20, HIGH) ;  // On
        digitalWrite (LED21, HIGH) ;  // On
        digitalWrite (LED22, HIGH) ;  // On
        digitalWrite (LED23, HIGH) ;  // On
        digitalWrite (LED24, HIGH) ;  // On
        digitalWrite (LED25, HIGH) ;  // On
        delay (500) ;               // mS
//        digitalWrite (LED, LOW) ;   // Off
        digitalWrite (LED1, LOW) ;  // On
        digitalWrite (LED2, LOW) ;  // On
        digitalWrite (LED3, LOW) ;  // On
        digitalWrite (LED4, LOW) ;  // On
        digitalWrite (LED5, LOW) ;  // On
        digitalWrite (LED6, LOW) ;  // On
        digitalWrite (LED7, LOW) ;  // On
        digitalWrite (LED8, LOW) ;  // On
        digitalWrite (LED9, LOW) ;  // On
        digitalWrite (LED10, LOW) ;  // On
        digitalWrite (LED11, LOW) ;  // On
        digitalWrite (LED12, LOW) ;  // On
        digitalWrite (LED13, LOW) ;  // On
        digitalWrite (LED14, LOW) ;  // On
        digitalWrite (LED15, LOW) ;  // On
        digitalWrite (LED16, LOW) ;  // On
        digitalWrite (LED17, LOW) ;  // On
        digitalWrite (LED18, LOW) ;  // On
        digitalWrite (LED19, LOW) ;  // On
        digitalWrite (LED20, LOW) ;  // On
        digitalWrite (LED21, LOW) ;  // On
        digitalWrite (LED22, LOW) ;  // On
        digitalWrite (LED23, LOW) ;  // On
        digitalWrite (LED24, LOW) ;  // On
        digitalWrite (LED25, LOW) ;  // On
        delay (500) ;
    }
    return 0 ;
}