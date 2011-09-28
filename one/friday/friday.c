/*
ID: fanzeyi1
LANG: C
TASK: friday 
*/
/*
 * =====================================================================================
 *
 *       Filename:  friday.c
 *        Version:  1.0
 *        Created:  08/21/2011 05:31:43 PM
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

int main(void)
{
    FILE *fin = fopen("friday.in","r");
    FILE *fout = fopen("friday.out", "w");
    int n;
    int year = 1900; 
    int month = 1; 
    int count[7] = {0}; 
    int monthday[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
    int weekday = 6; 
    int max; 
    fscanf(fin, "%d", &n); 
    max = year + n; 
    for( year = 1900 ; year < max ; year++ ) {
        for( month = 1 ; month < 13 ; month++ ) {
            count[weekday] = count[weekday] + 1;
            if(month == 2){ // 闰年判断
                if(year % 400 == 0){ // 400 闰年
                    weekday = (weekday + 29) % 7; 
                }else if(year % 4 == 0 && year % 100 != 0){ // 普通闰年
                    weekday = (weekday + 29) % 7; 
                }else{ // 非闰年
                    weekday = (weekday + 28) % 7; 
                }
            }else{ // 普通月份
                weekday = (weekday + monthday[month]) % 7; 
            }
        }
    }
    fprintf(fout, "%d ", count[6]); 
    for( weekday = 0;  weekday < 5 ; weekday++ ){
        fprintf(fout, "%d ", count[weekday]); 
    }
    fprintf(fout, "%d\n", count[5]); 
    return 0;
}
