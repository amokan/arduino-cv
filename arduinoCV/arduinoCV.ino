// change the pwm duty cycle as needed (0-255)
int pwm = 127;

void setup()
{
  // set pin 11 to low-impedance state
  pinMode(11, OUTPUT);
  
  // set freq to 61.5 khz
  TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(CS20);
  
  // duty cycle defined at the top of code
  OCR2A = pwm;
}

void loop()
{
  OCR2A = pwm;  
}
