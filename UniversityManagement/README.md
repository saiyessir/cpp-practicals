# University Management Using Inheritance

## AIM
To understand base and derived classes and how data and behaviour can be reused through inheritance.

## Class relationship diagram

```text
+------------------+
|      Person      |
|------------------|
| # name           |
| # age            |
| + displayPerson()|
+------------------+
         |
         | public inheritance
         v
+----------------------+
|       Student        |
|----------------------|
| # studentID          |
| # course             |
| + displayStudent()   |
+----------------------+
         |
         | public inheritance
         v
+-----------------------------+
|       GraduateStudent       |
|-----------------------------|
| - researchTopic             |
| - supervisor                |
| + displayGraduateStudent()  |
+-----------------------------+
```

## Inheritance explained
- **Person → Student:** Single inheritance. Student derives directly from Person.
- **Person → Student → GraduateStudent:** Multilevel inheritance. GraduateStudent derives from Student, which derives from Person.
- The `protected` members `name` and `age` are accessible inside Student and GraduateStudent. The `protected` members `studentID` and `course` are accessible inside GraduateStudent.
- Public member functions such as `displayPerson()` and `displayStudent()` are available through the public inheritance chain.
- GraduateStudent also has its own private research topic and supervisor fields.

## Compile and run
```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o university
./university
```

## Result / observation
The program demonstrates single inheritance from Person to Student and multilevel inheritance from Person through Student to GraduateStudent. Derived classes reuse the data and display behaviour of their base classes, reducing repeated code.
