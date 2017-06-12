//============================================================================
// Name        : BinaryTree.cpp
// Author      : Marius Popescu
// Description : This is a binary tree, the function is AVL will check if this
// tree is a AVL tree.
//============================================================================

#include <iostream>
#include <cstdlib>
#include "BinarySearchTree.h"


int main()
{
    BinarySearchTree tree;
    int ch,tmp,tmp1;
    while(1)
    {
       cout <<endl;
       cout<<" Chose one option: "<<endl;
       cout<<" [1]-Insertion/Creation [2]-In-Order Traversal [3]-Pre-Order Traversal [4]-Post-Order Traversal [5]-Removal [6]-isAVL? [7]-Exit "<<endl;
       cin>>ch;
       switch(ch)
       {
           case 1 : cout<<" Enter Numbers to be inserted/ -99 lo exit : ";
                   do{
           	   	   	cin>>tmp;
           	   	   	if(tmp != -99)
                    tree.insert(tmp);
                   }
                    while (tmp != -99);
                    break;
           case 2 : cout<<endl;
                    cout<<" ----------In-Order Traversal-------- "<<endl;
                    tree.print_inorder();
                    break;
           case 3 : cout<<endl;
                    cout<<" ----------Pre-Order Traversal-------- "<<endl;
                    tree.print_preorder();
                    break;
           case 4 : cout<<endl;
                    cout<<" ----------Post-Order Traversal-------- "<<endl;
                    tree.print_postorder();
                    break;
           case 5 : cout<<" Enter data to be deleted : ";
                    cin>>tmp1;
                    tree.remove(tmp1);
                    break;
           case 6 : if(tree.isAVL())
                    	cout << "This tree is an AVL tree!!!";
                    else
                    	cout << "This tree is NOT an AVL tree!";
                    break;
           case 7 : system("pause");
                    return 0;
                    break;
       }
    }
}
