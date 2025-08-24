#include "StorageManager.hpp"
#include <iostream>

int main() {
    StorageManager manager;
    int choice;
    std::string username, password, filename, content;

    while (true) {
        std::cout << "\n1. Sign Up\n2. Login\n3. Upload File\n4. Download File\n5. List Files\n6. Delete File\n7. Restore File\n8. Search File\n9. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter username: ";
                std::cin >> username;
                std::cout << "Enter password: ";
                std::cin >> password;
                manager.signUp(username, password);
                break;
            case 2:
                std::cout << "Enter username: ";
                std::cin >> username;
                std::cout << "Enter password: ";
                std::cin >> password;
                manager.login(username, password);
                break;
            case 3:
                std::cout << "Enter filename: ";
                std::cin >> filename;
                std::cout << "Enter content: ";
                std::cin.ignore();
                std::getline(std::cin, content);
                manager.uploadFile(filename, content);
                break;
            case 4:
                std::cout << "Enter filename: ";
                std::cin >> filename;
                manager.downloadFile(filename);
                break;
            case 5:
                manager.listFiles();
                break;
            case 6:
                std::cout << "Enter filename: ";
                std::cin >> filename;
                manager.deleteFile(filename);
                break;
            case 7:
                std::cout << "Enter filename: ";
                std::cin >> filename;
                manager.restoreFile(filename);
                break;
            case 8:
                std::cout << "Enter search query: ";
                std::cin >> filename;
                manager.searchFile(filename);
                break;
            case 9:
                return 0;
            default:
                std::cout << "Invalid choice.\n";
        }
    }
}
