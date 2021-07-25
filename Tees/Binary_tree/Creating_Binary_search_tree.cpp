#include <bits/stdc++.h>//Constructing Binary Search Tree//

using namespace std;
class node //declaration of Class of node type //
{  public:
    int value;
    int counts;
    class node*l;
    class node*r;
}*new_,*r=0;
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
void display(class node*root)
{
    if(root==0)
    {
        exit(0);
    }else{
        cout<<"root= "<<root->value<<"("<<root->counts<<")       \n"<<endl;
        if(root->l!=0)
        {
            cout<<root->l->value<<"("<<root->l->counts<<")       ";
            enque(root->l);
        }else
        {
            cout<<"-             ";
        }
        if(root->r!=0)
        {
            cout<<root->r->value<<"("<<root->r->counts<<")"<<endl;
            enque(root->r);
        }else
        {
            cout<<" -  "<<endl;
        }
 cout<<"-------------------------------------------------"<<endl;
        root=dequeue();//Taking one of the previous child node as parent node for new element to be added //
        display(root);


     }

}
class node*insert_(class node*new_,class node*root)//Function to find the suitable position of the new node to be added and add it //
{
 if(root->value<new_->value)
 {
     if(root->r==0)
     {
         root->r=new_;
          cout<<new_->value<<" inserted "<<"to the right of "<<root->value<<endl;

     }else
     {
        root->r=insert_(new_,root->r);
     }
 }else if(root->value>new_->value)
 {
     if(root->l==0)
     {
         root->l=new_;
          cout<<new_->value<<" inserted "<<"to the left of "<<root->value<<endl;
     }else
     {
         root->l=insert_(new_,root->l);

     }
 }else if(root->value==new_->value)
 {
     root->counts++;
     cout<<new_->value<<" inserted "<<"to the same node and incremented the count of "<<root->value<<endl;
 }

 return root;
};
class node*add(class node*root,int data)
{
    new_=(class node*)malloc(sizeof(class node*));
    new_->value=data;
    new_->counts=1;
    new_->l=0;
    new_->r=0;
    if(root==0)
    {
        root=new_;
        cout<<root->value<<" root node created "<<endl;
    }else
    {
       root=insert_(new_,root);
    }

    return root;
};
int main()
{ class node* r=0;
 r=add(r,9);
 r=add(r,4);
 r=add(r,6);
 r=add(r,3);
 r=add(r,42);
 r=add(r,8);
 r=add(r,28);
 r=add(r,7);
 r=add(r,7);
 display(r);

    /*int i,exit=0,data; //Dynamic input //
    char choice;
    class node* r=0;
    while(exit!=1)
    {   cout << "\nTo add an element press y else to exit press n :- " << endl;
        cin>>choice;
        switch(choice)
        {
            case 'y':{ cout<<"Insert the item to add :- ";
                       cin>>data;
                       r=add(r,data);
                      }break;
            case 'n':{cout<<" All items added "<<endl;
                      display(r);
                      exit=1;
                      }break;
            default:{cout<<"enter the correct choice "<<endl;}
        }
    }*/


    return 0;
}
