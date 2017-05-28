#include <Servo.h>
#define x_home 90
#define y_home 0
Servo x_mov;
Servo y_mov;

int x_val;
int y_val;
String buf;

void setup() {
  Serial.begin(9600);
  x_mov.attach(10);
  y_mov.attach(7);

  x_mov.write(x_home);
  y_mov.write(y_home);
}

String delimiter(String in, int order) {
  int colonIndex = in.indexOf(':');
  if(order == 0) {
    return in.substring(0, colonIndex);
  } else
    return in.substring(colonIndex + 1);
}
  
void serialEvent() { 
    buf  = Serial.readString();
    x_val = delimiter(buf,0).toInt();
    y_val = delimiter(buf,1).toInt();  
}

void loop(){
    x_mov.write(x_val);
    y_mov.write(y_val); 
     Serial.print("buf "); Serial.println(buf);
    Serial.print("x "); Serial.println(x_val);
    Serial.print("y "); Serial.println(y_val);
}
