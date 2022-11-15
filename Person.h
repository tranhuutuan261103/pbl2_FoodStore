#ifndef Person_h
#define Person_h
#include <bits/stdc++.h>
#include "Day.h"

using namespace std;

class Person{
private:
    string name;
    string sdt;
    Day ngaysinh;
public:
    Person(){}
    Person(string name,string sdt,Day ngaysinh):name(name),sdt(sdt),ngaysinh(ngaysinh){}
    Person(const Person &P);
    ~Person(){}
    void setName(string name);
    string getName() const;
    void setSDT(string sdt);
    string getSDT() const;
    void setNS(Day D);
    Day getNS() const;
    void printfPerson();
};

#endif // Person_h
