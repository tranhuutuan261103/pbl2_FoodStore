#include <bits/stdc++.h>
#include "Discount.h"


Discount::Discount(int x,int y)
{
    this->DiemHoaHong=x;
    this->MucChietKhau=y;
}

Discount::Discount(const Discount &Ds)
{
    this->DiemHoaHong=Ds.DiemHoaHong;
    this->MucChietKhau=Ds.MucChietKhau;
}

Discount::~Discount()
{

}

Discount Discount::SetDiscount(int x,int y)
{
    this->DiemHoaHong=x;
    this->MucChietKhau=y;
    return *this;
}

Discount Discount::DocFile(string TenFile)
{
    ifstream input_File;
    input_File.open(TenFile,ios::in);
    input_File >> this->DiemHoaHong;
    input_File >> this->MucChietKhau;
    input_File.close();
    return *this;
}

void Discount::GhiFile(string TenFile) const
{
    ofstream output_File;
    output_File.open(TenFile,ios::out | ios::trunc);
    output_File << this->DiemHoaHong << " ";
    output_File << this->MucChietKhau;
    output_File.close();
}

void Discount::printfDiscount() const
{
    cout << this->DiemHoaHong << " ";
    cout << this->MucChietKhau << endl;
}

float Discount::getMucDiemHH() const
{
    return this->DiemHoaHong;
}

float Discount::getMucCK() const
{
    return this->MucChietKhau;
}
