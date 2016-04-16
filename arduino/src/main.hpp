#ifndef __MAIN_H
#define __MAIN_H

#define STAR 0xFF42BD
#define HASH 0xFF52AD
#define KEY_1 0xFF6897
#define KEY_2 0xFF9867
#define KEY_3 0xFFB04F
#define KEY_4 0xFF30CF
#define KEY_5 0xFF18E7
#define KEY_6 0xFF7A85
#define KEY_7 0xFF10EF
#define KEY_8 0xFF38C7
#define KEY_9 0xFF5AA5
#define KEY_0 0xFF4Ab5

#define KEY_DOWN 0xFFA857
#define KEY_UP 0xFF629D
#define KEY_RIGHT 0xFFC23D
#define KEY_LEFT 0xFF22DD
#define KEY_OK 0xFF02FD

#define IR_REPEAT 0xFFFFFFFF

void ir_read();
void blink(int times);

#endif
