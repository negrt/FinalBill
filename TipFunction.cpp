//*********************************************************************
//Function: CalculateFinalBill
//
//Purpose: To calculate the final bill and return it to main.
//
//Update Information
//------------------
//
//*********************************************************************

#include "TipFunction.h"

double CalculateFinalBill(double billAmount, double taxPct, double tipPct)
{
	double finalBill, taxedBill;
	
	//Calculate the total of the bill with the tax added.
	taxedBill = (billAmount*taxPct) + billAmount;

	//Calculate the total of the bill with the tax and tip added.
	finalBill = (taxedBill*tipPct) + taxedBill;
	
	return finalBill;
}