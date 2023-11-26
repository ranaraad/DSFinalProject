#include <iostream>
#include <string>
#include <cstdlib>
#include <regex>
using namespace std;
 
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
 
class Position {
public:
    string type[4] = {"Manager", "Inventory Manager", "Night Shift Employee", "Day Shift Employee"};
    int hours[4] = {90, 70, 63, 63};
    double hourlyRate[4] = {20.0, 15.0, 10.0, 10.0};  
 
    string choosePosition() {
        cout << "Choose the Employee's position:\n";
        for (int i = 0; i < 4; ++i) {
            cout << i + 1 << ". " << type[i] << endl;
        }
 
        int choice;
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        return type[choice - 1];
    }
};
 
class Employee {
private:
    string idEmp;
    string firstname;
    string lastname;
    int age;
    string email;
    Position position;
    double salary;
    int hours;
    string chosenPosition;
 
public:
    string getEmpId() { return idEmp; }
    string getFirstName() { return firstname; }
    string getLastName() { return lastname; }
    int getHours() { return hours; }
    int getAge() { return age; }
    string getEmail() { return email; }
    Position getPos() { return position; }
    double getSalary() { return salary; }
 
    string setEmpId(string id) { idEmp = id; }
    string setFirstName(string fn) { firstname=fn; }
    string setLastName(string ln) { lastname = ln ; }
    int setHours(int hrs) {  hours= hrs; }
    int setAge(int age) {  this->age=age; }
    string setEmail(string e) {  email=e; }
    Position setPos(Position pos) { position=pos; }
    double setSalary(double sal) { salary=sal; }
 
 
 
    bool isValidEmail(const string& email) {
        const regex pattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
        return regex_match(email, pattern);
    }
 
    Employee(string id, string fn, string ln, int a, string e, Position pos, double sal, int hrs)
        : idEmp(id), firstname(fn), lastname(ln), age(a), email(e), position(pos), salary(sal), hours(hrs) {}
 
    Employee()
        : idEmp(""), firstname(""), lastname(""), age(0), email(""), position(Position()), salary(0.0), hours(0) {}
 
    void generateId() {
        idEmp = firstname.substr(0, 1) + lastname.substr(0, 1) + to_string(age) +
                to_string(rand() % 10) + to_string(rand() % 10);
        cout << "Your Generated id is: " << idEmp << endl;
    }
 
    void enterDetails() {
        cout << "Enter First Name: ";
        cin >> firstname;
        cout << "Enter Last Name: ";
        cin >> lastname;
        cout << "Enter Age: ";
        cin >> age;
        do {
            cout << "Enter Email: ";
            cin >> email;
 
            if (!isValidEmail(email)) {
                cout << "Invalid email format. Please enter a valid email address." << endl;
            }
        } while (!isValidEmail(email));
 
        generateId();
 
        chosenPosition = position.choosePosition();
        int index = -1;
 
        for (int i = 0; i < 4; ++i) {
            if (chosenPosition == position.type[i]) {
                index = i;
                break;
            }
        }
 
        if (index != -1) {
            hours = position.hours[index];
        } else {
            cout << "Invalid position selected." << endl;
            hours = 0;
        }
 
        cout << endl;
    }
 
    double calculateSalary() {
        int index = -1;
        for (int i = 0; i < 4; ++i) {
            if (chosenPosition == position.type[i]) {
                index = i;
                break;
            }
        }
 
        if (index != -1) {
            return hours * position.hourlyRate[index];
        } else {
            cout << "Invalid position for salary calculation." << endl;
            return 0.0;
        }
    }
};

 
int main() {
    Employee employee;
 
    employee.enterDetails();
 
    return 0;
}
 
#endif // EMPLOYEE_H