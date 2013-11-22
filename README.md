#RobotMovementLibrary


Uses the MSP430 Microcontroller to move a Robot!

##Basic Function

This code will implement simple movements on a robot to make it do basic manuevers such as move forward, move backward,
move left, and move right. The movements only last approximately 1 second each with exception to the small left and
right turns which take 0.5 seconds to complete. There are large left and right turns also in the code which take 1 
second to complete. Make sure you have enough room to let the robot roam free.

##Required Equipment

- MSP430G2553 Microcontroller Chip
- SN754410 Motor Driver Chip
- LDV33 3.3V Regulator
- 100 Micro Farad Capacitor
- Robot built with battery, on/off switch, place for MSP430 launchpad


##Important Note on the Robot

- Make sure that you use a duty cycle appropriate the move the robot
- Put some additional weight or a large battery on one side of the robot to not let it be so "jerky"
- The "jerkyness" of movements could potentially reset the robot and make it start all over with implementing movement code

##Code Explanations

```
void ConfigTimer()
```
- In this section of my code for motor.c file, I use timer A to interface between the MSP430 and the motor driver chip

```
void MoveRightMotorForward()
```
- Forward movement is set on TA1.1, which is not grounded at this point. We want to set the duty cycle here as well as resetting the 1.0 backward at OUTMOD_5

```
void MoveLeftMotorForward()
```
- Much of the same as the right motor except we are operating on TA0.1 in the code. Set this to the duty cycle to move foward.

```
void MoveRightMotorBackward()
```
- Here we want to make sure that 1.1 gets set to be ground, so we set the duty cycle to '0' and toggle the reverse using OUTMOD_4

```
void MoveLeftMotorBackward()
```
- Same as right motor backward, except we are operting on 0.1, repeat the steps

```
void MoveForward()
```
- Here the right motor forward and left motor forward code get implemented. 
- Makes sense right? We want both motors to move forward at once to get the robot to move

```
void MoveBackward()
```
- Same as move forward command except now we use the move left motor backward and right motor backward as well
- It is as easy and simple as that!
- I will use the rest to you to figure out the left and right turns!
- Do not forget to include functions you declare in the header file as well as telling your robot to implement them in the main.c file!!!

##Documented Help on Code

- I recieved help from C2C Brandon Belcher on figuring out the toggle. In my previous code I did not toggle on the backward movements.
- I recieved help from Capt Branchflower with GitHub. I forgot to pull my Readme file before pushing the rest of my code to GitHub
- I recieved help from C2C Ryan Turner who gave me a basic understanding of Timer A and the motors itself


##Licensing 

Feel free to use my code! I hope you all have fun programming robots. I hope my code is simple to follow. If you have any questions
feel free to contact me. Any concerns or critiques to my code, please let me know as I am always looking to become a better programmer!





