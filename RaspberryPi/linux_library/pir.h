//
//  pir.h
//  RaspberryPi
//
//  Created by Mamunul Mazid on 4/6/14.
//  Copyright (c) 2014 Mamunul Mazid. All rights reserved.
//

#ifndef __RaspberryPi__pir__
#define __RaspberryPi__pir__

#include <iostream>

#include "linux_gpio.h"

class Pir{
    LinuxGPIO *inputPin;
    bool stopSearchingMovement;
    bool isObjectMovement;
    
    void InitializePins(int gpio_no);
    void ActivatePir(bool active);
    
public:
    Pir();
    Pir(int gpio_no);
    ~Pir();
    bool IsObjectMoving();
   
    void CheckObjectMovement(struct timespec delay);
    void StopObjectMovement();
    
};

#endif /* defined(__RaspberryPi__pir__) */
