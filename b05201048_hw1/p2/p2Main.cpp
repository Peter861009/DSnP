/****************************************************************************
  FileName     [ p2Main.cpp ]
  PackageName  [ p2 ]
  Synopsis     [ Define main() function ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2016-present DVLab, GIEE, NTU, Taiwan ]
****************************************************************************/
#include <iostream>
#include <string>
#include "p2Json.h"

using namespace std;

int main()
{
   Json json;

   // Read in the csv file. Do NOT change this part of code.
   string jsonFile;
   cout << "Please enter the file name: ";
   cin >> jsonFile;
   if (json.read(jsonFile))
      cout << "File \"" << jsonFile << "\" was read in successfully." << endl;
   else {
      cerr << "Failed to read in file \"" << jsonFile << "\"!" << endl;
      exit(-1); // jsonFile does not exist.
   }

   // TODO read and execute commands
   cout << "Enter command: ";
   while (true) {
      string command;
      cin >> command;
      cout << "Enter command: ";
      if (command=="PRINT")
         json.print();
      if (command=="ADD"){
         string key;
         int value;
         cin >> key >> value;
         json.add(key, value);
      }
      if (command=="AVE")
         json.ave();
      if (command=="MAX")
         json.max();
      if (command=="MIN")
         json.min();
      if (command=="SUM")
         json.sum();
      if (command=="EXIT")
         return false;   
    }
}
