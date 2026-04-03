#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#include "twixt.h"
#include "links.h"

void init_links() {
   for(int i=0;i<25;i++){
    for(int j=0;j<25;j++){
        for(int k=0;k<8;k++){
            links[i][j][k]=false;
            l_color[i][j][k]=0;
        }
    }
   }
}

bool link_intersect(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){

    if((x1==x3 && y1==y3) || (x1==x4 && y1==y4) ||
       (x2==x3 && y2==y3) || (x2==x4 && y2==y4)){
        return false;
    }

    long long d_X1=x2-x1;
    long long d_Y1=y2-y1;
    long long d_X2=x4-x3;
    long long d_Y2=y4-y3;
    long long d_X3=x3-x1;
    long long d_Y3=y3-y1;

    long long det=d_X1*(-d_Y2)-(d_Y1*(-d_X2));
    if(det==0){
        return false; 
    }

    long long d_x=d_X3 * d_Y2 - d_Y3 * d_X2;
    long long d_y=d_X3 * d_Y1 - d_Y3 * d_X1;

    if(det>0){
        if(d_x>=0 && d_x<=det && d_y>=0 && d_y<=det){
            return true;
        }   
        else{
            if(d_x<=0 && d_x>=det && d_y<=0 && d_y>=det){
                return true;
            }
        }
    }else{
        if(d_x<=0 && d_x>=det && d_y<=0 && d_y>=det){
            return true;
        } 
    }
    return false;
}

bool chk_clinks(int x1,int y1,int x2,int y2,char color){
    for(int i=1;i<25;i++){
        for(int j=1;j<25;j++){
            for(int k=0;k<8;k++){
                if(links[i][j][k]){
                    int kx=i+k_moves[k][0];
                    int ky=j+k_moves[k][1];
                    if(link_intersect(x1,y1,x2,y2,i,j,kx,ky)){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void a_link(int x,int y,char color){
    for(int i=0;i<8;i++){
        int kx=x+k_moves[i][0];
        int ky=y+k_moves[i][1];
        
        if(kx<1 || kx>24 || ky<1 || ky>24){
            continue;
        }
        
        if(arr[kx][ky]!=color){
            continue;           
        }
        
        if(links[x][y][i]==true){
            continue;
        }

        if(chk_clinks(x,y,kx,ky,color)==true){
            printf("Link cannot be formed between (%d,%d) and (%d,%d). A crossing link already exists.\n", kx, ky, x, y);
            continue;   
        }

        links[x][y][i]=true;
        l_color[x][y][i]=color;
        
        for(int j=0;j<8;j++){
            int Dx=kx-x;
            int Dy=ky-y;
            if(-Dx==k_moves[j][0] && -Dy==k_moves[j][1]){
                links[kx][ky][j]=true;
                l_color[kx][ky][j]=color;
                break;
            }
        }
    }
}

