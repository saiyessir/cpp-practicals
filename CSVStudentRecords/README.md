# Practical 11 – CSV Reader/Writer Using fstream

## Aim
To practise persistent storage, structured records, file modes, and file-position operations.

## CSV format
The program uses a simple comma-separated format with one record per line:

`ID,Name,Marks`

Names in this demonstration do not contain commas. The CSV file stores text values, not raw C++ struct bytes, so the format is readable and portable.

## Program description
1. Writes a header and three student records to `students.csv` using `std::ofstream`.
2. Checks whether the file opens and whether writing succeeds.
3. Reads the CSV file using `std::ifstream`, parses each row, and displays the records.
4. Skips malformed rows and reports them.
5. Demonstrates file-position operations separately on `position_demo.txt`.

## File-position functions
- **tellg():** Returns the current get position, which is used for reading.
- **seekg():** Moves the get position to a specified location.
- **tellp():** Returns the current put position, which is used for writing.
- **seekp():** Moves the put position to a specified location.

The get position controls where the next input operation reads. The put position controls where the next output operation writes.

## Position demonstration
The program initially creates `position_demo.txt` containing `ABCDE`.
- `tellg()` at the start reports position 0.
- After reading two characters, `tellg()` reports position 2.
- `seekg(3)` moves to position 3, where the character `D` is read.
- `tellp()` at the end reports position 5.
- `seekp(2)` moves the write position to 2; writing `X` changes the file to `ABXDE`.

## Compile and run
Using g++ with C++17:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o csv_demo
./csv_demo
```

Run the program from the folder containing `main.cpp`. It creates or replaces `students.csv` and `position_demo.txt` in the current working directory.

## Expected output
See [sample-output.txt](sample-output.txt).

## Result
Thus, I successfully implemented CSV file writing and reading using C++ file streams. I also demonstrated `seekg()`, `tellg()`, `seekp()`, and `tellp()), and understood the difference between read and write positions.
