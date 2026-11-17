#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct Student {
    int id;
    std::string name;
    double marks;
};

int main() {
    const std::string csvFile = "students.csv";

    // Write three student records in CSV format: ID,Name,Marks
    std::ofstream outFile(csvFile);
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open " << csvFile << " for writing.\n";
        return 1;
    }

    outFile << "ID,Name,Marks\n";
    outFile << "101,Aarav,85.5\n";
    outFile << "102,Diya,91.0\n";
    outFile << "103,Rohan,78.5\n";
    outFile.close();

    if (!outFile) {
        std::cerr << "Error: Writing to " << csvFile << " failed.\n";
        return 1;
    }

    std::cout << "Student records written to " << csvFile << ".\n";

    // Read the CSV records back.
    std::ifstream inFile(csvFile);
    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open " << csvFile << " for reading.\n";
        return 1;
    }

    std::string line;
    std::getline(inFile, line); // Skip the header row.

    std::cout << "\nSTUDENT RECORDS\n";
    std::cout << "ID\tName\tMarks\n";

    while (std::getline(inFile, line)) {
        std::stringstream row(line);
        std::string idText, name, marksText;

        if (!std::getline(row, idText, ',') ||
            !std::getline(row, name, ',') ||
            !std::getline(row, marksText, ',')) {
            std::cout << "Skipping malformed row: " << line << '\n';
            continue;
        }

        try {
            Student student{
                std::stoi(idText),
                name,
                std::stod(marksText)
            };
            std::cout << student.id << '\t' << student.name
                      << '\t' << student.marks << '\n';
        } catch (const std::exception&) {
            std::cout << "Skipping malformed row: " << line << '\n';
        }
    }
    inFile.close();

    // Demonstrate get-position functions on a separate simple text file.
    const std::string positionFile = "position_demo.txt";
    {
        std::ofstream createFile(positionFile);
        if (!createFile) {
            std::cerr << "Error: Could not create " << positionFile << ".\n";
            return 1;
        }
        createFile << "ABCDE";
    }

    std::fstream positionStream(positionFile, std::ios::in | std::ios::out);
    if (!positionStream) {
        std::cerr << "Error: Could not open " << positionFile << ".\n";
        return 1;
    }

    std::cout << "\nFILE POSITION DEMONSTRATION\n";

    // tellg() reports the current get (read) position; seekg() changes it.
    positionStream.seekg(0, std::ios::beg);
    std::cout << "tellg() at start: " << positionStream.tellg() << '\n';

    char firstTwo[3] = {};
    positionStream.read(firstTwo, 2);
    std::cout << "Read characters: " << firstTwo << '\n';
    std::cout << "tellg() after reading 2 characters: "
              << positionStream.tellg() << '\n';

    positionStream.seekg(3, std::ios::beg);
    std::cout << "tellg() after seekg(3): " << positionStream.tellg() << '\n';
    char selected = '\0';
    positionStream.get(selected);
    std::cout << "Character read at position 3: " << selected << '\n';

    // tellp() reports the current put (write) position; seekp() changes it.
    positionStream.clear();
    positionStream.seekp(0, std::ios::end);
    std::cout << "tellp() at end: " << positionStream.tellp() << '\n';

    positionStream.seekp(2, std::ios::beg);
    std::cout << "tellp() after seekp(2): " << positionStream.tellp() << '\n';
    positionStream.put('X');
    std::cout << "tellp() after writing one character: "
              << positionStream.tellp() << '\n';
    positionStream.close();

    std::cout << "Updated position_demo.txt content: ABXDE\n";
    return 0;
}
