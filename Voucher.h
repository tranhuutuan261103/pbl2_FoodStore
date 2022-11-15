#ifndef Voucher_h
#define Voucher_h
#include <bits/stdc++.h>
#include "Day.h"

using namespace std;

class Node_Voucher{
private:
    string MaVoucher;
    Day nsx;
    Day hsd;
    float chietkhau;
    float muc_ap_dung;
    float giam_toi_da;
    Node_Voucher *next;
public:
    Node_Voucher(string MaVC,Day nsx,Day hsd,float ck,float mad,float gtd,
Node_Voucher *next):MaVoucher(MaVC),nsx(nsx),hsd(hsd),chietkhau(ck),
muc_ap_dung(mad),giam_toi_da(gtd),next(next){};
    friend class Voucher;
};

class Voucher{
private:
    Node_Voucher *head;
public:
    Voucher();
    Voucher(const Voucher &V);
    ~Voucher();
    Voucher InsertNodeAfter(string MaVC,Day nsx,Day hsd,float ck,float mad,float gtd);
    Voucher DocFile(string tenFile);
    void GhiFile(string tenFile);
    void printfVoucher() const;
    float getCK(string s) const;
    float getGTD(string s) const;
    float MucGiam(string maVC,float GiaGoc) const;
};

#endif // Voucher_h
