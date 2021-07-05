#include <bits/stdc++.h>//Binary tree using linked list //
using namespace std;

class node  //Declaration of class node//
{  public:
      int data;
      class node*left;
      class node*right;
}*root,*new_,*Root; //Global declaration of new and root node //

class roots//Declaration of class element for queue//
{  public:
    class node*value;
    class roots*next;
}*front_,*rear=0,*temp,*new__;

void enque(class node *root ) //Function to add an address at the end of the queue//
{

new__=(class roots*)malloc(sizeof(class roots*));
new__->value=root;
new__->next=0;
if(front_==0)
{
    front_=new__;
    rear=new__;
}else
{
    rear->next=new__;
    rear=new__;
}
}
class node* dequeue()//Function to remove an elemnt from the front of the queue//
{

    class node *x;
    if(front_==0)
    {
        cout<<"empty"<<endl;
        x=0;
    }else
    {
        x= front_->value;
        front_=front_->next;

    }
    return x;
}

                              //Function to create a new node which  take int data as input//
class node* create_node(int data){ // and returns the address of new created node//
  new_=(class node*)malloc(sizeof(class node*));
  new_->data=data;//Declaring data //
  new_->left=0;//initializing left child as NULL//
  new_->right=0;//initializing right child as NULL//
  return new_;
}
                                   //Function to add a node in the tree with address of parent node and input data as input //
class node* Insert(class node* root,int data)//And returning address of the child  node created//
{

    if(root==0)// If the Binary Tree is empty //
    {
        root = create_node(data); //Declaring first node as root node//

    }else
    {
     if(root->left==0)
     {
         root->left=create_node(data);
         enque(root->left);

     }else if(root->right==0)
     {
        root->right= create_node(data);
        enque(root->right);
     }else
     {
         root=dequeue();//When all the child Nodes are fulled then one new child node is created //
                       //using one previous child node as new parent node //
         root=Insert(root,data);
     }
}

return root;
}

 void displays() //Function to display the Present Contents of the Queue //
{ cout<<"\n--------------------------------------"<<endl;
  cout<<"Contents of the queue are :- "<<endl;
    if(front_==0)
{
    cout<<"The queue is empty "<<endl;
}else
 {  temp=front_;
    while(temp!=0)
    {
    cout<<temp->value->data<<" -> ";
    temp=temp->next;
    }
    cout<<"\n--------------------------------------\n"<<endl;
 }
}
 void Display(class node *Root)//Function to display our tree //
 {
     if(Root==0)
     {
         exit(0);
     }else
     {
        cout<<"Root=                "<<Root->data<<endl;
        cout<<"               "<<endl;
        if(Root->left!=0){
        cout<<"Child_nodes =     "<<Root->left->data;
        if(Root->right!=0){
        cout<<"      "<<Root->right->data<<endl;
        cout<<"---------------------------------"<<endl;
        enque(Root->left);
        cout<<"child enqueued = "<<Root->left->data<<endl;}else
        {
        cout<<"       "<<"--"<<endl;
        exit(0);
        }
        enque(Root->right);
         cout<<"child enqueued = "<<Root->right->data<<endl;}else
         {
             exit(0);
         }
         displays();
        Root=dequeue();//Taking one of the previous child node as parent node for new element to be added //
        Display(Root);


     }
 }
int main()
{
   Root=Insert(root,15);//Code for fixed inputs //
   root=Root;
   root=Insert(root,10);
   root=Insert(root,20);
   root=Insert(root,30);
   root=Insert(root,40);
   root=Insert(root,50);
   root=Insert(root,60);
   root=Insert(root,70);
   root=Insert(root,80);
   root=Insert(root,90);
   root=Insert(root,100);
   root=Insert(root ,0);
   root=Insert(root ,990);
   root=Insert(root ,880);

   while(front_!=0)//  Emptying the contents of Queue ,so that it can be used again //
   {
       dequeue();
   }
   cout<<" ++++++++++++++++++++++++++++"<<endl;
   Display(Root);
    return 0;
}

