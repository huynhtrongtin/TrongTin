#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
 
 
struct SinhVien{
    char hovaten[30];
    char mssv[20];
    char mmh[10];
    float dmh;

};
 
typedef SinhVien SV;
 
void nhap(SV &sv);
void nhapN(SV a[], int n);
void xuat(SV sv);
void xuatN(SV a[], int n);
void sapxeptang(SV a[], int n);
void sapxepgiam(SV a[], int n);
void timmax(SV a[], int n);
void timmin(SV a[], int n);

 
int main(){
    int key;
    int n;
    bool daNhap = false;
    do{
        printf("\nNhap so luong SV: "); scanf("%d", &n);
    }while(n <= 0);
    SV a[n];
    while(true){
        system("cls");
        printf("****************************************************\n");
        printf("**              QUAN LY SINH VIEN                 **\n");
        printf("**      1. Nhap du lieu                           **\n");
        printf("**      2. In danh sach sinh vien                 **\n");
        printf("**      3. Sap xep sinh vien theo diem tang dan   **\n");
        printf("**      4. Sap xep sinh vien theo diem giam dan   **\n");
        printf("**      5. Tim sinh vien co diem cao nhat         **\n");
        printf("**      6. Tim sinh vien co diem thap nhat        **\n");
        printf("**      0. Thoat                                  **\n");
        printf("****************************************************\n");
        printf("**       Nhap lua chon cua ban                    **\n");
        scanf("%d",&key);
        switch(key){
            case 1:
                printf("\nBan da chon nhap DS sinh vien!");
                nhapN(a, n);
                printf("\nBan da nhap thanh cong!");
                daNhap = true;
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 2:
                if(daNhap){
                    printf("\nBan da chon xuat DS sinh vien!");
                    xuatN(a, n);
                }else{
                    printf("\nNhap DS SV truoc!!!!");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 3:
                if(daNhap){
                    printf("\nBan da chon sap xep diem SV theo tang dan");
                    sapxeptang(a, n);
                    xuatN(a, n);
                }else{
                    printf("\nNhap DS SV truoc!!!!");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 4:
                if(daNhap){
                    printf("\nBan da chon sap xep diem SV theo giam dan");
                    sapxepgiam(a,n);
                    xuatN(a, n);
                }else{
                    printf("\nNhap DS SV truoc!!!!");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 5:
            	if(daNhap){
                    printf("\nBan da chon tim SV co diem cao nhat");
                    timmax(a,n);
                }else{
                    printf("\nNhap DS SV truoc!!!!");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 6:
            	if(daNhap){
                    printf("\nBan da chon tim SV co diem thap nhat");
                    timmin(a,n);
                }else{
                    printf("\nNhap DS SV truoc!!!!");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 0:
                printf("\nBan da chon thoat chuong trinh!");
                getch();
                return 0;
            default:
                printf("\nKhong co chuc nang nay!");
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
        }
    }
}
 
 
void nhap(SV &sv){
	//Nhap thong tin sinh vien
    printf("\nNhap ho va ten: "); fflush(stdin); gets(sv.hovaten);
    printf("\nNhap ma sinh vien: "); gets(sv.mssv);
    printf("\nNhap ma mon hoc: "); gets(sv.mmh);
    printf("\nNhap diem mon hoc: "); scanf("%f",&sv.dmh);
    
}
 
void nhapN(SV a[], int n){
    printf("\n____________________________________\n");
    for(int i = 0; i< n; ++i){
        printf("\nNhap SV thu %d:", i+1);
        nhap(a[i]);
    }
    printf("\n____________________________________\n");
}
 
void xuat(SV sv){
	//Xuat thong tin sinh vien
    printf("\nHo va ten SV: %s", sv.hovaten);
    printf("\nMa sinh vien: %s", sv.mssv);
    printf("\nMa mon hoc  : %s", sv.mmh);
    printf("\nDiem mon hoc: %.2f", sv.dmh);

}
 
void xuatN(SV a[], int n){
    printf("\n____________________________________\n");
    for(int i = 0;i < n;++i){
        printf("\nThong tin SV thu %d:", i+1);
        xuat(a[i]);
    }
    printf("\n____________________________________\n");
}
void timmax(SV a[], int n) {
	//Tim dien sinh vien cao nhat & in thong tin sinh vien ra man hinh
	printf("\n____________________________________\n");
    SV max = a[0];
    for(int i = 0; i < n; i++){
        if(max.dmh < a[i].dmh)
        {
            max = a[i];    
        }           
    }
    xuat(max); 
    printf("\n____________________________________\n");
}
void timmin(SV a[], int n) {
	//Tim diem sinh vien nho nhat & in thong tin sinh vien ra man hinh
	printf("\n____________________________________\n");
    SV min = a[0];
    for(int i = 0; i < n; i++){
        if(min.dmh > a[i].dmh)
        {
            min = a[i];    
        }           
    }
    xuat(min); 
    printf("\n____________________________________\n");
}
void sapxeptang(SV a[], int n){
    //Sap xep theo diem tang dan
    SV tmp;
    for(int i = 0;i < n;++i){
        for(int j = i+1; j < n;++j){
            if(a[i].dmh > a[j].dmh){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}


void sapxepgiam(SV a[], int n){
    //Sap xep theo diem giam dan
    SV tmp;
    for(int i = 0;i < n;++i){
        for(int j = i+1; j < n;++j){
            if(a[i].dmh < a[j].dmh){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

 

 
