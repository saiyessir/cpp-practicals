# UML Class Diagram

```text
+-----------------------------------+
|              Student              |
+-----------------------------------+
| + id: int                         |
| + name: string                    |
| + course: string                  |
| + marks: double                   |
+-----------------------------------+
| + calculateGrade(): char          |
+-----------------------------------+

                 1
                 |
                 | managed by
                 |
                 *
+-----------------------------------+
|         StudentManagement         |
+-----------------------------------+
| - students: vector<Student>       |
| - fileName: string                |
+-----------------------------------+
| + addStudent(Student): void       |
| + searchStudent(int): Student*    |
| + listStudents(): void            |
| + saveToFile(): void              |
| + loadFromFile(): void            |
| - findById(int): Student*         |
+-----------------------------------+
```

## Relationship
One `StudentManagement` object manages zero or more `Student` records using `std::vector<Student>`. Each `Student` object calculates its own grade. The diagram corresponds to the classes implemented in `main.cpp`.
