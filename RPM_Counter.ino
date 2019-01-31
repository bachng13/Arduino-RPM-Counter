int pins[2][4]={
  {0,0,0,0},
  {0,0,0,0}
};
volatile int rpmcount = 2;
volatile int rpmcount2= 3;
int rpm = 0;
int count = 0;
int dir=5;//direction indicator
unsigned long lastmillis = 0;

void setup(){
 Serial.begin(9600); 
 pinMode(13, OUTPUT);
 pinMode(12, OUTPUT);
 pinMode(11, OUTPUT);
 pinMode(10, OUTPUT);
 pinMode(9, OUTPUT);
 pinMode(8, OUTPUT);
 pinMode(7, OUTPUT);
 pinMode(6, OUTPUT);
 pinMode(5,OUTPUT);
 attachInterrupt(digitalPinToInterrupt(3),rpm1, FALLING);//interrupt digital pin 1 is on pin 3
 attachInterrupt(digitalPinToInterrupt(2),rpm1, FALLING);//interrupt (0) is on pin (2).
}

int Display2() {
  digitalWrite(13, pins[0][0]);
  digitalWrite(12, pins[0][1]);
  digitalWrite(11, pins[0][2]);
  digitalWrite(10, pins[0][3]);
};

int Display1() {
  digitalWrite(9, pins[1][0]);
  digitalWrite(8, pins[1][1]);
  digitalWrite(7, pins[1][2]);
  digitalWrite(6, pins[1][3]);
};
void loop(){
 int sensor1 = digitalRead(2);
 int sensor2 = digitalRead(3);
 if (sensor1 == HIGH && sensor2 == LOW){
  digitalWrite(dir,HIGH);
 }
 if( sensor1 == LOW && sensor2 == HIGH ){
  digitalWrite(dir,LOW);
 }
 if (millis() - lastmillis == 2000){  /*Uptade every one second, this will be equal to reading frecuency (Hz).*/
 
 detachInterrupt(digitalPinToInterrupt(2));    //Disable interrupt 1 when calculating
 detachInterrupt(digitalPinToInterrupt(3));    //Disable interrupt 2 when calculating

// rpm = map(rpmcount,0,12,0,99);
 rpm = rpmcount * 30 /16;
 int digits[] = {rpm / 10, rpm % 10};
 
 Serial.print("RPM =\t"); //print the word "RPM" and tab.
 Serial.print(rpm); // print the rpm value.
 Serial.print("\t Hz=\t"); //print the word "Hz".
 Serial.println(rpmcount); /*print revolutions per second or Hz. And print new line or enter.*/
 switch (digits[0]) {
      case 0:
        pins[0][0]=0; pins[0][1]=0; pins[0][2]=0; pins[0][3]=0;
        Display2();
        break;
      case 1:
        pins[0][0]=0; pins[0][1]=0; pins[0][2]=0; pins[0][3]=1;
        Display2();
        break;
      case 2:
        pins[0][0]=0; pins[0][1]=0; pins[0][2]=1; pins[0][3]=0;
        Display2();
        break;
      case 3:
        pins[0][0]=0; pins[0][1]=0; pins[0][2]=1; pins[0][3]=1;
        Display2();
        break;
      case 4:
        pins[0][0]=0; pins[0][1]=1; pins[0][2]=0; pins[0][3]=0;
        Display2();
        break;
      case 5:
        pins[0][0]=0; pins[0][1]=1; pins[0][2]=0; pins[0][3]=1;
        Display2();
        break;
      case 6:
        pins[0][0]=0; pins[0][1]=1; pins[0][2]=1; pins[0][3]=0;
        Display2();
        break;
      case 7:
        pins[0][0]=0; pins[0][1]=1; pins[0][2]=1; pins[0][3]=1;
        Display2();
        break;
      case 8:
        pins[0][0]=1; pins[0][1]=0; pins[0][2]=0; pins[0][3]=0;
        Display2();
        break;
      case 9:
        pins[0][0]=1; pins[0][1]=0; pins[0][2]=0; pins[0][3]=1;
        Display2();
        break;
    }
    switch (digits[1]) {
      case 0:
        pins[1][0]=0; pins[1][1]=0; pins[1][2]=0; pins[1][3]=0;
        Display1();
        break;
      case 1:
        pins[1][0]=0; pins[1][1]=0; pins[1][2]=0; pins[1][3]=1;
        Display1();
        break;
      case 2:
        pins[1][0]=0; pins[1][1]=0; pins[1][2]=1; pins[1][3]=0;
        Display1();
        break;
      case 3:
        pins[1][0]=0; pins[1][1]=0; pins[1][2]=1; pins[1][3]=1;
        Display1();
        break;
      case 4:
        pins[1][0]=0; pins[1][1]=1; pins[1][2]=0; pins[1][3]=0;
        Display1();
        break;
      case 5:
        pins[1][0]=0; pins[1][1]=1; pins[1][2]=0; pins[1][3]=1;
        Display1();
        break;
      case 6:
        pins[1][0]=0; pins[1][1]=1; pins[1][2]=1; pins[1][3]=0;
        Display1();
        break;
      case 7:
        pins[1][0]=0; pins[1][1]=1; pins[1][2]=1; pins[1][3]=1;
        Display1();
        break;
      case 8:
        pins[1][0]=1; pins[1][1]=0; pins[1][2]=0; pins[1][3]=0;
        Display1();
        break;
      case 9:
        pins[1][0]=1; pins[1][1]=0; pins[1][2]=0; pins[1][3]=1;
        Display1();
        break;
    }
    
 rpmcount = 0; // Restart the RPM counter
 lastmillis = millis();
 attachInterrupt(digitalPinToInterrupt(2),rpm1, FALLING); //enable interrupt
 attachInterrupt(digitalPinToInterrupt(3),rpm1, FALLING);//enable interrupt 2
 }
}


void rpm1(){
  rpmcount2++;
  rpmcount++;
}
