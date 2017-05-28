#include <Servo.h>
#define x_home 90
#define y_home 180
#define x_pin 10
#define y_pin 6 // left - inverted
Servo x_mov;
Servo y_mov;

int x_val;
int y_val;
String buf;

void setup() {
  Serial.begin(9600);
  x_mov.attach(x_pin);
  y_mov.attach(y_pin);

  x_mov.write(x_home);
  y_mov.write(y_home);
}

String delimiter(String in, int order) {
  int colonIndex = in.indexOf(':');
  int check = in.indexOf(':',colonIndex +1);
  Serial.print("check "); Serial.println(check);
  if(order == 0) { // x_val
    return in.substring(0, colonIndex);
  } else if (order == 1){
    if(check != -1) {// serial is disrupted
      return in.substring(check + 1);
    } else {// serial is properly sent
      return in.substring(colonIndex+ + 1);
    }
  }
}
  
void serialEvent() { 
    buf  = Serial.readString();
    x_val = delimiter(buf,0).toInt();
    y_val =  180-85-delimiter(buf,1).toInt(); //only for left  
}


void loop(){
    x_mov.write(x_val);
    delay(50); // delay causes serial disruption, but necessary for y_mov 
    y_mov.write(y_val); 
    
    Serial.print("buf "); Serial.println(buf);
    Serial.print("x "); Serial.println(x_val);
    Serial.print("y "); Serial.println(y_val);
}
