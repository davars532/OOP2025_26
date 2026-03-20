//
// Created by David Arsov on 18.3.26.
//
#include <iostream>

class Library;
class LibraryMember;
using namespace std;

// Book која соджи информации за името на книгата, името на авторот и нејзината достапност.

class Book {
    char name[100];
    char author[100];
    bool available;

    friend void checkOutBook(LibraryMember &lm, Library &l, int index);

public:
    Book(char* name = "", char* author = "", bool available = false) {
        strcpy(this -> name, name);
        strcpy(this -> author, author);
        this -> available = available;
    }

    Book(const Book& b) {
        strcpy(this -> name, b.name);
        strcpy(this -> author, b.author);
        this -> available = b.available;
    }

    ~Book() {}

    char* getName() {
        return name;
    }

    char* getAuthor() {
        return author;
    }

    bool getAvailable() {
        return available;
    }

    void print() {
        cout << name << " " << author << " " << available << endl;
    }


};

// Во оваа класа се чува името на библиотеката(иницијално поставено “Braka Miladinovci”),
// низа објекти од класата Book и бројот на книги(иницијално поставен на 0).

class Library {
    char name[100];
    Book books[100];
    int numBooks;

    friend void checkOutBook(LibraryMember &lm, Library &l, int index);

public:

    Library(char *name, Book* books, int numBooks) {
        strcpy(this -> name, name);
        this -> numBooks = numBooks;

        for (int i = 0; i < numBooks; i++) {
            this -> books[i] = books[i];
        }
    }

    Library(char* name) {
        strcpy(this -> name, name);
        numBooks = 0;
    }

    Library() {
        strcpy(this -> name, "Braka Miladinovci");
        numBooks = 0;
    }

    Library(const Library& l) {
        strcpy(this -> name, l.name);
        for (int i = 0; i < l.numBooks; i++) {
            this -> books[i] = l.books[i];
        }
        this -> numBooks = l.numBooks;
    }

    // За оваа класа да се дефинира метод addBook кој додава книга во низата книги и
    // метод за печатење на сите информации за библиотеката.

    void addBook(const Book &book) {
        if (numBooks != 100) {
            books[numBooks] = book;
            numBooks++;
        } else {
            cout << "Nizata so knigi e polna!" << endl;
        }
    }

    void print() {
        cout << "Ime: " << name << endl;
        cout << "Broj na knigi: " << numBooks << endl;
        cout << "Dostapni knigi: " << endl;
        for (int i = 0; i < numBooks; i++) {
            books[i].print();
        }
    }
};

// Да се дефинира и трета класа LibraryMember во која се чуваат информации за име и
// идентификациски број, за членот во библиотеката. Да се обезбедат соодветни конструктори,
// деструктори, set и get методи доколку се потребни.

class LibraryMember {
    char name[100];
    int id;

    static int idGenerator;

friend void checkOutBook(LibraryMember &lm, Library &l, int index);
public:
    LibraryMember(char *name = "") {
        strcpy(this -> name, name);
        this -> id = idGenerator;
        idGenerator++;
    }

    LibraryMember(const LibraryMember& l) {
        strcpy(this -> name, l.name);
        this -> id = l.id;
    }

    ~LibraryMember() {}

    void print() {
        cout << "Ime: " << name << "Id: " << id << endl;
    }
};

void checkOutBook(LibraryMember &lm, Library &l, int index) {
    if (l.books[index].available) {
        cout << "Korisnikot " << lm.name << " uspesno ja pozajmil knigata ";
        l.books[index].print();
        l.books[index].available = false;
    } else {
        cout << "Knigata ne e dostapna";
    }
}

int LibraryMember::idGenerator = 0;

int main() {

    // Во главната програма да се направи еден објект од класата Library, да се внесат
    // информации за најмногу 30 книги и истите да се додадат во библиотеката. Потоа да се
    // испечатат информациите за библиотеката. Да се креира и еден член на библиотеката и
    // дополнително да се внесе редниот број на книгата што сака да ја позајми. Да се провери
    // дали таа книга е достапна.

    Library l("TestLib");

    for (int i = 0; i < 30; i++) {
        Book b("Book", "Author", i % 3 == 0);
        cout << "Vnesena kniga: " << endl;
        b.print();
        l.addBook(b);
    }

    l.print();

    LibraryMember lm("TestMemeber0");
    lm.print();

    LibraryMember lm2("TestMemeber1");
    lm2.print();

    LibraryMember lm3("TestMemeber2");
    lm3.print();

    LibraryMember lm4("TestMemeber3");
    lm4.print();

    checkOutBook(lm, l, 9);
    return 0;
}