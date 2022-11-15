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

MyProduct MyProduct::InsertNodeAfter(string s,int i)
{
    Node_MyProduct *temp=new Node_MyProduct(s,i,NULL);
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

void MyProduct::printfMyProduct() const
{
    if(this->head!=NULL)
    {
        Node_MyProduct *node=this->head;
        while (node!=NULL)
        {
            cout << left << setw(10) << node->MaSP;
            cout << node->SL<<endl;
            node=node->next;
        }
        cout << endl;
    }
}

string MyProduct::getMaSP(int i) const
{
    Node_MyProduct *node=this->head;

    while (i--)
        node=node->next;
    return node->MaSP;
}

int MyProduct::getSL(int i) const
{
    Node_MyProduct *node=this->head;
    while (i--)
        node=node->next;
    return node->SL;
}

int MyProduct::sizeofMyProduct() const
{
    int c=0;
    Node_MyProduct *temp=this->head;
    while(temp!=NULL)
    {
        c++;
        temp=temp->next;
    }
    return c;
}

float MyProduct::ThanhTien(const Product &p)
{
    float s=0;
    for (int i=0;i<this->sizeofMyProduct();i++)
    {
        s+=(p.getDonGia(this->getMaSP(i)))*(this->getSL(i));
    }
    return s;
}
