#include <iostream>
#include <fstream>

#define ERROR 1
#define DEBUG true
#define STRING_SIZE 256

using namespace std;

//Function prototypes
void getFileName(char []);
void readFile(char[], char[]);

int main()
{
   //Read in file from the user
   char fileName[STRING_SIZE];
   char output[STRING_SIZE];
   getFileName(fileName);
   //Parse file
   readFile(fileName, output);
   //Print resulting madlib
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
   int numChar = 0;
   char letter;
   char madlibPrompt[STRING_SIZE];

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
   }
fin.close();
}

