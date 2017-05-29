# Human Sensing with Kinect

This uses the Kinect SDK, specifically, FaceBasics WPF in C#. This also uses an Arduino to control the "Shooter," which consists of an x-axis and y-axis servo, and an LED.
The Shooter tracks and follows a person's face and lights the LED if the person is happy.

I altered the Main.cs from the Kinect SDK and wrote servo.ino in order for the Shooter to wirelessly receive Main.cs serial information. 

