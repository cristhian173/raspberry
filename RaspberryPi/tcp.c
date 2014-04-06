/*
 *  Description: This example shows how to configure the GPRS module in single
 *  client mode and open a TCP socket as client. This example only shows the
 *  AT commands (and the answers of the module) used to open a TCP/UDP
 *  connection. For more information about the AT commands, refer to
 *  the AT command manual.
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

int8_t sendATcommand2(char* ATcommand, char* expected_answer1,
                      char* expected_answer2, unsigned int timeout);
void power_on();


int8_t answer;
int onModulePin= 2;
char aux_str[50];

char ip_data[40]="Test string from GPRS shield\r\n";



void setup(){
    
    pinMode(onModulePin, OUTPUT);
    Serial.begin(115200);
    
    Serial.println("Starting...");
    power_on();
    
    delay(3000);
    
    // sets the PIN code
    sendATcommand2("AT+CPIN=****", "OK", "ERROR", 2000);
    
    delay(3000);
    
    Serial.println("Connecting to the network...");
    
    while( sendATcommand2("AT+CREG?", "+CREG: 0,1", "+CREG: 0,5", 1000)== 0 );
    
}


void loop(){
    
    
    // Selects Single-connection mode
    if (sendATcommand2("AT+CIPMUX=0", "OK", "ERROR", 1000) == 1)
    {
        // Waits for status IP INITIAL
        while(sendATcommand2("AT+CIPSTATUS", "INITIAL", "", 500)  == 0 );
        delay(5000);
        
        // Sets the APN, user name and password
        if (sendATcommand2("AT+CSTT=\"APN\",\"user_name\",\"password\"", "OK",  "ERROR", 30000) == 1)
        {
            // Waits for status IP START
            while(sendATcommand2("AT+CIPSTATUS", "START", "", 500)  == 0 );
            delay(5000);
            
            // Brings Up Wireless Connection
            if (sendATcommand2("AT+CIICR", "OK", "ERROR", 30000) == 1)
            {
                // Waits for status IP GPRSACT
                while(sendATcommand2("AT+CIPSTATUS", "GPRSACT", "", 500)  == 0 );
                delay(5000);
                
                // Gets Local IP Address
                if (sendATcommand2("AT+CIFSR", ".", "ERROR", 10000) == 1)
                {
                    // Waits for status IP STATUS
                    while(sendATcommand2("AT+CIPSTATUS", "IP STATUS", "", 500)  == 0 );
                    delay(5000);
                    Serial.println("Openning TCP");
                    
                    // Opens a TCP socket
                    if (sendATcommand2("AT+CIPSTART=\"TCP\",\"IP_address\",\"port\"",
                                       "CONNECT OK", "CONNECT FAIL", 30000) == 1)
                    {
                        Serial.println("Connected");
                        
                        // Sends some data to the TCP socket
                        sprintf(aux_str,"AT+CIPSEND=%d", strlen(ip_data));
                        if (sendATcommand2(aux_str, ">", "ERROR", 10000) == 1)
                        {
                            sendATcommand2(ip_data, "SEND OK", "ERROR", 10000);
                        }
                        
                        // Closes the socket
                        sendATcommand2("AT+CIPCLOSE", "CLOSE OK", "ERROR", 10000);
                    }
                    else
                    {
                        Serial.println("Error openning the connection");
                    }
                }
                else
                {
                    Serial.println("Error getting the IP address");
                }
            }
            else
            {
                Serial.println("Error bring up wireless connection");
            }
        }
        else
        {
            Serial.println("Error setting the APN");
        }
    }
    else
    {
        Serial.println("Error setting the single connection");
    }
    
    sendATcommand2("AT+CIPSHUT", "OK", "ERROR", 10000);
    delay(10000);
}

void power_on(){
    
    uint8_t answer=0;
    
    // checks if the module is started
    answer = sendATcommand2("AT", "OK", "OK", 2000);
    if (answer == 0)
    {
        // power on pulse
        digitalWrite(onModulePin,HIGH);
        delay(3000);
        digitalWrite(onModulePin,LOW);
        
        // waits for an answer from the module
        while(answer == 0){     // Send AT every two seconds and wait for the answer
            answer = sendATcommand2("AT", "OK", "OK", 2000);
        }
    }
    
}

int8_t sendATcommand2(char* ATcommand, char* expected_answer1,
                      char* expected_answer2, unsigned int timeout){
    
    uint8_t x=0,  answer=0;
    char response[100];
    unsigned long previous;
    
    memset(response, '\0', 100);    // Initialize the string
    
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
            // check if the desired answer 1  is in the response of the module
            if (strstr(response, expected_answer1) != NULL)
            {
                answer = 1;
            }
            // check if the desired answer 2 is in the response of the module
            else if (strstr(response, expected_answer2) != NULL)
            {
                answer = 2;
            }
        }
    }
    // Waits for the asnwer with time out
    while((answer == 0) && ((millis() - previous) < timeout));
    
    return answer;
}

int main (){
    setup();
    while(1){
        loop();
    }
    return (0);
}