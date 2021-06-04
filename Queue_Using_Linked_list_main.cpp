#include <iostream>

using namespace std;
class node
{  public:
    int data;
    class node*next;
}*front_,*rear,*temp,*new_;


void display()
{ cout<<"\n--------------------------------------"<<endl;
    if(front_==0)
{
    cout<<"The queue is empty "<<endl;
}else
 {  temp=front_;
    while(temp!=0)
    {
    cout<<temp->data<<" -> ";
    temp=temp->next;
    }
    cout<<"\n"<<endl;
 }

}


void enque()
{ int value;
cout<<"Enter the value to add :- ";
cin>>value;
new_=(class node*)malloc(sizeof(class node*));
new_->data=value;
new_->next=0;
if(front_==0)
{
    front_=new_;
    rear=new_;
}else
{   cout<<"\n:"<<value<<" added at the end of queue "<<endl;
    rear->next=new_;
    rear=new_;
}
display();
}



void dequeue()
{
    if(front_==0)
    {
        cout<<"Underflow condition"<<endl;
    }else
    {   cout<<"\n"<<front_->data<<" is deleted from front of queue "<<endl;
        front_=front_->next;
        display();
    }

}

void Count()
{
    int sum=0;
    temp=front_;
    while(temp!=0)
    {
        sum++;
        temp=temp->next;
    }
    cout<<"Total no of elements in your queue = "<<sum<<"\n"<<endl;
}

int main()
{
    int i,exit=0,choice,n,value;
    cout<<"Enter the no of elements in your initial queue "<<endl;
    cin>>n;
    cout<<"Enter the value's"<<endl;
    for(i=0;i<n;i++)
    {  cin>>value;
        new_=(class node*)malloc(sizeof(class node*));
        new_->data=value;
        new_->next=0;
        if(front_==0)
        {
            front_=new_;
            rear=new_;
        }else
        {
            rear->next=new_;
            rear=new_;
        }
    }
    display();
     cout<<"\n------------------------------------------"<<endl;
     cout<<"To add an element at the rear of queue press :- 1 "<<endl;
     cout<<"To delete the element from the front of queue press :- 2 "<<endl;
     cout<<"To print the size of your current queue  press :- 3 "<<endl;
     cout<<"To Print the final queue elements and exit press :- 4"<<endl;
     cout<<"---------------------------------------------\n"<<endl;
     while(exit!=1)
     {
         cout<<"Enter your choice :- ";
         cin>>choice;
         cout<<"\n"<<endl;
         switch (choice)
         {
             case 1:{enque();}
             break;
             case 2:{dequeue();}
             break;
             case 3:{Count();}
             break;
             case 4:{display();
                    cout<<"Thank u and good bye "<<endl;
            exit=1;}
             break;
             default:{cout<<"Enter the correct choice please "<<endl;}
         }
     }

    return 0;
}
