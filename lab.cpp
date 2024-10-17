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
        cin >> a >> b >> h >> n;
        if ((a >= b and h >= 0) or (a <= b and h <= 0) or cin.fail())
        {
            cout << "Error uncorect data, please check value of variables " << endl;
            opt = 2;
        }
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

                cout << "Value of c : " << myText << endl;
                break;
            case 3:
                n = stod(myText);
                cout << "Value of d : " << myText << endl;
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