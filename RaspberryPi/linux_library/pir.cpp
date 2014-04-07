//
//  pir.cpp
//  RaspberryPi
//
//  Created by Mamunul Mazid on 4/6/14.
//  Copyright (c) 2014 Mamunul Mazid. All rights reserved.
//

#include "pir.h"


Pir::Pir(){

}
Pir::Pir(int gpio_no){
    
    this->InitializePins( gpio_no);

}
Pir::~Pir(){

}

void Pir::InitializePins(int gpio_no){
     this->inputPin=new RaspberryGPIO(gpio_no);
     this->inputPin->SetDirection(false);
}

void Pir::CheckObjectMovement(struct timespec delay){
    
    this->stopSearchingMovement=false;
    while(!this->stopSearchingMovement){
    
        this->isObjectMovement=this->inputPin->GetValue();
        nanosleep(&delay, NULL);
    
    }

}

void Pir::StopObjectMovement(){
    this->stopSearchingMovement=true;
}

bool Pir::IsObjectMoving(){
    
    return this->isObjectMovement;
    
}
void Pir::ActivatePir(bool active){

}