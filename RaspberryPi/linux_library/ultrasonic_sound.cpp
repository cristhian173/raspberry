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
    delay.tv_nsec=10000;
    
    this->triggerPin->SetValue(true);
    
    nanosleep(&delay, NULL);
    this->triggerPin->SetValue(false);

}
bool Ultrasound::checkEndofSonicBurst(){
    
    struct timeval time_day;
    
    gettimeofday(&time_day, NULL);  
    int low_time_start=0;
    int low_time_end=0;
    int count=0;
    bool pass_high=true;
    bool pass_low;
    
    while(count<12){
        
        if(this->echoPin->GetValue()==0){
            gettimeofday(&time_day, NULL);
            low_time_start=time_day.tv_usec;
            printf("low:%d",time_day.tv_usec);
            pass_low=true;
            if(pass_high){
                pass_high=false;
                count++;
            }
     }
        
        
        if(this->echoPin->GetValue()==1){
            gettimeofday(&time_day, NULL);
            low_time_end=time_day.tv_usec;
            printf("high:%d",time_day.tv_usec);
            pass_high=true;
            if(pass_low){
                pass_low=false;
                count++;
                
                if(count==8)
                {
                    return true;
                    break;
                }
            }
            printf("count:%d",count);
            
        }
    
    }
    
    return false;

}

bool Ultrasound::checkForEcho(){

while(this->echoPin->GetValue()==1)
    ;
    
    return true;
}


Ultrasound::Ultrasound(int trig_gpio,int echo_gpio){
    this->initializePins(trig_gpio, echo_gpio);
}

void Ultrasound::initializePins(int trig_gpio, int echo_gpio){

    this->triggerPin=new RaspberryGPIO(trig_gpio);
    this->echoPin=new RaspberryGPIO(echo_gpio);
    
    this->triggerPin->SetDirection(true);
    this->echoPin->SetDirection(false);

}

Ultrasound::~Ultrasound(){
//    this->trigger();
    
    
}

int Ultrasound::checkDistance(){

    this->trigger();
    
    this->checkEndofSonicBurst();
    this->checkForEcho();
    
    return 0;
}
