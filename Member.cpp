#include <bits/stdc++.h>
#include "Person.h"
#include "Day.h"
#include "Member.h"

using namespace std;

Member::Member()
{
    this->head=NULL;
}

Member::Member(const Member &M)
{
    this->head=M.head;
}

Member::~Member()
{
    this->head=NULL;
}

bool Member::CheckMaTV(string s) const
{
    Node_Member *p=this->head;
    while (p!=NULL)
    {
        if (p->getSDT()==s) return true;
        p=p->next;
    }
    return false;
}

Member Member::InsertNodeAfter(string name,string sdt,Day ngaysinh,int diem)
{
    Node_Member *temp=new Node_Member(name,sdt,ngaysinh,diem,NULL);
    if (this->head==NULL)
        this->head=temp;
    else
    {
        Node_Member *node = this->head;
        while ( node->next!=NULL )
            node = node->next;
        node->next = temp;
    }
    return *this;
}

Member Member::DocFile(string TenFile)
{
    ifstream input_File;
    input_File.open(TenFile,ios::in);
    while (1)
    {
        string s1,s2,line;
        int d,m,y;
        int diem;
        getline(input_File,s1,'|');

        getline(input_File,s2,'|');

        input_File >> d;
        getline(input_File,line,'/');
        input_File >> m;
        getline(input_File,line,'/');
        input_File >> y;
        getline(input_File,line,'|');
        Day D(d,m,y);

        input_File >> diem;

        getline(input_File,line,'\n');

        if (input_File.eof())
            break;
        InsertNodeAfter(s1,s2,D,diem);
    }
    input_File.close();
    return *this;
}

void Member::GhiFile(string TenFile) const
{
    Node_Member *node = this->head;
    ofstream output_File;
    output_File.open(TenFile,ios::out | ios::trunc);
    while (node!=NULL)
    {
        output_File << node->getName();
        output_File << "|";

        output_File << node->getSDT();
        output_File << "|";

        Day D=node->getNS();

        output_File << D.getDay();
        output_File << "/";

        output_File << D.getMonth();
        output_File << "/";

        output_File << D.getYear();
        output_File << "|";

        output_File << node->diem << endl;
        node=node->next;
    }
    output_File.close();
}

void Member::printfMember() const
{
    if(this->head!=NULL)
    {
        Node_Member *node = this->head;
        while (node!=NULL)
        {
            cout << left << setw(20) << node->getName() ;
            cout << left << setw(12) << node->getSDT();
            cout << node->getNS();
            cout << left << setw(10) << node->diem;
            cout << endl;
            node=node->next;
        }
    }
}

int Member::getDiem(string s) const
{
    Node_Member *node=this->head;
    while (node!=NULL)
    {
        if (s==node->getSDT()) break;
        node=node->next;
    }
    return node->diem;
}

Member Member::UpdateDiem(string s,int d)
{
    Node_Member *node=this->head;
    while (node!=NULL)
    {
        if (s==node->getSDT())
        {
            node->diem+=d;
            break;
        }
        node=node->next;
    }
    return *this;
}

istream &operator>>(istream &in,Member &M)
{
    string name,sdt;
    Day ngaysinh;
    int diem=0;
    do{
        cout << "Nhap so dien thoai:";
        in >> sdt;
    }while(M.CheckMaTV(sdt)==true);
    cout << "Nhap ho ten:";
    in >> name;
    cout << "Nhap ngay sinh:" << endl;
    in >> ngaysinh;
    M.InsertNodeAfter(name,sdt,ngaysinh,diem);
    return in;
}

ostream &operator<<(ostream &out,const Member &M)
{
    M.printfMember();
    return out;
}

