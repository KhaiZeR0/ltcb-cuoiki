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
                cout<<"\nMang nhap vao la: ";
                break;
            }
        case 2:
            {
                cout<<"\n";
                xuatMang(arr,n);
                break;
            }
        case 3:
            {
                int sample[] = {-8, 8, 5, 10, -5, 0, 1, 2};
                int sum = 0;
                sum = tinhtongduongleboi5(sample, sizeof(sample) / sizeof(int));
                cout << "the sum of Positive numbers which are multiple of 5 is: " << sum;
                return 0;
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
    cout<<"\n--------------NGUOI THUC HIEN: CAO PHAN KHAI - 2274801030064 ----------------";
    cout<<"\n1. Nhap mang";
    cout<<"\n2. Xuat Mang";
    cout<<"\n3. Tong cac so duong le la boi so cua 5 co trong mang";
    cout<<"\n4. Trung binh cong cac so duong co trong mang";
    cout<<"\n5. Tinh tong cac so nguyen to co trong mang";
    cout<<"\n6. Cho biet trong mang co bao nhieu so hoan thien";
    cout<<"\n7. ";
    cout<<"\n-----------------------------------------------------------------------------";
}

void nhapMang(int a[KTM], int &spt)
{
    //nhap so luong phan tu mang
    do{
        cout<<"\nNhap so luong phan tu cua mang: ";
        cin>>spt;
    }while(spt<=0 || spt>KTM);
    //nhap gia tri cho cac phan tu mang
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

bool isNegative(int number)
{
    bool ret = false;

    if (number < 0)
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
        if (isNegative(arr[i]) == false)
        {
            if ((arr[i] % 5) == 0)
            {
                sum += arr[i];
            }
        }
    }
    return sum;
}
