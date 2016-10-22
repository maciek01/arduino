//Declaring Variables

unsigned long counter = 0;

//Setup routine
void setup(){

  // initialize digital pin 13 as an output.
  //pinMode(13, OUTPUT);
  DDRB |= B00110000;
  Serial.begin(9600); 
  
}

//Main program loop
void loop(){
  delay(250);
  counter++;
  print_signals();
}


void print_signals(){
  //Serial.print("Counter:");
  //Serial.println(counter);

  if (counter % 10 == 0) {
    //digitalWrite(13, HIGH);
    PORTB |= B00100000;
  }

  if (counter % 10 == 3) {
    //digitalWrite(13, LOW);
    PORTB &= B11011111;
  }
  
}



