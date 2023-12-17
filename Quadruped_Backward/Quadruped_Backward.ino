#include <avr/io.h>
#include <avr/interrupt.h>
#define clearbit(x, y) (x &= ~y)
#define setbit(x, y) (x |= y)
#define checkbit(x, y) ((x) & (y))
#define bitn(p) (0x01 << (p))
int count = 0;

int right_fore, count_angle, right_hind, count_angle1, 
left_fore, count_angle2, left_hind, count_angle3;
int main()
{
  DDRD = 0xFF;
  TCNT1 = 0x00;
  OCR1A = 21;
  TCCR1A = 0x00;
  TCCR1B = 0x0A;
  TIMSK1 = 0X02;
  SREG = 0x80;
  home_position();
  convert();
  while(1)
  {
    for (int i = 1; i <= 20; i++)
    {
      right_hind--;
      left_fore++;
      convert();
    }
    for (int i = 1; i <= 10; i++)
    {
      right_fore++;
      left_hind--;
      convert();
    }
    for (int i = 1; i <= 20; i++)
    {
      right_hind++;
      left_fore--;
      convert();
    }
    for (int i = 1; i <= 10; i++)
    {
      right_fore--;
      left_hind++;
      convert();
    }
    for (int i = 1; i <= 20; i++)
    {
      right_fore--;
      left_hind++;
      convert();
    }
    for (int i = 1; i <= 10; i++)
    {
      right_hind++;
      left_fore--;
      convert();
    }
    for (int i = 1; i <= 20; i++)
    {
      right_fore++;
      left_hind--;
      convert();
    }
    for (int i = 1; i <= 10; i++)
    {
      right_hind--;
      left_fore++;
      convert();
    }
  }
}
void convert()
{
  count_angle = right_fore + 46;
  count_angle1 = right_hind + 46;
  count_angle2 = left_fore + 46;
  count_angle3 = left_hind + 46;
  _delay_us(1200);
}
void home_position()
{
  right_fore = 90;
  right_hind = 90;
  left_fore = 90;
  left_hind = 90;
} 
ISR (TIMER1_COMPA_vect)
{
  count++;
  if (count <= count_angle)
  {
    setbit(PORTD, bitn(4));
  }
  else if ((count > count_angle) && (count < 1818))
  {
    clearbit(PORTD, bitn(4));
  }
  else if (count >= 1818)
  {
    count = 0;
  }
  if (count <= count_angle1)
  {
    setbit(PORTD, bitn(5));
  }
  else if (( count > count_angle1) && (count < 1818))
  {
    clearbit(PORTD, bitn(5));
  }
  if (count <= count_angle2)
  {
    setbit(PORTD, bitn(6));
  }
  else if ((count > count_angle2) && (count < 1818))
  {
    clearbit(PORTD, bitn(6));
  }
  if ( count <= count_angle3)
  {
    setbit(PORTD, bitn(7));
  }
  else if ((count > count_angle3) && (count < 1818))
  {
    clearbit(PORTD, bitn(7));
  }
}