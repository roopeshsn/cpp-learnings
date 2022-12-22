#include <iostream>

using namespace std;

// Virtual Function -> used when pointers are required to access the object.
// It is a member function of a base class that is expected to be redefined or overridden in the derived class.
class Shape {
    protected:
    int length;
    int breadth;
    int height;

    public:
    Shape(int length, int breadth, int height) {
        this->length = length;
        this->breadth = breadth;
        this->height = height;
    }

    virtual int findArea() = 0;
};

class Rectangle : public Shape {
    public:
    Rectangle(int length, int breadth)
    : Shape(length, breadth, 0) {

    }

    int findArea() {
        return length * breadth;
    }
};

class Triangle : public Shape {
    int base;
    public:
    Triangle(int base, int height)
    : Shape(0 ,0, height) {
        this->base = base;
    }

    int findArea() {
        return (base * height) / 2;
    }
};


int main() {
    Shape *shapePtr;

    Rectangle rect(10, 10);
    shapePtr = &rect;
    cout << rect.findArea() << endl; // static or early binding (compile-time)
    cout << shapePtr->findArea() << endl; // dynamic or late binding (run-time)

    Triangle tria(10, 10);
    shapePtr = &tria;
    cout << shapePtr->findArea() << endl;
    return 0;
}