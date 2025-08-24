#include "StorageManager.hpp"
#include "Utils.hpp"
#include <iostream>

bool StorageManager::signUp(const std::string &username, const std::string &password) {
    if (users.find(username) != users.end()) {
        std::cout << "User already exists.\n";
        return false;
    }
    users[username] = Utils::hashPassword(password);
    std::cout << "Sign up successful!\n";
    return true;
}

bool StorageManager::login(const std::string &username, const std::string &password) {
    auto it = users.find(username);
    if (it == users.end() || it->second != Utils::hashPassword(password)) {
        std::cout << "Invalid credentials.\n";
        return false;
    }
    currentUser = username;
    std::cout << "Login successful!\n";
    return true;
}

void StorageManager::uploadFile(const std::string &filename, const std::string &content) {
    FileVersion version = {content, 1};
    for (auto &file : userFiles[currentUser]) {
        if (file.name == filename && !file.inTrash) {
            version.version = file.versions.back().version + 1;
            file.versions.push_back(version);
            std::cout << "Uploaded new version of " << filename << "\n";
            return;
        }
    }
    FileEntry entry = {filename, {version}, false};
    userFiles[currentUser].push_back(entry);
    std::cout << "Uploaded " << filename << "\n";
}

void StorageManager::downloadFile(const std::string &filename) {
    for (auto &file : userFiles[currentUser]) {
        if (file.name == filename && !file.inTrash) {
            auto latest = file.versions.back();
            std::cout << "Downloaded " << filename << " with content: " << latest.content << "\n";
            return;
        }
    }
    std::cout << "File not found.\n";
}

void StorageManager::listFiles() {
    std::cout << "Files for " << currentUser << ":\n";
    for (auto &file : userFiles[currentUser]) {
        if (!file.inTrash) {
            std::cout << "- " << file.name << " (versions: " << file.versions.size() << ")\n";
        }
    }
}

void StorageManager::deleteFile(const std::string &filename) {
    for (auto &file : userFiles[currentUser]) {
        if (file.name == filename && !file.inTrash) {
            file.inTrash = true;
            std::cout << filename << " moved to trash.\n";
            return;
        }
    }
    std::cout << "File not found.\n";
}

void StorageManager::restoreFile(const std::string &filename) {
    for (auto &file : userFiles[currentUser]) {
        if (file.name == filename && file.inTrash) {
            file.inTrash = false;
            std::cout << filename << " restored.\n";
            return;
        }
    }
    std::cout << "File not found in trash.\n";
}

void StorageManager::searchFile(const std::string &filename) {
    for (auto &file : userFiles[currentUser]) {
        if (file.name.find(filename) != std::string::npos && !file.inTrash) {
            std::cout << "Found: " << file.name << "\n";
        }
    }
}
