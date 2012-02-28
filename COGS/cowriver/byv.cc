/*
USER: fanzeyi1
LANG: C++
TASK: byv
*/
/*
 * =====================================================================================
 * 
 *       Filename:  byv.cc
 *        Created:  02/09/2012 08:01:30 PM
 *       Compiler:  g++
 *         Author:  Zeray Rice, fanzeyi1994@gmail.com
 * 
 * =====================================================================================
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#define MAX 2501
using namespace std; 
 
int N, Ans; 
int M, F[MAX], G[MAX]; 
 
void init()
{
    int i; 
    freopen("river.in", "r", stdin); 
    freopen("river.out", "w", stdout); 
    cin  >>  N  >>       G[0]; 
    for (i=1; i <= N; i++)
    {
        cin  >>  M; 
        G[i]=G[i-1]+M; 
    }
}
 
void                            dynamic()
{
    int i, k, min; 
    F[1]=G[1]+G[0]; 
    for (i=2; i <= N; i++)
    {
        min                     =0x7FFFFFFF; 
        for (k=0; k <= i-1; k++)
        {
            if (F[k]+G[i-k]+G[0]<min)
                                                    min=F[k]+G[i-k]+G[0]; 
        }
        F[i]=min; 
    }
    Ans=F[N]-G[0]; 
}
 
int main                                ()
{
    init(); 
    dynamic(); 
    cout  <<  Ans  <<  endl; 
    return 0; 
}               
