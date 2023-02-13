#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;

struct Banhang
{
    /* data */
    char mahang[100];
    char tenhang[255];
    char donvitinh[10];
    int soluong;
    double dongia;
};

// khai bao ham con
void menu();
void nhapbanhang(Banhang &x);
void nhapbanhangtxt(Banhang &x);
void xuatbanhang(Banhang x);
void nhapMangbanhang(Banhang a[], int &n);
void xuatMangbanhang(Banhang a[], int n);
unsigned long tongtrigiamathang(Banhang a[], int n);
unsigned long mathangcodongiacaonhat(Banhang a[], int n);
void nhapmangsapxepgiamdan(Banhang a[], int n);
void xuatmangsapxepgiamdan(Banhang a[], int n);
void mathangcosoluongthapnhat(Banhang a[], int n);
unsigned long tongsoluongmathang(Banhang a[], int n);
void xuatmangsapxepgiamdan(Banhang a[], int n);
void nhapmangsapxeptangdan(Banhang a[], int n);
void timkiemmathang(Banhang a[], int n);
void danhsachtren50000den150000(Banhang a[], int n);
bool checktangdantheodongia(Banhang a[], int n);

int main()
{
    Banhang mh[40];
    int somh,n,chon=0;
    do
    {
        menu();
        cout<<"\nVui long chon 1 chuc nang: ";
        cin >> chon;
        switch (chon)
        {
        case 2:
            {
                nhapMangbanhang(mh, somh);
                break;
            }
        case 3:
            {
                
                break;
            }
        case 4:
            {
                cout << "\nThong tin don hang duoc nhap la: ";
                xuatMangbanhang(mh, somh);
                break;
            }   
        case 6:
            {
                cout<<mathangcodongiacaonhat(mh, somh);
                break;
            }
        case 8:
            {
                mathangcosoluongthapnhat(mh,somh);
                break;
            }
        default:
            break;
        }

    } while (chon!=0);
    return (0);
}

void menu()
{
    cout<<"\n6. In ra danh sach cac mat hang co don gia cao nhat (Khai)";
    cout<<"\n8. in ra danh sach cac mat hang co so luong thap nhat (Khai)";
}

void nhapbanhang(Banhang &x)
{
    cout << "\nNhap ma hang: ";
    rewind(stdin);
    cin.getline(x.mahang, 100);
    cout << "\nNhap ten mat hang: ";
    cin.getline(x.tenhang, 255);
    cout << "\nNhap don vi tinh: ";
    cin.getline(x.donvitinh, 10);
    cout << "\nNhap so luong: ";
    cin >> x.soluong;
    cout << "\nNhap don gia: ";
    cin >> x.dongia;
}



void xuatbanhang(Banhang x)
{
    cout << "\n"
         << x.mahang << "  " << x.tenhang << "  " << x.donvitinh << "  " << x.soluong << "  " << x.dongia;
}

void nhapMangbanhang(Banhang a[], int &n)
{
    do
    {
        cout << "\nNhap so mat hang: ";
        cin >> n;
    } while (n <= 0);
    for (int k = 0; k < n; k++)
    {
        cout << "\nNhap gia tri mat hang thu: " << k + 1 << " ";
        nhapbanhang(a[k]);
    }
}

void xuatMangbanhang(Banhang a[], int n)
{
    cout << "\nMa Hang  Ten mat hang  don vi tinh  so luong  don gia";
    for (int k = 0; k < n; k++)
    {
        xuatbanhang(a[k]);
    }
}
unsigned long mathangcodongiacaonhat(Banhang a[], int n)
{
    unsigned long max = a[0].dongia;
    for (int i = 1; i < n; i++)
        if (a[i].dongia > max)
            max = a[i].dongia;
    cout << "\nMat hang co don gia lon nhat:\n";
    for (int i = 0; i < n; i++)
        if (a[i].dongia == max)
        {
            cout << "\nTen Hang \t Don gia";
            cout <<"\n"<< a[i].tenhang << "\t" << a[i].dongia << endl;
        }
}

void mathangcosoluongthapnhat(Banhang a[], int n)
{
    unsigned long min = a[0].soluong;
    for (int i = 1; i < n; i++)
        if (a[i].soluong < min)
            min = a[i].soluong;
    cout << "\nMat hang co so luong nho nhat:\n";
    for (int i = 0; i < n; i++)
        if (a[i].soluong == min)
        {
            cout << "\nTen Hang \t So luong";
            cout <<"\n"<< a[i].tenhang << "\t" << a[i].soluong << endl;
        }
}
