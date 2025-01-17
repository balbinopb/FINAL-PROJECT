#include "library_management.h"

// Member Functions
void createListMember(ListMember &LM) {
    LM.firstMember = NULL;
}

addressMember createElmMember(infotypeMember infoMember) {
    addressMember newMember = new Member;
    newMember->infoMember = infoMember;
    newMember->borrowList = NULL;
    newMember->nextMember = NULL;
    return newMember;
}


void insertFirstMember(ListMember &LM, addressMember p){
    if (LM.firstMember == NULL){
        LM.firstMember = p;
    } else {
        p->nextMember = LM.firstMember;
        LM.firstMember = p;
    }
}

void insertLastMember(ListMember &LM, addressMember p){
    if (LM.firstMember == NULL){
        LM.firstMember = p;
    } else {
        addressMember q = LM.firstMember;
        while (q->nextMember != NULL){
            q = q->nextMember;
        }
        q->nextMember = p;
    }
}

void insertAfterMember(ListMember &LM, addressMember prec, addressMember p) {
    if (prec != NULL) {
        p->nextMember = prec->nextMember;
        prec->nextMember = p;
    }
}

void deleteFirstMember(ListMember &LM) {
    if (LM.firstMember != NULL) {
        addressMember toDelete = LM.firstMember;

        addressBorrow currentBorrow = toDelete->borrowList;
        while (currentBorrow != NULL) {
            addressBorrow nextBorrow = currentBorrow->nextBorrow;

            // Disconnect borrow from Book
            addressBook book = currentBorrow->borrowedBook;
            if (book != NULL && book->borrowList == currentBorrow) {
                book->borrowList = currentBorrow->nextBorrow;
            }

            delete currentBorrow;
            currentBorrow = nextBorrow;
        }

        LM.firstMember = toDelete->nextMember;
        delete toDelete;
    }
}

void deleteLastMember(ListMember &LM) {
    if (LM.firstMember != NULL) {
        if (LM.firstMember->nextMember == NULL) {
            // Only one member
            deleteFirstMember(LM);
        } else {
            addressMember prev = NULL;
            addressMember current = LM.firstMember;
            while (current->nextMember != NULL) { //find the second-to-last member
                prev = current;
                current = current->nextMember;
            }

            // Disconnect borrows for the last member
            addressBorrow currentBorrow = current->borrowList;
            while (currentBorrow != NULL) {
                addressBorrow nextBorrow = currentBorrow->nextBorrow;

                // Disconnect borrow from Book
                if (currentBorrow->borrowedBook != NULL) {
                    addressBook book = currentBorrow->borrowedBook;
                    if (book->borrowList == currentBorrow) {
                        book->borrowList = currentBorrow->nextBorrow;
                    }
                }

                delete currentBorrow;
                currentBorrow = nextBorrow;
            }
            prev->nextMember = NULL;
            delete current;
        }
    }
}

void deleteSpecificMember(ListMember &LM, string memberID) {
    addressMember p = LM.firstMember;
    addressMember prec = NULL;

    while (p != NULL && p->infoMember.memberID != memberID) {
        prec = p;
        p = p->nextMember;
    }

    if (p != NULL) {
        if (prec == NULL) { // Deleting first member
            LM.firstMember = p->nextMember;
        } else { // Deleting in the middle or end
            prec->nextMember = p->nextMember;
        }
        p->nextMember = NULL;
        delete p;
    }
}

void searchMember(ListMember LM, addressMember &p, string ID) {
    p = LM.firstMember;
    while (p != NULL && p->infoMember.memberID != ID) {
        p = p->nextMember;
    }
}

void updateMemberInfo(ListMember &LM, string memberID, infotypeMember newInfo) {
    addressMember p;
    searchMember(LM, p, memberID);
    if (p != NULL) {
        p->infoMember = newInfo;
    }
}

void displayAllMembers(ListMember LM) {
    addressMember p = LM.firstMember;
    cout << "=============================================" << endl;
    cout << "List of All Members" << endl;
    cout << endl;
    while (p != NULL) {
        cout << "Name: " << p->infoMember.name << endl;
        cout << "Member ID: " << p->infoMember.memberID << endl;
        p = p->nextMember;
    }
    cout << "=============================================" << endl;
}

int countMembers(ListMember LM){
    addressMember p = LM.firstMember;
    int count = 0;
    while (p != NULL){
        count++;
        p = p->nextMember;
    }
    return count;
}



//sjeifwjjpe
