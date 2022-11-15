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

Member Member::InsertNodeAfter(string name,string sdt,Day ngaysinh,string mk,int diem)
{
    Node_Member *temp=new Node_Member(name,sdt,ngaysinh,mk,diem,NULL);
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
        string s1,s2,s3,line;
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

        getline(input_File,s3,'|');

        input_File >> diem;

        getline(input_File,line,'\n');

        if (input_File.eof())
            break;
        InsertNodeAfter(s1,s2,D,s3,diem);
    }
    input_File.close();
    return *this;
}

void Member::GhiFile(string TenFile)
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

        output_File << node->mk;
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
