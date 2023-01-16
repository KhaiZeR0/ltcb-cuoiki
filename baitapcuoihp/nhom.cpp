#include <iostream>
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
void nhapbanhang(Banhang &x);
void xuatbanhang(Banhang x);
void nhapMangbanhang(Banhang a[], int &n);
void xuatMangbanhang(Banhang a[], int n);
unsigned long tongtrigiamathang(Banhang a[], int n);
unsigned long mathangcodongiacaonhat(Banhang a[], int n);
void nhapmangsapxepgiamdan(Banhang a[], int n);
void xuatmangsapxepgiamdan(Banhang a[], int n);
unsigned long mathangcosoluongthapnhat(Banhang a[], int n);
unsigned long tongsoluongmathang(Banhang a[], int n);

int main()
{  
    Banhang mh[40];
    int somh;
    nhapMangbanhang(mh, somh);
    cout << "\nThong tin don hang duoc nhap la: ";
    xuatMangbanhang(mh, somh);
    cout << "\nTong gia tri cac mat hang la: ";
    cout << tongtrigiamathang(mh, somh) << endl;
    mathangcodongiacaonhat(mh, somh);
    nhapmangsapxepgiamdan(mh, somh);
    cout<<"\nDanh sach cac mat hang theo thu tu giam dan theo don gia la: ";
    xuatmangsapxepgiamdan(mh, somh);
    mathangcosoluongthapnhat(mh,somh);
    cout << tongsoluongmathang(mh, somh) << endl;
    return (0);
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
unsigned long tongtrigiamathang(Banhang a[], int n)
{
    unsigned long sum = a[0].dongia * a[0].soluong;
    for (int i = 1; i < n; i++)
        sum += a[i].dongia * a[i].soluong;
    return sum;
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
// sapxep
void nhapmangsapxepgiamdan(Banhang a[], int n)
{
    int trunggian;
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(a[i].dongia < a[j].dongia)
            {
                trunggian = a[i].dongia;
                a[i].dongia = a[j].dongia;
                a[j].dongia = trunggian;
            }
}
void xuatmangsapxepgiamdan(Banhang a[], int n)
{
    int i;
    cout << "\nTen Hang \t Don Gia";
    for (i=0; i < n; i++)
        {
            cout <<"\n"<< a[i].tenhang << "\t" << a[i].dongia << endl;
        }
}
unsigned long mathangcosoluongthapnhat(Banhang a[], int n)
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
unsigned long tongsoluongmathang(Banhang a[], int n)
{
    unsigned long sum = a[0].soluong;
    for (int i = 1; i < n; i++)
        sum += a[i].soluong;
    return sum;
}