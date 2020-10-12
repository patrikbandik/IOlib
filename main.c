#include<stdio.h>

//void pinMode(unsigned char portname, int portnum, int flag);

unsigned char DDRB = 0b00000000;
void pinMode(char portname,int portnum, int flag){
  switch(portname){
    case 'B':
      DDRB ^= (flag ^ DDRB) & (1UL << portnum);
  }

}



int main(){
    /* int arr[] = {1, 2, 3};
    for(int i = 0; i <= 2; i++){
        printf("%d\t", arr[i]);
    }
    return 0; */

    unsigned char number = 0b00000000;
    unsigned long newbit = !!1;    // Also booleanize to force 0 or 1
    number ^= (-newbit ^ number) & (1 << 3);
    number ^= (-newbit ^ number) & (1UL << 0);
    number ^= (-newbit ^ number) & (1UL << 1);
    newbit = !!0;
    number ^= (-newbit ^ number) & (1UL << 0);
    number ^= (-newbit ^ number) & (1UL << 1);
    printf("%d\n",number);
    number = (number & ~(1UL << 3)) | (newbit << 3);
    printf("%d\n",number);

    pinMode('B',0, 1);
    printf("%d",DDRB);
    }

