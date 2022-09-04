#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>

#define maxdinh 20
#define FILENAME "input.txt"
#define MTK "mtk.txt"

// khai bao bien
int X[maxdinh];
int Y[maxdinh];
int Z[maxdinh];
int D[maxdinh][maxdinh];
float M[maxdinh];
int xgd[maxdinh];
int cot, hang;

FILE *fp;

void nhaptoado(int X[maxdinh], int Y[maxdinh] , int Z[maxdinh]){
	fp= fopen(FILENAME , "r");
	if(fp==NULL){
		printf("Khong tim thay file!!!");
		exit(1);
	}
	else
	{
		fscanf(fp,"%d",&hang);
		fscanf(fp,"%d\n",&cot);
		printf("\nSo hang: %d\nSo cot: %d \n",hang,cot);
			// doc toa do cho X
	for(int i=0; i<cot;i++){
		fscanf(fp,"%d",&X[i]);
		printf("%d ",X[i]);
	}
	printf("\n");
		// doc toa do cho Y
	for(int i=0; i<cot;i++){
		fscanf(fp,"%d",&Y[i]);
		printf("%d ",Y[i]);
	}
		printf("\n");
		// doc toa do cho Z
	for(int i=0; i<cot;i++){
		fscanf(fp,"%d",&Z[i]);
		printf("%d ",Z[i]);
	}
		printf("\n");
		fclose(fp);
	}
}

void matranke(int D[maxdinh][maxdinh]){
	fp= fopen(MTK, "r");
	if(fp==NULL){
		printf("Khong tim thay file!!!");
		exit(1);
	}
	else{
		for(int i=0; i<cot;i++){
			for(int j=0;j<cot;j++){
				fscanf(fp,"%d",&D[i][j]);	
			}
		}
		printf("\nMA tran ke: \n");
		for(int i=0; i<cot;i++){
			for(int j=0;j<cot;j++){
				printf(" %d ",D[i][j]);	
			}
			printf("\n");
		}
	}
}

int oxz(int X[maxdinh], int Z[maxdinh]){ //chieu mat ben-chieu canh
	int i,j;
	for(i=0;i<cot-1;i++){
		for(j=i+1;j<cot;j++){
			if(D[i][j]==1){
				line(X[i],Z[i],X[j],Z[j]);
			}
		}
	}
}

int oxy(int X[maxdinh], int Y[maxdinh]){ //chieu mat truoc-chieu dung
	int i,j;
	for(i=0;i<cot-1;i++){
		for(j=i+1;j<cot;j++){
			if(D[i][j]==1){
				line(X[i],Y[i],X[j],Y[j]);
			}
		}
	}
}
int phepquay(int X[maxdinh], int Z[maxdinh], int xr, int yr, int goc){
	float dx,dy;
	for(int i=0;i<cot;i++){
		dx = (float) X[i]-xr;
		dy = (float) Z[i]-yr;
		X[i] = xr + (float) dx*cos(goc*3.1416/180) - (float)dy*sin(goc*3.1416/180);
		Z[i] = yr + (float) dx*sin(goc*3.1416/180) + (float)dy*cos(goc*3.1416/180);
	}
}

int Scanline (int X[maxdinh], int Y[maxdinh]){
	X[cot]=X[0];
	Y[cot]=Y[0];
	int i;
	for(i =0 ;i<cot;i++){
	float dx,dy;
	dx=X[i+1]-X[i];
	dy=Y[i+1]-Y[i];
	if(dy==0){
		M[i]=0.0;
	}
	if(dx==0){
		M[i]=1.0;
	}
	if(dx!=0&&dy!=0){
		M[i]=(float)(dx)/dy;
	}
}
	printf("\nHe so goc cac canh cua da giac la: \n");
	for(i=0;i<cot;i++){
		printf(" %0.1f ",M[i]);
	}
	int ymin=Y[0];
	int ymax=Y[0];
	//tim ymin
	for(i=1;i<cot;i++){
		if(ymin>Y[i]){
			ymin=Y[i];
		}
	}
	//tim ymax
	for(i=1;i<cot;i++){
		if(ymax<Y[i]){
			ymax=Y[i];
		}
	}
	printf("\nYmin = %d",ymin);
	printf("\nYmax = %d",ymax);
	
	
	// tim hoanh do giao diem cua y(ymin -> ymax) voi cac dinh cua da giac
	int y;
	for(y=ymin;y<=ymax;y++){
		int dem=0; //reset so giao diem
		for(i=0;i<cot;i++){
			if(((y < Y[i])&&(y < Y[i+1]))||((y > Y[i])&&(y > Y[i+1]))){
			//khong co giao diem - khong can tinh	
			}
			else{
				xgd[dem]= round(X[i]+(y-Y[i])*M[i]);	
				dem++;
			}
		}
		printf("\nHoanh do giao diem cua y = %d voi cac canh da giac",y);
		for(i=0;i<dem;i++){
			printf("\n (%d,%d) ",xgd[i],y);
		}
		// ve doan thang noi lien cac giao diem
		for(i=0;i<dem-1;i=i+2){
			line(xgd[i],y,xgd[i+1],y);
		}
	}//het y
	
}
int main(){
	nhaptoado(X,Y,Z);
	matranke(D);
	initwindow(600,600);
	setcolor(YELLOW);
//	printf("\nKet qua hinh chieu bang:\n");
	//oxz(X,Z);	
//	for(int i=0;i<17;i++){
	//	setcolor(i);
		phepquay(X,Y,300,300,20);
		//oxz(X,Z);
		oxy(X,Y);
		Scanline(Y,Z);
		delay(100);
		//cleardevice();
//	}
	getch();
}
