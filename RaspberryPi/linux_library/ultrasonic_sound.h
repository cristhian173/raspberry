//
//  ultrasonic_sound.h
//  RaspberryPi
//
//  Created by Mamunul Mazid on 4/6/14.
//  Copyright (c) 2014 Mamunul Mazid. All rights reserved.
//

#ifndef __RaspberryPi__ultrasonic_sound__
#define __RaspberryPi__ultrasonic_sound__

#include <iostream>

#include "linux_gpio.h"
#include <sys/time.h>
#include <time.h>

class Ultrasound{
    
    
    LinuxGPIO *triggerPin;
    LinuxGPIO *echoPin;

    void trigger();
    void checkEndofSonicBurst();
    void initializePins(int trig_gpio,int echo_gpio);
    
public:
    Ultrasound(int trig_gpio,int echo_gpio);
    ~Ultrasound();
    int checkDistance();


};

#endif /* defined(__RaspberryPi__ultrasonic_sound__) */
