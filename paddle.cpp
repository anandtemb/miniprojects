Paddle

#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<ctype.h>

struct but3d
{
   int x,y;
}b[80];
struct opt
{
   int x,y;
   int flag;
   int count;
}op[20];
struct dump
{
   int sc;
   char name[25];
}d[80];

int       bricount=0,count=4,dx=10,x=400,y=400,bcnt=14,ii,length=60;
int       color,incy=0,fallflag=0,dely=5000,padhit=0;
int
ry=390,rx=425,dy=10,score=0,xb,yb,k=233,level=1,j,l=20,w=10,but,escflag=0;
char      s1[10],s[20],ch[1],mx,my,re,open;
int       a[80],t,c[80];
int       hiscore,opc =4;


char      restart();
char      openscreen();
main()
{
union REGS i,o;
int gd=DETECT,gm;
char *p1;
/* start();*/
initgraph(&gd,&gm," ");
setcolor(10);
rectangle(10,10,630,410);
open = openscreen();
switch(toupper(open))
 {
    case  'D' :    dely = 1000; break;
    case  'N' :    dely = 2000; break;
    case  'E' :    dely = 4000; break;
 }
b[1].x=10+2*l;
b[1].y=100;
settextstyle(1,0,3);
sprintf(s1,"Lifes = %d",count);
                    setcolor(6);
                    outtextxy(400,450,s1);
sprintf(s,"Score = %d",score);
                      setcolor(3);
                      outtextxy(100,450,s);
   
  circ()
{
	int i;
	for(i=0;i<15;i++)
		circle(320,240,i*10);
	rectangle(240,160,400,320);
}

bulb()
{
	int i=1,c=1;
	randomize();
	while(!kbhit())
	{
		if((i%2)==0)
			setcolor(c++);
		setfillstyle(1,getcolor());
		circle(320,240,i*20);
		putpixel(320-i+2,240-i+2,1);
		floodfill(320-i+2,240-i+2,getcolor());
		delay(1000);
		i++;
		if(i>=5)
			i=1;
	}
}

dot()
{
	int i,j,of=40,wid=5;
	setcolor(8);
	setfillstyle(1,getcolor());
	for(i=of;i<getmaxx();i+=of)
		bar(i,0,i+wid,getmaxy());

	for(i=of;i<getmaxy();i+=of)
		bar(0,i,getmaxx(),i+wid);

	for(i=of;i<getmaxx();i+=of)
		for(j=of;j<getmaxy();j+=of)
		{
			setcolor(15);
			setfillstyle(1,getcolor());
			circle(i+2,j+2,4);
			floodfill(i+2,j+2,getcolor());
		}

}


LEVEL :
settextstyle(0,0,1);
if(level==1)
{
   bcnt=63;
   mess1();
}
if(level==2)
{
  bcnt =60;
   mess2();
}

if(level==3)
 {
    bcnt=72;
    mess3();
 }
if(level ==4)
 {
    bcnt = 60;
    mess4();
 }


paddle(x,y,7,length);

sprintf(ch,"%c",k);
setcolor(12);
outtextxy(rx,ry,ch);
settextstyle(1,0,5);
setcolor(2);
rectangle(95,195,600,260);
rectangle(97,197,598,258);

S:
setcolor(12);
outtextxy(100,200,"Press ( SPACE ) to Play");
flushall();
if(getch()!=32)
goto   S;

sprintf(ch,"%c",k);
layer(20,190,610,300);
setcolor(0);
 settextstyle(0,0,1);
outtextxy(rx,ry,ch);
setcolor(4);
op[1].y = 150;
op[1].x = b[25].x;



for(t=1;t<=bcnt;t++ )  { a[t]=0; }
   while( 1)
     {
      setcolor(10);
      rectangle(10,10,630,410);
      if(ry>=y-6-4  )  {
                          if(rx<x+length/6) dx = -30;
                                                     if(rx>x+length-length/6) dx =  30;
                                                     if(rx<=x+length/3&&rx>=x+length/6) dx=-10;
                                                     if(rx>=x+length-length/3&&rx<=x+length-length/6) dx=10;
                                                     if(rx>x+length/3&&rx<=x+length-length/3)  dx = 5;

                                                     music(50);
                                                     dy = -dy;
                                                     music(0);
                                                  }
      if(ry<=10+6+4 )  {music(50); dy =  10; music(0); }
      if(rx>=630-6-10) {music(50); dx = -dx; music(0); }
      if(rx<=10+6+4 )  {music(50); dx = -dx; music(0); }
      ry= ry+dy;
      rx= rx+dx;


      sprintf(ch,"%c",k);
      setcolor(12);
      outtextxy(rx,ry,ch);
      delay(dely);
      setcolor(0);
      outtextxy(rx,ry,ch);
                xb=x;yb=y;

      if(kbhit())
                {
                  i.h.ah=0;
                  int86(22,&i,&o);
                  if(o.h.ah==1)   escflag=1;
                  if(o.h.ah==75)  {
music(41);paddle(x,y,0,length);x-=length/2;paddle(x,y,7,length);
music(0); }
                  if(o.h.ah==77)  {
music(41);paddle(x,y,0,length);x+=length/2;paddle(x,y,7,length);
music(0); }
                  if(o.h.ah==83)  {
                                                        settextstyle(0,0,2);
                                                        setcolor(14);
                                                        rectangle(20,195,600,298);
                                                        rectangle(22,197,598,300);
                                                        setcolor(1);
                                                        outtextxy(120,210,"       ( PAUSE ) " );
                                                        outtextxy(50,250," Press Enter Key to Continue ");
                                                        while(!kbhit()) ;
                                                        layer(20,180,610,310);
                                                     }
                }
      if(fallflag==1)
                {

                      layer(op[1].x,op[1].y,op[1].x+15,op[1].y+11);
                   op[1].y += 10;
                      falloption(op[1].x,op[1].y,opc);
                   if(op[1].y >= y-6-5)    fallflag=0;

                }
       if(op[1].y >= y-6-4)
                   check_catch_option();

      check_died();
      if(bricount==bcnt)
                {
                  change_level();

                   goto LEVEL;
                }

      check_endgame();

      check_hit_brick();

      settextstyle(0,0,1);
    }   /* end of while*/
 } /* end of main*/

/*   sub functions  to check the progress of the game */
check_catch_option()
 {
    if(op[1].x>x&&op[1].x<x+length)
     {
                   layer(op[1].x,op[1].y,op[1].x+15,op[1].y+11);
                   paddle(x,y,7,length);
                   op[1].x=100;
                   op[1].y =150;
                   if(bricount<=15)    count+=1;
                      else if(bricount<=30)  score+= 100;
                                 else if(bricount<=45) length+=20;
                                  else   score += 100;
                   displaylifes();
                   displayscore();
    }
   else if(op[1].x<x||op[1].x>x+length)
      {
                 layer(op[1].x,op[1].y,op[1].x+15,op[1].y+11);
                   paddle(x,y,7,length);
                   op[1].flag =0;
                   op[1].x=100;
                   op[1].y =150;
      }
      op[1].flag =0;
 }

check_died()
   {
      if((rx<x||rx>x+length)&&ry >=y-6-4)
                  {
                    music(10);

                    settextstyle(1,0,3);
                    count=count-1;
                    displaylifes();
                    rx=x+25;ry=y-10;
                    if(x+l+5>= 630 )   rx = 50;
                    music(0);
                   }
     }
 check_endgame()
 {
      if(count==0||escflag==1||level>4)
                  {
                    settextstyle(1,0,5);
                    layer(11,11,628,405);
                       music(40);
              setcolor(2);
                  rectangle(95,195,600,298);
                  rectangle(97,197,598,296);
                      setcolor(14);
                    outtextxy(100,200,"      Game Over");
                    outtextxy(80,240," Another Game (y / n)");
                    music(0);
                    re = restart();
                    if (re=='Y'||re=='y')
                       {
                                   restore_defaults();

                                   main();
                                 }
                    endscreen();
                    closegraph();
                    nosound();
                    exit(0);
                  }
      }

 change_level()
  {
     level+=1;
                  count+=1;
                  bricount=0;
                  length = 50;
                  rx = x+5;
                  ry = y-4-6;
                  settextstyle(1,0,5);
         setcolor(2);
                  rectangle(12,195,624,260);
                  rectangle(13,196,623,259);
                  setcolor(14);
                  outtextxy(40,200," Level is completed");
                  outtextxy(40,300,"Press Space to Continue");
                  getch();
                  layer(11,194,629,400);
  }

 check_hit_brick()
 {

      for(j=1;j<=bcnt;j++)
                 if(rx>=b[j].x-5&&rx<=b[j].x+l&&ry>=b[j].y-10&&ry<=b[j].y+w)
                  {

                      setfillstyle(1,0);
                      bar(b[j].x,b[j].y,b[j].x+l+1,b[j].y+w+1);
                      if(a[j]==0)
                      {
                      music(90);

                      dy = -dy;
                     score = score+10;
            displayscore();
                      bricount++;
                      music(0);
                      if(bricount<=15)    opc =4;
                                 else if(bricount<=30)  opc = 2;
                                  else if(bricount<=45) opc =1;
                                    else opc = 12;
                      if(bricount%5==0&&op[1].flag==0)
                                  {
                                     op[1].flag=1;
                                     fallflag=1;
                                     op[1].y =150;
                                     op[1].x = 100+random(400);
                                  }
                      }
                      a[j]=1;

                  }
    }

/* function to create paddle */

paddle(int x,int y,int c,int len)
  {
     setcolor(c);
     rectangle(x,y,x+len,y+5);
     rectangle(x+1,y+1,x+len-1,y+4);
     rectangle(x+1,y+2,x+len-1,y+3);
     line(x,y-1,x+len,y-1);
     ellipse(x,y+2,0,360,4,3);
     ellipse(x+len,y+2,0,360,4,3);
  }

/*   functions to create bricks   */

mess1()
 {
   for(j=1;j<=bcnt/3;j++)
     {
                b[j].y=b[1].y;
                  button3d(b[j].x,b[j].y,l,w,6);
                  letter(b[j].x,b[j].y,l,w,3,0);
                b[j+1].x=b[j].x+l+5;
      }
   b[j].x=b[1].x;
   for(j=bcnt/3+1;j<=2*bcnt/3;j++)
     {
                b[j].y=b[1].y+w+5;
                  button3d(b[j].x,b[j].y,l,w,1);
                                   letter(b[j].x,b[j].y,l,w,4,14);
                b[j+1].x=b[j].x+l+5;
     }
   b[j].x=b[1].x;
   for(j=2*bcnt/3+1;j<=bcnt;j++)
     {
                b[j].y=b[1].y+2*w+10;
                  button3d(b[j].x,b[j].y,l,w,6);
                                   letter(b[j].x,b[j].y,l,w,5,0);
                b[j+1].x=b[j].x+l+5;
     }

 }
mess2()
{
  for(j=1;j<=bcnt/4;j++)
   {
    b[j].y = 100;
    button3d(b[j].x,b[j].y,l,w,8,14);
    letter(b[j].x,b[j].y,l,w,6);
    b[j+1].x=b[j].x+l+2;
   }
   b[j].x =200;
   for(j=bcnt/4+1;j<=bcnt/2;j++)
   {
    b[j].y = 100+2*w;
    button3d(b[j].x,b[j].y,l,w,4,14);
    letter(b[j].x,b[j].y,l,w,6);
    b[j+1].x=b[j].x+l+2;
   }
   b[j].x = 200;
   for(j=bcnt/2+1;j<=3*bcnt/4;j++)
   {
    b[j].y = 100+4*w;
    button3d(b[j].x,b[j].y,l,w,1,14);
    letter(b[j].x,b[j].y,l,w,6);
    b[j+1].x=b[j].x+l+2;
   }
   b[j].x =  b[1].x;
   for(j=3*bcnt/4+1;j<=bcnt;j++)
   {
    b[j].y = 100+6*w;
    button3d(b[j].x,b[j].y,l,w,6,14);
    letter(b[j].x,b[j].y,l,w,6);
    b[j+1].x=b[j].x+l+2;
   }

  }
mess3()
  {
    for(j=1;j<=24;j+=1)
                {
                   b[j].y = b[1].y;
                   button3d(b[j].x,b[j].y,l,w,9);
          letter(b[j].x,b[j].y,l,w,1);
                   b[j+1].x=b[j].x+l+2;
                }
   b[j].x=b[1].x;
   for(j=25;j<=48;j+=1)
                {
                   b[j].y = b[1].y+w+2;
                   button3d(b[j].x,b[j].y,l,w,9);
          letter(b[j].x,b[j].y,l,w,1);
                   b[j+1].x=b[j].x+l+2;
                }
   b[j].x=b[1].x;
   for(j=49;j<=72;j+=1)
      {
                  b[j].y = b[1].y+2*w+4;
                   button3d(b[j].x,b[j].y,l,w,9);
                   letter(b[j].x,b[j].y,l,w,1);
                   b[j+1].x=b[j].x+l+2;
     }

  }
 mess4()
  {
    b[j].x =b[1].x;
   for(j=1;j<=13;j+=1)
                {
                   b[j].y = 100 - 1;
                   button3d(b[j].x,b[j].y,l,w,9,14);
                   letter(b[j].x,b[j].y,l,w,1);
                   b[j+1].x=b[j].x+2*l;
                }
    b[j].x=b[1].x+2*w;
    for(j=14;j<=25;j+=1)
                {
                   b[j].y = 100+2*w;
                   button3d(b[j].x,b[j].y,l,w,9,14);
                   letter(b[j].x,b[j].y,l,w,1);
                   b[j+1].x=b[j].x+2*l;
                }
     b[j].x=b[1].x+4*w;
     for(j=26;j<=36;j+=1)
                {
                   b[j].y = 100+4*w;
                   button3d(b[j].x,b[j].y,l,w,9,14);
                   letter(b[j].x,b[j].y,l,w,1);
                   b[j+1].x=b[j].x+2*l;
                }
     b[j].x=b[1].x+6*w;
     for(j=37;j<=46;j+=1)
                {
                   b[j].y = 100 + 6*w;
                   button3d(b[j].x,b[j].y,l,w,9,14);
                   letter(b[j].x,b[j].y,l,w,1);
                   b[j+1].x=b[j].x+2*l;
                }
      b[j].x = b[1].x + 8*w;
                for(j=47;j<=55;j++)
                 {
                   b[j].y = 100 + 8*w ;
                   button3d(b[j].x,b[j].y,l,w,9,14);
                   letter(b[j].x,b[j].y,l,w,1);
                   b[j+1].x=b[j].x+2*l;
                }
 }
 /*  function to clear a layer */

  layer(int x1,int y1,int x2,int y2)
   {
      setfillstyle(1,0);
      bar(x1,y1,x2,y2);
   }

/*  functon to produce various sounds */

  music(int opt)
   {
     int a;
     if(opt==0)  nosound();
   /*  for(a=1;a<=opt;a++)
     {
                sound(5+2*opt);
                delay(10);
     } */
   }

char   openscreen()
   {

     char reply;
     layer(11,11,629,399);
     settextstyle(0,0,1);
     setcolor(12);
     outtextxy(300,0,"DJ-BALL");
     settextstyle(4,0,3);
     setcolor(2);
     outtextxy(31,14*7,"    Use Left and Right arrows to move your
Paddle.");
     outtextxy(31,17*7,"    You will lose a life when the ball touch the
");
     outtextxy(31,20*7,"    ground. For each brick you will get 10
points.");
     outtextxy(31,23*7,"    if all the bricks are over in each level
you");
     outtextxy(31,26*7,"    will get a bonus life.
");
     line(10,26*10,630,26*10);
     setcolor(4);

     settextstyle(1,0,3);
     outtextxy(31,29*10,"    SELECT LEVEL  ");

     outtextxy(31,33*10,"    (D)ifficult   ");
     outtextxy(31,35*10,"    (N)ormal      ");
     outtextxy(31,37*10,"    (E)asy        ");

      reply = getch();

     layer(11,11,629,399);
     return(reply);
   }
/* function for option falling */
falloption(int x,int y,int c)
    {
                button3d(x,y,10,10,c);
                letter(x,y,10,10,'+',0);
                delay(1000);
    }
endscreen()
    {
    }

restore_defaults()
    {
                 bricount=0;count=4;dx=10;x=400;y=400;bcnt=14;padhit=0;
      ry=390;rx=425;dy=10;score=0;k=233;level=1;l=20;w=10;escflag=0;
      length=50;
    }

 char restart()
  {
      return(getch());
  }

/*   function to create a single brick */

 button3d(int x,int y,int l,int w,int c)
 {
   setcolor(LIGHTGRAY);
   setfillstyle(1,c);

   bar(x,y,x+l,y+w);

   setcolor(WHITE);
   line(x,y,x+l,y);
   line(x,y,x,y+w);


   setcolor(DARKGRAY);
   line(x+l+1,y,x+l+1,y+w+1);
   line(x,y+w+1,x+l+1,y+w+1);
}

/* function to display symbol on brick */

letter(int x,int y,int l,int w,int ch,int c)
 {
   char s[1];
   setcolor(c);
   sprintf(s,"%c",ch);
   outtextxy(x + l/4 + 2,y + w/5, s);
 }

 displaylifes()
  {
     settextstyle(1,0,3);

                     setcolor(0);
                    outtextxy(400,450,s1);
                    sprintf(s1,"Lifes = %d",count);

                    setcolor(6);
                    outtextxy(400,450,s1);
 }
 displayscore()
  {
                      settextstyle(1,0,3);
                      setcolor(0);
                      outtextxy(100,450,s);
                      sprintf(s,"Score = %d",score);
                      setcolor(3);
                      outtextxy(100,450,s);
   }
