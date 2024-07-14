#include "mbed.h"
#include <cstdio>


 InterruptIn BUTTON(PC_13); // Initialise the User button as the interupt button
volatile int counter = 0;
volatile int ispressed = 0;

void BUTTON_pressed(){
    ispressed = 1;
    counter++; //this will mean as button presses the counter variable will increase incrementally +1
}
int main()
{
        
        BUTTON.fall(&BUTTON_pressed);   //action to be taken when button is in fall (pushed)
        
        while (true) {
            if (ispressed == 1) {
                printf("Button press count %d \r\n", counter); //print to the command screen that the button count is now = 
                ispressed = 0;
                
            }
        }
}