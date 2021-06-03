#include <bits/stdc++.h>

using namespace std;

void display(int *arr,int top,int n)//pass by pointer as arr in the input itself represents  the address of first element of array//
{
    int k;
    cout<<"\nYour stack elements are :- "<<endl;
    for(k=top;k>-1;k--)
    {
        cout<<arr[k]<<endl;
    }
cout<<"---------------------------\n\n"<<endl;
}

int  push(int *arr,int top,int n)
{ int k;
if(top==n-1)
{
    cout<<"Overflow Condition "<<endl;
}else{
cout<<"Enter the element to add Top "<<endl;
cin>>k;
top++;
 arr[top]=k;
 display(arr,top,n);
}
 return top;


}
int  pop(int *arr,int top,int n)
{ int k;
if(top==0)
{
    cout<<"Underflow Condition "<<endl;
}else{

top--;
display(arr,top,n);

}
 return top;

}



int main()
{ int n,i,top=-1,choice,exit=0,k;
  cout <<"Enter the max size of array " << endl;
  cin>>n;
  int arr[n];
  cout<<"Enter no of initial elements of your stack"<<endl;
  cin>>k;
  for(i=0;i<k;i++)
  {
       top++;
    cin>>arr[top];
 }
 display(arr,top,n);
  cout<<"-------------------------------------------------------------------"<<endl;
  cout<<"Enter your operation to perform\n"<<endl;

  cout<<"To add an element at top of the stack press :- 1 \n"<<endl;

  cout<<"To delete the top most element of the stack press :- 2 \n"<<endl;

  cout<<"To print the elements of stack and total available size press :- 3\n "<<endl;

  cout<<"To exit press :- 4 \n"<<endl;
  cout<<"--------------------------------------------------------------------"<<endl;

  while(exit!=1)
  {   cout<<"Enter your choice"<<endl;
      cin>>choice;
    switch (choice){

     case 1:{ top= push(arr,top,n);

       break;}
     case 2: {top=pop(arr,top,n);
            }
      break;
      case 3: {display(arr,top,n);
              cout<<"Size of your stack filled = "<<top+1<<"\nand the size left empty = "<<n-top-1<<endl;
      break;}
      case 4: { exit =1;
      }break;
      default:{ cout<<"Enter the correct choice "<<endl;
        }
                  }
  }


    return 0;
}
