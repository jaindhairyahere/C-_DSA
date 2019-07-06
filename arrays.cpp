#include<iostream>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>
#include <complex>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <time.h>

#define rep(i,a,b) for(int i=a;i <b;i++)
using namespace std;

int main()
{
    int n = 10000;
    int array[n];
    rep(i,0,n){
        array[i] = i*2 + i*i;
    }

    cout<<"\nadd of array = "<<array;
    cout<<"\nSize of int : "<< (&array[1]-&array[0]);
    cout<<"\nadd of array[10] = "<<&array[10];
    cout<<"\nadd of array[1] = "<<&array[1];



    return 0;
}
