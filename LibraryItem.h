#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H
#include <QString>
#include <QTextStream>

/*
 * LibraryItem.h
 * This file defines the abstract base class LibraryItem, which serves as a
 * common interface for all items in the library system (e.g., books, magazines).
 * It stores basic metadata such as title, author, and ID, and tracks borrow status.
 * Derived classes must implement the displayInfo() method.
 */

// Global QTextStreams for input/output (commonly used in Qt console applications)
extern QTextStream qout;
extern QTextStream qin;

// Abstract base class representing a generic library item
class LibraryItem
{
    QString title;      //Title of the item
    QString author;     //Author of the item
    QString id;         //ID of the item
    bool isBorrowed;    // Indicated whether the item is currently borrowed

public:
    /*
     * Constructor for initializing a LibraryItem with title, author, and ID.
     * The item is marked as not borrowed by default.
     */
    LibraryItem(QString newTitle, QString newAuthor, QString newID)
        : title(newTitle), author(newAuthor), id(newID), isBorrowed(false) {}

    // Virtual destructor for proper cleanup in derived classes
    virtual ~LibraryItem() {}

    // Setters and getters for item metadata
    void setTitle(QString newTitle){
        title = newTitle;
    }

    QString getTitle(){
        return title;
    }

    void setAuthor(QString newAuthor){
        author = newAuthor;
    }

    QString getAuthor(){
        return author;
    }

    void setID(QString newID){
        id = newID;
    }

    QString getID(){
        return id;
    }

    // Set or get the borrow state of the item
    void setBorrowedState(bool state){
        isBorrowed = state;
    }
    bool getBorrowedState() const{
        return isBorrowed;
    }

    /*
     * Pure virtual function that must be implemented by derived classes
     * to display item-specific information.
     */
    virtual void displayInfo() = 0;
};
#endif // LIBRARYITEM_H
