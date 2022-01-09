#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <windows.h>
#define MAXTL 100
int len=35,wid=167;

int headX,headY,fruitX,fruitY,gameOver,level,flag=0,score=0;
int tailX[MAXTL];int tailY[MAXTL];
int countTail=0;
void draw();
void defaultsetting();
void userinput();
void my_sleep(int level);
//void delay();

void draw(){
system("cls");


    for(int i=0;i<len;i++)
    {
        for(int j=0;j<wid;j++){
            if(i==0 || i==len-1){
                printf("#");

            }
            else if(j==0 || j==wid-1){
                printf("#");

            }
            else{
                    if(i==headX && j==headY){
                      printf("O");
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
do{
    fruitX=rand()%20;
    fruitY=rand()%20;
}while(fruitX==0||fruitY==0);
}
void userinput(){
    if(kbhit())
        {

        switch(getch()){
        case 72://up
            flag=1;
            break;

        case 75://left
            flag=2;
            break;

        case 77://right
            flag=3;
            break;

        case 80://down
            flag=4;
            break;

        case 'q':
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
            //printf("Inside default");
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
do{
   fruitX=rand()%20;
   fruitY=rand()%20;
}while(fruitX==0 ||fruitY==0);
score+=10;
countTail++;

}
}

int main(){
    int m,n;
    char c;

    srand(time(0));

    defaultsetting();
    printf("- X --- X --- X --- X --- X --- X --- X --- X --- X --- SNAKE GAME --- X --- X --- X --- X --- X --- X --- X --- X --- X -\n");
    printf("User can use arrow keys for upward,left,right & downward movements.\n");
    printf("Enter level of game as 1 or 2 or 3\n");
    scanf("%d",&level);
    //ShowWindow(GetConsoleWindow(),SW_MAXIMIZE);
    while(!gameOver)
    {

        draw();
        userinput();
        logic();
        my_sleep(level);
    }

    printf("Your Score =%d",score);

    return 0;
}
void my_sleep(int level){
    if(level==1){
        sleep(1);
    }
    else if(level==2){
        sleep(0.5);
    }
    else if(level==3){
        sleep(0);
    }
}
