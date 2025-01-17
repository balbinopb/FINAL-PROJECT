#ifndef LIBRARY_MANAGEMENT_H_INCLUDED
#define LIBRARY_MANAGEMENT_H_INCLUDED

#include <iostream>

using namespace std;

typedef struct Member *addressMember;
typedef struct Book *addressBook;
typedef struct Borrow *addressBorrow;

// Member
struct infotypeMember {
    string name;
    string memberID;
};

struct Member {
    infotypeMember infoMember;
    addressBorrow borrowList;
    addressMember nextMember;
};

struct ListMember {
    addressMember firstMember;
};

// Book
struct infotypeBook {
    string title;
    string author;
    string category;
};

struct Book {
    infotypeBook infoBook;
    addressBorrow borrowList;
    addressBook nextBook;
};

struct ListBook {
    addressBook firstBook;
};

// Borrow
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

// Member Functions
void createListMember(ListMember &LM);
addressMember createElmMember(infotypeMember infoMember);
void insertFirstMember(ListMember &LM, addressMember p);
void insertLastMember(ListMember &LM, addressMember p);
void insertAfterMember(ListMember &LM, addressMember prec, addressMember p);
void deleteFirstMember(ListMember &LM);
void deleteLastMember(ListMember &LM);
void deleteSpecificMember(ListMember &LM, string memberID);
void searchMember(ListMember LM, addressMember &p, string ID);
void updateMemberInfo(ListMember &LM, string memberID, infotypeMember newInfo);
void displayAllMembers(ListMember LM);
int countMembers(ListMember LM);

// Book Functions
void createListBook(ListBook &LB);
addressBook createElmBook(infotypeBook infoBook);
void insertFirstBook(ListBook &LB, addressBook p);
void insertLastBook(ListBook &LB, addressBook p);
void insertAfterBook(ListBook &LB, addressBook prec, addressBook p);
void deleteFirstBook(ListBook &LB);
void deleteLastBook(ListBook &LB);
void deleteSpecificBook(ListBook &LB, string title);
void searchBook(ListBook LB, addressBook &p, string title);
void updateBookInfo(ListBook &LB, string title, infotypeBook newInfo);
void displayAllBooks(ListBook LB);
void searchBooksByCategory(ListBook LB, string category);
void searchBooksByAuthor(ListBook LB, string author);
bool isBookAvailable(ListBook LB, ListBorrow LBW, string title);
int countBooks(ListBook LB);


// Borrow Functions
void createListBorrow(ListBorrow &LBW);
addressBorrow createElmBorrow(infotypeBorrow infoBorrow);
void insertFirstBorrow(ListBorrow &LBW, addressBorrow p);
void insertLastBorrow(ListBorrow &LBW, addressBorrow p);
void insertAfterBorrow(ListBorrow &LBW, addressBorrow prec, addressBorrow p);
void deleteFirstBorrow(ListBorrow &LBW);
void deleteLastBorrow(ListBorrow &LBW);
void deleteSpecificBorrow(ListBorrow &LBW, string title);
void searchBorrow(ListBorrow LBW, addressBorrow &p, string title);
void updateBorrowInfo(ListBorrow &LBW, string title, string newReturnDate);
void displayAllBorrowedBooks(ListBorrow LBW);
void displayBorrowHistory(ListBorrow LBW, string memberID);
int countBorrowedBooks(ListBorrow LBW);

// Menu Functions
void showMainMenu();
void showMemberMenu();
void showBookMenu();
void showBorrowMenu();
void showBorrowedBooksMenu();
void showReportsMenu();


#endif // LIBRARY_MANAGEMENT_H_INCLUDED
