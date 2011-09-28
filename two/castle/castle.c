/*
ID: fanzeyi1
LANG: C
TASK: castle 
*/
/*
 * =====================================================================================
 *
 *       Filename:  castle.c
 *        Version:  1.0
 *        Created:  09/18/2011 10:46:53 AM
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
#define EAST() if(!color[a][b+1]){floodfill(a, b+1, colo); count = count + 1; } // 东
#define WEST() if(!color[a][b-1]){floodfill(a, b-1, colo); count = count + 1; } // 西
#define SOUTH() if(!color[a+1][b]){floodfill(a+1, b, colo); count = count + 1; } // 南
#define NORTH() if(!color[a-1][b]){floodfill(a-1, b, colo); count = count + 1; } // 北
#define EAST_COLOR() if(!room_area[a][b+1]){setColor(a, b+1, colo); } // 东
#define WEST_COLOR() if(!room_area[a][b-1]){setColor(a, b-1, colo); } // 西
#define SOUTH_COLOR() if(!room_area[a+1][b]){setColor(a+1, b, colo); } // 南
#define NORTH_COLOR() if(!room_area[a-1][b]){setColor(a-1, b, colo); } // 北
#define CHECK_EAST() if(j != x-1 && color[i][j] != color[i][j+1] && room_area[i][j]+room_area[i][j+1]>max[0]){max[0] = room_area[i][j]+room_area[i][j+1]; max[1]=i+1; max[2]=j+1; max[3]=0; }
#define CHECK_NORTH() if(i != 0 && color[i][j] != color[i-1][j] && room_area[i][j]+room_area[i-1][j]>max[0]){max[0] = room_area[i][j]+room_area[i-1][j]; max[1]=i+1; max[2]=j+1; max[3]=1;  }


int **room; 
int **color; 
int **room_area; 
int x, y; 
int count = 1; 
int room_count = 1; 
int max_area; 

/*
 *
 * b+1 东 b-1 西
 * a+1 南 a-1 北
 *
 */

void floodfill(int a, int b, int colo) {
    if( a == y || b == x) {
        return; 
    }
    color[a][b] = colo; 
    switch(room[a][b]) {
        case 0:
            EAST(); 
            WEST(); 
            NORTH(); 
            SOUTH(); 
            break; 
        case 1: 
            // 东面 南面 北面 无墙
            EAST(); 
            SOUTH(); 
            NORTH(); 
            break; 
        case 2:
            // 东 西 南
            EAST();
            WEST(); 
            SOUTH(); 
            break; 
        case 3:
            // 东 南
            EAST(); 
            SOUTH(); 
            break; 
        case 4:
            // 西 南 北
            WEST(); 
            SOUTH(); 
            NORTH(); 
            break; 
        case 5:
            // 南 北
            SOUTH(); 
            NORTH(); 
            break; 
        case 6:
            // 西 南
            WEST(); 
            SOUTH(); 
            break; 
        case 7:
            // 南
            SOUTH(); 
            break; 
        case 8:
            // 西 北 东
            WEST(); 
            EAST(); 
            NORTH(); 
            break; 
        case 9:
            // 东 北
            EAST(); 
            NORTH(); 
            break; 
        case 10:
            // 东 西
            EAST(); 
            WEST(); 
            break; 
        case 11:
            // 东
            EAST(); 
            break; 
        case 12:
            // 西 北
            WEST(); 
            NORTH(); 
            break; 
        case 13:
            // 北
            NORTH(); 
            break; 
        case 14:
            // 西
            WEST(); 
            break; 
        case 15:
            break; 
    }
}

void setColor(int a, int b, int colo) {
    if( a == y || b == x) {
        return; 
    }
    room_area[a][b] = colo; 
    switch(room[a][b]) {
        case 0:
            EAST_COLOR(); 
            WEST_COLOR(); 
            NORTH_COLOR(); 
            SOUTH_COLOR(); 
            break; 
        case 1: 
            // 东面 南面 北面 无墙
            EAST_COLOR(); 
            SOUTH_COLOR(); 
            NORTH_COLOR(); 
            break; 
        case 2:
            // 东 西 南
            EAST_COLOR();
            WEST_COLOR(); 
            SOUTH_COLOR(); 
            break; 
        case 3:
            // 东 南
            EAST_COLOR(); 
            SOUTH_COLOR(); 
            break; 
        case 4:
            // 西 南 北
            WEST_COLOR(); 
            SOUTH_COLOR(); 
            NORTH_COLOR(); 
            break; 
        case 5:
            // 南 北
            SOUTH_COLOR(); 
            NORTH_COLOR(); 
            break; 
        case 6:
            // 西 南
            WEST_COLOR(); 
            SOUTH_COLOR(); 
            break; 
        case 7:
            // 南
            SOUTH_COLOR(); 
            break; 
        case 8:
            // 西 北 东
            WEST_COLOR(); 
            EAST_COLOR(); 
            NORTH_COLOR(); 
            break; 
        case 9:
            // 东 北
            EAST_COLOR(); 
            NORTH_COLOR(); 
            break; 
        case 10:
            // 东 西
            EAST_COLOR(); 
            WEST_COLOR(); 
            break; 
        case 11:
            // 东
            EAST_COLOR(); 
            break; 
        case 12:
            // 西 北
            WEST_COLOR(); 
            NORTH_COLOR(); 
            break; 
        case 13:
            // 北
            NORTH_COLOR(); 
            break; 
        case 14:
            // 西
            WEST_COLOR(); 
            break; 
        case 15:
            break; 
    }
}

int cmp(const void *a, const void *b) {
    return *(int*)b - *(int*)a; 
}

int main(void) {
    FILE *fin = fopen("castle.in","r");
    FILE *fout = fopen("castle.out", "w");
    int i, j; 
    int max[4] = {0, 0, 0}; 
    fscanf(fin, "%d %d", &x, &y); 
    room = (int**)malloc(sizeof(int*)*y); 
    color = (int**)malloc(sizeof(int*)*y); 
    room_area = (int**)malloc(sizeof(int*)*y); 
    for( i = 0 ; i < y ; i++ ) {
        room[i] = (int*)calloc(x, sizeof(int)); 
        color[i] = (int*)calloc(x, sizeof(int)); 
        room_area[i] = (int*)calloc(x, sizeof(int)); 
        for( j = 0 ; j < x ; j++ ) {
            fscanf(fin, "%d", &room[i][j]); 
        }
    }
    for( i = 0 ; i < y ; i++ ) {
        for( j = 0 ; j < x ; j++ ) {
            if(!color[i][j]) {
                count = 1; 
                floodfill(i, j, room_count++); 
                setColor(i, j, count); 
                if(count > max_area) {
                    max_area = count; 
                }
            }
        }
    }
    for( j = 0 ; j < x ; j++ ) {
        for( i = y-1 ; i >= 0 ; i-- ) {
            switch(room[i][j]) {
                case 0:
                    break; 
                case 1: 
                    // 东面 南面 北面 无墙
//                    CHECK_WEST(); 
                    break; 
                case 2:
                    // 东 西 南
                    CHECK_NORTH(); 
                    break; 
                case 3:
                    // 东 南
//                    CHECK_WEST(); 
                    CHECK_NORTH(); 
                    break; 
                case 4:
                    // 西 南 北
                    CHECK_EAST(); 
                    break; 
                case 5:
                    // 南 北
                    CHECK_EAST(); 
//                    CHECK_WEST(); 
                    break; 
                case 6:
                    // 西 南
                    CHECK_NORTH(); 
                    CHECK_EAST(); 
                    break; 
                case 7:
                    // 南
//                    CHECK_WEST(); 
                    CHECK_NORTH(); 
                    CHECK_EAST(); 
                    break; 
                case 8:
                    // 西 北 东
//                    CHECK_SOUTH(); 
                    break; 
                case 9:
                    // 东 北
//                    CHECK_WEST(); 
//                    CHECK_SOUTH(); 
                    break; 
                case 10:
                    // 东 西
                    CHECK_NORTH(); 
//                    CHECK_SOUTH(); 
                    break; 
                case 11:
                    // 东
//                    CHECK_WEST(); 
                    CHECK_NORTH(); 
//                    CHECK_SOUTH();
                    break; 
                case 12:
                    // 西 北
                    CHECK_EAST(); 
//                    CHECK_SOUTH(); 
                    break; 
                case 13:
                    // 北
//                    CHECK_WEST(); 
                    CHECK_EAST(); 
//                    CHECK_SOUTH(); 
                    break; 
                case 14:
                    // 西
                    CHECK_NORTH(); 
                    CHECK_EAST(); 
//                    CHECK_SOUTH(); 
                    break; 
                case 15:
//                    CHECK_WEST(); 
                    CHECK_NORTH(); 
                    CHECK_EAST(); 
//                    CHECK_SOUTH(); 
                    break; 
            }
        }
    }
    for( i = 0 ; i < y ; i++ ) {
        for( j = 0 ; j < x ; j++ ) {
            printf("%d ", color[i][j]); 
        }
        printf("\n"); 
    }
    fprintf(fout, "%d\n", room_count - 1); 
    fprintf(fout, "%d\n", max_area); 
    fprintf(fout, "%d\n%d %d ", max[0], max[1], max[2]);
    if(max[3]) {
        fprintf(fout, "N\n"); 
    }else{
        fprintf(fout, "E\n"); 
    }
    return 0;
}
