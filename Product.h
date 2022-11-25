#ifndef Product_h
#define Product_h
#include <bits/stdc++.h>

using namespace std;

class Node{
private:
    string MaSP;
    string TenSP;
    int SL;
    float DonGia;
    Node *next;
public:
    Node(string MaSP,string TenSP,int SL,float DonGia,Node *next):MaSP(MaSP),
TenSP(TenSP),SL(SL),DonGia(DonGia),next(next){};
    friend class Product;
};

class Product{
private:
    Node *head;
public:
    Product();
    Product(const Product &p);
    ~Product();
    bool CheckMaSP(string s) const;
    int GetSL(string s) const;
    Product UpDateSL(string s,int sl);
    Product InsertNodeAfter(string MaSP,string TenSP,int SL,float DonGia);
    Product DocFile(string tenFile);
    void GhiFile(string tenFile) const;
    void printfProduct() const;
    friend istream &operator>>(istream &in,Product &P);
    friend ostream &operator<<(ostream &out,const Product &P);
    float getDonGia(string s) const;
};

#endif // Product_h
