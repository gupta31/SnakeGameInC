#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAXTL 100
int len=20,wid=20;
int headX,headY,fruitX,fruitY,gameOver,flag,score=0;
int tailX[MAXTL];int tailY[MAXTL];
int countTail=0;
void draw();
void defaultsetting();
void userinput();
void delay();

void draw(){
    system("cls");

    for(int i=0;i<len;i++)
    {
        for(int j=0;j<wid;j++){
            if(i==0 || i==len-1){
                printf("=");
            }
            else if(j==0 || j==wid-1){
                printf("#");
            }
            else{
                    if(i==headX && j==headY){
                      printf(">");
                    }
                    else if(i==fruitX && j==fruitY){
                      printf("*");
                    }
                    else{
                            int tail=0;
                        for(int k=0;k<countTail;k++){
                            if(i==tailX[k]&& j==tailY[k]){
                                printf("-");
                                tail=1;
                            }
                        }
                        if(tail==0){
                            printf(" ");
                        }

                    }

            }
        }
        printf("\n");
    }



}
void defaultsetting(){
    gameOver=0;
    headX=len/2;
    headY=wid/2;
label1:
    fruitX=rand()%20;
    if(fruitX==0){
        goto label1;
    }
label2:
    fruitY=rand()%20;
    if(fruitY==0){
        goto label2;
    }
}
void userinput(){
    if(kbhit()){
        switch(getch()){
        case 'u':
            flag=1;
            break;

        case 'l':
            flag=2;
            break;

        case 'r':
            flag=3;
            break;

        case 'd':
            flag=4;
            break;

        case 'z':
            gameOver=1;
            break;
        }
    }
}
void logic(){

    int i,prev2X,prev2Y;
    int prevX=tailX[0];
    int prevY=tailY[0];
    tailX[0]=headX;
    tailY[0]=headY;
    for(i=1;i<countTail;i++){
        prev2X=tailX[i];
        prev2Y=tailY[i];
        tailX[i]=prevX;
        tailY[i]=prevY;
        prevX=prev2X;
        prevY=prev2Y;
    }
    switch(flag){
        case 1:
            headX--;
            break;
        case 2:
            headY--;
            break;
        case 3:
            headY++;
            break;
        case 4:
            headX++;
            break;
        default:
            printf("Inside default");
            break;

    }
if(headX <0|| headX>len||headY<0||headY>wid){
        gameOver=1;
    }
for(i=0;i<countTail;i++){
    if(i==tailX[i]&& i==tailY[i]){
        gameOver=1;
    }
}
if(headX==fruitX&& headY==fruitY)
{
label3:
    fruitX=rand()%20;
    if(fruitX==0)
        goto label3;

label4:
    fruitY=rand()%20;
    if(fruitY==0)
        goto label4;
    score+=10;
countTail++;

}
}

int main(){
    int m,n;
    char c;

    label5:
    defaultsetting();

    while(!gameOver)
    {
        draw();
        userinput();
        logic();
        for(int m=0;m<10000;m++)
            {
            for(int n=0;n<20000;n++)
            {

            }
        }
    }

    printf("Your Score =%d",score);
    printf("\nPress Y to continue again:");
    scanf("%c",&c);
    if(c=='y'|| c=='Y')
        goto label5;
    return 0;
}
