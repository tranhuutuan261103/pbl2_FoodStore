#include <bits/stdc++.h>
#include "LinkedList.h"
#include "Product.h"
#include "Day.h"
#include "Person.h"
#include "Staff.h"
#include "Member.h"
#include "Detail.h"
#include "Discount.h"
#include "Bill.h"
#include "Category.h"
// Xem tat ca san pham theo loai
// Xem chi tiet hoa don
// Xem chi tiet lap hoa don cua 1 thanh vien
// Xem chi tiet hoa don do nhan vien 1 lap

using namespace std;

void GetData(LinkedList<Product> &P,LinkedList<Staff> &S,LinkedList<Member> &M,LinkedList<Bill> &B,LinkedList<Detail> &Dtl,LinkedList<Category> &C,Discount &D);
void Menu(LinkedList<Product> &P,LinkedList<Staff> &S,LinkedList<Member> &M,LinkedList<Bill> &B,LinkedList<Detail> &Dtl,LinkedList<Category> &C,Discount &D);
void PrintfList(LinkedList<Product> &P,LinkedList<Staff> &S,LinkedList<Member> &M,LinkedList<Bill> &B,LinkedList<Detail> &Dtl,LinkedList<Category> &C,Discount &D);
void CreateNode(LinkedList<Product> &P,LinkedList<Staff> &S,LinkedList<Member> &M,LinkedList<Bill> &B,LinkedList<Detail> &Dtl,LinkedList<Category> &C,Discount &D);
void EditNode(LinkedList<Product> &P,LinkedList<Staff> &S,LinkedList<Member> &M,LinkedList<Bill> &B,LinkedList<Detail> &Dtl,LinkedList<Category> &C,Discount &D);
void DeleteNode(LinkedList<Product> &P,LinkedList<Staff> &S,LinkedList<Member> &M,LinkedList<Bill> &B,LinkedList<Detail> &Dtl,LinkedList<Category> &C,Discount &D);
void SaveData(const LinkedList<Product> &P,const LinkedList<Staff> &S,const LinkedList<Member> &M,const LinkedList<Bill> &B,const LinkedList<Detail> &Dtl,const LinkedList<Category> &C,const Discount &D);

int main()
{
    LinkedList<Product> P;
    LinkedList<Staff> S;
    LinkedList<Member> M;
    LinkedList<Bill> B;
    LinkedList<Detail> Dtl;
    LinkedList<Category> C;
    Discount D;
    GetData(P,S,M,B,Dtl,C,D);
    Menu(P,S,M,B,Dtl,C,D);
    SaveData(P,S,M,B,Dtl,C,D);
    return 0;
}

void Menu(LinkedList<Product> &P,LinkedList<Staff> &S,LinkedList<Member> &M,LinkedList<Bill> &B,LinkedList<Detail> &Dtl,LinkedList<Category> &C,Discount &D)
{

    Bill b;
    int choose;
    do
    {
        system("cls");
        cout << "1.In ...\n";
        cout << "2.Them ....\n";
        cout << "3.Sua ...\n";
        cout << "4.Xoa ...\n";
        cout << "0.Thoat\n";
        cout << "Chon:";
        cin >> choose;
        cin.ignore();
        switch(choose)
        {
        case 0:
            cout << "\n\n";
            break;
        case 1:
            PrintfList(P,S,M,B,Dtl,C,D);
            break;
        case 2:
            CreateNode(P,S,M,B,Dtl,C,D);
            break;
        case 3:
            EditNode(P,S,M,B,Dtl,C,D);
            break;
        case 4:
            DeleteNode(P,S,M,B,Dtl,C,D);
            break;
        default:
            cout << "Nhap lai!\n";
            system("pause");
            break;
        }
    } while (choose);
}

void PrintfList(LinkedList<Product> &P,LinkedList<Staff> &S,LinkedList<Member> &M,LinkedList<Bill> &B,LinkedList<Detail> &Dtl,LinkedList<Category> &C,Discount &D)
{
    Bill b;
    int choose;
    do
    {
        system("cls");
        cout << "1.In danh sach cac san pham\n";
        cout << "2.In danh sach cac loai san pham\n";
        cout << "3.In danh sach cac hoa don\n";
        cout << "4.In danh sach cac nhan vien\n";
        cout << "5.In danh sach cac thanh vien\n";
        cout << "0.Thoat\n";
        cout << "Chon:";
        cin >> choose;
        cin.ignore();
        switch(choose)
        {
        case 0:
            break;
        case 1:
            system("cls");
            P.printfList();
            cout << "\n\n";
            system("pause");
            break;
        case 2:
            system("cls");
            C.printfList();
            cout << "\n\n";
            system("pause");
            break;
        case 3:
            system("cls");
            B.printfList();
            cout << "\n\n";
            system("pause");
            break;
        case 4:
            system("cls");
            S.printfList();
            cout << "\n\n";
            system("pause");
            break;
        case 5:
            system("cls");
            M.printfList();
            cout << "\n\n";
            system("pause");
            break;
        default:
            cout << "Nhap lai!";
            system("pause");
            break;
        }
    } while (choose);
}

void CreateNode(LinkedList<Product> &P,LinkedList<Staff> &S,LinkedList<Member> &M,LinkedList<Bill> &B,LinkedList<Detail> &Dtl,LinkedList<Category> &C,Discount &D)
{
    Bill b;
    int choose;
    do
    {
        system("cls");
        cout << "1.Them san pham\n";
        cout << "2.Them loai san pham\n";
        cout << "3.Them hoa don\n";
        cout << "4.Them nhan vien\n";
        cout << "5.Them thanh vien\n";
        cout << "0.Thoat\n";
        cout << "Chon:";
        cin >> choose;
        cin.ignore();
        switch(choose)
        {
        case 0:
            break;
        case 1:
            system("cls");
            P.printfList();
            cout << "\n\n";
            cin >> P;
            system("pause");
            break;
        case 2:
            system("cls");
            C.printfList();
            cout << "\n\n";
            cin >> C;
            system("pause");
            break;
        case 3:
            system("cls");
            B.printfList();
            cout << "\n\n";
            b.CreateBill("NV01",B,P,Dtl,M,D);
            system("pause");
            break;
        case 4:
            system("cls");
            S.printfList();
            cout << "\n\n";
            cin >> S;
            system("pause");
            break;
        case 5:
            system("cls");
            M.printfList();
            cout << "\n\n";
            cin >> M;
            system("pause");
            break;
        default:
            cout << "Nhap lai!";
            system("pause");
            break;
        }
    } while (choose);
}

void EditNode(LinkedList<Product> &P,LinkedList<Staff> &S,LinkedList<Member> &M,LinkedList<Bill> &B,LinkedList<Detail> &Dtl,LinkedList<Category> &C,Discount &D)
{
    float x,y;
    string s;
    Product p;
    int choose;
    do
    {
        system("cls");
        cout << "1.Cap nhat so luong san pham\n";
        cout << "2.Cap nhat don gia san pham\n";
        cout << "3.Cap nhat muc chiet khau\n";
        cout << "0.Thoat\n";
        cout << "Chon:";
        cin >> choose;
        cin.ignore();
        switch(choose)
        {
        case 0:
            break;
        case 1:
            system("cls");
            P.printfList();
            cout << "\n\n";
            do {
                cout << "Nhap ma san pham:";
                getline(cin,s);
            } while (P.CheckID(s)==false);
            p.EditAmount(s,P);
            system("pause");
            break;
        case 2:
            system("cls");
            P.printfList();
            cout << "\n\n";
            do {
                cout << "Nhap ma san pham:";
                getline(cin,s);
            } while (P.CheckID(s)==false);
            p.EditPrice(s,P);
            system("pause");
            break;
        case 3:
            system("cls");
            D.printfDiscount();
            cout << "\n\n";
            cout << "Nhap muc quy doi ve diem:";
            cin >> x;
            cout << "Nhap muc chiet khau moi diem:";
            cin >> y;
            D.SetDiscount(x,y);
            system("pause");
            break;
        default:
            cout << "Nhap lai!";
            system("pause");
            break;
        }
    } while (choose);
}


void GetData(LinkedList<Product> &P,LinkedList<Staff> &S,LinkedList<Member> &M,LinkedList<Bill> &B,LinkedList<Detail> &Dtl,LinkedList<Category> &C,Discount &D)
{
    P.ReadDataFromFile("Product.txt");
    S.ReadDataFromFile("Staff.txt");
    M.ReadDataFromFile("Member.txt");
    B.ReadDataFromFile("Bill.txt");
    Dtl.ReadDataFromFile("Detail.txt");
    C.ReadDataFromFile("Category.txt");
    D.ReadNode("Discount.txt");
}

void DeleteNode(LinkedList<Product> &P,LinkedList<Staff> &S,LinkedList<Member> &M,LinkedList<Bill> &B,LinkedList<Detail> &Dtl,LinkedList<Category> &C,Discount &D)
{
    Bill b;
    Product p;
    Category c;
    int choose;
    do
    {
        system("cls");
        cout << "1.Xoa 1 san pham\n";
        cout << "2.Xoa 1 loai san pham\n";
        cout << "3.Xoa 1 hoa don\n";\
        cout << "0.Thoat\n";
        cout << "Chon:";
        cin >> choose;
        cin.ignore();
        switch(choose)
        {
        case 0:
            break;
        case 1:
            system("cls");
            P.printfList();
            cout << "\n\n";
            p.DeleteProduct(P,Dtl);
            system("pause");
            break;
        case 2:
            system("cls");
            C.printfList();
            cout << "\n\n";
            c.DeleteCategory(C,P);
            system("pause");
            break;
        case 3:
            system("cls");
            B.printfList();
            cout << "\n\n";
            b.DeleteBill(B,Dtl);
            system("pause");
            break;
        default:
            cout << "Nhap lai!";
            system("pause");
            break;
        }
    } while (choose);
}


void SaveData(const LinkedList<Product> &P,const LinkedList<Staff> &S,const LinkedList<Member> &M,const LinkedList<Bill> &B,const LinkedList<Detail> &Dtl,const LinkedList<Category> &C,const Discount &D)
{
    P.SavaDataToFile("Product.txt");
    S.SavaDataToFile("Staff.txt");
    M.SavaDataToFile("Member.txt");
    B.SavaDataToFile("Bill.txt");
    Dtl.SavaDataToFile("Detail.txt");
    C.SavaDataToFile("Category.txt");
    D.SaveNode("Discount.txt");
}
