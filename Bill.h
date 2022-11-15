#ifndef Bill_h
#define Bill_h
#include <bits/stdc++.h>
#include "Staff.h"
#include "Member.h"
#include "Product.h"
#include "MyProduct.h"
#include "Voucher.h"

using namespace std;

class Node_Bill{
private:
    string MaHD;
    string MaTV;
    MyProduct P;
    Day ngaynhap;
    string MaNV;
    string MaVC;
    int SoSP;
    Node_Bill *next;
public:
    Node_Bill(string MaHD,string MaTV,MyProduct P,Day D,string MaNV,string MaVC,int soSP,Node_Bill *next):
MaHD(MaHD),MaTV(MaTV),P(P),ngaynhap(D),MaNV(MaNV),MaVC(MaVC),SoSP(soSP),next(next){};
    friend class Bill;
};

class Bill{
private:
    Node_Bill *head;
public:
    Bill();
    Bill(const Bill &B);
    ~Bill();
    Bill InsertNodeAfter(string MaHD,string MaTV,MyProduct P,Day D,string MaNV,string MaVC,int soSP);
    Bill DocFile(string tenFile);
    void GhiFile(string tenFile);
    void printfBill(const Product &p,const Voucher &V) const;
//    float ThanhTien(Product P);
};

#endif // Bill_h
