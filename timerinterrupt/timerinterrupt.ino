

const int FREQ = 8;
const int WARNING_PERIOD = 10000;
const int WARNING_SOUND = 1000;
const int SEVERE_PERIOD = 2500;
const int SEVERE_SOUND = 1250;
volatile unsigned long intCounter = 0;
unsigned int tonePeriod = WARNING_PERIOD;
unsigned int toneSound = WARNING_SOUND;

boolean beeperActive = false;

void setup()
{

  beeperSetup();

}


/**
 * setup the timer registers
 */
void beeperSetup() {
  DDRB |= B00101000;//port 11 and 13 - test beeper

  // initialize timer1 
  noInterrupts();           // disable all interrupts
  
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;

  //OCR1A = 31250;            // compare match register 16MHz/256/2Hz
  OCR1A = FREQ;            // compare match register 16MHz/256/FRQHz
  
  TCCR1B |= (1 << WGM12);   // CTC mode
  TCCR1B |= (1 << CS12);    // 256 prescaler 

  
  //TIMSK1 |= (1 << OCIE1A);  // enable timer compare interrupt
  interrupts();             // enable all interrupts



  Serial.begin(57600); 

}

void loop()
{

  //activate beeper
  toneWarning();
  //toneSevere();


  unsigned long start = millis();
  
  while (millis() - start < 10000) {
    Serial.print("TONE: ");
    Serial.println(PORTB);  
  }

  //deactivate beeper
  toneNone();


  start = millis();

  while (millis() - start < 10000) {
    Serial.print("NO TONE: ");
    Serial.println(PORTB);  
  }
  

}


/**
 * turn warning on
 */
void toneWarning() {
  noInterrupts();
  tonePeriod = WARNING_PERIOD;
  toneSound = WARNING_SOUND; 
  TIMSK1 |= (1 << OCIE1A); 
  beeperActive = true;
  PORTB ^=  B00101000;
  interrupts();
}

/**
 * turn severe on
 */
void toneSevere() {
  noInterrupts();
  tonePeriod = SEVERE_PERIOD;
  toneSound = SEVERE_SOUND;
  TIMSK1 |= (1 << OCIE1A);  
  beeperActive = true;
  PORTB ^=  B00101000;
  interrupts();
}


/**
 * stop beeper
 */
void toneNone() {
  noInterrupts();
  TIMSK1 &= ~(1 << OCIE1A);
  intCounter = 0;
  beeperActive = false;
  PORTB &=  B11010111;
  interrupts();
}

/**
 * manager timer 1 interrupts - handle beeper
 */
ISR(TIMER1_COMPA_vect)          // timer compare interrupt service routine
{
  intCounter++;

  if (intCounter % tonePeriod < toneSound) {
    PORTB ^=  B00101000;//13 and 11
    //PORTB ^=  B00100000;//13 only
  }

}


