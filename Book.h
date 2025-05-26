#ifndef BOOK_H
#define BOOK_H

#include "LibraryItem.h"
#include <QDebug>
#include <QString>

/*
 * Book.h
 * This file defines the Book class, which inherits form LibraryItem.
 * A Book has additional information such as genre, in iddition to title, author, and ID.
 */

// Class for creating and managing Book objects in the Library system
class Book : public LibraryItem
{
    QString genre; // Genre of the book (e.g., Fantacy, History)
public:
    /*
     * Constructor for the Book class.
     * newTitle - Title of the book.
     * newAuthor - Author of the book.
     * newID - Unique ID of the book.
     * newGenre - Genre of the book.
     */
    Book(QString newTitle, QString newAuthor, QString newID, QString newGenre)
        : LibraryItem(newTitle, newAuthor, newID), genre(newGenre) {}

    // Sets a new genre for the book.
    void setGenre(QString newGenre){
        genre = newGenre;
    }

    // Returns the genre of the book.
    QString getGenre(){
        return genre;
    }

    // Displays detailed information about the book.
    void displayInfo() override {
        qout << "Book Title: " << getTitle()
             << ", Author: " << getAuthor()
             << ", ID: " << getID()
             << ", Genre: " << getGenre() << '\n';
    }
};

#endif // BOOK_H
