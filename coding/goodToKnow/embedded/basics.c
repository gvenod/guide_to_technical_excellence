#include <stdio.h>
#include <stdlib.h> //malloc

#define REGISTER_ADDRESS 0x20002000


/*How do you set the value at memory address 0x20002000 to 0xDEADBEEF*/
void setValue() {
	//memory alignment; 32 bit arch, indianness  
	int ptr = 0x20002000;
	int val = 0xDEADBEEF;
	memset(ptr, 0xDEADBEEF, sizeof(uint32_t));

    volatile uint32_t *register_ptr = (volatile uint32_t *)REGISTER_ADDRESS;

    // Read the value from the register.
    uint32_t register_value = *register_ptr;
	
}

#define STACK_MAX 100
char stack[STACK_MAX];
int stackTop = -1;

int push(char val) {
	if(stackTop >= STACK_MAX) {
		return -1; //error
	} else {
		stack[++stackTop] = val;
		return 0;
	}
}

char pop() {
	if(stackTop != -1) {
		char val = stack[stackTop];
		stackTop--;
		return val;		
	}
	
	return '';
}

#define A_FLAG (1UL << 2)

void isBitSet(int val, int pos) {
	int flag = 1 << pos;
	if(val & flag) {
		printf("bit set\n");
	} else {
		printf("bit not set\n");
	}
}

void swap_nibble(int val) {//4 bits
	int out;
	/*
	printf("Before %lu\n", (unsigned long) uvalue);   // In decimal
    printf("Before 0x%lX\n", (unsigned long) uvalue); // In hexadecimal

    // Get first (most significant) and last (least significant) nibble.
    uint32_t first_nibble = uvalue >> (32-4);
    uint32_t last_nibble = uvalue & 0xF;

    // zero out the first and last nibble.
    uvalue &= 0x0FFFFFF0; 
    // Now "or" in the replacement nibbles.
    uvalue |= first_nibble;
    uvalue |= last_nibble << (32-4);
	*/
	printf("in = %d ; out = %d", val, out);
}


char* reverseString(char* inStr) {

	int len = strlen(inStr);
	int i = len - 1, pos = 0;
	char *pOutStr = (char*) malloc(len * sizeof(char));
	if(pOutStr == NULL) return NULL;
	
	printf("len = %d \n", len);
	for (; i >= 0; i--, pos++) {
		printf("pos = %d ", pos);
		printf(" char = %c\n", inStr[i]);
		pOutStr[pos] = inStr[i];
	}
	printf("pos = %d ", pos);
	pOutStr[pos] = '\0';
	
	return pOutStr;
}

void decimalToHex(int dec) {
	int val = dec;
	char hex[10];
	int pos = 0;
	while(val) {
		int rem = val % 16;
		if(rem < 10) {
			hex[pos++] = (char) (rem + '0');
		} else {
			hex[pos++] = (char) ((rem - 10) + 'A');
		}
		val = val /16;
	}
	hex[pos] = '\0';
	printf("%d hex %s \n", dec, hex);
	return;
}

void decimalToBinary(int dec) {
	int val = dec;
	char bin[50];
	int pos = 0;
	while(val) {
		int rem = val % 2;
		bin[pos++] = (char) (rem + '0');
		val = val /2;
	}
	//reverse 
	
	
	bin[pos] = '\0';
	
	
	
	printf("%d bin %s \n", dec, bin);
	return;
}

void countK(int val, int k) {
	int pos = 0;
	int count = 0;
	while(val) {
		int rem = val % 10;
		if(rem == k) {
			count++;
		}
		val = val /10;
	}
	printf("%d \n", count);
	return;
}

int main() {
	char inStr[] = "Hello";
	printf("inStr = %s \n", inStr);
	char* pOutStr = reverseString(inStr);	
	if(pOutStr) {
		printf("outStr %s \n", pOutStr);
		free (pOutStr);
	}
	
	decimalToHex(1000);
	
	decimalToBinary(4);
	decimalToBinary(5);
	
	countK(23252, 2);
	
	isBitSet(3, 1);
	isBitSet(4, 1);
	isBitSet(0, 5);
	
	return 0;
}