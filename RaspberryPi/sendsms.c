/*
 *  Description: This example shows how to send a SMS to a desired phone.
 *  This example only shows the AT commands (and the answers of the module) used
 *  to send the SMS. For more information about the AT commands, refer to the AT
 *  command manual.
 *
 *  Copyright (C) 2013 Libelium Comunicaciones Distribuidas S.L.
 *  http://www.libelium.com
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Version 0.2
 *  Author: Alejandro Gallego
 */

//Include arduPi library
#include "arduPi.h"

int8_t sendATcommand(char* ATcommand, char* expected_answer, unsigned int timeout);
void power_on();

int8_t answer;
int onModulePin= 2;
char aux_string[30];
char phone_number[]="*********";

void setup(){
    
    pinMode(onModulePin, OUTPUT);
    Serial.begin(115200);
    
    Serial.println("Starting...");
    power_on();
    
    delay(3000);
    
    // sets the PIN code
    sendATcommand("AT+CPIN=****", "OK", 2000);
    
    delay(3000);
    
    Serial.println("Connecting to the network...");
    
    while( (sendATcommand("AT+CREG?", "+CREG: 0,1", 500) ||
            sendATcommand("AT+CREG?", "+CREG: 0,5", 500)) == 0 );
    
    Serial.print("Setting SMS mode...");
    sendATcommand("AT+CMGF=1", "OK", 1000);    // sets the SMS mode to text
    Serial.println("Sending SMS");
    
    sprintf(aux_string,"AT+CMGS=\"%s\"", phone_number);
    answer = sendATcommand(aux_string, ">", 2000);    // send the SMS number
    if (answer == 1)
    {
        Serial.println("Test-Arduino-Hello World");
        Serial.write(0x1A);
        answer = sendATcommand("", "OK", 20000);
        if (answer == 1)
        {
            Serial.print("Sent ");
        }
        else
        {
            Serial.print("error ");
        }
    }
    else
    {
        Serial.print("error ");
        Serial.println(answer, DEC);
    }
    
}


void loop(){
    
}

void power_on(){
    
    uint8_t answer=0;
    
    // checks if the module is started
    answer = sendATcommand("AT", "OK", 2000);
    if (answer == 0)
    {
        // power on pulse
        digitalWrite(onModulePin,HIGH);
        delay(3000);
        digitalWrite(onModulePin,LOW);
        
        // waits for an answer from the module
        while(answer == 0){     // Send AT every two seconds and wait for the answer
            answer = sendATcommand("AT", "OK", 2000);
        }
    }
    
}

int8_t sendATcommand(char* ATcommand, char* expected_answer, unsigned int timeout){
    
    uint8_t x=0,  answer=0;
    char response[100];
    unsigned long previous;
    
    memset(response, '\0', 100);    // Initialice the string
    
    delay(100);
    
    while( Serial.available() > 0) Serial.read();    // Clean the input buffer
    
    Serial.println(ATcommand);    // Send the AT command
    
    
    x = 0;
    previous = millis();
    
    // this loop waits for the answer
    do{
        // if there are data in the UART input buffer, reads it and checks for the asnwer
        if(Serial.available() != 0){
            response[x] = Serial.read();
            x++;
            // check if the desired answer is in the response of the module
            if (strstr(response, expected_answer) != NULL)
            {
                answer = 1;
            }
        }
        // Waits for the asnwer with time out
    }while((answer == 0) && ((millis() - previous) < timeout));
    
    return answer;
}

int main (){
    setup();
    while(1){
        loop();
    }
    return (0);
}