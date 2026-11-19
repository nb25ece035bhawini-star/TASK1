
#include <iostream>
#include <string>
using namespace std;

class Student {
    string name, usn;
    float marks;
    static int count;

public:
    Student(string n, string u, float m)
        : name(n), usn(u), marks(m) { ++count; }

    ~Student() { --count; }

    void display() const { display(true); }

    void display(bool showUSN) const {
        cout << "Name: " << name << '\n';
        if (showUSN) cout << "USN: " << usn << '\n';
        cout << "Marks: " << marks << '\n';
    }

    static int getCount() { return count; }

    bool operator>(const Student& s) const {
        return marks > s.marks;
    }

    friend void compare(const Student&, const Student&);
};

int Student::count = 0;

void compare(const Student& a, const Student& b) {
    if (a.marks > b.marks)
        cout << a.name << " has higher marks.\n";
    else if (b.marks > a.marks)
        cout << b.name << " has higher marks.\n";
    else
        cout << "Both students have equal marks.\n";
}

int main() {
    Student *s1 = new Student("Aarav", "NMIT001", 88.5f);
    Student *s2 = new Student("Diya", "NMIT002", 92.0f);

    cout << "Student 1:\n";
    s1->display();

    cout << "\nStudent 2:\n";
    s2->display(false);

    cout << "\nNumber of students: "
         << Student::getCount() << '\n';

    cout << ((*s2 > *s1) ?
        "Diya has more marks.\n" :
        "Aarav has more marks.\n");

    compare(*s1, *s2);

    delete s1;
    delete s2;

    cout << "Students remaining: "
         << Student::getCount() << '\n';

    return 0;
}
