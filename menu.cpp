#include "library_management.h"

void showMainMenu() {
    cout<<endl;
    cout << "=============================================" << endl;
    cout << "<>         LIBRARY MANAGEMENT SYSTEM       <>" << endl;
    cout << "=============================================" << endl;
    cout << "1. Member Menu" << endl;
    cout << "2. Book Menu" << endl;
    cout << "3. Borrow Menu" << endl;
    cout << "4. Borrowed Books Menu" << endl;
    cout << "5. Reports Menu" << endl;
    cout << "6. Exit" << endl;
    cout << "=============================================" << endl;
    cout << "Choose menu option: ";
}

void showMemberMenu() {
    cout<<endl;
    cout << "=============================================" << endl;
    cout << "<>             MEMBER MENU                <>" << endl;
    cout << "=============================================" << endl;
    cout << "1. Add a Member" << endl;
    cout << "2. Update Member Info" << endl;
    cout << "3. Delete a Member" << endl;
    cout << "4. Search a Member" << endl;
    cout << "5. Show All Members" << endl;
    cout << "6. Back to Main Menu" << endl;
    cout << "=============================================" << endl;
    cout << "Choose menu option: ";
}

void showBookMenu() {
    cout<<endl;
    cout << "=============================================" << endl;
    cout << "<>               BOOK MENU                <>" << endl;
    cout << "=============================================" << endl;
    cout << "1. Add a Book" << endl;
    cout << "2. Update Book Info" << endl;
    cout << "3. Delete a Book" << endl;
    cout << "4. Search a Book" << endl;
    cout << "5. Show All Books" << endl;
    cout << "6. Search Books by Category" << endl;
    cout << "7. Search Books by Author" << endl;
    cout << "8. Back to Main Menu" << endl;
    cout << "=============================================" << endl;
    cout << "Choose menu option: ";
}

void showBorrowMenu() {
    cout<<endl;
    cout << "=============================================" << endl;
    cout << "<>               BORROW MENU              <>" << endl;
    cout << "=============================================" << endl;
    cout << "1. Borrow a Book" << endl;
    cout << "2. Return a Book" << endl;
    cout << "3. View Borrow History of a Member" << endl;
    cout << "4. Back to Main Menu" << endl;
    cout << "=============================================" << endl;
    cout << "Choose menu option: ";
}

void showBorrowedBooksMenu() {
    cout<<endl;
    cout << "=============================================" << endl;
    cout << "<>          BORROWED BOOKS MENU           <>" << endl;
    cout << "=============================================" << endl;
    cout << "1. Show All Borrowed Books" << endl;
    cout << "2. Check Availability of a Book" << endl;
    cout << "3. Back to Main Menu" << endl;
    cout << "=============================================" << endl;
    cout << "Choose menu option: ";
}

void showReportsMenu() {
    cout<<endl;
    cout << "=============================================" << endl;
    cout << "<>              REPORTS MENU              <>" << endl;
    cout << "=============================================" << endl;
    cout << "1. Total Members Count" << endl;
    cout << "2. Total Books Count" << endl;
    cout << "3. Total Borrowed Books Count" << endl;
    cout << "4. Back to Main Menu" << endl;
    cout << "=============================================" << endl;
    cout << "Choose menu option: ";
}
