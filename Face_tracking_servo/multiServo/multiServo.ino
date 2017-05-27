//limits
#define panServo_min 0
#define panServo_max 180
#define tiltServo_min 0
#define tiltServo_max 180
//starting positions 
#define panServo_Home 90
#define tiltServo_Home 5
//trigger positions

//to shoot or not to shoot

//pin instantiaions
int panServoPin;
int tiltServoPinR;
int tiltServoPinL;
int ledPin;

typedef struct config_t
{
  int val; // serial data
  int shoot; //bool
}

configuration;
configuration configuration1;

#include <Servo.h>

Servo pan;    // 10
Servo tilt_R; // 6 or 7 from front
Servo tilt_L; // 6 or 7
//http://forums.trossenrobotics.com/tutorials/how-to-diy-128/complete-control-of-an-arduino-via-serial-3300/

int x;
int y_R;
int y_L;
int shoot;

// some bytes used during serial communication
byte header;
byte xbyte100;  // x                     
byte ybyte010;  // y -RIGHT
byte ybyte001;  // r -LEFT
byte lightByte; // indicator for shooting

//pins!
void assignPins(){
  panServoPin = 10;
  tiltServoPinR = 7;
  tiltServoPinL = 6;
  ledPin = 5; 
}

void setup() {
  assignPins(); 
  Serial.begin(9600);
  //connect pins to devices
  pan.attach(panServoPin);
  tilt_R.attach(tiltServoPinR);
  tilt_L.attach(tiltServoPinL);
  //set to starting positions
  pan.write(panServo_Home);
  tilt_R.write(tiltServo_Home);
  tilt_L.write(90); 

  //led
  pinMode(ledPin,OUTPUT);
}

void serialEvent(){
  if(Serial.available() >= 2) { // new set of packet with 5 variables
    header = Serial.read();
    if(header == 's'){
      //read Kinect data
 /*     xbyte100  = Serial.read();
      ybyte010 = Serial.read();
      ybyte001 = Serial.read();
      lightByte = Serial.read();
*/
/*      //convert byte to int
      x = int(xbyte100);// - 48;
      y_R = int(ybyte010);// - 48;
      y_L = int(ybyte001);// - 48;
      shoot = int(lightByte);// - 48;           // convert byte to integer
*/
      x = Serial.parseInt();
     /* y_R = Serial.toInt();
      y_L = Serial.toInt();
      shoot = Serial.toInt();  
      */
      // execute
      pan.write(x);
     // tilt_R.write(y_R);
      //tilt_L.write(y_L);
   /*   if(shoot  >= 1){ 
        digitalWrite(ledPin, HIGH);   
      } else {
        digitalWrite(ledPin, LOW);
      } 
*/
   //Serial.println(Servo.read());
      Serial.print("s "); Serial.println(header);
      Serial.print("x "); Serial.println(x);
    //  Serial.print("y_R "); Serial.println(y_R);
    //  Serial.print("y_L "); Serial.println(y_L); 
    } 
  } 
}

 
void loop()
{
}
  


