#include <iostream>
#include <typeinfo>
#include <string.h>

using namespace std;

// Inheritance -> "is a" relationship
// Base Class
class Employee {
    private:
    string name;
    string position;
    int id;
    int age;
    double salary;

    public:
    Employee() {
    }

    Employee(int id, string name, double salary = 0) {
        // if('i'.compare(typeid(id).name())) {
        //     this->id = id;
        // }
        this->id = id;
        this->name = name;
        this->salary = salary;
    }

    void getInfo() {
        cout << this->name + ", whose id is " + to_string(this->id) + ", earning" + " " + to_string(this->salary) + " / month" << endl;
    }

    void setSalary(double salary) {
        this->salary = salary;
    }
};

// All  Contract Employee is an Employee, but all Employee is not Contract Employee
// ContractEmployee -> Derived Class
class ContractEmployee : protected Employee {
    int workHours;
    int incomePerHour = 200;

    public:
    ContractEmployee(int id, string name, int workHours)
    : Employee(id, name) {
        this->workHours = workHours;
        setSalary();
    }

    void setSalary() {
        Employee::setSalary(workHours * incomePerHour);
    }

    void getInfo() {
        Employee::getInfo();
    }
};

int main() {
    Employee roopesh(1, "Roopesh", 60000);
    ContractEmployee sachin(2, "Sachin", 8);
    roopesh.getInfo();
    sachin.getInfo();
    return 0;
}