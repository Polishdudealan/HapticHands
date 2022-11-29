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

## Unity Package Installation Guideline
1. Install Unity
1. Visit [Unity online asset store](https://assetstore.unity.com/packages/tools/integration/oculus-integration-82022) and add Oculus Integration to your resources. Remember to use the same account to login the Unity and the Unity asset store.
2. Create an empty Unity 3D project
3. In menu bar, go to windows -> package manager. In a drop down menu, find my assets. Then select Oculus Integration, download and import it.
4. Keep the project opening, in local file explorer, find the Unity package for the hand project then double click it.
5. Import all files in the package. (You don't need to select Oculus folder if there is any in the package)(If there is an error showing up, re-import the Oculus Integration)
6. If there are some warning complaining about SerialPort, in menu bar, go to edit -> project settings -> player -> other settings, find .Net settings. Set it to .Net4.0 or some other versions you have, just not set it to .Net2.0.
7. You can adjust the values and properties in the side panels. For gameobject CommManager, you can adjust comport and calibration. You can find scripts in the file explorer on the bottom.


