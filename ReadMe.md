# Library Management System

## Overview
The Library Management System is a C language project developed by Bayram Aliyev, Fazil Behbudov, and Ughur Mammadov. This system is designed to help manage library operations such as book lending, returning, and inventory management.

## Description

The Library Management System allows users to interact with the library's database through a simple command-line interface. Upon starting the program, users are prompted to log in as either an **Admin** or a **Regular User**. 

### Admin Access
Admins have full control over the library system and can perform the following actions:
1. **Show Books**: View a list of all books currently in the library's inventory.
2. **Entry of New Book**: Add new books to the library's collection, including details such as title, author, genre, and ISBN.
3. **Edit Details of Book**: Modify the information of existing books, such as updating the title, author, or availability status.
4. **Remove a Book from Shelf**: Delete books from the inventory that are no longer available or needed.
5. **Retrieve Book Information**: Access detailed information about a specific book, including its borrowing history and current status.
6. **Report**: Generate reports on various aspects of the library, such as lending statistics, popular books, or overdue items.
7. **Save and Go Back to Previous Menu**: Save any changes made and return to the previous menu for further actions.

### Regular User Access
Regular users can perform the following operations:
1. **Show Available Books**: View a list of all books currently available in the library.
2. **Search for a Book**: Search for specific books by title, author, or genre.
3. **Purchase a Book**: Buy a book from the library's inventory.
4. **Rent a Book**: Rent a book for a specified period.
5. **Give Back a Book**: Return a rented book and update the inventory accordingly.
6. **Exit and Display Invoice**: Exit the program and display an invoice for any purchases or rentals made during the session.


This dual-access system ensures that sensitive operations are restricted to authorized personnel while allowing regular users to interact with the library's resources effectively.

## Features
- **User  Management**: Add, remove, and update user information.
- **Book Management**: Add, remove, and update book details.
- **Lending System**: Track which books are lent out and to whom.
- **Return System**: Manage the return of books and update inventory.
- **Search Functionality**: Search for books and users easily.

## Project Background
This project was developed as my first-year final project at university, allowing me to apply my programming skills in C and gain practical experience in software development. It has been a valuable learning experience, and I hope it serves as a useful tool for managing library operations.      