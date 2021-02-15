#include <iostream>
#include <string> 
#include <cstring> 
#include <vector>
#include <locale>

void menu();
void copyToVect();
void paliCheck();

using namespace std;

char phrase[80] = { 0 };
vector<char> paliVect;
bool isPal;
bool testingPali = true;
string userInput;

//main function simply calls the menu which in turn calls the other functions
//the instructions said we could assume the input contains only letters and spaces so i did not catch any exceptions for non letters and spaces - however....
//the program works with all characters, symbols, integers greater than 0 and any space variation
int main()
{		
	menu();
}

//menu that asks the user to enter a string
void menu() 
{	
	while (testingPali)
	{
		//asks the user to input a string
		cout << "This program tests if a word/phrase is palindrome. " << endl;
		cout << "Please enter your phrase (just letters and blanks, please): " << endl;

		//stores the entire string
		cin.getline(phrase, sizeof(phrase));

		//calls copy to vector function
		copyToVect();

		break;		
	}
}
//copys the input stream from the menu into a vector
void copyToVect()
{
	for (int i = 0; i < 80; i++)
	{
		//copies only non space non zero characters
		if (phrase[i] != 0 && phrase[i] != ' ')
		{
			paliVect.push_back(tolower(phrase[i]));			
		}		
	 }
	//calls funtion to check if its a pali
	paliCheck();
}

//checks if the input is a palindrome
void paliCheck()
{
	//sets k to the last index of the vector
	int k = paliVect.size()-1;	
		
	//for loop searches the string to make sure the characters are equal
	for (int j = 0; j < paliVect.size(); j++)
	{
		if (paliVect.size() <= 0)
		{				
			isPal = false; 			
			break;
		}
		//if the first and last characters match the program continues to increment
		else if (paliVect[j] == paliVect[k])
		{			
			//decrements k			
			k--;
		}
		//if the characters dont match bool is set to false;
		else
		{
			isPal = false;
			break;
		}
		isPal = true;
	}
	//prints this if bool is true
	if (isPal == true)
	{
		cout << "Yes, the phrase is a palindrome! " << endl;	
	}
	//prints this if bool is false
	if (isPal == false)
	{
		cout << "No, the phrase is not a palindrome! " << endl;		
	}
}

 