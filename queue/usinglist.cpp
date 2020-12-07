#include<bits/stdc++.h> 
using namespace std;
struct node{
    node *link;
    int data;
    node(int value){
        data=value;
    }
};
struct Queue_
{
    node* front=NULL;
    node* rear=NULL;
    void push(int value);
    void pop();
    void clear();
    int enqueue();
    void display();
};
void Queue_::push(int value)
{
    if(front==NULL){
        front=new node(value);
        rear=front;
    }
    else {
        node *next=new node(value);
        rear->link=next;
        rear=next;
    }
    display();
}
void Queue_::pop()
{
   if(front==NULL) cout<<"empty";
   else if(front==rear) front=rear=NULL;
   else{
       node* remove_now=front;
       front=front->link;
       delete remove_now;
   }
}
int Queue_::enqueue()
{   
   return front->data;
}
void Queue_::clear()
{
  front=rear=NULL;
}
void Queue_::display()
{
    node *index=front;
    while(index!=NULL){
        cout<<index->data<<" ";
        index=index->link;
    }
    cout<<endl;
}
int main()
{
    Queue_* que = new Queue_();
    que->push(1);
    que->push(2);
    que->pop();
    que->push(3);
    que->push(4);
    que->pop();
    que->push(5);
    que->push(6);
    que->pop();
    que->push(7);
    que->push(8);
    que->pop();
    que->push(9);
    que->push(10);
    return 0;
}