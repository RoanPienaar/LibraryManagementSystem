#ifndef LIBRARY_H
#define LIBRARY_H
#include "LibraryItem.h"
#include "Book.h"
#include "Magazine.h"
#include <QVector>
#include <QFile>
#include <QString>
#include <QDebug>

using std::vector;

// Global variable that stores the file path for persistent library data
extern QString globalLibraryFilePath;

/*
 * Library class
 * Manages a collection of LibraryItem objects (Books and Magazines).
 * Supports adding, searching, borrowing, returning items, and saving/loading from a file.
 */
class Library
{
    QVector<LibraryItem*> items;    // Container for all library items

public:
    // Constructor loads existing library data from file on initialization
    Library() {
        loadData();
    }

    // Destructor ensures proper cleanup of dynamically allocated memory
    ~Library() {
        for (auto& item : items) {
            delete item;
        }
    }

    /*
     * Loads library data from a file defined by globalLibraryFilePath.
     * Creates Book or Magazine objects based on the data and adds them to the collection.
     */
    void loadData(){
        QString type, title, author, id, issueNumber, genre, isBorrowed;
        QFile file(globalLibraryFilePath);
        if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
            QTextStream in(&file);
            while(!in.atEnd()){
                type = in.readLine();
                title = in.readLine();
                author = in.readLine();
                id = in.readLine();
                if(type == "Book"){
                    genre = in.readLine();
                    isBorrowed = in.readLine();
                    Book* book = new Book(title, author, id, genre);
                    book->setBorrowedState(isBorrowed == "1");
                    items.push_back(book);
                }
                if(type == "Magazine"){
                    issueNumber = in.readLine();
                    isBorrowed = in.readLine();
                    Magazine* magazine = new Magazine(title, author, id, issueNumber);
                    magazine->setBorrowedState(isBorrowed == "1");
                    items.push_back(magazine);
                }
            }
            file.close();
        }

        else
            qout << "Error opening file for reading\n";
    }

    /*
     * Saves the current state of the library to the file defined by globalLibraryFilePath.
     * Serializes both Books and Magazines to a plain-text format.
     */
    void saveData(){
        QFile file(globalLibraryFilePath);
        if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
            QTextStream out(&file);
            for(auto& item : items){
                if(Book* book = dynamic_cast<Book*>(item)){
                    out << "Book\n" << book->getTitle() << '\n' << book->getAuthor() << '\n' << book->getID()
                        << '\n' << book->getGenre() << '\n' << (book->getBorrowedState() ? "1" : "0") << '\n';
                }
                if(Magazine* magazine = dynamic_cast<Magazine*>(item)){
                    out << "Magazine\n" << magazine->getTitle() << '\n' << magazine->getAuthor() << '\n'
                        << magazine->getID() << '\n' << magazine->getIssueNumber() << '\n' << (magazine->getBorrowedState() ? "1" : "0") << '\n';
                }
            }
        }
        else
            qout << "Error opening file for writing\n";
    }

    /*
     * Adds a new Book to the library.
     * Automatically saves the updated library to file.
     */
    void addBook(QString title, QString author, QString id, QString genre){
        items.push_back(new Book(title, author, id, genre));
        saveData();
        qout << "Book added successfully.\n";
    }

    /*
     * Adds a new Magazine to the library.
     * Automatically saves the updated library to file.
     */
    void addMagazine(QString title, QString author, QString id, QString issueNumber){
        items.push_back(new Magazine(title, author, id, issueNumber));
        saveData();
        qout << "Magazine added successfully.\n";
    }

    /*
     * Searches for items with a title containing the given string (case-insensitive).
     * Displays all matching items.
     */
    void searchForItem(QString title){
        bool found = false;
        for(auto& item : items){
            if(item->getTitle().contains(title, Qt::CaseInsensitive)){
                item->displayInfo();
                found = true;
            }
        }
        if(!found)
            qout << "\n*No such title found*\n\n";
    }

    /*
     * Attempts to borrow an item by its ID.
     * Updates borrow state and saves changes to file.
     */
    void borrowItem(QString id){
        for(auto& item : items){
            if(item->getID() == id){
                if(item->getBorrowedState()){
                    qout << "Item already borrowed\n";
                }
                else{
                    item->setBorrowedState(true);
                    qout << item->getTitle() << " has successfully been borrowed\n";
                    saveData();
                }
                return;
            }
        }
        qout << "\n*No such item found to borrow*\n\n";
    }

    /*
     * Attempts to return an item by its ID.
     * Updates borrow state and saves changes to file.
     */
    void returnItem(QString id){
        for(auto& item : items){
            if(item->getID() == id){
                if(item->getBorrowedState()){
                    item->setBorrowedState(false);
                    qout << item->getTitle() << " was successfully returned\n";
                    saveData();
                }
                else
                    qout << item->getTitle() << " has not been borrowed\n";

                return;
            }
        }
        qout << "\n*No such item found to return*\n\n";
    }

    /*
     * Displays all items currently in the library.
     * If no items exist, notifies the user.
     */
    void displayAll(){
        if(items.isEmpty()){
            qout << "Library is empty.\n";
            return;
        }
        for(auto& item : items){
            item->displayInfo();
        }
    }
};

#endif // LIBRARY_H
