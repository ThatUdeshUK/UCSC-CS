#include <bits/stdc++.h>

using namespace std;

class Student
{
  private:
    int id;

  public:
    Student();

    Student(int id)
    {
        this->id = id;
    };

    int getId()
    {
        return id;
    }
};

class Mark
{
  private:
    Student *student;
    int mark;
    char grade;

  public:
    static const char GRADE_A = 'A';
    static const char GRADE_B = 'B';
    static const char GRADE_C = 'C';
    static const char GRADE_D = 'D';
    static const char GRADE_F = 'E';

    Mark(){};

    Mark(int mark, Student *student)
    {
        this->mark = mark;
        if (mark < 30)
        {
            this->grade = GRADE_F;
        }
        else if (mark < 40)
        {
            this->grade = GRADE_D;
        }
        else if (mark < 55)
        {
            this->grade = GRADE_C;
        }
        else if (mark < 70)
        {
            this->grade = GRADE_B;
        }
        else
        {
            this->grade = GRADE_A;
        }
        this->student = student;
    };

    void display()
    {
        cout << student->getId() << " " << mark << " " << grade << endl;
    }

    // Getter
    int getMark()
    {
        return mark;
    }

    char getGrade()
    {
        return grade;
    }

    Student *getStudent()
    {
        return student;
    }
};

class Subject
{
  private:
    string id;
    int markCount;
    int markCounter;
    Mark *marks;

  public:
    Subject(){};

    Subject(string id, int markCount)
    {
        this->id = id;
        this->markCounter = 0;
        this->markCount = markCount;
        this->marks = new Mark[markCount];
    };

    void addMark(Mark mark)
    {
        this->marks[markCounter] = mark;
        markCounter++;
    }

    void displayMarks()
    {
        for (size_t i = 0; i < markCount; i++)
        {
            Mark mark = marks[i];
            mark.display();
        }
    }

    // Getter
    string getId()
    {
        return id;
    }

    int getMarkCount()
    {
        return markCount;
    }

    int countGrade(char grade)
    {
        int count = 0;
        for (size_t i = 0; i < markCount; i++)
        {
            if (marks[i].getGrade() == grade)
            {
                count++;
            }
        }
        return count;
    }

    double getGradePresentage(char grade)
    {
        return countGrade(grade) * 100.0 / getMarkCount();
    }

    double getAverage()
    {
        int sum = 0;
        for (size_t i = 0; i < markCount; i++)
        {
            sum += marks[i].getMark();
        }
        return sum / markCount;
    }

    double getStandardDiviation()
    {
        double average = getAverage();
        double sum = 0;
        for (size_t i = 0; i < markCount; i++)
        {
            sum += pow(average - marks[i].getMark(), 2);
        }
        double variance = sum / markCount;
        return sqrt(variance);
    }

    Mark *getStudentMark(int id)
    {
        for (size_t i = 0; i < markCount; i++)
        {
            if (marks[i].getStudent()->getId() == id)
            {
                return &marks[i];
            }
        }
        return NULL;
    }
};

class Markstore
{
  private:
    static const int MAXSUBJECTS = 10;
    static const int MAXSTUDENTS = 100;

    Subject subjects[MAXSUBJECTS];
    int subjectCounter = 0;

    void loadData()
    {
        const string dataPath = "subjdata.txt";
        ifstream file;
        file.open(dataPath);
        if (file.is_open())
        {
            while (!file.eof())
            {
                string subject;
                int n;
                file >> subject >> n;
                Subject newSubject = Subject(subject, n);
                size_t i;
                for (i = 0; i < n; i++)
                {
                    int student, mark;
                    file >> student >> mark;
                    Student *newStudent = new Student(student);
                    Mark newMark = Mark(mark, newStudent);
                    newSubject.addMark(newMark);
                }
                addSubject(newSubject);
            }
            file.close();
        }
        else
            cout << "Unable to open file";
    };

  public:
    Markstore()
    {
        loadData();
    }
    ~Markstore() {}

    void addSubject(Subject subject)
    {
        subjects[subjectCounter] = subject;
        subjectCounter++;
    }

    void searchSubject(string query)
    {
        for (size_t i = 0; i < subjectCounter; i++)
        {
            if (subjects[i].getId().compare(query) == 0)
            {
                cout << subjects[i].getId() << endl;
                subjects[i].displayMarks();
                return;
            }
        }
        cout << "Given subject id not found!";
    }

    void searchStudent(int id)
    {
        bool isExist = false;
        bool isFirst = true;
        for (size_t i = 0; i < subjectCounter; i++)
        {
            Subject subject = subjects[i];
            Mark *mark = subject.getStudentMark(id);
            if (mark != NULL)
            {
                isExist = true;
                if (isFirst)
                {
                    cout << id << endl;
                    cout << 20 << id / 1000000 << endl;
                    isFirst = false;
                }
                cout << subject.getId() << " " << mark->getMark() << " " << mark->getGrade() << endl;
            }
        }
        if (isExist)
            return;
        cout << "Given subject id not found!";
    }

    void displaySubjectSummary(string query)
    {
        for (size_t i = 0; i < subjectCounter; i++)
        {
            if (subjects[i].getId().compare(query) == 0)
            {
                cout << subjects[i].getId() << endl;
                cout << "Average: " << subjects[i].getAverage() << endl;
                cout << "Standerd diviation: " << subjects[i].getStandardDiviation() << endl;
                cout << "A count: " << subjects[i].countGrade(Mark::GRADE_A) << endl;
                cout << "B count: " << subjects[i].countGrade(Mark::GRADE_B) << endl;
                cout << "C count: " << subjects[i].countGrade(Mark::GRADE_C) << endl;
                cout << "D count: " << subjects[i].countGrade(Mark::GRADE_D) << endl;
                cout << "E count: " << subjects[i].countGrade(Mark::GRADE_F) << endl;
                return;
            }
        }
        cout << "Given subject id not found!";
    }

    void saveSummaries()
    {
        const string dataPath = "summdata.txt";
        ofstream file;
        file.open(dataPath);
        if (file.is_open())
        {
            for (size_t i = 0; i < subjectCounter; i++)
            {
                file << subjects[i].getId();
                file << " " << subjects[i].getAverage();
                file << " A " << subjects[i].getGradePresentage(Mark::GRADE_A) << "\%";
                file << " B " << subjects[i].getGradePresentage(Mark::GRADE_B) << "\%";
                file << " C " << subjects[i].getGradePresentage(Mark::GRADE_C) << "\%";
                file << " D " << subjects[i].getGradePresentage(Mark::GRADE_D) << "\%";
                file << " E " << subjects[i].getGradePresentage(Mark::GRADE_F) << "\%";
                file << endl;
            }
            file << EOF;
            file.close();
            cout << "Saved successfully" << endl;
        }
        else
            cout << "Unable to open file";
    }

    void displaySubjects()
    {
        for (size_t i = 0; i < subjectCounter; i++)
        {
            cout << subjects[i].getId() << endl;
            subjects[i].displayMarks();
        }
    }
};

int main(int argc, char const *argv[])
{
    Markstore markstore = Markstore();
    markstore.saveSummaries();
    // markstore.displaySubjectSummary("SCS1202");
    // markstore.searchStudent(17000001);
    // markstore.searchSubject("SCS1202");
    // markstore.displaySubjects();
    return 0;
}
