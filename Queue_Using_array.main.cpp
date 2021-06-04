#include <bits/stdc++.h>//Once we use the array space or delete an element size of array keep on decreasing resulting in a condition //
                        //when even after having the space in linear queue we are unable to use that space and thus circular queue is //
                        //the better form to use all the benefits of queue //

using namespace std;

void display(int *arr,int start,int end_,int n)
{
    int i;
    if(start==end_)
    {
        cout<<"Your queue is empty. "<<endl;
    }else{
       for(i=start;i<end_;i++)
       {
           cout<<arr[i]<<" <- ";
       }
       cout<<"\n"<<endl;
    }
}
int  enque(int *arr,int start,int end_,int n)
{
    int value;
    if(end_==n)
    {
        cout<<"Overflow Condition "<<endl;
    }else
    {
      cout<<"Enter value to add "<<endl;
      cin>>value;
      cout<<value<<" is added to queue "<<endl;
      arr[end_]=value;
      end_++;
      cout<<"\nYour Current queue elements are :- \n"<<endl;
      display(arr,start,end_,n);
    }
    return end_;
}
int dequeue(int *arr,int start,int end_,int n)
{

    if(start==end_)
    {
        cout<<"Underflow Condition "<<endl;
    }else
    {
        cout<<arr[start]<<" is deleted "<<endl;
        start++;
        cout<<"\nYour Current queue elements are :- "<<endl;
        display(arr,start,end_,n);
    }
    return start;
}
void Count(int *arr,int start,int end_,int n)
           {
               int size_=0;
               size_=end_-start ;
               cout<<"\nTotal size of our stack = "<<n<<"\nToatal space filled = "<<size_<<"\nTotal space empty = "<<n-size_<<endl;
           }

int main()
{
    int n,i,k,choice,exit=0,start=0,end_=0;
    cout<<"Enter the Total size of your queue "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the no of elements initially present in your initial queue "<<endl;
    cin>>k;
    cout<<"Enter the elements of your queue in same line with space "<<endl;
    for(i=0;i<k;i++)
    {
   cin>>arr[end_];
   end_++;
    }
    cout<<"\nYour initial elements are :- "<<endl;
    display(arr,start,end_,n);
    cout<<"\n---------------------------------"<<endl;
    cout<<"To add an element at end press :- 1 "<<endl;
    cout<<"To delete an element from the beginning press :- 2 "<<endl;
    cout<<"To print the the size and and space filled and left empty press :- 3 "<<endl;
    cout<<"To exit the program press :-4 "<<endl;
    cout<<"------------------------------------\n"<<endl;

    while(exit!=1)
    {  cout<<"\nEnter your choice :- ";
       cin>>choice;
        switch(choice)
        {
            case 1:{end_=enque(arr,start,end_,n);}
            break;
            case 2:{start=dequeue(arr,start,end_,n);}
            break;
            case 3:{Count(arr,start,end_,n);}
            break;
            case 4:{display(arr,start,end_,n);
            cout<<"Thank u and good Bye :)"<<endl;
            exit=1;}
            break;
            default:{cout<<"Enter the correct choice "<<endl;}
        }
    }


    return 0;
}
