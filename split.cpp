/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/
//#include <iostream>
#include "split.h"
#include <cstddef>
using namespace std;
/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
// identify first Node in the Linked List 
//use the value in the first value in the Node object
//determine whether that value is odd or even
//add that value to the corresponding linked list
//delete first node from the original list 
//call split function again
  //don't allocated new memory but just change the pointers
  if (in==NULL){
    odds=NULL;
    evens=NULL;
    in=NULL;
    return; 
  } 
  split (in->next, odds, evens);
  int current =in->value;
  if (current % 2==0){
    //Node* temp=in;
    in->next=evens;
    evens=in;
   
    
    
  }
  else {
    //push_back(odds, current); 
    in->next=odds;
    odds=in;
    
    
  }
  in=NULL;
  
}

//confused on how to test and submit
/* If you needed a helper function, write it here */
