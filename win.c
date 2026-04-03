#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#include "links.h"
#include "twixt.h"
#include "win.h"




bool check_win(char color){
    bool dp[25][25];
    for(int i=0;i<25;i++){
        for(int j=0;j<25;j++){
            dp[i][j]=false;
        }
    }
    if(color=='R'){
        for(int j=1;j<25;j++){
            if(arr[1][j]=='R'){
                dp[1][j]=true;
            }
        }
        bool visited=true;
        while(visited){
            visited=false;
            for(int i=0;i<25;i++){
                for(int j=0;j<25;j++){
                    if(dp[i][j]==true && arr[i][j]=='R'){
                        for(int k=0;k<8;k++){
                    if(links[i][j][k] && l_color[i][j][k]=='R'){
                        int ni=i+k_moves[k][0];
                        int nj=j+k_moves[k][1];
                        if(ni>=1 && ni<25 && nj>=1 && nj<25){
                            if(dp[ni][nj]==false){
                                dp[ni][nj]=true;
                                visited=true;
                            }
                        }
                    }
                }
            }
        }
    }
}
for(int j=1;j<25;j++){
    if(dp[24][j]){
        return true;
    }
}

    }else{
        for(int j=1;j<25;j++){
            if(arr[j][1]=='B'){
                dp[j][1]=true;
            }
        }
        bool visited=true;
        while(visited){
            visited=false;
            for(int i=0;i<25;i++){
                for(int j=0;j<25;j++){
                    if(dp[i][j]==true && arr[i][j]=='B'){
                        for(int k=0;k<8;k++){
                    if(links[i][j][k] && l_color[i][j][k]=='B'){
                        int ni=i+k_moves[k][0];
                        int nj=j+k_moves[k][1];
                        if(ni>=1 && ni<25 && nj>=1 && nj<25){
                            if(dp[ni][nj]==false){
                                dp[ni][nj]=true;
                                visited=true;
                            }
                        }
                    }
                }
            }
        }
    }
}
for(int j=1;j<25;j++){
    if(dp[j][24]){
        return true;
    }
}
    }
    return false;
}

