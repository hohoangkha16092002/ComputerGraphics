#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>

#define maxdinh 20
#define INPUT "chopcut.inp"
#define MTK "chopcut.mtk"

int X[maxdinh];
int Y[maxdinh];
int Z[maxdinh];
int D[maxdinh][maxdinh];
int hsg[maxdinh];
int xgd[maxdinh];
int sodinh,sochieu;
FILE *fp;

void nhaptoado(int X[maxdinh],int Y[maxdinh], int Z[maxdinh]) {
	fp= fopen(INPUT,"r");
	if(fp==NULL) {
		printf("Khong tim thay file INPUT!");
		exit(1);
	} else {
		fscanf(fp,"%d",&sodinh);
		fscanf(fp,"%d",&sochieu);
		printf("\nSo dinh: %d \n Sochieu: %d\n");
		for(int i=0; i<sodinh; i++) {
			fscanf(fp,"%d",&X[i]);
			printf("%d ",X[i]);
		}
		for(int i=0; i<sodinh; i++) {
			fscanf(fp,"%d",&Y[i]);
			printf("%d ",Y[i]);
		}
		for(int i=0; i<sodinh; i++) {
			fscanf(fp,"%d",&Z[i]);
			printf("%d ",Z[i]);
		}
		fclose(fp);
	}
	
}

void matranke(int D[maxdinh][maxdinh]) {
	fp= fopen(MTK,"r");
	if(fp==NULL) {
		printf("Khong tim thay file MTK!");
		exit(1);
	} else {
		for(int i=0;i<sodinh-1;i++) {
			for(int j=i+1; j<sodinh; j++) {
				if(D[i][j]==1);
				line(X[i],Y[i],X[j],Y[j]);
			}
		}
	}
}
