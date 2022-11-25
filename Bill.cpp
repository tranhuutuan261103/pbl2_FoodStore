#include <bits/stdc++.h>
#include "Staff.h"
#include "Member.h"
#include "Product.h"
#include "Bill.h"
#include "Day.h"
#include "Discount.h"

float ChietKhau(int diem,float mucCK)
{
    return diem*mucCK;
}

int getDiemHH(float t,float MucDiemHH)
{
    return t*MucDiemHH;
}

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

bool Bill::CheckMaHD(string s) const
{
    Node_Bill *p=this->head;
    while (p!=NULL)
    {
        if (p->MaHD==s) return false;
        p=p->next;
    }
    return true;
}

Bill Bill::InsertNodeAfter(string MaHD,string MaTV,Day D,string MaNV,int diem,float mucChietKhau)
{
    Node_Bill *temp=new Node_Bill(MaHD,MaTV,D,MaNV,diem,mucChietKhau,NULL);
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
        string s1,s2,s3,line,s;
        int d,m,y;
        int diem;
        float mucCK;
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

        input_File >> diem;

        input_File >> mucCK;

        getline(input_File,line,'\n');

        if (input_File.eof())
            break;
        InsertNodeAfter(s1,s2,D,s3,diem,mucCK);
    }
    input_File.close();
    return *this;
}

void Bill::GhiFile(string TenFile) const
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

        output_File << node->diem << " " << node->mucChietKhau << endl;

        node=node->next;
    }
    output_File.close();
}

void Bill::printfBill(const Product &p,const MyProduct &MyP) const
{
    if(this->head!=NULL)
    {
        Node_Bill *node = this->head;
        while (node!=NULL)
        {
            // string MaHD,string MaTV,Day D,string MaNV,int diem,float mucChietKhau
            cout << left << setw(20) << node->MaHD ;
            cout << left << setw(12) << node->MaTV;
            cout << node->ngaynhap;
            cout << left << setw(15) << node->MaNV;
            cout << left << setw(10) << node->diem;
            cout << left << setw(10) << node->mucChietKhau;
            cout << endl;
            MyP.printfMyProduct(node->MaHD);
            float t=MyP.ThanhTien(node->MaHD);
            cout << left << setw(15) << "Tong:" << t << endl;
            float c=ChietKhau(node->diem,node->mucChietKhau);
            cout << left << setw(15) << "Chiet khau:" << c << endl;
            cout << left << setw(15) << "Thanh tien:" << t-c << endl;
            cout << endl;

            node=node->next;
        }
    }
}

Bill Bill::CreateBill(string MaNV,Product &P,MyProduct &MyP,Member &M,const Discount &Ds)
{
    string maHD,maTV,s;
    int sl,diem=0;
    float mucCK=Ds.getMucCK();
    do{
        cout << "Nhap ma hoa don:";
        cin >> maHD;
    }while (!this->CheckMaHD(maHD));
    Day D;
    cout << "Ngay nhap hoa don:" << endl;
    cin >> D;

    do {
        do {
            cout << "Nhap ma san pham(nhap 0 de dung):";
            cin >> s;
            if (s=="0") break;
        }while (!P.CheckMaSP(s));
        if (s=="0") break;
        do {
            cout << "Nhap so luong:";
            cin >> sl;
        }while (sl>P.GetSL(s) || sl<=0);
        P.UpDateSL(s,sl);
        MyP.InsertNodeAfter(maHD,s,sl,P.getDonGia(s));
    } while (1);

    do {
        cout << "Nhap ma thanh vien(nhap 0 de thanh toan ngay):" ;
        cin >> maTV;
    }while(maTV!="0" && M.CheckMaTV(maTV)==false);

    float t=MyP.ThanhTien(maHD);
    cout << "Tong tien:" << t << endl;

    if (maTV=="0")
        diem=0;
    else{
        cout << "Diem cua ban la:" << M.getDiem(maTV) << endl;
        cout << "Muc chiet khau moi diem:" << Ds.getMucCK() << endl;
        do {
            cout << "Nhap muc diem quy doi:" ;
            cin >> diem;
        } while (diem<0 || ChietKhau(diem,mucCK) >= t || diem>M.getDiem(maTV));
        M.UpdateDiem(maTV,-diem);
        int new_diem=getDiemHH(t,Ds.getMucDiemHH());
        M.UpdateDiem(maTV,new_diem);
    }

    this->InsertNodeAfter(maHD,maTV,D,MaNV,diem,mucCK);
    return *this;
}

