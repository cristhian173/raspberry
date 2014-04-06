//
//  blink.h
//  RaspberryPi
//
//  Created by Mamunul Mazid on 4/4/14.
//  Copyright (c) 2014 Mamunul Mazid. All rights reserved.
//

#ifndef __RaspberryPi__blink__
#define __RaspberryPi__blink__

#include <iostream>

#endif /* defined(__RaspberryPi__blink__) */

#include "linux_gpio.h"

 class Blink{

    LinuxGPIO* outputPin;
    LinuxGPIO* inputPin;
    
   void initializePins();
   
    
public:
    Blink();
    ~Blink();
    void startToBlink(int width);//width is millisecond
    void startToBlink(int onewidth, int zerowidth); //height, width both is in milliseconds
//if else switch do do while for

 };
