/****SAMPLE PROGRAM HEADER*******************************************************
St George Pennant
Due Date: February 03, 2020
Course:  C0P3014
Assignment:  Program 2
Professor: Sorgente

Description:

*************************************************************/
#include <iostream> //standard library for i/o
#include <string> // always include this when you use the string class
using namespace std;


//Declaration/ Prototypes for your functions will go here
//BE SURE TO ADD COMMENTS TO THE FUNCTION PROTOTYPES AND THE FUNCTION DEFINITIONS

void GetOrderData(string&, string&, int&, double&, int&);
void GetTaxRate(double&, int);
void Calculation(int, double, double, double&, double&, double&);
void Display(string, string, int, double, int, double, double, double, double);

//HERE IS THE main function

int main()
{
	//declare all variables in the main function
	string userResponse = "y";
	string name; //Users Name
	string cellNum; //Cell phone number input
	string itemNum; //Item number input
	//string cell; //Cell phone number output
	//string item; //Item number output
	int quantity; // The Amount
	int locID; //Location ID Number
	double price; // Cost
	double taxRate; // Area Taxes 
	double tax; //(price * quantity * taxRate)
	double net; //(quantity * price)
	double total; // Over all Cost

	cout << "Enter your first name: ";
	cin >> name;

	while (userResponse != "n" && userResponse != "N")
	{
		//get the order data function call
		GetOrderData(cellNum, itemNum, quantity, price, locID);
		
		if (locID < 500)  //invalid location, < 500 – is not a valid entry for the locationID(less than 500 is not valid)
			cout << "Invalid location" << endl << endl;
		else
		{
			//get the tax rate function call
			GetTaxRate(taxRate, locID);

			//make the calculations function call
			Calculation(quantity, price, taxRate, tax, net, total);

			//display the results function call
			Display(cellNum, itemNum, quantity, price, locID, taxRate, tax, net, total);

		}
		cout << name << ", Would you like to do another calculation (Y or N): " << endl;
		cin >> userResponse;
	}

	cout << endl << "Have a nice day! " << name << endl;
	return  0;
}
//Function Implementations will go here

///*************************************************************************************
//Name:  GetTaxRate
//Precondition: The location ID has a value in the correct range
//Postcondition: The tax rate will be set based on the location ID
//Description:  Sets the the tax rate by reference based on the value of the location ID
//*************************************************************************************

void GetTaxRate(double& taxRate, int locID)
{
	//use the location ID to set the tax rate
	if (locID >= 500 && locID <= 530) //500 <= locationID <= 530– TAX rate is 4 % (.04)
		taxRate = .04;

	else if (531 >= locID && locID <= 560) //531 <= locationID <= 560 – TAX rate is 6 % (.06)
		taxRate = 0.06;

	else if (561 >= locID && locID <= 580) //561 <= locationID <= 580– TAX rate is 6.6 % (.066)
		taxRate = 0.066;

	else if (581 >= locID && locID <= 600) //581 <= locationID <= 600– TAX rate is 7 % (.07)
		taxRate = 0.07;

	else if (locID > 600) //locationID > 600 - TAX rate is 8.25 % (.0825)
		taxRate = 0.0825;
}

///*************************************************************************************
//Name:  GetOrderData
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does (purpose).  

//PURPOSE: SHOW THAT YOU KNOW HOW TO READ INPUT AND USE CALL BY REFERENCE Parameters

//*************************************************************************************

void GetOrderData(string& cellNum, string& itemNum, int& quantity, double& price, int& locID)
{
	//ask and get the information from the user
	cout << "Enter the cell phone number: ";
	cin >> cellNum;

	cout << "Enter the item number? ";
	cin >> itemNum;

	cout << "Enter the quantity? ";
	cin >> quantity;

	cout << "Enter the price? ";
	cin >> price;

	cout << "Enter the location ID number? ";
	cin >> locID;
}



///*************************************************************************************
//Name:  Calculations
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does (purpose).
//*
//PURPOSE: SHOW THAT YOU KNOW HOW TO USE call be reference and call by value parameters
///*************************************************************************************
void Calculation(int quantity, double price, double taxRate, double& tax, double& net, double& total)
{
	//do the calculations here for tax, net, and total
	tax = (price * quantity * taxRate);
	net = (quantity * price);
	total = (net + tax);
}


///*************************************************************************************
//Name:  Display
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does (purpose).
//*
//PURPOSE: SHOW THAT YOU KNOW HOW TO USE call by value parameters
///*************************************************************************************
void Display(string cell, string item, int quantity, double price, int locID, double taxRate, double tax, double net, double total)
{
	//set the number of decimal places for doubles
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2); //use any number her for the number of decimal places

	// display the results here
	cout << "\nCell number: " << cell << endl;

	cout << "Item number: " << item << endl;

	cout << "Quantity: " << quantity << endl;

	cout << "Price: " << price << endl;

	cout << "Location ID: " << locID << endl;

	cout << "Tax Rate: " << taxRate << endl;

	cout << "Order Tax: $" << tax << endl;

	cout << "Net Cost: $" << net << endl;

	cout << "Total Cost $" << total << "\n" << endl;
}





