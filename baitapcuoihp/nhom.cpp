#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>

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
void readFileTXT();
int main()
{
    Banhang mh[40];
    int somh, n, chon = 0;
    do
    {
        menu();
        cout << "\nVui long chon 1 chuc nang: ";
        cin >> chon;
        switch (chon)
        {
        case 1:
        {
            cout << "\n1. Cao Phan Khai - 2274801030064";
            cout << "\n2. Nguyen Manh Tien - 2274801030149";
            cout << "\n3. Nguyen Ngo Hoang Nguyen - 2274801030102";
            cout << "\n4. Le Minh Tam - 207ot41160";
            break;
        }
        case 2:
        {
            nhapMangbanhang(mh, somh);
            break;
        }
        case 3:
        {
            readFileTXT();
            break;
        }
        case 4:
        {
            cout << "\nThong tin don hang duoc nhap la: ";
            xuatMangbanhang(mh, somh);
            break;
        }
        case 5:
        {
            cout << "\nTong gia tri cac mat hang la: ";
            cout << tongtrigiamathang(mh, somh) << endl;
            break;
        }
        case 6:
        {
            cout << mathangcodongiacaonhat(mh, somh);
            break;
        }
        case 7:
        {
            nhapmangsapxepgiamdan(mh, somh);
            cout << "\nDanh sach cac mat hang theo thu tu giam dan theo don gia la: ";
            xuatmangsapxepgiamdan(mh, somh);
            break;
        }
        case 8:
        {
            mathangcosoluongthapnhat(mh, somh);
            break;
        }
        case 9:
        {
            cout << tongsoluongmathang(mh, somh) << endl;
            break;
        }
        case 10:
        {
            if (checktangdantheodongia(mh, somh) == true)
            {
                cout << "\nDanh sach mat hang duoc tang dan theo don gia";
            }
            else
            {
                cout << "\nDanh sach mat hang khong duoc tang dan theo don gia";
            }
            break;
        }
        case 11:
        {
            timkiemmathang(mh, somh);
            break;
        }
        case 12:
        {
            cout << "\nDanh sach cac mat hang co don gia tu 50k->150k:";
            danhsachtren50000den150000(mh, somh);
            break;
        }
        default:
            break;
        }

    } while (chon != 0);
    return (0);
}

void menu()
{
    cout << "\n--------------Nhom Anh Em Van Phong----------------";
    cout << "\n1. Thong tin thanh vien nhom";
    cout << "\n2. Nhap danh sach cac mat hang";
    cout << "\n3. Nhap danh sach mat hang tu file txt(chua biet)"; // chua lam duoc
    cout << "\n4. Xuat danh sach cac mat hang";
    cout << "\n5. Tinh tong tri gia cac mat hang co trong danh sach (Tien)";
    cout << "\n6. In ra danh sach cac mat hang co don gia cao nhat (Khai)";
    cout << "\n7. Sap xep danh sach mat hang giam dan theo don gia (Nguyen)";
    cout << "\n8. in ra danh sach cac mat hang co so luong thap nhat (Khai)";
    cout << "\n9. Tinh tong so luong cac mat hang co trong danh sach (Tien)";
    cout << "\n10. Danh sach mat hang co duoc sap xep tang dan theo don gia hay khong (Nguyen)";
    cout << "\n11. Tim kiem mat hang khi biet ma hang (Tam)";
    cout << "\n12. Danh sach cac mat hang co don gia tren tu 50k->150k (Tam)";
    cout << "\n---------------------------------------------------";
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
         << x.mahang << "\t " << x.tenhang << "\t\t" << x.donvitinh << "\t\t" << x.soluong << "\t" << x.dongia;
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
            cout << "\n"
                 << a[i].tenhang << "\t\t  " << a[i].dongia << endl;
        }
}
void nhapmangsapxepgiamdan(Banhang a[], int n)
{
    int trunggian;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i].dongia < a[j].dongia)
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
    for (i = 0; i < n; i++)
    {
        cout << "\n"
             << a[i].tenhang << "\t\t" << a[i].dongia << endl;
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
            cout << "\n"
                 << a[i].tenhang << "\t\t" << a[i].soluong << endl;
        }
}
unsigned long tongsoluongmathang(Banhang a[], int n)
{
    unsigned long sum = a[0].soluong;
    cout << "\nTong so luong mat hang ";
    for (int i = 1; i < n; i++)
        sum += a[i].soluong;
    return sum;
}
void timkiemmathang(Banhang a[], int n)
{
    string tk;
    cout << "\nVui long nhap ma don hang can tim: ";
    cin >> tk;
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (tk == a[i].mahang)
        {
            cout << "\nTen mat hang la: " << a[i].tenhang;
        }
    }
}
bool checktangdantheodongia(Banhang a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        if (a[i].dongia > a[i + 1].dongia)
            return false;
    return true;
}
void danhsachtren50000den150000(Banhang a[], int n)
{
    cout << "\nTen hang \t Don gia";
    for (int i = 0; i < n; i++)
        if (50000 <= a[i].dongia && a[i].dongia <= 150000)
            cout << "\n"
                 << a[i].tenhang << "\t\t" << a[i].dongia;
}
void readFileTXT()
{
    // tạo string để output file
    vector<string> myTexts;
    string myText;
    ifstream ifs("Exam.txt");
    while (getline(ifs, myText))
        myTexts.push_back(myText);
    // Xuất từng dòng từ lines và in ra màn hình
    for (const auto &i : myTexts)
        cout << i << endl;
    ifs.close();
}