#include<iostream>

#include<vector>

using namespace std;

int main()
{
    int i,n=5,value,size_, result;

    vector<int> v;

    vector<int>new_v;

    for(i=0;i<n;i++)//Way of taking N inputs where N is known in advance //
    {
        cout<<"Enter the next element: "<<endl;

        cin>>value;

        v.push_back(value);
    }
    cout<<"Your list is :- "<<endl;

    for(auto k=v.begin();k!=v.end();k++)//To print the elements of the list from first to last element //
    {
        cout<<*k<<" ";
    }
    cout<<"\nYour reversed list :- "<<endl;//To print the  elements of the list from last to first element//

    for(auto k=v.rbegin();k!=v.rend();k++)
    {
        cout<<*k<<" ";
    }

    size_=v.size();//Function to get the no of elements of declared data type in th vector list //

    cout<<"\nsize = "<<size_<<endl;

    size_=v.max_size();//Function to get the maximum no of elements that can be holden in th vector list //

    cout<<"maximum no of elements the vector can hold = "<<size_<<endl;

     size_=v.capacity();//Function to get the no of elements space allocated initially of declared data type in th vector list //

    cout<<"The current allocated space for elements in vector (expressed in no of elements ) = "<<size_<<endl;

    v.resize(3);//Function to resize the no of elements in th vector list which deletes all extra elements  //

    size_=v.size();

    cout<<"New size = "<<size_<<endl;

    result=v.empty();//Function to check the emptiness of the list directly//

    cout<<"Condition of vector list "<<result<<endl;

    v.shrink_to_fit();//removes all unfilled space capacity //

    cout<<"shrined size = "<<v.size()<<endl;

    cout<<"shrined capacity = "<<v.capacity()<<endl;

    new_v.reserve(10);

    cout<<"Enter the elements of new vector list :-";

    for(i=0;i<10;i++)
   {
        cin>>value;

        new_v.push_back(value);
    }

    size_=new_v.size();

    cout<<"\nNew size = "<<size_<<endl;

    for(auto k =new_v.begin();k!=new_v.end();k++)
    {
        cout<<*k<<" ";
    }
    cout << "\nReference operator [g] :at position 3 = " << new_v[2];//Just like array with index starting from 0//

    cout << "\nat : new_v.at(4) = " << new_v.at(4);//function that Returns the value at that position 4+1=5//

    cout << "\nfront() : new_v.front() = " << new_v.front();//function prints the front element //

    cout << "\nback() : new_v.back() = " << new_v.back();//function that prints the last element//

    //new_v.assign()// T edit have some dout XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX//

    //new_v.push_back(9);//adds 9 to the end of th vector elements list//

    new_v.pop_back();//removes or deletes one element from the last of the list //
    size_=v.size();

    cout<<"New size of vector v after removing last element  = "<<size_<<endl;

    new_v.insert(new_v.begin()+2,9);//It inserts new elements before the element at the specified position//
    size_=v.size();

    cout<<"New size of vector v after adding 9 at position 3 = "<<size_<<endl;
    new_v.erase(v.begin());//It is used to remove elements from a container from the specified position or range.//
    size_=v.size();

    cout<<"New size of vector v after deleting first element  = "<<size_<<endl;
    v.swap(new_v);

    size_=v.size();

    cout<<"New size of vector v after swap = "<<size_<<endl;

    size_=new_v.size();//Swaps the content of vector v and new_v//

    cout<<"New size of vector new_v after swap = "<<size_<<endl;

    new_v.clear();//Deletes all the element of of vector v//

    size_=new_v.size();//Swaps the content of vector v and new_v//

    cout<<"New size of vector new_v after(new_v.clear()) = "<<size_<<endl;

    v.emplace(v.begin(),10);//Inserts 10 at the beginning of the vector list

    size_=v.size();//printing the size of the vector list//

    cout<<"New size of vector v  after (v.emplace(v.begin(),10)= "<<size_<<endl;

    v.emplace_back(20);//Inserts 20 at the end of the vector list//

    size_=v.size();//Printing size of vector list//

    cout<<"New size of vector v after(v.emplce_back(20))  = "<<size_<<endl;

  return 0;
}
