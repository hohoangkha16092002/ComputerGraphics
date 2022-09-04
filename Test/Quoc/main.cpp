#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<dos.h>

#define RAD 0.01745329


int main()
{
    int r,tx,ty;  // Radian và tọa độ của quạt.
    int rc,rq,d;
    int gd =0,gm,i;
    int c1[8];
    int c2[8];
    int c3[8];
    
    // khởi tạo quạt.
    initgraph(&gd,&gm,"");
    tx=getmaxx()/2;    
    ty=getmaxy()/3;
    c1[0]=c1[6]=tx;c1[1]=c1[7]=ty;
    c2[0]=c2[6]=tx;c2[1]=c2[7]=ty;
    c3[0]=c3[6]=tx;c3[1]=c3[7]=ty;
    d=0;
    r=100;
    rq=r-20;
    rc=30;
    
    // vẽ quạt
    circle(tx,ty,r);
    rectangle(tx-2,ty+r,tx+2,ty+r*2);
    rectangle(tx-10,ty+r*2,tx+10,ty+r*3);
    rectangle(tx-50,ty+r*3,tx+50,ty+r*3+20);
    while(!kbhit())
    {    
        setcolor(BLACK);
        
        c1[2]=tx+rq*sin(d*RAD);
        c1[3]=ty-rq*cos(d*RAD);
        c1[4]=tx+rq*sin((d+rc)*RAD);
        c1[5]=ty-rq*cos((d+rc)*RAD);
        
        c2[2]=tx+rq*sin((d+120)*RAD);
        c2[3]=ty-rq*cos((d+120)*RAD);
        c2[4]=tx+rq*sin((d+120+rc)*RAD);
        c2[5]=ty-rq*cos((d+120+rc)*RAD);
        c3[2]=tx+rq*sin((d+240)*RAD);
        c3[3]=ty-rq*cos((d+240)*RAD);
        c3[4]=tx+rq*sin((d+240+rc)*RAD);
        c3[5]=ty-rq*cos((d+240+rc)*RAD);
        
        setfillstyle(2,BLUE);
        fillpoly(4,c1);
        fillpoly(4,c2);
        fillpoly(4,c3);
        
        delay(5);
        setfillstyle(2,BLACK);
        fillpoly(4,c1);
        fillpoly(4,c2);
        fillpoly(4,c3);
                
        d+=2;
        if(d==360) d=0;
    }
    getch();
    closegraph();
    return 0;
}