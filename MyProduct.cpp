#include <bits/stdc++.h>
#include "MyProduct.h"
#include "Product.h"

using namespace std;

MyProduct::MyProduct()
{
    this->head=NULL;
}

MyProduct::MyProduct(const MyProduct &P)
{
    this->head=P.head;
}

MyProduct::~MyProduct()
{
    this->head=NULL;
}

MyProduct MyProduct::operator=(const MyProduct &P)
{
    if (this!=&P)
    {
        this->head=P.head;
    }
    return *this;
}

MyProduct MyProduct::InsertNodeAfter(string MaHD,string MaSP,int SL,float DonGia)
{
    Node_MyProduct *temp=new Node_MyProduct(MaHD,MaSP,SL,DonGia,NULL);
    if (this->head==NULL)
        this->head=temp;
    else
    {
        Node_MyProduct *node = this->head;
        while ( node->next!=NULL )
            node = node->next;
        node->next = temp;
    }
    return *this;
}

MyProduct MyProduct::DocFile(string TenFile)
{
    ifstream input_File;
    input_File.open(TenFile,ios::in);
    while (1)
    {
        string s1,s2,line;
        int sl;
        float dongia;
        getline(input_File,s1,'|');

        getline(input_File,s2,'|');

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

void MyProduct::GhiFile(string TenFile) const
{
    Node_MyProduct *node = this->head;
    ofstream output_File;
    output_File.open(TenFile,ios::out | ios::trunc);
    while (node!=NULL)
    {
        output_File << node->MaHD;
        output_File << "|";
        output_File << node->MaSP;
        output_File << "|";
        output_File << node->SL << " " << node->DonGia << endl;
        node=node->next;
    }
    output_File.close();
}


void MyProduct::printfMyProduct() const
{
    if(this->head!=NULL)
    {
        Node_MyProduct *node = this->head;
        while (node!=NULL)
        {
            cout << left << setw(10) << node->MaHD;
            cout << left << setw(30) << node->MaSP;
            cout << left << setw(10) << node->SL;
            cout << left << setw(10) << node->DonGia;
            cout << endl;
            node=node->next;
        }
    }
}

void MyProduct::printfMyProduct(string s) const
{
    if(this->head!=NULL)
    {
        Node_MyProduct *node = this->head;
        while (node!=NULL)
        {
            if (node->MaHD==s)
            {
                cout << left << setw(30) << node->MaSP;
                cout << left << setw(10) << node->SL;
                cout << left << setw(10) << node->DonGia << endl;
            }
            node=node->next;
        }
    }
}

float MyProduct::ThanhTien(string s) const
{
    float t=0;
    if(this->head!=NULL)
    {
        Node_MyProduct *node = this->head;
        while (node!=NULL)
        {
            if(node->MaHD==s)
            {
                t+=(node->SL)*(node->DonGia);
            }
            node=node->next;
        }
    }
    return t;
}
