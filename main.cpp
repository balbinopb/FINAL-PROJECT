#include "library_management.h"

int main() {
    ListMember LM;
    ListBook LB;
    ListBorrow LBW;

    createListMember(LM);
    createListBook(LB);
    createListBorrow(LBW);

//====================these are the data that are already in the system====================

    // these members of group in this project
    infotypeMember member1 = {"Balbino", "103012350551"};
    infotypeMember member2 = {"Nazario", "103012350552"};
    infotypeMember member3 = {"Amir", "103012340364"};
    insertFirstMember(LM, createElmMember(member1));
    insertFirstMember(LM, createElmMember(member2));
    insertFirstMember(LM, createElmMember(member3));

    // Add some books
    infotypeBook book1 = {"Competitive Programming 4", "Steven Halim, Felix Halim, Suhendry Effendy", "Competitive Programming"};
    infotypeBook book2 = {"Supremacy", "Parmy Olson", "Technology"};
    infotypeBook book3 = {"Atomic Habits", "James Clear", "Non-Fiction"};
    insertFirstBook(LB, createElmBook(book1));
    insertFirstBook(LB, createElmBook(book2));
    insertFirstBook(LB, createElmBook(book3));

    // Add some borrow records
    infotypeBorrow borrow1 = {"2025-01-01", "2025-01-15"};
    infotypeBorrow borrow2 = {"2025-01-05", "2025-01-20"};
    addressMember memberPtr;
    addressBook bookPtr;

    // Borrow 1: Balbino borrows "1984"
    searchMember(LM, memberPtr, "103012350551");
    searchBook(LB, bookPtr, "Competitive Programming 4");
    addressBorrow borrowRecord1 = createElmBorrow(borrow1);
    borrowRecord1->borrower = memberPtr;
    borrowRecord1->borrowedBook = bookPtr;
    insertFirstBorrow(LBW, borrowRecord1);

    // Borrow 2: Nazario borrows "The Great Gatsby"
    searchMember(LM, memberPtr, "103012350552");
    searchBook(LB, bookPtr, "Supremacy");
    addressBorrow borrowRecord2 = createElmBorrow(borrow2);
    borrowRecord2->borrower = memberPtr;
    borrowRecord2->borrowedBook = bookPtr;
    insertFirstBorrow(LBW, borrowRecord2);

//======================================= until here =======================================


    int mainChoice, subChoice;

    do {
        showMainMenu();
        cin >> mainChoice;
        cout << endl;

        switch (mainChoice) {
            case 1: { // Member Menu
                do {
                    showMemberMenu();
                    cin >> subChoice;
                    cout << endl;
                    switch (subChoice) {
                        case 1: {// Add Member
                            infotypeMember newMember;
                            cout << "Enter Member Name: ";
                            cin >> newMember.name;
                            cout << "Enter Member ID: ";
                            cin >> newMember.memberID;
                            addressMember member = createElmMember(newMember);
                            insertLastMember(LM, member);
                            cout << "Member added successfully!" << endl;
                            break;
                        }
                        case 2: {// Update Member
                            string memberID;
                            infotypeMember updatedInfo;
                            cout << "Enter Member ID to update: ";
                            cin >> memberID;
                            cout << "Enter New Member Name: ";
                            cin >> updatedInfo.name;
                            cout << "Enter New Member ID: ";
                            cin >> updatedInfo.memberID;
                            updateMemberInfo(LM, memberID, updatedInfo);
                            cout << "Member updated successfully!" << endl;
                            break;
                        }
                        case 3: {// Delete Member
                            string memberID;
                            cout << "Enter Member ID to delete: ";
                            cin >> memberID;
                            deleteSpecificMember(LM, memberID);
                            cout << "Member deleted successfully!" << endl;
                            break;
                        }
                        case 4: {// Search Member
                            string memberID;
                            addressMember member;
                            cout << "Enter Member ID to search: ";
                            cin >> memberID;
                            searchMember(LM, member, memberID);
                            if (member) {
                                cout << "Member found: " << member->infoMember.name << endl;
                            } else {
                                cout << "Member not found!" << endl;
                            }
                            break;
                        }
                        case 5: {// Display All Members
                            displayAllMembers(LM);
                            break;
                        }
                    }
                } while (subChoice != 6);
                break;
            }

            case 2: { // Book Menu
                do {
                    showBookMenu();
                    cin >> subChoice;
                    cout << endl;
                    switch (subChoice) {
                        case 1: {// Add Book
                            infotypeBook newBook;
                            cout << "Enter Book Title: ";
                            cin >> newBook.title;
                            cout << "Enter Book Author: ";
                            cin >> newBook.author;
                            cout << "Enter Book Category: ";
                            cin >> newBook.category;
                            addressBook book = createElmBook(newBook);
                            insertLastBook(LB, book);
                            cout << "Book added successfully!" << endl;
                            break;
                        }
                        case 2: {// Update Book
                            string title;
                            infotypeBook updatedBook;
                            cout << "Enter Book Title to update: ";
                            cin >> title;
                            cout << "Enter New Title: ";
                            cin >> updatedBook.title;
                            cout << "Enter New Author: ";
                            cin >> updatedBook.author;
                            cout << "Enter New Category: ";
                            cin >> updatedBook.category;
                            updateBookInfo(LB, title, updatedBook);
                            cout << "Book updated successfully!" << endl;
                            break;
                        }
                        case 3: {// Delete Book
                            string title;
                            cout << "Enter Book Title to delete: ";
                            cin >> title;
                            deleteSpecificBook(LB, title);
                            cout << "Book deleted successfully!" << endl;
                            break;
                        }
                        case 4: {// Search Book
                            string title;
                            addressBook book;
                            cout << "Enter Book Title to search: ";
                            cin >> title;
                            searchBook(LB, book, title);
                            if (book) {
                                cout << "Book found: " << book->infoBook.title << endl;
                            } else {
                                cout << "Book not found" << endl;
                            }
                            break;
                        }
                        case 5: {// Display All Books
                            displayAllBooks(LB);
                            break;
                        }
                        case 6: {// Search Books by Category
                            string category;
                            cout << "Enter Category: ";
                            cin >> category;
                            searchBooksByCategory(LB, category);
                            break;
                        }
                        case 7: {// Search Books by Author
                            string author;
                            cout << "Enter Author: ";
                            cin >> author;
                            searchBooksByAuthor(LB, author);
                            break;
                        }
                    }
                } while (subChoice != 8);
                break;
            }

            case 3: { // Borrow Menu
                do {
                    showBorrowMenu();
                    cin >> subChoice;
                    cout << endl;
                    switch (subChoice) {
                        case 1: {// Borrow Book
                            string memberID, title, borrowDate, returnDate;
                            cout << "Enter Member ID: ";
                            cin >> memberID;
                            cout << "Enter Book Title: ";
                            cin >> title;
                            cout << "Enter Borrow Date: ";
                            cin >> borrowDate;
                            cout << "Enter Return Date: ";
                            cin >> returnDate;

                            infotypeBorrow borrowInfo = {borrowDate, returnDate};
                            addressMember member;
                            addressBook book;
                            searchMember(LM, member, memberID);
                            searchBook(LB, book, title);

                            if (member && book) {
                                addressBorrow borrow = createElmBorrow(borrowInfo);
                                borrow->borrower = member;
                                borrow->borrowedBook = book;
                                insertLastBorrow(LBW, borrow);
                                cout << "Book borrowed successfully!" << endl;
                            } else {
                                cout << "Member or Book not found!" << endl;
                            }
                            break;
                        }
                        case 2: {// Return Book
                            string title;
                            cout << "Enter Book Title to return: ";
                            cin >> title;
                            deleteSpecificBorrow(LBW, title);
                            cout << "Book returned successfully!" << endl;
                            break;
                        }
                        case 3: {// View Borrow History of a Member
                            string memberID;
                            cout << "Enter Member ID: ";
                            cin >> memberID;
                            displayBorrowHistory(LBW, memberID);
                            break;
                        }
                    }
                } while (subChoice != 4);
                break;
            }

            case 4: { // Borrowed Books Menu
                do {
                    showBorrowedBooksMenu();
                    cin >> subChoice;
                    cout << endl;
                    switch (subChoice) {
                        case 1: {// Display All Borrowed Books
                            displayAllBorrowedBooks(LBW);
                            break;
                        }
                        case 2: {// Check Book Availability
                            string title;
                            cout << "Enter Book Title: ";
                            cin >> title;
                            bool available = isBookAvailable(LB, LBW, title);
                            cout << "Book " << (available ? "is available." : "is not available.") << endl;
                            break;
                        }
                    }
                } while (subChoice != 3);
                break;
            }

            case 5: { // Reports Menu
                do {
                    showReportsMenu();
                    cin >> subChoice;
                    cout << endl;
                    switch (subChoice) {
                        case 1: {// Total Members
                            cout << "Total Members: " << countMembers(LM) << endl;
                            break;
                        }
                        case 2: {// Total Books
                            cout << "Total Books: " << countBooks(LB) << endl;
                            break;
                        }
                        case 3: {// Total Borrowed Books
                            cout << "Total Borrowed Books: " << countBorrowedBooks(LBW) << endl;
                            break;
                        }
                    }
                } while (subChoice != 4);
                break;
            }

            case 6:
                cout<<"---------------------------------------------"<<endl;
                cout << "          *****       *****         " << endl;
                cout << "       *S********   **********      " << endl;
                cout << "     ****T***D**** *************    " << endl;
                cout << "    ******R****A*****************   " << endl;
                cout << "     ******U*****T**************    " << endl;
                cout << "      ******C******A***********     " << endl;
                cout << "       ******T****************      " << endl;
                cout << "         *****U*************        " << endl;
                cout << "           ****R**********          " << endl;
                cout << "             ***E*******            " << endl;
                cout << "               **S****              " << endl;
                cout << "                 ***                " << endl;
                cout << "                  *                 " << endl;
                cout << "     Thank you for using the system!" << endl;
                cout<<"we really appreciate for testing our system"<<endl; 
                cout<<"---------------------------------------------"<<endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (mainChoice != 6);

    return 0;
}
