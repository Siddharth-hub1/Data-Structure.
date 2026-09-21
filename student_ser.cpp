#include <iostream>
using namespace std;

int main()
{
    int roll[5], searchRoll;
    bool found = false;

    cout << "Enter roll numbers of 5 students:\n";

    for (int i = 0; i < 5; i++)
    {
        cin >> roll[i];
    }

    cout << "Enter roll number to search: ";
    cin >> searchRoll;

    for (int i = 0; i < 5; i++)
    {
        if (roll[i] == searchRoll)
        {
            cout << "Student found\n";
            cout << "Student count: " << i + 1 << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Student not found" << endl;
    }

    return 0;
}
