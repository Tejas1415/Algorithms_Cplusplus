/* 
Reference from youtube video - https://www.youtube.com/watch?v=Rub-JsjMhWY
Coded and commented according to my personal understanding and needs.
Complete C++ - Intermediate to advance level tutorial.

Tejas K Reddy
*/ 

#include<iostream>
#include<vector>         // To allow operations over vectors
#include<string>        
#include<fstream>       // To allow operations over files

using namespace std;    // else shoud write like std::cout

int main(){
	
cout << "Hey Bro" << endl;
const double PI = 3.1415;          // declaring constants with double datatype
char mygrade = 'A';                // declaring characters. Characters always take 1 byte memory in the inside space.
bool isHappy = true;               // or could be false. 
 
int myage = 22;
float hi= 3.141516;                // can hold upto 6 decimal digits in general
double hii = 3.1415;               // can hold decimal numbers upto 15 digits in general

/*
Other Data types include

short int : Atleast 16 bits
long int : Atleast 32 bits
long long int : Atleast 64 bits
unsigned int : Same as signed version
long double int : Not less than double
*/

/* to print any of the above value */
cout << "My present age is " << myage << endl;

/* To find the size of a datatype */
cout << "Size of int data type is" << sizeof(myage)
     << endl; 


/* trying to increment and decrement. */
int five = 5;
cout << five++ << endl; //5
cout << ++five << endl; //7
cout << five-- << endl; //7
cout << --five << endl; //5

/* casting - Changing one data type to an other, for example u need ans of 2 ints in float */
cout << 4/5 << endl;         // ans =0; 
cout << (float)4/5 << endl; // ans =0.8  // it can be char, int, float, double 

/* if statement was covered */

/* Switch statement - used whenever we have a limited number of possible options */

int greetoption=2;

switch(greetoption){
	case 1:
		cout << "Hey" <<endl;
		break;                        // If no break, then it would exegute case 2 also. 
	case 2:
		cout << "Hi" << endl;        // Ans Hi
		break;
	case 3:
		cout << "Hello" << endl;
		break;		
	default:
		cout << "No Greet" << endl;
}

/* ternary operator */
// variable = (condition)? true:false 
int largestnum = (5>2)? 5:2;  // ans largestnum = 5;

/* Arrays */ 
int favNums[5]; // can declare this way

int badnums[5]= {1,2,3,4,5};  // index starts from 0
cout << "Bad num 2 is given as: " << badnums[1] << endl;

char myname[5][5] = {{'t','e','j','a','s'},        // Declaring 2d array, Characters single quotes, strings double 
                    {'r','e','d','d','y'}};
cout << "2nd array 2nd element: " << myname[1][1] << endl;
myname[0][2] = '3';        // Append the matrix with new stuff
 
/* Printing random numbers */

int randnum = (rand()%100) + 1; // %100 is random numbers from 0 to 100 

while (randnum != 100){
	cout << randnum << ", ";
	randnum = (rand()%100)+1;  // end the loop whenever the value becomes 100
	}
cout << endl;

/* while and do while loop discussed - 20 mins done*/

//#####################################################################################

/* Strings */
char HappyArray[6] = {'h','a','p','p','y','\0'}; // Always end with a backslash zero, to use in loops.
string birthdaystr = "birthday";
cout << HappyArray+birthdaystr << endl;     //string concatenation

string yourname;
cout << "what is your name?";
getline(cin, yourname);         // To get an user input. (get it from the user and save it in variable yourname
cout << "Hello" << yourname << endl;

// Other simple operations on strings -
yourname.size() // returns the size - Tejas has 5 size
yourname.empty() // returns 1 if true or 0 if false
yourname.append(" good") //  returns tejas good 
yourname.compare(hisname) // if both strings are equal you get 1,0,-1 based on key values

// searching for a part of the string.
int lastnameindex = yourname.find("Reddy",0); // search reddy from the index value 0 onwards.
cout << "index for the last name is: " << lastnameindex; // Tells where the string starts. Tejas Reddy - ans = 6

yourname.insert(5," Krishna");
cout << yourname << endl;     // Tejas Krishna Reddy, at 6th position added.
yourname.erase(6,8);
cout << yourname << endl;  // Tejas Reddy, from 6th position delete 8 elements
yourname.replace(6,5,"Hey  ");
cout << yourname << endl); // Tejas Hey  . replaced 5 letters from the 6th position.

/* Vectors */ 
// Similar to arrays, but can be used over several operations such as
vector <int> lotteryNumVect(10);
// lotteryNumVect.insert(), lotteryNumVect.begin(), lotteryNumVect.at(), lotteryNumVect.back(), lotteryNumVect.front(), 
// lotteryNumvect.push_back(), lotteryNumVect.pop_back()
// IMPORTANT - A vector could be used dynamically, elements need not be of fixed length as arrays.

/* Functions */ //-30 mins
int getfactorial(int number){
	int sum;
	if(number==1) sum=1;
	else sum = getfactorial(number-1)*number;
	return sum;
}
int main(){
	cout << "The factorial of 3 is: " << getfactorial(3) << endl;
	return 0;
}
	
/* Files */ //- 35 mins
string stevequote = "Apple a day";
ofstream writer("tejas.txt");         // create a function writer and tejas.txt is the name of the text file that I want to generate

if (! writer){
	cout << "Error opening the file" << endl;
	return -1;  // just to indicate if something went wrong in detecting and opening the file
} else {
	writer << stevequote << endl; // Give the information of what needs to be in tejas.txt
	writer.close();               // close the function after use
}

ofstream writer2("tejas.txt", ios::app);  // append to a already existing file
// ios::in to read a file 
// ios::trunc is the default
// ios::out open a file to write output
if (! writer2){
	cout << "Error opening the file" << endl;
	return -1;  // just to indicate if something went wrong in detecting and opening the file
} else {
	writer << "\n Hey how are you" << endl; // appends the information
	writer2.close();               // close the function after use
}

// Reading a file or reading every character of the stream untill the end of the file
// Read characters from a file using an input file stream
	ifstream reader("stevequote.txt");
 
	if(! reader){
		cout << "Error opening file" << endl;
		return -1;
	} else {
		// Read each character from the stream until end of file
		for(int i = 0; ! reader.eof(); i++){
			// Get the next letter and output it
			reader.get(letter);
			cout << letter;
		}
		cout << endl;
		reader.close();
}

/* Exception Handling in C++, the try and except functions */
int number = 0;
 
	try{                           // Used to Avoid potential errors
 
		if(number != 0){
			cout << 2/number << endl;
		} else throw(number);    // The throw here searches for the catch command.
 
	} 
	catch(int number){
 
		cout << number << " is not valid input" << endl;
 
	}

/* Pointers */ // - 40 Mins

int myage=23;          // Here int takes 4 bytes of memory
char letter = 'A';
cout << sizeof(myage); // 4 bytes
cout << sizeof(letter); // 1 byte
cout << "Myage is located at: " << &myage << endl; // address of myage returns - 0x7fff61de8948

// Clear example to use pointers

int myage = 48;
int* ageptr = &myage;
cout << "Address of the pointer" << ageptr << endl;       // Returns the address
cout << "Data at the memory address" << *ageptr << endl;  // Decodes the data value in that address

// Using pointers and address
int badnums[5] = {4, 13, 14, 24, 34};
int* numArrayaptr = badnums;
cout << "Address " << numArrayptr << "Value " << *numArrayptr << endl; // 0x7fff61de8948 4
numArrayptr++ // just to take the next element in the array
cout << "Address " << numArrayptr << "Value " << *numArrayptr << endl; // 0x7fff61de8952 13 // observe the 4 bytes difference in the address
// An Array name can be used as pointer to the array
cout << "Address " << badnums << "Value " << *badnums << endl; // First element 4 is printed again.


// Call by reference using pointers.

void makemeyoung(int* age){
	cout << "I used to be" << *age << endl; // use * to get the value. 
	*age = 21; // changing the values too.
	// dont return anything
}

int main(){
	makemeyoung(&myage);
	cout << "I am " << myage << "years old now" << endl;     // Output : I used to be 48 \n I am 21 years old now
// IMPORTANT - The variable changed in the function is globally changed now, Because it was changed based on adress and not name of the variable.
}
// When you pass a variable to a function you are passing the value
// When you pass a pointer to a function you are passing a reference
// that can be changed

//Use Pointers if you don't want to initialize at declaration, or if
// you need to assign another variable otherwise use a reference
 
/* Classes and Objects */

// Classes are the blueprints for modeling real world objects
// Real world objects have attributes, classes have members / variables
// Real world objects have abilities, classes have methods / functions, both mean the same.
// Classes believe in hiding data (encapsulation) from outside code

// after headers, using name space, declare class above the main part of the program.
class Animal{
   private: 
   int height;
   int weight;
   string name;
   
   static int numofAnimals; // This static variable can be used for every object in the class Animal ever created.
   	
   	public:     // able to access the values inside it 
   	int getHeight(){return height; }
   	int getWeight(){ return weight; }
   	string getName(){ return name;}
   	
   	void setHeight(int cm){height = cm;}
    void setWeight(int kg){weight = kg;}
   	void setHeight(string cm){height = cm;}
}
return 0;  // 0 stands for execution happening perfectly
}



