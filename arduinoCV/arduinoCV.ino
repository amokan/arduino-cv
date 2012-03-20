// change the pwm duty cycle as needed (0-255)
int pwm = 0;
int timer = 20;

void setup()
{
  // set pin 11 to low-impedance state
  pinMode(11, OUTPUT);
  
  // set freq to 61.5 khz
  TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(CS20);
  
  OCR2A = pwm;
}

void loop()
{
  // loop the duty cycle from 0-255.
  for(int i = 0; i <= 255; i++) {
    pwm = i;
    OCR2A = pwm;
    delay(timer);
  }
}
