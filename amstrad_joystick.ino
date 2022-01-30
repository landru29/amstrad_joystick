#include <Ps3Controller.h>

bool bottom;
bool top;
bool left;
bool right;

void setup() {
    Serial.begin(115200);

    Ps3.attach(notify);
    Ps3.attachOnConnect(onConnect);
    Ps3.begin();
    
    String address = Ps3.getAddress();

    Serial.print("The ESP32's Bluetooth MAC address is: ");
    Serial.println(address);
}

void notify()
{
    //--- Digital cross/square/triangle/circle button events ---
    if( Ps3.event.button_down.cross ) {
        Serial.println("Started pressing the cross button");
    }
    if( Ps3.event.button_up.cross ) {
        Serial.println("Released the cross button");
    }


    //---------------- Analog stick value events ---------------
   if( abs(Ps3.event.analog_changed.stick.lx) + abs(Ps3.event.analog_changed.stick.ly) > 2 ){

         if ((!right) && (Ps3.data.analog.stick.lx > 70)) {
             Serial.println("right on");
             right = true;
         }
  
         if ((right) && (Ps3.data.analog.stick.lx < 60)) {
             Serial.println("right off");
             right = false;
         }

         if ((!left) && (Ps3.data.analog.stick.lx < -70)) {
             Serial.println("left on");
             left = true;
         }
         
         if ((left) && (Ps3.data.analog.stick.lx > -60)) {
             Serial.println("left off");
             left = false;
         }

         if ((!bottom) && (Ps3.data.analog.stick.ly > 70)) {
             Serial.println("bottom on");
             bottom = true;
         }

         if ((bottom) && (Ps3.data.analog.stick.ly < 60)) {
             Serial.println("bottom off");
             bottom = false;
         }
     
         if ((!top) && (Ps3.data.analog.stick.ly < -70)) {
             Serial.println("top on");
             top = true;
         }

         if ((top) && (Ps3.data.analog.stick.ly > -60)) {
             Serial.println("top off");
             top = false;
         }
       

    }

}

void onConnect(){
    Serial.println("Connected.");
}

void loop(){
}
