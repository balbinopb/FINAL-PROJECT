#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>

using namespace std;

typedef struct Member *addressMember;
typedef struct Book *addressBook;
typedef struct Borrow *addressBorrow;
typedef struct Staff *addressStaff;
typedef struct Reservation *addressReservation;

//member
struct infotypeMember {
    string name;
    string memberID;
};

struct Member {
    infotypeMember infoMember;
    addressBorrow borrowList;
    addressReservation reservationList;
    addressMember nextMember;
};

struct ListMember {
    addressMember firstMember;
};
//end of member

//book
struct infotypeBook {
    string title;
    string author;
    string category;
};

struct Book {
    infotypeBook infoBook;
    addressBorrow borrowList;
    addressReservation reservationList;
    addressBook nextBook;
};

struct ListBook {
    addressBook firstBook;
};
//end of book

//borrow
struct infotypeBorrow {
    string borrowDate;
    string returnDate;
};

struct Borrow {
    infotypeBorrow infoBorrow;
    addressMember borrower;
    addressBook borrowedBook;
    addressBorrow nextBorrow;
};

struct ListBorrow {
    addressBorrow firstBorrow;
};
//end of borrow

//staff
struct infotypeStaff {
    string name;
    string staffID;
    string role;
};

struct Staff {
    infotypeStaff infoStaff;
    addressStaff nextStaff;
};

struct ListStaff {
    addressStaff firstStaff;
};
//end of staff

//reservation
struct infotypeReservation {
    string reservationDate;
    string expirationDate;
};

struct Reservation {
    infotypeReservation infoReservation;
    addressMember reservingMember;
    addressBook reservedBook;
    addressReservation nextReservation;
};

struct ListReservation {
    addressReservation firstReservation;
};
//end of reservation


void createListMember(ListMember &LM);
void createListBook(ListBook &LB);
void createListBorrow(ListBorrow &LBW);
void createListStaff(ListStaff &LS);
void createListReservation(ListReservation &LR);

addressBook createElmBook(infotypeBook infoBook);
addressMember createElmMember(infotypeMember infoMember);
addressBorrow createElmBorrow(infotypeBorrow infoBorrow);
addressStaff createElmStaff(infotypeStaff infoStaff);
addressReservation createElmReservation(infotypeReservation infoReservation);

void insertFirstMember(ListMember &LM, addressMember p);
void insertFirstBook(ListBook &LB, addressBook p);
void insertFirstBorrow(ListBorrow &LBW, addressBorrow p);
void insertFirstStaff(ListStaff &LS, addressStaff p);
void insertFirstReservation(ListReservation &LR, addressReservation p);

void insertLastMember(ListMember &LM, addressMember p);
void insertLastBook(ListBook &LB, addressBook p);
void insertLastBorrow(ListBorrow &LBW, addressBorrow p);
void insertLastStaff(ListStaff &LS, addressStaff p);
void insertLastReservation(ListReservation &LR, addressReservation p);

void insertAfterMember(ListMember &LM, addressMember prec, addressMember p);
void insertAfterBook(ListBook &LB, addressBook prec, addressBook p);
void insertAfterBorrow(ListBorrow &LBW, addressBorrow prec, addressBorrow p);
void insertAfterStaff(ListStaff &LS, addressStaff prec, addressStaff p);
void insertAfterReservation(ListReservation &LR, addressReservation prec, addressReservation p);


void showMenu();
void showBorrowedBooksMenu();

#endif // HEADER_H_INCLUDED
