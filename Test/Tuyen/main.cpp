#include<stdio.h>
#include<math.h>
#include<graphics.h>
#define INPUT "chopnhon.inp"
#define matranke "chopnhon.mtk"
#define maxdinh 20
int P[maxdinh][maxdinh],D[maxdinh][maxdinh];
int X[maxdinh],Y[maxdinh],Z[maxdinh];
int sodinh, sochieu;
float m[maxdinh];

FILE *fp;
void nhapdinh()
{
	fp=fopen(INPUT,"r");
	if(fp==NULL)
	{
		printf("File not found");
		exit(1);
	}
	else
	{
		fscanf(fp,"%d",&sochieu);
		fscanf(fp,"%d",&sodinh);
		for(int i=0;i<sochieu;i++)
			for(int j=0;j<sodinh;j++)
				fscanf(fp,"%d",&P[i][j]);
		for(int i=0;i<sodinh;i++)
		{
			X[i]=P[0][i];
			Y[i]=P[1][i];
			Z[i]=P[2][i];	
		}
	}
}
void nhapmatranke()
{
	fp=fopen(matranke,"r");
	if(fp==NULL)
	{
		printf("File not found");
		exit(1);
	}
	else
	{
		for(int i=0;i<sodinh;i++)
			for(int j=0;j<sodinh;j++)
				fscanf(fp,"%d",&D[i][j]);
	}
}
void xuat()
{
	printf("%5d %5d",sodinh,sochieu);
	printf("\n matranP: \n");
	for(int i=0;i<sochieu;i++)
	{
			for(int j=0;j<sodinh;j++)
			{
				printf("%5d",P[i][j]);
			}
		printf("\n");
	}
	printf("matranke: \n");
	for(int i=0;i<sodinh;i++)
	{
			for(int j=0;j<sodinh;j++)
			{
				printf("%5d",D[i][j]);
			}
		printf("\n");
	}
				
}
void Oxy()
{
	for(int i=0;i<sodinh-1;i++){
		for(int j=i+1;j<sodinh;j++){
			if(D[i][j]==1){
				line(X[i],Y[i],X[j],Y[j]);
			}
		}
	}
				
}
void Oxz()
{
	for(int i=0;i<sodinh-1;i++){
		for(int j=i+1;j<sodinh;j++){
			if(D[i][j]==1){
				line(X[i],Z[i],X[j],Z[j]);
			}
		}
	}	
				
}
void Oyz()
{

	for(int i=0;i<sodinh-1;i++){
		for(int j=i+1;j<sodinh;j++){
			if(D[i][j]==1){
				line(Y[i],Z[i],Y[j],Z[j]);
			}
		}
	}	
				
}
void PhepquayXY(int xr,int yr,int phi)
{
	int dx,dy;
	for(int i=0;i<sodinh;i++)
	{
		dx=X[i]-xr;
		dy=Y[i]-yr;
		X[i]=(xr+(float)dx*cos(phi*3.1416/180)-(float)dy*sin(phi*3.1416/180));
		Y[i]=(yr+(float)dx*sin(phi*3.1416/180)+(float)dy*cos(phi*3.1416/180));
	}
	Oxy();
}
void PhepquayXZ(int xr,int zr,int phi)
{
	int dx,dz;
	for(int i=0;i<sodinh;i++)
	{
		dx=(X[i]-xr);
		dz=(Z[i]-zr);
		X[i]=(xr+(float)dx*cos(phi*3.1416/180)-(float)dz*sin(phi*3.1416/180));
		Z[i]=(zr+(float)dx*sin(phi*3.1416/180)+(float)dz*cos(phi*3.1416/180));
	}
	Oxz();
}
void PhepquayYZ(int yr,int zr,int phi)
{
	int dy,dz;
	for(int i=0;i<sodinh;i++)
	{
		dy=(Y[i]-yr);
		dz=(Z[i]-zr);
		Y[i]=(yr+(float)dy*cos(phi*3.1416/180)-(float)dz*sin(phi*3.1416/180));
		Z[i]=(zr+(float)dy*sin(phi*3.1416/180)+(float)dz*cos(phi*3.1416/180));
	}
	Oyz();
}
void hesogoc()
{
  
	for(int i=0;i<sodinh;i++)
	printf("%5d",X[i]);
	X[sodinh]=X[0]; // Xmoi=Xdau
	Y[sodinh]=Y[0]; // ymoi=ydau
	sodinh++;
	// tim he so goc
	for(int i=0;i<sodinh-1;i++){
		if (X[i+1]==X[i]){//dx=0;
			m[i]=99999;
		}
		else {
			if (Y[i+1]==Y[i]){
				m[i]=1;
				
			}
			else{
			m[i]=(float)(Y[i+1]-Y[i])/(X[i+1]-X[i]);		
			}
		}

	}
	// in ra he so goc
	printf("\nhe so goc cac canh cua da giac: \n");
	for(int i=0;i<sodinh-1;i++){
		printf("%.2f\t",m[i]);
	}
}
int scanline( int color){
	// tim ymin, ymax
	int ymin=Y[0];// Y0
	int ymax=Y[0];// Y0
	int i;
	
	for(i=1;i<sodinh-1;i++){
		if (ymin > Y[i]){
			ymin=Y[i];
			}
		}
	for(i=1;i<sodinh-1;i++){
		if (ymax < Y[i]){
			ymax=Y[i];
			}
		}
	// tim hoanh do giao diem tu ymin den ymax
	int y;
	int xgd[sodinh];
	for(y=ymin; y<=ymax;y++){
		int dem=0; // reset so luong gdiem
		for(int i=0;i<sodinh-1;i++){
		if ((y<Y[i] && y<Y[i+1])||(y>Y[i] && y>Y[i+1])){
			//printf("\nVoi y= %d, khong co giao diem\n",z);
		}
		else{
			// xac dinh giao diem cho tung canh
				xgd[dem]=round(X[i]+(y-Y[i])/m[i]);
				dem++;
			
			}
		}	


		// ve cac doan thang noi cac hoanh do gdiem
		setcolor(color);	
		for(int i=0;i<dem-1;i=i+2){
			line (xgd[i],y,xgd[i+1],y);
		}
	}

}
int main()
{
	initwindow(800,600);
	nhapdinh();
	nhapmatranke();
	xuat();
	//Oxy();
	Oxz();
	//Oyz();
	for(int i=1;i<12;i++)
	{
		setcolor(i);
PhepquayXZ(200,200,30);
	//	scanline(i);
	}
	hesogoc();
		

	getch();
	return 0;
	
}
