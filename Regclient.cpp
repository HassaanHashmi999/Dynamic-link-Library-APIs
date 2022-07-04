// Regclient.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <Windows.h>
#include <iostream>
#include"RegLibrary.h"

;
using namespace std;

int main()
{
    cout << "Creating a new registry..";
    if (Cr_reg())
    {
        cout << "Success"<<endl;
    }
    else 
    {
        cout << "Error" << endl;
    }
    char chk;
    DWORD val;
    
    cout << "Do you want to set the value yourself (y/n):";
    cin >> chk;
    if (chk == 'y' || chk == 'Y')
    {
        cout << "Enter Value:";
        cin >> val;
        cout << "Setting value for the registry(By User)..";
        if (setN(val))
        {
            cout << "Success" << endl;
        }
        else
        {
            cout << "Error" << endl;
        }
    }
    else {
        cout << "Setting value for the registry(Done by library)..";
        if (Reg_setV())
        {
            cout << "Success" << endl;
        }
        else
        {
            cout << "Error" << endl;
        }
    }



            cout << "Getting value from the Registry::";
            DWORD Value,cval;
            Value = getval();
            cout << Value << endl;



        cout << "Changing the value of registry..Adding 23."<<endl<<"The Value is::";
        Value += 23;
        cval= setter(Value);
        cout << cval << endl;


       cout << "Deleting the Registry..";
        if(Reg_Del())
        {
            cout << "Success"<<endl;
        }
        else
        {
            cout << "Error"<<endl;
        }
}

