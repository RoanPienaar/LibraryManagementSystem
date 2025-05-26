#ifndef MAGAZINE_H
#define MAGAZINE_H
#include "LibraryItem.h"
#include <QString>
#include <QDebug>

/*
 * Magazine.h
 * This file defines the Magazine class, which inherits form LibraryItem.
 * A Magazine has additional information such as Issue Number, in iddition to title, author, and ID.
 */

// Class for creating and managing Book objects in the Library system
class Magazine : public LibraryItem
{
    QString issueNumber;// Issue Number of the book (e.g., B001, B002, M001)
public:
    /*
     * Constructor for the Magazine class.
     * newTitle - Title of the book.
     * newAuthor - Author of the book.
     * newID - Unique ID of the book.
     * newIssueNumber - Issue Number of the book.
     */
    Magazine(QString newTitle, QString newAuthor, QString newID, QString newIssueNumber)
        : LibraryItem(newTitle, newAuthor, newID), issueNumber(newIssueNumber)  {}

    // Sets a new issue number for the magazine.
    void setIssueNumber(QString newIssueNumber){
        issueNumber = newIssueNumber;
    }

    // Returns the issue number of the magazine.
    QString getIssueNumber(){
        return issueNumber;
    }

    // Displays detailed information about the magazine.
    void displayInfo() override {
        qout << "Magazine Title: " << getTitle()
             << ", Author: " << getAuthor()
             << ", ID: " << getID()
             << ", Issue Number: " << getIssueNumber() << '\n';
    }
};

#endif // MAGAZINE_H
