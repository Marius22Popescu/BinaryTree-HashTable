/*
 * BinarySearchTree.h
 *
 *  Created on: Jun 10, 2017
 *      Author: Marius Popescu
 */

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include <iostream>
#include <assert.h>

using namespace std;

class BinarySearchTree
{
    private:
        struct tree_node
        {
           tree_node* left;
           tree_node* right;
           int data;
        };
        tree_node* root;
    public:
        BinarySearchTree()
        {
           root = NULL;
        }
        bool isEmpty() const { return root==NULL; }
        void print_inorder();
        void inorder(tree_node*);
        void print_preorder();
        void preorder(tree_node*);
        void print_postorder();
        void postorder(tree_node*);
        void insert(int);
        void remove(int);
        bool isAVL();
        bool isAVLtree(tree_node*);
        int max(int a, int b);
        int height(tree_node*);

};

// Smaller elements go left
// larger elements go right
void BinarySearchTree::insert(int d)
{
    tree_node* t = new tree_node;
    tree_node* parent;
    t->data = d;
    t->left = NULL;
    t->right = NULL;
    parent = NULL;
  // If is a new tree
  if(isEmpty()) root = t;
  else
  {
    //Note: ALL insertions are as leaf nodes
    tree_node* curr;
    curr = root;
    // Find the Node's parent
    while(curr)
    {
        parent = curr;
        if(t->data > curr->data) curr = curr->right;
        else curr = curr->left;
    }

    if(t->data < parent->data)
       parent->left = t;
    else
       parent->right = t;
  }
}

void BinarySearchTree::remove(int d)
{
    //Locate the element
    bool found = false;
    if(isEmpty())
    {
        cout<<" This Tree is empty! "<<endl;
        return;
    }
    tree_node* curr;
    tree_node* parent;
    curr = root;
    while(curr != NULL)
    {
         if(curr->data == d)
         {
            found = true;
            break;
         }
         else
         {
             parent = curr;
             if(d>curr->data) curr = curr->right;
             else curr = curr->left;
         }
    }
    if(!found)
		 {
        cout<<" Data not found! "<<endl;
        return;
    }


		 // 3 cases :
    // 1. We're removing a leaf node
    // 2. We're removing a node with a single child
    // 3. we're removing a node with 2 children

    // Node with single child
    if((curr->left == NULL && curr->right != NULL)|| (curr->left != NULL && curr->right == NULL))
    {
       if(curr->left == NULL && curr->right != NULL)
       {
           if(parent->left == curr)
           {
             parent->left = curr->right;
             delete curr;
           }
           else
           {
             parent->right = curr->right;
             delete curr;
           }
       }
       else // left child present, no right child
       {
          if(parent->left == curr)
           {
             parent->left = curr->left;
             delete curr;
           }
           else
           {
             parent->right = curr->left;
             delete curr;
           }
       }
     return;
    }

		 //We're looking at a leaf node
		 if( curr->left == NULL && curr->right == NULL)
    {
        if(parent->left == curr) parent->left = NULL;
        else parent->right = NULL;
		 		 delete curr;
		 		 return;
    }


    //Node with 2 children
    // replace node with smallest value in right subtree
    if (curr->left != NULL && curr->right != NULL)
    {
        tree_node* chkr;
        chkr = curr->right;
        if((chkr->left == NULL) && (chkr->right == NULL))
        {
            curr = chkr;
            delete chkr;
            curr->right = NULL;
        }
        else // right child has children
        {
            //if the node's right child has a left child
            // Move all the way down left to locate smallest element

            if((curr->right)->left != NULL)
            {
                tree_node* lcurr;
                tree_node* lcurrp;
                lcurrp = curr->right;
                lcurr = (curr->right)->left;
                while(lcurr->left != NULL)
                {
                   lcurrp = lcurr;
                   lcurr = lcurr->left;
                }
		 		 		 		 curr->data = lcurr->data;
                delete lcurr;
                lcurrp->left = NULL;
           }
           else
           {
               tree_node* tmp;
               tmp = curr->right;
               curr->data = tmp->data;
		 		 		    curr->right = tmp->right;
               delete tmp;
           }

        }
		 return;
    }

}

void BinarySearchTree::print_inorder()
{
  inorder(root);
}

void BinarySearchTree::inorder(tree_node* p)
{
    if(p != NULL)
    {
        if(p->left) inorder(p->left);
        cout<<" "<<p->data<<" ";
        if(p->right) inorder(p->right);
    }
    else return;
}

void BinarySearchTree::print_preorder()
{
  preorder(root);
}

void BinarySearchTree::preorder(tree_node* p)
{
    if(p != NULL)
    {
        cout<<" "<<p->data<<" ";
        if(p->left) preorder(p->left);
        if(p->right) preorder(p->right);
    }
    else return;
}

void BinarySearchTree::print_postorder()
{
  postorder(root);
}

void BinarySearchTree::postorder(tree_node* p)
{
    if(p != NULL)
    {
        if(p->left) postorder(p->left);
        if(p->right) postorder(p->right);
        cout<<" "<<p->data<<" ";
    }
    else return;
}

// returns maximum of two integers
int BinarySearchTree::max(int a, int b)
{
  return (a >= b)? a: b;
}

/*  The function Compute the "height" of a tree. Height is the
    number of nodes along the longest path from the root node
    down to the farthest leaf node.*/
int BinarySearchTree::height(tree_node* p)
{
   // base case tree is empty
   if(p == NULL)
       return 0;

   // If tree is not empty then height = 1 + max of left height and right heights
   return 1 + max(height(p->left), height(p->right));
}

bool BinarySearchTree::isAVL()
{
	isAVLtree(root);
}
bool BinarySearchTree::isAVLtree(tree_node* p)
{
   int lh; // for height of left subtree
   int rh; // for height of right subtree

   // If tree is empty then return true
   if(p == NULL)
    return 1;

   // Get the height of left and right sub trees
   lh = height(p->left);
   rh = height(p->right);

   if( abs(lh-rh) <= 1 && isAVLtree(p->left) && isAVLtree(p->right))
     return 1;

   // If we reach here then tree is not height-balanced
   return 0;
}

#endif /* BINARYSEARCHTREE_H_ */
