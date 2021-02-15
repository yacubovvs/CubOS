#define byte unsigned char
#define boolean bool
#define PROGMEM /**/
#define pgm_read_byte *

#define max MAX
#define min MIN

#define MAX(X,Y) 
#define MIN(X,Y) ( ((X) < (Y)) ? (X) : (Y) )

#include <stdio.h>
#include "WString.h"

unsigned long millis(){
    return clock()/4;
}

int max(int a, int b){
    return ((a>b)?a:b);
}

int min(int a, int b){
    return ((a<b)?a:b);
}

unsigned char max(unsigned char a, unsigned char b){
    return ((a>b)?a:b);
}

unsigned char min(unsigned char a, unsigned char b){
    return ((a<b)?a:b);
}

// PREDEFINED