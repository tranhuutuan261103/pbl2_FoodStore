#include <bits/stdc++.h>
#include "Person.h"
#include "Day.h"
#include "Staff.h"

using namespace std;

Staff::Staff()
{
    this->head=NULL;
}

Staff::Staff(const Staff &S)
{
    this->head=S.head;
}

Staff::~Staff()
{
    this->head=NULL;
}

Staff Staff::InsertNodeAfter(string name,string sdt,Day ngaysinh,string mk,
string cmnd,string DiaChi,string email,float Luong)
{
    Node_Staff *temp=new Node_Staff(name,sdt,ngaysinh,mk,cmnd,DiaChi,email,Luong,NULL);
    if (this->head==NULL)
        this->head=temp;
    else
    {
        Node_Staff *node = this->head;
        while ( node->next!=NULL )
            node = node->next;
        node->next = temp;
    }
    return *this;
}

Staff Staff::DocFile(string TenFile)
{
    ifstream input_File;
    input_File.open(TenFile,ios::in);
    while (1)
    {
        string s1,s2,s3,s4,s5,s6,line;
        int d,m,y;
        float luong;
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

        getline(input_File,s5,'|');

        getline(input_File,s6,'|');

        input_File >> luong;

        getline(input_File,line,'\n');

        if (input_File.eof())
            break;
        InsertNodeAfter(s1,s2,D,s3,s4,s5,s6,luong);
    }
    input_File.close();
    return *this;
}

void Staff::GhiFile(string TenFile)
{
    Node_Staff *node = this->head;
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

        output_File << node->mk;
        output_File << "|";

        output_File << node->cmnd;
        output_File << "|";

        output_File << node->DiaChi;
        output_File << "|";

        output_File << node->email;
        output_File << "|";

        output_File << node->Luong << endl;
        node=node->next;
    }
    output_File.close();
}

void Staff::printfStaff() const
{
    if(this->head!=NULL)
    {
        Node_Staff *node = this->head;
        while (node!=NULL)
        {
            cout << left << setw(20) << node->getName() ;
            cout << left << setw(12) << node->getSDT();
            cout << node->getNS();
            cout << left << setw(15) << node->cmnd;
            cout << left << setw(30) << node->DiaChi;
            cout << left << setw(35) << node->email;
            cout << left << setw(10) << node->Luong;
            cout << endl;
            node=node->next;
        }
    }
}
