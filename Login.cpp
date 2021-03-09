//
//  main.cpp
//  experiment
//
//  Created by Jay Shah on 1/26/21.
//

#include <iostream>
#include <string.h>

using namespace std;

int i = 1;

int main ()
{
    string username[100], password[100];
    string us, ps, us1, ps1;
    int signi;
    int sign = 0;
    while (sign < 5)
    {
        cout << "---------Welcome to Student Record!------------\n";
        cout << "Enter (1 to sign-in) / (0 to sign up).\n";
        cin >> signi;
        if (signi == 0)
        {
            cout << "Username\n";
            cin >> us;
            username[i] = us;
            cout << "Password\n";
            cin >> ps;
            password[i] = ps;
            i++;
        }
        
        else if (signi == 1)
        {
            cout << "Username\n";
            cin >> us1;
            cout << "Password\n";
            cin >> ps1;
            int x = 0;
            while (x <= i)
            {
                if ( us1 == username[x] && ps1 == password[x])
                {
                    cout << "Good so far!!!!";
                    break;
                }
                else
                {
                    x++;
                }
            }
            if ( us1 == username[x] && ps1 == password[x])
            {
                cout << "yesss";
                break;
            }
            else
            {
                cout << "Incorrect username or password! \n Try again or sign up. \n";
            }
        }
        else
        {
            cout << "Enter 0/1 to process.\n";
        }

    }
    return 0;
}
