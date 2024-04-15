#pragma once
using namespace std;

// Date: 3/30/2023
// Chemistry Element (struct) contains these properties(fields/attributes) 
struct Element
{
	int atomicNumber = 0;//variable will hold the atomic numbers of all elements
	char name[25] = "unknown";//variable will hold the names of all elements
	char symbol[3] = "  ";//variable will hold the atomic symbols of all the elements
	double atomicMass = 0.0;//variable will hold the atomic mass of all the elements
	int state = 0;//variable will hold the atomic state of all elements
	int type = 0;//variable will hold the type of each element
	char discoverer[100] = "unknown";//variable will hold the name of all the element discoverers
	int discoveredYear = 0;//variable will hold the year each element was discovered
};

//lookup arrays
const string states[] = { "unknown", "Solid", "Liquid", "Gas" };
const string types[] = { "unknown", "Actinide", "Alkali Metal", "Alkaline Earth Metal", "Halogen", "Lanthanide", "Metalloid", "Noble Gas", "Reactive Nonmetal", "Post-Transition Metal",  "Transition Metal" };

//precondition  : e (an Element structure)
//postcondition: none
// display an element's fields/attributes
void displayElement(const Element ElementInput)
{
	cout << "\nAtomic number   : " << ElementInput.atomicNumber;//this will display the atomic numbers of all elements
	cout << "\nSymbol          : " << ElementInput.symbol;//this will display the atomic symbols of all elements
	cout << "\nName            : " << ElementInput.name;//this will display the names of all elements
	cout << "\nType            : " << ElementInput.type << " (" << types[ElementInput.type] << ")";//this will display the elemental type of all elements
	cout << "\nAtomic mass     : " << ElementInput.atomicMass;//this will display the atomic mass of all elements
	cout << "\nStandard state  : " << ElementInput.state << " (" << states[ElementInput.state] << ")";// this will display all atomic masses of all elements
	cout << "\nDiscovered by   : " << ElementInput.discoverer;//this will display the name of the individuals that might've discovered the element
	cout << "\nDiscovered year : " << ElementInput.discoveredYear << "\n";//this will display the year each element was discovered
}

//precondition: pointer to an array of Element structure)
///////////////   size (integer of the arrary size)
//postcondition: none
//display all elements from the dynamic array
void displayPeriodicTableElements(const Element* ElementInput, int size)
{
	for (int i = 0; i < size; i++)//for loop will loop through all of the elements in the binary files
	{
		cout << "\n\tPeriodic Table element[" << i + 1 << "]";
		cout << "\n\t" << string(70, char(196));
		displayElement(ElementInput[i]);//all the data from the binary files will be displayed
	}
}


//precondition none
//postcondition none
//updateElement function will be used in case 7 of part A of the exam to allow the user to update an element from the binary based on the atomic number of the element
void updateElement(Element& e)//the function will alow the user to update all atributes of the selected element from atomic mass, atomic number, atomic state, atomic name and all other atributes
{///////////////////////////////
	string symbol = inputString("\n\tEnter a new symbol(Symbol cannot have more than 2 letters!): ", false);
	for (int i = 0; i < symbol.length(); i++)
		symbol[i] = (i == 0) ? toupper(symbol[i]) : tolower(symbol[i]);

	strcpy_s(e.symbol, sizeof(e.symbol), symbol.c_str());

	string name = inputString("\tEnter a new name: ", false);
	for (int i = 0; i < symbol.length(); i++)
		name[i] = (i == 0) ? toupper(name[i]) : tolower(name[i]);

	strcpy_s(e.name, sizeof(e.name), name.c_str());
	e.state = inputInteger("\tEnter a new state (0-unknown, 1-Solid, 2-Liquid, or 3-Gas): ", 0, 3);
	e.atomicMass = inputDouble("\tEnter a new atomic mass: ", true);
	e.type = inputInteger("\tEnter a new type (0-unknown, 1-Actinide, 2-Alkali Metal, 3-Alkaline Earth Metal,\n\t\t\t  4-Halogen, 5-Lanthanide, 6-Metalloid, 7-Noble Gas,\n\t\t\t  8-Reactive Nonmetal, 9-Post-Transition Metal, or 10-Transition Metal): ", 0, 10);
	strcpy_s(e.discoverer, sizeof(e.discoverer), inputString("\tEnter a new discoverer: ", true).c_str());
	e.discoveredYear = inputInteger("\tEnter a new year discovered: ", true);
}

//precondition none
//postcondition none
//Periodictable1 will be used in the main menu of the program and it will display the periodic table in color
void Periodictable1()
{
	system("cls");
	HANDLE Colors = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(Colors, 3); cout << "           PERIODIC TABLE OF ELEMENTS BY SYMBOL" << endl;
	cout << endl;
	SetConsoleTextAttribute(Colors, 14);
	cout << "[H]";cout << "                                                                ";	SetConsoleTextAttribute(Colors, 3);cout << "[He]" << endl;
	SetConsoleTextAttribute(Colors, 11);
	SetConsoleTextAttribute(Colors, 11); cout << "[Li]";	SetConsoleTextAttribute(Colors, 4); cout << "[Be]                                       ";SetConsoleTextAttribute(Colors, 9); cout << "[B ]"; SetConsoleTextAttribute(Colors, 9); cout << "[C ][N][ O ][F ]";SetConsoleTextAttribute(Colors, 3); cout << "[Ne] " << endl;
	SetConsoleTextAttribute(Colors, 11); cout << "[Na]"; SetConsoleTextAttribute(Colors, 4); cout << "[Mg]                                       ";SetConsoleTextAttribute(Colors, 9); cout << "[Al][Si][P][ S ][Cl]";SetConsoleTextAttribute(Colors, 3); cout << "[Ar]" << endl;
	SetConsoleTextAttribute(Colors, 11); cout << "[K ]"; SetConsoleTextAttribute(Colors, 4); cout << "[Ca]";SetConsoleTextAttribute(Colors, 5); cout << "[Sc][Ti][V][Cr][Mn][Fe][Co][Ni][Cu][Zn]";SetConsoleTextAttribute(Colors, 9); cout << "[Ga][Ge][As][Se][Br]";SetConsoleTextAttribute(Colors, 3); cout << "[Kr] " << endl;
	SetConsoleTextAttribute(Colors, 11); cout << "[Rb]"; SetConsoleTextAttribute(Colors, 4); cout << "[Sr]";SetConsoleTextAttribute(Colors, 5); cout << "[Y][Zr][Nb][Mo][Tc][Ru][Rh][Pd][Ag][Cd]";SetConsoleTextAttribute(Colors, 9); cout << "[In][Sn][Sb][Te][I ]";SetConsoleTextAttribute(Colors, 3); cout << "[Xe] " << endl;
	SetConsoleTextAttribute(Colors, 11); cout << "[Cs]"; SetConsoleTextAttribute(Colors, 4); cout << "[Ba]";SetConsoleTextAttribute(Colors, 5); cout << " * [Hf][Ta][W][Re][Os][Ir][Pt][Au][Hg ]";SetConsoleTextAttribute(Colors, 9); cout <<  "[Tl][Pb][Bi][Po][At]";SetConsoleTextAttribute(Colors, 3); cout << "[Rn] " << endl;
	SetConsoleTextAttribute(Colors, 11); cout << "[Fr]"; SetConsoleTextAttribute(Colors, 4); cout << "[Ra]";SetConsoleTextAttribute(Colors, 5); cout << "* *[Rf][Db][Sg][Bh][Hs][Mt][Ds][Rg][Cn]";SetConsoleTextAttribute(Colors, 6); cout << "[Nh][Fl][Mc][Lv][Ts][Og]" << endl;
	cout << endl;
	SetConsoleTextAttribute(Colors, 2); cout << "            * [La][Ce][Pr][Nd][Pm][Sm][Eu][Gd][Tb][Dy][Ho][Er][Tm][Yb][Lu]" << endl;
	SetConsoleTextAttribute(Colors, 3); cout << "          *  *[ Ac][Th][Pa][U][Np][Pu][Am][Cm][Bk][Cf][Es][Fm][Md][No][Lr]" << endl;
	cout << endl;
	cout << endl;
	SetConsoleTextAttribute(Colors, 7); cout << "In chemistry, the periodic table is a tabular display of the chemical elements.It is widely used in" << endl;
	cout << "chemistry, physics, and other sciences, and is generally seen as an icon of chemistry.It is a graphic" << endl;
	cout << "formulation of the periodic law, which states that the properties of the chemical elements exhibit a" << endl;
	cout << "periodic dependence on their atomic numbers." << endl;
	cout << endl;

}

//precondition none
//postcondition none
//Periodictable2 will be used in the part A menu of the program and it will display the periodic table in color in case 6 and it will be based on the atomic symbols of all elements
void Periodictable2()
{
	system("cls");
	HANDLE Color = GetStdHandle(STD_OUTPUT_HANDLE);
	
	cout << endl;
	SetConsoleTextAttribute(Color, 14);
	cout << "[H]";cout << "                                                                ";	SetConsoleTextAttribute(Color, 3);cout << "[He]" << endl;
	SetConsoleTextAttribute(Color, 11);
	SetConsoleTextAttribute(Color, 11); cout << "[Li]";	SetConsoleTextAttribute(Color, 4); cout << "[Be]                                       ";SetConsoleTextAttribute(Color, 9); cout << "[B ]"; SetConsoleTextAttribute(Color, 9); cout << "[C ][N][ O ][F ]";SetConsoleTextAttribute(Color, 3); cout << "[Ne] " << endl;
	SetConsoleTextAttribute(Color, 11); cout << "[Na]"; SetConsoleTextAttribute(Color, 4); cout << "[Mg]                                       ";SetConsoleTextAttribute(Color, 9); cout << "[Al][Si][P][ S ][Cl]";SetConsoleTextAttribute(Color, 3); cout << "[Ar]" << endl;
	SetConsoleTextAttribute(Color, 11); cout << "[K ]"; SetConsoleTextAttribute(Color, 4); cout << "[Ca]";SetConsoleTextAttribute(Color, 5); cout << "[Sc][Ti][V][Cr][Mn][Fe][Co][Ni][Cu][Zn]";SetConsoleTextAttribute(Color, 9); cout << "[Ga][Ge][As][Se][Br]";SetConsoleTextAttribute(Color, 3); cout << "[Kr] " << endl;
	SetConsoleTextAttribute(Color, 11); cout << "[Rb]"; SetConsoleTextAttribute(Color, 4); cout << "[Sr]";SetConsoleTextAttribute(Color, 5); cout << "[Y][Zr][Nb][Mo][Tc][Ru][Rh][Pd][Ag][Cd]";SetConsoleTextAttribute(Color, 9); cout << "[In][Sn][Sb][Te][I ]";SetConsoleTextAttribute(Color, 3); cout << "[Xe] " << endl;
	SetConsoleTextAttribute(Color, 11); cout << "[Cs]"; SetConsoleTextAttribute(Color, 4); cout << "[Ba]";SetConsoleTextAttribute(Color, 5); cout << " * [Hf][Ta][W][Re][Os][Ir][Pt][Au][Hg ]";SetConsoleTextAttribute(Color, 9); cout << "[Tl][Pb][Bi][Po][At]";SetConsoleTextAttribute(Color, 3); cout << "[Rn] " << endl;
	SetConsoleTextAttribute(Color, 11); cout << "[Fr]"; SetConsoleTextAttribute(Color, 4); cout << "[Ra]";SetConsoleTextAttribute(Color, 5); cout << "* *[Rf][Db][Sg][Bh][Hs][Mt][Ds][Rg][Cn]";SetConsoleTextAttribute(Color, 6); cout << "[Nh][Fl][Mc][Lv][Ts][Og]" << endl;
	cout << endl;
	SetConsoleTextAttribute(Color, 2); cout << "            * [La][Ce][Pr][Nd][Pm][Sm][Eu][Gd][Tb][Dy][Ho][Er][Tm][Yb][Lu]" << endl;
	SetConsoleTextAttribute(Color, 3); cout << "          *  *[ Ac][Th][Pa][U][Np][Pu][Am][Cm][Bk][Cf][Es][Fm][Md][No][Lr]" << endl;
	cout << endl;
	cout << endl;
	SetConsoleTextAttribute(Color, 7);
	cout << endl;

}

//precondition none
//postcondition none
//Periodictable2 will be used in the part A menu of the program and it will display the periodic table in color in case 6 and it will be based on the atomic numbers of all elements
void Periodictable3()
{
	system("cls");
	HANDLE Color = GetStdHandle(STD_OUTPUT_HANDLE);

	cout << endl;
	SetConsoleTextAttribute(Color, 14);
	cout << "[1]";cout << "                                                                                    ";	SetConsoleTextAttribute(Color, 3);cout << "[ 2]" << endl;
	SetConsoleTextAttribute(Color, 11);
	SetConsoleTextAttribute(Color, 11); cout << "[3]";	SetConsoleTextAttribute(Color, 4); cout << "[4]                                                   ";SetConsoleTextAttribute(Color, 9); cout << "[ 5  ]"; SetConsoleTextAttribute(Color, 9); cout << "[ 6  ][ 7  ][ 8  ][ 9  ]";SetConsoleTextAttribute(Color, 3); cout << "[10] " << endl;
	SetConsoleTextAttribute(Color, 11); cout << "[11]"; SetConsoleTextAttribute(Color, 4); cout << "[12]                                                 ";SetConsoleTextAttribute(Color, 9); cout << "[ 13 ][ 14 ][ 15 ][ 16 ][ 17 ]";SetConsoleTextAttribute(Color, 3); cout << "[18]" << endl;
	SetConsoleTextAttribute(Color, 11); cout << "[19]"; SetConsoleTextAttribute(Color, 4); cout << "[20]";SetConsoleTextAttribute(Color, 5); cout << "[21][22 ][23 ][24 ][25 ][26 ][27 ][28 ][29 ][30 ]";SetConsoleTextAttribute(Color, 9); cout << "[ 31 ][ 32 ][ 33 ][ 34 ][ 35 ]";SetConsoleTextAttribute(Color, 3); cout << "[36] " << endl;
	SetConsoleTextAttribute(Color, 11); cout << "[37]"; SetConsoleTextAttribute(Color, 4); cout << "[38]";SetConsoleTextAttribute(Color, 5); cout << "[39][40 ][41 ][42 ][43 ][44 ][45 ][46 ][47 ][48 ]";SetConsoleTextAttribute(Color, 9); cout << "[ 49 ][ 50 ][ 51 ][ 52 ][ 53 ]";SetConsoleTextAttribute(Color, 3); cout << "[54] " << endl;
	SetConsoleTextAttribute(Color, 11); cout << "[55]"; SetConsoleTextAttribute(Color, 4); cout << "[56]";SetConsoleTextAttribute(Color, 5); cout << " * [ 72 ][73 ][74 ][75 ][76 ][77 ][78 ][79 ][80 ]";SetConsoleTextAttribute(Color, 9); cout << "[ 81 ][ 82 ][ 83 ][ 84 ][ 85 ]";SetConsoleTextAttribute(Color, 3); cout << "[86] " << endl;
	SetConsoleTextAttribute(Color, 11); cout << "[87]"; SetConsoleTextAttribute(Color, 4); cout << "[88]";SetConsoleTextAttribute(Color, 5); cout << "* *[104][105][106 ][107][108][109][110][111][112]";SetConsoleTextAttribute(Color, 6); cout << "[113 ][114 ][115 ][116 ][117][118]" << endl;
	cout << endl;
	SetConsoleTextAttribute(Color, 2); cout << "            * [57][58 ][59][60][61][62][63][64][65][66][67][68][69][70 ][ 71 ]" << endl;
	SetConsoleTextAttribute(Color, 3); cout << "          *  *[89][90][91][92][93][94][95][96][97][98][99][100][101][102][103]" << endl;
	cout << endl;
	cout << endl;
	SetConsoleTextAttribute(Color, 7);
	cout << endl;

}