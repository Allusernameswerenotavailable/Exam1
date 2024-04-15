#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "input.h"
#include "Element (2).h"
using namespace std;

char menuOption();
void Periodictable1();////
void Periodictable2();////these are all our function prototypes
void Periodictable3();///
void DynamicArrayElements();//
void StructureElementsBinaryFiles();//


//precondition none
//postcondition none
int main()
{
	Periodictable1();//Periodictable1 will display the periodic table in color
	

	do
	{
		switch (toupper(menuOption()))///////////////
		{////////////////////////////////////////////Do switch will switch between both parts of the exam which is part A which involves
		case 'A': DynamicArrayElements(); break;/////creating a dynamic array that will hold data from binary files
		case 'B': StructureElementsBinaryFiles(); break;//Part B involves doing the same as part A but we will be using random access
		case 'X': exit(0); break;


		}

		system("pause");
	} while (true);

	return 0;


}
//menuOption will display the menu for both parts of the exam -- part A and part B
//precondition none
//postcondition none
char menuOption()
{
	
	
	cout << endl;
	cout << "\n\tPeriodic Table of Elements(using struct ADT) by Oscar Gallardo 03/30/23";
	cout << "\n\t" << string(80, char(205));
	cout << "\n\tA.Dynamic Array of Structure Elements";//Part A will be storing data from binary files using a dynamic array 
	cout << "\n\tB.Structure Elements from Binary File";//Part B we will use random access to analyze data from binary files 
	cout << "\n\t" << string(80, char(196));
	cout << "\n\tX.Exit the program";//case X will allow the user to exit the program
	cout << "\n\t" << string(80, char(205));
	cout << "\n";

	return inputChar("\n\toption: ", static_cast<string>("ABCX"));




}

//precondtion none
//postcondition none
//DynamicArrayElements holds our program for Part A of the exam
//Here we will call binary files and store their data in a dynamic array
//Our program will have functions that will
void DynamicArrayElements()
{	
	system("cls");
	Element* ElementInput = nullptr;//ElementInput will hold our dynamic array for the data in the binary files
	fstream file;//initializing our input file
	int size = 118;//int size will be initialized to 118 since we know our dynamic array will hold data for 118 elements
	int E = 0;//int E is initalized and will be used in case 1 to read through all of our data will be 118 elements

	do
	{
		start:
		cout << endl;
		cout << "Dynamic Array of Structure Elements";
		cout << "\n" << string(80, char(205));
		cout << "\n1. Read binary structure input data file and store elements into an dynamic array";//for case 1 we will open our binary file and we will read our data to our dynamic array
		cout << "\n2. Display 118 elements from the dynamic array";//for case 2 our program will display the data from our dynamic array
		cout << "\n3. Sort ascending order the dynamic array by atomic number(5 points Extra)";//for case 3 we will have a program that will sort our elements in ascending order from 1-118
		cout << "\n4. Sort descending order the dynamic array by atomic number(5 points Extra)";//for case 4 we will have a program that will sort our elements in descending order from 118-1
		cout << "\n5. Binary search for an element's atomic number from the array (10 points Extra)";// Did not do case 5 
		cout << "\n6. Sequencial search for an element's symbol from the array";//for case 6 we will have a program that will allow our user to search for an element based on their symbol
		cout << "\n7. Update an element by atomic number from the array(10 points Xtra)";//for case 7 we will have a program that will allow the user to update any element from our dynamic array based on their atomic number
		cout << "\n8. Save the dynamic array into a binary data file";//for case 8 the user will be able to save a new binary file with the data from our dynamic array
		cout << "\n" << string(60, char(196));
		cout << "\n0. Return";//case 0 will alow us to return to the main menu
		cout << "\n" << string(60, char(205));

		switch (inputInteger("\nOption: ", 0, 8))//we will switch through each of our cases 1-8
		{
		case 0: 
			file.close();//we will close our file
			delete[]ElementInput;//We will delete our dynamic array ElementInput in order to free up our memory
			
			return;
		case 1://for case 1 will open and read our binary file and our dynamic array will be created
		{
			if (file.is_open())//if statement will close any unwanted file that might be open in order to prevent logic errors
			{
				file.close();

			}
			E = 0;//setting our integer E, it will help us loop through all 118 elements
			
			ElementInput = new Element[size];//initalizing our dynamic array ElementInput

			string filename = inputString("\nEnter a binary data file(sorted.dat or unsorted.dat): ", true);//We will enter the name of the binary file we want to open
			

		
			file.open(filename, ios::in | ios::binary);//we will open our binary file
			if(file.fail())//we will use this if statement to do an input validation if the file the user enters does not exist this message will appear
			{
				cout << "Data file does not exist!" << endl;
			
			}
			else
			{
				cout << "Data was found and ready to continue!" << endl;//message if the file was found
				cout << endl;
				while (!file.eof())//we will use this while loop to run through our data from the binary file in order to read all of the data in the file
				{
					file.read(reinterpret_cast<char*> (&ElementInput[E]), sizeof(Element));//we will read through all the data in our binary file
					E++;//E integer will help tally up all the data found in our file
				}

			}
			
		}
		break;

		case 2://for case 2 we will display the data found in the binary file that was opened in case 1
		{
			system("cls");//we include system cls to clear anything not relevant from the screen

			if (!file.is_open())//we will have this input validation, if user chooses case 2 without opening a file in case 1 the message below will appear
			{
				cout << "\nERROR, No file has been found to analyze" << endl;
				break;

			}
			
			for(int i = 0; i < size; i++)//for loop will loop through 118 elements from the binary data file
			{
				displayElement(ElementInput[i]);//After the user opens a binary file in case 1 we will display all 118 elements in our binary data file 
				cout << '\n';
			}
					
						
		}

		break;

		case 3://for case 3 we will have a program that will sort all elements from our dynamic array in ascending order from 1-118
		{
			if(!file.is_open())///we will have this input validation, if user chooses case 3 without opening a file in case 1 the message below will appear
			{
				cout << "\nERROR, No file has been found to analyze " << endl;
				break;
			
			}
			cout << "\n\tCompleted sorting array in ASCENDING order you can now continue to case 2 to display the array in the new order!\n"; 
			cout << endl;
			int minIndex; //initalizing integer minIndex will help us swap and compare values from the dynamic array
			int minValue; //initializing integer minValue will help us swap and compare values from the dynamic array
			for (int i = 0; i < (size - 1); i++) //we will use this for loop to loop between all 118 elements in our dynamic array
			{
				minIndex = i; //setting minIndex integer equal to int i
				minValue = ElementInput[i].atomicNumber; //setting minValue integer equal to our element atomic numbers 

				for (int j = i + 1; j < size; j++)//we will use this second for loop to loop between all 118 elements in our dynamic array 
				{
					if (ElementInput[j].atomicNumber < minValue) //if statement will compare values between all elements and set values in order from lowest to highest 
					{
						minValue = ElementInput[j].atomicNumber; //setting minValue equal to lower value atomic numbers
						minIndex = j;//setting minIndex equal to j
					}
				}
				
				swap(ElementInput[minIndex].atomicNumber, ElementInput[i].atomicNumber);//////
				swap(ElementInput[minIndex].symbol, ElementInput[i].symbol);//////////////////
				swap(ElementInput[minIndex].name, ElementInput[i].name);//////////////////////All of these swap functions will swap
				swap(ElementInput[minIndex].type, ElementInput[i].type);//////////////////////all element attributes in ascending order
				swap(ElementInput[minIndex].atomicMass, ElementInput[i].atomicMass);//////////all atomic numbers will be sorted along with
				swap(ElementInput[minIndex].state, ElementInput[i].state);////////////////////each individual atomic symbols, atomic states and
				swap(ElementInput[minIndex].discoverer, ElementInput[i].discoverer);//////////all others attributes as well
				swap(ElementInput[minIndex].discoveredYear, ElementInput[i].discoveredYear);//
			}

		
		}
		break;

		case 4://for case 3 we will have a program that will sort all elements from our dynamic array in descending order from 118-1
		{
			if (!file.is_open())///we will have this input validation, if user chooses case 4 without opening a file in case 1 the message below will appear
			{
				cout << "\nERROR, No file has been found to analyze " << endl;
				break;

			}
			cout << "\n\tCompleted sorting array in DESCENDING order you can now continue to case 2 to display the array in the new order!\n"; 
			cout << endl;
			int minIndex;//initalizing integer minIndex will help us swap and compare values from the dynamic array
			int minValue;//initializing integer minValue will help us swap and compare values from the dynamic array 
			for (int i = 0; i < (size - 1); i++) //we will use this for loop to loop between all 118 elements in our dynamic array
			{
				minIndex = i; //setting minIndex integer equal to int i

				minValue = ElementInput[i].atomicNumber; //setting minValue integer equal to our element atomic numbers 
				for (int j = i + 1; j < size; j++) //we will use this second for loop to loop between all 118 elements in our dynamic array
				{
					if (ElementInput[j].atomicNumber > minValue) //if statement will compare values between all elements and set values in order from highest to lowest
					{
						minValue = ElementInput[j].atomicNumber;//setting minValue equal to higher value atomic numbers 
						minIndex = j;//setting minIndex equal to j
					}
				}

				
				swap(ElementInput[minIndex].atomicNumber, ElementInput[i].atomicNumber);//////
				swap(ElementInput[minIndex].symbol, ElementInput[i].symbol);//////////////////
				swap(ElementInput[minIndex].name, ElementInput[i].name);//////////////////////All of these swap functions will swap
				swap(ElementInput[minIndex].type, ElementInput[i].type);//////////////////////all element attributes in descending order
				swap(ElementInput[minIndex].atomicMass, ElementInput[i].atomicMass);//////////all atomic numbers will be sorted along with
				swap(ElementInput[minIndex].state, ElementInput[i].state);////////////////////each individual atomic symbols, atomic states and
				swap(ElementInput[minIndex].discoverer, ElementInput[i].discoverer);//////////all others attributes as well
				swap(ElementInput[minIndex].discoveredYear, ElementInput[i].discoveredYear);//
			}
		
			
		}
		break;

		case 5: 
		{
			cout << "DID NOT COMPLETE THIS CASE FOR EXTRA CREDIT " << endl;
		
		}
		break;

		case 6: 
		{
			Periodictable2();//Periodictable2 function will display a periodic table in color with the atomic symbol of all elements

			if (!file.is_open())///we will have this input validation, if user chooses case 6 without opening a file in case 1 the message below will appear
			{
				cout << "\nERROR, No file has been found to analyze " << endl;
				break;

			}
			
			bool bfound = false;//bool bFound will be used to input validate later on in the program in case the user inputs an atomic symbol that does not exist in the file
			char atomicSymbol[3];//char atomicSymbol will hold the atomic symbol input from our user

			cout << "\nEnter an atomic symbol - FIRST LETTER OF SYMBOL MUST BE CAPITILIZED! (X - to stop): ";
			cin.getline(atomicSymbol, 3);//we will ask the user to input an atomic symbol

			if ((strcmp("x", atomicSymbol) == 0) || (strcmp("X", atomicSymbol) == 0))//Here we will allow the user the option to return to the previous menu in case they don't wish to enter an atomic symbol
			{
				goto start;//goto start will take the user back to the previous menu
			}

			for (int i = 0; i < size; i++)//we will use this for loop to loop through all 118 elements in our dynamic array
			{
				if (strcmp(atomicSymbol, ElementInput[i].symbol) == 0)//with this if statement our program will display the element based on the atomic symbol the user inputs
				{
					displayElement(ElementInput[i]);//our function displayElement will display the element that corresponds to the atomic symbol the user inputs
					bfound = true;//bFound will validate if our atomic symbol is found in our dynamic array
					break;
				}
			}

			if (!bfound)
				cout << "\nERROR: The element with symbol(" << atomicSymbol << ") not found.\n";//if the atomic symbol that the user inputs is not found in the dynamic array then this message will appear to the user
		
		}
		break;

		case 7: 
		{
			Periodictable3();//Periodictable3 function will display a periodic table in color with the atomic mass of all elements

			if (!file.is_open())///we will have this input validation, if user chooses case 7 without opening a file in case 1 the message below will appear
			{
				cout << "\nERROR: No file has been found to analyze " << endl;
				break;

			}
			
			bool bfound = false;//bool bFound will be used to input validate later on in the program in case the user inputs an atomic number that does not exist in the file
			int atomicNumber1 = inputInteger("\nEnter an atomic number(1-118, 0 - to stop): ", 0, 118);//we will ask the user to input an atomic number

			if (atomicNumber1 == 0)//Here we will allow the user the option to return to the previous menu in case they don't wish to enter an atomic number
			{
				goto start;//goto function will return our user to the previous menu
			}

			for (int i = 0; i < size; i++)//we will use this for loop to loop through all 118 elements in our dynamic array
			{
				if (ElementInput[i].atomicNumber == atomicNumber1)//with this if statement our program will allow the user to update an element based on the atomic number the user inputs
				{
					updateElement(ElementInput[i]);//update element will allow the user to update an element from the dynamic array
					bfound = true;//bFound will validate if our atomic number is found in our dynamic array
					break;
				}
			}

			if (!bfound)
				cout << "\nERROR: The element with the atomic number(" << atomicNumber1 << ") not found.\n";//if the atomic number that the user inputs is not found in the dynamic array then this message will appear to the user
		
		}
		break;

		case 8: 
		{
			if (!file.is_open())///we will have this input validation, if user chooses case 2 without opening a file in case 1 the message below will appear
			{
				cout << "\nERROR: No file has been found to analyze " << endl;
				break;

			}
			fstream file2;//initializing our output file

			string filename2 = inputString("\nEnter name for new binary file: ", false);//user will be asked to input a name for the new file that will be created

			file2.open(filename2, ios::out | ios::binary);//we will open the new file for binary output

			if(!file2)//input validation, if file does not open the message below will appear to the user
			{
				cout << "Cannot do that!" << endl;
			
			}

			for (int i = 0; i < size; i++)//with this for loop we will loop through all elements that will be written to the new file
			{
				
				file2.write(reinterpret_cast<char*> (&ElementInput[i]), sizeof(Element));//writing data to new file
			}
			cout << "Complete, data is now stored into new file and can be found in the exam folder" << endl;

			file2.close();//we will close the file

		
		}
		break;



		}

		system("pause");
		
	} while (true);//this ends the do while loop


}

//precondtion none
//postcondition none
//For this part of the exam we will open and read data from binary files using random access
//our program will alow the user to display the data from the binary files and will be menu driven
void StructureElementsBinaryFiles()
{
	system("cls");
	string filename;//filename will hold the file the user will be asked to input
	fstream file;//initializing our input file
	Element ElementInput;//initializing our structure variable that will hold information about the elements in the periodic table
	

	do
	{
		start:
		cout << endl;
		cout << "Structure Elements from Binary Files";
		cout << "\n" << string(80, char(205));
		cout << "\n1. Input the binary file you wish to analyze";//in case 1 we will open a binary file and we will read data from it
		cout << "\n2. Display all elements from the file";//in case 2 our program will display all data from our binary file input
		cout << "\n3. Sequential search for an element's atomic number from the file";//in case 3 we will allow the user to search for an element from the binary data based on the atomic number of the element
		cout << "\n4. Sequential search for an element's symbol from the file";//in case 4 we will allow the user to search for an element from the binary data based on the atomic symbol of the element
		cout << "\n" << string(60, char(196));
		cout << "\n0. Return";//case 0 will allow the user to return to the main menu
		cout << "\n" << string(60, char(205));

		
		switch(inputInteger("\nOption: ", 0, 4))//our switch function will allow user to switch between all cases which will include the option to open a binary file and the option to read data from the file
		{
		case 0: //for case 0 we will close our file and we will return to the main menu
			file.close();
			return;
			break;
		case 1:
		{ 			
			if(file.is_open())//if statement will close any unwanted file that might be open in order to prevent logic errors
			{
				file.close();
			
			}
			filename = inputString("\nEnter a binary file (sorted.dat or unsorted.dat): ", true);//we will allow the user to input a binary file
			file.open(filename, ios::in | ios::binary);//we will open the binary file for analysis

			if (file.fail())//if the file the user inputs does not exist then the message below will be displayed
			{
				cout << "Data file does not exist!" << endl;

			}
			else
			{
				
				cout << "File was found and ready to continue!" << endl;
				file.read(reinterpret_cast<char*>(&ElementInput), (sizeof(Element)));//if file is found then we will read the data from the binary filoe				
			
			}
					
		}
		break;

		case 2: 
		{
			if (!file.is_open())//we will have this input validation, if user chooses case 2 without opening a file in case 1 the message below will appear
			{
				cout << "\nERROR: No file has been found to analyze " << endl;
				break;
			}

		
			file.clear();//Here we will clear the eof flag, this eliminates the need to close and reopen the file for each case
			file.seekg(ios::beg);//seekg will set the read the position from the beginning of the file
			while (!file.eof())//while loop 
			{
			
				file.read(reinterpret_cast<char*>(&ElementInput), (sizeof(ElementInput)));//we will read the data from our binary file
				if (file.eof()) break;//if file will allow the data from the binary file to be read until the end of the file

				displayElement(ElementInput);//displayElement function will display the data from our binary file
			}

			
		
		}
		break;

		case 3: 
		{
			Periodictable3();//Periodictable2 will display the periodic table in color with all the atomic number

			if (!file.is_open())//we will have this input validation, if user chooses case 3 without opening a file in case 1 the message below will appear
			{
				cout << "\nERROR: No file has been found to analyze " << endl;
				break;
			}


			file.clear();//Here we will clear the eof flag, this eliminates the need to close and reopen the file for each case
			file.seekg(ios::beg);//seekg will set the read the position from the beginning of the file
			bool bFound = false;//bool bFound will be used to input validate later on in the program in case the user inputs an atomic number that does not exist in the file
			
			
			int inputAtomicNumber = inputInteger("\nEnter an atomic number(1-118, 0 - to stop): ", 0, 118);//we will ask the user to input an atomic number
			if (inputAtomicNumber == 0)//Here we will allow the user the option to return to the previous menu in case they don't wish to enter an atomic number
			{
				goto start;//goto function will return our user to the previous menu
			}
			
			while(!file.eof())//with this while loop we will loop through the data of the input file until the end of the file 
			{
				
				file.read(reinterpret_cast<char*>(&ElementInput), (sizeof(ElementInput)));//the data from our binary file will be read

				if(ElementInput.atomicNumber == inputAtomicNumber)//with this if statement our program will display the element based on the atomic number the user inputs
				{
										
					displayElement(ElementInput);//our function displayElement will display the element that corresponds to the atomic number the user inputs
					bFound = true;//bFound will validate if our atomic number is found in our dynamic array
					break;
				
				}
						
			}
			if(!bFound)//if the atomic number that the user inputs is not found then this message will appear to the user
			{
				cout << "Element with that atomic number cannot be found!" << endl;
						
			}
					
		}
		break;
		case 4:
		{
			Periodictable2();//Periodictable2 will display the periodic table in color with all the atomic symbol

			if (!file.is_open())//we will have this input validation, if user chooses case 4 without opening a file in case 1 the message below will appear
			{
				cout << "\nERROR: No file has been found to analyze " << endl;
				break;
			}

			file.clear();//Here we will clear the eof flag, this eliminates the need to close and reopen the file for each case
			file.seekg(ios::beg);//seekg will set the read the position from the beginning of the file
			bool bFound = false;//bool bFound will be used to input validate later on in the program in case the user inputs an atomic symbol that does not exist in the file
			
			string inputAtomicSymbol = inputString("\nEnter an atomic symbol(FIRST LETTER OF SYMBOL MUST BE CAPITILIZED): ", true); //inputAtomicSymbol will hold the atomic symbol input from the user
		
			

			while (!file.eof())//while loop will loop through the binary file until the end of the file
			{
			
				file.read(reinterpret_cast<char*>(&ElementInput), (sizeof(ElementInput)));//we will read the binary data from our file

				if (ElementInput.symbol == inputAtomicSymbol)//with this if statement our program will display the element based on the atomic symbol the user inputs
				{

					displayElement(ElementInput);//our function displayElement will display the element that corresponds to the atomic symbol the user inputs
					bFound = true;//
					break;

				}


			}
			if (!bFound)//if the atomic symbol that the user inputs is not found then this message will appear to the user
			{
				cout << "Element with that atomic symbol cannot be found!" << endl;


			}

					
		}
		break;
		
	
		}
	
		system("pause");
	} while (true);//this will be the end of the do while loop


}