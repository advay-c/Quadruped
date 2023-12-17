# Quadruped
Walking quadruped robot using arduino nano + 4 servo motors 


# Installation

1. Install [Arduino IDE 2.2.1](https://www.arduino.cc/en/software)
2. Install the [MightyCore](https://github.com/MCUdude/MightyCore) arduino library
3. Open the .ino file into the **Arduino IDE**
4. Select the [board and port](https://support.arduino.cc/hc/en-us/articles/4406856349970-Select-board-and-port-in-Arduino-IDE) (Arduino Nano)

# Functions

  **Convert**

  ```c++
  void convert()
{
  count_angle = right_fore + 46;
  count_angle1 = right_hind + 46;
  count_angle2 = left_fore + 46;
  count_angle3 = left_hind + 46;
  _delay_us(1200);
}
```

  **Home Position**

  ```c++
  void home_position()
{
  right_fore = 90;
  right_hind = 90;
  left_fore = 90;
  left_hind = 90;
} 
  ```

  **Timer**

  ```c++
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
  ```
