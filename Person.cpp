#include <bits/stdc++.h>
#include "Person.h"
#include "Day.h"

void Person::setName(string name)
{
    this->name=name;
}
string Person::getName() const
{
    return name;
}
void Person::setSDT(string sdt)
{
    this->sdt=sdt;
}
string Person::getSDT() const
{
    return sdt;
}
void Person::setNS(Day D)
{
    this->ngaysinh=D;
}
Day Person::getNS() const
{
    return ngaysinh;
}

void Person::printfPerson()
{
    cout << getName() << getSDT() << getNS();
}
