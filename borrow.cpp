#include"library_management.h"

void createListBorrow(ListBorrow &LBW){
    LBW.firstBorrow = NULL; // Initialize the first borrow to NULL
}

addressBorrow createElmBorrow(infotypeBorrow infoBorrow){
    addressBorrow newBorrow = new Borrow;
    newBorrow->infoBorrow = infoBorrow;
    newBorrow->borrower = NULL;
    newBorrow->borrowedBook = NULL;
    newBorrow->nextBorrow = NULL;
    return newBorrow;
}

void insertFirstBorrow(ListBorrow &LBW, addressBorrow p){
    if (LBW.firstBorrow == NULL){
        LBW.firstBorrow = p;
    } else {
        p->nextBorrow = LBW.firstBorrow; 
        LBW.firstBorrow = p;
    }
}


void insertLastBorrow(ListBorrow &LBW, addressBorrow p){
    if (LBW.firstBorrow == NULL){
        LBW.firstBorrow = p;
    } else {
        addressBorrow q = LBW.firstBorrow;
        while (q->nextBorrow != NULL){ // Find the last borrow
            q = q->nextBorrow;
        }
        q->nextBorrow = p;
    }
}

void deleteFirstBorrow(ListBorrow &LBW) {
    if (LBW.firstBorrow != NULL) {
        addressBorrow toDelete = LBW.firstBorrow;

        // Disconnect from Member
        if (toDelete->borrower != NULL) {
            addressMember member = toDelete->borrower;
            if (member->borrowList == toDelete) {
                member->borrowList = toDelete->nextBorrow;
            }
        }

        // Disconnect from Book
        if (toDelete->borrowedBook != NULL) {
            addressBook book = toDelete->borrowedBook;
            if (book->borrowList == toDelete) {
                book->borrowList = toDelete->nextBorrow;
            }
        }

        LBW.firstBorrow = toDelete->nextBorrow; // Move the first borrow to the next borrow
        delete toDelete;
    }
}


void deleteLastBorrow(ListBorrow &LBW) {
    if (LBW.firstBorrow != NULL) {
        if (LBW.firstBorrow->nextBorrow == NULL) {
            deleteFirstBorrow(LBW);
        } else {
            addressBorrow prev = NULL;
            addressBorrow current = LBW.firstBorrow;
            while (current->nextBorrow != NULL) { // Find the second-to-last borrow
                prev = current;
                current = current->nextBorrow;
            }

            // Disconnect from Member
            if (current->borrower != NULL) {
                addressMember member = current->borrower;
                if (member->borrowList == current) {
                    member->borrowList = current->nextBorrow;
                }
            }

            // Disconnect from Book
            if (current->borrowedBook != NULL) {
                addressBook book = current->borrowedBook;
                if (book->borrowList == current) {
                    book->borrowList = current->nextBorrow;
                }
            }

            prev->nextBorrow = NULL;
            delete current;
        }
    }
}


void deleteSpecificBorrow(ListBorrow &LBW, string title) {
    if (LBW.firstBorrow != NULL) {
        addressBorrow current = LBW.firstBorrow;
        addressBorrow previous = NULL;

        // Traverse the borrow list to find the borrow with the specified title
        while (current != NULL && current->borrowedBook->infoBook.title != title) {
            previous = current;
            current = current->nextBorrow;
        }

        // If borrow record with the title is found
        if (current != NULL) {
            // Disconnect from the book's borrow list
            addressBook book = current->borrowedBook;
            if (book != NULL && book->borrowList == current) {
                book->borrowList = current->nextBorrow;
            }

            // Disconnect from the member's borrow list
            addressMember member = current->borrower;
            if (member != NULL && member->borrowList == current) {
                member->borrowList = current->nextBorrow;
            }

            // Remove from the borrow list
            if (previous == NULL) {
                // Deleting the first node
                LBW.firstBorrow = current->nextBorrow;
            } else {
                previous->nextBorrow = current->nextBorrow;
            }

            // Delete the borrow record
            delete current;
        }
    }
}

void searchBorrow(ListBorrow LBW, addressBorrow &p, string title){
    p = LBW.firstBorrow;
    while (p != NULL && p->borrowedBook->infoBook.title != title){
        p = p->nextBorrow;
    }
}
void updateBorrowInfo(ListBorrow &LBW, string title, string newReturnDate){
    addressBorrow p;
    searchBorrow(LBW, p, title);
    if (p != NULL){
        p->infoBorrow.returnDate = newReturnDate;
    }
}

int countBorrowedBooks(ListBorrow LBW){
    addressBorrow p = LBW.firstBorrow;
    int count = 0;
    while (p != NULL){
        count++;
        p = p->nextBorrow;
    }
    return count;
}

void displayAllBorrowedBooks(ListBorrow LBW){
    addressBorrow p = LBW.firstBorrow;
    cout << "=============================================" << endl;
    cout << "List of All Borrowed Books" << endl;
    cout<<endl;
    while (p != NULL){
        cout << "Book Title: " << p->borrowedBook->infoBook.title << endl;
        cout << "Borrower: " << p->borrower->infoMember.name << endl;
        cout << "Borrow Date: " << p->infoBorrow.borrowDate << endl;
        cout << "Return Date: " << p->infoBorrow.returnDate << endl;
        cout << endl;
        p = p->nextBorrow;
    }
    cout << "=============================================" << endl;
}
void displayBorrowHistory(ListBorrow LBW, string memberID){
    addressBorrow p = LBW.firstBorrow;
    cout << "=============================================" << endl;
    cout << "Borrow History of Member " << memberID << endl;
    cout << endl;
    while (p != NULL){
        if (p->borrower->infoMember.memberID == memberID){
            cout << "Book Title: " << p->borrowedBook->infoBook.title << endl;
            cout << "Borrow Date: " << p->infoBorrow.borrowDate << endl;
            cout << "Return Date: " << p->infoBorrow.returnDate << endl;
            cout << endl;
        }
        p = p->nextBorrow;
    }
    cout << "=============================================" << endl;
}
