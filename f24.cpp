#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//----------------------------------------------------------------------------------------------------------------------------------
struct Employee {
int id;
string name;
string designation;
double salary;
};
//----------------------------------------------------------------------------------------------------------------------------------

void add_employee() {

ofstream outfile("employees.txt", ios::app);

Employee employee;
cout << "Enter employee details: ";
cout << "ID: ";
cin >> employee.id;
cout << "Name: ";
cin>>employee.name;
cout << "Designation: ";
cin>>employee.designation;
cout << "Salary: ";
cin >> employee.salary;

outfile.write((char *)&employee, sizeof(employee));
outfile.close();
}
//----------------------------------------------------------------------------------------------------------------------------------

void delete_employee() {
int id;
cout << "Enter the ID of the employee to delete: ";
cin >> id;
Employee employee;
ifstream infile("employees.txt");
ofstream outfile("temp.txt");

while (infile.read((char *)&employee, sizeof(employee))) {
if (employee.id != id) {
    outfile.write((char *)&employee, sizeof(employee));
}
}

infile.close();
outfile.close();
remove("employees.txt");
rename("temp.txt", "employees.txt");
}
//----------------------------------------------------------------------------------------------------------------------------------

void display_employee() {
int id;
cout << "Enter the ID of the employee to display: ";
cin >> id;

Employee employee;
bool found = false;
ifstream infile("employees.txt");
while (infile.read((char *)&employee, sizeof(employee))) {
if (employee.id == id) {

cout << "Employee details: " << endl;
cout << "ID: " << employee.id << endl;
cout << "Name: " << employee.name << endl;
cout << "Designation: " << employee.designation << endl;
cout << "Salary: " << employee.salary << endl;
found = true;
break;
}
}
infile.close();
if (!found) {
cout << "Employee not found!" << endl;
}
}
//----------------------------------------------------------------------------------------------------------------------------------
int main() {
int choice;
do {
cout << "1. Add employee" << endl;
cout << "2. Delete employee" << endl;
cout << "3. Display employee" << endl;
cout << "4. Exit" << endl;
cout << "Enter your choice: ";
cin >> choice;
switch (choice) {
    case 1:
        add_employee();
        break;
    case 2:
        delete_employee();
        break;
    case 3:
        display_employee();
        break;
    case 4:
        cout<<"Existing";
    default:
        cout << "Invalid choice!" << endl;
}
} while (choice != 4);
return 0;
}
