// (You are asked with developing a Student Management and Perfomance Analysis System using C++ that effectively demonstrate 
//object oriented programming principles, data encapsulation and nested functions while landing multiple student record. The 
//system should define a student class private data members, including rollNumber, name, marks(an array of five subjects), 
//totalMarks and averageMarks. It should also include various member functions such a inputDetails(), which gathers student data; 
//calculateTotalAverage(), a nested function to compute total and average marks; displayDetails(), which prints student information; 
//compareMarks(student other), which allows comparison netween student objects and a static function findTopper(Studentarr[], 
//int size), which identifies the student with the highest marks.)

//Additionally, a separate Classroom class should be implemented to manage multiple students efficiently. This class should 
//contain an array of subject objects and methods such as addStudent() for adding students, displayAllStudents() for displaying
// all stored record, and getTopper() to determine the highest scoring student. The main() function should facilitate user 
//interaction by allowing multiple input of student data, storing multiple student records within classroom object, displaying 
//all student details, identifying the topper. The program should enforce encapsulation, ensuring private data members are 
//accesed only through public methods, and implemented object comparison techniques for making students based on performance.

//The system should handle user input validation to ensure marks fall within the valid range of 0-100. It should also demonstrate
// proper array handling within a class and make use of nested functions for improved modularity. Additional features such as 
//operator overloading for student comparisons, file handling for data persistence, and an automated grading system based on 
//average marks can further increase the complexity and utility of the program. By implementing these elements, the system will 
//serve as a comprehensive demonstration of key C++ concepts while providing a robust solution for managing and analyzing student
// performance.


#include <iostream>
using namespace std;

class student {
private:
    int rollNumber;
    string name;
    int marks[5];
    int totalMarks;
    float averageMarks;

    float totalAvg() {
        totalMarks = 0;
        for (int j = 0; j < 5; j++) {
            totalMarks += marks[j];
        }
        averageMarks = totalMarks / 5.0;
        return averageMarks;
    }

public:
    void inputDetails(string n, int roll, int m[5]) {
        name = n;
        rollNumber = roll;
        for (int i = 0; i < 5; i++) {
            marks[i] = m[i];
        }
        totalAvg();
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Roll: " << rollNumber << endl;
        for (int k = 0; k < 5; k++) {
            cout << "Marks of Subject #" << k + 1 << ": " << marks[k] << endl;
        }
        cout << "Total Marks: " << totalMarks << endl;
        cout << "Average Marks: " << averageMarks << endl;
    }

    float getTotalAvg() {
        return totalAvg();
    }

    bool operator>(const student &other) {
        return totalMarks > other.totalMarks;
    }

    static student findTopper(student obj[], int n) {
        student max = obj[0];
        for (int j = 1; j < n; j++) {
            if (obj[j] > max) {
                max = obj[j];
            }
        }
        return max;
    }
};

class classroom {
private:
    int n;
    student obj[100];

public:
    classroom() {
        n = 0;
    }

    void AddStudent() {
        if (n < 100) {
            string name;
            int roll, marks[5];

            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Roll Number: ";
            cin >> roll;
            cout << "Enter marks for 5 subjects: ";
            for (int i = 0; i < 5; i++) {
                cin >> marks[i];
            }

            obj[n].inputDetails(name, roll, marks);
            n++;
        } else {
            cout << "Classroom is full!\n";
        }
    }

    void DisplayStudent() {
        for (int i = 0; i < n; i++) {
            obj[i].display();
        }
    }

    void Compare() {
        if (n == 0) {
            cout << "No students available.\n";
            return;
        }
        student topper = student::findTopper(obj, n);
        cout << "Topper Details:\n";
        topper.display();
    }
};

int main() {
    classroom object;
    char ch = 'y';
    int choice;

    while (ch == 'y') {
        cout << "Add student? [y/n]: ";
        cin >> ch;

        if (ch == 'y') {
            object.AddStudent();
        }

        cout << "1. Average Marks" << endl;
        cout << "2. Display Students" << endl;
        cout << "3. Highest Scorer" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Average Marks Calculation Not Available in Main" << endl;
        } else if (choice == 2) {
            object.DisplayStudent();
        } else if (choice == 3) {
            object.Compare();
        } else {
            cout << "Invalid Choice" << endl;
        }
    }

    return 0;
}
