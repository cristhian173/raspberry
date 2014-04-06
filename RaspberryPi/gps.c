/*
 *  Description: This example start the GPS engine and get NMEA strings.
 *  For more information about the AT commands, refer to the AT
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
 *  Version 0.1
 *  Author: Alejandro Gallego
 */

//Include arduPi library
#include "arduPi.h"

int8_t sendATcommand(char* ATcommand, char* expected_answer1,
                     unsigned int timeout);
void power_on();

int8_t answer;
int onModulePin= 2;
int counter;
long previous;


char Basic_str[100];
char GGA_str[100];
char GLL_str[100];
char RMC_str[100];
char VTG_str[100];
char ZDA_str[100];

void setup(){
    
    pinMode(onModulePin, OUTPUT);
    Serial.begin(115200);
    
    printf("Starting...\n");
    power_on();
    
    delay(3000);
    
    // sets the PIN code
    sendATcommand("AT+CPIN=****", "OK", 2000);
    
    delay(3000);
    
    // sets APN, user name and password
    sendATcommand("AT+CGPSPWR=1", "OK", 2000);
    sendATcommand("AT+CGPSRST=0", "OK", 2000);
    
    
    // waits for fix GPS
    while( (sendATcommand("AT+CGPSSTATUS?", "2D Fix", 5000) ||
            sendATcommand("AT+CGPSSTATUS?", "3D Fix", 5000)) == 0 );
    
    
}

void loop(){
    // Basic
    // Clean the input buffer
    while( Serial.available() > 0) Serial.read();
    delay(100);
    // request Basic string
    sendATcommand("AT+CGPSINF=0", "AT+CGPSINF=0\r\n\r\n", 2000);
    
    counter = 0;
    answer = 0;
    memset(Basic_str, '\0', 100);    // Initialize the string
    previous = millis();
    // this loop waits for the NMEA string
    do{
        
        if(Serial.available() != 0){
            Basic_str[counter] = Serial.read();
            counter++;
            // check if the desired answer is in the response of the module
            if (strstr(Basic_str, "OK") != NULL)
            {
                answer = 1;
            }
        }
        // Waits for the asnwer with time out
    }while((answer == 0) && ((millis() - previous) < 2000));
    
    Basic_str[counter-3] = '\0';
    
    //**********************************************************
    // GGA
    // Clean the input buffer
    while( Serial.available() > 0) Serial.read();
    delay(100);
    // request GGA string
    sendATcommand("AT+CGPSINF=2", "AT+CGPSINF=2\r\n\r\n", 2000);
    
    counter = 0;
    answer = 0;
    memset(GGA_str, '\0', 100);    // Initialize the string
    previous = millis();
    // this loop waits for the NMEA string
    do{
        
        if(Serial.available() != 0){
            GGA_str[counter] = Serial.read();
            counter++;
            // check if the desired answer is in the response of the module
            if (strstr(GGA_str, "OK") != NULL)
            {
                answer = 1;
            }
        }
        // Waits for the asnwer with time out
    }while((answer == 0) && ((millis() - previous) < 2000));
    
    GGA_str[counter-3] = '\0';
    
    //**********************************************************
    // GLL
    // Clean the input buffer
    while( Serial.available() > 0) Serial.read();
    
    delay(100);
    // request GLL string
    sendATcommand("AT+CGPSINF=4", "AT+CGPSINF=4\r\n\r\n", 2000);
    
    counter = 0;
    answer = 0;
    memset(GLL_str, '\0', 100);    // Initialize the string
    previous = millis();
    // this loop waits for the NMEA string
    do{
        
        if(Serial.available() != 0){
            GLL_str[counter] = Serial.read();
            counter++;
            // check if the desired answer is in the response of the module
            if (strstr(GLL_str, "OK") != NULL)
            {
                answer = 1;
            }
        }
        // Waits for the asnwer with time out
    }while((answer == 0) && ((millis() - previous) < 2000));
    
    GLL_str[counter-3] = '\0';
    
    //**********************************************************
    // RMC
    // Clean the input buffer
    while( Serial.available() > 0) Serial.read();
    
    delay(100);
    // request RMC string
    sendATcommand("AT+CGPSINF=32", "AT+CGPSINF=32\r\n\r\n", 2000);
    
    counter = 0;
    answer = 0;
    memset(RMC_str, '\0', 100);    // Initialize the string
    previous = millis();
    // this loop waits for the NMEA string
    do{
        
        if(Serial.available() != 0){
            RMC_str[counter] = Serial.read();
            counter++;
            // check if the desired answer is in the response of the module
            if (strstr(RMC_str, "OK") != NULL)
            {
                answer = 1;
            }
        }
        // Waits for the asnwer with time out
    }while((answer == 0) && ((millis() - previous) < 2000));
    
    RMC_str[counter-3] = '\0';
    
    //**********************************************************
    // VTG
    // Clean the input buffer
    while( Serial.available() > 0) Serial.read();
    
    delay(100);
    // request VTG string
    sendATcommand("AT+CGPSINF=64", "AT+CGPSINF=64\r\n\r\n", 2000);
    
    counter = 0;
    answer = 0;
    memset(VTG_str, '\0', 100);    // Initialize the string
    previous = millis();
    // this loop waits for the NMEA string
    do{
        
        if(Serial.available() != 0){
            VTG_str[counter] = Serial.read();
            counter++;
            // check if the desired answer is in the response of the module
            if (strstr(VTG_str, "OK") != NULL)
            {
                answer = 1;
            }
        }
        // Waits for the asnwer with time out
    }while((answer == 0) && ((millis() - previous) < 2000));
    
    VTG_str[counter-3] = '\0';
    
    //**********************************************************
    // ZDA
    // Clean the input buffer
    while( Serial.available() > 0) Serial.read();
    
    delay(100);
    // request ZDA string
    sendATcommand("AT+CGPSINF=128", "AT+CGPSINF=128\r\n\r\n", 2000);
    
    counter = 0;
    answer = 0;
    memset(ZDA_str, '\0', 100);    // Initialize the string
    previous = millis();
    // this loop waits for the NMEA string
    do{
        
        if(Serial.available() != 0){
            ZDA_str[counter] = Serial.read();
            counter++;
            // check if the desired answer is in the response of the module
            if (strstr(ZDA_str, "OK") != NULL)
            {
                answer = 1;
            }
        }
        // Waits for the asnwer with time out
    }while((answer == 0) && ((millis() - previous) < 2000));
    
    ZDA_str[counter-3] = '\0';
    
    printf("*************************************************\n");
    printf("Basic string: ");
    printf("%s\n",Basic_str);
    printf("GGA string: ");
    printf("%s\n",GGA_str);
    printf("GLL string: ");
    printf("%s\n",GLL_str);
    printf("RMC string: ");
    printf("%s\n",RMC_str);
    printf("VTG string: ");
    printf("%s\n",VTG_str);
    printf("ZDA string: ");
    printf("%s\n",ZDA_str);
    
    delay(15000);
    
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
        while(answer == 0){
            // Send AT every two seconds and wait for the answer
            answer = sendATcommand("AT", "OK", 2000);
        }
    }
    
}


int8_t sendATcommand(char* ATcommand, char* expected_answer1,
                     unsigned int timeout)
{
    
    uint8_t x=0,  answer=0;
    char response[100];
    unsigned long previous;
    
    memset(response, '\0', 100);    // Initialize the string
    
    delay(100);
    
    // Clean the input buffer
    while( Serial.available() > 0) Serial.read();
    
    Serial.println(ATcommand);    // Send the AT command
    
    
    x = 0;
    previous = millis();
    
    // this loop waits for the answer
    do{
        
        if(Serial.available() != 0){
            response[x] = Serial.read();
            x++;
            // check if the desired answer is in the response of the module
            if (strstr(response, expected_answer1) != NULL)
            {
                answer = 1;
            }
        }
        // Waits for the asnwer with time out
    }while((answer == 0) && ((millis() - previous) < timeout));
    
    return answer;
}

int main(){
    setup();
    while(1){loop();}
    return 0;
}