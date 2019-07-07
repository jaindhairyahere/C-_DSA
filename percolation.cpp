#include <iostream>
using namespace std;

//Quick Find
bool QFconnected(int indexarray[], int a,int b)
{
    if(indexarray[a]==indexarray[b]) { return true;}
    else { return false;}
}

void quickFind(int n,int indexarray[],int a,int b)
{
       int temp = indexarray[b];
    for(int i=0; i<n;i++)
    {
        if( indexarray[i] == temp)     indexarray[i] = indexarray[a];
    }
    return;
}

//Quick Union
int FindRoot(int arr[],int n)   {
    if (arr[n] == n) return n;
    else{
        return FindRoot(arr,arr[n]);
    }
}
void quickUnion(int n,int arr[],int p, int q)
{
    int i = FindRoot(arr,p);
    int j = FindRoot(arr,q);

    arr[j] = i;
}
bool QUconnected(int arr[],int p,int q)
{
    return (FindRoot(arr,p) == FindRoot(arr,q));
}

//Weighted Quick Union with path compression
int FindRootPC(int arr[],int n)   {
    if (arr[n] == n) return n;
    else{
        arr[n]=arr[arr[n]];
        return FindRoot(arr,arr[n]);
    }
}
int findtimes(int arr[], int n)
{
    int times= 0;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i]==n) times++;
    }
    return times;
}
int weightedFindRoot(int arr[],int n)   {
    if (arr[n] == n) return n;
    else{
        return FindRoot(arr,arr[n]);
    }
}
void weightedQuickUnion(int n,int arr[],int p, int q)
{
    int i = FindRoot(arr,p);
    int j = FindRoot(arr,q);
    if (findtimes(arr, FindRoot(arr,q)) < findtimes(arr, FindRoot(arr,p)) )    arr[j] = i;
    else arr[i]=j;
}
bool WQUconnected(int arr[],int p,int q)
{
    return (FindRoot(arr,p) == FindRoot(arr,q));
}


int main()
{
    int arr[10];
    for(int i=0; i<10;i++)  arr[i] = i;
    weightedQuickUnion(10,arr,1,3);

    weightedQuickUnion(10,arr,1,2);

    weightedQuickUnion(10,arr,2,5);

    weightedQuickUnion(10,arr,9,1);


    for(int i=0; i<10;i++)  cout<<arr[i] ;cout<<"\n";

    cout<<WQUconnected(arr,3,9);
    return 0;
}
