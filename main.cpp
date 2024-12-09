#include "library management.h"

int main(){

    ListMember LM;
    ListBook LB;
    ListBorrow LBW;
    ListStaff LS;
    ListReservation LR;

    createListMember(LM);
    createListBook(LB);
    createListBorrow(LBW);
    createListStaff(LS);
    createListReservation(LR);



    return 0;
}
