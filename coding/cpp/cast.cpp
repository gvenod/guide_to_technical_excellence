
/*
Casting is a conversion process wherein data can be changed from one type to another. C++ has two types of conversions:

Implicit conversion: Conversions are performed automatically by the compiler without the programmer's intervention.
Explicit conversion: Conversions are performed only when explicitly specified by the programmer.

four types of casting operators.
- static_cast - tells the compiler to attempt to convert between two different data types.
- const_cast - changes the "const-ness" of the expression. It can make something const what was not const before, or it can make something volatile/changeable by getting rid of the const.
- reinterpret_cast - most powerful cast, the reinterpret_cast can convert from any built-in type to any other, and from any pointer type to another pointer type.
- dynamic_cast - used for handling polymorphism only 
*/

int iVariable = 20;
float fVariable = iVariable; //Assigning an int to a float will trigger a conversion.  
float fVariable2 = (float) iVariable / 10;

float fVariable3 = static_cast<float>(iVariable); /*converts iVariable which is of type int to float. */