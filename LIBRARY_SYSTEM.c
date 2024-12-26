#include "system.h"

int main() {
    ADMIN ADMIN = {"Admin",123456,100.00};
    BOOK books[MAX_BOOKS];
    USER Users[MAX_USERS];
    char findtitle[MAX_TITLE_LENGTH], findauthor[MAX_AUTHOR_LENGTH], purpose[10],username[MAX_USERNAME_LENGTH];
    int index;
    int book_count_of_db=0;
    int choice;
    int Usercount=0;
    int check;
    float wallet;
    char top_books_names[3][100],topR_books_names[3][100];
    char Promocode[][8]={"NAHLA50","FINAL20","CAVID40"};
    // Reading File and appending to list
    ReadDateBase(books, &book_count_of_db);
    UserRDataBase(Users, &Usercount);

    printf("===================================================\n");
    printf("======================LIBRARY======================\n");
    printf("===================================================\n");
    printf("----------------------Welcome----------------------");

    while (1) {
        printf("\n\nEnter library as an \"Admin\" or a \"User\" : ");
        char userType[10];
        scanf("%s", userType);

        // ADMIN //
        if (strcmp(userType, "Admin") == 0) {
            checkADMIN();
            int t = 1;
            while (t) {
                choice = ADMINInterface();
                switch (choice) {
                    case 1://Shelf //Fazil
                        DisplayShelf(books,book_count_of_db);
                        break;
                    case 2: // Add Book // Fazil
                        addBook(books, book_count_of_db);
                        book_count_of_db++;
                        break;
                    case 3: // Edit Book // Fazil
                        askingBook("edit",findtitle, findauthor);
                        index = searchBook(findtitle, findauthor, books, book_count_of_db);
                        if (index != -1) {
                            editBook(books, index);
                            printf("Book edited successfully.");
                        } else {
                            printf("Sorry, the book you have been looking for could not be found.\nBook will be added to the library by Admin in a few days.");
                        }
                        break;
                    case 4: // Remove Book // Fazil
                        askingBook("remove", findtitle, findauthor);
                        index = searchBook(findtitle, findauthor, books, book_count_of_db);
                        if (index != -1){
                            removeBook(books, index, &book_count_of_db);
                            printf("Book removed successfully.");
                        } else {
                            printf("Sorry, the book you have been looking for could not be found.\nBook will be added to the library by Admin in a few days.");
                        }
                        break;
                    case 5: // Retrieve Book //
                        askingBook("retrieve", findtitle, findauthor);
                        index = searchBook(findtitle, findauthor, books, book_count_of_db);
                        if (index != -1) {
                            displaytoAdminBook(books,index); /// Yusif
                        } else {
                            printf("Sorry, the book you have been looking for could not be found.\nBook will be added to the library by Admin in a few days.");
                        }
                        break;
                    case 6:// Report //
                        FindMostSaledBooks(books,book_count_of_db,top_books_names);
                        FindMostRentedBooks(books,book_count_of_db,topR_books_names);
                        break;
                    case 7: // Exiting //   
                        WriteDataBase(books,book_count_of_db);
                        Shelf(books,book_count_of_db);
                        printf("\nGoing back to the previous menu...\n");
                        t = 0;
                        break;
                    default:
                        printf("Invalid choice\n");
                }
            }
        }
        // User //
        else if (strcmp(userType, "User") == 0){
            int t = 1;
            while (t) {
                int decision=WelcomeUser();
                switch (decision){
                    case 1:
                        check=checkLogIn(Users, Usercount,username,wallet);
                        if(check!=-1)
                        {   printf("\nHello %s",username);
                            printf("\nYou are logged in succesfuly");
                            int k=1;
                            BOUGHTBOOK BoughtBooks[MAX_COUNT_FOR_BUYING];
                            int buycount=0;
                            while (k){
                                choice = UserInterface();
                                switch (choice){
                                    case 1 ://Shelf
                                        DisplayShelf(books,book_count_of_db);
                                        break;
                                    case 2: //Display Book//
                                    askingBook("find",findtitle,findauthor);
                                    index=searchBook(findtitle,findauthor,books,book_count_of_db);
                                    if (index!=-1){
                                    displaytoUserBook(books,index);
                                    }else{
                                        printf("Sorry, the book you have been looking for could not found.");}  
                                        break;
                                    case 3: // Purchase Book //
                                        askingBook("buy",findtitle,findauthor);
                                        index=searchBook(findtitle,findauthor,books,book_count_of_db);
                                        if (index!=-1){
                                            buyBook(books,index,Users,check,ADMIN,&buycount,wallet,BoughtBooks,Promocode);
                                        }else{
                                            printf("Sorry, the book you have been looking for could not found.");}
                                            //UserDataBase(Users,Usercount);
                                        break;
                                    case 4: // Rent book //
                                        askingBook("rent",findtitle,findauthor);
                                        index=searchBook(findtitle,findauthor,books,book_count_of_db);
                                        if (index!=-1){
                                            rentBook(books,index);
                                        }else{
                                            printf("Sorry, the book you have been looking for could not found.");}
                                        break;
                                    case 5:// Give Book //
                                        askingBook("give back",findtitle,findauthor);
                                        index=searchBook(findtitle,findauthor,books,book_count_of_db);
                                        if (index!=-1)
                                        {
                                            giveBook(books,index);
                                        }else{
                                            printf("Sorry, the book you have been looking for could not found.");}
                                        break;
                                    case 6: // Invoice //
                                        printf("\nThis is your check\n");
                                        Invoice(username, books,BoughtBooks,buycount);
                                        printf("\nExiting...\n");
                                        WriteDataBase(books, book_count_of_db);
                                        Shelf(books,book_count_of_db);
                                        k=0;
                                        t=0;
                                        break;
                                    default:
                                        printf("Invalid choice\n");
                                }
                            }
                        }else
                        {
                            printf("\nYour account information could not found.");
                            printf("\nTry to Sign Up.");
                        }
                        break;
                    case 2:
                        Usercount=SignUp(Users, Usercount)+1;
                        UserDataBase(Users,Usercount);
                        break;
                    case 3:
                        printf("Going back to Main menu.........");
                        t = 0;
                        break;
                    default:
                        printf("Invalid choice\n");
                        break;
                }
            }
        } else if (strcmp(userType, "Exit") == 0) {
            printf("\33[1mTHANKS FOR VISITING.\33[0m");
            return 1;
        } else {
            printf("Invalid user type\n");
        }
    }
    return 0;
}

