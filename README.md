# Haptic Hands

## Components Specs and Technicalities

### Servo MG90S 5V
Servo in controlled by pwm signals generated by timer 2. System clock is 16 Mhz.
Timer is prescaled by 4. To achieve a period of 20ms necessary for servo control, the counter period is 80,000. 
While the MG90S spec sheet states duty cycle of 1-2ms controls 0-180 degrees, this is not the case for the servos we have.
Our servos take between 0.5-2.5ms to move 0-180 degrees.


### Potentiometer 3.3V
The potentiometer value is access through an ADC port on the nucleo. DMA conversions are maintained by Timer 3 at a frequency of 1kHz.
The value is transferred to the program during the callback. Then is is sampled by user programs.

### Recalibration Button (Currently Blue Button on Nucleo)
DO NOT PRESS WHILE GLOVE IS ON.
This will bring the servo to angle 0 and send command '0' to the PC to map servo angle 0 to potentiometer values.
Then it will bring the servo to angle 180 and send command 'M' to the PC to map servo angle 180 to potentiometer values.
It is the job of the PC to do the rest of the math there (might change in future).
It is unknown if angle 180 would bend a user's fingers too far. It might be better to use a different value