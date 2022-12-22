// Abstract Class
// If a class contains atleast one pure virtual function then the class is said to be an abstract class.
// Note: 
// 1. A derived class should override the virtual pure functions in the base class.
// 2. Not possible to create an object for an abstract class.
// 3. Creating Pointers is an exception.

class Shape {
    int length;
    int breadth;
    int height;

    public:
    Shape(int length, int breadth, int height) {
        this->length = length;
        this->breadth = breadth;
        this->height = height;
    }

    virtual int findArea() = 0; // pure virtual function
};