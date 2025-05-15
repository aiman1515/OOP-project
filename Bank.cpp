#include <iostream>
#include <string>
using namespace std;

int arr[50];
int accountCounter = 1003400;
int accountIndex = 0;
class BankAccount
{
public:
	struct Bank
{
        string name;
        int cnic;
        int mobileNumber;
        int balance;
};
    static Bank accounts[50];

    void getAccountDetails()
	{
        cout << "\n\n\t\t\t\tFill In The detail for Account ";
        cout << "\nEnter your name: ";
        cin >> accounts[accountIndex].name;
		fflush(stdin);
        cout << "Enter your CNIC: ";
        cin >> accounts[accountIndex].cnic;
        cout << "Enter your mobile number: ";
        cin >> accounts[accountIndex].mobileNumber;
        cout << "Enter your Account initial Balance: ";
        cin >> accounts[accountIndex].balance;
    }

    void displayAccount()
	{
        cout << "\n\t\tACCOUNT DETAILS!\n";
        cout << "\t\tName: " << accounts[accountIndex].name << endl;
        cout << "\t\tCNIC: " << accounts[accountIndex].cnic << endl;
        cout << "\t\tMobile Number: " << accounts[accountIndex].mobileNumber << endl;
        cout << "\t\tBalance: " << accounts[accountIndex].balance << endl;
        cout << "\n\tYOUR ACCOUNT HAS BEEN CREATED SUCCESSFULLY!\n";
        cout << "\n\t\tYour account number: " << accountCounter << endl;
        cout << "-----------------------------" << endl;
        arr[accountIndex]=accountCounter;
        accountCounter++;
        accountIndex++;
    }
};

BankAccount::Bank BankAccount::accounts[50];

class DeleteAccount : public BankAccount
{
private:
    int account, flag = 0;
    char ch;
public:
    void getAccountDetails()
	{
        cout << "\n\nEnter Account Number to Delete : ";
        cin >> account;
    }

    void closeAccount()
	{
        for (int i = 0; i < accountIndex; i++)
		{
            if (account == arr[i])
			{
                cout << "\n\t\tAccount found successfully!";
                cout << "\n\nDo you really want to delete this account (y/n): ";
                cin >> ch;
                if (ch == 'y' || ch == 'Y')
				{
                    for (int j = i; j < accountIndex - 1; j++)
					{
                        arr[j] = arr[j + 1];
                        accounts[j] = accounts[j + 1];
                    }
                    cout << "\n\t\tAccount Deleted!";
                    accountIndex--;
                    return;
                }
				else
				{
                    cout << "\n\t\t Okay! Your account is not deleted.";
                    return;
                }
                flag = 1;
            }
        }

        if (flag == 0)
		{
            cout << "\n\t\tNo such account found!";
            return;
        }
    }
};

class CheckBalance : public BankAccount
{
private:
    int account;
public:
    void getAccountDetails()
	{
        cout << "\nENTER ACCOUNT NUMBER TO CHECK BALANCE: ";
        cin >> account;
    }

    void check() const
	{
        for (int i = 0; i < accountIndex; i++)
		{
            if (arr[i] == account)
			{
                cout << "\n\t\tAccount Balance = " << accounts[i].balance;
                return;
            }
        }

        cout << "\n\t\tNo account found!\n\n";
    }
};

class WithdrawAmount : public BankAccount
{
private:
    int account;
public:
    void getAccountDetails()
	{
        cout << "ENTER ACCOUNT NUMBER TO WITHDRAW: ";
        cin >> account;
    }

    void withdraw()
	{
        double amount;
        for (int i = 0; i < accountIndex; i++)
		{
            if (account == arr[i])
			{
                cout << "\n\n\t\t\tAccount opened for withdrawal.\n";
                cout << "\nEnter Amount for Withdrawl : ";
                cin >> amount;

                if (amount <= 0)
				{
                    cout << "\nInvalid amount entered.";
                    return;
                }

                if (accounts[i].balance < amount)
				{
                    cout << "\n\t\tInsufficient balance!!\n";
                }
				else
				{
                    accounts[i].balance -= amount;
                    cout << "\n\n\t\tAmount withdrawal successful!\n";
                    cout << "\n\t\tAfter withdrawal, the remaining balance is " << accounts[i].balance << endl;
                }
                return;
            }
        }

        cout << "\nNo such account found!\n\n";
    }
};

class DepositAmount : public BankAccount
{
private:
    int account;
public:
    void getAccountDetails()
	{
        cout << "ENTER ACCOUNT NUMBER TO DEPOSIT: ";
        cin >> account;
    }

    void deposit()
	{
        double amount;
        for (int i = 0; i < accountIndex; i++)
		{
            if (account == arr[i])
			{
                cout << "\n\n\t\t\tAccount opened for deposit.\n";
                cout << "\nEnter Amount To Deposit : ";
                cin >> amount;
                accounts[i].balance += amount;
                cout << "\n\n\t\tAmount deposit successful!\n";
                cout << "\n\t\tAfter deposit, the new balance is " << accounts[i].balance << endl;
                return;
            }
        }
        cout << "\n\t\tNo such account found!\n\n";
    }
};

class Display
{
public:
    virtual void displayAllAccounts() = 0;
};

class DisplayAccounts : public Display
{
public:
    void displayAllAccounts()
	{
        for (int i = 0; i <accountIndex; ++i)
		{
            cout << "\n\t\tACCOUNT DETAILS!\n";
            cout << "\t\tName: " << BankAccount::accounts[i].name << endl;
            cout << "\t\tCNIC: " << BankAccount::accounts[i].cnic << endl;
            cout << "\t\tMobile Number: " << BankAccount::accounts[i].mobileNumber << endl;
            cout << "\t\tBalance: " << BankAccount::accounts[i].balance << endl;
            cout << "\t\tAccount number: " << i + 1003400 << endl;
        }
        cout << "\n\t\tTotal Accounts Available : " << accountIndex<<endl;
    }
};

int main()
{
    int choice;
    char id[100];
    string correct_password = "bank@gmail.com";
    int key;
    Display *display = new DisplayAccounts();
     cout << "\n\t\t\t\t\t\t\"Bank Management System\"\n";
    do
	{
        cout << "\n\n1. Create new account\n";
        cout << "2. Delete account\n";
        cout << "3. Check balance\n";
        cout << "4. Withdraw amount\n";
        cout << "5. Deposit amount\n";
        cout << "6. Display all available Accounts\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
		{
            case 1:
			{
                if (accountIndex < 50)
				{
                    BankAccount account;
                    account.getAccountDetails();
                    account.displayAccount();
                }
				else
				{
                    cout << "\n\n\t\tBank Currently Full !!! ";
                }
                break;
            }
            case 2:
			{
                if (accountIndex > 0)
				{
                    DeleteAccount d1;
                    d1.getAccountDetails();
                    d1.closeAccount();
                }
				else
				{
                    cout << "\n\n\t\tNo Account Exist Yet  !!!";
                }
                break;
            }
            case 3:
			{
                if (accountIndex > 0)
				{
                    CheckBalance c1;
                    c1.getAccountDetails();
                    c1.check();
                }
				else
				{
                    cout << "\n\n\t\tNo Account Exist Yet  !!!";
                }
                break;
            }
            case 4:
			{
                if (accountIndex > 0)
				{
                    WithdrawAmount w1;
                    w1.getAccountDetails();
                    w1.withdraw();
                }
				else
				{
                    cout << "\n\n\t\tNo Account Exist Yet  !!!";
                }
                break;
            }
            case 5:
			{
                if (accountIndex > 0)
				{
                    DepositAmount d;
                    d.getAccountDetails();
                    d.deposit();
                }
				else
				{
                    cout << "\n\n\t\tNo Account Exist Yet  !!!";
                }
                break;
            }
            case 6:
			{
                cout << "\n\t\t\t\nThis Option Is only Valid for Official Members !!\n";
                cout << "\nPlease Verify Your Identity By Entering Log-in ID and password\n";
                cout << "\n\nID: ";
                cin >> id;
                cout << "Password : ";
                cin >> key;
                if (id == correct_password && key == 12345)
				{
                    cout << "\n\t\t\tIdentity Verified !!";
                    if (accountIndex > 0)
					{
                        cout << "\nDetails OF Accounts are as follow \n\n";
                        display->displayAllAccounts();
                    }
					else
					{
                        cout << "\n\n\t\tNo Account Exist Yet  !!!";
                    }
                }
				else
				{
                    cout << "Wrong Id or Password!!! ";
                }
                break;
            }
            case 7:
			{
                cout << "\nExiting....";
                break;
            }
            default:
                cout << "\nInvalid choice. Please try again.\n";
                break;
        }
    } while (choice != 7);

    return 0;
}