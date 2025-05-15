#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
 {
    string username, password;
    // Step 1: Save login credentials 
    ofstream firstFile("privateData.txt" );
    if (!firstFile) 
    {
        cout << "Error creating privateData.txt file!" << endl;
        return 1;
    }
    cout << "Enter the username (Spaces Not Allowed): ";
    getline(cin, username);
    cout << "Enter the password: ";
    getline(cin, password);
    firstFile << username << endl;
    firstFile << password << endl;
    cout << "Security Details Entered Successfully." << endl;
    firstFile.close();

    // Step 2: Saving account details 
    string name, cnic, phoneNo;
    double balance;
    ofstream secondFile("AccountDetails.txt", ios::out);
    if (!secondFile) 
    {
        cout << "Error creating AccountDetails.txt file!" << endl;
        return 1;
    }
    cout << "Enter the name of the user: ";
    getline(cin, name);
    cout << "Enter the CNIC of the user: ";
    getline(cin, cnic);
    cout << "Enter the phone number of the user: ";
    getline(cin, phoneNo);
    m:
    cout << "Enter the balance of the user: ";
    cin >> balance;
    if(balance < 0 ){
        cout<<"Enter Positive Numbers, Try again\n";
        goto m;
    }
    if(cin.fail()){
        cout<<"Only Numbers Allowed , Please Try again \n";
        cin.clear();
        cin.ignore(1000000000, '\n');
        goto m;
    }
    cin.ignore();
    secondFile << "*-----------------------------------------*" << endl;
    secondFile << "Name: " << name << endl;
    secondFile << "CNIC: " << cnic << endl;
    secondFile << "Phone No: " << phoneNo << endl;
    secondFile << "Balance: " << balance << endl;
    secondFile.close();

    // Step 3: Login process
    cout << "\n Login Required so , Enter your credentials" << endl;
    string enteredUserName, enteredPassword;
    bool isLoggedIn = false;
    while (!isLoggedIn)
     {
        cout << "\nEnter the username: ";
        getline(cin, enteredUserName);
        cout << "Enter the password: ";
        getline(cin, enteredPassword);
        ifstream file("privateData.txt");
        if (!file) 
        {
            cout << "No Data found....\n " << endl;
            return 1;
        }
        string storedUsername, storedPassword;


        getline(file, storedUsername);
        getline(file, storedPassword);
        file.close();
        if (enteredUserName == storedUsername && enteredPassword == storedPassword) {
            cout << " Login Successful!" << endl;
            isLoggedIn = true;
        } else
        {
            cout << "Login Failed! Please try again." << endl;
        }
    }
    return 0;
}