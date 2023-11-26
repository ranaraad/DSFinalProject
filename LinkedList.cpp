#include "Employee.h"
#include <stdio.h>
using namespace std;
class Node{ 
public:

Employee employee;
Node* next;

};

class LinkedList {
private:
    Node* head;
};

public: 
LinkedList(){
    head = NULL;
}

void addEmployee (Employee emp){
    Node *newemp = new Node ();
    Node *current = head;

    if (head == NULL) 
        head = newemp; 
    else{
    while(current->next != NULL){
        current = current->next;
    }
    current->next = newemp;
    }
}

void deleteEmployee (String id){

    if (head == NULL){
    cout << "Employee's list is empty.";
    return;
    }

    Node* current = head;
    Node* prev = NULL;

    if (head->next == NULL){
        if (head->employee.getId() == id){
            head = NULL;
        }
        cout << "Employee not found";
        return;
    }
    
    while (current != NULL && current->employee.getId() != id) {
        prev = current;
        current = current->next;
    }
    if (current == NULL){
        cout << "Employee not found";
        return;
    }
    prev->next = current->next;

    cout << "Employee with ID " << id << " deleted successfully." << endl;
    }

    void displayEmpList() {

        if (head == NULL) {
            cout << "Employee's list is empty." << endl;
            return;
        }
         
    Node* current = head;

    while (current != NULL) {
        int counter = 1;
        cout << "Employee " << counter << "information: " << endl;
        cout << "ID: " << current->employee.getEmpId() << endl;
        cout << "Name: " << current->employee.getFirstName() << " " << current->employee.getLastName() << endl;
        cout << "Age: " << current->employee.getAge() << endl;
        cout << "Email: " << current->employee.getEmail() << endl;
        cout << "Position: " << current->employee.getPos().choosePosition() << endl;
        cout << "Hours: " << current->employee.getHours() << endl;
        cout << "Salary: $" << current->employee.calculateSalary() << endl;

        current = current->next;
        counter++;
    }
}

void modifyEmp (){

}

