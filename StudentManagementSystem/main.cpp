#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <utility>

struct Student {
    int id{};
    std::string name;
    std::string course;
    double marks{};

    char calculateGrade() const {
        if (marks >= 90) return 'A';
        if (marks >= 80) return 'B';
        if (marks >= 70) return 'C';
        if (marks >= 60) return 'D';
        return 'F';
    }
};

class StudentManagement {
private:
    std::vector<Student> students;
    const std::string fileName = "students.csv";

    static bool isValidText(const std::string& value) {
        return !value.empty() && value.find(',') == std::string::npos;
    }

    Student* findById(int id) {
        auto it = std::find_if(students.begin(), students.end(),
            [id](const Student& student) { return student.id == id; });
        return it == students.end() ? nullptr : &(*it);
    }

public:
    void addStudent(const Student& student) {
        if (student.id <= 0) {
            throw std::invalid_argument("Student ID must be a positive number.");
        }
        if (!isValidText(student.name) || !isValidText(student.course)) {
            throw std::invalid_argument("Name and course must be non-empty and cannot contain commas.");
        }
        if (student.marks < 0 || student.marks > 100) {
            throw std::invalid_argument("Marks must be between 0 and 100.");
        }
        if (findById(student.id) != nullptr) {
            throw std::invalid_argument("A student with this ID already exists.");
        }
        students.push_back(student);
    }

    const Student* searchStudent(int id) const {
        auto it = std::find_if(students.begin(), students.end(),
            [id](const Student& student) { return student.id == id; });
        return it == students.end() ? nullptr : &(*it);
    }

    void listStudents() const {
        if (students.empty()) {
            std::cout << "No student records found.\n";
            return;
        }

        std::cout << std::left << std::setw(10) << "ID"
                  << std::setw(22) << "Name"
                  << std::setw(20) << "Course"
                  << std::setw(10) << "Marks" << "Grade\n";
        std::cout << std::string(67, '-') << '\n';

        for (const Student& student : students) {
            std::cout << std::left << std::setw(10) << student.id
                      << std::setw(22) << student.name
                      << std::setw(20) << student.course
                      << std::setw(10) << std::fixed << std::setprecision(1)
                      << student.marks << student.calculateGrade() << '\n';
        }
    }

    void saveToFile() const {
        std::ofstream outFile(fileName);
        if (!outFile) {
            throw std::runtime_error("Could not open " + fileName + " for writing.");
        }

        outFile << "ID,Name,Course,Marks\n";
        for (const Student& student : students) {
            outFile << student.id << ',' << student.name << ','
                    << student.course << ',' << student.marks << '\n';
        }
        outFile.close();

        if (!outFile) {
            throw std::runtime_error("An error occurred while saving student records.");
        }
    }

    void loadFromFile() {
        std::ifstream inFile(fileName);
        if (!inFile) {
            // A missing file is normal on the first run; start with an empty list.
            std::cout << "No existing " << fileName
                      << " found. Starting with an empty record list.\n";
            return;
        }

        std::vector<Student> loadedStudents;
        std::string line;
        std::getline(inFile, line); // Skip CSV header.

        int lineNumber = 1;
        while (std::getline(inFile, line)) {
            ++lineNumber;
            if (line.empty()) continue;

            std::stringstream row(line);
            std::string idText, name, course, marksText, extra;

            if (!std::getline(row, idText, ',') ||
                !std::getline(row, name, ',') ||
                !std::getline(row, course, ',') ||
                !std::getline(row, marksText, ',') ||
                std::getline(row, extra, ',')) {
                std::cerr << "Skipping malformed CSV row " << lineNumber << ".\n";
                continue;
            }

            try {
                std::size_t idUsed = 0;
                std::size_t marksUsed = 0;
                int id = std::stoi(idText, &idUsed);
                double marks = std::stod(marksText, &marksUsed);

                if (idUsed != idText.size() || marksUsed != marksText.size()) {
                    throw std::invalid_argument("Invalid numeric field.");
                }

                Student student{id, name, course, marks};
                if (id <= 0 || !isValidText(name) || !isValidText(course) ||
                    marks < 0 || marks > 100) {
                    throw std::invalid_argument("Record values are outside valid limits.");
                }

                const bool duplicate = std::any_of(
                    loadedStudents.begin(), loadedStudents.end(),
                    [id](const Student& existing) { return existing.id == id; });
                if (duplicate) {
                    throw std::invalid_argument("Duplicate student ID.");
                }

                loadedStudents.push_back(student);
            } catch (const std::exception&) {
                std::cerr << "Skipping invalid CSV row " << lineNumber << ".\n";
            }
        }

        if (inFile.bad()) {
            throw std::runtime_error("An error occurred while reading " + fileName + ".");
        }

        students = std::move(loadedStudents);
        std::cout << students.size() << " student record(s) loaded.\n";
    }
};

int main() {
    StudentManagement manager;

    try {
        manager.loadFromFile();
    } catch (const std::exception& error) {
        std::cerr << "Load error: " << error.what() << '\n';
        return 1;
    }

    int choice = 0;
    do {
        std::cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n"
                  << "1. Add student\n"
                  << "2. Search student by ID\n"
                  << "3. List all students\n"
                  << "4. Save records\n"
                  << "5. Exit\n"
                  << "Enter your choice: ";

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Please enter a valid menu number.\n";
            continue;
        }

        try {
            if (choice == 1) {
                Student student;
                std::cout << "Enter student ID: ";
                if (!(std::cin >> student.id)) throw std::invalid_argument("ID must be a number.");
                std::cin.ignore(10000, '\n');

                std::cout << "Enter student name (no commas): ";
                std::getline(std::cin, student.name);
                std::cout << "Enter course (no commas): ";
                std::getline(std::cin, student.course);
                std::cout << "Enter marks (0-100): ";
                if (!(std::cin >> student.marks)) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    throw std::invalid_argument("Marks must be a number.");
                }

                manager.addStudent(student);
                std::cout << "Student added successfully.\n";
            } else if (choice == 2) {
                int id;
                std::cout << "Enter student ID to search: ";
                if (!(std::cin >> id)) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    throw std::invalid_argument("ID must be a number.");
                }

                const Student* student = manager.searchStudent(id);
                if (student) {
                    std::cout << "Record found: " << student->id << " | "
                              << student->name << " | " << student->course
                              << " | " << student->marks << " | Grade: "
                              << student->calculateGrade() << '\n';
                } else {
                    std::cout << "No student found with ID " << id << ".\n";
                }
            } else if (choice == 3) {
                manager.listStudents();
            } else if (choice == 4) {
                manager.saveToFile();
                std::cout << "Records saved to students.csv.\n";
            } else if (choice == 5) {
                manager.saveToFile();
                std::cout << "Records saved. Goodbye!\n";
            } else {
                std::cout << "Please choose a number from 1 to 5.\n";
            }
        } catch (const std::exception& error) {
            std::cout << "Error: " << error.what() << '\n';
        }
    } while (choice != 5);

    return 0;
}
