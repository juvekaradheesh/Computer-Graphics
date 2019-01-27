#include<stdio.h>
#include<graphics.h>
#include<math.h>

#define COLOR WHITE
#define AXISCOLOR GREEN
#define POINTS 14
#define ROWS 3

int factorial(int n)
{
    if (n == 1 || n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

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

int main(){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\Program Files (x86)\CodeBlocks\MinGW\lib");
    int xc = getmaxx()/2;
    int yc = getmaxy()/2;

    drawLine(getmaxx()/2,0,getmaxx()/2,getmaxy(),0,0);
    drawLine(0,getmaxy()/2,getmaxx(),getmaxy()/2,0,0);

    int noOfPoints;
    while(true){
        printf("Enter number of points (0 to Exit) : ");
        scanf("%d", &noOfPoints);
        if(noOfPoints == 0)
            break;
        float points[2][noOfPoints];
        for(int j = 0; j < noOfPoints; j++){
            printf("Enter x and y co-ordinates of P%d : ",j);
            scanf("%f %f", &points[0][j], &points[1][j]);
        }

        float drawPoints[2][11];
        double u = 0;
        int drawPointIndex = 0;
        while(u <= 1){
            double x = 0, y = 0;
            for(int j = 0; j < noOfPoints; j++){
                x += points[0][j]*((factorial(noOfPoints - 1)/(factorial(j)*factorial(noOfPoints - j - 1)))*(pow(u,double(j)))*(pow(1-u,double(noOfPoints-j-1))));
                y += points[1][j]*((factorial(noOfPoints - 1)/(factorial(j)*factorial(noOfPoints - j - 1)))*(pow(u,double(j)))*(pow(1-u,double(noOfPoints-j-1))));
            }
            drawPoints[0][drawPointIndex] = float(x);
            drawPoints[1][drawPointIndex] = float(y);
            drawPointIndex++;
            u += 0.1;
        }
        for(int j = 0; j < 10; j++){
            drawLine(drawPoints[0][j], drawPoints[1][j], drawPoints[0][(j+1)], drawPoints[1][(j+1)], xc, yc);
        }
    }

    getch();
    return 0;
}
