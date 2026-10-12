#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;
    int token;

    cout << "Enter 5 customer token numbers:" << endl;

    for (int i = 0; i < 5; i++)
    {
        cin >> token;
        q.push(token);
    }

    cout << "\nCustomers are served in the following order:" << endl;

    while (q.size() > 0)
    {
        cout << "Serving customer with token number: "
             << q.front() << endl;
        q.pop();
    }

    return 0;
}
