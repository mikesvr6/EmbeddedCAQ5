#include "mbed.h"
#include <cstdio>


 InterruptIn BUTTON(PC_13); // Initialise the User button as the interupt button

volatile int ispressed = 0;

void BUTTON_pressed(){
    ispressed = 1;
}
int main()
{
        
        BUTTON.fall(&BUTTON_pressed);   //action to be taken when button is in fall (pushed)
        
        while (true) {
            if (ispressed == 1) {
                printf("Button press count %d \r\n", ispressed); //print to the command screen that the button has been pushed 
                ispressed = 0;
                
            }
        }
}