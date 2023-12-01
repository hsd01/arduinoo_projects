# arduinoo_projects

# How the HC-SR04 Ultrasonic Distance Sensor Works?
It emits an ultrasound at 40 000 Hz which travels through the air and if there is an object
or obstacle on its path It will bounce back to the module. Considering the travel time and 
the speed of the sound you can calculate the distance.
In order to generate the ultrasound we need to set the Trig pin on a High State for 10 µs.
That will send out an 8 cycle ultrasonic burst which will travel at the speed of sound. 
The Echo pins goes high right away after that 8 cycle ultrasonic burst is sent, and it starts
listening or waiting for that wave to be reflected from an object.
If there is no object or reflected pulse, the Echo pin will time-out after 38ms and get back to low state.
If we receive a reflected pulse, the Echo pin will go down sooner than those 38ms. According to the amount 
of time the Echo pin was HIGH, we can determine the distance the sound wave traveled, thus the distance 
from the sensor to the object.
For that purpose we are using the following basic formula for calculating distance:

*Distance* = *Speed* x *Time*

We actually know both the speed and the time values. The time is the amount of time the Echo pin was HIGH, 
and the speed is the speed of sound which is 340m/s. There’s one additional step we need to do, and that’s 
divide the end result by 2. and that’s because we are measuring the duration the sound wave needs to travel 
to the object and bounce back.

Let’s say the Echo pin was HIGH for 2ms. If we want the get the distance result in cm, we can convert the speed
of sound value from 340m/s to 34cm/ms.
Distance = (Speed x Time) / 2 = (34cm/ms x 1.5ms) / 2 = 25.5cm.
So, if the Echo pin was HIGH for 2ms (which we measure using the pulseIn() function), 
the distance from the sensor to the object is 34cm.

# auto tea 


