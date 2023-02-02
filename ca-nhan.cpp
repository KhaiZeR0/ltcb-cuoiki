// Bài tập đồ án cá nhân
//Họ và tên: Cao Phan Khải
//MSSV: 2274801030064
//lớp: 71K28KTPM01
//Lớp học phần: 71SEBA10012_01
//các câu thục hiện: 2,5,8,11,14,17,20,23,26

#include <iostream>
using namespace std;
#define KTM 100

//khai bao ham con
void menu();
void nhapMang(int a[KTM], int &spt);
void xuatMang(int a[], int spt);
int tongduongleboi5(int arr[], int spt);
int tinhTBCongDuong(int arr[], int spt);
int KiemTra(int spt);
int TongNguyenTo(int arr[], int spt);
bool kiemtrasohoanthien(int n);
void sohoanthien(int arr[], int spt);
void lietketoanchan(int arr[], int spt);
int kiemtrachanhaykhong(int arr[], int spt);
int kiemTraMangSapXep(int a[], int spt);
int kiemTraSoHoanThien2 (int n);
int kiemTraToanSoHoanThien(int arr[], int spt);
void xoaPhanTu(int a[], int &spt, int x);

int main() {
    int chon=0;
    int arr[KTM], n;
    do
    {
        menu();
        cout<<"\nVui long chon 1 chuc nang: ";
        cin>>chon;
        switch (chon)
        {
        case 1:
            {
                nhapMang(arr,n);
                break;
            }
        case 2:
            {
                cout<<"\nMang nhap vao la: ";
                xuatMang(arr,n);
                cout<<"\n";
                break;
            }
        case 3:
            {
                cout<<"Tong cac so duong le co boi so cua 5 la: "<<tongduongleboi5(arr,n);
                break;
            }
        case 4:
            {
                cout<<"\nTong trung binh cong cac so duong la: "<<tinhTBCongDuong(arr,n);
                break;
            }
        case 5:
        {
                cout<<"\nTong cac nguyen to co trong mang la: "<<TongNguyenTo( arr,n);
                break;
        }
        case 6:
            {
                sohoanthien(arr,n);
                break;
            }
        case 7:
            {
                cout<<"\nPhan tu la so nguyen co cac chu so toan chan la: ";
                lietketoanchan(arr,n);
                break;
            }
        case 8:
            {
                if(kiemtrachanhaykhong(arr,n)==-1)
                {
		            cout<<("\nMang khong co bao gom tat ca cac phan tu la so chan");
                }
	            else
                {
                    cout<<("\nMang co bao gom tat ca cac phan tu la so chan");
                }
                break;
            }
        case 9:
            {
                if(kiemTraToanSoHoanThien(arr,n)==true)
                {
                    cout<<"Mang gom tat ca cac so hoan thien ";
                }
                else
                {
                    cout<<"Mang khong gom tat ca cac so hoan thien ";
                }
                break;
            }
        case 10:
            {
                if(kiemTraMangSapXep(arr,n)==true)
                {
                    cout<<"Mang duoc sap xep giam dan";
                }
                else
                {
                    cout<<"Mang khong duoc sap xep giam dan ";
                }
                break;
            }
        case 11:
            {
                int s;
                xoaPhanTu(arr,n,s);
                cout<<"\nPhan tu con lai:";
                xuatMang(arr,n);
                break;
            }
        default:
            break;   
        }
    } while (chon!=0);
    return 0;
    

    
}

void menu()
{
    cout<<"\n------------------------NGUOI THUC HIEN: CAO PHAN KHAI - 2274801030064 --------------------------";
    cout<<"\n1. Nhap mang";//done
    cout<<"\n2. Xuat Mang";//done
    cout<<"\n3. Tong cac so duong le la boi so cua 5 co trong mang";//done bai 2
    cout<<"\n4. Trung binh cong cac so duong co trong mang";//done bai 5
    cout<<"\n5. Tinh tong cac so nguyen to co trong mang";//xong nhung deo hieu bai 8
    cout<<"\n6. Cho biet trong mang co bao nhieu so hoan thien";//bai 11
    cout<<"\n7. Cho biet trong mang co mang nao co phan tu nao la so nguyen co cac chu so toan chan hay khong";// done bai 14 
    cout<<"\n8. Cho biet trong mang co bao gom tat ca cac phan tu la so chan khong";//done bai 17
    cout<<"\n9. Cho biet trong mang co bao gom cac so phan tu la so hoan thien";//done bai 20
    cout<<"\n10. Cho biet phan tu trong mang co duoc sap xep giam dan hay khong";//bai 23
    cout<<"\n11. Xoa mot phan tu khoi mang";//done bai 26
    cout<<"\n0. Thoat chuong trinh";
    cout<<"\n-------------------------------------------------------------------------------------------------";
}

void nhapMang(int a[KTM], int &spt)
{
    do{
        cout<<"\nNhap so luong phan tu cua mang: ";
        cin>>spt;
    }while(spt<=0 || spt>KTM);
    cout<<"\nNhap gia tri cho cac phan tu mang: ";
    for(int k=0;k<spt;k++)
    {
        cout<<"\nNhap gia tri cho phan tu thu "<<k+1<<" : ";
        cin>>a[k];
    }
}
void xuatMang(int a[], int spt)
{
    for(int k=0;k<spt;k++)
        cout<<a[k]<<"  ";
}

bool kiemtrasoam(int n)
{
    bool ret = false;

    if (n < 0)
    {
        ret = true;
    }

    return ret;
}

int tongduongleboi5(int arr[], int n){
    
	int tong=0;
	for(int i=0; i<n; i++)
		if( arr[i]%5==0 && arr[i]>0 && arr[i]%2!=0)
			tong += arr[i];
		return tong;
}

int tinhTBCongDuong(int arr[], int spt)
{
    int sum=0, dem=0; 
    for(int i=0;i<spt;i++){
        if(arr[i] > 0) {
            sum+=arr[i]; dem++;
        }
    }
    if(dem==0) return 0;
    return sum/dem;
}
int KiemTra(int spt)
{
    for(int i=2; i<spt; i++)
        {
            if(spt%i==0)
                return 0;
        }
    return 1;
}

int TongNguyenTo(int arr[], int spt)
{
    int sum=0;
    for(int i=0; i<spt;i++)
        if(KiemTra(arr[i])==1)
            sum+=arr[i];
    return sum;
}

bool kiemtrasohoanthien(int n)
{
    int a =0;
    for(int i=1; i<n; i++){
        if(n% i == 0)
            a = a + i;
    }
    
    if(a != 0 && a == n)
        return true;
    else
        return false;
}

void sohoanthien(int arr[], int spt)
{
    cout<<"mang co so hoan thien la: ";
    for(int i =0; i<spt; i++){
        if(kiemtrasohoanthien(arr[i]))
            cout<<arr[i]<<" ";
    }
}

void lietketoanchan(int arr[], int spt)
{
    for(int i = 0; i < spt; i++)
    {
        if(arr[i] % 2 == 0)
        {
            cout<<"\n"<<arr[i];
        }
    }
}
int kiemtrachanhaykhong(int arr[], int spt)
{
	for( int i=0;i<spt;i++)
		if(arr[i]%2!=0)
		{
			return -1;
			break;
		}
	return 1;
}

int kiemTraMangSapXep(int a[], int spt)
{
     for(int i = 0; i < spt-1; i++){
        if(a[i] < a[i+1]) return false;
    }
    return true;
}

int kiemTraSoHoanThien2 (int n)
{
  int tong = 0;
  for(int i=1;i<n/2;i++){
    if(n%i==0){
        tong+=i;
    }  
  }
  if(tong==n)
      return 1;
  return 0;
}
int kiemTraToanSoHoanThien(int a[], int m)
{
  for(int i=0;i<m;i++){
        if(kiemTraSoHoanThien2(a[i])==0)
        return false;
        return true;
        
    }
    
}
void xoaPhanTu(int a[], int &spt, int x)
{
  if(spt <= 0){
        return;
    }
    if(x < 0){
        x = 0;
    }
    else if(x >= spt){
        x = spt-1;
    }
    for(int i = x; i < spt - 1; i++){
        a[i] = a[i+1];
    }
    --spt;
}
