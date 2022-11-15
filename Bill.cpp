#include <bits/stdc++.h>
#include "Staff.h"
#include "Member.h"
#include "Product.h"
#include "Bill.h"
#include "Voucher.h"

using namespace std;

Bill::Bill()
{
    this->head=NULL;
}

Bill::Bill(const Bill &B)
{
    this->head=B.head;
}

Bill::~Bill()
{
    this->head=NULL;
}

Bill Bill::InsertNodeAfter(string MaHD,string MaTV,MyProduct P,Day D,string MaNV,string MaVC,int soSP)
{
    Node_Bill *temp=new Node_Bill(MaHD,MaTV,P,D,MaNV,MaVC,soSP,NULL);
    if (this->head==NULL)
        this->head=temp;
    else
    {
        Node_Bill *node = this->head;
        while ( node->next!=NULL )
            node = node->next;
        node->next = temp;
    }
    return *this;
}

Bill Bill::DocFile(string TenFile)
{
    ifstream input_File;
    input_File.open(TenFile,ios::in);
    while (1)
    {
        MyProduct P;
        string s1,s2,s3,s4,line,s;
        int d,m,y;
        int soSP,n,i;
        getline(input_File,s1,'|');

        getline(input_File,s2,'|');

        input_File >> d;
        getline(input_File,line,'/');
        input_File >> m;
        getline(input_File,line,'/');
        input_File >> y;
        getline(input_File,line,'|');
        Day D(d,m,y);

        getline(input_File,s3,'|');

        getline(input_File,s4,'|');

        input_File >> soSP;

        getline(input_File,line,'\n');

        n=soSP;

        while (n--)
        {
            getline(input_File,s,'|');
            input_File >> i;
            getline(input_File,line,'\n');
            P.InsertNodeAfter(s,i);
        }

        if (input_File.eof())
            break;
        InsertNodeAfter(s1,s2,P,D,s3,s4,soSP);
    }
    input_File.close();
    return *this;
}

void Bill::GhiFile(string TenFile)
{
    Node_Bill *node = this->head;
    ofstream output_File;
    output_File.open(TenFile,ios::out | ios::trunc);
    while (node!=NULL)
    {
        output_File << node->MaHD;
        output_File << "|";

        output_File << node->MaTV;
        output_File << "|";

        Day D=node->ngaynhap;

        output_File << D.getDay();
        output_File << "/";

        output_File << D.getMonth();
        output_File << "/";

        output_File << D.getYear();
        output_File << "|";

        output_File << node->MaNV;
        output_File << "|";

        output_File << node->MaVC;
        output_File << "|";

        output_File << node->SoSP << endl;

        int n=node->SoSP;

        for (int i=0;i<n;i++)

        {
            output_File << node->P.getMaSP(i);
            output_File << "|";
            output_File << node->P.getSL(i) << endl;
        }

        node=node->next;
    }
    output_File.close();
}

void Bill::printfBill(const Product &p,const Voucher &V) const
{
    if(this->head!=NULL)
    {
        Node_Bill *node = this->head;
        while (node!=NULL)
        {
            cout << left << setw(20) << node->MaHD ;
            cout << left << setw(12) << node->MaTV;
            cout << node->ngaynhap;
            cout << left << setw(15) << node->MaNV;
            cout << left << setw(15) << node->MaVC;
            cout << left << setw(10) << node->SoSP;
            cout << endl;
            node->P.printfMyProduct();
            float t=node->P.ThanhTien(p);
            cout << t << endl;
            cout << V.MucGiam(node->MaVC,t) << endl;
            node=node->next;
        }
    }
}
/*
float Bill::ThanhTien(Product p)
{
    float s=0;
    for (int i=0;i<this->head->P.sizeofMyProduct();i++)
    {
        s+=(p.getDonGia(this->head->P.getMaSP(i)))*(this->head->P.getSL(i));
    }
    return s;
}*/
