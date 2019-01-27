#include<stdio.h>
#include<graphics.h>
#include<math.h>

#define COLOR WHITE
#define AXISCOLOR GREEN

void drawLine(float x1, float y1, float x2, float y2,int xc,int yc){

    float dx = x2 - x1;
    float dy = y2 - y1;
    float l;
    if(abs(dx) >= abs(dy)){
        l = abs(dx);
    }
    else{
        l = abs(dy);
    }

    float incx = dx / l;
    float incy = dy / l;

    float x = x1;
    float y = y1;


    if(xc == 0 && yc == 0){
        putpixel(x + xc,y + yc,AXISCOLOR);
    }
    else{
        putpixel(x + xc,yc - y,COLOR);
    }

    for(int i = 0; i < l; i++){
        x = x + incx;
        y = y + incy;

        if(xc == 0 && yc == 0){
        putpixel(x + xc,y + yc,AXISCOLOR);
        }
        else{
            putpixel(x + xc,yc - y,COLOR);
        }

    }

}

void plot(float x, float y, float xcen, float ycen, int xc , int yc){
    putpixel(xc + (xcen + x), yc - (ycen + y),COLOR);
    putpixel(xc + (xcen + y), yc - (ycen + x),COLOR);
    putpixel(xc + (xcen + x), yc - (ycen - y),COLOR);
    putpixel(xc + (xcen - y), yc - (ycen + x),COLOR);
    putpixel(xc + (xcen - x), yc - (ycen - y),COLOR);
    putpixel(xc + (xcen - y), yc - (ycen - x),COLOR);
    putpixel(xc + (xcen - x), yc - (ycen + y),COLOR);
    putpixel(xc + (xcen + y), yc - (ycen - x),COLOR);
}

drawCircle(float xcen, float ycen, float r, int xc, int yc ){
    float x = 0, y = r;
    plot(x,y,xcen,ycen,xc,yc);
    float p = 3 - 2*r;
    while(x<=y){
        delay(10);
        if(p < 0){
            p += 4*x + 6;
            x = x + 1;
            y = y;
            plot(x,y,xcen,ycen,xc,yc);
        }
        else{
            p += 4*(x-y) + 10;
            x = x + 1;
            y = y - 1;
            plot(x,y,xcen,ycen,xc,yc);
        }
    }
}

int main(){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\Program Files (x86)\CodeBlocks\MinGW\lib");
    int xc = getmaxx()/2;
    int yc = getmaxy()/2;

    drawLine(getmaxx()/2,0,getmaxx()/2,getmaxy(),0,0);
    drawLine(0,getmaxy()/2,getmaxx(),getmaxy()/2,0,0);

    //face circle
    drawCircle(100,80,60,xc,yc);
    //ear circle right
    drawCircle(160,140,24.85,xc,yc);
    //ear circle left
    drawCircle(40,140,24.85,xc,yc);
    //inner circle right ear
    drawCircle(150.575,130.575,9.2125,xc,yc);
    //inner circle left ear
    drawCircle(49.425,130.575,9.2125,xc,yc);
    //inner circle main
    drawCircle(100,65,25,xc,yc);
    //inner inner circle
    drawCircle(100,77.5,12.5,xc,yc);
    //eye circle right
    drawCircle(125,90,10.355,xc,yc);
    //eye circle left
    drawCircle(75,90,10.355,xc,yc);

    getch();

    return 0;
}
