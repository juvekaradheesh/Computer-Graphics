#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <iostream>
//#include<X11/Xlib.h>

using namespace std;

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

void polyClip(int n, int arr[][2], int x0, int y0, int x1, int y1){
    cout<<"Processing ... ";

    std::vector<int> xtemp;
    std::vector<int> ytemp;
    std::vector<int> xnew;
    std::vector<int> ynew;

    for(int i = 0; i < n; i++){
        xtemp.push_back(arr[i][0]);
        ytemp.push_back(arr[i][1]);
    }
    int flag;
    // LEFT EDGE
    for(int edge = 3; edge < 3+4; edge++){
        int rc[xtemp.size()][4];
        //std::cout<<"\nEdge- "<<edge<<"\n";
        //std::cout<<xtemp.size()<<"\n";
        for(int i = 0; i < xtemp.size(); i++){
            rc[i][0] = ytemp[i]>y1?'1':'0';
            rc[i][1] = ytemp[i]<y0?'1':'0';
            rc[i][2] = xtemp[i]>x1?'1':'0';
            rc[i][3] = xtemp[i]<x0?'1':'0';
        }
        for(int i = 0; i < xtemp.size(); i++){
            if(rc[i][edge%4] != '1' && rc[(i+1)%xtemp.size()][edge%4] != '1'){
                //cout<<"in ->in"<<endl;
                //line in->in
                //insert end point to vector
                //cout<<xtemp[i]<<" "<<ytemp[i]<<"to"<<xtemp[];
                xnew.push_back(xtemp[(i+1)%xtemp.size()]);
                ynew.push_back(ytemp[(i+1)%xtemp.size()]);
                continue;
            }
            if(rc[i][edge%4] == '1' && rc[(i+1)%xtemp.size()][edge%4] == '1'){
                //line out->out
                //cout<<"out ->in";
                continue;
            }
            int newx,newy;
            float slope;
            if(xtemp[(i+1)%xtemp.size()] - xtemp[i] != 0)
                slope = (ytemp[(i+1)%xtemp.size()] - ytemp[i]) / (xtemp[(i+1)%xtemp.size()] - xtemp[i]);
            switch(edge % 4){
                case 3:
                    newx = x0;
                    if(xtemp[(i+1)%xtemp.size()] - xtemp[i] == 0)
                        slope = 0;
                    newy = ytemp[i] + slope*(x0 - xtemp[i]);
                    break;
                case 0:
                    newy = y1;
                    if(xtemp[(i+1)%xtemp.size()] - xtemp[i] == 0)
                        newx = xtemp[i];
                    else
                        newx = xtemp[i] + (1/slope)*(y1 - ytemp[i]);
                    break;
                case 1:
                    newy = y0;
                    if(xtemp[(i+1)%xtemp.size()] - xtemp[i] == 0)
                        newx = xtemp[i];
                    else
                        newx = xtemp[i] + (1/slope)*(y0 - ytemp[i]);
                    break;
                case 2:
                    newx = x1;
                    if(xtemp[(i+1)%xtemp.size()] - xtemp[i] == 0)
                        newy = ytemp[i];
                    else
                        newy = ytemp[i] + slope*(x1 - xtemp[i]);
                    break;
            }
            if(rc[i][edge%4] == '1'){
                //line out->in
                xnew.push_back(newx);
                ynew.push_back(newy);
                xnew.push_back(xtemp[(i+1)%xtemp.size()]);
                ynew.push_back(ytemp[(i+1)%xtemp.size()]);
            }
            else{
                //line in->out
                xnew.push_back(newx);
                ynew.push_back(newy);
            }


        }
        xtemp.resize(0);
        ytemp.resize(0);
        for(int i = 0; i < xnew.size(); i++){
            xtemp.push_back(xnew[i]);
            ytemp.push_back(ynew[i]);
        }
        xnew.resize(0);
        ynew.resize(0);

    }

    cout<<"Done ... ";

    for(int i = 0; i < xtemp.size(); i++){
        line(xtemp[i],ytemp[i],xtemp[(i+1)%xtemp.size()],ytemp[(i+1)%xtemp.size()]);
    }

}

int main()
{
    //XInitThreads();
    freopen("input.txt","r",stdin);//redirects standard input
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\Program Files (x86)\CodeBlocks\MinGW\lib");
    //initgraph(&gd, &gm,NULL);
    int x0, y0, x1, y1;
    cout<<"Enter 2 diagonal co-ordinates of Window : ";
    cin>>x0>>y0>>x1>>y1;
    drawLine(x0, y0, x1, y0, GREEN);
    drawLine(x1, y0, x1, y1, GREEN);
    drawLine(x1, y1, x0, y1, GREEN);
    drawLine(x0, y1, x0, y0, GREEN);

    int n;
    cout<<"Enter no. of points of polygon : ";
    cin>>n;

    int arr[n][2];

    for(int i = 0; i < n; i++){
        cout<<"Enter Co-ordinates of point : "<<i+1;
        cin>>arr[i][0]>>arr[i][1];
    }

    printf("Before Clipping");
    for(int i = 0; i < n; i++){
        line(arr[i][0],arr[i][1],arr[(i+1)%n][0],arr[(i+1)%n][1]);
    }
    delay(3000);
    closegraph();
    initgraph(&gd, &gm,NULL);
    printf("After Clipping");
    drawLine(x0, y0, x1, y0, GREEN);
    drawLine(x1, y0, x1, y1, GREEN);
    drawLine(x1, y1, x0, y1, GREEN);
    drawLine(x0, y1, x0, y0, GREEN);
    polyClip(n, arr, x0, y0, x1, y1);
    delay(3000);
    getch();
    return 0;
}
