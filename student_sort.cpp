#include <iostream>
using namespace std;

int main() {
    int marks[5];

    // Input marks
    cout << "Enter marks of 5 students:\n";
    for (int i = 0; i < 5; i++) {
        cout << "Student " << i + 1 << ": ";
        cin >> marks[i];
    }

    // Sort in descending order
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (marks[i] < marks[j]) {
                int temp = marks[i];
                marks[i] = marks[j];
                marks[j] = temp;
            }
        }
    }

    // Display marks
    cout << "\nMarks from highest to lowest:\n";
    for (int i = 0; i < 5; i++) {
        cout << marks[i] << endl;
    }

    return 0;
}

