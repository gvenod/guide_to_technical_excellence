#include <iostream>
#include <string>

using namespace std;

template <typename T>
T add(T a, T b) {
    return a + b;
}

template <typename T>
class MyClass {
public:
    MyClass(T value) : value_(value) {}

    T getValue() const {
        return value_;
    }

private:
    T value_;
};

template <typename T, typename U>
class Pair {
public:
    Pair(T first, U second) : first_(first), second_(second) {}

    void print() const {
        cout << "First: " << first_ << ", Second: " << second_ << endl;
    }

private:
    T first_;
    U second_;
};

int main() {
    cout << add<int>(2, 3) << endl;
    cout << add<double>(2.5, 3.5) << endl;
	
	MyClass<int> intObject(10);
    cout << intObject.getValue() << endl;

    MyClass<string> stringObject("Hello");
    cout << stringObject.getValue() << endl;
	
	
	Pair<int, double> pair1(10, 3.14);
    pair1.print();

    Pair<std::string, bool> pair2("Hello", true);
    pair2.print();
	
	
    return 0;
}