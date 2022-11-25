#include <bits/stdc++.h>
#include "Product.h"
#include "Person.h"
#include "Day.h"
#include "Staff.h"
#include "Member.h"
#include "Bill.h"
#include "MyProduct.h"
#include "Discount.h"
#include "Menu.cpp"

using namespace std;

void GetData(Product &P,Staff &S,Member &M,Bill &B,MyProduct &MyP,Discount &D);
void Menu(Product &P,Staff &S,Member &M,Bill &B,MyProduct &MyP,Discount &D);
void SaveData(const Product &P,const Staff &S,const Member &M,const Bill &B,const MyProduct &MyP,const Discount &D);

int main()
{
    Product P;
    Staff S;
    Member M;
    Bill B;
    MyProduct MyP;
    Discount D;
    GetData(P,S,M,B,MyP,D);
    Menu(P,S,M,B,MyP,D);
    SaveData(P,S,M,B,MyP,D);
    return 0;
}

void Menu(Product &P,Staff &S,Member &M,Bill &B,MyProduct &MyP,Discount &D)
{
    int choose;
    do
    {
        system("cls");
        cout << "1.Them san pham\n";
        cout << "2.Them nhan vien\n";
        cout << "3.Dang ky thanh vien\n";
        cout << "4.Lap hoa don\n";
        cout << "5.Xem tat ca cac hoa don\n";
        cout << "0.Thoat\n";
        cout << "Chon:";
        cin >> choose;
        cin.ignore();
        switch(choose)
        {
        case 0:
            break;
        case 1:
            system("cls");
            P.printfProduct();
            cout << "\n\n";
            cin >> P;
            break;
        case 2:
            system("cls");
            S.printfStaff();
            cout << "\n\n";
            cin >> S;
            break;
        case 3:
            system("cls");
            M.printfMember();
            cout << "\n\n";
            cin >> M;
            break;
        case 4:
            system("cls");
            P.printfProduct();
            B.CreateBill("NV01",P,MyP,M,D);
            break;
        case 5:
            system("cls");
            B.printfBill(P,MyP);
            system("pause");
            break;
        default:
            cout << "Nhap lai!";
            system("pause");
            break;
        }
    } while (choose);
}

void GetData(Product &P,Staff &S,Member &M,Bill &B,MyProduct &MyP,Discount &D)
{
    P.DocFile("Product.txt");
    S.DocFile("Staff.txt");
    M.DocFile("Member.txt");
    B.DocFile("Bill.txt");
    MyP.DocFile("MyProduct.txt");
    D.DocFile("Discount.txt");
}

void SaveData(const Product &P,const Staff &S,const Member &M,const Bill &B,const MyProduct &MyP,const Discount &D)
{
    P.GhiFile("Product.txt");
    S.GhiFile("Staff.txt");
    M.GhiFile("Member.txt");
    B.GhiFile("Bill.txt");
    MyP.GhiFile("MyProduct.txt");
    D.GhiFile("Discount.txt");
}

// Sản phẩm : class Product
// Đồ ăn, thức uống
    // Tên sản phẩm
    // Mã sản phẩm
    // Giá tiền của 1 sản phẩm
    // Số lượng có thể bán : nếu < 0 thì báo hết món (Day 1 luôn luôn có món nếu muốn code hay hơn thì sẽ có 1 món bất kì hết hàng)



// class Person
// Thông tin chủ : Tên, số điện thoại,mk, Số cmnd, email liên hệ, ngày sinh.
// Thông tin nhân viên :Tên, số điện thoại,mk, Số cmnd,dia chi, email liên hệ, ngày sinh, he so luong, (so ngay nghi)

// int ra Budget
// Ngân sách
    // Day 1 bán được bao nhiêu đó ghi vào tiền tổng ( lịch sử mua bán là bao gồm hóa đơn)
    // Day 2 ...

    // Day n (Tổng tiền của n ngày : 2000000vnd)

// kế thừa từ lớp person
// Mã thành viên
    // 1 : tích điểm -- tích tới 1 mức điểm nhất định ví dụ 50đ
    // 2 : giảm giá (chiết khấu theo %) :
    // Khai báo ra thành viên : kế thừa từ lớp person : Tên, điện thoại, ngày sinh, mã voucher
        // Điểm tích lũy (theo % của hóa đơn) :

// class voucher
    // voucher (nếu mà đơn hàng vượt 1 mức nhất định như 50k hoặ 100k thì sẽ áp dụng được mã tương ứng)
        // vc 1 : áp dụng cho >= 50k
    // vc 2: áp dụng cho >= 100k
    // Tài khoản và mật khẩu của thành viên
        // Tk là auto sdt
        // Mk là do khách nhập


// Class Bill
    // Mã nhân viên
        // Thông tin của món ăn
    // Mã sản phẩm
    // Số lượng
        // Bao nhiêu đó (5 món của 1 mã sản phẩm nào đó)
    // Đơn giá
        // Tính ra tiền của 1 món
    // Thành tiền
        // 1 * 5
        // Tổng cộng tiền

        // Quý khách có muốn mở thẻ thành viên không : yes or no
    // Chiết khấu
        //tích điểm và giảm giá hoặc voucher (giảm giá được tiền cụ)
    // Phương thức
        // Tiền mặt
        // Tiền khách đưa 100k đơn 65 thì return tiền
        // Tiền khách đưa bé hơn đơn thì cout không đủ tiền mua hàng vui lòng đưa thêm hoặc (do while)

// product.txt
    // Tên           Mã sp            Số lượng hiện có           Đon giá          ...
    //  abc            x                     y                    ...vnd

// Thông tin chủ và nhân viên
    // Chủ :
    // Nhân viên mỗi ngày day 1 day 2 làm được bao nhiêu h đó
        // giờ làm sẽ được ghi vào file txt
// infor.txt
   // mã hóa đơn     mã sp       mã thành viên    soluong    ngaynhap

// voucher.txt
    // ABC123 : 50k
    // XYZ456 : 100k











// Day 1 : tên nhân viên làm việc (nv A)    Giờ làm : 5 tiếng     lương là 20k/h    Tổng lương : 100k
// Day 2 : tên nhân viên làm việc (nv B)    Giờ làm : 6 tiếng
