 const int burn=7;
 const int buzz_pin=4;
int max_alti=0;

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);


pinMode(buzz_pin,OUTPUT);

setupbmp();
 
pinMode(burn,OUTPUT);
digitalWrite(burn,HIGH);


/// BURNING TEST
/*digitalWrite(burn,HIGH); 
delay(1000);
digitalWrite(burn,  LOW); 
delay(900);
digitalWrite(burn,HIGH); 
delay(1000); 
*/


///BUZZER TEST
/*digitalWrite(buzz_pin,HIGH);
*/

  

}

void loop() {
  
 float temp=getTemp();
 float pressure=getPress();
 float alti=getAlti();

Serial.print("Altitude: "); Serial.println(alti);
int int_alti=(int) alti;
if(max_alti<int_alti) max_alti=int_alti;
Serial.print("MAX Altitude: "); Serial.println(max_alti);
if(int_alti==170 && max_alti-5>int_alti) ///condition to activate burning
  {
    digitalWrite(burn,LOW); 
    delay(850);
    digitalWrite(burn,HIGH);
  }
if(int_alti==170 && max_alti-5>int_alti) ///condition to activate buzzer
{
  digitalWrite(buzz_pin,HIGH);
}
}

///void loop(){} - for debugging purpose from setup
