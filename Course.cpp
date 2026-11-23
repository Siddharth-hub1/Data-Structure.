#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct Student
{
    int rollNo;
    string name;
    int age;
    string course;

    Student* next;       
    Student* hashNext;   
};

Student* head = NULL;

const int SIZE = 10;
Student* hashTable[SIZE] = {NULL};

int hashFunction(int rollNo)
{
    return rollNo % SIZE;
}

void addRegistration()
{
    Student* s = new Student;

    cout << "Enter Roll Number: ";
    cin >> s->rollNo;

    int index = hashFunction(s->rollNo);
    Student* temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->rollNo == s->rollNo)
        {
            cout << "Roll Number already exists!\n";
            delete s;
            return;
        }

        temp = temp->hashNext;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Student Name: ";
    getline(cin, s->name);

    cout << "Enter Age: ";
    cin >> s->age;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Course Name: ";
    getline(cin, s->course);

    s->next = NULL;

    if (head == NULL)
    {
        head = s;
    }
    else
    {
        Student* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = s;
    }

    s->hashNext = hashTable[index];
    hashTable[index] = s;

    cout << "Student Registered Successfully!\n";
}

void updateStudent()
{
    int rollNo;

    cout << "Enter Roll Number to update: ";
    cin >> rollNo;

    int index = hashFunction(rollNo);

    Student* temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->rollNo == rollNo)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter New Student Name: ";
            getline(cin, temp->name);

            cout << "Enter New Age: ";
            cin >> temp->age;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter New Course Name: ";
            getline(cin, temp->course);

            cout << "Student Information Updated Successfully!\n";
            return;
        }

        temp = temp->hashNext;
    }

    cout << "Student not found!\n";
}

void withdrawStudent()
{
    int rollNo;

    cout << "Enter Roll Number to withdraw: ";
    cin >> rollNo;

    int index = hashFunction(rollNo);

    Student* temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->rollNo == rollNo)
        {
            if (temp->course == "Not Enrolled")
            {
                cout << "Student is not enrolled in any course!\n";
                return;
            }

            temp->course = "Not Enrolled";

            cout << "Student Withdrawn from Course Successfully!\n";
            return;
        }

        temp = temp->hashNext;
    }

    cout << "Student not found!\n";
}

void displayStudents()
{
    Student* temp = head;

    if (temp == NULL)
    {
        cout << "No Student Records Available.\n";
        return;
    }

    cout << "\n--- All Student Records ---\n";

    while (temp != NULL)
    {
        cout << "\nRoll Number: " << temp->rollNo << endl;
        cout << "Student Name: " << temp->name << endl;
        cout << "Age: " << temp->age << endl;
        cout << "Course: " << temp->course << endl;

        temp = temp->next;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n--- University Student Registration System ---\n";

        cout << "1. Add Student Registration\n";
        cout << "2. Withdraw Student from Course\n";
        cout << "3. Display All Students\n";
        cout << "4. Update Student Information\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addRegistration();
                break;

            case 2:
                withdrawStudent();
                break;

            case 3:
                displayStudents();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                cout << "Exiting Program...\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}