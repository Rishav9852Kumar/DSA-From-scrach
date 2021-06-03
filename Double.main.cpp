#include <iostream>

using namespace std;
class node
{ public:
  class node* prev;
  int data;
  class node* next;
}*head,*temp,*tail,*current,*new_,*next_,*prev_;

 void display()
 { cout<<"----------------"<<endl;
     if(head==0)
     {
         cout<<"List is empty "<<endl;
     }else{
         temp=head;
         while(temp!=0)
         {
             cout<<temp->data<<"->";
             temp=temp->next;
         }

     }
     cout<<"\n----------------"<<endl;
 }
  void add_beg()
  {
      int value ;
      new_=(class node *)malloc(sizeof(class node*));
      cout<<"enter the data "<<endl;
      cin>>value;
      new_->prev=0;
      new_->data=value;
      new_->next=0;
       if(head==0)
       {
           head=new_;
           tail=new_;
       }else{
           head->prev=new_;
           new_->next=head;
           head=new_;
       }
      display();
  }
  void add_end()
  {
      int value;
      new_=(class node*)malloc(sizeof(class node*));
      cout<<" Enter the Data "<<endl;
      cin>>value;
      new_->data=value;
      new_->prev= 0;
      new_->next=0;
      if(head==0)
      {
          cout<<"List is empty "<<endl;

      }else{
          tail->next=new_;
          new_->prev=tail;
          tail=new_;
      }
      display();
  }
  void add_spec()
  {
      int i,n,value;
      cout<<"Enter the position you want to add the value "<<endl;
      cin>>n;
      cout<<"Enter the data you want to add "<<endl;
      cin>>value;
      new_=(class node*)malloc(sizeof(class node*));
      new_->data=value;
      new_->next=0;
      new_->prev=0;
      temp=head;
      for(i=1;i<n;i++)
      {
          temp=temp->next;
      }
      new_->prev=temp->next->prev;
      new_->next=temp->next;
      temp->next->prev=new_;
      temp->next=new_;
      display();
  }
  void del_beg()
  { if(head==0)
    {
      cout<<"You Have Empty list "<<endl;
    }else{
      temp=head->next;
      temp->prev=0;
      head->next=0;
      head=temp;
       display();
    }
   }
  void del_end()
  {
      if(head==0)
      {
          cout<<"You have Empty list "<<endl;
      }else{
       temp=tail;
       temp=temp->prev;
       temp->next=0;
       tail->prev=0;
       tail=temp;
        display();
      }
  }
  void del_spec()
  { int n,i;
      cout<<"Enter the position to delete "<<endl;
      cin>>n;
      temp=head;
      for(i=1;i<n;i++)
      {
          temp=temp->next;
      }
      temp->next->prev=temp->prev;
      temp->prev->next=temp->next;
      temp->next=0;
      temp->prev=0;
      display();
  }
  void Count()
  {
      int sum=0;
      if(head==0)
      {
           display();
      }else{
        temp=head;
        while(temp!=0)
        {
            temp=temp->next;
            sum++;
        }
        cout<<"Your list has "<<sum<<" elements"<<endl;
      }
  }
  void rev()
  {
      cout<<"Your Reversed List is :- "<<endl;

      temp=head;
      prev_=0;
      current=head;
      while(temp->next!=0)
      {
          temp=temp->next;
          current->prev=current->next;
          current->next=prev_;
          prev_=current;
          current=temp;
      }
      current->prev=current->next;
      current->next=prev_;
      head =current;
    display();
  }
int main()
{   int i,n;
     cout << "Enter the size of of your initial List " << endl;
     cin>>n;
     for(i=0;i<n;i++)
     {  int value;
         new_=(class node*)malloc(sizeof(class node*));
         cout<<"Enter the data "<<endl;
         cin>>value;
         new_->prev=0;
         new_->data=value;
         new_->next=0;
         if(head==0)
         {
             head=new_;
             tail=new_;
         }else{
             tail->next=new_;
             new_->prev=tail;
             tail=new_;
         }
      }
           display();
            int choice,End =0;
            cout<<"Now if you want to edit the list :-"<<endl;
            cout<<" TO add an element at beginning press :- 1  "<<endl;
            cout<<" TO add an element at end press :- 2  "<<endl;
            cout<<" TO add an element at specific position press :- 3  "<<endl;
            cout<<" TO delete an element at beginning press :- 4  "<<endl;
            cout<<" TO delete an element at end press :- 5  "<<endl;
            cout<<" TO delete an element at specific position press :- 6  "<<endl;
            cout<<" TO count the no of element in the list press :- 7  "<<endl;
            cout<<" To reverse the list press :- 8"<<endl;
            cout<<" TO exit and print result  press :- 9  "<<endl;
            while(End!=1)
            { cout<<"Enter your choice "<<endl;
            cin>>choice;
            switch (choice){
                case 1:{ add_beg();
                }
                break;
                case 2:{ add_end();
                }
                break;
                case 3:{ add_spec();
                }
                break;
                case 4:{ del_beg();
                }
                break;
                case 5:{ del_end();
                }
                break;
                case 6:{ del_spec();
                }
                break;
                case 7:{ Count();
                }
                break;
                case 8:{rev();
                }
                break;
                case 9:{End =1;
                        display();
                        cout<<"Bye :)"<<endl;
                }
                break;
                default:{ cout<<"Enter the correct choice "<<endl;}
              }

            }

    return 0;
}
