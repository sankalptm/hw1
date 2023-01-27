#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream> // delete this later

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

void ULListStr::push_back(const std::string& val){
  //empty list
  if (head_==NULL && tail_ == NULL){
    Item* temp=new Item;
    temp->val[0]=val;
    //temp->first=0;
    temp->last++;
    head_=temp;
    tail_=temp;
    size_++;
  }
  //partial list 
  else {
    if (tail_->last==ARRSIZE){
      Item* temp=new Item;
      temp->val[0]=val;
      //temp->first=0;
      temp->last=1;
      tail_->next=temp;
      temp->prev= tail_;
      temp->next = NULL;
      tail_=temp;
      size_++;

    }
    else{
      tail_->val[tail_->last]=val;
      tail_->last++;
      size_++;
    }
  }
  
 /* if (head_==NULL){
    //save value
    //check if array is full before creating new Item
    Item* temp=new Item;
    temp->val= val;
    temp->first=0;
    temp->last=ARRSIZE;
    head_=temp;
    tail_=temp;
  }
  else {
    Item* temp=new Item;
    temp->val=val;
    temp->first=0;
    temp->last=ARRSIZE;
    temp->next=NULL;
    tail_->next= temp;
    temp->prev=tail_;
    tail_=temp;

  }*/
}
void ULListStr::push_front(const std::string& val){
  //empty list
  if (head_==NULL && tail_ == NULL){
    Item* temp=new Item;
    temp->val[0]=val;
    temp->first=0;
    temp->last=1;
    head_=temp;
    tail_=temp;
    size_++;

  }
  //partial list
  else{
    if (head_->first==0){
      Item* temp=new Item;
      temp->val[ARRSIZE-1]=val;
      temp->first= (ARRSIZE -1);
      temp->last=ARRSIZE;
      head_->prev=temp;
      temp->next= head_;
      head_=temp;
      head_->prev = NULL;
      size_++;
    }
    else{
      int position = (head_->first - 1);
      head_->val[position]=val;
      head_->first = position;
      size_++;
    }
  }
  
  
  /*if (head_==NULL){
    Item* temp=new Item;
    //save value 
    temp->val=val;
    temp->first=0;
    temp->last=ARRSIZE;
    head_=temp;
    tail_=temp;
  }
  else {
    Item* temp=new Item;
    temp->val=val;
    temp->first=0;
    temp->last=ARRSIZE;
    temp->next=head;
    head_->prev=temp;
    head_=temp;
  }
  size_++;
  */
}
void ULListStr::pop_front(){
if (head_==NULL && tail_==NULL){
  return;
  //just move last and first for pop functions
}
else if(head_==tail_) {
  head_->first++;
  size_--;
}
else {
  if (head_->first==ARRSIZE-1){
    Item* temp=head_;
    head_=head_->next;
    head_->first=0;
    head_->last=ARRSIZE;
    size_--;
    delete temp;
  }
  else {
    head_->first++;
    size_--;
  }
  /*Item* temp=head_;
  head_=head_->next;
  head_->first++;
  size_--;
  delete temp;*/
  
}

}
void ULListStr::pop_back(){
  if (head_==NULL && tail_==NULL){
    return;
  }
  else if (head_==tail_){
    tail_->last--;
    size_--;
  }
  else{
    if (tail_->last==0){
    Item* temp=tail_;
    tail_=tail_->prev;
    tail_->first=0;
    tail_->last=ARRSIZE;
    size_--;
    delete temp;
  }
  else {
    tail_->last--;
    size_--;
  }
    /*Item* temp=tail_;
    tail_=tail_->prev;
    tail_->last--;
    size_--;
    delete temp;*/
    
  }
  
}
std::string const &ULListStr::back() const{
  return tail_->val[tail_->last-1];
}
std::string const &ULListStr::front() const{
  return head_->val[head_->first];
}

std::string* ULListStr:: getValAtLoc(size_t loc) const{
  Item* temp= head_;
  if (loc>= size_){
    return NULL;
  }
  
  while (temp->last-temp->first <=loc){
   loc=loc-(temp->last-temp->first);
   temp=temp->next; 
  }
  return &(temp->val[loc+temp->first]);

  
}

