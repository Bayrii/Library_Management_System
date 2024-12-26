#if !defined(SYSTEM_H)
#define SYSTEM_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>

#define MAX_BOOKS 1000
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 50
#define MAX_GENRE_LENGTH 50
#define MAX_USERNAME_LENGTH 25
#define MAX_PW_LENGTH 8
#define MAX_COUNT_FOR_BUYING 10
#define MAX_USERS 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    float price;
    int stock_sale;
    int stock_rent;
    int saled_books;
    int rented_books;
}BOOK;

typedef struct {
    char username[50];
    long password;
    float wallet;
} ADMIN;

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PW_LENGTH];
    float wallet;
}USER;

typedef struct{
    int bookcount;
    float totalvalue;
    int bindex;
}BOUGHTBOOK;

// Function prototypes
int UserInterface();
int WelcomeUser();
int ADMINInterface();
void checkADMIN();
void askingBook(char purpose[], char findtitle[], char findauthor[]);
int searchBook(const char *title, const char *author, BOOK books[], int bookCount);
void addBook(BOOK books[], int bookCount);
void editBook(BOOK books[], int index);
void removeBook(BOOK books[], int index, int *bookCount);
void displaytoAdminBook(BOOK books[], int index);
void displaytoUserBook(BOOK books[], int index);
void buyBook(BOOK books[], int index,USER user[],int Uindex,ADMIN admin,int *buycount,float wallet,BOUGHTBOOK BoughtBooks[],char promocode[][8]);
void rentBook(BOOK books[], int index); 
void giveBook(BOOK books[],int index);
void WriteDataBase(BOOK books[], int count);
void ReadDateBase(BOOK books[], int *book_count_of_db);
int checkLogIn(USER user[], int Usercount,char username[],float wallet);
int SignUp(USER user[], int Usercount);
void Invoice(char username[],BOOK books[],BOUGHTBOOK BoughtBooks[],int buycount);
void UserDataBase(USER user[], int Usercount);
void UserRDataBase(USER user[], int *Usercount);
void Shelf(BOOK books[], int book_count_of_db);
void DisplayShelf(BOOK books[], int book_count_of_db); 
void FindMostSaledBooks(BOOK books[], int book_count_of_db, char top_books_names[][100]);
void FindMostRentedBooks(BOOK books[],int book_count_of_db, char top_books_names[][100]);




int UserInterface(){
    int choice;
    printf("\n\n======Book Shop Management System======");
    printf("\n1. Show avaible Books");
    printf("\n2. Search for Book");
    printf("\n3. Purchase Book");
    printf("\n4. Rent a Book");
    printf("\n5. Giving Back a Book" );
    printf("\n6. Exit and Display invoice\n");
    printf("=======================================");
    printf("\nEnter your Choice: ");
    scanf("%d", &choice);
    return choice;
}

int WelcomeUser(){
    int decision;
    printf("\n----------\33[1mHello User\33[0m-----------\n");
    printf("\t1. Log in\n \t2. Sign up\n \t3. Go to previous menu  \n");
    printf("-------------------------------\n");
    printf("\nEnter your decision : ");
    scanf("%d", &decision);
    return decision;
}

int ADMINInterface() {
    int choice;
    printf("\n\n======Book Shop Management System======");
    printf("\n1. Show Books");
    printf("\n2. Entry of New Book");
    printf("\n3. Edit Details of Book");
    printf("\n4. Remove a Book from Shelf");
    printf("\n5. Retrieve a Book Information");
    printf("\n6. Report");
    printf("\n7. Save and Go back to previous menu\n");
    printf("=======================================");
    printf("\nEnter your Choice: ");
    scanf("%d", &choice);
    return choice;
}

void checkADMIN() {
    char username[50];
    long  password;
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%ld", &password);
    int attemp=0;
    while (strcmp(username, "Admin") != 0 || password != 123456) {
        printf("\nYour password or username was \33[1mwrong\33[0m\nEnter again\n");
        printf("Username :");
        scanf("%s", username);
        printf("Password :");
        scanf("%ld", &password);
        attemp++;
        if (attemp==5)
        {
            exit(-1);
        }
        
    }
    printf("\nLogged in as Admin successfully.\n");
}

void askingBook(char purpose[], char findtitle[], char findauthor[]) {
    printf("\nEnter information of the book that you want to %s: ", purpose);
    printf("\nTitle of book: ");
    while (getchar() != '\n');
    fgets(findtitle, MAX_TITLE_LENGTH, stdin);
    findtitle[strcspn(findtitle, "\n")] = '\0';

    printf("\nAuthor of book: ");
    fgets(findauthor, MAX_AUTHOR_LENGTH, stdin);
    findauthor[strcspn(findauthor, "\n")] = '\0';
}

int searchBook(const char *ftitle, const char *fauthor, BOOK books[], int bookCount) {
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(books[i].title, ftitle) == 0 && strcmp(books[i].author, fauthor) == 0) {
            return i;
        }
    }
    return -1;
}

void addBook(BOOK books[], int bookCount) {
    if (bookCount >= MAX_BOOKS) {
        printf("No space to add more books\n");
        return;
    }
    // Clear input buffer
    printf("Enter information of the book:\n");

    while(getchar() != '\n');

    printf("Enter title of book: ");
    fgets(books[bookCount].title, MAX_TITLE_LENGTH, stdin);
    books[bookCount].title[strcspn(books[bookCount].title, "\n")] = '\0';

    printf("Enter author of book: ");
    fgets(books[bookCount].author, MAX_AUTHOR_LENGTH, stdin);
    books[bookCount].author[strcspn(books[bookCount].author, "\n")] = '\0';

    printf("Enter genre of book: ");
    fgets(books[bookCount].genre, MAX_GENRE_LENGTH, stdin);
    books[bookCount].genre[strcspn(books[bookCount].genre, "\n")] = '\0';

    printf("Enter price of book: ");
    scanf("%f", &books[bookCount].price);
    while (getchar() != '\n'); // Clear input buffer

    printf("Enter stock for sale: ");
    scanf("%d", &books[bookCount].stock_sale);
    while (getchar() != '\n'); // Clear input buffer

    printf("Enter stock for rent: ");
    scanf("%d", &books[bookCount].stock_rent);
    while (getchar() != '\n'); // Clear input buffer

    printf("Enter count of saled books : ");   //0
    scanf("%d", &books[bookCount].saled_books);
    while (getchar() != '\n'); // Clear input buffer

    printf("Enter count of rented books : ");  //0
    scanf("%d", &books[bookCount].rented_books);
    while (getchar() != '\n'); // Clear input buffer

}

void editBook(BOOK books[], int index) {
    char buffer[100];
    printf("You can edit whatever you want about this book.\n");
    printf("Enter new title of book: ");
    fgets(books[index].title, MAX_TITLE_LENGTH, stdin);
    // Remove newline character from title if present //
    if (strchr(books[index].title, '\n') != NULL) {
        books[index].title[strcspn(books[index].title, "\n")] = '\0';
    } else {
        // Clear remaining input buffer if title exceeds buffer size //
        while (fgets(buffer, sizeof(buffer), stdin) != NULL && strcmp(buffer, "\n") != 0);
    }
    printf("Enter new author of book: ");
    fgets(books[index].author, MAX_AUTHOR_LENGTH, stdin);
    // Remove newline character from author if present //
    if (strchr(books[index].author, '\n') != NULL) {
        books[index].author[strcspn(books[index].author, "\n")] = '\0';
    } else {
        // Clear remaining input buffer if author exceeds buffer size
        while (fgets(buffer, sizeof(buffer), stdin) != NULL && strcmp(buffer, "\n") != 0);
    }
    printf("Enter new genre of book: ");
    fgets(books[index].genre, MAX_GENRE_LENGTH, stdin);
    // Remove newline character from genre if present
    if (strchr(books[index].genre, '\n') != NULL) {
        books[index].genre[strcspn(books[index].genre, "\n")] = '\0';
    } else {
        // Clear remaining input buffer if genre exceeds buffer size
        while (fgets(buffer, sizeof(buffer), stdin) != NULL && strcmp(buffer, "\n") != 0);
    }

    printf("Enter new price of book: ");
    scanf("%f", &books[index].price);
    // Clear remaining input buffer after last input
    while (getchar() != '\n');
}

void removeBook(BOOK books[], int index, int *book_count_of_db) {
    for (int i = index; i < *book_count_of_db - 1; i++) {
        strcpy(books[i].title, books[i + 1].title);
        strcpy(books[i].author, books[i + 1].author);
        strcpy(books[i].genre, books[i + 1].genre);
        books[i].price = books[i + 1].price;
        books[i].stock_sale = books[i + 1].stock_sale;
        books[i].stock_rent = books[i + 1].stock_rent;
        books[i].saled_books= books[i +1 ].saled_books;
        books[i].rented_books= books[i +1 ].rented_books;
    }
    (*book_count_of_db)--;
}

void displaytoAdminBook(BOOK books[], int index) {
    printf("\nTitle: %s\n", books[index].title);
    printf("Author: %s\n", books[index].author);
    printf("Genre: %s\n", books[index].genre);
    printf("Price: %.2f\n", books[index].price);
    printf("Stock for sale: %d\n", books[index].stock_sale);
    printf("Stock for rent: %d\n", books[index].stock_rent);
    printf("Count of saled books: %d\n", books[index].saled_books);
    printf("Count of rented books: %d\n", books[index].rented_books);
}

void displaytoUserBook(BOOK books[],int index){
    printf("\nTitle: %s\n", books[index].title);
    printf("Author: %s\n", books[index].author);
    printf("Genre: %s\n", books[index].genre);
    printf("Price: %.2f\n", books[index].price);
}

void buyBook(BOOK books[], int index,USER user[],int Uindex,ADMIN admin,int *buycount,float wallet,BOUGHTBOOK BoughtBooks[], char promocode[][8]){
    char panswer[4];
    char promocodetry[8];
    int book_count=books[index].stock_sale;
    char decision[4];
    char c[4];
    printf("\nI have a offer for you, If you buy all of the stock you will get 15%% discount for all of them\n");
    printf("\nDo you want to buy all or not (yes/no).? ");
    scanf("%s",&decision);
    if (strcmp(decision,"yes")==0)
    {
        BoughtBooks[*buycount].bindex=index;
        BoughtBooks[*buycount].bookcount=books[index].stock_sale;

        printf("\nWe have %d \"%s\" books in the stock.",books[index].stock_sale,books[index].title);
            wallet-=(books[index].price * 0.15)* book_count;
            admin.wallet+=(books[index].price * 0.15)* book_count;
            books[index].saled_books=books[index].stock_sale;
            books[index].stock_sale=0;
            printf("\nYour cost will be: %.2f$.\n\33[1mTHANKS FOR CHOOSING US\33[0m\n", (books[index].price * 0.15)* book_count);
            BoughtBooks[*buycount].totalvalue=(books[index].price * 0.15)* book_count;
            (*buycount)++;

    }else{
        printf("\nHow many books do you want to purchase? ");
        scanf("%d",&book_count);
        if (book_count<=books[index].stock_sale){
                BoughtBooks[*buycount].bookcount=book_count;
                BoughtBooks[*buycount].bindex=index;
                
                wallet-=books[index].price * book_count;
                admin.wallet+=books[index].price * book_count;
                books[index].stock_sale -= book_count;
                books[index].saled_books+=book_count;
                printf("Do you have promocode (yes/no): ");
                scanf("%s",&panswer);
                if (strcmp(panswer,"yes")==0)
                {   int t=-1;
                    printf("Enter promocode (e.g:FINAL30): ");
                    scanf("%s",&promocodetry);
                    for (int i = 0; i < 3; i++)
                    {
                        if (strcmp(promocodetry,promocode[i])==0)
                        {
                            t=i;
                            break;
                        }
                    }
                    if (t==0)
                    {
                        printf("\nYou get 50%% discount");                
                        printf("\nYour cost will be: %.2f$\n\33[1mTHANKS FOR CHOOSING US\33[0m\n", books[index].price * book_count*0.5);
                        BoughtBooks[*buycount].totalvalue=books[index].price* book_count*0.5;
                    }
                    else if (t==1)
                    {
                        printf("\nYou get 20%% discount");                
                        printf("\nYour cost will be: %.2f$\n\33[1mTHANKS FOR CHOOSING US\33[0m\n", books[index].price * book_count*0.2);
                        BoughtBooks[*buycount].totalvalue=books[index].price* book_count*0.2;
                    }
                    else if (t==2)
                    {
                        printf("\nYou get 40%% discount");                
                        printf("\nYour cost will be: %.2f$\n\33[1mTHANKS FOR CHOOSING US\33[0m\n", books[index].price * book_count*0.4);
                        BoughtBooks[*buycount].totalvalue=books[index].price* book_count*0.4;
                    }
                    else{printf("\nYour promocode did not work, that is why you will not get any discount.");
                        printf("Your cost will be: %.2f$\n\33[1mTHANKS FOR CHOOSING US\33[0m\n", books[index].price * book_count);
                        BoughtBooks[*buycount].totalvalue=books[index].price* book_count;
                    }
                    
                }else{
                printf("Your cost will be: %.2f$\n\33[1mTHANKS FOR CHOOSING US\33[0m\n", books[index].price * book_count);
                BoughtBooks[*buycount].totalvalue=books[index].price* book_count;}
                (*buycount)++;
        }
            else{
                printf("\nWe have only %d copies of %s by %s in stock.\n", books[index].stock_sale, books[index].title, books[index].author);
                printf("Do you still want to buy this book (yes/no)?.. ");
                scanf("%s",&c);
                if (strcmp(c,"yes")==0)
                {
                    printf("How many do you want : ");
                    scanf("%d", &book_count);
                    if (book_count <= books[index].stock_sale){
                            BoughtBooks[*buycount].bindex=index;
                            BoughtBooks[*buycount].bookcount=book_count;

                            wallet-=books[index].price * book_count;
                            admin.wallet+=books[index].price * book_count;
                            books[index].stock_sale -= book_count;
                            books[index].saled_books+=book_count;
                            printf("Your cost will be: %.2f$\n\33[1mTHANKS FOR CHOOSING US\33[0m\n", books[index].price * book_count);
                            BoughtBooks[*buycount].totalvalue=books[index].price* book_count;
                            (*buycount)++;
                    } else {
                        printf("Sorry, we don't have enough book in stock.\n");
                    }
            
            }else{printf("\nHave a good day!\n");}
        }
    }
}

void rentBook(BOOK books[], int index) {
    int time;
    printf("\n  ------Choose time range for renting-----");
    printf("\n*    1. 1-10 days  -> 20%% of book price     *");
    printf("\n*    2. 11-20 days -> 35%% of book price    *");
    printf("\n*    3. 21-30 days -> 45%% of book price    *");
    printf("\n  -------MAX DAYS FOR RENTIN ARE 30-------");
    printf("\n\nCHOOSE (1) (2) (3) : ");
    scanf("%d",&time);
    // int d1,m1,y1;
    // printf("Enter taking date (dd/mm/yyyy): "); 
    // scanf("%d/%d/%d",&d1,&m1,&d1);
    switch (time)
    { 
    case 1:
        printf("\nYou rented %s book by %s succesfuly.", books[index].title, books[index].author);
        printf("\nYour cost will be %.2f.",books[index].price*0.20);
        books[index].rented_books+=1;
        break;
    case 2:
        printf("\nYou rented %s book by %s succesfuly.", books[index].title, books[index].author);
        printf("\nYour cost will be %.2f.",books[index].price*0.35);
        books[index].rented_books+=1;
        break;
    case 3:
        printf("\nYou rented %s book by %s succesfuly.", books[index].title, books[index].author);
        printf("\nYour cost will be %.2f.",books[index].price*0.40);
        books[index].rented_books+=1;
        break;
        
    default: 
        printf("\nInvalid choice\n");
        break;
    }
}

void giveBook(BOOK books[],int index){
    books[index].stock_rent+=1;
    srand(time(NULL));
    int book_value=50;
    int array[50]={3,1,1,1,1,2,1,1,3,1,1,2,1,1,1,1,2,1,1,1,1,2,1,1,1,1,3,2,4,1,1,1,1,2,1,1,1,1,2,1,1,3,1,1,2,1,1,1,1,3};
    int i=rand()%50;
    int damage_level=array[i];
    switch(damage_level){
    case 1:
        printf("Thanks you for your reliability!!!"); 
        break;
    case 2:
        printf("Your damaged the book. Your damage level is 2 over 4 and you have to pay a fine. Amount of fine: %.2f",(float)book_value*20/100); 
        break;
    case 3:
        printf("Your damaged the book. Your damage level is 3 over 4 and you have to pay a fine. Amount of fine: %.2f",(float)book_value*50/100);
        break;
    case 4:
        printf("Your damaged the book. Your damage level is 4 over 4 and you have to pay a fine. Amount of fine: %.2f",book_value); 
        break;}
}

void Invoice(char username[],BOOK books[],BOUGHTBOOK BoughtBooks[],int buycount){
    float total=0;
    for (int j = 0; j < buycount; j++)
    {
        total+= BoughtBooks[j].totalvalue;
    }
    printf("\n");
    printf("BILLED TO:\t%s",username);
    printf("\n");
    printf("PAY TO:\t\tLibrary");
    printf("\n\n");
    printf("----------------------------------------------\n");
    printf("NAME\t                QTY   PRICE   SUBTOTAL\n");
    printf("----------------------------------------------\n");
    for (int i = 0; i < buycount; i++){
        printf("%-25s%-5d$%-7.3f$%-20.3f\n", books[BoughtBooks[i].bindex].title, BoughtBooks[i].bookcount, BoughtBooks[i].totalvalue/BoughtBooks[i].bookcount,BoughtBooks[i].totalvalue);}
    printf("----------------------------------------------\n");
    printf("                              TOTAL"); 
    printf("   $%.3f\n", total);
    printf("----------------------------------------------\n\n");
    printf("                                    Thank You!");

}

void WriteDataBase(BOOK books[], int count) {
    FILE *pF;
    pF = fopen("DataBase.txt", "w");
    if (pF == NULL) {
        printf("File could not be opened for writing.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < count; i++) {
        fprintf(pF, "%s\n%s\n%s\n%.2f\n%d\n%d\n%d\n%d\n",
                books[i].title, books[i].author, books[i].genre,
                books[i].price, books[i].stock_sale, books[i].stock_rent,
                books[i].saled_books,books[i].rented_books);
    }
    fclose(pF);
}

void ReadDateBase(BOOK books[], int *book_count_of_db) {
    FILE *pF;
    pF = fopen("DataBase.txt", "r");
    if (pF == NULL) {
        printf("File could not be opened.\n");
        exit(EXIT_FAILURE);
    }
    rewind(pF);
    int i = 0;
    while (fscanf(pF, "%49[^\n]\n%49[^\n]\n%24[^\n]\n%f\n%d\n%d\n%d\n%d\n",
                  books[i].title, books[i].author, books[i].genre,
                  &books[i].price, &books[i].stock_sale, &books[i].stock_rent,
                  &books[i].saled_books,&books[i].rented_books) == 8){
        i++;}
    *book_count_of_db = i;
    fclose(pF);
}

void UserRDataBase(USER user[], int *Usercount) {
    FILE *pFu;
    pFu = fopen("UserDataBase.txt", "r");
    if (pFu == NULL) {
            printf("File could not be opened.");// Check file exist or we have problems with file 
            exit(EXIT_FAILURE);
        }
   rewind(pFu);
    int i=0;
    while (fscanf(pFu, "%24[^\n]\n%7[^\n]\n",user[i].username, user[i].password)==2)
    {
        i++;
    }
    *Usercount=i;
    
    fclose(pFu);
}

void UserDataBase(USER user[], int Usercount) {
    FILE *pFu;
    pFu = fopen("UserDataBase.txt","w");
    if (pFu == NULL) {
        printf("File could not be opened for writing.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < Usercount; i++){
        fprintf(pFu,"%s\n%s\n",user[i].username,user[i].password);}
    fclose(pFu); 
}

int checkLogIn(USER user[], int Usercount,char username[],float wallet) {
    char password[MAX_PW_LENGTH];
    printf("Username:");
    scanf("%24s",username);
    while (getchar() != '\n');
    printf("Password:");
    scanf("%7s",password);
    while (getchar() != '\n');
    printf("How much money you have in your balance (max: 1000): ");
    scanf("%f",&wallet);
    for (int i = 0; i < Usercount; i++)
    {
        if (strcmp(user[i].username, username) == 0 && strcmp(user[i].password, password) == 0)
        {
            return i;
        }
    }
    return -1;
}

int SignUp(USER user[], int Usercount) {
    printf("\n\tLET'S CREATE YOUR ACCOUNT");
    printf("\nEnter your username :");
    scanf("%24s", &user[Usercount].username);
    printf("\nCreate your password : ");
    scanf("%7s", &user[Usercount].password);
    printf("Your account created successfully.\n");
    return Usercount;
}

void Shelf(BOOK books[], int book_count_of_db) {
    FILE *pF;
    pF = fopen("DataBasedisplay.txt", "w");
    if (pF == NULL) {
        printf("Error: Unable to open file for writing.\n");
        exit(EXIT_FAILURE);
    }

    // Write book details to the file
    fprintf(pF,"=============================================================BOOKS INFORMATION===================================================================\n");
    fprintf(pF,"Title                                               Author                   Genre               Price         Sale Quantity        Rent Quantity\n");
    fprintf(pF,"=================================================================================================================================================\n");
    for (int i = 0; i < book_count_of_db; i++) {
        fprintf(pF, "%-51s %-24s %-19s %-13.2f %-20d %d\n",
                books[i].title, books[i].author, books[i].genre,
                books[i].price, books[i].stock_sale, books[i].stock_rent);
    }
    fclose(pF);
}

void FindMostSaledBooks(BOOK books[], int book_count_of_db, char top_books_names[][100]) {
    // Initialize indices of top 3 books to -1 (indicating no books selected yet)
    int top1 = -1, top2 = -1, top3 = -1;

    // Find the top 3 most sold books
    for (int i = 0; i < book_count_of_db; i++) {
        if (top1 == -1 || books[i].saled_books > books[top1].saled_books) {
            top3 = top2;
            top2 = top1;
            top1 = i;
        }else if (top2 == -1 || books[i].saled_books > books[top2].saled_books) {
            top3 = top2;
            top2 = i;
        }else if (top3 == -1 || books[i].saled_books > books[top3].saled_books) {
            top3 = i;
        }
    }
    // Copy the names of the top 3 books
    strcpy(top_books_names[0], books[top1].title);
    strcpy(top_books_names[1], books[top2].title);
    strcpy(top_books_names[2], books[top3].title);

    // Print the formatted output
    printf("\n\n\t\tTHE BEST SELLING BOOKS \n\n");
    printf("                      %s\n", top_books_names[0]);
    printf("   %s\n", top_books_names[1]);
    printf("                    ____________     %s\n", top_books_names[2]);
    printf("   ____________    /      1     \\  \n");
    printf("  /      2     \\  /              \\  ____________\n");
    printf(" /              \\/                \\/      3     \\\n");
    printf("/________________________________________________\\\n");    
}

void FindMostRentedBooks(BOOK books[],int book_count_of_db, char top_books_names[][100]){
    // Initialize indices of top 3 books to -1 (indicating no books selected yet)
    int top1 = -1, top2 = -1, top3 = -1;

    // Find the top 3 most sold books
    for (int i = 0; i < book_count_of_db; i++) {
        if (top1 == -1 || books[i].rented_books > books[top1].rented_books) {
            top3 = top2;
            top2 = top1;
            top1 = i;
        } else if (top2 == -1 || books[i].rented_books > books[top2].rented_books) {
            top3 = top2;
            top2 = i;
        } else if (top3 == -1 || books[i].rented_books > books[top3].rented_books) {
            top3 = i;
        }
    }

    // Copy the names of the top 3 books
    strcpy(top_books_names[0], books[top1].title);
    strcpy(top_books_names[1], books[top2].title);
    strcpy(top_books_names[2], books[top3].title);

    printf("\n\n\t\tTHE BEST RENTING BOOKS \n\n");
    printf("                      %s\n", top_books_names[0]);
    printf("   %s\n", top_books_names[1]);
    printf("                    ____________     %s\n", top_books_names[2]);
    printf("   ____________    /      1     \\  \n");
    printf("  /      2     \\  /              \\  ____________\n");
    printf(" /              \\/                \\/      3     \\\n");
    printf("/________________________________________________\\\n");
}

void DisplayShelf(BOOK books[],int book_cout_of_db){
    printf("\n\n================================================================================================================================================\n");
	printf("|                                                                 BOOKS                                                                        |\n");
    printf("================================================================================================================================================\n");
	printf("|               Title                      |          Author          |        Genre         |      Price      | Sale Quantity | Rent Quantity |\n");
    printf("================================================================================================================================================\n");
	for (int i=0; i<book_cout_of_db; i++){
		
        printf("|%-41s |%-25s |%-21s |%-16f |%-14d |%-12d   |\n",books[i].title,books[i].author,books[i].genre,books[i].price,books[i].stock_sale,books[i].stock_rent);
	printf("------------------------------------------------------------------------------------------------------------------------------------------------\n");

    }
}


#endif // SYSTEM_H
