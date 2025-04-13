#include <stdio.h>
#include <stdlib.h> //malloc

/*
In little-endian systems, the least significant byte (LSB) is stored at the lowest memory address, while in big-endian systems, the most significant byte (MSB) is stored at the lowest memory address
determine if the system architecture is little-endian or big-endian:

Consider the number 0x12345678.
In a little-endian system, the bytes would be stored in memory as 78 56 34 12 (LSB to MSB). 
In a big-endian system, the bytes would be stored in memory as 12 34 56 78 (MSB to LSB). 
*/

int check_endianess() {
    unsigned int num = 1;
    char *ptr = (char *)&num; //casting int into char to check where is 1. 

//examining the byte order of an integer. If the first byte of the integer is 1, it indicates a little-endian system; otherwise, it's a big-endian system. 
    if (*ptr == 1) {
        printf("Little-endian\n");
    } else {
        printf("Big-endian\n");
    }

    return 0;
}