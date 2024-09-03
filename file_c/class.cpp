#include <iostream>
using namespace std;

class A {
public:
    virtual void sayHello() {
        cout << "Hello from A" << endl;
    }
};

class B : public A {
public:
    void sayHello() {
        cout << "Hello from B" << endl;
    }
};

class C : public A {
public:
    void sayHello() {
        cout << "Hello from C" << endl;
    }
};

int main() {
    A* ptr;

    B b;
    ptr = &b;
    ptr->sayHello();  // Output: Hello from A

    C c;
    ptr = &c;
    ptr->sayHello();  // Output: Hello from A

    return 0;
}
