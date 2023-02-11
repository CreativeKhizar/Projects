#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
int height=70;
int width=20;
int i,j,k;
int x,y,fruitx,fruity;
int flag;
int gameover=1;int score;
int tailx[100],taily[100];
int counttail=0;
int z;
int n=0;
FILE *fp;
void setup()
{
     x=width/2;
     y=height/2;
     label:
     fruitx=rand()%20;
     if(fruitx<=1||fruitx>=height-1)
     goto label;
     back:
     fruity=rand()%20;
     if(fruity<=1||fruity>=width-1)
     goto back;
     score=0;
}
void draw()
{
       clrscr();
     for(i=0;i<width;i++)
     {
	for(j=0;j<height;j++)
	{
	  if(j==0||i==0||j==height-1||i==width-1)
	  {
	     printf("*");
	  }
	 else
	 {
	   if(i==x&&j==y)
	   printf("0");
	   else if(i==fruitx&&j==fruity)
	   printf("@");
	   else
	   {
	    int ch=0;
	    for(k=0;k<counttail;k++)
	    {
	     if(i==tailx[k]&&j==taily[k])
	     {
		 printf("o");
		 ch=1;
	     }
	     }
	     if(ch==0)
	       printf(" ");

	  }
	  }
	  }
	 printf("\n");
     }
 }
 void input()
 {
   if(kbhit())
   {
     switch(getch())
     {
     case 75:   flag=1;
		  break;
     case 77:    flag=2;
		break;
     case 72:    flag=3;
		break;
     case 80:    flag=4;
		break;
     default:
		break;
     }
 }
 }
 void logic()
 {

    int prevx=tailx[0];
    int prevy=taily[0];
    int prev2x,prev2y;
     tailx[0]=x;
     taily[0]=y;


      for(i=1;i<counttail;i++)
      {
	 prev2x=tailx[i];
	 prev2y=taily[i];
	 tailx[i]=prevx;
	 taily[i]=prevy;
	 prevx=prev2x;
	 prevy=prev2y;
      }
      switch(flag)
      {
      case 1: y--;
	      break;
      case 2: y++;
	      break;
      case 3: x--;
	      break;
      case 4: x++;
	      break;
     }
     if(fruitx==x&&fruity==y)
     {
       help:
       fruitx=rand()%20;
       if(fruitx==0)
       goto help;
       how:
       fruity=rand()%20;
       if(fruity==0)
       goto how;
       score=score+1;
       sound(50);
       delay(5);
       counttail++;
       n=n+1;
       if(n%2==1)
       fruity=5*((n%5)-1)+fruity;
       nosound();
     }
     if(x<=0||x>=width-1||y<=0||y>=height-1)
     gameover=0;
     for(z=0;z<counttail;z++)
     {
       if(x==tailx[z]&&y==taily[z])
       gameover=0;
     }
 }
void main()
{
   int t,i;
   char ch[50];
   clrscr();
   i=0;
   printf("The rules of the game are\n press Up arrow key to move the snake up \nDown arrow key to move the snake down \n Left arrow key to make the snake move left\n Right arrow key to move the snake right\n");
   printf("If you understand the rules then press enter to start the game");
   getch();
   clrscr();
   setup();
   while(gameover)
   {
   sound(i);
   draw();
   input();
   logic();
   printf("Score=%d",score);
   delay(100);
   i++;
   }
   clrscr();
   fp=fopen("Number.txt","r");
   fscanf(fp,"%d",&t);
   printf("Game over\n");
   if(t<score)
   {
     fp=fopen("Number.txt","w");
     fprintf(fp,"%d",score);
     printf("New Highscore\n");
     printf("Enter your name\n");
     gets(ch);
     fprintf(fp,"%s",ch);
   }
   printf("Score=%d\n",score);
   if(t>score)
   {
      fscanf(fp,"%d",t);
      fscanf(fp,"%s",ch);
      printf("High score is:%d\n",t);
      printf("By %s",ch);
   }
   getch();
   getch();
   nosound();
}