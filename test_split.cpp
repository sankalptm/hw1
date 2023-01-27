/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{

Node* head= new Node(5, nullptr);
Node* temp=new Node(6, nullptr);
head->next=temp;
Node* evens =nullptr;
Node* odds =nullptr;
Node* temp2=head;
while (temp2){
  cout<<temp2->value<<endl;
  temp2=temp2->next;
}
split(head, odds, evens);



}
