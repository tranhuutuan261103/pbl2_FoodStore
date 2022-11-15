#include <bits/stdc++.h>
#include "Day.h"
#include "Voucher.h"

using namespace std;

Voucher::Voucher()
{
    this->head=NULL;
}

Voucher::Voucher(const Voucher &V)
{
    this->head=V.head;
}

Voucher::~Voucher()
{
    this->head=NULL;
}

Voucher Voucher::InsertNodeAfter(string MaVC,Day nsx,Day hsd,float ck,float mad,float gtd)
{
    Node_Voucher *temp=new Node_Voucher(MaVC,nsx,hsd,ck,mad,gtd,NULL);
    if (this->head==NULL)
        this->head=temp;
    else
    {
        Node_Voucher *node = this->head;
        while ( node->next!=NULL )
            node = node->next;
        node->next = temp;
    }
    return *this;
}

Voucher Voucher::DocFile(string TenFile)
{
    ifstream input_File;
    input_File.open(TenFile,ios::in);
    while (1)
    {
        string s1,line;
        int d,m,y;
        float f1,f2,f3;
        getline(input_File,s1,'|');

        input_File >> d;
        getline(input_File,line,'/');
        input_File >> m;
        getline(input_File,line,'/');
        input_File >> y;
        getline(input_File,line,'|');
        Day D1(d,m,y);

        input_File >> d;
        getline(input_File,line,'/');
        input_File >> m;
        getline(input_File,line,'/');
        input_File >> y;
        getline(input_File,line,'|');
        Day D2(d,m,y);

        input_File >> f1;
        getline(input_File,line,'|');
        input_File >> f2;
        getline(input_File,line,'|');
        input_File >> f3;

        getline(input_File,line,'\n');

        if (input_File.eof())
            break;

        InsertNodeAfter(s1,D1,D2,f1,f2,f3);
    }
    input_File.close();
    return *this;
}

void Voucher::GhiFile(string TenFile)
{
    Node_Voucher *node = this->head;
    ofstream output_File;
    output_File.open(TenFile,ios::out | ios::trunc);
    while (node!=NULL)
    {
        output_File << node->MaVoucher;
        output_File << "|";

        Day D1=node->nsx;

        output_File << D1.getDay();
        output_File << "/";

        output_File << D1.getMonth();
        output_File << "/";

        output_File << D1.getYear();
        output_File << "|";

        Day D2=node->hsd;

        output_File << D2.getDay();
        output_File << "/";

        output_File << D2.getMonth();
        output_File << "/";

        output_File << D2.getYear();
        output_File << "|";

        output_File << node->chietkhau;
        output_File << "|";

        output_File << node->muc_ap_dung;
        output_File << "|";

        output_File << node->giam_toi_da << endl;
        node=node->next;
    }
    output_File.close();
}

void Voucher::printfVoucher() const
{
    if(this->head!=NULL)
    {
        Node_Voucher *node = this->head;
        while (node!=NULL)
        {
            cout << left << setw(20) << node->MaVoucher ;
            cout << node->nsx;
            cout << node->hsd;
            cout << left << setw(10) << node->chietkhau;
            cout << left << setw(10) << node->muc_ap_dung;
            cout << left << setw(10) << node->giam_toi_da;
            cout << endl;
            node=node->next;
        }
    }
}

float Voucher::getCK(string s) const
{
    Node_Voucher *temp=this->head;
    while (temp!=NULL)
    {
        if (temp->MaVoucher==s) return temp->chietkhau;
        temp=temp->next;
    }
    return 0;
}

float Voucher::getGTD(string s) const
{
    Node_Voucher *temp=this->head;
    while (temp!=NULL)
    {
        if (temp->MaVoucher==s) return temp->giam_toi_da;
        temp=temp->next;
    }
    return 0;
}

float Voucher::MucGiam(string maVC,float GiaGoc) const
{
    float t=GiaGoc*(this->getCK(maVC)/100);
    if (t>=this->getGTD(maVC)) return this->getGTD(maVC);
    return t;
}
