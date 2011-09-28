/*
ID: fanzeyi1
LANG: C
TASK: milk 
*/
/*
 * =====================================================================================
 *
 *       Filename:  milk.c
 *        Version:  1.0
 *        Created:  08/30/2011 03:39:03 PM
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

typedef struct {
    int price; 
    int num; 
} Farmer; 

int cmp( const void *a ,const void *b) {
    Farmer *c = (Farmer *)a;
    Farmer *d = (Farmer *)b; 
    return  c->price - d->price; 
}

int main(void)
{
    FILE *fin = fopen("milk.in","r");
    FILE *fout = fopen("milk.out", "w");
    int farmer_num;
    int need_milk; 
    int milk = 0; 
    int cost = 0; 
    int n; 
    int i; 
    Farmer **farmer; 
    fscanf(fin, "%d %d", &need_milk, &farmer_num);
    farmer = (Farmer**)malloc(sizeof(Farmer*) * farmer_num); 
    for( i = 0 ; i < farmer_num ; i++ ) {
        farmer[i] = (Farmer*)malloc(sizeof(Farmer)); 
        fscanf(fin, "%d %d", &farmer[i]->price, &farmer[i]->num);
    }
    qsort(farmer[0], farmer_num, 16, cmp); 
    i = 0; 
    while(milk < need_milk && i < farmer_num) {
        if(farmer[i]->num > need_milk - milk) {
            cost = cost + ((need_milk - milk) * farmer[i]->price); 
            milk = need_milk; 
            i = i + 1; 
        } else { 
            milk = milk + farmer[i]->num; 
            cost = cost + (farmer[i]->price * farmer[i]->num); 
            i = i + 1; 
        }
    }
    fprintf(fout, "%d\n", cost); 
    return 0;
}
