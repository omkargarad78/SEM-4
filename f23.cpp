#include <iostream>
#include <fstream>
using namespace std;
//----------------------------------------------------------------------------

struct Student {                                                // Define the structure of the student record
int rollNo;
char name[50];
char division;
char address[100];
};
//---------------------------------------------------------------------------------------------------------------------------------

void addStudent() {                                             // Function to add a new student record to the file
ofstream outFile("students.dat", ios::app | ios::binary);       // Open the file in append mode

Student student;                                                // Get the details of the new student from the user
cout << "Enter Roll No: ";
cin >> student.rollNo;
cout << "Enter Name: ";
cin>>student.name;                                                 
cout << "Enter Division: ";
cin >> student.division;
cout << "Enter Address: ";
cin>>student.address;                                                


outFile.write((char*)&student, sizeof(Student));    // Write the new student record to the file
outFile.close();
}
//----------------------------------------------------------------------------------------------------------------------------------

void deleteStudent() {                                          // Function to delete a student record from the file

int rollNo;
cout << "Enter Roll No of the student to be deleted: ";
cin >> rollNo;

fstream file("students.dat", ios::in | ios::out | ios::binary);     // Open the file in read-write mode
Student student;                                                    // Search for the student record with the given roll number
bool found = false;
while (!file.eof()) {
    file.read(reinterpret_cast<char*>(&student), sizeof(Student));
    if (student.rollNo == rollNo) {
    found = true;
    break;
    }
}

if (found) {                                                                  // If the student record is found, delete it
    file.seekg(-static_cast<int>(sizeof(Student)), ios::cur);                   // Move the file pointer back by the size of one record
    student.rollNo = -1;                                                        // Mark the record as deleted by setting its roll number to -1
    file.write((char*)&student, sizeof(Student));                               // Write the modified record back to the file
    cout << "Student record deleted successfully.\n";
    }  
else {
    cout << "Student record not found.\n";
}

file.close();
}
//----------------------------------------------------------------------------------------------------------------------------------

void displayStudent() {                                                         // Function to display the details of a particular student
int rollNo;
cout << "Enter Roll No of the student to be displayed: ";
cin >> rollNo;

ifstream file("students.dat", ios::binary);                                     // Open the file in read mode

Student student;                                                                // Search for the student record with the given roll number
bool found = false;
while (!file.eof()) {
file.read((char*)&student, sizeof(Student));
if (student.rollNo == rollNo) {
    found = true;
    break;
    }
}

if (found && student.rollNo != -1) {                                             // If the student record is found, display its details
    cout << "Roll No: " << student.rollNo << endl;
    cout << "Name: " << student.name << endl;
    cout << "Division: " << student.division << endl;
    cout << "Address: " << student.address<<endl;
} 
else {
    cout << "Student record not found.\n";
}
file.close();
}

//----------------------------------------------------------------------------------------------------------------------------------
int main() {
    int choice;
    do {
    cout << "\nMenu:\n";
    cout << "1. Add a new student\n";
    cout << "2. Delete a student\n";
    cout << "3. Display a student's details\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            deleteStudent();
            break;
        case 3:
            displayStudent();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
            break;
        }
    } while (choice != 4);
return 0;
}
//----------------------------------------------------------------------------------------------------------------------------------