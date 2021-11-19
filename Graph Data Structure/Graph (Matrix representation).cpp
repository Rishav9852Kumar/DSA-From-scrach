#include <iostream>//Adjacent and Incident Matrix representation of an Graph//
#include <math.h>
using namespace std;

int main()
{
    int n,e,x,y;
    cout << "Enter the no of vertices in your graph = ";
    cin>>n;
    cout<<"\nEnter the no of edges in your graph :- ";
    cin>>e;
    int arr[n+1][n+1],karr[n+1][n+1],marr[e+1][n+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if((i==0)||(j==0))
            {
                arr[i][j]=max(i,j);
                karr[i][j]=max(i,j);
            }else{
            arr[i][j]=0;
            karr[i][j]=0;
            }

        }
    }
    for(int i=0;i<=e;i++)
    {
        for(int j=0;j<=n;j++)
        {
          if((i==0)||(j==0))
             marr[i][j]=max(i,j);
            else
             marr[i][j]=0;
        }
    }
    for(int i=0;i<e;i++)
    {
        cout<<"\nEnter the vertex's connecting the edge no "<<i+1<< ":- ";
        cin>>x>>y;
        marr[i+1][x]=1;
        marr[i+1][y]=1;
        arr[x][y]=1;
        karr[x][y]=1;
        karr[y][x]=1;

    }



    cout<<"\nYour Adjacent Matrix representation of an undirected graph :- \n"<<endl;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<" "<<karr[i][j]<<" ";
        }
        cout<<"\n";
    }

    cout<<"\nYour Adjacent Matrix representation of a directed graph :- \n"<<endl;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<" "<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
     cout<<"\nYour Incident Matrix representation of a graph :- \n"<<endl;
    for(int i=0;i<=e;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<" "<<marr[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
