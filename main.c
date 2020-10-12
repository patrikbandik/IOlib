#include<stdio.h>

unsigned char DDRB = 0b00000000;
void pinMode(char portname,int portnum, int flag){
  switch(portname){
    case 'B':
      DDRB ^= (-flag ^ DDRB) & (1UL << portnum);
      //another way: DDRB = (DDRB & ~(1UL << portnum)) | (flag << portnum);
  }
}



int main(){
    pinMode('B',2, 0);
    printf("%d\n",DDRB);
    pinMode('B',3, 1);
    printf("%d\n",DDRB);
    }

