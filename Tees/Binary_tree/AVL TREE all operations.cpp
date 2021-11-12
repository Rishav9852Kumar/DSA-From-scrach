#include <iostream>//Program to create an AVL tree and addition ,deletion,searching operations.

using namespace std;
class node //declaration of Class of node type //
{  public:
    int value;
    int counts;
    class node*l;
    class node*r;
}*new_,*temp,*r=0;
int find_minimum_right(class node *root)//Function to find the minimum valued node in the tree//
{
   while(root->l!=0)
   {
       root=root->l;
   }
    return root->value;
};
class node* delete_(class node*root,int key)
{
 if(root!=0)
 {
  if(key==root->value) //if the element to delete is found and is the root //
  {
      if((root->l==0)&&(root->r==0))//if the node to delete is a leaf node(both child null)//
      {   if(root->counts==1){
          root=0;}
          else{
          root->counts=root->counts-1;
          }

       return root;
      }else if((root->l==0)||(root->r==0))//if the node to delete is a single child node (only one child )//
      {
         if(root->l==0)//IF the child present is right child//
         {   if(root->counts==1){
             root=root->r;}
             else{
             root->counts=root->counts-1;
             }

             return root;
         }else if (root->r==0)  //IF the child present is left child//
         {   if(root->counts==0){
             root=root->l;}
             else{
             root->counts=root->counts-1;
             }

             return root;
         }

      }else //If the node to delete has both child not null (two child present)//
      {
       if(root->counts==1)
       {
        int key;
        key = find_minimum_right(root->r);
        root->value=key;

        root->r=delete_(root->r,key);
        return root;

       }else
         {
           root->counts=root->counts-1;
           return root;
         }
       }
   }else if (key>root->value)  //If the element to delete is not the head then we transverse the tree //
        {
            root->r=delete_(root->r,key);
            return root;
   }else if(key<root->value)
        {
            root->l=delete_(root->l,key);
            return root;

   }
 }else{  //if the element wanted to be deleted is not present in the tree//
     cout<<"Element : "<<key<<" to be deleted not found in the tree"<<endl;
     return root;
     exit(0);
      }
};
class node *find_min(class node *root)//Function to find the minimum valued node in the tree//
{
    if(root==0)
    {
        cout<<"Minimum element = "<<"Null"<<endl;
        return root;
    }else if (root->l==0)
    {
        cout<<"Minimum element = "<<root->value<<endl;
        return root;
    }else{
     root->l=find_min(root->l);
     return root;
    }
};
class node *find_max(class node *root)//Function to find the maximum valued node in the tree//
{
    if(root==0)
    {
        cout<<"Maximum element = "<<"Null"<<endl;
        return root;
    }else if (root->r==0)
    {
        cout<<"Maximum element = "<<root->value<<endl;
        return root;
    }else{
     root->r= find_max(root->r);
     return root;
    }
};
class node*search_(class node *root,int key)//Function to search a particular valued node in the tree//
{
    if(root!=0)
    {
        if(key==root->value)
        {
            cout<<"Element : "<<key<<" Found in the tree "<<endl;
            return root;
            exit(0);
        }else if (key>root->value)
        {
            root->r=search_(root->r,key);
        }else if (key<root->value)
        {
            root->l=search_(root->l,key);
        }

    }else
    {
        cout<<"Element : "<<key<<" not found in the tree"<<endl;
        return root;
        exit(0);
    }
    return root;
};
class node*display(class node*root)
{
    if(root!=0)
    {
        cout<<"\nparent =      "<<root->value<<"("<<root->counts<<")"<<endl;
        if((root->l!=0)&&(root->r!=0)){
        cout<<"childs =   "<<root->l->value<<"        "<<root->r->value<<endl;
        root->l=display(root->l);
        root->r=display(root->r);
        }else if((root->l==0)&&(root->r!=0)){
        cout<<"childs =   "<<" - "<<"       "<<root->r->value<<endl;
        root->r=display(root->r);
        }else if((root->l!=0)&&(root->r==0)){
        cout<<"childs =   "<<root->l->value<<"        "<<"- "<<endl;
        root->l=display(root->l);
        }else{
        cout<<"childs =   "<<"- "<<"       "<<"- "<<endl;
        }
        return root;
    }

}
class node* LL_Rotation(class node *root)
{
    temp=new node;
    temp=root;
    root=temp->l;
    root->r=temp;
    temp->l=0;
    cout<<"\nLL Rotation for node "<<temp->value<<" completed with node "<<root->value<<" as new root "<<endl;
    cout<<"\n-----------------------------------------------------"<<endl;
    r=display(r);
    return root;
};
class node* RR_Rotation(class node *root)
{
    temp=new node;;
    temp=root;
    root=temp->r;
    temp->r=0;
    root->l=temp;
    temp->r=0;
    cout<<"\nRR Rotation for node "<<temp->value<<" completed with node "<<root->value<<" as new root "<<endl;
    r=display(r);
    cout<<"\n-----------------------------------------------------"<<endl;
    return root;
};
class node* LR_Rotation(class node *root)
{
    temp=new node;;
    temp=root->l;
    root->l=temp->r;
    temp->r=0;
    root->l->l=temp;
    root->l->r=0;
    temp->r=0;
    cout<<"\nLR Rotation for node "<<root->value<<" completed with node "<<root->value<<" as new root "<<endl;
    root=LL_Rotation(root);
    r=display(r);
    cout<<"\n-----------------------------------------------------"<<endl;
    return root;
};
class node* RL_Rotation(class node *root)
{
    temp=new node;;
    temp=root->r;
    root->r=temp->l;
    temp->l=0;
    root->r->r=temp;
    root->r->l=0;
    temp->l=0;
    cout<<"\nRL Rotation for node "<<root->value<<" completed with node "<<root->value<<" as new root "<<endl;
    root=RR_Rotation(root);
    r=display(r);
    cout<<"\n-----------------------------------------------------"<<endl;
    return root;
};
int AVLHeight(class node*root)
{
    int left_height,right_height;

    if(root==0)
    {
        return 0;
    }
    left_height=AVLHeight(root->l);
    right_height=AVLHeight(root->r);
    return (max(left_height,right_height)+1);
}
int check_degree(class node*root)
{
    int x,y;
    x=AVLHeight(root->l);
    y=AVLHeight(root->r);
    return (x-y);
}

class node*add(class node*root,int data)
{ int d;
    if(root==0)
    {
    new_=new node;//Creating a new node by dynamic memory allocation //
    new_->value=data;
    new_->counts=1;
    new_->l=0;
    new_->r=0;
    root=new_;
    cout<<"\n-----------------------------------------"<<endl;
    cout<<"     "<<root->value<<" new node created "<<endl;
    cout<<"-----------------------------------------\n"<<endl;
    }else if(data>root->value)
    {
       root->r=add(root->r,data);
    }else if(data<root->value)
    {
        root->l=add(root->l,data);
    }else if(data==root->value)
    {
        root->counts=root->counts+1;
    }
    d= check_degree(root);
    cout<<"\nfor node "<<root->value<< " balancing factor d is "<<d<<endl;
    if(d==0||d==-1||d==+1){
     return root;
    }else{
        if((d>1)&&(check_degree(root->l)>0))
        { cout<<"Doing LL Rotation "<<endl;
            root=LL_Rotation(root);
        }else if((d>1)&&(check_degree(root->l)<0))
        {   cout<<"Doing LR Rotation "<<endl;
            root=LR_Rotation(root);
        }else if((d<1)&&(check_degree(root->r)>0))
        {   cout<<"Doing RL Rotation "<<endl;
            root=RL_Rotation(root);
        }else if((d<1)&&(check_degree(root->r)<0))
        {   cout<<"Doing RR Rotation "<<endl;
            root=RR_Rotation(root);
        }

        return root;
    }
};
int main()
{ class node* r=0;
 r=add(r,9);
 r=add(r,4);
 r=add(r,6);
 r=display(r);
 r=add(r,3);
 r=add(r,42);
 r=display(r);
 r=add(r,8);
 r=add(r,28);
 r=display(r);
 r=add(r,7);
 r=add(r,0);
 r=display(r);
 r=add(r,7);
 cout<<"\n your final created AVL tree :- "<<endl;
 cout<<"-------------------------------------------"<<endl;
 cout<<"-------------------------------------------"<<endl;
 r=display(r);
 r=delete_(r,9);
 cout<<"-----------------------"<<endl;
 cout<<"Deleting "<<"9"<<endl;
 cout<<"-----------------------"<<endl;
 r=display(r);
 r = search_(r,2);
 r = search_(r,28);
 r = search_(r,0);
 cout<<"\n--------------------------"<<endl;
 r = find_max(r);
 r = find_min(r); //Edit upto here and remove th comment symbol to take input dynamically//
 /*int i,exit=0,data; //Dynamic input //
    char choice;
    class node* r=0;
    while(exit!=1)
    {   cout << "\nTo add an element press 'A',To delete an element press 'D' ,To search an element press 'S' else to exit press 'E' (all in capital letters) :- " << endl;
        cin>>choice;
        switch(choice)
        {
            case 'A':{ cout<<"Insert the item to add :- ";
                       cin>>data;
                       r=add(r,data);
                       r=display(r);
                      }break;
            case 'E':{cout<<" All items added "<<endl;
                      r=display(r);
                      r = find_max(r);
                      r = find_min(r);
                      exit=1;
                      }break;
            case 'S':{cout<<" Enter the element to search "<<endl;
                      int key;
                      cin>>key;
                      r=search_(r,key);
                      }break;
           case 'D':{cout<<" Enter the element to Delete "<<endl;
                      int key;
                      cin>>key;
                      r=delete(r,key);
                      cout<<"Your element "<<key<<" deleted from tree "<<endl;
                      }break;
            default:{cout<<"enter the correct choice "<<endl;}
        }
    }*/


    return 0;
}
