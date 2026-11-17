#include <iostream>
#include <string>
using namespace std;

// Base class: stores information common to every person.
class Person {
protected:
    string name;
    int age;

public:
    Person(const string& personName, int personAge)
        : name(personName), age(personAge) {}

    void displayPerson() const {
        cout << "Name: " << name << '\n';
        cout << "Age: " << age << '\n';
    }
};

// Student inherits the public and protected members of Person.
class Student : public Person {
protected:
    string studentID;
    string course;

public:
    Student(const string& personName, int personAge,
            const string& id, const string& courseName)
        : Person(personName, personAge),
          studentID(id), course(courseName) {}

    void displayStudent() const {
        displayPerson(); // Reuses the base-class display function.
        cout << "Student ID: " << studentID << '\n';
        cout << "Course: " << course << '\n';
    }
};

// GraduateStudent inherits Student, which already inherits Person.
class GraduateStudent : public Student {
private:
    string researchTopic;
    string supervisor;

public:
    GraduateStudent(const string& personName, int personAge,
                    const string& id, const string& courseName,
                    const string& topic, const string& supervisorName)
        : Student(personName, personAge, id, courseName),
          researchTopic(topic), supervisor(supervisorName) {}

    void displayGraduateStudent() const {
        displayStudent(); // Reuses Student and Person information.
        cout << "Research Topic: " << researchTopic << '\n';
        cout << "Supervisor: " << supervisor << '\n';
    }
};

int main() {
    cout << "=== STUDENT DETAILS ===\n";
    Student student("Aarav Sharma", 20, "STU101", "B.Sc. Computer Science");
    student.displayStudent();

    cout << "\n=== GRADUATE STUDENT DETAILS ===\n";
    GraduateStudent graduate("Meera Patel", 24, "GRD205",
                             "M.Sc. Computer Science",
                             "Artificial Intelligence",
                             "Dr. Rao");
    graduate.displayGraduateStudent();

    return 0;
}
