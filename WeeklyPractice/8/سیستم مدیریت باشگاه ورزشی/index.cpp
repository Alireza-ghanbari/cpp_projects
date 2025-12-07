#include <iostream>
#include <vector>
using namespace std;

class Person
{
private:
    string name;
    int age;
    string phoneNumber;

public:
    Person(string name, int age, string phone)
        : name(name), age(age), phoneNumber(phone) {}

    void printInfo() const
    {
        cout << "Name: " << name
             << ", Age: " << age
             << ", Phone: " << phoneNumber;
    }
};

class Member : public Person
{
private:
    int memberId;
    string subscriptionType;
    string endDate;

public:
    Member(string name, int age, string phone,
           int memberId, string subType, string endDate)
        : Person(name, age, phone),
          memberId(memberId),
          subscriptionType(subType),
          endDate(endDate) {}

    void printMemberInfo() const
    {
        printInfo();
        cout << ", Member ID: " << memberId
             << ", Subscription: " << subscriptionType
             << ", End Date: " << endDate;
    }
};

class Coach : public Person
{
private:
    string specialty;
    double salary;

public:
    Coach(string name, int age, string phone,
          string specialty, double salary)
        : Person(name, age, phone),
          specialty(specialty),
          salary(salary) {}

    void printCoachInfo() const
    {
        printInfo();
        cout << ", Specialty: " << specialty
             << ", Salary: " << salary;
    }
};

class Course
{
private:
    string courseName;
    int weeks;
    int capacity;
    Coach coach;
    vector<Member *> members;

public:
    Course(string name, int weeks, int cap, Coach coach)
        : courseName(name), weeks(weeks),
          capacity(cap), coach(coach) {}

    bool addMember(Member *m)
    {
        if (members.size() >= capacity)
        {
            cout << "Capacity full! Cannot add member.\n";
            return false;
        }
        members.push_back(m);
        return true;
    }

    void printCourseInfo() const
    {
        cout << "\n--- Course Info ---\n";
        cout << "Course: " << courseName
             << ", Weeks: " << weeks
             << ", Capacity: " << capacity
             << ", Registered: " << members.size() << endl;

        cout << "Coach -> ";
        coach.printCoachInfo();
        cout << "\nMembers:\n";
        for (auto m : members)
        {
            cout << "- ";
            m->printMemberInfo();
            cout << endl;
        }
    }
};

class Address
{
private:
    string city;
    string street;
    int buildingNo;

public:
    Address(string city, string street, int buildingNo)
        : city(city), street(street), buildingNo(buildingNo) {}

    void printAddress() const
    {
        cout << city << ", " << street
             << ", No: " << buildingNo;
    }
};

class Gym
{
private:
    string name;
    Address address;
    vector<Coach> coaches;
    vector<Member> members;
    vector<Course> courses;

public:
    Gym(string name, Address addr)
        : name(name), address(addr) {}

    void addCoach(const Coach &c) { coaches.push_back(c); }
    void addMember(const Member &m) { members.push_back(m); }
    void addCourse(const Course &c) { courses.push_back(c); }

    void printAllCoaches() const
    {
        cout << "\n=== Coaches ===\n";
        for (auto &c : coaches)
        {
            c.printCoachInfo();
            cout << endl;
        }
    }

    void printAllMembers() const
    {
        cout << "\n=== Members ===\n";
        for (auto &m : members)
        {
            m.printMemberInfo();
            cout << endl;
        }
    }

    void printAllCourses() const
    {
        cout << "\n=== Courses ===\n";
        for (auto &c : courses)
        {
            c.printCourseInfo();
        }
    }
};

int main()
{
    Gym gym("FitPlus", Address("Tehran", "Valiasr", 123));

    Coach c1("Ali", 35, "09121234567", "Bodybuilding", 1500);
    Coach c2("Sara", 29, "09391234567", "Yoga", 1200);

    gym.addCoach(c1);
    gym.addCoach(c2);

    Member m1("Reza", 28, "09125557788", 101, "Monthly", "1403/11/20");
    Member m2("Maryam", 24, "09351112233", 102, "Yearly", "1404/05/10");
    Member m3("Omid", 31, "09121117799", 103, "Daily", "1403/12/05");

    gym.addMember(m1);
    gym.addMember(m2);
    gym.addMember(m3);

    Course course1("TRX Beginner", 8, 2, c1);
    Course course2("Yoga Advanced", 10, 3, c2);

    course1.addMember(&m1);
    course1.addMember(&m2);
    course1.addMember(&m3);

    course2.addMember(&m2);
    course2.addMember(&m3);

    gym.addCourse(course1);
    gym.addCourse(course2);

    gym.printAllCoaches();
    gym.printAllMembers();
    gym.printAllCourses();

    return 0;
}
