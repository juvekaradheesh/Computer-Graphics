#include<graphics.h>
#include<stdio.h>

void floodFill(int x, int y, int old, int fill)
{
	int current;
	current=getpixel(x,y);
	if(current==old)
	{
		putpixel(x,y,fill);
        floodFill(x+1,y,old,fill);
		floodFill(x-1,y,old,fill);
		floodFill(x, y+1,old,fill);
        floodFill(x,y-1,old,fill);
        floodFill(x+1,y+1,old,fill);
        floodFill(x+1,y-1,old,fill);
        floodFill(x-1,y+1,old,fill);
        floodFill(x-1,y-1,old,fill);
	}
}

int main()
{
		int x,y,o=0;
		int gDriver=DETECT,gmode;
		initgraph(&gDriver,&gmode, NULL);
        
        //face circle
        circle(100,130,60);
        circle(100,130,61);
        circle(100,130,62);
        //ear circle right
        circle(160,70,24.85);
        circle(160,70,25.85);
        circle(160,70,26.85);
        //ear circle left
        circle(40,70,24.85);
        circle(40,70,25.85);
        circle(40,70,26.85);
        //inner circle right ear
        circle(150.575,80.575,9.2125);
        //inner circle left ear
        circle(49.425,80.575,9.2125);
        //inner circle main
        circle(100,145,25);
        //inner inner circle
        circle(100,132.5,12.5);
        //eye circle right
        circle(125,120,10.355);
        //eye circle left
        circle(75,120,10.355);
        
		x=100;
		y=80;
        floodFill(x,y,o,4);
        floodFill(160,70,o,14);
        floodFill(40,70,o,14);
		getch();
        closegraph();
        return 0;
}