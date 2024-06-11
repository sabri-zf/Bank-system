#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
class clsWithDrow:clsScreen
{
public:
	static void WithdrowAccount() {
		clsScreen::_drowHeaderScreen("Withdrow Screen");
		cout << "Enter Account Number ";
		string AccountNumber = clsInputValidate::ReadString();
		while (clsBankClient::IsClientExist(AccountNumber)) {
			cout << "this Account Number [" << AccountNumber << "] Is Not Found , Enter another Value ..";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient client1 = clsBankClient::Find(AccountNumber);
		clsScreen::_printInfo(client1);

		int Amount = 0;
		cout << "\nHow do you want Need Amount ? ";
		Amount = clsInputValidate::ReadIntNumber();

		char ans;
		cout << "\n\n Are you sure , do you want Withdrow amount ";

		cin >> ans;

		if (towupper(ans) == 'Y') {
			if (client1.WithDrowAmount(Amount)) {
			
			cout << "\n Withdrow Is Sucssefully :) \n";
			cout << "The Amount OF Balenct Now Is :" << client1.Belence << endl;

			}
			else {
				cout << "\nCant Not Withdrow Amonte.... !!\n";
				cout << "\nAmount of WithDrow is  " << Amount << endl;
				cout << "\nYour Balence In Account   " << client1.Belence << endl;
			}
		}
		else {
			cout << "Opraition was cancellde /n";
		}

	}
};

