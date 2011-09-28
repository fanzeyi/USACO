/*
ID: fanzeyi1
LANG: C
TASK:  packrec
*/
/*
 * =====================================================================================
 *
 *       Filename:  packrec1.c
 *        Version:  1.0
 *        Created:  09/13/2011 06:51:05 PM
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  Zeray Fan, fanzeyi1994[at]gmail.com
 *        Company:  http://www.fanhe.org/
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack[3000][3];
int minsize=20000000;
int top=0;
int square[4][2];
void deal(int maxl,int maxw)
{
    int k,size;
    size=maxl*maxw;
    if(maxl>maxw)
    {
        k=maxl;
        maxl=maxw;
        maxw=k;
    }
    if(size<minsize)
    {
        stack[0][0]=size;
        stack[0][1]=maxl;
        stack[0][2]=maxw;
        minsize=size;
        top=1;
    }
    else if(size==minsize)
    {
        stack[top][0]=size;
        stack[top][1]=maxl;
        stack[top][2]=maxw;
        top++;
    }
}
void quicksort(int l,int r)
{
    int x,y,tp1,tp2;
    if(l>=r)
    return ;
    x=l;
    y=r;
    tp1=stack[l][1];
    tp2=stack[l][2];
    while(x<y)
    {
        while(x<y&&stack[y][1]>=tp1)
        y--;
        stack[x][1]=stack[y][1];
        stack[x][2]=stack[y][2];
        while(x<y&&stack[x][1]<=tp1)
        x++;
        stack[y][1]=stack[x][1];
        stack[y][2]=stack[x][2];
    }
    stack[x][1]=tp1;
    stack[x][2]=tp2;
    quicksort(l,x-1);
    quicksort(x+1,r);
}
void cal(int p)
{
    int i,maxl,maxw;
    if(p==1)
    {
        maxl=0;
        maxw=0;
        for(i=0;i<4;i++)
        {
            if(square[i][0]>maxl)
            maxl=square[i][0];
            maxw+=square[i][1];
        }
        deal(maxl,maxw);
    }
 
 
    if(p==2)
    {
        maxl=0;
        maxw=0;
        for(i=0;i<3;i++)
        {
            if(square[i][0]>maxl)
            maxl=square[i][0];
            maxw+=square[i][1];
        }
        maxl+=square[3][0];
        if(maxw<square[3][1])
        maxw=square[3][1];
        deal(maxl,maxw);
    }
 
    if(p==3)
    {
        maxl=0;
        maxw=0;
        for(i=0;i<2;i++)
        {
            if(square[i][0]>maxl)
            maxl=square[i][0];
            maxw+=square[i][1];
        }
        maxl+=square[2][0];
        if(maxw<square[2][1])
        maxw=square[2][1];
        maxw+=square[3][1];
        if(maxl<square[3][0])
        maxl=square[3][0];
        deal(maxl,maxw);
    }
 
    if(p==4)
    {
        maxl=0;
        maxw=0;
        for(i=0;i<2;i++)
        {
            if(square[i][0]>maxl)
            maxl=square[i][0];
            maxw+=square[i][1];
        }
        if(square[2][1]>square[3][1])
        maxw+=square[2][1];
        else
        maxw+=square[3][1];
        if(maxl<square[2][0]+square[3][0])
        maxl=square[2][0]+square[3][0];
        deal(maxl,maxw);
    }
 
    if(p==5)
    {
        if(square[2][1]<square[3][1]
        &&square[1][0]>square[2][0])
        return ;
        if(square[1][1]<square[0][1]
        &&square[2][0]>square[1][0])
        return ;
        if(square[2][1]<square[3][1]
        &&square[3][0]>square[0][0])
        return ;
        if(square[3][1]<square[2][1]
        &&square[3][0]<square[0][0])
        return ;
        if(square[0][0]+square[1][0]>square[2][0]+square[3][0])
        maxl=square[0][0]+square[1][0];
        else
        maxl=square[2][0]+square[3][0];
        if(square[0][1]+square[3][1]>square[1][1]+square[2][1])
        maxw=square[0][1]+square[3][1];
        else
        maxw=square[1][1]+square[2][1];
        deal(maxl,maxw);
    }
}
void order(int p)
{
    int i,j,k,temp0,temp1,temp3,temp4;
    if(p>=4)
    {
        return;
    }
    if(p==3)
    {
        for(i=1;i<=5;i++)
        cal(i);
    }
    order(p+1);
    temp0=square[p][0];
    temp1=square[p][1];
    for(i=p+1;i<4;i++)
    {
        square[p][0]=square[i][0];
        square[p][1]=square[i][1];
        square[i][0]=temp0;
        square[i][1]=temp1;
        order(p+1);
        temp3=square[p][0];
        temp4=square[p][1];
        square[p][0]=square[i][0];
        square[p][1]=square[i][1];
        square[i][0]=temp3;
        square[i][1]=temp4;
    }
}
void ss(int p)
{
    int i,j,k,temp;
    if(p==4)
    {
        order(0);
        return ;
    }
 
    ss(p+1);
    temp=square[p][0];
    square[p][0]=square[p][1];
    square[p][1]=temp;
    ss(p+1);
    temp=square[p][0];
    square[p][0]=square[p][1];
    square[p][1]=temp;
}
int main()
{
    int i,j,k;
    int l,w;
    FILE *fp,*fq;
    fp=fopen("packrec.in","r");
    fq=fopen("packrec.out","w");
    for(i=0;i<4;i++)
    fscanf(fp,"%d%d",&square[i][0],&square[i][1]);
    ss(0);
    quicksort(0,top-1);
    fprintf(fq,"%d\n",minsize);
    for(i=0;i<top;i++)
    {
        fprintf(fq,"%d %d\n",stack[i][1],stack[i][2]);
        l=stack[i][1];
        while(stack[i][1]==l)
        {
            i++;
        }
        i--;
    }
    fclose(fp);
    fclose(fq);
 
    return 0;
}
