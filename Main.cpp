#include <bits/stdc++.h>
#include "Product.h"
#include "Person.h"
#include "Day.h"
#include "Staff.h"
#include "Member.h"
#include "Bill.h"
#include "Voucher.h"
#include "MyProduct.h"

using namespace std;

int main()
{
    Product L;
    L.DocFile("Product.txt");

    cout << L;
    L.GhiFile("Product.txt");

    Staff S;
    S.DocFile("Staff.txt");
    S.printfStaff();
    S.GhiFile("Staff.txt");

    Member M;
    M.DocFile("Member.txt");
    M.printfMember();
    M.GhiFile("Member.txt");

    Day d1(14,5,2022),d2(16,5,2022);
    Voucher V;
    V.DocFile("Voucher.txt");
    V.GhiFile("Voucher.txt");
    V.printfVoucher();

    Bill B;
    B.DocFile("Bill.txt");
    B.GhiFile("Bill.txt");
    B.printfBill(L,V);
    return 0;
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