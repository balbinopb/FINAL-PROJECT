#include"library_management.h"

// Book Functions
void createListBook(ListBook &LB){
    LB.firstBook = NULL;
}

addressBook createElmBook(infotypeBook infoBook) {
    addressBook newBook = new Book;
    newBook->infoBook = infoBook;
    newBook->borrowList = NULL;
    newBook->nextBook = NULL;
    return newBook;
}

void insertFirstBook(ListBook &LB, addressBook p){
    if (LB.firstBook == NULL){
        LB.firstBook = p;
    } else {
        p->nextBook = LB.firstBook;
        LB.firstBook = p;
    }
}

void insertLastBook(ListBook &LB, addressBook p) {
    if (LB.firstBook == NULL) {
        LB.firstBook = p;
    } else {
        addressBook q = LB.firstBook;
        while (q->nextBook != NULL) {
            q = q->nextBook;
        }
        q->nextBook = p;
    }
}

void deleteFirstBook(ListBook &LB) {
    if (LB.firstBook != NULL) {
        addressBook toDelete = LB.firstBook;

        // Disconnect all associated borrows
        addressBorrow currentBorrow = toDelete->borrowList;
        while (currentBorrow != NULL) {
            addressBorrow nextBorrow = currentBorrow->nextBorrow;

            // Disconnect borrow from Member
            addressMember member = currentBorrow->borrower;
            if (member != NULL && member->borrowList == currentBorrow) {
                member->borrowList = currentBorrow->nextBorrow;
            }

            delete currentBorrow;
            currentBorrow = nextBorrow;
        }

        LB.firstBook = toDelete->nextBook;
        delete toDelete;
    }
}

void deleteLastBook(ListBook &LB) {
    if (LB.firstBook != NULL) {
        if (LB.firstBook->nextBook == NULL) {
            deleteFirstBook(LB);
        } else {
            // find the second-to-last node
            addressBook prev = NULL;
            addressBook current = LB.firstBook;
            while (current->nextBook != NULL) {
                prev = current;
                current = current->nextBook;
            }

            // Disconnect all associated borrows for the last book
            addressBorrow currentBorrow = current->borrowList;
            while (currentBorrow != NULL) {
                addressBorrow nextBorrow = currentBorrow->nextBorrow;

                // Disconnect borrow from Member
                if (currentBorrow->borrower != NULL) {
                    addressMember member = currentBorrow->borrower;
                    if (member->borrowList == currentBorrow) {
                        member->borrowList = currentBorrow->nextBorrow;
                    }
                }

                delete currentBorrow;
                currentBorrow = nextBorrow;
            }
            prev->nextBook = NULL;
            delete current; //free the memory
        }
    }
}

void deleteSpecificBook(ListBook &LB, string title) {
    addressBook p = LB.firstBook;
    addressBook prec = NULL;

    // Find the book to delete
    while (p != NULL && p->infoBook.title != title) {
        prec = p;
        p = p->nextBook;
    }

    if (p != NULL) { // If the book is found
        // Step 1: Disconnect all associated borrows
        while (p->borrowList != NULL) {
            addressBorrow borrow = p->borrowList;
            p->borrowList = borrow->nextBorrow;  // Move to the next borrow

            // Disconnect the borrow from the member
            if (borrow->borrower != NULL && borrow->borrower->borrowList == borrow) {
                borrow->borrower->borrowList = borrow->nextBorrow;
            }

            // Disconnect the borrow from the book
            borrow->borrowedBook = NULL;
            borrow->borrower = NULL;
            delete borrow; 
        }

        // Step 2: Disconnect the book List
        if (prec == NULL) { // Deleting the first book
            LB.firstBook = p->nextBook;
        } else { 
            prec->nextBook = p->nextBook;
        }

        // Step 3: Delete the book record
        p->nextBook = NULL;
        delete p;
    }
}


void searchBook(ListBook LB, addressBook &p, string title) {
    p = LB.firstBook;
    while (p != NULL && p->infoBook.title != title) {
        p = p->nextBook;
    }
}

void updateBookInfo(ListBook &LB, string title, infotypeBook newInfo) {
    addressBook p;
    searchBook(LB, p, title);
    if (p != NULL) {
        p->infoBook = newInfo;
    }
}

void displayAllBooks(ListBook LB) {
    addressBook p = LB.firstBook;
    cout << "=============================================" << endl;
    cout << "List of All Books" << endl;
    cout << endl;
    while (p != NULL) {
        cout << "Title: " << p->infoBook.title<<endl;
        cout << "Author: " << p->infoBook.author<<endl;
        cout << "Category: " << p->infoBook.category<<endl;
        cout << endl;
        p = p->nextBook;
    }
    cout << "=============================================" << endl;
}

void searchBooksByCategory(ListBook LB, string category){
    addressBook p = LB.firstBook;
    cout<<"============================================="<<endl;
    cout<<"List of Books with category"<<category<<endl;
    cout << endl;
    while (p != NULL){
        if (p->infoBook.category == category){
            cout << "Title: " << p->infoBook.title<<endl;
            cout << "Author: " << p->infoBook.author<<endl;
            cout << "Category: " << p->infoBook.category<<endl;
            cout << endl;
        }
        p = p->nextBook;
    }
    cout<<"============================================="<<endl;
}

void searchBooksByAuthor(ListBook LB, string author){
    addressBook p = LB.firstBook;
    cout<<"============================================="<<endl;
    cout<<"List of Books with author"<<author<<endl;
    cout << endl;
    while (p != NULL){
        if (p->infoBook.author == author){
            cout << "Title: " << p->infoBook.title<<endl;
            cout << "Author: " << p->infoBook.author<<endl;
            cout << "Category: " << p->infoBook.category<<endl;
            cout << endl;
        }
        p = p->nextBook;
    }
    cout<<"============================================="<<endl;
}

bool isBookAvailable(ListBook LB, ListBorrow LBW, string title){
    addressBook p;
    searchBook(LB, p, title);
    if (p != NULL){
        addressBorrow q = p->borrowList;
        while (q != NULL){
            if (q->borrower != NULL && q->borrower->borrowList == q){
                return false;
            }
            q = q->nextBorrow;
        }
        return true;
    }
    return false;
}

int countBooks(ListBook LB){
    addressBook p = LB.firstBook;
    int count = 0;
    while (p != NULL){
        count++;
        p = p->nextBook;
    }
    return count;
}



