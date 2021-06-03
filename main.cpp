#include <iostream>

using namespace std;
class node //Class declaration//
{ public:
    int data;
    class node*next;
}*top,*temp,*new_;

void display()//Display Function//
{ temp=top;
  cout<<"\n---------------"<<endl;
    while(temp->next!=0)
    {
        cout<<temp->data<<endl;
        cout<<" "<<endl;
        temp=temp->next;
    }
    cout<<temp->data<<endl;
}
void push()//Functioning and declaration op push function//
{
    int value ;
    cout<<"\nEnter the data to add at top of stack"<<endl;
    cin>>value;
    new_=(class node*)malloc(sizeof(class node*));
    new_->data=value;
    new_->next=0;
    if(top==0)
    {
        top=new_;
    }else{
    new_->next=top;
    top=new_;
    }
    display();
}
void pop()
{
    if(top==0)
    {
        cout<<"\nunderflow"<<endl;
    }else
    {
        top=top->next;
    }
    display();
}
void Count()
{   int sum=0;
    temp=top;
    while(temp->next!=0)
    {
        sum++;
        temp=temp->next;
    }
    cout<<"\nNo of elements in the stack = "<<sum++<<endl;
}

int main()
{ int n,exit=0,i,choice;
    cout<<"Enter the elements in your initial stack "<<endl;
    cin>>n;
    cout<<"Enter the elements "<<endl;
    for(i=0;i<n;i++)
    { int value;
    cin>>value;
        new_=(class node*)malloc(sizeof(class node* ));
        new_->data=value;
        new_->next=0;
        if(top==0)
        {
         top=new_;
        }else{
            new_->next=top;//ADDING NEW ELEMENTS A THE START OF TRHE LINKED LIST//
            top=new_;
        }
    }
    cout<<"\n\n------------------------------------------------------------\n"<<endl;
    cout<<"To add an element at top of stack press :- 1\n"<<endl;
    cout<<"To Delete the element from the top of stack press :- 2\n"<<endl;
    cout<<"To count the no elements in  stack press :- 3\n"<<endl;
    cout<<"To display all the elements in the stack and exit press :- 4\n"<<endl;
    cout<<"\n\n------------------------------------------------------------\n"<<endl;

    while(exit!=1)
    { cout<<"\nEnter the Choice : ";
      cin>>choice;
        switch (choice) {
         case 1:{ push();
         }break;
         case 2:{  pop();
         }break;
         case 3:{ Count();
         }break;
         case 4:{ display();
                 exit=1;
                 cout<<"\nThank u and Bye :)"<<endl;
         }break;
                     }
    }
    return 0;
}
