#include <iostream>//Program to implement Priority Queue using Linked list//

using namespace std;
class node
{  public:
    int data;
    class node *next;
}*head,*tail,*new_,*temp;

void Display()
{  cout<<"\n---------------"<<endl;
    if(head==0)
    {
        cout<<"\nNo elements  in queue "<<endl;

    }else
    { temp=head;
        while(temp!=0)
        {
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
    }
    cout<<"\n---------------"<<endl;
}
int  Count()
{
    int sum=0;
    if(head==0)
    {
        return 0;
    }else
    {
        temp=head;
        while(temp!=0)
        {
            sum++;
            temp=temp->next;
        }

        return sum;
    }

}

void Insert()//Time complexity  of insertion is O(n)//
{
    int i,value;
    new_ =(class node*)malloc(sizeof(class node *));
    cout<<"Enter the value you want to add :- ";
    cin>>value;
    new_->data=value;
    new_->next=0;
     if(head==0)
     {
         head=new_;
         tail=new_;
     }else
     {
         i=value;

         if(i<=(head->data))
         {
             new_->next=head;
             head=new_;
         }else if(i<tail->data)
         {
             temp=head;
         while((i>=(temp->next->data))&&(temp->next!=0))
         { cout<<i<<" is greater than "<<head->data<<endl;
             temp=temp->next;

         }
         new_->next=temp->next;
         temp->next=new_;

         }
         else
         {
             tail->next=new_;
             tail=new_;
         }
     }

     Display();

}
void delete_highest()//Time complexity of Deletion is O(1),//
{ if(Count()>1){ //  But here I tried to use both min-priority and highest-priority queue together//
    cout<<"Deleting highest priority element : "<<tail->data<<endl;
    temp=head;
    while(temp->next!=tail)
    {
        temp=temp->next;
    }
    temp->next=0;
    tail=temp;
    Display();
}else if(Count()==1)
{
     cout<<"Deleting highest priority element : "<<tail->data<<endl;
     head=0;
     tail=0;
}else{
    cout<<"\nXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
    cout<<"Underflow condition "<<endl;
    cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXX\n"<<endl;
}
}
void delete_lowest()//Time complexity of Deletion is O(1),//
{
    if(Count()>1)
   {cout<<"Deleting the Lowest priority element : "<<head->data<<endl;
    temp=head->next;
    head->next=0;
    head=temp;
    Display();
   }else if(Count()==1){
     cout<<"Deleting lowest priority element : "<<head->data<<endl;
     head=0;
     tail=0;
}else{
       cout<<"\nXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
       cout<<"Underflow condition "<<endl;
       cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXX\n"<<endl;
   }
}
void peek()
{
    cout<<"Current Highest priority element = "<<tail->data<<"\nCurrent Lowest priority element = "<<head->data<<endl;
}


int main()
{ int i,n,choice,exit=0,k;
cout<<"Enter the initial no of elements in priority queue :- ";
cin>>n;
cout<<"\n";

for(i=0;i<n;i++)
{
    Insert();
}

   cout<<"\n----------------------------------------------------------------"<<endl;
   cout<<"To add an element in priority queue press :- 1 "<<endl;
   cout<<"To delete the element with highest vale press :- 2 "<<endl;
   cout<<"To delete the element with lowest vale press :- 3 "<<endl;
   cout<<"To print the greatest and smallest value press :-4 "<<endl;
   cout<<"To count the no of elements in your queue pres :- 5 "<<endl;
   cout<<"To print all the elements and exit press :- 6 "<<endl;
   cout<<"------------------------------------------------------------------\n"<<endl;
   while(exit!=1)
   {
       cout<<"Enter your choice :- ";
       cin>>choice;
       cout<<"\n"<<endl;
       switch (choice)
       {
           case 1:{Insert();}
            break;
           case 2:{delete_highest();}
            break;
           case 3:{delete_lowest();}
            break;
           case 4:{peek();}
           break;
           case 5:{ k=Count();
                   cout<<"No of elements in your priority queue is = "<<k<<endl;}
            break;
           case 6:{exit=1;

                   Display();
                   cout<<"You pressed Exit Bye :)"<<endl;}
            break;
            default:{cout<<"Enter the correct choice "<<endl;}
       }
   }
    return 0;
}
