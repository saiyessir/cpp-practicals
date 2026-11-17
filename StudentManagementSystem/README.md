# Student Management System (C++)

## Project overview
A menu-driven C++ application to manage student records. It stores each student's ID, name, course, and marks, calculates a grade, and saves/reloads records using a CSV file.

## Features
- Add student records.
- Validate positive, unique student IDs.
- Validate marks from 0 to 100.
- Search for a student by ID.
- List all students with their calculated grades.
- Save records to `students.csv` and reload them at startup.
- Handle invalid input, duplicate IDs, and file errors with exceptions.
- Skip malformed or invalid rows when loading a CSV file.

## Grade scale
| Marks | Grade |
|---|---|
| 90–100 | A |
| 80–89.9 | B |
| 70–79.9 | C |
| 60–69.9 | D |
| Below 60 | F |

## CSV format
The file uses this header and one record per line:

`ID,Name,Course,Marks`

For simplicity, names and course names must not contain commas. The file stores text fields rather than raw C++ struct bytes.

## Classes and STL
- `Student` stores one student's details and provides `calculateGrade()`.
- `StudentManagement` manages the collection and application operations.
- `std::vector<Student>` stores records dynamically.
- STL algorithms `std::find_if` and `std::any_of` are used to search and check duplicate IDs.
- `std::ifstream` and `std::ofstream` read and write CSV records.
- `std::invalid_argument` and `std::runtime_error` report invalid data and file failures.

## UML class diagram
See [UML.md](UML.md).

## Compile and run
Requires a C++17 compiler such as g++.

Linux/macOS:
```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o student_manager
./student_manager
```

Windows (MinGW):
```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o student_manager.exe
student_manager.exe
```

Run the program from the folder containing `students.csv`. If the CSV file is missing, the program starts with an empty list. Use menu option 4 to save records.

## Sample data and output
- Sample input data: [students.csv](students.csv)
- Example console session: [sample-output.txt](sample-output.txt)

The sample output is illustrative; run the program to capture your own execution evidence.
