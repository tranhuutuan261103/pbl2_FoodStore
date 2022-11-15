#ifndef Staff_h
#define Staff_h
#include <bits/stdc++.h>
#include "Person.h"
#include "Day.h"

using namespace std;

class Node_Staff:public Person{
private:
    string mk;
    string cmnd;
    string DiaChi;
    string email;
    float Luong;
    Node_Staff *next;
public:
    Node_Staff(string name,string sdt,Day ngaysinh,string mk,string cmnd,
string DiaChi,string email,float Luong,Node_Staff *next):Person(name,sdt,ngaysinh)
,mk(mk),cmnd(cmnd),DiaChi(DiaChi),email(email),Luong(Luong),next(next){};
    friend class Staff;
};

class Staff:public Person{
private:
    Node_Staff *head;
public:
    Staff();
    Staff(const Staff &S);
    ~Staff();
    Staff InsertNodeAfter(string name,string sdt,Day ngaysinh,string mk,
string cmnd,string DiaChi,string email,float Luong);
    Staff DocFile(string tenFile);
    void GhiFile(string tenFile);
    void printfStaff() const;
};

#endif // Staff_h
