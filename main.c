#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#include "twixt.h"
#include "links.h"
#include "win.h"


int main(){
    init_game();
    init_links();
    display_board(arr);

    int count=1;
    bool over=false;
    while(over==false){
        int x,y;
        char dump;
        char pin;
        if(count%2!=0){
            printf("Red's Turn (x<space>y): ");
            pin='R';
        }else{
            printf("Black's Turn (x<space>y): ");
            pin='B';
        }
      int num= scanf("%d%c%d",&x,&dump,&y);
       if(num!=3){
            printf("Invalid Move!. Please enter two digits separated by space.\n");
            while(getchar()!='\n');
            continue;
        }
        if(dump!=' '){
            printf("Invalid Move!. Please enter two digits separated by space.\n");
            continue;
        }
        if(valid_move(x,y,pin,count)==false){
            continue;
        }
        place_pin(x,y,pin);
        a_link(x,y,pin);
        
        count++;
        display_board(arr);
        if(check_win(pin)==true){
            if(pin=='R'){
                printf("!*==============*!\n");
                printf("   Red Wins!!!\n");
                printf("!*==============*!\n");
                printf("\n");
                int c;
                printf("Play again?(1 for Yes, 0 for No):  ");
                scanf("%d",&c);
                if(c==1){
                    init_game();
                    init_links();
                    display_board(arr);
                    count=1;
                    continue;
                }else{

                over = true;
            }
                 
            }else{
                printf("!*==============*!\n");   
                printf("   Black Wins!!!\n");
                printf("!*==============*!\n");  
                printf("\n");
                int c;          

                printf("Play again?(1 for Yes, 0 for No):  ");
                scanf("%d",&c);

                if(c==1){
                    init_game();
                    init_links();
                    display_board(arr);
                    count=1;
                    continue;
                }else{
                 over = true;
            }
        }
       
    }
   

} 
return 0;
}