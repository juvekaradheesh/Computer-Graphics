#include<stdio.h>
#include<graphics.h>
#include<math.h>

#define COLOR WHITE
#define AXISCOLOR GREEN
#define POINTS 14
#define ROWS 3

float keyMatrix[ROWS][POINTS] = {
    {40, 40, 100, 100, 70, 70, 80, 80, 70, 70, 90, 90, 70, 70},
    {40, 190, 190, 175, 175, 165, 165, 155, 155, 150, 150, 140, 140, 40},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

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

void drawKey(float xc, float yc){

    for(int j = 0; j < POINTS; j++){
        drawLine(keyMatrix[0][j], keyMatrix[1][j], keyMatrix[0][(j + 1) % POINTS], keyMatrix[1][(j + 1) % POINTS], xc, yc);
    }
}

void rotateAbout(float xc, float yc, float xt, float yt, double t){
    for(int j = 0; j < 14; j++){
        keyMatrix[0][j] = keyMatrix[0][j] - xt;
        keyMatrix[1][j] = keyMatrix[1][j] - yt;
    }

    t = (t * 3.14) / 180;
    float rotateMatrix[3][3] = {{cos(t), -sin(t), 0}, {sin(t), cos(t), 0}, {0, 0, 1}};
    float sum = 0;
    for(int c = 0; c < 3; c++) {
        for(int d = 0; d < POINTS; d++) {
            for(int k = 0; k < ROWS; k++) {
                sum = sum + rotateMatrix[c][k]*keyMatrix[k][d];
            }
            keyMatrix[c][d] = sum;
            sum = 0;
        }
    }

    for(int j = 0; j < 14; j++){
        keyMatrix[0][j] = keyMatrix[0][j] + xt;
        keyMatrix[1][j] = keyMatrix[1][j] + yt;
    }

    drawKey(xc, yc);

}

int main(){

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\Program Files (x86)\CodeBlocks\MinGW\lib");
    int xc = getmaxx()/2;
    int yc = getmaxy()/2;

    drawLine(getmaxx()/2,0,getmaxx()/2,getmaxy(),0,0);
    drawLine(0,getmaxy()/2,getmaxx(),getmaxy()/2,0,0);

    float keyStartx, keyStarty;

    drawKey(xc, yc);

    float xt, yt;
    double t;

    printf("Enter x and y co-ordinates of point to rotate the key about : ");
    scanf("%f %f", &xt, &yt);
    printf("Enter angle measure to rotate the key by : ");
    scanf("%lf", &t);

    rotateAbout(xc, yc, xt, yt, t);

    getch();
    return 0;
}
