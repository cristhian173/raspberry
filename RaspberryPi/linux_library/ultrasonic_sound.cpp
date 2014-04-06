//
//  ultrasonic_sound.cpp
//  RaspberryPi
//
//  Created by Mamunul Mazid on 4/6/14.
//  Copyright (c) 2014 Mamunul Mazid. All rights reserved.
//

#include "ultrasonic_sound.h"


void Ultrasound::trigger(){
    
    struct timespec delay;
    
    delay.tv_nsec=0;
    delay.tv_nsec=1000;
    
    this->triggerPin->SetValue(true);
    
    nanosleep(&delay, NULL);
    this->triggerPin->SetValue(false);

}
void Ultrasound::checkEndofSonicBurst(){
    
    int low_length=0;
    
    while(this->echoPin->GetValue()==0 && low_length<40){
        struct timeval timeday;
    
        gettimeofday(&timeday, NULL);
    
    }

}


Ultrasound::Ultrasound(int trig_gpio,int echo_gpio){
    this->initializePins(trig_gpio, echo_gpio);
}

void Ultrasound::initializePins(int trig_gpio, int echo_gpio){

    this->triggerPin=new LinuxGPIO(trig_gpio);
    this->echoPin=new LinuxGPIO(echo_gpio);
    
    this->triggerPin->SetDirection(true);
    this->echoPin->SetDirection(false);

}

Ultrasound::~Ultrasound(){
//    this->trigger();
    
    
}

int Ultrasound::checkDistance(){

    this->trigger();
    
    return 0;
}
