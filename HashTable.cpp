//============================================================================
// Name        : HashTable.cpp
// Author      : Marius Popescu
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
#include "HashTable.h"
using namespace std;


int main()
{
    HashMap hash;
    int key;
    int  elemKey;
    string value;
    int choice;
    while (1)
    {
    	cout << endl;
        cout<<"Chose [1] to add [2] to find how many times it is [3] to find if it is [4] to find the total number of collisions [5] to exit: "<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
        	for (int i = 0; i < 6; i++){
            cout<<"Enter element to be inserted: ";
            cin>>value;
            hash.Insert(value);
        }
            break;
        case 2:
            cout<<"Enter word to be searched: ";
            cin>>value;
            elemKey = hash.get(value);
            cout << "The number of words are: " << elemKey<<endl;
            break;
        case 3:
            cout<<"Enter word to search if it is in the file: ";
            cin>>value;
            if (hash.contains(value))
            	cout << "The entered word is in the file";
            else
            	cout << "The entered word is NOT in the file";
            break;
        case 4:
            cout << "Number of Collisions: " << hash.getCollisions();
            break;
        case 5:
            exit(1);
        default:
           cout<<"\nEnter correct option\n";
       }
    }
    return 0;
}
