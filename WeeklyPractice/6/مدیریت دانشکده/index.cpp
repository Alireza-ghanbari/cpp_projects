#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Faculty;

class Teacher {
    friend class Faculty;
private:
    string name;
    double salary;
    Faculty* faculty;

public:
    Teacher(const string& name)
        : name(name), salary(0.0), faculty(nullptr) {}

    Teacher(const string& name, Faculty* f)
        : name(name), salary(0.0), faculty(nullptr) {
        if (f) updateFaculty(f);
    }

    Teacher(const Teacher& other)
        : name(other.name), salary(other.salary), faculty(nullptr) {}

    const string& getName() const { return name; }
    double getSalary() const { return salary; }

    void setSalary(double s) { salary = s; }

    string getFaculty() const;
    void updateFaculty(Faculty* newFaculty);
};

class Faculty {
    friend void compareBudget(const Faculty& a, const Faculty& b);
private:
    string name;
    Teacher** teachers;
    int teacherCount;
    int capacity;
    int students;
    double totalBudget;

    static const int INITIAL_CAPACITY = 4;

    void ensureCapacity() {
        if (teacherCount >= capacity) {
            int newCap = capacity * 2;
            Teacher** tmp = new Teacher*[newCap];
            for (int i = 0; i < teacherCount; ++i) tmp[i] = teachers[i];
            delete[] teachers;
            teachers = tmp;
            capacity = newCap;
        }
    }

public:
    Faculty(const string& name, double budget, int students)
        : name(name), teacherCount(0), capacity(INITIAL_CAPACITY),
          students(students), totalBudget(budget) {
        teachers = new Teacher*[capacity];
        for (int i = 0; i < capacity; ++i) teachers[i] = nullptr;
    }

    Faculty(const Faculty& other)
        : name(other.name), teacherCount(0), capacity(other.capacity),
          students(other.students), totalBudget(other.totalBudget) {
        teachers = new Teacher*[capacity];
        for (int i = 0; i < capacity; ++i) teachers[i] = nullptr;
    }

    Faculty& operator=(const Faculty& other) = delete;

    ~Faculty() {
        delete[] teachers;
    }

    const string& getName() const { return name; }

    void addStudents(int n) {
        if (n > 0) students += n;
    }

    void removeStudents(int n) {
        if (n > 0 && n <= students) students -= n;
    }

    void printFacultyInfo() const {
        cout << "Faculty Name: " << name << endl
             << "Teacher Count: " << teacherCount << endl
             << "Student Count: " << students << endl
             << "Remaining Budget: " << fixed << setprecision(2) << totalBudget << endl << endl;
    }

    Faculty& hireTeacher(const Teacher& t, double salary) {
        Teacher* tp = const_cast<Teacher*>(&t);
        if (tp->faculty && tp->faculty != this) {
            tp->faculty->removeTeacher(tp);
        }
        tp->setSalary(salary);
        tp->faculty = this;
        ensureCapacity();
        teachers[teacherCount++] = tp;
        totalBudget -= salary;
        return *this;
    }

    bool removeTeacher(Teacher* t) {
        for (int i = 0; i < teacherCount; ++i) {
            if (teachers[i] == t) {
                totalBudget += teachers[i]->salary;
                teachers[i]->faculty = nullptr;
                for (int j = i; j < teacherCount - 1; ++j)
                    teachers[j] = teachers[j + 1];
                --teacherCount;
                return true;
            }
        }
        return false;
    }

    bool removeTeacher(const string& tname) {
        for (int i = 0; i < teacherCount; ++i) {
            if (teachers[i]->getName() == tname) {
                totalBudget += teachers[i]->salary;
                teachers[i]->faculty = nullptr;
                for (int j = i; j < teacherCount - 1; ++j)
                    teachers[j] = teachers[j + 1];
                --teacherCount;
                return true;
            }
        }
        return false;
    }

    void printTeachers() const {
        cout << "Teachers in " << name << " (" << teacherCount << "):" << endl;
        for (int i = 0; i < teacherCount; ++i) {
            cout << " - " << teachers[i]->getName()
                 << " | Salary: " << teachers[i]->getSalary() << endl;
        }
        cout << endl;
    }

    friend void compareBudget(const Faculty& a, const Faculty& b);
};

string Teacher::getFaculty() const {
    if (faculty)
        return faculty->getName();
    cout << "This teacher is currently not hired." << endl;
    return string();
}

void Teacher::updateFaculty(Faculty* newFaculty) {
    if (newFaculty == faculty) return;
    if (faculty) {
        faculty->removeTeacher(this);
    }
    if (newFaculty) {
        newFaculty->hireTeacher(*this, this->salary);
    } else {
        this->faculty = nullptr;
    }
}

void compareBudget(const Faculty& a, const Faculty& b) {
    if (a.totalBudget > b.totalBudget)
        cout << a.name << " has more budget (" << a.totalBudget << ") than " << b.name << " (" << b.totalBudget << ")." << endl;
    else if (a.totalBudget < b.totalBudget)
        cout << b.name << " has more budget (" << b.totalBudget << ") than " << a.name << " (" << a.totalBudget << ")." << endl;
    else
        cout << a.name << " and " << b.name << " have equal budgets (" << a.totalBudget << ")." << endl;
}

int main() {
    Faculty compSci("Computer Science", 100000.0, 400);
    Faculty math("Mathematics", 80000.0, 300);

    Teacher alice("Alice");
    Teacher bob("Bob");
    Teacher carol("Carol");

    compSci.hireTeacher(alice, 20000.0).hireTeacher(bob, 15000.0);
    math.hireTeacher(carol, 18000.0);

    compSci.printTeachers();
    math.printTeachers();
    compSci.printFacultyInfo();
    math.printFacultyInfo();

    Teacher copyOfAlice = alice;
    cout << "Copy created: " << copyOfAlice.getName() << ", salary: " << copyOfAlice.getSalary() << endl;
    copyOfAlice.getFaculty();
    cout << endl;

    cout << "Moving Bob from Computer Science to Mathematics..." << endl;
    bob.updateFaculty(&math);

    compSci.printTeachers();
    math.printTeachers();
    compSci.printFacultyInfo();
    math.printFacultyInfo();

    cout << "Removing Carol from Mathematics (should refund salary)..." << endl;
    math.removeTeacher("Carol");
    math.printTeachers();
    math.printFacultyInfo();

    compareBudget(compSci, math);

    Faculty compCopy = compSci;
    compCopy.printFacultyInfo();
    cout << "Original faculty still intact:" << endl;
    compSci.printTeachers();

    compSci.addStudents(25);
    compSci.removeStudents(10);
    compSci.printFacultyInfo();

    return 0;
}
