#include <Servo.h>

Servo x_mov;
int val;

void setup() {
  Serial.begin(9600);
  x_mov.attach(10);
}
void loop(){
  //serialEvent();
}
  
void serialEvent() {
    val = Serial.parseInt();
    if(val != 0){
      x_mov.write(val);  
    }
    Serial.print("x "); Serial.println(val); 
 }


