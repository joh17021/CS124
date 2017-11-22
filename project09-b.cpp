#include <iostream>
#include <fstream>
#include <string.h>

#define ERROR 1
#define DEBUG true
#define STRING_SIZE 256

using namespace std;

//Function prototypes
void getFileName(char []);
void readFile(char[], char[]);
void printOutput(char[]);

int main()
{
   //Read in file from the user
   char fileName[STRING_SIZE];
   char output[STRING_SIZE];
   getFileName(fileName);
   //Parse file
   readFile(fileName, output);
   //Print resulting madlib
   printOutput(output);
   return 0;
}

//Get fileName from user
//Parameter: fileName: The variable that the fileName will be saved to
void getFileName(char fileName[])
{
   if(DEBUG) cout << "Starting the program" << endl;
   cout << "Please enter the filename of the Mad Lib: ";
   cin >> fileName;
   if(DEBUG) 
      cout << "You opened the file: " << fileName << endl;
}

//Opens file and parse contents
//Replaces words in <> with user input
//Param fileName: file to parse input
//Param output: MadLib with replaced words
void readFile(char fileName[], char output[])
{
   bool seen_chevron = false;
   int numChar = 0;
   char letter;
   char madlibPrompt[STRING_SIZE];
   char userInput[STRING_SIZE];

   ifstream fin(fileName);
   if (fin.fail())
   {
      cout << "Error reading file: " << fileName << endl;
      throw ERROR;
   }

   //Look at eah char && if letter is < then save it in the madlibPrompt
   //until you see a >. After the '>', prompt the user for that variable
   //Save user input to output string
   while (numChar < STRING_SIZE && fin >> letter)  
   {
      if(DEBUG) cout << "Looking at char " << letter << endl;

      //Start builing the madlib prompt
      if (seen_chevron)
      {
         //prompt the usere with the madldib prompt and save inupt to output string
         if (letter == '>')
	 {
	    seen_chevron = false;
	    if (DEBUG) cout << "Seen right chevron" << endl;
	    //TODO If the length of the madlibPrompt is 1, then check if it is one of the
	    //special characters
	    //TODO if the prompt is one of the special chracters, then don't prompt user
	    //just swap it out for what it needs to be
	    cout << madlibPrompt << ": ";
	    cin >> userInput;
	    //TODO add userinput to output
	    memset(madlibPrompt, 0, STRING_SIZE);
	 }

	 else
         {
	    strncat(madlibPrompt, &letter, 1);
	 }
      }
      else // not seen chevron
      {
         if (letter == '<')
	 {
	    //Assuming there will not be nested chevrons
	    if (DEBUG) cout << "Seen left chevron" << endl;
	    seen_chevron = true;
	 }
	 //save character to output
	 else
	 {
	    strncat(madlibPrompt, &letter, 1);
	 }
      }
   }
	fin.close();
}

void printOutput(char output[])
{
   cout << output;
}
