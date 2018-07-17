//***************************************************************************
//File: MainTipFunction.cpp
//
//Purpose: Take data from a file, calculate final bill, send data to a file. 
//
//Written By: Timothy Negron
//
//Compiler: Visual Studio C++ 2017
//
//Update Information
//------------------
//
//Name: Timothy Negron
//Date: 2/10/2018
//Description: Removed line 67. The line wasn't needed for the code to work.
//
//Name: Timothy Negron
//Date: 2/15/2018
//Description: Hardcoded Record.txt file. The program no longer ask the user
//				which file to open. The change was requested by Professor 
//				Arthur Hoskey.
//
//***************************************************************************

#include <iostream>
#include "TipFunction.h"
using namespace std;

int main()
{
	//All data types used.
	string ucRead, ucWrite;
	ifstream input;
	ofstream output;
	double bill, taxPct, tipPct, finalBill, choice;

	//********************************************************************************
	//Enters into a do while loop and creates a record as many times as desired. 
	//The user has a option to end the loop after the first record is made.
	//********************************************************************************
	do{
		//Open records from text file.
		input.open("Record.txt");
		
		//Ask the user which file do they want to write to then open it.
		cout << "File to write to: ";
		cin >> ucWrite;
		output.open(ucWrite);

		//Write the column headers on the output file.
		output << setw(8) << right << "Bill";
		output << setw(10) << right << "Tax Pct";
		output << setw(10) << right << "Tip Pct";
		output << setw(13) << right << "Final Bill" << endl;

		//Loop until all the data from the file is read, calculated, and inserted.
		while (!input.eof())
		{
			//Place the first 3 pieces of data into variables
			input >> bill;
			input >> taxPct;
			input >> tipPct;

			//Call the function CalculateFinalBill to calculate the final bill.
			finalBill = CalculateFinalBill(bill, taxPct, tipPct);
			
			//Send the data to the output file.
			output << setw(8) << right << fixed << setprecision(2) << bill;
			output << setw(10) << right << fixed << setprecision(3) << taxPct;
			output << setw(10) << right << fixed << setprecision(2) << tipPct;
			output << setw(13) << right << fixed << setprecision(2) << finalBill << endl;
		}

		//Close the files.
		input.close();
		output.close();

		//Give the user the option to end the program/loop.
		cout << endl << "Type -1 to exit the program or any other number to continue: ";
		cin >> choice;
		cout << endl;

	} while (choice != -1);

	
	return 0;
}