#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>

#define maxdinh 20
#define INPUT "chopnhon.txt"
#define MTK "chopnhonmtk.txt"


int X[maxdinh],Y[maxdinh],Z[maxdinh];
int D[maxdinh][maxdinh],P[maxdinh][maxdinh];
int sochieu,sodinh;
FILE *fp;


void nhaptoado(){
	
	fp = fopen(INPUT,"r");
	if (fp==NULL)
	{
		printf("FILE NOT FOUND!");
		exit(1);
	}
	else
	{
		fscanf(fp,"%d",&sochieu);
		fscanf(fp,"%d",&sodinh);
		printf("so chieu = %d\n",sochieu);
		printf("so dinh = %d\n",sodinh);
		
		for(int i=0; i<sochieu;i++)
		{
			for(int j=0;j<sodinh;j++)
			{
				fscanf(fp,"%d",&P[i][j]);
			}
		}
		for(int i=0; i<sodinh;i++)
		{
			X[i]=P[0][i];
			Y[i]=P[1][i];
			Z[i]=P[2][i];
		}
	}
	fclose(fp);
}

void matranke()
{
	int i,j;
	fp = fopen(MTK,"r");
	
	if(fp==NULL)
	{
		printf("FILE NOT FOUND!");
		exit(1);
	}
	else 
	{
		for (i=0;i<sodinh;i++)
		{
			for (j=0;j<sodinh;j++)
			{
				fscanf(fp,"%d",&D[i][j]);
			}
		}
		
		for (i=0;i<sodinh;i++)
		{
			for (j=0;j<sodinh;j++)
			{
				printf("%d",D[i][j]);
			}
			printf("\n");
		}	
	}
}

int oxy()
{
	int i,j;
	
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

void phepquayoxy(int xr, int yr, int phi)
{
	int i,dx,dy;
	for(i=0;i<sodinh;i++)
	{
		dx=X[i]-xr;
		dy=Y[i]-yr;
		X[i]= (xr+ (float)dx*cos(phi*3.1416/180) - (float)dy*sin(phi*3.1416/180));
		Y[i]= (yr+ (float)dx*sin(phi*3.1416/180) + (float)dy*cos(phi*3.1416/180));		
	}
	oxy();
}


int main()
{
	nhaptoado();
	matranke();
	initwindow(800,800);
	oxy();
	phepquayoxy(200,200,30);
	getch();
}


