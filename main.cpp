/*
 * a Program that function like a library, where you can view books or magazines already added,
 * add more books or magazines, search for a books or magazines and borrow or return them.
 */

#include "LibraryItem.h"
#include "Library.h"
#include <QString>
#include <QDebug>

//Global variable used by Library.h for the path of the library_data.txt file
QString globalLibraryFilePath = "/Users/Data/library_data.txt";

QTextStream qout(stdout);
QTextStream qin(stdin);

// Display all books and magazines
void displayAllItems(){
    Library newLibrary;
    newLibrary.displayAll();
}

// Return an item by id
void returnItem(){
    QString id;
    Library newLibrary;
    qout << "Enter the id of the item you want to return: " << Qt::flush;
    qin >> id;
    newLibrary.returnItem(id);
}

// Borrow an item by id
void borrowItem(){
    QString id;
    Library newLibrary;
    qout << "Enter id of item you want to borrow: " << Qt::flush;
    qin >> id;
    newLibrary.borrowItem(id);
}

//Search for item by title
void searchLibrary(){
    QString title;
    Library newlibrary;
    qout << "Enter title of book you are looking for: " << Qt::flush;
    qin >> title;
    newlibrary.searchForItem(title);
}

//Add new Magazine
void addMagazine(){
    Library newlibrary;
    QString title, author, id, issueNumber;
    qout << "Title: " << Qt::flush;
    qin >> title;
    qout << "Author: " << Qt::flush;
    qin >> author;
    qout << "ID: ";
    qin >> id;
    qout << "Issue Number: " << Qt::flush;
    qin >> issueNumber;
    newlibrary.addMagazine(title, author, id, issueNumber);
}

//Add new Book
void addBook(){
    Library newlibrary;
    QString title, author, id, genre;
    qout << "Title: " << Qt::flush;
    qin >> title;
    qout << "Author: " << Qt::flush;
    qin >> author;
    qout << "ID: " << Qt::flush;
    qin >> id;
    qout << "Genre: " << Qt::flush;
    qin >> genre;
    newlibrary.addBook(title, author, id, genre);
}

//Main Menu interface for user to see choices
void displayMainMenu(){
    qout << "----- Main Menu -----\n";
    qout << "1. Add Book\n";
    qout << "2. Add Magazine\n";
    qout << "3. Search for Book/Magazine\n";
    qout << "4. Borrow Book/Magazine\n";
    qout << "5. Return Book/Magazine\n";
    qout << "6. Display all Books and Magazines\n";
    qout << "7. Exit\n";
    qout << "Enter your choice: " << Qt::flush;
}

//Function that maps the user choice to the correct function
void mainMenu(){
    bool menuState = true;
    int userChoice;

    while(menuState){
        displayMainMenu();
        qin >> userChoice;
        switch (userChoice) {
        case 1:
            addBook();
            break;
        case 2:
            addMagazine();
            break;
        case 3:
            searchLibrary();
            break;
        case 4:
            borrowItem();
            break;
        case 5:
            returnItem();
            break;
        case 6:
            displayAllItems();
            break;
        case 7:
            qout << "Thank you for using the Library System. Goodbye!\n";
            menuState = false;
            break;
        default:
            break;
        }
    }
}

int main()
{
    mainMenu();
    return 0;
}
