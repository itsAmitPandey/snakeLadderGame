#include <graphics.h>
#include <stdlib.h>
#include <iostream.h>
#include <conio.h>
#include <dos.h>
int p1=0,p2=0;
char pl1[15]={""},pl2[15]={"computer"};
struct snk
	{
	 int ax,ay,bx,by;
	}s1,s2,s3,s4,s5,s6;
struct ldr
	{
	 int ax,ay,bx,by;
	}l1,l2,l3,l4,l5,l7;
void intro();
void ds(int ax,int ay,int bx,int by)
{
int t=0,x,y;
setlinestyle(0,3,3);
  for(x=ax;x<bx;x=x+7)
  {
  if(t==0)
   {
   setcolor(4);
   x=x+12;
   y=ay+((by-ay)/(bx-ax))*(x-ax);
   circle(x,y,11);
   x=x+7;
   t++;
   }
  else{
	setcolor(1);
	y=ay+((by-ay)/(bx-ax))*(x-ax);
	circle(x,y,6);
      }
  }
}

void snake()
{
int i,x,y;
ds(s1.ax,s1.ay,s1.bx,s1.by);
ds(s2.ax,s2.ay,s2.bx,s2.by);
ds(s3.ax,s3.ay,s3.bx,s2.by);
ds(s4.ax,s4.ay,s4.bx,s4.by);
  {//snake---- 23-5
   setcolor(4);
   circle(320,290,11);
   setcolor(1);
   circle(305,305,7);
   circle(295,313,7);
   circle(285,322,6);
   circle(275,331,6);
   circle(265,340,6);
   circle(255,349,6);
   circle(245,358,5);
  }
}

void ladder()
{      int d=7;
setlinestyle(0,1,3);
setcolor(2);//7-29
line(l1.ax+d,l1.ay-d,l1.bx+d,l1.by-d);
line(l1.ax-d,l1.ay+d,l1.bx-d,l1.by+d);//68-96
line(l2.ax-d,l2.ay+d,l2.bx-d,l2.by+d);
line(l2.ax+2*d,l2.ay+2*d,l2.bx+2*d,l2.by+2*d);//42-49
line(l3.ax+d,l3.ay-d,l3.bx+d,l3.by-d);
line(l3.ax-d,l3.ay+d,l3.bx-d,l3.by+d);//57-83
line(l4.ax-d,l4.ay,l4.bx-d,l4.by+d);
line(l4.ax+2*d,l4.ay+2*d,l4.bx+2*d,l4.by+2*d);//12-31
line(l5.ax-d,l5.ay+d,l5.bx-d,l5.by+d);
line(l5.ax+2*d,l5.ay+2*d,l5.bx+2*d,l5.by+2*d);//51-72
line(l7.ax+d,l7.ay-d,l7.bx+d,l7.by-d);
line(l7.ax-d,l7.ay+d,l7.bx-d,l7.by+d);
}

void draw()
{
   int gdriver = DETECT, gmode, errorcode;
   int x, y, tx, ty, t, c;
   char ts[3];
   initgraph(&gdriver, &gmode, "");
   errorcode = graphresult();
   if (errorcode != grOk)
      cout<<"Graphics error:"<< grapherrormsg(errorcode);
   setbkcolor(0);
   x = getmaxx()-200;
   y =x-50;
   t=100;c=1;
for(ty=y/10; ty<y; ty=ty+y/10)
  {
   for(tx=x/10; tx<x; tx=tx+x/10)
    {
     if(c%2==0) setcolor(4);
     else setcolor(14);
     setlinestyle(0,3,3);
     rectangle(tx-x/10,ty-y/10,tx,ty);
     itoa(t,ts,10);
     setcolor(14);
     outtextxy(tx-x/15,ty-y/15,ts);
	//ladder position
	if(t==7)  { l1.ax=(tx-x/15); l1.ay=(ty-y/15); }
	if(t==29) { l1.bx=(tx-x/15); l1.by=(ty-y/15); }
	if(t==68) { l2.ax=(tx-x/15); l2.ay=(ty-y/15); }
	if(t==96) { l2.bx=(tx-x/15); l2.by=(ty-y/15); }
	if(t==24) { l3.ax=(tx-x/15); l3.ay=(ty-y/15); }
	if(t==49) { l3.bx=(tx-x/15); l3.by=(ty-y/15); }
	if(t==57) { l4.ax=(tx-x/15); l4.ay=(ty-y/15); }
	if(t==83) { l4.bx=(tx-x/15); l4.by=(ty-y/15); }
	if(t==12) { l5.ax=(tx-x/15); l5.ay=(ty-y/15); }
	if(t==31) { l5.bx=(tx-x/15); l5.by=(ty-y/15); }
	if(t==51) { l7.ax=(tx-x/15); l7.ay=(ty-y/15); }
	if(t==72) { l7.bx=(tx-x/15); l7.by=(ty-y/15); }
	//snake position
	if(t==99)  { s1.ax=(tx-x/15); s1.ay=(ty-y/15); }     //99
	if(t==5)  { s1.bx=(tx-x/15); s1.by=(ty-y/15); }      //55...
	if(t==86)  { s2.ax=(tx-x/15); s2.ay=(ty-y/15); }     //86
	if(t==32)  { s2.bx=(tx-x/15); s2.by=(ty-y/15); }     //42...
	if(t==95)  { s3.ax=(tx-x/15); s3.ay=(ty-y/15); }     //95
	if(t==32)  { s3.bx=(tx-x/15); s3.by=(ty-y/15); }     //62...
	if(t==38)  { s4.ax=(tx-x/15); s4.ay=(ty-y/15); }     //38
	if(t==6)   { s4.bx=(tx-x/15); s4.by=(ty-y/15); }      //16...
   t--;    c++;
    }    c++;
   }
   setfillstyle(SOLID_FILL,4);
   bar(0,400,630,470);
   setcolor(14);
   rectangle(10,410,620,460);
   settextstyle(4,0,5);
   outtextxy(100,405,"Snake  Ladder  Game");
   settextstyle(1,0,1);
}

void pos(int p1, int p2)
{
   int x, y, tx, ty, t;
   setbkcolor(0);
   x = getmaxx()-200;
   y =x-50;
   t=100;
for(ty=y/10; ty<y; ty=ty+y/10)
  {
   for(tx=x/10; tx<x; tx=tx+x/10)
    {
     setlinestyle(0,1,3);
     if(p1==t)
      {
       setcolor(1);
       circle(tx-x/20,ty-y/20,x/30);
      }
     if(p2==t)
      {
       setcolor(2);
       circle(tx-x/20,ty-y/20,x/30);
      }
      t--;
    }
  }
}

void clrpos(int p1, int p2)
{
   int x, y, tx, ty, t;
   setbkcolor(0);
   x = getmaxx()-200;
   y =x-50;
   t=100;
for(ty=y/10; ty<y; ty=ty+y/10)
  {
   for(tx=x/10; tx<x; tx=tx+x/10)
    {
     setlinestyle(0,1,3);
     if(p1==t)
      {
       setcolor(0);
       circle(tx-x/20,ty-y/20,x/30);
      }
     if(p2==t)
      {
       setcolor(0);
       circle(tx-x/20,ty-y/20,x/30);
      }
       t--;
    }
 }
}

void checkwinner(int p1,int p2)
{int i;
 if(p1==100)
  {
   setfillstyle(1,14);
   bar(100,80,550,300);
   setcolor(4);
   rectangle(110,90,540,290);
   settextstyle(10,0,5);
   outtextxy(220,150,"won.");
   outtextxy(220,100,pl1);
   getch();
   exit(0);
  }
  else if(p2==100)
  {
   setfillstyle(1,14);
   bar(100,80,550,300);
   setcolor(4);
   rectangle(110,90,540,290);
   settextstyle(10,0,5);
   outtextxy(220,150,"won.");
   outtextxy(220,100,pl2);
   getch();
   exit(0);
  }
}

int checkpos(int p)
{
switch(p)
 {       // snakes
 case 99: return(55);
 case 95: return(62);
 case 86: return(42);
 case 38: return(16);
 case 23: return(5);
   // Ladders
   case 68: return(96);
   case 57: return(83);
   case 51: return(72);
   case 24: return(49);
   case 12: return(31);
   case 7:  return(29);
   default:return(p);
 }
}

void dice(int n, int p)
{
char c[2];
int x=500, y=280, r=4; //dice position
itoa(p,c,10);
setfillstyle(SOLID_FILL,14);
bar(500,250,600,275);
setcolor(4);
if(p==1) {setcolor(1);outtextxy(515,250,pl1);}
else {setcolor(2);outtextxy(515,250,pl2);}
setfillstyle(SOLID_FILL,14);
bar(x,y,x+100,y+100);
setfillstyle(SOLID_FILL,4);
bar(x+10,y+10,x+90,y+90);
setcolor(14);
switch(n)
{
case 1:	circle(x+50,y+50,r); break;//4
case 2:	circle(x+30,y+30,r); //1
	circle(x+70,y+70,r);break;//7
case 3:	circle(x+30,y+30,r); //1
	circle(x+70,y+70,r);//7
	circle(x+50,y+50,r);break;//4
case 4: circle(x+30,y+30,r);//1
	circle(x+30,y+70,r);//3
	circle(x+70,y+30,r);//5
	circle(x+70,y+70,r);break;//7
case 5: circle(x+30,y+30,r);//1
	circle(x+30,y+70,r);//3
	circle(x+50,y+50,r);//4
	circle(x+70,y+30,r);//5
	circle(x+70,y+70,r);break;//7
case 6: circle(x+30,y+30,r);//1
	circle(x+30,y+50,r);//2
	circle(x+30,y+70,r);//3
	circle(x+70,y+30,r);//5
	circle(x+70,y+50,r);//6
	circle(x+70,y+70,r);break;//7
}
}

void score()
{
char s1[3],s2[3];
setcolor(14);
bar(460,100,640,230);
rectangle(465,105,635,225);
outtextxy(500,110,"SCOREBOARD");
outtextxy(470,140,"Player:1  Player:2");
itoa(p1,s1,10);itoa(p2,s2,10);
outtextxy(500,170,s1);
outtextxy(590,170,s2);
}

void main()
{  int t1,t2,tp1,tp2,i,n=0,x=460,y=10,j,k;
   char ce;
   intro();
   draw();
   ladder();
   snake();
   dice(0,1);
   score();
do{
  pos(p1,p2);
  tp1=p1;tp2=p2;
  if(n%2==0)
   {
   setfillstyle(SOLID_FILL,4);
   bar(x,y,x+260,y+80);
   setcolor(1);
   outtextxy(x+30,y+5,"Player.1 turn");
   setfillstyle(SOLID_FILL,1);
   bar(x+10,y+30,x+170,y+70);
   ce=getch(); //check exit
   if((int)ce == 27)
   exit(0);
   randomize();
   t1=rand()%6;
   dice(t1+1,1);
    for(j=p1;j<=p1+t1+1;j++)
     {
      pos(j,p2);
      delay(200);
      clrpos(j,p2);
     }
   if(p1+t1+1<=100)
     p1=checkpos(p1+t1+1);
     //if(p1==p2) p2=0;     //katne wala ni ho rha
   }
  else
   {
   setfillstyle(SOLID_FILL,4);
   bar(x,y,x+260,y+80);
   setcolor(2);
   outtextxy(x+30,y+5,"Player.2 turn");
   setfillstyle(SOLID_FILL,2);
   bar(x+10,y+30,x+170,y+70);
   ce=getch();
   if((int)ce == 27)
   exit(0);
   randomize();
   t2=rand()%6;
   dice(t2+1,2);
     for(j=p2;j<=p2+t2+1;j++)
     {
      pos(p1,j);
      delay(200);
      clrpos(p1,j);
     }
   if(p2+t2+1<=100)
     p2=checkpos(p2+t2+1);
   //  if(p2==p1) p1=0;  //katne wala nhi ho rha
   }
  delay(500);
  clrpos(tp1,tp2);
  pos(p1,p2);
  ladder();
  score();
  checkwinner(p1,p2);
  n++;
}while(1);
}

void intro(void)
{
   int gdriver = DETECT, gmode;
   int p=1,i=350;
   char ch=56;
   initgraph(&gdriver, &gmode, "");
   setcolor(4);
   setfillstyle(SOLID_FILL,14);
   bar(50,420,550,435);
   outtextxy(335,425,"Press ESC to exit anytime");
   outtextxy(55,425," 8:UP   2:DOWN     ENTER:SELECT");
   setfillstyle(SOLID_FILL,4);
   bar(50,60,550,400);
   setfillstyle(SOLID_FILL,14);
   bar(60,70,540,390);
   delay(1000);
   for(i=0;i<=85;i++)
   {
   setfillstyle(SOLID_FILL,14);
   bar(60,70,540,390);
   settextstyle(10,0,3);
   outtextxy(60+i,90,"SNAKE");
   outtextxy(405-i,90,"LADDER");
//   delay(20);
   }
   setcolor(1);
   outtextxy(280,90,"&");
   setcolor(4);
   setlinestyle(0,3,3);
   line(145,140,458,140);
   settextstyle(1,0,3);
   delay(400);
   setcolor(1);
   outtextxy(100,200,"PLAYER MODE");
   settextstyle(1,0,1);
   delay(200);
   outtextxy(160,240,"SINGLE PLAYER");
   delay(200);
   outtextxy(160,270,"DOUBLE PLAYER");
   settextstyle(10,0,1);
   outtextxy(145,228,">");
   ch=getch();
 do {
     if((int)ch==50)
     {
      setcolor(14);
      outtextxy(145,228,">");
      setcolor(4);
      outtextxy(145,258,">");
      p=2;
     }
     if((int)ch==56)
      {
      setcolor(14);
      outtextxy(145,258,">");
      setcolor(4);
      outtextxy(145,228,">");
      p=1;
      }
      ch=getch();
      if((int)ch==27) exit(0);
      if((int)ch==13) break;
   }while(1);
   gotoxy(100,70);
   cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
   cout<<"\tPlayer 1:";
   cin.getline(pl1,10);
   cout<<"\tPlayer 2:";
   if(p==1)      cout<<pl2;
   else if(p==2) cin.getline(pl2,10);
   getch();
}