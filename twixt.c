#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "twixt.h"

char arr[25][25];
bool links[25][25][8];
char l_color[25][25][8];

int k_moves[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};


void init_game() {
    for(int i=0;i<25;i++){
        for(int j=0;j<25;j++){
            arr[i][j]='.';
        }
    }
}

void display_board(char arr[25][25]) {
    printf("================================================================================\n");
    printf("    ");
for (int j=1;j<25;j++) {
if (j==1) {
    printf("%2d|",j);
 } else if (j==24) {
    printf("|%3d",j);
 } else if (j<=9) {
      printf("%2d ",j);
 } else {
      printf("%3d",j);
      }
    }
    printf("\n");
for (int i=1; i<25;i++) {
  printf("%2d ",i);
   for (int j=1; j< 25;j++) {
  if ((i==1 && j==1) || (i==24 && j==1)) {
    if (j==1 || j==23) {
         printf("   |");
       }
  continue;
  } else if ((i==1 && j==24) || (i==24 && j==24)) {
    continue;
  } else {
     printf(" %c ", arr[i][j]);
    if (j==1 || j==23) {
       printf("|");
     }
  }
}
  if (i==1 || i==23) {
   printf("\n");
      for (int j=1;j<=26;j++) {
         printf("---");
     }
  }
        printf("\n");
     }
    printf("================================================================================\n");
}


bool valid_move(int x,int y, char color,int count){

if((x==1 && y==1) || (x==24 && y==24) || (x==1 && y==24) || (x==24 && y==1)){
        printf("Invalid Move!!!\n");
        return false;
    }
if(color=='B' && (x==1 || x==24)){
        printf("Invalid Move. You can't put pin here because this row is only for Red.\n");
        return false;
    }
if(color=='R' && (y==1 || y==24)){
    printf("Invalid Move. You can't put pin here because this column is only for Black.\n");
        return false;
    }

if(x>24 || y>24 || x<1 || y<1){
    printf("Invalid Move!!!\n");
    return false;
}
if(arr[x][y]=='B' && color=='B'){
    printf("Black is already there. Enter a valid move.\n");
    return false;

}

if(arr[x][y]=='R' && color=='R'){
     printf("Red is already there. Enter a valid move.\n");
    return false;
}
return true;
}


void place_pin(int x,int y,char color){
    arr[x][y]=color;
}


