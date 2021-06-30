#include <bits/stdc++.h>//Binary tree using array //

using namespace std; //ENTER ANY STRING OF NUMBERS WITH EACH NODE VALUE LESS THAN 10 AND -(DASH) SYMBOL IF NO ELEMENTS ARE PRESENT //
void create_binary_tree(char arr[],int n)
{
 int i;
 for(i=0;i<n;i++)
 { if(i<(n+1)/2){
  cout<<"   "<<arr[i]<<"   "<<endl;
  cout<<" / | "<<endl;}
  if(2*i+1<n){
  cout<<arr[2*i+1]<<"  ";
  if(2*i+1<n){
  cout<<arr[2*i+2]<<"  "<<endl;
 }}}
}
/*For example :-          1        from here 1
                        /   \
                       4     5     from here 4 5
                      / \   / \
                    3   7  -   8   from here 3 7 - 8
                   / \  /\    /\
                  4  - 0 8   1  6  from here 4 - 0 8 - - 1 6

               enter string :- 14537-84-08--16
*/
int main()
{ int n,i,t;
    char arr[1000000];
    cout << "Creating first binary tree " << endl;
    cout<<"Enter the elements of your binary tree :- ";
    cin>>arr;
    n=strlen(arr);

    cout<<endl;

    cout<<" Elements of your tree are  :- ";
    for(i=0;i<n;i++)
    {
        cout<<arr[i];
    }
    cout<<endl;
    cout << "Your binary tree :- " << endl;

    create_binary_tree(arr,n);
    return 0;
}
