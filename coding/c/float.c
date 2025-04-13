/*

In C, float values are stored using a 32-bit memory block following the IEEE-754 standard, which divides the bits into a sign bit, an 8-bit exponent, and a 23-bit mantissa (or significand)

Sign Bit (1 bit): Indicates whether the number is positive (0) or negative (1). 
Exponent (8 bits): Represents the power of 2, stored as an excess-127 value (meaning 127 is subtracted from the stored value to get the actual exponent). 
Mantissa (23 bits): Represents the significant digits of the number, with the leading '1' assumed to be present (except for special cases like zero and denormalized numbers

---- To convert an integral part into binary,  usual method. base 2 - dived by 2 and take remainder.
---- To convert the fractional part to binary, 
	multiply fractional part with 2 and take the one bit which appears before the decimal point. 
	Follow the same procedure with after the decimal point (.) part until it becomes 1.0.
Like,
0.25 * 2 =0.50 //take 0 and move 0.50 to next step
0.50 * 2 =1.00 //take 1 and stop the process because of 00 in fraction side.
0.25 = 01

In floating number storage, the computer will allocate 23 bits for the fractional part. So, it's enough to do the above method at max 23 times.

Combining both integral and fractional,

4.25 = 100.01
*/