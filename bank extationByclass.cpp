#include<iostream>
#include<string>
#include"clsString.h"
#include"clsDate.h"
#include"clsUlit.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
#include"clsLogInscreen.h"
#include"GlobalDec.h"

#include "clsCurrency.h"
using namespace std;



int main()
{


	while (true)
	{
		if (!clsLogInscreen::LoginAccountUser()) {
			break;
		}

	}
	

	
	

	return 0;
}

