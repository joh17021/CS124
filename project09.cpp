/***********************************************************************
* Program:
*    Project 09, Mad Lib        
*    Brother Cook, CS124
* Author:
*    Rachel Johnson      
* Summary: 
*    My program prompts the user for a mad lib, prompts them to fill 
in the information, and displays the completed mad lib.
*
*    Estimated:  1.0 hrs   
*    Actual:     6.0 hrs
*      The most difficult part was inserting the user input into
the mad lib.
************************************************************************/
 
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <ctime>
#include <fstream>
#include <string.h>
using namespace std;

#define DEBUG true

void getFileName(char fileName[])
{
   if(DEBUG) cout << "Starting the program" << endl;
   cout << "Please enter the filename of the Mad Lib: ";
   cin >> fileName;
   if(DEBUG) 
      cout << "You opened the file: " << fileName << endl;
}

void promptUser(char text[], int count)
{
   cout << "\t" << (char)toupper(text[1]);

   for (int i = 2; text[i] != '>'; i++)
   {
      if (text[i] == '_')   
         cout << " ";
      else
      {
         cout << (char)tolower(text[i]);
      }
   }
   cout << ": ";                                    
   if (count == 0)
   {
      cin.ignore();
      cin.getline(text,256);
   }
   else if(count > 0)
      cin.getline(text,256);
   
   return;
}

void convertPunctuation(char punctuation[])
{   
   {
      switch (punctuation[1])
      {
         case '#':
            punctuation[0] = '\n';
            punctuation[1] = '\0';
         case '{':
            punctuation[0] = ' ';
            punctuation[1] = '\"';
            punctuation[2] = '\0';
         case '}':
            punctuation[0] = '\"';
            punctuation[1] = ' ';
            punctuation[2] = '\0';
         case '[':
            punctuation[0] = ' ';
            punctuation[1] = '\'';
            punctuation[2] = '\0';
         case ']':
            punctuation[0] = '\'';
            punctuation[1] = ' ';
            punctuation[2] = '\0';
      }        
   }  
   return; 
}

int readFile(char fileName[], char madLib[][32])
{
   ifstream fin(fileName);

   if (fin.fail())
      return -1; 
   int count = 0;
   int numWords = 0;
   while (numWords < 256 && fin >> madLib[numWords])  
   {
      if (madLib[numWords][0] == '<' && isalpha(madLib[numWords][1]))
      {
         promptUser(madLib[numWords], count);
         count++;
      }
      else if (madLib[numWords][0] == '<' && !isalpha(madLib[numWords][2]))
         convertPunctuation(madLib[numWords]);
      numWords++;
   }
   fin.close();
   
   return numWords; 
}

/******************************************************************************
 */
 
void display (char madLib[][32], int numWords)   
{
   for (int i = 0; i < numWords; i++)
   {  
      if (i == 0)
         cout << madLib[i];
      else if (madLib[i][0] == '.' || madLib[i][0] == ',')
         cout << madLib[i];
   }
}

int main()
{
   char fileName[256];
   char madLib[256][32];
   char punctuation[256];
  
   getFileName(fileName);
   
   int numWords = readFile(fileName, madLib);

   if (numWords == -1)
      cout << "Unable to open file " << fileName << endl;
   else 
       {
          // display(madLib, numWords);
       cout << "Thank you for playing." << endl;
       }
   return 0;   
}
