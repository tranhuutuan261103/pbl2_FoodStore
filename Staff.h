#ifndef Staff_h
#define Staff_h
#include <bits/stdc++.h>
#include "Person.h"
#include "Day.h"

using namespace std;

class Node_Staff:public Person{
private:
    string MaNV;
    string cmnd;
    string DiaChi;
    string email;
    float Luong;
    Node_Staff *next;
public:
    Node_Staff(string MaNV,string name,string sdt,Day ngaysinh,string cmnd,
string DiaChi,string email,float Luong,Node_Staff *next):Person(name,sdt,ngaysinh)
,MaNV(MaNV),cmnd(cmnd),DiaChi(DiaChi),email(email),Luong(Luong),next(next){};
    friend class Staff;
};

class Staff:public Person{
private:
    Node_Staff *head;
public:
    Staff();
    Staff(const Staff &S);
    ~Staff();
    bool CheckMaNV(string s) const;
    Staff InsertNodeAfter(string MaNV,string name,string sdt,Day ngaysinh,
string cmnd,string DiaChi,string email,float Luong);
    Staff DocFile(string tenFile);
    void GhiFile(string tenFile) const;
    void printfStaff() const;
    friend istream& operator>>(istream &in,Staff &S);
    friend ostream& operator<<(ostream &out,const Staff &S);
};

#endif // Staff_h
