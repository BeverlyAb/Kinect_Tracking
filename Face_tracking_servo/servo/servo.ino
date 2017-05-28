#include <Servo.h>
#define x_home 90
#define y_home 180
#define x_pin 10
#define y_pin 6 // left - inverted
#define light_pin 5

Servo x_mov;
Servo y_mov;

String buf;
int x_val;
int y_val;
int shoot;

void setup() {
  Serial.begin(9600);
  x_mov.attach(x_pin);
  y_mov.attach(y_pin);
  
  x_mov.write(x_home);
  y_mov.write(y_home);
}

String delimiter(String in, int order) {
  int colonIndex = in.indexOf(':');
  int colonIndexTwo = in.indexOf(':', colonIndex +1);
  //int check = in.indexOf(':',colonIndex +1);
  //check = in.indexOf(':',check + 1); // checks if there are too many colons and serial was disrupted
//  Serial.print("check "); Serial.println(check);
  if(order == 0) { // x_val
    return in.substring(0, colonIndex);
  /*} else if (order == 1){ //y_val
    if(check != -1) {// serial is disrupted
      return in.substring(check + 1);
    } else {// serial is properly sent
      return in.substring(colonIndex + 1);
    }
  } else if (order == 2) { // shoot
      if(check != -1) {// serial is disrupted
        return in.substring(check + 1);
      } else {// serial is properly sent
        return in.substring(colonIndex+ 1);
      }
  }*/
  } else if(order == 1) {
    return in.substring(colonIndex + 1, colonIndexTwo);
  }else {
    return in.substring(colonIndexTwo + 1);
  }
}
  
void serialEvent() { 
    buf  = Serial.readString();
    x_val = delimiter(buf,0).toInt();
    y_val =  180-85-delimiter(buf,1).toInt(); //only for left  
    shoot = delimiter(buf,2).toInt();
}


void loop(){
    x_mov.write(x_val);
    delay(50); // delay causes serial disruption, but necessary for y_mov 
    y_mov.write(y_val); 
    if(shoot == 1) {
      digitalWrite(light_pin, HIGH);
    } else {
      digitalWrite(light_pin, LOW);
    }
    
    Serial.print("buf "); Serial.println(buf);
    Serial.print("x "); Serial.println(x_val);
    Serial.print("y "); Serial.println(y_val);
    Serial.print("shoot "); Serial.println(shoot);
}
