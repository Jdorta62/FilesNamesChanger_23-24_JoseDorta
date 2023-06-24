#include <iostream>
#include <filesystem>
#include <string>

int main() {
    const std::string folderPath = "C:\\Users\\zenit\\Documents\\UDRambla";

    for (const auto& entry : std::filesystem::directory_iterator(folderPath)) {
        if (std::filesystem::is_regular_file(entry)) {
            std::cout << entry.path().filename() << std::endl;
        }
    }

    return 0;
}