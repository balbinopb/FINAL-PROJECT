#include<header.h>

void createListMember(ListMember &LM){
    LM.firstMember = NULL;
}
void createListBook(ListBook &LB){
    LB.firstBook = NULL;
}
void createListBorrow(ListBorrow &LBW){
    LBW.firstBorrow = NULL;
}
void createListStaff(ListStaff &LS){
    LS.firstStaff = NULL;
}
void createListReservation(ListReservation &LR){
    LR.firstReservation = NULL;
}

addressBook createElmBook(infotypeBook infoBook){
    addressBook p = new Book;
    p->infoBook = infoBook;
    p->nextBook = NULL;
    return p;
}
addressMember createElmMember(infotypeMember infoMember){
    addressMember p = new Member;
    p->infoMember = infoMember;
    p->nextMember = NULL;
    return p;
}
addressBorrow createElmBorrow(infotypeBorrow infoBorrow){
    addressBorrow p = new Borrow;
    p->infoBorrow = infoBorrow;
    p->nextBorrow = NULL;
    return p;
}
addressStaff createElmStaff(infotypeStaff infoStaff){
    addressStaff p = new Staff;
    p->infoStaff = infoStaff;
    p->nextStaff = NULL;
    return p;
}
addressReservation createElmReservation(infotypeReservation infoReservation){
    addressReservation p = new Reservation;
    p->infoReservation = infoReservation;
    p->nextReservation = NULL;
    return p;
}

void insertFirstMember(ListMember &LM, addressMember p){
    if (LM.firstMember == NULL){
        LM.firstMember = p;
    } else {
        p->nextMember = LM.firstMember;
        LM.firstMember = p;
    }
}
void insertFirstBook(ListBook &LB, addressBook p){
    if (LB.firstBook == NULL){
        LB.firstBook = p;
    } else {
        p->nextBook = LB.firstBook;
        LB.firstBook = p;
    }
}
void insertFirstBorrow(ListBorrow &LBW, addressBorrow p){
    if (LBW.firstBorrow == NULL){
        LBW.firstBorrow = p;
    } else {
        p->nextBorrow = LBW.firstBorrow;
        LBW.firstBorrow = p;
    }
}
void insertFirstStaff(ListStaff &LS, addressStaff p){
    if (LS.firstStaff == NULL){
        LS.firstStaff = p;
    } else {
        p->nextStaff = LS.firstStaff;
        LS.firstStaff = p;
    }
}
void insertFirstReservation(ListReservation &LR, addressReservation p){
    if (LR.firstReservation == NULL){
        LR.firstReservation = p;
    } else {
        p->nextReservation = LR.firstReservation;
        LR.firstReservation = p;
    }
}