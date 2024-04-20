#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct student {
    struct student* next;
    struct { string first, last, patronymic; } name;
    string group;
    struct { int B[5] = {0}; float average; } grades;
};


struct student* read_fl() {
    int i = 1; // счётчик полей в структуре 
    struct student *lst = NULL, *curr = new student;
    string str;

    string filename = ".txt";
    /*cout << "Input name of the file with data: " << endl;
    filename = read_str();
    cout << endl;
    */
    fstream fl;
    fl.open(filename);
    if (!fl) {
        cout << "File not found." << endl;
        exit(1);
    }
    while (!fl.eof()) {
        getline(fl, str);
        switch (i)
        {
            case 1:
                curr->name.last = str;
                break;
            case 2:
                curr->name.first = str;
                break;
            case 3:
                curr->name.patronymic = str;
                break;
            case 4:
                curr->group = str;
                break;
            case 5:
                int j = 0;
                for (int k = 0; k < str.length(); k++) {
                    if (str[k] == ',')
                        continue;
                    if (str[k] == ' ') {
                        j++;
                    }
                    else {
                        curr->grades.B[j] = curr->grades.B[j] * 10 + (str[k] - 48);
                    }
                }
                break;  
        }
        if (i == 5) {
            i = 1;
            curr->grades.average = (float)(curr->grades.B[0] + curr->grades.B[1] + 
                curr->grades.B[2] + curr->grades.B[3] + curr->grades.B[4]) / 5;
            curr->next = lst;
            lst = curr;
            curr = new student;
        }
        else i++;
    }
    fl.close();
    return lst;
}

string read_str()
{
    string s = "";
    do
    {
        getline(cin, s);
    } while (!s.size());

    return s;
}

void print_stack(struct student* lst) {
    struct student* p = lst;
    while (p) {
        cout << "Last name:     " << p->name.last << endl;
        cout << "First name:    " << p->name.first << endl;
        cout << "Patronymic:    " << p->name.patronymic << endl;
        cout << "Group:         " << p->group << endl;
        cout << "Grades:        ";
        for (int i = 0; i < 5; ++i)
            cout << p->grades.B[i] << " ";
        cout << endl;
        cout << "GPA:           " << p->grades.average << endl << endl;
        p = p->next;
    }
}

void input_student(student *student) {
    cout << "Last name:     ";
    student->name.last = read_str();
    cout << "First name:    ";
    student->name.first = read_str();
    cout << "Patronymic:    ";
    student->name.patronymic = read_str();
    cout << "Group:         ";
    student->group = read_str();
    cout << "Grades:        ";
    string grades = read_str();
    int j = 0;
    for (int k = 0; k < grades.length(); k++) {
        if (grades[k] == ',')
            continue;
        if (grades[k] == ' ') {
            j++;
        }
        else {
            student->grades.B[j] = student->grades.B[j] * 10 + (grades[k] - 48);
        }
    }
    student->grades.average = (float)(student->grades.B[0] + student->grades.B[1] +
        student->grades.B[2] + student->grades.B[3] + student->grades.B[4]) / 5;
}

bool insert_student(student *lst, student *new_student) {
    bool flag = false;

    return flag;
}

int main()
{
    student *lst;
    lst = read_fl();
    print_stack(lst);

    string group;
    cout << "Input the group number: " << endl;
    group = read_str();
    student *new_student = new student;
    input_student(new_student);


    return 0;
}
