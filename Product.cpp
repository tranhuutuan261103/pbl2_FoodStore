#include <bits/stdc++.h>
#include "Product.h"

using namespace std;

Product::Product()
{
    this->head=NULL;
}

Product::Product(const Product &p)
{
    this->head=p.head;
}

Product::~Product()
{
    this->head=NULL;
}

Product Product::InsertNodeAfter(string MaSP,string TenSP,int SL,float DonGia)
{
    Node *temp = new Node(MaSP,TenSP,SL,DonGia,NULL);
    if (this->head==NULL)
        this->head=temp;
    else
    {
        Node *node = this->head;
        while ( node->next!=NULL )
            node = node->next;
        node->next = temp;
    }
    return *this;
}

Product Product::DocFile(string TenFile)
{
    ifstream input_File;
    input_File.open(TenFile,ios::in);
    while (1)
    {
        string s1,s2,line;
        int sl;
        float dongia;
        getline(input_File,s1,',');

        getline(input_File,s2,',');

        input_File >> sl;

        input_File >> dongia;
        getline(input_File,line,'\n');
        if (input_File.eof())
            break;

        InsertNodeAfter(s1,s2,sl,dongia);
    }
    input_File.close();
    return *this;
}

void Product::GhiFile(string TenFile)
{
    Node *node = this->head;
    ofstream output_File;
    output_File.open(TenFile,ios::out | ios::trunc);
    while (node!=NULL)
    {
        output_File << node->MaSP;
        output_File << ",";
        output_File << node->TenSP;
        output_File << ",";
        output_File << node->SL << " " << node->DonGia << endl;
        node=node->next;
    }
    output_File.close();
}

void Product::printfProduct() const
{
    if(this->head!=NULL)
    {
        Node *node = this->head;
        while (node!=NULL)
        {
            cout << left << setw(10) << node->MaSP ;
            cout << left << setw(30) << node->TenSP;
            cout << left << setw(10) << node->SL;
            cout << left << setw(10) << node->DonGia;
            cout << endl;
            node=node->next;
        }
    }
}

istream &operator>>(istream &in,Product &P)
{
    string s1,s2;
    int sl;
    float dongia;
    cout << "Nhap ma san pham:";
    getline(std::cin,s1);
    cout << "Nhap ten san pham:";
    getline(std::cin,s2);
    cout << "Nhap so luong:";
    in >> sl;
    cout << "Nhap don gia:";
    in >> dongia;
    P.InsertNodeAfter(s1,s2,sl,dongia);
    return in;
}

ostream &operator<<(ostream &out,const Product &P)
{
    out << left << setw(10) << "Ma SP";
    out << left << setw(30) << "Ten SP";
    out << left << setw(10) << "So Luong";
    out << left << setw(10) << "Don gia";
    cout << endl;
    P.printfProduct();
    return out;
}

float Product::getDonGia(string s) const
{
    Node *temp=this->head;
    while (temp!=NULL)
    {
        if (s==temp->MaSP) return temp->DonGia;
        temp = temp->next;
    }
    return 0;
}
