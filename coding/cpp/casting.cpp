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

#include <iostream>

class Base {
public:
    virtual void display() {
        std::cout << "Base class display" << std::endl;
    }
    virtual ~Base() {}
};

class Derived : public Base {
public:
    void display() override {
        std::cout << "Derived class display" << std::endl;
    }
    void derivedFunction() {
        std::cout << "Derived class specific function" << std::endl;
    }
};

int main() {
    Base* basePtr = new Derived();
    
    // Attempting a downcast using dynamic_cast
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
    
    if (derivedPtr != nullptr) {
        // dynamic_cast successful, safe to use derivedPtr
        derivedPtr->display();
        derivedPtr->derivedFunction();
    } else {
        // dynamic_cast failed, basePtr does not point to a Derived object
        std::cout << "dynamic_cast failed: basePtr is not a Derived object" << std::endl;
    }
    
    // Example of a failed dynamic_cast
    Base* basePtr2 = new Base();
    Derived* derivedPtr2 = dynamic_cast<Derived*>(basePtr2);
    
    if (derivedPtr2 != nullptr) {
         derivedPtr2->display();
         derivedPtr2->derivedFunction();
    } else {
        std::cout << "dynamic_cast failed: basePtr2 is not a Derived object" << std::endl;
    }
    
    delete basePtr;
    delete basePtr2;
    
    return 0;
}