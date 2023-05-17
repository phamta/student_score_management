#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max 50  // danh  

int dem=0; // dem so lan sua diem 
float d[max]; // mang de luu diem trung binh
char MSV[max][10]; // mang de luu ma sinh vien max: so luong sinh vien Con 10 la do dai cua moi chuoi

struct SinhVien {
    char msv[10];
    char ten[30];
    char malop[10];
    float Lab1;
    float Lab2;
    float ProgressTest1;
    float ProgressTest2;
    float Presentation;
    float FinalTest;
//    float Diemtrungbinh;
};

typedef SinhVien SV;
//SV sv1;

void Menu(){
		printf("******************************************\n");
        printf("**  CHUONG TRINH QUAN LY DIEM SINH VIEN **\n");
        printf("**      1. Nhap diem                    **\n");
        printf("**      2. Xem diem                     **\n");
        printf("**      3. Sua diem                     **\n");
        printf("**      4. Sap Xep                      **\n");
        printf("**      5. In ra danh sach              **\n");
        printf("**      0. Thoat                        **\n");
        printf("******************************************\n");
        printf("**       Nhap lua chon cua ban          **\n");
}

// doc msv ten va ma lop tu file
void Docfile(struct SinhVien* arr_sv , int* slsv){
	FILE* f;
	f = fopen("input.txt","r");
	struct SinhVien SV;
	int i=0;
	if(f){
		while (fscanf(f,"%10s %20[^\n] %10s\n",SV.msv,SV.ten,SV.malop) == 3) {
            arr_sv[i++]= SV;
		}
	}
	*slsv=i;
	fclose(f);
}

// doc va luu ma sinh vien vao mang MSV
void Docmsv(int slsv){
	FILE *f;
	f = fopen("input.txt","r");
	struct SinhVien SV;
	int i = 0;
	if(f){
		for(;;){
			fscanf(f,"%10s %20[^\n] %10s \n",MSV[i++],SV.ten,SV.malop);	
			if(feof(f)){
				break;
			}
		}
	}
	fclose(f);
}

// cac mang sau de kiem tra diem da duoc nhap chua 
int checklab1[max], checklab2[max],checkPT1[max],checkPT2[max],checkPre[max],checkFn[max];
void check(int slsv){
	for(int i=0; i<slsv; i++) checklab1[i]=0;
	for(int i=0; i<slsv; i++) checklab2[i]=0;
	for(int i=0; i<slsv; i++) checkPT1[i]=0;
	for(int i=0; i<slsv; i++) checkPT2[i]=0;
	for(int i=0; i<slsv; i++) checkPre[i]=0;
	for(int i=0; i<slsv; i++) checkFn[i]=0;
}

void hienThiTTsv(struct SinhVien SV){
	printf("%s   %s %s",SV.msv,SV.ten,SV.malop);
}

void hienThiDSSV(struct SinhVien* arr_sv, int slsv){

int i;
for(i = 0; i <slsv; i++) {
	hienThiTTsv(arr_sv[i]);
	printf("\n");
}
}

// ham de kiem tra diem vua nhap co hop le khong
int ktra() {
    int input;
    char c;
    bool hople = false;
    while (!hople) {
        if (scanf("%d", &input) != 1) {
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Nhap sai, xin nhap lai: \n");
        } else if (input < 0 || input > 10) {
            printf("Nhap sai, xin nhap lai: \n");
        } else {
            hople = true;
        }
    }
    return input;
}

// ham de nhap diem va luu diem nhap vao file output.txt
void Ghifile(struct SinhVien* arr_sv,int slsv){
	char msv[10];
	int bug=0;
	int tam; // bien de luu chi so trong mang MSV trung voi ma sinh vien nhap tu ban phim
//	do{
//		printf("Nhap ma sinh vien can nhap diem: ");
//		bug = scanf("%d",&msv);
//		if(bug==1&&bug>0){
//		}else{
//			printf("Gia tri nhap vao khong hop le. Vui long nhap lai.\n");
//		}
//	}while(!bug);
	printf("Nhap ma sinh vien can nhap diem: ");
	scanf("%s",msv);
	getchar();
	for(int i=0;i<slsv;i++){
		int kq = strcmp(msv,arr_sv[i].msv); // kiem tra msv vua nhap co trong danh sach khong
		if(kq==0){
			bug = 1;
			tam = i;
			break;
		}
	}
	if(bug==0) printf("\nKhong tim thay ma sinh vien trong danh sach\n");
	else{
			int muc;
			do{
				printf("Chon diem can nhap:\n");
				printf("1. Lab1\n");
				printf("2. Lab2\n");
				printf("3. ProgressTest1\n");
				printf("4. ProgressTest2\n");
				printf("5. Presentation\n");
				printf("6. FinalTest\n");
				printf("7. Thoat\n");
				printf("Lua chon cua ban: ");
				if(scanf("%d",&muc)!=1){
					while(getchar()!='\n');
					muc=0;
				}
				switch(muc){
					case 1:
						printf("Nhap diem Lab1: ");
						arr_sv[tam].Lab1=ktra(); checklab1[tam]++;
						break;
					case 2:
						printf("Nhap diem Lab2: ");
						arr_sv[tam].Lab2=ktra(); checklab2[tam]++;
						break;
					case 3:
						printf("Nhap diem ProgressTest1: ");
						arr_sv[tam].ProgressTest1=ktra(); checkPT1[tam]++;
						break;
					case 4:
						printf("Nhap diem ProgressTest2: ");
						arr_sv[tam].ProgressTest2=ktra(); checkPT2[tam]++;
						break;
					case 5:
						printf("Nhap diem Presentation: ");
						arr_sv[tam].Presentation=ktra(); checkPre[tam]++;
						break;
					case 6:
						printf("Nhap diem FinalTest: ");
						arr_sv[tam].FinalTest=ktra(); checkFn[tam]++;
						break;
					case 7:
						break;
					default:
						printf("Lua chon khong hop le. Vui long nhap lai.\n\n");
						break;
				}
			}while(muc!=7);
//			FILE* f = fopen("output.txt", "w");
//			if (f == NULL) {
//			    printf("Khong the mo file output.txt\n");
//			    return;
//						}
//			else{
//				fprintf(f, "%-10s %-30s %-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", "MSV", "Ten", "MaLop", "Lab1", "Lab2", "PT1", "PT2", "Pres", "Final", "Tbinh");
//for (int j = 0; j < slsv; j++) {
//    fprintf(f, "%-10d %-30s %-10d %-10.2f %-10.2f %-10.2f %-10.2f %-10.2f %-10.2f Chua tinh\n", arr_sv[j].msv, arr_sv[j].ten, arr_sv[j].malop, arr_sv[j].Lab1, arr_sv[j].Lab2, arr_sv[j].ProgressTest1, arr_sv[j].ProgressTest2, arr_sv[j].Presentation, arr_sv[j].FinalTest);
//				}
//			}
//fclose(f);
//			break;
//			printf("\n Diem trung binh la : %.2f",arr_sv[i].Lab1 + arr_sv[i].Lab2 + arr_sv[i].ProgressTest1 + arr_sv[i].ProgressTest2 + arr_sv[i].Presentation+arr_sv[i].FinalTest);

		}
}

void in1sinhvien(SV arr_sv[],int i){
		printf("\nMSV: %s",arr_sv[i].msv);
		printf("\nTen: %s",arr_sv[i].ten); 
		printf("\nMa lop: %s",arr_sv[i].malop);
		if(checklab1[i]!=0)printf("\nDiem Lab1: %.2f",arr_sv[i].Lab1); else printf("\nDiem Lab1: ____");
		if(checklab2[i]!=0)printf("\nDiem Lab2: %.2f",arr_sv[i].Lab2); else printf("\nDiem Lab2: ____");
		if(checkPT1[i]!=0)printf("\nDiem Progress Test 1: %.2f",arr_sv[i].ProgressTest1); else printf("\nDiem Progress Test 1:___");
		if(checkPT2[i]!=0)printf("\nDiem Progress Test 2: %.2f",arr_sv[i].ProgressTest2); else printf("\nDiem Progress Test 2:___");
		if(checkPre[i]!=0)printf("\nDiem Presentation: %.2f",arr_sv[i].Presentation); else printf("\nDiem Presentation:___");
		if(checkFn[i]!=0)printf("\nDiem Final Test: %.2f\n\n",arr_sv[i].FinalTest); else printf("\nDiem Final Test:___");
}

void insinhvien(SV arr_sv[],int slsv){
	for(int i=0; i<slsv; i++)
		{
		in1sinhvien(arr_sv,i);
		}
	printf("\n");
}

// ham de xem diem cua sinh vien can tim
void show(SV arr_sv[], int slsv){
	int cp=0;
			char t[10]; printf("Nhap MSV can xem : "); scanf("%s",t);
			for(int i=0; i<slsv; i++){
				int kq = strcmp(t,MSV[i]); //
				if (kq==0) 
				{
					in1sinhvien(arr_sv,i);
					cp=1;
					break;
				}	
			}
			if(cp==0)printf("Khong tim thay!");
			printf("\n");
} 
//
//void luu(SV arr_sv[],int slsv){
//	for(int i=0; i<slsv;i++){
//		MSV[i]= arr_sv[i].msv;
//	}
//} 

float trungbinh(SV arr_sv[], int slsv, float d[]){
	for(int i=0; i<slsv; i++){
		d[i]= (arr_sv[i].Lab1 + arr_sv[i].Lab2 + arr_sv[i].ProgressTest1 + arr_sv[i].ProgressTest2 + arr_sv[i].Presentation+arr_sv[i].FinalTest)/6;
	}
//	for(int i=0; i<slsv; i++){
//		printf("Diem trung binh cua sinh vien co ma %d la : %.2f\n",MSV[i],d[i]);
//	}
}


void Hoandoi(float *i, float *j){
		float tam;
		tam = *i;
		*i =*j;
		*j= tam;
	}

void Hoandoi2(char a[], char b[]) {
    char temp[10];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

// sap xep va in ra diem trung binh tu cao den thap 
void sapxep(float d[], int slsv){
	for(int i=0; i<slsv-1; i++){
		for(int j=i+1; j<slsv; j++)
		if(d[i]<d[j]) {
			Hoandoi(&d[i],&d[j]);
			Hoandoi2(MSV[i],MSV[j]);
		}
	}
	int count = 0;
	for(int i=0; i<slsv; i++){
		printf("\n%d.Diem trung binh cua sinh vien co ma %s : %.2f",++count,MSV[i],d[i]);
		if (d[i]>=8.5) printf (" Hoc luc A");
		else if (d[i]<=8.4 && d[i]>=7.0) printf(" Hoc luc B"); 
		else if (d[i]<=6.9 && d[i]>=5.5) printf(" Hoc luc C"); 
		else if (d[i]<=5.4 && d[i]>=4.0) printf(" Hoc luc D"); 
		else printf(" Hoc luc F");
	}
	printf("\n");
}

void Doidiem(SV arr_sv[], int i){
	printf("\nDiem Lab1: "); arr_sv[i].Lab1=ktra();
	printf("\nDiem Lab2: "); arr_sv[i].Lab2=ktra();
	printf("\nDiem ProgressTest1: "); arr_sv[i].ProgressTest1=ktra();
	printf("\nDiem ProgressTest2: "); arr_sv[i].ProgressTest2=ktra();
	printf("\nDiem Presentation: "); arr_sv[i].Presentation=ktra();
	printf("\nDiem Final Test: "); arr_sv[i].FinalTest=ktra();	
}

void Doidiem1(SV arr_sv[], int choose, int i){
	switch(choose){
		case 1: if(checklab1[i]!=0) {printf("\nDiem Lab1: "); arr_sv[i].Lab1=ktra();} else printf("\nDiem chua nhap tu choi sua");break;
		case 2: if(checklab2[i]!=0) {printf("\nDiem Lab2: "); arr_sv[i].Lab2=ktra();} else printf("\nDiem chua nhap tu choi sua");break;
		case 3: if(checkPT1[i]!=0)	{printf("\nDiem ProgressTest1: "); arr_sv[i].ProgressTest1=ktra();} else printf("\nDiem chua nhap tu choi sua"); break;
		case 4: if(checkPT2[i]!=0)	{printf("\nDiem ProgressTest2: "); arr_sv[i].ProgressTest2=ktra();} else printf("\nDiem chua nhap tu choi sua"); break;
		case 5: if(checkPre[i]!=0)	{printf("\nDiem Presentation: "); arr_sv[i].Presentation=ktra();} else printf("\nDiem chua nhap tu choi sua"); break;
		case 6: if(checkFn[i]!=0)	{printf("\nDiem FinalTest: "); arr_sv[i].FinalTest=ktra();} else printf("\nDiem chua nhap tu choi sua"); break;
	}
}

void title(){
	printf("Bai tap PPL");
	printf("\nVan Ba Pham Tan MSV: 102220250 Lop 22T_DT5");
	printf("\nHo Quy Ly       MSV: 102220239 Lop 22T_DT5");
	printf("\nCopyright 01\n");
}

void ghitbinh(SV arr_sv[], int slsv,float d[]){
	FILE *ftb;
	ftb = fopen("Diemtrungbinh.txt","w");
	fprintf(ftb,"MSV\tTen\t\t\t\tMa lop\t  Diem Trung Binh\t\tHoc luc\n");
	for(int i=0; i<slsv; i++){
		fprintf(ftb,"%s	%s	%s	 \t\t%.2f",arr_sv[i].msv,arr_sv[i].ten,arr_sv[i].malop,d[i]);
		if (d[i]>=8.5) fprintf (ftb,"\t\t\t   A\n");
		else if (d[i]<=8.4 && d[i]>=7.0) fprintf (ftb,"\t\t\t   B\n"); 
		else if (d[i]<=6.9 && d[i]>=5.5) fprintf (ftb,"\t\t\t   C\n"); 
		else if (d[i]<=5.4 && d[i]>=4.0) fprintf (ftb,"\t\t\t   D\n"); 
		else fprintf (ftb,"\t\t\t   F\n");		
	}
	fclose(ftb);
}

void ghidiem(SV arr_sv[], int slsv){
	FILE *fd;
	fd = fopen("output.txt","w");
	fprintf(fd,"MSV\tTen\t\t\tMa lop\tLab1\tLab2\tPT1\tPT2\tPre\tFinal\n");
	for(int i=0; i<slsv; i++){
		fprintf(fd,"%s\t%s  %s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",arr_sv[i].msv,arr_sv[i].ten,arr_sv[i].malop,arr_sv[i].Lab1,arr_sv[i].Lab2,arr_sv[i].ProgressTest1,arr_sv[i].ProgressTest2,arr_sv[i].Presentation,arr_sv[i].FinalTest);
	}
	fclose(fd);
}

// ham de nhap diem thanh phan cho toan bo danh sach 
void nhapds(struct SinhVien* arr_sv,int slsv){
	
	printf("Chon diem can nhap:\n");
	printf("1. Lab1\n");
	printf("2. Lab2\n");
	printf("3. ProgressTest1\n");
	printf("4. ProgressTest2\n");
	printf("5. Presentation\n");
	printf("6. FinalTest\n");
	printf("7. Thoat\n");
	printf("Lua chon cua ban: ");
	int nhap ; scanf("%d",&nhap);
	switch(nhap){
		case 1: 
			for(int i=0; i<slsv; i++){
				printf("Nhap diem Lab1 cho sinh vien %d: ",i+1);
				arr_sv[i].Lab1 = ktra(); checklab1[i]++;
			}
			break;
		case 2:
			for(int i=0; i<slsv; i++){
				printf("Nhap diem Lab2 cho sinh vien %d: ",i+1);
				arr_sv[i].Lab2 = ktra(); checklab2[i]++;
			}
			break;
		case 3:
			for(int i=0; i<slsv; i++){
				printf("Nhap diem Progress Test 1 cho sinh vien %d : ",i+1);
				arr_sv[i].ProgressTest1 = ktra(); checkPT1[i]++;
			}
			break;	
		case 4:
			for(int i=0; i<slsv; i++){
				printf("Nhap diem Progress Test 2 cho sinh vien %d : ",i+1);
				arr_sv[i].ProgressTest2 = ktra(); checkPT2[i]++;
			}
			break;
		case 5:
			for(int i=0; i<slsv; i++){
				printf("Nhap diem Presentation cho sinh vien %d : ",i+1);
				arr_sv[i].Presentation = ktra(); checkPre[i]++;
			}
			break;
		case 6:
			for(int i=0; i<slsv; i++){
				printf("Nhap diem Final Test cho sinh vien %d : ",i+1);
				arr_sv[i].FinalTest = ktra(); checkFn[i]++;
			}
			break;
		case 7: break;
	}
	for(int i=0; i<slsv; i++){
		printf("Diem trung binh cua sinh vien co ma la : %.2f\n",(arr_sv[i].Lab1 + arr_sv[i].Lab2 + arr_sv[i].ProgressTest1 + arr_sv[i].ProgressTest2 + arr_sv[i].Presentation+arr_sv[i].FinalTest)/6);
	}		
} 

int main(){
	int chon;
	//SV a[max];
	int n;
	SV arr_sv[max]; // mang luu thong tin sinh vien 
	title();
	int chon1,chon2,chon3; // chon che do xem trong case1 case2 case3 
	int slsv = 0;
	Docfile(arr_sv,&slsv);
	for (int i = 0; i < slsv; i++) {
		arr_sv[i].Lab1 = 0;
    	arr_sv[i].Lab2 = 0;
    	arr_sv[i].ProgressTest1 = 0;
    	arr_sv[i].ProgressTest2 = 0;
    	arr_sv[i].Presentation = 0;
    	arr_sv[i].FinalTest = 0;
	}
	ghidiem(arr_sv,slsv);
	do{
        Menu();
		scanf("%d",&chon);
		int cp=0; // kiem tra msv vua nhap co trong danh sach khong 
		int tan = 0;
//		int slsv = 0;
//		Docfile(arr_sv,&slsv);
		switch(chon){
			case 1:
				Docmsv(slsv);
				printf("MSV Ho va ten   \tMa lop\n");
				hienThiDSSV(arr_sv,slsv);
				printf("Danh sach co %d sinh vien\n",slsv);
//				Ghifile(arr_sv,slsv);
//			insinhvien(arr_sv,slsv);
				printf("1_Nhap cho mot sinh vien\n");
				printf("2_Nhap cho toan bo danh sach\n");
				printf("3_Thoat\n");
				printf("Nhap lua chon : "); scanf("%d",&chon1);
				if(chon1==1) {
					Ghifile(arr_sv,slsv);
//					printf("Diem trung binh la: %.2f",(arr_sv[i].Lab1 + arr_sv[i].Lab2 + arr_sv[i].ProgressTest1 + arr_sv[i].ProgressTest2 + arr_sv[i].Presentation+arr_sv[i].FinalTest)/6);
				}
				else if (chon1==2) {
					nhapds(arr_sv,slsv);
					trungbinh(arr_sv,slsv,d);
				}
				else if (chon1==3) break;
				else printf("Lua chon khong thuc hien duoc do lenh khong hop le! \n");
				ghidiem(arr_sv,slsv);
			break;
			case 2: 
				Docmsv(slsv);
				printf("1_Xem diem mot sinh vien\n");
				printf("2_Xem diem toan bo danh sach\n");
				printf("3_Thoat\n");
				printf("Nhap lua chon : "); scanf("%d",&chon2);
				if (chon2==1) show(arr_sv,slsv);
				else if (chon2==2) insinhvien(arr_sv,slsv);
				else if (chon2==3) break;
				else printf("Lua chon khong thuc hien duoc do lenh khong hop le! \n");
			break;
			case 3: // Doi diem 
			Docmsv(slsv); 
//			printf("Thay doi lan %d\n",++dem); 
			char ly[10]; printf("Nhap MSV can sua : "); scanf("%s",ly); // ly : msv nhap tu ban phim
			for(int i=0; i<slsv; i++){
				int kq = strcmp(ly,MSV[i]);
				if(kq ==0){
					printf("Da tim thay!\n");
					tan = 1;
					break;
				}
			}
			if (tan==0) printf("Khong tim thay!\n");
			else{
			printf("Nhap phan can sua diem");
			printf("\n1_Diem Lab1");
			printf("\n2_Diem Lab2");
			printf("\n3_Diem ProgressTest1");
			printf("\n4_Diem ProgressTest2");
			printf("\n5_Diem Presentation ");
			printf("\n6_Diem Final Test ");
			printf("\n7_Diem Tat ca\n ");
			int tam;
			int choose; printf("Nhap phan can sua: "); scanf("%d",&choose);
			if (choose == 7){
				for(int i=0; i<slsv; i++){
				if (ly == MSV[i]) 
				{
					Doidiem(arr_sv,i);
					tam = i;
					cp=1;
					break; 
				}	
			}
			if(cp==0)printf("Khong tim thay!");
			}else{
				Doidiem1(arr_sv,choose,tam);
			}
			printf("\n");
			ghidiem(arr_sv,slsv);
			}
				break;
			case 4: // in danh sach theo diem trung binh
				Docmsv(slsv);
				trungbinh(arr_sv,slsv,d);
				sapxep(d,slsv);
				break;
			case 5: // ghi diem trung binh vao file
				Docmsv(slsv);
				trungbinh(arr_sv,slsv,d);
				ghitbinh(arr_sv,slsv,d);				
				printf("Da in diem trung binh vao file Diemtrungbinh.txt\n");
				ghidiem(arr_sv,slsv);
				printf("\nDiem thanh phan da ghi vao file output.txt\n");
				break;
			case 0:
				exit(1);	
		}
	}while(chon!=0);
}
