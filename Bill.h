#ifndef Bill_h
#define Bill_h
#include <bits/stdc++.h>
#include "Staff.h"
#include "Member.h"
#include "Product.h"
#include "MyProduct.h"
#include "Day.h"
#include "Discount.h"

using namespace std;

class Node_Bill{
private:
    string MaHD;
    string MaTV;
    Day ngaynhap;
    string MaNV;
    int diem;
    float mucChietKhau;
    Node_Bill *next;
public:
    Node_Bill(string MaHD,string MaTV,Day D,string MaNV,int diem,float mucChietKhau,Node_Bill *next):
MaHD(MaHD),MaTV(MaTV),ngaynhap(D),MaNV(MaNV),diem(diem),mucChietKhau(mucChietKhau),next(next){};
    friend class Bill;
};

class Bill{
private:
    Node_Bill *head;
public:
    Bill();
    Bill(const Bill &B);
    ~Bill();
    bool CheckMaHD(string s) const;
    Bill InsertNodeAfter(string MaHD,string MaTV,Day D,string MaNV,int diem,float mucChietKhau);
    Bill DocFile(string tenFile);
    void GhiFile(string tenFile) const;
    void printfBill(const Product &p,const MyProduct &MyP) const;
    Bill CreateBill(string MaNV,Product &P,MyProduct &MyP,Member &M,const Discount &Ds);
};


#endif // Bill_h
