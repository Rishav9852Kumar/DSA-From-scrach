#include <bits/stdc++.h>//Constructing and displaying in order pre order and post order expression  of Binary Search Tree//

using namespace std;
class node //declaration of Class of node type //
{  public:
    int value;
    int counts;
    class node*l;
    class node*r;
}*new_,*r=0;
class node* Display_Inorder(class node*k)
{
   if(k!=0)
   {
       k->l=Display_Inorder(k->l);
       cout<<k->value<<" ";
       k->r=Display_Inorder(k->r);
   }
   return k;
}
class node* Display_Preorder(class node*k)
{
  if(k!=0){
    cout<<k->value<<" ";
    k->l=Display_Preorder(k->l);
    k->r=Display_Preorder(k->r);
  }
    return k;
}
class node* Display_Postorder(class node*k)
{
 if((k->l!=0)&&(k->r!=0))
    {

     k->l=Display_Postorder(k->l);
     k->r=Display_Postorder(k->r);

     cout<<k->value<<" ";
    }else if ((k->l==0)&&(k->r!=0))
    {
        k->r=Display_Postorder(k->r);
        cout<<k->value<<" ";
    }else if ((k->l!=0)&&(k->r==0))
    {
        k->l=Display_Postorder(k->l);
        cout<<k->value<<" ";
    }
    else
    {

        cout<<k->value<<" ";

    }

    return k;
}
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

class node*add(class node*root,int data)
{
    if(root==0)
    {
    new_=new node;//Creating a new node by dynamic memory allocation //
    new_->value=data;
    new_->counts=1;
    new_->l=0;
    new_->r=0;
    root=new_;
    cout<<root->value<<" new node created "<<endl;
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
     return root;
};
int main()
{ /*class node* r=0;  // Use this to run the program with fixed inputs //
 r=add(r,9);
 r=add(r,4);
 r=add(r,6);
 r=add(r,3);
 r=add(r,42);
 r=add(r,8);
 r=add(r,28);
 r=add(r,7);
 r=add(r,7);
 r=display(r);
  cout<<"\nIn order expression = ";
  r=Display_Inorder(r);
  cout<<"\n\nPre order expression = ";
  r=Display_Preorder(r);
  cout<<"\n\nPost order expression = ";
  r=Display_Postorder(r);
 cout<<endl;
*/
    int i,exit=0,data; // Use this for Dynamic input //
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
                       r=display(r);
                      }break;
            case 'n':{cout<<" All items added "<<endl;
                      r=display(r);
                      cout<<"\nIn order expression = ";
                      r=Display_Inorder(r);
                      cout<<"\n\npre order expression = ";
                      r=Display_Preorder(r);
                      cout<<"\n\npost order expression = ";
                      r=Display_Postorder(r);
                      cout<<endl;
                      exit=1;
                      }break;
            default:{cout<<"enter the correct choice "<<endl;}
        }
    }


    return 0;
}

