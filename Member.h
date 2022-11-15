#ifndef Member_h
#define Member_h
#include <bits/stdc++.h>
#include "Person.h"
#include "Day.h"

using namespace std;

class Node_Member:public Person{
private:
    string mk;
    int diem;
    Node_Member *next;
public:
    Node_Member(string name,string sdt,Day ngaysinh,string mk,int diem,Node_Member *next):
    Person(name,sdt,ngaysinh),mk(mk),diem(diem),next(next){};
    friend class Member;
};

class Member:public Person{
private:
    Node_Member *head;
public:
    Member();
    Member(const Member &M);
    ~Member();
    Member InsertNodeAfter(string name,string sdt,Day ngaysinh,string mk,int diem);
    Member DocFile(string tenFile);
    void GhiFile(string tenFile);
    void printfMember() const;
};

#endif // Member_h
