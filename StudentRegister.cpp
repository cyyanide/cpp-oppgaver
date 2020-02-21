/* Oblig nr 3
 
• Lag en klasse Student med variablene
– fornavn
– etternavn
– studentnummer
– studieretning
– studiepoeng
• Lag en vector med studenter
• Lag en print meny funksjone som skriver ut hvilke valg brukeren har
– legg inn ny student
– skriv ut alle studenter
– registrer nye studiepoeng
• F˚a disse funksjonene til ˚a virke
*/

#include "../../std_lib_facilities.h"

class Student {
public:
    string name, surname, subject;
    int studentnr, points;
};

void add_student(vector <Student>& studenter)
{
    Student s1; 
    cout <<  "Add a new student to database " << endl;
    cout << "Name: ";
    cin >> s1.name;
    cout << "Surname: ";
    cin >> s1.surname;
    cout << "Student number: ";
    cin >> s1.studentnr;
    cout << "Subject: ";
    cin >> s1.subject;
    cout << "Points: ";
    cin >> s1.points;
    studenter.push_back(s1);
}

void register_points(vector <Student> &studenter)
{
    cout << "Enter student number and points to add: " << endl;
    int new_points, student_number;
    cin >> student_number >> new_points;
    for (int i = 0; i < studenter.size(); i++) {
        if (student_number == studenter[i].studentnr) {
            studenter[i].points += new_points;
        }
    }
}

void print_students(vector<Student> &studenter)
{
    cout << "Studenter: " << endl;

    for (int i = 0; i < studenter.size(); i++) {
        cout << "Student: " << studenter[i].name << " " << studenter[i].surname << endl << "Student number: " << studenter[i].studentnr <<
            endl << "Subject: " << studenter[i].subject << endl << "Points: " <<
            studenter[i].points << endl;
    }
}


void print_choice(vector <Student> &studenter)
{
    cout << "Welcome to student register!" << endl << "Press 1 to add a new student \nPress 2 to see all students \nPress 3 to register points  " << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        add_student(studenter);
        break;
    case 2:
        print_students(studenter);
        break;
    case 3:
        register_points(studenter);
        break;
    }
}

int main()
{
    vector <Student> studenter;
    while (true) { 
        print_choice(studenter);
    }
    
}
