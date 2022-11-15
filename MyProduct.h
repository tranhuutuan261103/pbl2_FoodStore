#ifndef MyProduct_h
#define MyProduct_h
#include <bits/stdc++.h>
#include "Product.h"

using namespace std;

class Node_MyProduct{
private:
    string MaSP;
    int SL;
    Node_MyProduct *next;
public:
    Node_MyProduct(string MaSP,int SL,Node_MyProduct *next):
MaSP(MaSP),SL(SL),next(next){};
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
    MyProduct InsertNodeAfter(string s,int i);
    void printfMyProduct() const;
    string getMaSP(int i) const;
    int getSL(int i) const;
    int sizeofMyProduct() const;
    float ThanhTien(const Product &p);
};

#endif // MyProduct_h
