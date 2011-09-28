/*
ID: fanzeyi1
LANG: C
TASK: beads 
*/
/*
 * =====================================================================================
 *
 *       Filename:  beads1.c
 *        Version:  1.0
 *        Created:  08/29/2011 10:49:40 AM
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


#define MAX 500
int main()
{
	freopen("beads.in","r",stdin);
	freopen("beads.out","w",stdout);
	char str[MAX*2],str1[MAX];
	memset(str,0,1000);
	int n;
	scanf("%d",&n);
	getchar();
	int i,j,k;
	gets(str1);
	strcpy(str,str1);
	strcpy(str+n,str1);
	int count1,count2,max=0,x,y;
	for(i=n-1;i>=0;i--)
	{
		x=y=0;
		count1=count2=0;
		for(j=i;;j--)
		{
			if(str[j]!='w')
				break;
			count1++;
			x++;
		}
		for(;j>=0;j--)
		{
			if((str[i-x]==str[j])||(str[j]=='w'))
			{
					count1++;
					continue;
			}
			break;
		}
		for(k=i+1;str[k]=='w';k++)
		{
			count2++;
			y++;
		}
		for(;k<=2*n-1;k++)
		{
			if((str[i+1+y]==str[k])||(str[k]=='w'))
			{
				count2++;
				continue;
			}
			break;
		}
		max=(max>(count1+count2))?max:(count1+count2);
	}
	if(max>n)max=n;
	printf("%d\n",max);
	return 0;
}
