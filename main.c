#include<stdio.h>

#define OUTPUT 1
#define INPUT 0
#define HIGH 1
#define LOW 0

unsigned char DDRB = 0b00000000;
unsigned char DDRC = 0b00000000;
unsigned char DDRD = 0b00000000;
unsigned char PORTB = 0b00000000;
unsigned char PORTC = 0b00000000;
unsigned char PORTD = 0b00000000;

void pinMode(char portname,int portnum, int flag){
  switch(portname){
    case 'B':
      DDRB ^= (-flag ^ DDRB) & (1UL << portnum);
    case 'C':
      DDRC = (DDRD & ~(1UL << portnum)) | (flag << portnum);
    case 'D':
      DDRD = (DDRD & ~(1UL << portnum)) | (flag << portnum);
  }
}

void digitalWrite(char portname, int portnum, int portstate){  //  HIGH/LOW
  switch(portname){
    case 'B':
      PORTB = (PORTB & ~(1UL << portnum)) | (portstate << portnum);
    case 'C':
      PORTC = (PORTC & ~(1UL << portnum)) | (portstate << portnum);
    case 'D':
      PORTD = (PORTD & ~(1UL << portnum)) | (portstate << portnum);
  } 
}

void pullup(char portname, int portnum)  
{
    digitalWrite(portname, portnum, 1);
}

int digitalRead(char portname, int portnum){
  switch(portname){  
    case 'B':
      if ((PORTB >> portnum) & 1U){return 1;}
      else {return 0;}
    case 'C':
      if ((PORTC >> portnum) & 1U){return 1;}
      else {return 0;}
    case 'D':
      if ((PORTD >> portnum) & 1U){return 1;}
      else {return 0;}
  }
}

int main(){
    digitalWrite('B',3, HIGH);
    printf("%d",PORTB);

    if (digitalRead('B', 3)){
      printf("\ntrue1");
      }

    digitalWrite('B',3, LOW);
    printf("\n%d",PORTB);

    pullup('D', 0);
    printf("\nD1: %d",digitalRead('D', 1));
    }

