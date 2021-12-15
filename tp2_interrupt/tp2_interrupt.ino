void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  pinMode (2, INPUT);
  pinMode(12,OUTPUT);
  attachInterrupt(INT0, turnOnLight, CHANGE);

}

volatile bool ledState = false; 

void loop() {
  // put your main code here, to run repeatedly:
Serial.print ("DEMAT BREIZH\n");
delay (2000);
digitalWrite (12,ledState);
}

void turnOnLight (void) {
  Serial.println ("interr");
ledState = !ledState;
  //digitalWrite (12, !digitalRead(12));

}
