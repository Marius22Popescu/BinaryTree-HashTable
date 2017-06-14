//============================================================================
// Name        : HashTable.cpp
// Author      : Marius Popescu
// Description : This program will count the number of collisions from a text file
// and it use a hash table
//============================================================================

#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
#include <fstream>
#include "HashTable.h"
using namespace std;


int main()
{
    HashMap hash;
    int  elemKey;
    string value;
    int choice;

    // Open the file and read in the hash table
    ifstream myfile;
    	myfile.open("wordCounting.txt");
    	if (myfile.is_open()) {
    		while (!myfile.eof())
    		{
    			myfile >> value;
    			hash.add(value);
    		}
    	}
    	else
    		cout << "file does not open";
    	myfile.close();

    	cout << "Number of Collisions: " << hash.getCollisions();
    	//The collisions in the "wordCounting.txt" are at the words:
    	//AND, BE, STRING, CONTAINING; and all was found two times each


    	//IF YOU NEED A MENIU TO TEST: int get(const string& value), bool contains(const string& str) FUNCTONS
    	//RELEASE THE FOLLOWING CODE:


   /*****
    while (1)
    {
    	cout << endl;
        cout<<"Chose [1]-to find how many times it is [2]-to find if it is [3]-to find the total number of collisions [4]-to exit: "<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter word to be searched: ";
            cin>>value;
            elemKey = hash.get(value);
            cout << "The number of words are: " << elemKey<<endl;
            break;
        case 2:
            cout<<"Enter word to search if it is in the file: ";
            cin>>value;
            if (hash.contains(value))
            	cout << "This word is in the file!";
            else
            	cout << "This word is NOT in the file!";
            break;
        case 3:
            cout << "Number of Collisions: " << hash.getCollisions();
            break;
        case 4:
            exit(1);
        default:
           cout<<"\nEnter correct option\n";
       }
    }
    ****/

    return 0;
}
