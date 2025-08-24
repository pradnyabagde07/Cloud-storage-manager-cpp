A **menu-driven cloud storage simulation** built with **C++17**.  
It provides **file upload/download, version control, search, sharing, and quota management** in a simulated environment.

---

## 📌 Features
- 🔑 **User Authentication** – Sign up / Login system  
- 📂 **File Operations** – Upload, Download, Delete, Restore, List files  
- 🔍 **Search** – Search files by name  
- 🕒 **Version Control** – Tracks file versions  
- 🗑️ **Trash & Restore** – Recover deleted files  
- 🔗 **Share via Token** – Simulated file sharing system  
- 📏 **Quota Management** – Storage limit per user  
- 🖥️ **Interactive Menu** – Easy-to-use CLI interface  

---

## 🛠️ Tech Stack
- **Language:** C++17  
- **Build System:** CMake  
- **Concepts:** File I/O, OOP, Data Structures, Exception Handling  

---

## ⚙️ Installation & Build
Clone the repository and build using **CMake**:

```bash
# Clone repo
git clone https://github.com/your-username/cloud-storage-manager-cpp.git
cd cloud-storage-manager-cpp

# Build project
cmake -S . -B build
cmake --build build

📂 Project Structure
cloud-storage-manager-cpp/
│── CMakeLists.txt        # Build configuration
│── README.md             # Project documentation
│── include/              # Header files
│   ├── StorageManager.h
│   ├── Utils.h
│   └── ...
│── src/                  # Source files
│   ├── main.cpp          # Entry point
│   ├── StorageManager.cpp
│   ├── Utils.cpp
│   └── ...
│── data/                 # Simulated storage (init at runtime)
│   ├── users/            # User accounts
│   ├── files/            # Uploaded files
│   └── trash/            # Deleted files


# Run
./build/cloud_storage
