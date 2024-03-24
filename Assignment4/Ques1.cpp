/*Q1. Stack is a Last-In-First-Out data structure. Write a Stack class. It implements stack using
Dynamically allocated array. Stack size should be passed in parameterized constructor. If size is not
given, allocate stack of size 5.
Provide member functions like push(), pop(), peek(), isEmpty(), isFull(), and print()*/

#include<iostream>
using namespace std;

class Stack
{ 
  int top;
  int size;
  int *ptr;
  
  public:
  
  Stack(int size = 5)
  {
    top=-1;
    this->size = size;
    ptr=new int[size];
    
  }


  void push(int val)
  {
    if(isFull())
    {
       cout<<"Stack is full"<<endl; 
    }
    else{
        top++;
        ptr[top]=val;
        cout<<"The pushed element :"<<ptr[top]<<endl;
    }

  }


  void pop()
  {
    if(isEmpty())
    cout<<"stack is Empty"<<endl;
    else
    { 
        cout<<"The popped element is "<<ptr[top]<<endl;
        top--;


    }
  }


  int peek()
  {
    if(isEmpty())
    cout<<"the stack is empty"<<endl;

    else
    {
       int x = ptr[top];
       return x;
    }
  }

  void print()
  {
    for(int i=size;i>=0; i--)
    {
      cout<<"stack is:"<<endl;
    cout<<" "<<endl;
    cout<<ptr[i]<<endl;
    
    }
  }

  bool isEmpty()
  {
    return top==-1;
  }


  bool isFull()
  {
    return top==(size-1);
  }
~Stack()
{
  delete[] ptr;
  ptr = NULL;
}

};
int main()
{
    Stack s1;
    int choice;
do{


    cout<<"0. EXIT "<<endl;
    cout<<"1.Push "<<endl;
    cout<<"2.Pop "<<endl;
    cout<<"3.Print "<<endl;
    cout<<"4.peek "<<endl;
    cout<<"Enter the choice"<<endl;
    cin>>choice;
    

    switch (choice)

    {
        case 0:
           cout<<" EXIT "<<endl;
           break;
        
        case 1:
        int value;
        cout<<"Enter the value for push"<<endl;
        cin>>value;
           s1.push(value);
           break;
        
        case 2:
          s1.pop();
          break;

        case 3:
        s1.print();
        break;

        case 4:
        cout<<"the cuurent element is :"<<s1.peek()<<endl; 
        break;

        default:
        cout<<"wrong choice"<<endl;
        break;

        

    }
}while(choice!=0);
  return 0;
}
