purpose:

 1. know/refresh existing data structures in cpp
	array, vector, list, set, map, tree, graph
 2. know the basic syntax, logics, loops for faster coding
 3. know when to use what
 4. know the Big O for each data structure.
    retrieve/insert/delete:
	array/stack/queue O(1) - index based
	list O(n) - go through entire list
	map/set O(1+hash calculation time which is again constant) - uses hash for indexing;
    search:
	array/list O(n) - go through entire list
	stack/queue - not applicable
	map/set O(1+hash calculation time which is again constant) - uses hash for indexing;		



C++
 - operator overloading
 - static polymorphism
 - dynamic polymorphism
 - abstraction - class - private
 - encapsulation
 - pointers
 - Abstraction - Abstraction is the process of showing the essential details to the user and hiding the details which we don’t want to show to the user or hiding the details which are irrelevant to a particular user.
Encapsulation
Inheritance
Polymorphism
Association, Aggregation, Composition
Class
Object
Method
Friend functions are not member functions.
friend class can access private, protected, and public members of other classes in which it is declared as friends

https://www.geeksforgeeks.org/solid-principle-in-programming-understand-with-real-life-examples/

principles:
SOLID

Single Responsibility Principle (SRP) - one purpose/responsibility -- class definition
Open/Closed Principle - open for extension & closed for modification. -- inherit for new features.....
Liskov’s Substitution Principle (LSP) - child class should be usable in place of its parent without any unexpected behavior
Interface Segregation Principle (ISP) - do not force any client to implement an interface which is irrelevant to them
Dependency Inversion Principle (DIP) - High-level modules should not depend on low-level modules. Both should depend on abstractions
