#ifndef MyProduct_h
#define MyProduct_h
#include <bits/stdc++.h>
#include "Product.h"

using namespace std;

class Node_MyProduct{
private:
    string MaHD;
    string MaSP;
    int SL;
    float DonGia;
    Node_MyProduct *next;
public:
    Node_MyProduct(string MaHD,string MaSP,int SL,float DonGia,Node_MyProduct *next):
MaHD(MaHD),MaSP(MaSP),SL(SL),DonGia(DonGia),next(next){};
    friend class MyProduct;
};

class MyProduct{
private:
    Node_MyProduct *head;
public:
    MyProduct();
    MyProduct(const MyProduct &P);
    ~MyProduct();
    MyProduct operator=(const MyProduct &P);
    MyProduct InsertNodeAfter(string MaHD,string MaSP,int SL,float DonGia);
    MyProduct DocFile(string TenFile);
    void GhiFile(string TenFile) const;
    void printfMyProduct() const;
    void printfMyProduct(string s) const;
    float ThanhTien(string s) const;
};

#endif // MyProduct_h
