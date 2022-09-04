//khai bao thu vien
#include <graqhics.h>
#include <math.h>
#define ROUND(a) ((int)(a+0.5))

//khai bao bien
int xa;
int xb;
int ya;
int yb;
float m;

//chuong trinh con

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

void zero_m_one_left_to_right()
{
  int x;
  int y;
  int q0;
  int q;
  int dy;
  int dx;
  
  initwindow(700,700);
  putpixel(xa,ya,255); 
  
  dy=yb-ya;
  dx=xb-xa;
  
  q0=2*dy-dx;
  
  x=xa;
  y=ya;
  
  putpixel(x,y,125);
  q=q0;
  
  while(x<xb)
  {
    if(q>0)
    {
      q=q+2*dy-2*dx;
    }
    else
    {
      q=q+2*dy;
      y++;
    }
    x=x+1;
    putpixel(x,y,255);
    delay(100);
    printf("%d,%d\t",x,y);
  }
  //closegraph();
}

void zero_2_one_right_2_left()
{
  int x;
  int y;
  int q0;
  int q;
  int dy;
  int dx;
  
  initwindow(700,700);
  putpixel(xa,ya,255); 
  dy=yb-ya;
  dx=xb-xa;
  q0=dx-2*dy;
  x=xa;
  y=ya;
  putpixel(x,y,125);
  q=q0;
  while(x>xb)
  {
    if(q<0)
    {
      q=q-2*dy;
    }
    else
    {
      q=q-2*dy+2*dx;
      y--;
    }
    x=x-1;
    putpixel(x,y,255);
    delay(100);
    printf("%d,%d\t",x,y);
  }
  //closegraph();
}

void more_than_one_left_2_right()
{
  int x;
  int y;
  int q0;
  int q;
  int dy;
  int dx;
  
  initwindow(700,700);
  putpixel(xa,ya,255); 
  dy=yb-ya;
  dx=xb-xa;
  q0=2*dx-dy;
  x=xa;
  y=ya;
  putpixel(x,y,125);
  q=q0;
  while(y<yb)
  {
    if(q<0)
    {
      q=q+2*dx;
    }
    else
    {
      q=q+2*dx-2*dy;
      x++;
    }
    y=y+1;
    putpixel(x,y,255);
    delay(100);
    printf("%d,%d\t",x,y);
  }
  //closegraph();
}

void more_than_one_right_2_left()
{
  int x;
  int y;
  int q0;
  int q;
  int dy;
  int dx;
  
  initwindow(700,700);
  putpixel(xa,ya,255); 
  dy=yb-ya;
  dx=xb-xa;
  q0=dx-2*dy;
  x=xa;
  y=ya;
  putpixel(x,y,125);
  q=q0;
  while(y>yb)
  {
    if(q<0)
    {
      q=q-2*dx;
      x--;
    }
    else
    {
      q=q-2*dx+2*dy;
    }
    y=y-1;
    putpixel(x,y,255);
    delay(100);
    printf("%d,%d\t",x,y);
  }
  //closegraph();
}

void zero_abs_m_one_left_2_right()
{
  int x;
  int y;
  int q0;
  int q;
  int dy;
  int dx;
  
  initwindow(700,700);
  putpixel(xa,ya,255); 
  dy=yb-ya;
  dx=xb-xa;
  q0=dx+2*dy;
  x=xa;
  y=ya;
  putpixel(x,y,125);
  q=q0;
  while(x<xb)
  {
    if(q<=0)
    {
      q=q+2*dx+2*dy;
      y--;
    }
    else
    {
      q=q+2*dy;
    }
    x=x+1;
    putpixel(x,y,255);
    delay(100);
    printf("%d,%d\t",x,y);
  }
  //closegraph();
}

void zero_abs_m_one_right_2_left()
{
  int x;
  int y;
  int q0;
  int q;
  int dy;
  int dx;
  
  initwindow(700,700);
  putpixel(xa,ya,255); 
  dy=yb-ya;
  dx=xb-xa;
  q0=dx+2*dy;
  x=xa;
  y=ya;
  putpixel(x,y,125);
  q=q0;
  while(x>xb)
  {
    if(q<0)
    {
      q=q+2*dx+2*dy;
    }
    else
    {
      q=q+2*dy;
      y++;
    }
    x=x-1;
    putpixel(x,y,255);
    delay(100);
    printf("%d,%d\t",x,y);
  }
  //closegraph();
}

void abs_m_more_than_one_left_2_right()
{
  int x;
  int y;
  int q0;
  int q;
  int dy;
  int dx;
  
  initwindow(700,700);
  putpixel(xa,ya,255); 
  dy=yb-ya;
  dx=xb-xa;
  q0=dy+2*dx;
  x=xa;
  y=ya;
  putpixel(x,y,125);
  q=q0;
  while(y>yb)
  {
    if(q<0)
    {
      q=q+2*dx;
    }
    else
    {
      q=q+2*dy+2*dx;
      x++;
    }
    y=y-1;
    putpixel(x,y,255);
    delay(100);
    printf("%d,%d\t",x,y);
  }
  //closegraph();
}

void abs_m_more_than_one_right_2_left()
{
  int x;
  int y;
  int q0;
  int q;
  int dy;
  int dx;
  
  initwindow(700,700);
  putpixel(xa,ya,255); 
  dy=yb-ya;
  dx=xb-xa;
  q0=dy+2*dx;
  x=xa;
  y=ya;
  putpixel(x,y,125);
  q=q0;
  while(y<yb)
  {
    if(q<0)
    {
      q=q+2*dy+2*dx;
    }
    else
    {
      q=q+2*dx;
      x--;
    }
    y=y+1;;
    putpixel(x,y,255);
    delay(100);
    printf("%d,%d\t",x,y);
  }
  //closegraph();
}

void checking()
{
  //0<m<1
  if(m>=0 && m<=1)
  {
    printf("\nDuong thang can ve co he so goc 0<=m<=1");
    if(leftright(xa,xb)==1)
    {
      printf("va co chieu tu trai sang phai \n");
      zero_2_one_left_2_right();
    }
    else
    {
      printf("va co chieu tu phai sang trai \n");
      zero_2_one_right_2_left();
    }
  }

  // m>1
  if(m>1)
  {
    printf("\nDuong thang can ve co he so goc m>1");
    if(leftright(xa,xb)==1)
    {
      printf(" va co chieu tu trai sang phai \n");
      more_than_one_left_2_right();
    }
    else
    {
      printf(" va co chieu tu phai sang trai \n");
      more_than_one_right_2_left();
    }
  }

  //-1<=m<=0
  if(m>=-1 && m<=0)
  {
    printf("\nDuong thang can ve co he so goc 0<=|m|<=1");
    if(leftright(xa,xb)==1)
    {
      printf("va co chieu tu trai sang phai \n");
      zero_abs_m_one_left_2_right();
    }
    else
    {
      printf("va co chieu tu phai sang trai \n");
      zero_abs_m_one_right_2_left();
    }
  }
 
 //m<-1 
  if(m<-1)
  {
    printf("\nDuong thang can ve co he so goc |m|>1");
    if(leftright(xa,xb)==1)
    {
      printf(" va co chieu tu trai sang phai \n");
      abs_m_more_than_one_left_2_right();
    }
    else
    {
      printf(" va co chieu tu phai sang trai \n");
      abs_m_more_than_one_right_2_left();
    }
  }
 
}

//chuong trinh chinh
main()
{ //khoi tao window
  input_xy();
  checking();
  //closegraqh();
  getch();
}