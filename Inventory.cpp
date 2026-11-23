#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct Product
{
    int id;
    string name;
    float price;

    Product* next;       
    Product* hashNext;   
};

Product* head = NULL;

const int SIZE = 10;
Product* hashTable[SIZE] = {NULL};

int hashFunction(int id)
{
    return id % SIZE;
}

void addProduct()
{
    Product* p = new Product;

    cout << "Enter Product ID: ";
    cin >> p->id;

    int index = hashFunction(p->id);
    Product* temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->id == p->id)
        {
            cout << "Product ID already exists!\n";
            delete p;
            return;
        }

        temp = temp->hashNext;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Product Name: ";
    getline(cin, p->name);

    cout << "Enter Product Price: ";
    cin >> p->price;

    p->next = NULL;

    if (head == NULL)
    {
        head = p;
    }
    else
    {
        Product* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = p;
    }

    p->hashNext = hashTable[index];
    hashTable[index] = p;

    cout << "Product Added Successfully!\n";
}

void updatePrice()
{
    int id;

    cout << "Enter Product ID to update price: ";
    cin >> id;

    int index = hashFunction(id);

    Product* temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            cout << "Current Price: " << temp->price << endl;

            cout << "Enter New Price: ";
            cin >> temp->price;

            cout << "Product Price Updated Successfully!\n";
            return;
        }

        temp = temp->hashNext;
    }

    cout << "Product not found!\n";
}

void displayProducts()
{
    Product* temp = head;

    if (temp == NULL)
    {
        cout << "No Products Available.\n";
        return;
    }

    cout << "\n--- All Available Products ---\n";

    while (temp != NULL)
    {
        cout << "\nProduct ID: " << temp->id << endl;
        cout << "Product Name: " << temp->name << endl;
        cout << "Product Price: " << temp->price << endl;

        temp = temp->next;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n--- E-Commerce Product Catalog System ---\n";

        cout << "1. Add New Product\n";
        cout << "2. Update Product Price\n";
        cout << "3. Display All Products\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addProduct();
                break;

            case 2:
                updatePrice();
                break;

            case 3:
                displayProducts();
                break;

            case 4:
                cout << "Exiting Program...\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}