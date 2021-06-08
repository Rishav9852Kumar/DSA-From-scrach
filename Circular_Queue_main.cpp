#include <iostream>

using namespace std;

void display(int *arr,int n,int front_,int rear)
{
    if(front_==-1)
    {
       cout<<"\n*******************************"<<endl;
       cout<<"No elements present in queue "<<endl;
       cout<<"\n*******************************"<<endl;
    }else {
     cout<<"\nElements present in your queue are :- ";
        if(front_<=rear)
        { while(front_-1!=rear){

        cout<<arr[front_]<<" -> ";
         front_++;
        }
        }else
        {
            while((front_-1)%n!=rear){
        cout<<arr[front_]<<" -> ";
        front_++;
            }

        }

        cout<<"\n"<<endl;
    }
}
void enque(int *arr,int n,int &front_,int &rear ,int k)
{
  if(((rear+1)%n)==front_)
  {   cout<<"\n*******************************"<<endl;
      cout<<"\nOverflow condition "<<endl;
      cout<<"\n*******************************"<<endl;
  }else{
    if(front_==-1)
    {
        rear++;
        arr[rear]=k;
        cout<<"\n------------"<<endl;
        cout<<" adding "<<k<<endl;
        front_=0;
    }else if(((rear+1)%n)!=front_)
    {     cout<<"\n------------"<<endl;
          cout<<" adding "<<k<<endl;
           rear++;
           arr[rear]=k;


    }
      }
    display(arr,n,front_,rear);
}
void Dequeue(int *arr,int n,int &front_,int &rear)
{
    if(front_==-1)
    {    cout<<"\n*******************************"<<endl;
        cout<<"\nUnderflow condition "<<endl;
        cout<<"\n*******************************"<<endl;
    }else if(front_==rear)
    {  cout<<"\n------------"<<endl;
       cout<<"\n deleting "<<arr[front_]<<endl;
       front_=-1;
       rear=-1;
    }else
    {   cout<<"\n------------"<<endl;
        cout<<"\n deleting "<<arr[front_]<<endl;
            front_=(front_+1)%n;


    }
    display(arr,n,front_,rear);
}
void Count(int *arr,int n,int front_ ,int rear )
{ int filled,empty_ ;
 cout<<"Front = "<<front_<<"\n Rear = "<<rear<<endl;
 if(front_==rear)
 {
     if(front_==-1)
     {
         filled=0;
     }else
     {
         filled=1;
     }

 }else if(front_==0)
 {
     filled=rear+1;
 }else if(front_<rear)
 {
     filled=rear-front_+1;
 }else
 {
     filled=n-front_+rear+1;
 }
 empty_=n-filled;

    cout<<"\nTotal size of your queue is = "<<n<<"\nTotal space filled = "<<filled<<"\nTotal space empty = "<<empty_<<endl;
}

int main()
{
     int n,k,choice,exit=0,front_=-1,rear=-1;
    cout<<"Enter the Total size of your Queue "<<endl;
    cin>>n;
    int arr[n];


    cout<<"\n-------------------------------------"<<endl;
    cout<<"To add an element in the array press :- 1 "<<endl;
    cout<<"To delete an element from front press :- 2 "<<endl;
    cout<<"To print the total size of queue,no of space filled and space left press :- 3 "<<endl;
    cout<<"To print the final queue and exit press :- 4 "<<endl;
    cout<<"-----------------------------------------\n"<<endl;


    while(exit!=1)
    { cout<<"Enter your choice :- ";
    cin>>choice;
    switch(choice){
      case 1:{cout<<"\nEnter element to add at rear :- ";
             cin>>k;

             enque(arr,n,front_,rear,k);
            }break;
      case 2:{Dequeue(arr,n,front_,rear);
            }break;
      case 3:{Count(arr,n,front_,rear);
            }break;
      case 4:{display(arr,n,front_,rear);
             exit=1;
             }break;
     default:{cout<<"\nXXXXXXXXX Enter the correct choice XXXXXXXXXXXX"<<endl;}
                  }
    }

    return 0;
}
