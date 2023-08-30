#include <stdio.h>
#include <stdlib.h>

FILE *f;

struct hoa_don{
    char ten[50];
    int so_luong;
    int so_luong_moi_mon;
    float so_tien_truoc;
    float so_tien_sau;
} p[100000];

int ma_hoa_don, ma_hoa_don_ban_dau;

int nhan_vien(){

    f = fopen("testthoi.txt","w");
    if(f==NULL){
        printf("\n loi tao hoac mo file");
        exit(1);
    }

    system("cls");
    printf("nhap ma giao dich: ");
    scanf("%d",&ma_hoa_don_ban_dau);
    while(ma_hoa_don_ban_dau <= ma_hoa_don){
        fprintf(f,"\nma hoa don : %d\n",ma_hoa_don_ban_dau);
        fprintf(f,"ten khach hang : %s\n",p[ma_hoa_don_ban_dau].ten);
        fprintf(f,"ten mon an%20s \n","so luong");
        for(int k=11;k <=20 ; k++){
            if(p[k].so_luong_moi_mon != 0){
                fprintf(f,"%d%25d\n",k,p[k].so_luong_moi_mon);
            }
        }
        fprintf(f,"tong so mon an cua ban la: %d\n",p[ma_hoa_don_ban_dau].so_luong);
        fprintf(f,"cam on va chuc '%s' ngon mieng.\n",p[ma_hoa_don_ban_dau].ten);
        fprintf(f,"tong so tien cua ban la: ");
        fprintf(f,"%.f\n",p[ma_hoa_don_ban_dau].so_tien_sau);
        ma_hoa_don_ban_dau++;
    };
    fclose(f);
    printf("bill cua ban da duoc in ra file ...");
}

void menu ()
{
    printf("...............................MENU...............................\n\n");
    printf("MA MON AN           TEN MON AN                           GIA (VND)\n");
    printf("[11]----------------Lau Hai San-------------------------300000 VND\n");
    printf("[12]----------------Lau Hai San Dac Biet----------------400000 VND\n");
    printf("[13]----------------Tom Hum-----------------------------700000 VND\n");
    printf("[14]----------------Cua Hoang De------------------------900000 VND\n");
    printf("[15]----------------Muc Hap-----------------------------250000 VND\n");
    printf("[16]----------------Goi Ca------------------------------250000 VND\n");
    printf("[17]----------------Bia---------------------------------300000 VND\n");
    printf("[18]----------------Cocacola-----------------------------20000 VND\n");
    printf("[19]----------------Nuoc ep------------------------------20000 VND\n");
    printf("[20]----------------Nuoc Loc-----------------------------10000 VND\n\n");

}
int in_hoa_don(){
    printf("\nso luong mon an ban yeu cau la: %d",p[ma_hoa_don].so_luong);
    if (p[ma_hoa_don].so_tien_truoc <= 2000000){
        p[ma_hoa_don].so_tien_sau = p[ma_hoa_don].so_tien_truoc;
        printf("\ntong so tien ban phai thanh toan la: %.f",p[ma_hoa_don].so_tien_sau);
    }
    else {
        printf("\ntong so tien ban phai thanh toan truoc khi khi ap dung khuyen mai la: %.f",p[ma_hoa_don].so_tien_truoc);
        p[ma_hoa_don].so_tien_sau = p[ma_hoa_don].so_tien_truoc - (p[ma_hoa_don].so_tien_truoc * 0.25);
        printf("\ntong so tien ban phai thanh toan sau khi khi ap dung khuyen mai 25 phan tram la: %.f",p[ma_hoa_don].so_tien_sau);
    }
}
int chon_mon(){
    int in, n=5, SL[50];

    for(int k=11; k<=20; k++){
        p[k].so_luong_moi_mon=0;
    }

    printf("vui long nhap ten cua ban:");
    getchar();
    gets(p[ma_hoa_don].ten);

    while(n--){
        printf("hay chon ma mon an:");
        scanf("%d",&in);

        switch (in){
            case(11) : {
                printf("moi ban nhap so luong:");
                scanf("%d",&SL[in]);
                p[ma_hoa_don].so_luong += SL[in];
                p[ma_hoa_don].so_tien_truoc += (SL[in]*300000);
                p[ma_hoa_don].so_luong_moi_mon=SL[in];
                printf("ban da chon mon 'Lau Hai San' voi so luong la: %d\n",SL[in]);
                break;
            }
            case(12) : {
                printf("moi ban nhap so luong:");
                scanf("%d",&SL[in]);
                p[ma_hoa_don].so_luong += SL[in];
                p[ma_hoa_don].so_tien_truoc += (SL[in]*400000);
                p[ma_hoa_don].so_luong_moi_mon=SL[in];
                printf("ban da chon mon 'Lau Hai San Dac Biet' voi so luong la: %d\n",SL[in]);
                break;
            }
            case(13) : {
                printf("moi ban nhap so luong:");
                scanf("%d",&SL[in]);
                p[ma_hoa_don].so_luong += SL[in];
                p[ma_hoa_don].so_tien_truoc += (SL[in]*700000);
                p[in].so_luong_moi_mon=SL[in];
                printf("ban da chon mon 'Tom Hum' voi so luong la: %d\n",SL[in]);
                break;
            }
            case(14) : {
                printf("moi ban nhap so luong:");
                scanf("%d",&SL[in]);
                p[ma_hoa_don].so_luong += SL[in];
                p[ma_hoa_don].so_tien_truoc += (SL[in]*900000);
                p[in].so_luong_moi_mon=SL[in];
                printf("ban da chon mon 'Cua Hoang De' voi so luong la: %d\n",SL[in]);
                break;
            }
            case(15) : {
                printf("moi ban nhap so luong:");
                scanf("%d",&SL[in]);
                p[ma_hoa_don].so_luong += SL[in];
                p[ma_hoa_don].so_tien_truoc += (SL[in]*250000);
                p[in].so_luong_moi_mon=SL[in];
                printf("ban da chon mon 'Muc Hap' voi so luong la: %d\n",SL[in]);
                break;
            }
            case(16) : {
                printf("moi ban nhap so luong:");
                scanf("%d",&SL[in]);
                p[ma_hoa_don].so_luong += SL[in];
                p[ma_hoa_don].so_tien_truoc += (SL[in]*200000);
                p[in].so_luong_moi_mon=SL[in];
                printf("ban da chon mon 'Goi Ca' voi so luong la: %d\n",SL[in]);
                break;
            }
            case(17) : {
                printf("moi ban nhap so luong:");
                scanf("%d",&SL[in]);
                p[ma_hoa_don].so_luong += SL[in];
                p[ma_hoa_don].so_tien_truoc += (SL[in]*300000);
                p[in].so_luong_moi_mon=SL[in];
                printf("ban da chon mon 'Bia' voi so luong la: %d\n",SL[in]);
                break;
            }
            case(18) : {
                printf("moi ban nhap so luong:");
                scanf("%d",&SL[in]);
                p[ma_hoa_don].so_luong += SL[in];
                p[ma_hoa_don].so_tien_truoc += (SL[in]*20000);
                p[in].so_luong_moi_mon=SL[in];
                printf("ban da chon mon 'Cocacola' voi so luong la: %d\n",SL[in]);
                break;
            }
            case(19) : {
            printf("moi ban nhap so luong:");
                scanf("%d",&SL[in]);
                p[ma_hoa_don].so_luong += SL[in];
                p[ma_hoa_don].so_tien_truoc += (SL[in]*20000);
                p[in].so_luong_moi_mon=SL[in];
                printf("ban da chon mon 'Nuoc ep' voi so luong la: %d\n",SL[in]);
                break;
            }
            case(20) : {
                printf("moi ban nhap so luong:");
                scanf("%d",&SL[in]);
                p[ma_hoa_don].so_luong += SL[in];
                p[ma_hoa_don].so_tien_truoc += (SL[in]*10000);
                p[in].so_luong_moi_mon=SL[in];
                printf("ban da chon mon 'Nuoc Loc' voi so luong la: %d\n",SL[in]);
                break;
            }
            case(00) : {
                n=0;
                goto in_hd;
            }
            default : {
                printf("lua chon khong dung moi ban nhap lai\n");
                n++;
            }
        }
    }
    in_hd:
    in_hoa_don();
}


int main(){
    printf("nhap ma giao dich: ");
    scanf("%d",&ma_hoa_don);
    ma_hoa_don_ban_dau=ma_hoa_don;
    
    printf("chao mung den voi 'BEACH RESTAURANT'\n");
    while (1){
        printf("\n----------------------------\n");
        printf("chon chuc nang\n");
        printf("1. chon mon \n2. lua chon cua nhan vien \n");
        printf("----------------------------\n");
        
        int in;
        scanf("%d",&in);
        
        switch (in){
            case (1) : {
                printf("\nma hoa don la: %d\n ",ma_hoa_don);
                menu();
                chon_mon();
                ma_hoa_don++;
                break;
            }
            case (2) : {
                nhan_vien();
                break;
            }
            default : {
                printf("lua chon khong hop le moi ban nhap lai");
            }
        }
    }
    return 0;
}