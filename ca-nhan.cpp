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
int tinhtongduongleboi5(int arr[], int spt);
int tinhTBCongDuong(int arr[], int spt);
int KiemTra(int spt);
int TongNguyenTo(int arr[], int spt);
bool kiemtrasohoanthien(int n);
void sohoanthien(int arr[], int spt);
void lietketoanchan(int arr[], int spt);
int kiemtrachanhaykhong(int arr[], int spt);
bool KiemtraTangDan (int arr[],int spt);

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
                int sample[] = {-8, 8, 5, 10, -5, 0, 1, 2};
                int sum = 0;
                sum = tinhtongduongleboi5(sample, sizeof(sample) / sizeof(int));
                cout << "Tong cac so duong le la boi cua 5 co trong mang: " << sum;
                return 0;
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
                break;
            }
        case 10:
            {
                KiemtraTangDan(arr,n);
                break;
            }
        case 11: 
            {
                
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
    cout<<"\n9. ";//bai 20
    cout<<"\n10. ";//bai 23
    cout<<"\n11. ";//bai 26
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

int tinhtongduongleboi5(int arr[], int spt)
{
    int sum = 0;
    for (int i=0;i<spt;i++)
    {
        if (kiemtrasoam(arr[i]) == false)
        {
            if ((arr[i] % 5) == 0)
            {
                sum += arr[i];
            }
        }
    }
    return sum;
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
bool KiemtraTangDan (int arr[],int spt)
{
    for( int i=0;i<=spt;i++)
        for( int j=i+1;j<spt; j++)
            if(arr[i]<=arr[j])
            {
                cout<<"\nmang tang";
            }
            else
            {
                cout<<"\nmang khong tang";
            }
}
void xoaphantu(int a[KTM], int &spt, int vtx)
{
    for (int i = vtx; i <= spt-1; i++)
    {
        a[i] = a[i + 1];
    }
    spt--;

}