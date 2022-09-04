#include <graphics.h>
#include <stdio.h>
#include <math.h>
#define ROUND(a) ((int)(a+0.5))

int xa;
int xb;
int ya;
int yb;
float m;
	
void input_xy()
{
	printf("\n************************************************************\n"); 
	printf("*\t0<m<1 va chieu trai sang phai: 100 100 200 150     *\n");
	printf("*\t0<m<1 va chieu phai sang trai: 200 150 100 100     *\n");
	printf("*\tm>1 va chieu trai sang phai: 100 100 150 200       *\n");
	printf("*\tm>1 va chieu phai sang trai: 150 200 100 100       *\n");
	printf("*\t0<|m|<1 va chieu trai sang phai: 100 150 200 100   *\n");
	printf("*\t0<|m|<1 va chieu phai sang trai: 200 100 100 150   *\n");
	printf("*\t|m|>1 va chieu trai sang phai: 100 200 150 100     *\n");
	printf("*\t|m|>1 va chieu phai sang trai: 150 100 100 200     *\n");
	printf("************************************************************\n");
	printf("x1:= ");
	scanf("%d",&xa);
	printf("y1:= ");
	scanf("%d",&ya);
	printf("x2:= ");
	scanf("%d",&xb);
	printf("y2:= ");
	scanf("%d",&yb); 
	m=(float) (yb-ya)/(xb-xa);
	printf("he so goc m = %f",m);
}	


int checkdirection(int a, int b)
{
	if(a<b)
	{
		return 1; //trai qua phai
	}
	else if(a>b)
	{
		return 0; //phai qua trai
	}
	else if (a==b)
	{
	return 2;
	}
}
////////////////////////////////////////////////////
void zero_m_one_left_to_right()
{
	int x;
	float y;
	
	initwindow(700,700);
	putpixel(xa,ya,255); 
	
	x=xa;
	y=ya+m;
	putpixel(x,ROUND(y),125);
	
	for(x=xa; x<=xb; x++) {
		printf("(%d,%.0f)\n",x,ROUND(y));
		putpixel(x,ROUND(y),1);
		delay(20);
		y=y+m;
	}
}

void zero_m_one_right_to_left()
{
	int x;
	float y;
	
	initwindow(700,700);
	putpixel(xa,ya,255); 
	
	x=xa;
	y=ya-m;
	putpixel(x,ROUND(y),125);

	for(x=xa; x>=xb; x--) {
		printf("(%d,%.0f)\n",x,ROUND(y));
		putpixel(x,ROUND(y),2);
		delay(20);
		y=y-m;
	}
}
/////////////////////////////////////////
void m_more_than_one_left_to_right()
{
  	float x;
  	int y;
  
  	initwindow(700,700);
  	putpixel(xa,ya,255); 

  	y=ya;
  	x=xa+1/m;
  	putpixel(ROUND(x),y,255);

  	for(y=ya; y<=yb; y++) {
		printf("(%.0f,%d)\n",ROUND(x),y);
		putpixel(ROUND(x),y,3);
		delay(20);
		x=x+1/m;
	}
}

void m_more_than_one_right_to_left()
{
	float x;
	int y;
	
	initwindow(700,700);
	putpixel(xa,ya,255); 
	
	y=ya;
	x=xa-1/m;
	putpixel(ROUND(x),y,255);
	
	for(y=ya; y>=yb; y--) {
		printf("(%.0f,%d)\n",ROUND(x),y);
		putpixel(ROUND(x),y,4);
		delay(20);
		x=x-1/m;
	}
}
///////////////////////////////////////////////////
void zero_abs_m_one_left_to_right()
{
  int x;
  float y;
  
  initwindow(700,700);
  putpixel(xa,ya,255); 

  x=xa;
  y=ya+m;
  putpixel(x,ROUND(y),125);

  for(x=xa; x<=xb; x++) {
		printf("(%d,%.0f)\n",x,ROUND(y));
		putpixel(x,ROUND(y),5);
		delay(20);
		y=y+m;
	}
}

void zero_abs_m_one_right_to_left()
{
	int x;
	float y;
	
	initwindow(700,700);
	putpixel(xa,ya,255); 
	
	x=xa;
	y=ya-m;
	putpixel(x,ROUND(y),125);
	
	for(x=xa; x>=xb; x--) {
		printf("(%d,%.0f)\n",x,ROUND(y));
		putpixel(x,ROUND(y),6);
		delay(20);
		y=y-m;
	}
}
///////////////////////////////////////////////
void abs_m_more_than_one_left_to_right()
{
	float x;
	int y;
	
	initwindow(700,700);
	putpixel(xa,ya,255); 
	
	y=ya;
	x=xa-1/m;
	putpixel(ROUND(x),y,255);
	
	for(y=ya; y>=yb; y--) {
		printf("(%.0f,%d)\n",ROUND(x),y);
		putpixel(ROUND(x),y,7);
		delay(20);
		x=x-1/m;
	}
}

void abs_m_more_than_one_right_to_left()
{
	float x;
	int y;
	
	initwindow(700,700);
	putpixel(xa,ya,255); 
	
	y=ya;
	x=xa+1/m;
	putpixel(ROUND(x),y,255);
	
	for(y=ya; y<=yb; y++) {
		printf("(%.0f,%d)\n",ROUND(x),y);
		putpixel(ROUND(x),y,8);
		delay(20);
		x=x+1/m;
	}
}
/////////////////////////////////////////////////
void m_inf_up()
{
	int x;
	int y;
	
	initwindow(700,700);
	putpixel(xa,ya,255);
	
	x=xa;
	y=ya-1;
	putpixel(x,y,255);
	
	for(y=ya; y>=yb; y--) {
		putpixel(x,y,9);
		delay(20);
	}	
}

void m_inf_down()
{
	int x;
	int y;
	
	initwindow(700,700);
	putpixel(xa,ya,255);
	
	x=xa;
	y=ya+1;
	putpixel(x,y,255);
	
	for(y=ya; y<=yb; y++) {
		putpixel(x,y,10);
		delay(20);
	}
}

/////////////////////////////////////////////////
void check_m()
{
	//0<m<1
	if(m>=0 && m<=1)
	{
		printf("\nDuong thang can ve co he so goc 0<=m<=1");
		if(checkdirection(xa,xb)==1)
		{
		printf(" va co chieu tu trai sang phai \n");
		zero_m_one_left_to_right();
		}
		else
		{
		printf(" va co chieu tu phai sang trai \n");
		zero_m_one_right_to_left();
		}
	}
	
	// m>1
	if(m>1)
	{
		printf("\nDuong thang can ve co he so goc m>1");
		if(checkdirection(xa,xb)==1)
		{
		printf(" va co chieu tu trai sang phai \n");
		m_more_than_one_left_to_right();
		}
		else if (checkdirection(xa,xb)==0)
		{
		printf(" va co chieu tu phai sang trai \n");
		m_more_than_one_right_to_left();
		}
		else if (checkdirection(xa,xb)==2)
		{
		printf(" va co chieu tu tren xuong duoi");
		m_inf_down();
		}
	}
	
	//-1<m<0
	if(m>=-1 && m<0)
	{
		printf("\nDuong thang can ve co he so goc 0<|m|<=1");
		if(checkdirection(xa,xb)==1)
		{
		printf("va co chieu tu trai sang phai \n");
		zero_abs_m_one_left_to_right();
		}
		else
		{
		printf("va co chieu tu phai sang trai \n");
		zero_abs_m_one_right_to_left();
		}
	}
	
	//m<-1
	if(m<-1)
	{
		printf("\nDuong thang can ve co he so goc |m|>1");
		if(checkdirection(xa,xb)==1)
		{
		printf(" va co chieu tu trai sang phai \n");
		abs_m_more_than_one_left_to_right();
		}
		else if (checkdirection(xa,xb)==0)
		{
		printf(" va co chieu tu phai sang trai \n");
		abs_m_more_than_one_right_to_left();
		}
		else if (checkdirection(xa,xb)==2)
		{
		printf(" va co chieu tu duoi len tren");
		m_inf_up();
		}
	}
}

//chuong trinh chinh
main()
{ //khoi tao window
	input_xy();
	check_m();
	//closegraph();
	getch();
}