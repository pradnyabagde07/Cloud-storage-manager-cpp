#pragma once
#include <string>
#include <map>
#include <vector>

struct FileVersion {
    std::string content;
    int version;
};

struct FileEntry {
    std::string name;
    std::vector<FileVersion> versions;
    bool inTrash = false;
};

class StorageManager {
private:
    std::string currentUser;
    std::map<std::string, std::string> users; 
    std::map<std::string, std::vector<FileEntry>> userFiles;
public:
    bool signUp(const std::string &username, const std::string &password);
    bool login(const std::string &username, const std::string &password);
    void uploadFile(const std::string &filename, const std::string &content);
    void downloadFile(const std::string &filename);
    void listFiles();
    void deleteFile(const std::string &filename);
    void restoreFile(const std::string &filename);
    void searchFile(const std::string &filename);
};
