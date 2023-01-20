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


int main() {
    int chon,n;
    do
    {
        menu();
    } while (chon !=0);
    
    //khai bao
    int arr[KTM], n;
    nhapMang(arr,n);
    cout<<"\nMang nhap vao la: ";
    xuatMang(arr,n);
}

void menu()
{
    cout<<"--------------NGUOI THUC HIEN: CAO PHAN KHAI - 2274801030064 ----------------";
    cout<<"\n1. Tong cac so duong le la boi so cua 5 co trong mang";
    cout<<"\n2. Trung binh cong cac so duong co trong mang";
    cout<<"\n3. Tinh tong cac so nguyen to co trong mang";
    cout<<"\n4. Cho biet trong mang co bao nhieu so hoan thien";
    cout<<"\n5. ";
    cout<<"-----------------------------------------------------------------------------";
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
