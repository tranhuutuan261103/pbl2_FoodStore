#ifndef Discount_h
#define Discount_h
#include <bits/stdc++.h>

using namespace std;

class Discount{
private:
    float DiemHoaHong;
    float MucChietKhau;
public:
    Discount(int=0,int=0);
    Discount(const Discount &Ds);
    ~Discount();
    Discount SetDiscount(int x,int y);
    Discount DocFile(string tenFile);
    void GhiFile(string tenFile) const;
    void printfDiscount() const;
    float getMucDiemHH() const;
    float getMucCK() const;
};


#endif // Discount_h
