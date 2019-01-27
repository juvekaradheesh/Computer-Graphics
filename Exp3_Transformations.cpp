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
float drawMatrix[ROWS][POINTS];

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
        drawLine(drawMatrix[0][j], drawMatrix[1][j], drawMatrix[0][(j + 1) % POINTS], drawMatrix[1][(j + 1) % POINTS], xc, yc);
    }
}

void translate(float xc, float yc, float xt, float yt){
    for(int j = 0; j < 14; j++){
        drawMatrix[0][j] = keyMatrix[0][j] + xt;
        drawMatrix[1][j] = keyMatrix[1][j] + yt;
    }
    drawKey(xc, yc);
}

void scale(float xc, float yc, float xt, float yt){
    float scalingMatrix[3][3] = {{xt, 0, 0}, {0, yt, 0}, {0, 0, 1}};
    float sum = 0;
    for(int c = 0; c < 3; c++) {
        for(int d = 0; d < POINTS; d++) {
            for(int k = 0; k < ROWS; k++) {
                sum = sum + scalingMatrix[c][k]*keyMatrix[k][d];
            }
            drawMatrix[c][d] = sum;
            sum = 0;
        }
    }
    drawKey(xc, yc);
}

void rotatek(float xc, float yc, double t){
t = (t * 3.14) / 180;
    float rotateMatrix[3][3] = {{cos(t), -sin(t), 0}, {sin(t), cos(t), 0}, {0, 0, 1}};
    float sum = 0;
    for(int c = 0; c < 3; c++) {
        for(int d = 0; d < POINTS; d++) {
            for(int k = 0; k < ROWS; k++) {
                sum = sum + rotateMatrix[c][k]*keyMatrix[k][d];
            }
            drawMatrix[c][d] = sum;
            sum = 0;
        }
    }
    drawKey(xc, yc);
}

void reflect(float xc, float yc, int subChoice){
    float reflectionMatrix[3][3];
    switch(subChoice){
        case 1:
            reflectionMatrix[0][0] = 1;
            reflectionMatrix[0][1] = 0;
            reflectionMatrix[0][2] = 0;
            reflectionMatrix[1][0] = 0;
            reflectionMatrix[1][1] = -1;
            reflectionMatrix[1][2] = 0;
            reflectionMatrix[2][0] = 0;
            reflectionMatrix[2][1] = 0;
            reflectionMatrix[2][2] = 1;
            break;
        case 2:
            reflectionMatrix[0][0] = -1;
            reflectionMatrix[0][1] = 0;
            reflectionMatrix[0][2] = 0;
            reflectionMatrix[1][0] = 0;
            reflectionMatrix[1][1] = 1;
            reflectionMatrix[1][2] = 0;
            reflectionMatrix[2][0] = 0;
            reflectionMatrix[2][1] = 0;
            reflectionMatrix[2][2] = 1;
            break;
        case 3:
            reflectionMatrix[0][0] = -1;
            reflectionMatrix[0][1] = 0;
            reflectionMatrix[0][2] = 0;
            reflectionMatrix[1][0] = 0;
            reflectionMatrix[1][1] = -1;
            reflectionMatrix[1][2] = 0;
            reflectionMatrix[2][0] = 0;
            reflectionMatrix[2][1] = 0;
            reflectionMatrix[2][2] = 1;
            break;
        case 4:
            reflectionMatrix[0][0] = 0;
            reflectionMatrix[0][1] = 1;
            reflectionMatrix[0][2] = 0;
            reflectionMatrix[1][0] = 1;
            reflectionMatrix[1][1] = 0;
            reflectionMatrix[1][2] = 0;
            reflectionMatrix[2][0] = 0;
            reflectionMatrix[2][1] = 0;
            reflectionMatrix[2][2] = 1;
            break;
    }

    float sum = 0;
    for(int c = 0; c < 3; c++) {
        for(int d = 0; d < POINTS; d++) {
            for(int k = 0; k < ROWS; k++) {
                sum = sum + reflectionMatrix[c][k]*keyMatrix[k][d];
            }
            drawMatrix[c][d] = sum;
            sum = 0;
        }
    }
    drawKey(xc, yc);
}

void shear(float xc, float yc, float xt, float yt){
    float shearingMatrix[3][3] = {{1, xt, 0}, {yt, 1, 0}, {0, 0, 1}};
    float sum = 0;
    for(int c = 0; c < 3; c++) {
        for(int d = 0; d < POINTS; d++) {
            for(int k = 0; k < ROWS; k++) {
                sum = sum + shearingMatrix[c][k]*keyMatrix[k][d];
            }
            drawMatrix[c][d] = sum;
            sum = 0;
        }
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

    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < POINTS; j++){
            drawMatrix[i][j] = keyMatrix[i][j];
        }
    }
    drawKey(xc, yc);

    float xt, yt;
    double t;
    int choice;
    do{
        printf("*******MENU*******\n");
        printf("1 : Translate\n");
        printf("2 : Scale\n");
        printf("3 : Rotate\n");
        printf("4 : Reflect\n");
        printf("5 : Shearing\n");
        printf("6 : Exit\n");
        printf("Enter you choice : \n");
        scanf("%d",&choice);

        switch(choice){
            case 1 :
                printf("Enter x and y co-ordinate to translate the key by : \n");
                scanf("%f %f", &xt, &yt);
                translate(xc, yc, xt, yt);
                break;
            case 2 :
                printf("Enter x and y multiples to scale the key by : \n");
                scanf("%f %f", &xt, &yt);
                scale(xc, yc, xt, yt);
                break;
            case 3 :
                printf("Enter angle to rotate key by : \n");
                scanf("%lf", &t);
                rotatek(xc, yc, t);
                break;
            case 4:
                int subChoice;
                printf("1 : Reflect About x-axis\n");
                printf("2 : Reflect About y-axis\n");
                printf("3 : Reflect About origin\n");
                printf("4 : Reflect About x = y\n");
                printf("Enter your choice : ");
                scanf("%d", &subChoice);
                if(subChoice <= 4 && subChoice >= 1)
                    reflect(xc, yc, subChoice);
                else
                    printf("Incorrect Choice!");
                break;
            case 5:
                printf("Enter x and y shearing forces : \n");
                scanf("%f %f", &xt, &yt);
                shear(xc, yc, xt, yt);
                break;
            case 6:
                printf("Thank you!");
                break;
            default:
                printf("Valid input de kuch bhi mat dal");
        }

    }while(choice != 6);
    getch();
    return 0;
}
