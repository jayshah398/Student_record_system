//
//  main.cpp
//  Filecreation
//
//  Created by Jay Shah on 3/11/21.
//

#include <iostream>
#include <struct.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <fstream>
#include <cstdlib>
using namespace std;
using std::fstream;
using std::ofstream;
using std::ifstream;


class Studentrecord
{
private:
    char firstname[100];
    char lastname[100];
    int rollnumber;
    float mathgrade;
    float englishgrade;
    float sciencegrade;
    float historygrade;
    double averagegrade;
    char lettergrade;
public:
    void read_data();
    void show_data();
    void write_data();
    void read_rec();
    void search_data();
    void edit_data();
    void delete_data();
};
void Studentrecord::read_data()
{
    cout << "Enter Roll Number: \n";
    cin >> rollnumber;
    cout << "Enter Firstname: \n";
    cin >> firstname;
    cout << "Enter Lastname: \n";
    cin >> lastname;
    cout << "Math Grade: \n";
    cin >> mathgrade;
    cout << "English Grade: \n";
    cin >> englishgrade;
    cout << "Science Grade: \n";
    cin >> sciencegrade;
    cout << "History Grade: \n";
    cin >> historygrade;
    cout << "Average Grade: \n";
    cin >> averagegrade;
    cout << "Letter Grade : \n";
    cin >> lettergrade;
    cout << endl;
}
void Studentrecord::show_data()
{
    cout << "Roll number: " << rollnumber << endl;
    cout << "First Name: " << firstname << endl;
    cout << "Last Name: " << lastname << endl;
    cout << "Math Grade: " << mathgrade << endl;
    cout << "English Grade: " << englishgrade << endl;
    cout << "Science Grade: " << sciencegrade << endl;
    cout << "History Grade: " << historygrade << endl;
    cout << "Average Grade: " << averagegrade << endl;
    cout << "Letter Grade : " << lettergrade << endl;
    cout << "--------------------------------------" << endl;
}
void Studentrecord::write_data()
{
    ofstream outfile;
    outfile.open("student.bank", ios::binary|ios::app);
    read_data();
    outfile.write(reinterpret_cast<char*>(this), sizeof(*this));
    outfile.close();
}
void Studentrecord::read_rec()
{
    ifstream infile;
    infile.open("student.bank", ios::binary);
    if(!infile)
    {
        cout << "Error in Opening! File Not Found!!" << endl;
        return;
    }
    cout << "\n****Data from file****<< endl";
    while(!infile.eof())
    {
        infile.read(reinterpret_cast<char*>(this), sizeof(*this));
        show_data();
    }
    infile.close();
}
void Studentrecord::search_data()
{
    int n;
    ifstream infile;
    infile.open("student.bank", ios::binary);
    if(!infile)
    {
        cout << "Error in Opening! File Not Found!!" << endl;
        return;
    }
    infile.seekg(0,ios::end);
    long count = infile.tellg()/sizeof(*this);
    cout << "\n There are " << count << " record in the file";
    cout<< "\n Enter Roll Number to Search: ";
    cin >> n;
    infile.seekg((n-1)*sizeof(*this));
    infile.read(reinterpret_cast<char*>(this), sizeof(*this));
    show_data();
}
void Studentrecord::edit_data()
{
    int n;
    fstream iofile;
    iofile.open("student.bank", ios::binary);
    if(!iofile)
    {
        cout << "Error in Opening! File Not Found!!" << endl;
        return;
    }
    iofile.seekg(0,ios::end);
    long count = iofile.tellg()/(sizeof(*this));
    cout << "\n There are " << count << " record in the file";
    cout<< "\n Enter Roll Number to edit: ";
    cin >> n;
    iofile.seekg((n-1)*sizeof(*this));
    iofile.read(reinterpret_cast<char*>(this), sizeof(*this));
    cout << "Record " << n << "has following data" << endl;
    show_data();
    iofile.close();
    iofile.open("record.bank", ios::out|ios::in|ios::binary);
    iofile.seekp((n-1)*sizeof(*this));
    cout << "\n Enter data to Modify " << endl;
    read_data();
    iofile.write(reinterpret_cast<char*>(this), sizeof(*this));
}
void Studentrecord::delete_data()
{
    int n;
    ifstream infile;
    infile.open("student.bank", ios::binary);
    if(!infile)
    {
        cout << "Error in Opening! File Not Found!!" << endl;
        return;
    }
    infile.seekg(0,ios::end);
    long count = infile.tellg()/(sizeof(*this));
    cout << "\n There are " << count << " record in the file";
    cout<< "\n Enter Roll Number to Delete: ";
    cin >> n;
    fstream tmpfile;
    tmpfile.open("tmpfile.bank", ios::out|ios::binary);
    infile.seekg(0);
    for(int i=0; i<count; i++)
    {
        infile.read(reinterpret_cast<char*>(this),sizeof(*this));
        if(i==(n-1))
            continue;
        tmpfile.write(reinterpret_cast<char*>(this),sizeof(*this));
    }
    infile.close();
    tmpfile.close();
    remove("sstudent.bank");
    rename("tmpfile.bank", "record.bank");
}
int main()
{
    
}
