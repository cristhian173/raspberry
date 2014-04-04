//
//  blink.cpp
//  RaspberryPi
//
//  Created by Mamunul Mazid on 4/4/14.
//  Copyright (c) 2014 Mamunul Mazid. All rights reserved.
//

#include "blink.h"

Blink::Blink(){
    initializePins();


}

Blink::~Blink(){


}


void Blink::initializePins(){

    outputPin=new LinuxGPIO(4);//gpio number
    
    outputPin->SetDirection(true);
    
//    inputPin=new LinuxGPIO(4);
//    inputPin->SetDirection(false);

}

void Blink::startToBlink(int width){

    this->startToBlink(width, width);
    
}

void Blink::startToBlink(int width, int height){

    while (1) {
        outputPin->SetValue(true);
        //        delay(width);
        sleep(width);
        outputPin->SetValue(false);
        sleep(height);
    }
    
    
}






