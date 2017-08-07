#include<graphics.h>
#include<dos.h>
/*T 8;
 B 9;
 L 4;
 R 7;
 RB 16;
 TB 17;
 LB 13;
 TR 15;
 LR 11;
 LT 12;
 TLB 21;
 LRB 20;
*/
void hline();
void vline();
void point();
void removepoint();
void maze();
void back();
void left();
void right();
void top();
void bottom();
int x[]={10,60,110,160,210,260,310};
int y[]={20,60,100,140,180,220};
int b[5][6]={{15,11,11,11,11,12},
	     {16,12,15,4,15,21},
	     {15,20,13,15,13,17},
	     {17,15,12,17,7,13},
	     {16,13,16,20,11,1}};
int a[4];
static int p=0,q=0;
void mid();
int main()
{
 int ch;
 int i,moves;
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 cleardevice();
     a[0]=26;
     a[1]=193;
     a[2]=43;
     a[3]=206;
     mid();
    // back();
     maze();

     point();

    do
     {
      moves = b[p][q];
      if(moves==16)
      {
       ch=getch();

       switch(ch)
       {

       case 80:removepoint();
	      bottom();
	       break;
       case 77:removepoint();
	       right();
	       break;

      }
     }
      else if(moves==17)
      {

       ch=getch();

       switch(ch)
       {
      case 72: removepoint();
			   top();
			   break;
       case 80:removepoint();
			   bottom();
				   break;
	}
      }
      else if(moves==13)
      {

       ch=getch();
       switch(ch)
       {
       case 80:removepoint();
			   bottom();
			   break;
       case 75:removepoint();
			   left();
			   break;
       }
      }
      else if(moves==15)
      {

       ch=getch();
       switch(ch)
       {
      case 72: removepoint();
			  top();
			   break;

       case 77:removepoint();
			   right();
				   break;
      }
      }
      else if(moves==11)
      {

       ch=getch();

       switch(ch)
       {
	case 75:removepoint();
				 left();
				break;
	case 77:removepoint();
				   right();
					break;
       }

     }
	   else if(moves==12)
      {

       ch=getch();

       switch(ch)
       {
	case 75:removepoint();
				left();
			   break;
	case 72:removepoint();
		   top();
			break;
       }

     }
	   else if(moves==21)
      {

       ch=getch();
       switch(ch)
       {
       case 72:removepoint();
				   top();
					break;
	case 75:removepoint();
					left();
						break;
	case 80:removepoint();
					bottom();
						break;
       }

     }
	   else if(moves==20)
      {

       ch=getch();
       switch(ch)
       {
	case 75:removepoint();
				left();
			   break;
	case 77:removepoint();
				right();
					break;
	case 80:removepoint();
					bottom();
						break;
       }

     }
     else if(moves==8)
     {
      ch=getch();
      if(ch==72)
      {
		  removepoint();
      top();
      }
     }
     else if(moves==4)
     {
      ch=getch();
      if(ch==75)
      {
		  removepoint();
      left();
      }
     }
     else if(moves==7)
     {
      ch=getch();
      if(ch==77)
      {
		  removepoint();
      right();
      }
     }
     else if(moves==9)
     {
		 removepoint();
      ch=getch();
      if(ch==80)
      {
      bottom();
      }
     }
    }
      while(moves!=1);
 outtextxy(200,200,"WIN");
 
 delay(2000);
 getch();
 closegraph();
 return 0;
}
void maze()
{

     hline(10,260,20);
     hline(60,310,220);
     hline(210,310,60);
     hline(60,160,100);
     hline(210,260,100);
     hline(10,60,140);
     hline(160,210,140);
     hline(60,260,180);

     vline(110,20,60);
     vline(60,60,100);
     vline(160,60,140);
     vline(210,140,180);
     vline(260,100,140);
     vline(110,140,180);
     vline(210,60,100);
     vline(10,20,180);
     vline(310,20,220);
}
void hline(int x1,int x2,int y1)
{
 int i;
 for(i=x1;i<=x2;i++)
 {
  putpixel(i,y1,WHITE);
 }
}
void vline(int x1,int y1,int y2)
{
 int i;
 for(i=y1;i<=y2;i++)
 {
  putpixel(x1,i,WHITE);
 }
}
void mid()
{
	int i,j,k,l;
	int x1,x2,y1,y2;
	for(i=0;i<6;i++)
	{
	  for(j=0;j<=6;j++)
	  {

		x1=(x[j+1]/3)+((2*x[j])/3);
		y1=(y[i+1]/3)+((2*y[i])/3);
		x2=(x[j]/3)+((2*x[j+1])/3);
		y2=(y[i]/3)+((2*y[i+1])/3);

	       /*	for(k=y1;k<=y2;k++)
		{
		 for(l=x1;l<=x2;l++)
		 {
		  putpixel(l,k,RED);
		  }
		 }*/
 }
 }

}
void right()
{
	       a[0]=a[0]+50;//right
	       a[2]=a[2]+50;
	       q++;
	       point();
}
void left()
{
     a[0]=a[0]-50; //left
     a[2]=a[2]-50;
     q--;
     point();
}
void top()
{
 a[1]=a[1]-40; //top
 a[3]=a[3]-40;
 p++;
 point();
}
void bottom()
{
 a[1]=a[1]+40; //down
 a[3]=a[3]+40;
 p--;
 point();
}
void point()
{
  int i,j;
  for(i=a[0];i<=a[2];i++)
  {
   for(j=a[1];j<=a[3];j++)
   {
    putpixel(i,j,RED);
   }
  }
}
void removepoint()
{
 int i,j;
  for(i=a[0];i<=a[2];i++)
 {
  for(j=a[1];j<=a[3];j++)
  {
   putpixel(i,j,BLACK);
  }
 }
}