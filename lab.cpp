#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>
using namespace std;

int main()
{
    int n;
    double y, h, a, b;
    cout << "Set the way of input " << endl;
    cout << "If you want read from keyboard write 1 " << endl;
    cout << "If you want read from file write 2 " << endl;
    int opt;

    cin >> opt;
    if (opt == 1)
    {
        cout << "Set the a and b for range h for step and n"
             << endl;
        do
        {
            cout << "Enter values for a and b (a < b): ";
            cin >> a >> b;

            if (cin.fail() || a >= b)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Error: incorrect values, please ensure that a < b." << endl;
            }
        } while (a >= b || cin.fail());

        do
        {
            cout << "Enter value for h (must be positive ): ";
            cin >> h;

            if (cin.fail() || h <= 0)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Error: incorrect value for h, please enter a positive step." << endl;
            }
        } while (h <= 0 || cin.fail());

        do
        {
            cout << "Enter value for n (must more than 1 ): ";
            cin >> n;

            if (cin.fail() || n <= 1)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Error: incorrect value for n (n>1)." << endl;
            }
        } while (n <= 1 || cin.fail());
    }
    if (opt != 1)
    {
        string myText;
        ifstream MyReadFile("variables.txt");

        int var = 0;
        while (getline(MyReadFile, myText))
        {
            switch (var)
            {
            case 0:
                a = stod(myText);
                cout << "Value of a : " << myText << endl;
                break;
            case 1:
                b = stod(myText);
                cout << "Value of b : " << myText << endl;
                break;
            case 2:
                h = stod(myText);

                cout << "Value of h : " << myText << endl;
                break;
            case 3:
                n = stod(myText);
                cout << "Value of n : " << myText << endl;
                break;
            }

            var++;
        }
    }
    for (double x = a; x <= b; x += h)
    {
        cout << "Value of x is : " << x << ";" << endl;
        if (n > 1)
        {
            if (x < 0)
            {

                y = 0;
                int i = 0;
                for (int i = 0; i <= n; i++)
                {
                    y += (x + i) * (x + i) + 5 * x;
                }
            }
            else
            {
                y = 1;
                for (int i = 0; i <= n; i++)
                {
                    for (int j = 1; j <= n - 1; j++)
                    {
                        y *= (i + (x * x) / (i + j) - 3 * j);
                    }
                }
            }
            cout << "Value of y is : " << y << endl;
        }
        else
        {
            cout << "You cant find y " << endl;
        }
    }

    return 0;
}