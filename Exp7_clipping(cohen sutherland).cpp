#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<string.h>
#include<X11/Xlib.h>

void drawLine(float x1, float y1, float x2, float y2, int color){

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
    putpixel(x, y, color);
    for(int i = 0; i < l; i++){
        x = x + incx;
        y = y + incy;

        putpixel(x, y, color);
    }
}

void clip(int x0, int y0, int x1, int y1, int lx0, int ly0, int lx1, int ly1){
    char rc0[4], rc1[4];
    int drawx0=lx0, drawy0=ly0, drawx1=lx1, drawy1=ly1;
    double m = (ly1 - ly0) / (lx1 - lx0);
    rc0[0] = ly0>y1?'1':'0';
    rc0[1] = ly0<y0?'1':'0';
    rc0[2] = lx0>x1?'1':'0';
    rc0[3] = lx0<x0?'1':'0';

    rc1[0] = ly1>y1?'1':'0';
    rc1[1] = ly1<y0?'1':'0';
    rc1[2] = lx1>x1?'1':'0';
    rc1[3] = lx1<x0?'1':'0';
    if(strcmp(rc0,"0000") == 0 && strcmp(rc1,"0000") == 0){
        drawLine(lx0, ly0, lx1, ly1, WHITE);
        return;
    }
    int flag = 0;
    for(int i = 0; i < 4; i++){
        if(rc0[i] != rc1[i]){
            flag = 1;
        }
    }
    if(flag == 0){
        printf("Line is Rejected");
        return;
    }
    do{
        if(rc0[0] == '1'){
            drawy0 = y1;
            drawx0 = lx0 + (1/m)*(y1 - ly0);
            rc0[0] = '0';
        }
        if(rc0[1] == '1'){
            drawy0 = y0;
            drawx0 = lx0 + (1/m)*(y0 - ly0);
            rc0[1] = '0';
        }
        if(rc0[2] == '1'){
            drawx0 = y1;
            drawy0 = ly0 + m*(x1 - lx0);
            rc0[2] = '0';
        }
        if(rc0[3] == '1'){
            drawx0 = x0;
            drawy0 = ly0 + m*(x0 - lx0);
            rc0[3] = '0';
        }
        if(rc1[0] == '1'){
            drawy1 = y1;
            drawx1 = lx1 + (1/m)*(y1 - ly1);
            rc1[0] = '0';
        }
        if(rc1[1] == '1'){
            drawy1 = y0;
            drawx1 = lx1 + (1/m)*(y0 - ly1);
            rc1[1] = '0';
        }
        if(rc1[2] == '1'){
            drawx1 = x1;
            drawy1 = ly1 + m*(x1 - lx1);
            rc1[2] = '0';
        }
        if(rc1[3] == '1'){
            drawx1 = x0;
            drawy1 = ly1 + m*(x0 - lx1);
            rc1[3] = '0';
        }
    }while(strcmp(rc0, "0000") != 0 && strcmp(rc1, "0000"));
    drawLine(drawx0, drawy0, drawx1, drawy1, WHITE);

}

int main()
{
    XInitThreads();
    int gd = DETECT, gm;
    //initgraph(&gd, &gm, "C:\Program Files (x86)\CodeBlocks\MinGW\lib");
    initgraph(&gd,&gm,NULL);
    int x0, y0, x1, y1, lx0, ly0, lx1, ly1;
    printf("Enter 2 diagonal co-ordinates of Window : ");
    scanf("%d %d %d %d", &x0, &y0, &x1, &y1);
    drawLine(x0, y0, x1, y0, GREEN);
    drawLine(x1, y0, x1, y1, GREEN);
    drawLine(x1, y1, x0, y1, GREEN);
    drawLine(x0, y1, x0, y0, GREEN);

    printf("Enter co-ordinates of Line: ");
    scanf("%d %d %d %d", &lx0, &ly0, &lx1, &ly1);

    clip(x0, y0, x1, y1, lx0, ly0, lx1, ly1);



    getch();
    closegraph();
    return 0;
}
