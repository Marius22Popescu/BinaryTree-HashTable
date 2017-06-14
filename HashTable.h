/*
 * HashTable.h
 *
 *  Created on: Jun 11, 2017
 *      Author: Marius
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <iostream>
#include <string>
using namespace std;
const int TABLE_SIZE = 10000;

//HashNode Class Declaration
class HashNode
{
    public:
       int key;
       string value;
       HashNode* next;
       HashNode(int key, string value){
        this->key = key;
	    this->value = value;
	    this->next = NULL;
        }
};

//HashMap Class Declaration
class HashMap
{
    private:
        HashNode** htable;
        int collisions = 0;
    public:
        HashMap(){
            htable = new HashNode*[TABLE_SIZE];
            for (int i = 0; i < TABLE_SIZE; i++)
                htable[i] = NULL;
        }
        ~HashMap(){
            for (int i = 0; i < TABLE_SIZE; ++i){
                HashNode* entry = htable[i];
                while (entry != NULL){
                    HashNode* prev = entry;
                    entry = entry->next;
                    delete prev;
                }
            }
            delete[] htable;
        }
        //Hash Function

        int setKey(const string & key){
        	int result = 0;
        	int length = key.size();
        	for (int i = 0; i < length; i++){
        		result = result + (27*i + 1)*key[i];
        	}
        	return result%TABLE_SIZE;
        }

        //Insert Element at a key
        void Insert(string value){
            int hash_val = setKey(value);
            HashNode* prev = NULL;
            HashNode* entry = htable[hash_val];
            while (entry != NULL){
                prev = entry;
                entry = entry->next;


            }
            if (entry == NULL){
                entry = new HashNode(hash_val, value);
                if (prev == NULL){
                    htable[hash_val] = entry;
                }
	        else{
                    prev->next = entry;
                    collisions++;
                }
            }
            else{
                entry->value = value;
            }
        }
        // Search Element at a key
        int get(string value){
            int hash_val = setKey(value);
            HashNode* entry = htable[hash_val];
            int count = 0;
            while (entry != NULL){
                if (entry->key == hash_val){
                    count ++;
                }
                entry = entry->next;
            }
                return count;
        }

        //Returns if the word is in the file
        bool contains(string str){
        	int ans = get(str);
        	if (ans == 0)
        		return true;
        	else
        		return false;
        }

        //Return collisions
        int getCollisions (){
        	return collisions;
        }
};

#endif /* HASHTABLE_H_ */
