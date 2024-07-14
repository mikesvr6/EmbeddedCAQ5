#include "mbed.h"
#include <cstdio>


 InterruptIn BUTTON(PC_13); // Initialise the User button as the interupt button
volatile int counter = 0; // Adding a variable to keep track of the total button presses. Volatile as the value will change
volatile int ispressed = 0; // Addind a variable to keep track of the press of the button. volatile as the button will be press/not pressed

void BUTTON_pressed(){ // Function to state what happens when the button is pushed
    ispressed = 1; // adjusted variable due to button press - from 0 not pressed to 1 
    counter++; //this will mean as button presses the counter variable will increase incrementally +1
}
int main()
{
        
        BUTTON.fall(&BUTTON_pressed);   // stating that the button function is to be taken when button is in fall (pushed)
        
        while (true) {
            if (ispressed == 1) {
                printf("Button press count %d \r\n", counter); //print to the command screen that the button count is now = 
                ispressed = 0; // setting the variable ispressed back to 0 so that the if function does not repeat indefinetly
                
            }
        }
}