#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>
#define FILENAME "scanline.inp"
#define maxdinh 10
FILE *fp;
int X[10];
int Y[10];
int Z[10];
int D[10][10];
int sodinh;
int toado[maxdinh][2];
float hsg[maxdinh];
int swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void Nhap(int X[maxdinh], int Y[maxdinh], int Z[maxdinh]){
	fp = fopen(FILENAME,"r");
	if(fp == NULL){
		printf("file not found");
		exit(1);
	}else{
			fscanf(fp,"%d",&sodinh);
			for(int j=0;j<sodinh;j++)
				fscanf(fp,"%d",&X[j]);			
			for(int j=0;j<sodinh;j++)
				fscanf(fp,"%d",&Y[j]);
			for(int j=0;j<sodinh;j++)
				fscanf(fp,"%d",&Z[j]);		
		for(int i=0;i<sodinh;i++)
		{
			for(int j=0;j<sodinh;j++){
				fscanf(fp,"%d",&D[i][j]);
			}
		}
		fclose(fp);
	}
}
void intoadoadiem()
{
	  int i,j;
	  for(i=0;i<sodinh;i++)
			{
				 printf("%d\t",X[i]);
			}
			
			printf("\n");
			for(i=0;i<sodinh;i++)
			{
				 printf("%d\t",Y[i]);
			}
			
			printf("\n");
			for(i=0;i<sodinh;i++)
			{
				 printf("%d\t",Z[i]);
			}
}
void matranke()
{
	  int i,j;
	  
	  for(i=0;i<sodinh;i++)
	  {
	  	 D[i][i]=1;
			}
			
			for(i=0;i<sodinh-1;i++)
			{
				 for(j=i+1;j<sodinh;j++)
				 {
				 	  printf("D[%d,%d]= ",i,j);
				 	  scanf("%d",&D[i][j]);
					}
			}
			
			for(i=0;i<sodinh;i++)
			{
				  for(j=0;j<sodinh;j++)
				  {
				  	  if(i>j)
				  	  {
				  	  	  D[i][j]=D[j][i];
									}
						}
			}
}

void inmatranke()
{
	  int i,j;
	  
	  	//in ra ma tran ke
			printf("\nDanh sach ma tran ke:\n");
			for(i=0;i<sodinh;i++)
			{
				  for(j=0;j<sodinh;j++)
				  {
				  	  printf("%d\t",D[i][j]);
						}
						printf("\n");
			}
}

void oxy()
{
	int i,j;
	  
	  //cai nay do minh dat ban dau, neu sau nay tu nhap tu ban phim thi thay bang so cu the
	int m =0;
	for(i=0;i<sodinh-1;i++)
	{
	  	for(j=i+1;j<sodinh;j++)
		{
	  	 	if(D[i][j]==1)
	  		  	{
	  	 		line(X[i],Y[i],X[j],Y[j]);	  	 			  	 		
			    }	  	 	  	
		}
	}
}

void oxz()
{
	  int i,j;
	  
	  //cai nay do minh dat ban dau, neu sau nay tu nhap tu ban phim thi thay bang so cu the
	  
	  for(i=0;i<sodinh-1;i++)
	  {
	  	 for(j=i+1;j<sodinh;j++)
	  	 {
	  	 	  if(D[i][j]==1)
	  	 	  {
	  	 	  	  line(X[i],Z[i],X[j],Z[j]);
								}
					}
			}
}

void oyz()
{
	  int i,j;
	  
	  //cai nay do minh dat ban dau, neu sau nay tu nhap tu ban phim thi thay bang so cu the
	  
	  for(i=0;i<sodinh-1;i++)
	  {
	  	 for(j=i+1;j<sodinh;j++)
	  	 {
	  	 	  if(D[i][j]==1)
	  	 	  {
	  	 	  	  line(Y[i],Z[i],Y[j],Z[j]);
								}
					}
			}
}


void ve3D()
{
	setcolor(RED);
	oxy();
	
	setcolor(GREEN);
	oxz();	

	setcolor(YELLOW);
	oyz();	

}
int vedagiac(int toado[maxdinh][2])
{

	//Nhap cac phan tu cua mang 2 chieu
	int i,j;
	for(i = 0; i < sodinh; i++)
	{
		toado[i][0]=X[i];
	}
	for(i=0; i < sodinh; i++)
	{
		toado[i][1]=Z[i];
	}
	//them dinh moi bang voi dinh dau
	toado[sodinh][0] = toado[0][0];		//X moi = Xdau
	toado[sodinh][1] = toado[0][1];		//Y moi = Ydau
	sodinh++;
	//tim he so goc
	for(i = 0; i < sodinh - 1; i++)
	{
		if(toado[i+1][0] == toado[i][0])		//dx = 0
		{
			hsg[i] = 99999;
		}
		else
		{
			if(toado[i+1][1] == toado[i][1])
			{
				hsg[i] = 1.00;
			}
			else
			{
				hsg[i] = (float)(toado[i+1][1] - toado[i][1])/(toado[i+1][0] - toado[i][0]);
			}
		}
	}
}

int scanline(int toado[maxdinh][2], int color)
{
	//tim ymin, ymax
	int ymin = toado[0][1];		//y0
	int ymax = toado[0][1];		//y0
	int i;
	for(i = 1; i < sodinh - 1; i++)
	{
		if(ymin > toado[i][1])
		{
			ymin = toado[i][1];
		}
	}
	for(i = 1; i < sodinh - 1; i++)
	{
		if(ymax < toado[i][1])
		{
			ymax = toado[i][1];
		}
	}

	//tim hoanh do giao diem tu ymin den ymax
	int y;
	int xgd[sodinh];
	for(y = ymin; y <= ymax; y++)
	{
		int dem = 0;	//reset so luong giao diem
		for(i = 0; i <sodinh - 1; i++)
		{
			if((y < toado[i][1] && y < toado[i+1][1]) || (y > toado[i][1] && y > toado[i+1][1]))
			{
				printf("Voi y = %d, khong co giao diem \n", y);
			}
			else
			{
				//Xac dinh giao diem cho tung canh
				xgd[dem] = round(toado[i][0] + (y - toado[i][1])/hsg[i]);
				dem++;
			}
		}
		//sap xep cac giao diem tang dan theo hoanh do
		for(i = 0; i < dem - 1; i++)
		{
			if(xgd[i]>xgd[i+1])
			{
				swap(&xgd[i], &xgd[i+1]);
			}
		}
		//in ra toa do cac giao diem
		for(i = 0; i < dem; i++)
		{
			printf("\nVoi y = %d, giao diem (%d, %d)\n", y, xgd[i], y);
		}
		//Ve cac doan thang noi cac hoanh do giao diem 
		setcolor(color);
		for(i = 0; i < dem - 1; i = i+2)
 		{
			line(xgd[i],y,xgd[i+1],y);
 		}
	}//tang dong quet len 1; y = y+1
}
//chuong trinh chinh
int main()
{

	Nhap(X,Y,Z);
    intoadoadiem();						
	//in ra ma tran ke
	inmatranke();				
	//khoi tao man hinh do hoa
	initwindow(600,600);	  
	//ve3D();	 
	vedagiac(toado); 
	scanline(toado, 9);
	getch();
}
