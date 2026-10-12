#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;
    int token;

    cout << "Enter 5 served customer token numbers:" << endl;

    for (int i = 0; i < 5; i++)
    {
        cin >> token;
        s.push(token);
    }

    cout << "\nService History (Most Recent First):" << endl;

    while (s.size() > 0)
    {
        cout << "Token Number: " << s.top() << endl;
        s.pop();
    }

    return 0;
}
