#include <Ps3Controller.h>

#define LEFT   32
#define RIGHT  33
#define UP     26
#define BOTTOM 27
#define FIRE1  25
#define FIRE2  14

bool bottom;
bool top;
bool left;
bool right;
bool button1;
bool button2;
bool selectB;

bool rightStick;

void setup() {
  Serial.begin(115200);

  Ps3.attach(notify);
  Ps3.attachOnConnect(onConnect);
  Ps3.begin();
  
  String address = Ps3.getAddress();

  Serial.print("The ESPLEFT's Bluetooth MAC address is: ");
  Serial.println(address);

  pinMode(LEFT, OUTPUT);
  pinMode(RIGHT, OUTPUT);
  pinMode(UP, OUTPUT);
  pinMode(BOTTOM, OUTPUT);
  pinMode(FIRE1, OUTPUT);
  pinMode(FIRE2, OUTPUT);
}

void notify()
{
  //--- Digital cross/square/triangle/circle button events ---
  if ((Ps3.event.button_down.cross) || (Ps3.event.button_down.square) || (Ps3.event.button_down.l2) || (Ps3.event.button_down.l1) || (Ps3.event.button_down.l3) || (Ps3.event.button_down.r3)) {
    if (!button1) Serial.println("Started pressing the button 1");
    digitalWrite(FIRE1, HIGH);
    button1 = true;
  }
  if ((Ps3.event.button_up.cross) || (Ps3.event.button_up.square) || (Ps3.event.button_up.l2) || (Ps3.event.button_up.l1) || (Ps3.event.button_up.l3) || (Ps3.event.button_up.r3)) {
    if (button1) Serial.println("Released the button 1");
    digitalWrite(FIRE1, LOW);
    button1 = false;
  }

  if ((Ps3.event.button_down.triangle) || (Ps3.event.button_down.circle) || (Ps3.event.button_down.r2) || (Ps3.event.button_down.r1)) {
    if (!button2) Serial.println("Started pressing the button 2");
    digitalWrite(FIRE2, HIGH);
    button2 = true;
  }
  if ((Ps3.event.button_up.triangle) || (Ps3.event.button_up.circle) || (Ps3.event.button_up.r2) || (Ps3.event.button_up.r1)) {
    if (button2) Serial.println("Released the button 2");
    digitalWrite(FIRE2, LOW);
    button2 = false;
  }

  if (Ps3.event.button_down.select) {
    if (!selectB) Serial.println("Started pressing the select button");
    selectB = true;
  }
  if (Ps3.event.button_up.select) {
    if (selectB) Serial.println("Released the select button");
    if (selectB) {
      rightStick = !rightStick;
    }
    selectB = false;
  }

  if (rightStick) {
    if( abs(Ps3.event.analog_changed.stick.rx) + abs(Ps3.event.analog_changed.stick.ry) > 2 ){
      if (Ps3.data.analog.stick.rx > 70) {
        if (!right) Serial.println("right on");
        digitalWrite(LEFT, HIGH);
        right = true;
      }

      if (Ps3.data.analog.stick.rx < 60) {
        if (right) Serial.println("right off");
        digitalWrite(LEFT, LOW);
        right = false;
      }

      if (Ps3.data.analog.stick.rx < -70) {
        if (!left) Serial.println("left on");
        digitalWrite(RIGHT, HIGH);
        left = true;
      }
      
      if (Ps3.data.analog.stick.rx > -60) {
        if (left) Serial.println("left off");
        digitalWrite(RIGHT, LOW);
        left = false;
      }

      if (Ps3.data.analog.stick.ry > 70) {
        if (!bottom) Serial.println("bottom on");
        digitalWrite(UP, HIGH);
        bottom = true;
      }

      if (Ps3.data.analog.stick.ry < 60) {
        if (bottom) Serial.println("bottom off");
        digitalWrite(UP, LOW);
        bottom = false;
      }
  
      if (Ps3.data.analog.stick.ry < -70) {
        if (!top) Serial.println("top on");
        digitalWrite(BOTTOM, HIGH);
        top = true;
      }

      if (Ps3.data.analog.stick.ry > -60) {
        if (top) Serial.println("top off");
        digitalWrite(BOTTOM, LOW);
        top = false;
      }
    }
  } else {
    if( abs(Ps3.event.analog_changed.stick.lx) + abs(Ps3.event.analog_changed.stick.ly) > 2 ){
      if (Ps3.data.analog.stick.lx > 70) {
        if (!right) Serial.println("right on");
        digitalWrite(LEFT, HIGH);
        right = true;
      }

      if (Ps3.data.analog.stick.lx < 60) {
        if (right) Serial.println("right off");
        digitalWrite(LEFT, LOW);
        right = false;
      }

      if (Ps3.data.analog.stick.lx < -70) {
        if (!left) Serial.println("left on");
        digitalWrite(RIGHT, HIGH);
        left = true;
      }
      
      if (Ps3.data.analog.stick.lx > -60) {
        if (left) Serial.println("left off");
        digitalWrite(RIGHT, LOW);
        left = false;
      }

      if (Ps3.data.analog.stick.ly > 70) {
        if (!bottom) Serial.println("bottom on");
        digitalWrite(UP, HIGH);
        bottom = true;
      }

      if (Ps3.data.analog.stick.ly < 60) {
        if (bottom) Serial.println("bottom off");
        digitalWrite(UP, LOW);
        bottom = false;
      }
  
      if (Ps3.data.analog.stick.ly < -70) {
        if (!top) Serial.println("top on");
        digitalWrite(BOTTOM, HIGH);
        top = true;
      }

      if (Ps3.data.analog.stick.ly > -60) {
        if (top) Serial.println("top off");
        digitalWrite(BOTTOM, LOW);
        top = false;
      }
    }
  }
}

void setJoystick(byte x) {
  if (x & 1) {
    digitalWrite(LEFT, HIGH);
  } else {
    digitalWrite(LEFT, LOW);
  }

  if (x & 2) {
    digitalWrite(RIGHT, HIGH);
  } else {
    digitalWrite(RIGHT, LOW);
  }

  if (x & 4) {
    digitalWrite(34, HIGH);
  } else {
    digitalWrite(34, LOW);
  }

  if (x & 8) {
    digitalWrite(35, HIGH);
  } else {
    digitalWrite(35, LOW);
  }
}

void onConnect(){
    Serial.println("Connected.");
}

void loop(){
}
