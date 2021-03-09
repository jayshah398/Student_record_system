//
//  main.cpp
//  Gradebook_struct
//
//  Created by Jay Shah on 2/23/21.
//
#include <iostream>
#include <struct.h>
#include <math.h>
#include <string>
#include <sstream>
#include <ctype.h>
#include <stdio.h>
#include <ostream>
using namespace std;


int r = 1;
int i = 1;

struct student
{
    string name;
    string lname;
    int roll;
    float math;
    float english;
    float science;
    float history;
    double average;
    string lettergrade;
} students [100];

int main()
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
                    break;
                }
                else
                {
                    x++;
                }
            }
            if ( us1 == username[x] && ps1 == password[x])
            {
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
    int n = 0;
    int choise = 1;

    while (choise < 5 & choise > 0)
    {
        cout << "1. Enter student information. \n";
        cout << "2. Display student information. \n";
        cout << "3. Delete student information. \n";
        cout << "4. Display Gradebook. \n";
        cout << "0. Quit.\n";
        cout << "Enter your choise number 0-4 below: \n";
        cin >> choise;
        if (choise == 1)
        {
            cout << "Enter number of new student in the class below:" << endl;
            cin >> n;
            for (int x = 1; x <= n; x++)
            {
                r++;
                students[n].roll = r;
                cout << "Enter student first name:\n";
                cin >> students[n].name;
                cout << "Enter student last name:\n";
                cin >> students[n].lname;
                cout << "Enter Math grade in number:\n";
                cin >> students[n].math;
                cout << "Enter English grade in number:\n";
                cin >> students[n].english;
                cout << "Enter Science grade in number:\n";
                cin >> students[n].science;
                cout << "Enter History grade in number:\n";
                cin >> students[n].history;
                
                double average = (((students[n].math + students[n].english + students[n].science + students[n].history)/400)*100);
                students[n].average = average;
                cout << average;
                
                if (students[n].average <= 100 && students[n].average >= 90)
                {
                    students[n].lettergrade = "A";
                    break;
                }
                else if (students[n].average <= 89 && students[n].average >= 85)
                {
                    students[n].lettergrade = "B+";
                    break;
                }
                else if (students[n].average <= 84 && students[n].average >= 78)
                {
                    students[n].lettergrade = "B";
                    break;
                }
                else if (students[n].average <= 77 && students[n].average >= 72)
                {
                    students[n].lettergrade = "C+";
                    break;
                }
                else if (students[n].average <= 71 && students[n].average >= 65)
                {
                    students[n].lettergrade = "C";
                    break;
                }
                else if (students[n].average <= 64 && students[n].average >= 58)
                {
                    students[n].lettergrade = "D";
                    break;
                }
                else if (students[n].average <= 58 && students[n].average >= 0)
                {
                    students[n].lettergrade = "F";
                    break;
                }
                else
                {
                    cout << "Grade must be out of 100 in every subject. \n";
                }
                
                cout << "Enter 1 to display letter grade else 0 to end:\n";
                int dis;
                cin >> dis;
                
                if (dis == 1)
                {
                    cout << "Letter grade:" << students[n].lettergrade << "\n" << endl;
                }
                
                else if (dis == 0)
                {
                    cout << "The End \n";
                }
                
                else
                {
                    cout << "Wrong Input \n";
                }
            }
        }
        
        if (choise == 2)
            {
                cout << "1. To search by roll number.\n";
                cout << "2. To seach by name. \n";
                cout << "Choose your desire search option.\n";
                int choise2;
                cin >> choise2;
                if (choise2 == 1)
                {
                    int rn;
                    cout << "Enter roll number:\n"<<endl;
                    cin >> rn;
                    cout << "Student name: " << students[rn].name << students[rn].lname <<"\n" << endl;
                    cout << "Math grade: " << students[rn].math << "\n" << endl;
                    cout << "English grade: " << students[rn].english << "\n" << endl;
                    cout << "Science grade: " << students[rn].science << "\n" << endl;
                    cout << "History grade: " << students[rn].history << "\n" << endl;
                    
                }
                else if (choise2 == 2)
                {
                    string sname;
                    cout << "Enter Student name:\n"<<endl;
                    cin >> sname;
                    int i;
                    for(i=1 ; i<=n ; i++)
                    {
                        if (sname == students[i].name || sname == students[i].lname)
                        {
                            break;
                        }
                    }
                    cout << "Student roll number: " << i << "\n" <<endl;
                    cout << "Math grade: " << students[i].math << "\n" <<  endl;
                    cout << "English grade: " << students[i].english << "\n" << endl;
                    cout << "Science grade: " << students[i].science << "\n" << endl;
                    cout << "History grade: " << students[i].history << "\n" << endl;
                }
            }
        
        if (choise == 3)
        {
            cout << "1. Delete by roll number.\n";
            cout << "2. To Delete by name. \n";
            cout << "Choose your desire search option.\n";
            int choise3;
            cin >> choise3;
            int roll;
            
            if (choise3 == 1)
            {
                cout << "Enter roll number: \n" << endl;
                cin >> roll;
                students[roll].math = -1;
                students[roll].english = -1;
                students[roll].science = -1;
                students[roll].history = -1;
                students[roll].name = " ";
                students[n].roll = 0;
                
            }
            else if (choise3 == 2)
            {
                string sdname;
                cout << "Enter Student name:\n"<<endl;
                cin >> sdname;
                int j;
                for (j = 1; j<=n; j++)
                {
                    if (sdname == students[j].name || sdname == students[j].lname) {
                        break;
                    }
                }
                students[j].math = -1;
                students[j].english = -1;
                students[j].science = -1;
                students[j].history = -1;
                students[j].name = " ";
                students[j].lname = " ";
                students[n].roll = 0;
            }
        }
        if (choise == 4)
        {
            int ns;
            cout << "Enter total number of students in your class:\n" << endl;
            cin >> ns;
            for (int x = 1; x <= n; x++)
            {
                if (students[x].roll == 0)
                {
                    cout << " "<< endl;
                }
                else
                {
                cout << "Roll number: "<< x << "\n" << endl;
                cout << "Name:\n" << students[ns].name << students[ns].lname << "\n" << endl;
                cout << "Math grade: " << students[ns].math << "\n" << endl;
                cout << "English grade: " << students[ns].english << "\n" << endl;
                cout << "Science grade: " << students[ns].science << "\n" << endl;
                cout << "History grade: " << students[ns].history << "\n" << endl;
                }
            }
        }
        else
        {
            cout << "Thank you for choosing!! \n" << endl;
        }
    }
    return 0;
}
