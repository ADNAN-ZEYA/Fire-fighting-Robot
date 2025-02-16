void setup() {

// put your setup code here, to run once:

Serial.begin(9600); // Begins the Serial Communication with the Baud rate 9600.

pinMode (10, OUTPUT); // Sets the Pins 9, 10, 11, 12, 13 as OUTPUT Pins.
pinMode (11, OUTPUT);
pinMode (12, OUTPUT);
pinMode (13, OUTPUT);
pinMode (9, OUTPUT);

pinMode (A0, INPUT); // Sets the Analog Pins A0 A1 and A2 as Input Pins
pinMode (A1, INPUT);
pinMode (A2,INPUT);

}

void moveRobot(String motion) {

if (motion == "Forward") {// RW-Fwd (10 Pos, 11 Neg); LW-Fwd (12 Pos, 13-Neg)

digitalWrite(10, HIGH);
digitalWrite(11, LOW);
digitalWrite(12, HIGH);
digitalWrite(13, LOW);

Serial.println("Forward");
}


if (motion == "Backward") { 
digitalWrite(10,LOW);
digitalWrite(11, HIGH);
digitalWrite(12, LOW);
digitalWrite(13, HIGH);

Serial.println("Backward");

}

if (motion="Left"){ // RK-Fwd (10 Pos, 11-Neg); LW-Bck (12-Neg. 13-Pos)

digitalWrite(10, HIGH);

digitalWrite(11, LOW);

digitalWrite(12, LOW);

digitalWrite(13, HIGH);

Serial.println("Left");

}

if(motion == "Right") { // RW-Bck (10-Neg. 11-Pos); LWF-wd (12- Pos, 13-Neg)

digitalWrite(10, LOW);

digitalWrite(11, HIGH);

digitalWrite(12, HIGH);

digitalWrite(13, LOW);

Serial.println("Right");

}

if (motion == "Stop") {// RW-Stop (10-Neg, 11- Neg); LW-Stop (12- Neg. 13-Neg) 
digitalWrite(10, LOW);

digitalWrite(11, LOW);

digitalWrite(12, LOW);

digitalWrite(13, LOW);

Serial.println("Stop");

}

}

void loop(){

// put your main code here, to run repeatedly:

int Right = analogRead(0); 

int Middle = analogRead (A1);

int Left = analogRead (A2);

 if ((Left > 1000) && (Middle > 1000) && (Right > 1000)) {
 moveRobot ("Stop");
 }
 
 else{

if ((Left > Middle) && (Left > Right))

moveRobot ("Left");

delay(100);

moveRobot ("Stop");

delay(200);

}

if ((Right > Middle) && (Right > Left)) {

moveRobot ("Right");

delay(100);

moveRobot ("Stop");

delay(200);

}

if ((Middle > Right) && (Middle > Left) && (Middle < 600)){

moveRobot ("Forward");

delay(60);

moveRobot ("Stop");

delay (200);

}

if ((Middle > Right) && (Middle > Left) && (Middle < 600)) {

moveRobot ("Forward");

delay(60);

moveRobot ("Stop");

delay(200);

}

if ((Middle > Right) && (Middle > Left) && (Middle > 600)) {

moveRobot ("stop");

digitalWrite(9,HIGH);

delay(2000);

digitalWrite(9,LOW);

    }
  }
