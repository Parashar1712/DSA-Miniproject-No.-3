#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Node structure representing a Book
struct BookNode {
    int bookId;
    string title;
    string author;
    string isbn;
    BookNode* left;
    BookNode* right;

    BookNode(int id, string t, string a, string i)
        : bookId(id), title(t), author(a), isbn(i), left(nullptr), right(nullptr) {}
};

class LibraryCatalog {
private:
    BookNode* root;
    int totalBooks;

    // Recursive helper for adding a book
    BookNode* insert(BookNode* node, int id, string title, string author, string isbn) {
        if (node == nullptr) {
            totalBooks++;
            return new BookNode(id, title, author, isbn);
        }
        if (id < node->bookId)
            node->left = insert(node->left, id, title, author, isbn);
        else if (id > node->bookId)
            node->right = insert(node->right, id, title, author, isbn);
        else
            cout << "Book with ID " << id << " already exists!\n";
        return node;
    }

    // Helper to find the node with the minimum value (used in deletion)
    BookNode* findMin(BookNode* node) {
        while (node && node->left != nullptr)
            node = node->left;
        return node;
    }

    // Recursive helper for deleting a book
    BookNode* remove(BookNode* node, int id) {
        if (node == nullptr) return node;

        if (id < node->bookId) {
            node->left = remove(node->left, id);
        } else if (id > node->bookId) {
            node->right = remove(node->right, id);
        } else {
            // Node found
            if (node->left == nullptr) {
                BookNode* temp = node->right;
                delete node;
                totalBooks--;
                return temp;
            } else if (node->right == nullptr) {
                BookNode* temp = node->left;
                delete node;
                totalBooks--;
                return temp;
            }
            // Node with two children: Get the inorder successor
            BookNode* temp = findMin(node->right);
            node->bookId = temp->bookId;
            node->title = temp->title;
            node->author = temp->author;
            node->isbn = temp->isbn;
            node->right = remove(node->right, temp->bookId);
        }
        return node;
    }

    // Recursive helper for search
    BookNode* search(BookNode* node, int id) {
        if (node == nullptr || node->bookId == id)
            return node;
        if (id < node->bookId)
            return search(node->left, id);
        return search(node->right, id);
    }

    // Recursive helper for inorder traversal (sorted order)
    void inorder(BookNode* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << left << setw(6) << node->bookId 
                 << setw(25) << node->title 
                 << setw(22) << node->author 
                 << node->isbn << "\n";
            inorder(node->right);
        }
    }

public:
    LibraryCatalog() : root(nullptr), totalBooks(0) {}

    void addBook(int id, string title, string author, string isbn) {
        root = insert(root, id, title, author, isbn);
    }

    void deleteBook(int id) {
        int initialCount = totalBooks;
        root = remove(root, id);
        if (initialCount == totalBooks) {
            cout << "Book ID " << id << " not found.\n";
        } else {
            cout << "Book ID " << id << " deleted successfully.\n";
        }
    }

    void searchBook(int id) {
        BookNode* result = search(root, id);
        if (result) {
            cout << "Found: " << result->title << " by " << result->author << " (ISBN: " << result->isbn << ")\n";
        } else {
            cout << "Book with ID " << id << " not found.\n";
        }
    }

    void displayBooks() {
        cout << string(68, '-') << "\n";
        cout << left << setw(6) << "ID" << setw(25) << "Title" << setw(22) << "Author" << "ISBN\n";
        cout << string(68, '-') << "\n";
        inorder(root);
        cout << string(68, '-') << "\n";
    }

    int countBooks() {
        return totalBooks;
    }
};

int main() {
    LibraryCatalog catalog;

    // 1. Adding new books to the catalog
    catalog.addBook(105, "The Great Gatsby", "F. Scott Fitzgerald", "9780743273565");
    catalog.addBook(102, "1984", "George Orwell", "9780451524935");
    catalog.addBook(108, "Mockingbird", "Harper Lee", "9780060935467");
    catalog.addBook(101, "The Hobbit", "J.R.R. Tolkien", "9780345339683");

    // 4. Displaying books in sorted order
    cout << "\n--- Library Catalog ---\n";
    catalog.displayBooks();
    
    // 5. Counting total books
    cout << "Total Books in System: " << catalog.countBooks() << "\n\n";

    // 3. Searching for books by key
    cout << "--- Searching ---\n";
    catalog.searchBook(108);
    catalog.searchBook(999);
    
    // 2. Deleting outdated or removed books
    cout << "\n--- Deleting Book ID 102 ---\n";
    catalog.deleteBook(102);
    
    cout << "\n--- Catalog After Deletion ---\n";
    catalog.displayBooks();
    cout << "Total Books in System: " << catalog.countBooks() << "\n";

    return 0;
}