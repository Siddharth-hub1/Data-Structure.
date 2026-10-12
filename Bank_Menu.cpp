#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;
    int choice;
    int token = 1;

    do
    {
        cout << "\n===== BANK TOKEN SYSTEM =====" << endl;
        cout << "1. Issue a Token" << endl;
        cout << "2. Display All Tokens" << endl;
        cout << "3. Serve a Customer" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                q.push(token);
                cout << "Token issued successfully. Token Number: "
                     << token << endl;
                token++;
                break;

            case 2:
                if (q.size() > 0)
                {
                    queue<int> temp = q;

                    cout << "Waiting Customer Tokens: ";
                    while (temp.size() > 0)
                    {
                        cout << temp.front() << " ";
                        temp.pop();
                    }
                    cout << endl;
                }
                else
                {
                    cout << "No tokens available." << endl;
                }
                break;

            case 3:
                if (q.size() > 0)
                {
                    cout << "Serving customer with Token Number: "
                         << q.front() << endl;
                    q.pop();
                }
                else
                {
                    cout << "No customers waiting to be served." << endl;
                }
                break;

            case 4:
                cout << "Exiting Bank Token System. Thank you!" << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice < 4);

    return 0;
}
