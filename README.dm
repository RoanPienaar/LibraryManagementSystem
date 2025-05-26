# Library Management System

This is a simple console-based Library Management System built using C++ and Qt. It allows users to add, view, search, borrow, and return books and magazines. All library data is saved in a persistent text file.

---

## ✅ Requirements

- **Operating System**: macOS, Windows, or Linux
- **Qt Version**: Qt 5 or Qt 6 (Tested with Qt Creator)
- **Build Tool**: Qt Creator (recommended)

---

## ⚙️ Setup Instructions

1. **Download the Source Code**:
   - Clone this repository or download the ZIP and extract it.

2. **Copy the Data File**:
   - Copy `library_data.txt` to your desired documents folder.

3. **Set File Path in Code**:
   - Open `main.cpp`
   - Find this line:
     ```cpp
     QString globalLibraryFilePath = "/Users/Data/library_data.txt";
     ```
   - Change the path to match where you placed the file, e.g.:
     ```cpp
     QString globalLibraryFilePath = "/home/yourname/Documents/library_data.txt";
     ```

4. **Open the Project in Qt Creator**:
   - Go to **File → Open Project**
   - Select the folder containing your `.cpp` and `.h` files
   - Ensure all files are added to the project

---

## 🚀 Features

- ✅ Add a Book or Magazine
- 🔍 Search for a title
- 📚 View all library items
- 📖 Borrow or return an item using its ID
- 💾 All data is saved to and loaded from a `.txt` file

---

## 📁 Data Format (library_data.txt)

Each item is stored as plain text in this format:

For books:
```txt
Book
Title
Author
ID
Genre
BorrowedState (1 = borrowed, 0 = available)


For magazines:
```txt
Book
Title
Author
ID
IssueNumber
BorrowedState (1 = borrowed, 0 = available)



---

## 🪪 License

This project is licensed under the [MIT License](LICENSE).

---

## 👨‍💻 Author

Created by [Roan Pienaar].  
Feel free to fork, star, or suggest improvements!

