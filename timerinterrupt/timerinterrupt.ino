

const int FREQ = 8;
const int WARNING_PERIOD = 10000;
const int WARNING_SOUND = 1000;
const int SEVERE_PERIOD = 2500;
const int SEVERE_SOUND = 1250;
unsigned long intCounter = 0;
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
  DDRD |= B00000100;//port 2 - beeper
  DDRB |= B00001000;//port 11 - test beeper
  
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

}

void loop()
{

  //activate beeper
  toneWarning();
  //toneSevere();
  delay(10000);

  //deactivate beeper
  toneNone();
  delay(10000);
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
  interrupts();
}

/**
 * manager timer 1 interrupts - handle beeper
 */
ISR(TIMER1_COMPA_vect)          // timer compare interrupt service routine
{
  intCounter++;

  if (intCounter % tonePeriod < toneSound) {
    PORTD ^=  B00000100;
    PORTB ^=  B00001000;
  }

}


