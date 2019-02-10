#include <bits/stdc++.h>

using namespace std;

/*
  Mark

  Class to store marks and grades of students in each subjects.
*/
class Mark
{
  private:
    int student;
    int mark;
    char grade;

  public:
    static const char GRADE_A = 'A';
    static const char GRADE_B = 'B';
    static const char GRADE_C = 'C';
    static const char GRADE_D = 'D';
    static const char GRADE_F = 'E';

    // Default constructor
    Mark(){};

    /*
    Overloaded constructor

    @param mark - mark of the student
    @param student - student index of the student
    */
    Mark(int mark, int student)
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

    // Getters
    int getMark();
    char getGrade();
    int getStudent();

    // Comparater to be used in the sort
    bool operator<(const Mark &other) const
    {
        return student < other.student;
    }

    friend ostream &operator<<(ostream &out, const Mark &obj);
};

int Mark::getMark()
{
    return mark;
}

char Mark::getGrade()
{
    return grade;
}

int Mark::getStudent()
{
    return student;
}

// Overload for output operator
ostream &operator<<(ostream &out, const Mark &obj)
{
    out << obj.student << " " << obj.mark << " " << obj.grade << endl;
    return out;
}

/*
  Subject

  Class to store subject details.
*/
class Subject
{
  private:
    string id;
    int markCount;
    int markCounter;
    Mark *marks;

  public:
    // Default constructor
    Subject(){};

    /*
    Overloaded constructor

    @param id - subject id
    @param markCount - number of mark records availble for the subject
    */
    Subject(string id, int markCount)
    {
        this->id = id;
        this->markCounter = 0;
        this->markCount = markCount;
        this->marks = new Mark[markCount];
    };

    void addMark(Mark mark);
    string getId();
    int getMarkCount();
    int countGrade(char grade);
    double getGradePresentage(char grade);
    double getAverage();
    double getStandardDiviation();
    Mark *getStudentMark(int id);
    void sortMarksByStudents();

    friend ostream &operator<<(ostream &out, Subject &subject);
};

/*
    Add the given mark to the marks array

    @param mark - mark object with including marks and grade and student.
    */
void Subject::addMark(Mark mark)
{
    this->marks[markCounter] = mark;
    markCounter++;
}

string Subject::getId()
{
    return id;
}

int Subject::getMarkCount()
{
    return markCount;
}

/*
    Return the persentage of the given grade.

    @param grade - grade to be counted.
    */
double Subject::getGradePresentage(char grade)
{
    return countGrade(grade) * 100.0 / getMarkCount();
}

/*
    Return the count of the given grade.

    @param grade - grade to be counted.
    */
int Subject::countGrade(char grade)
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

/*
    Return the average of the subject.
    */
double Subject::getAverage()
{
    int sum = 0;
    for (size_t i = 0; i < markCount; i++)
    {
        sum += marks[i].getMark();
    }
    return sum / markCount;
}

/*
    Return the stadard diviation of the subject.
    */
double Subject::getStandardDiviation()
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

/*
    Return the mark of the given student.

    @param id - student id
    */
Mark *Subject::getStudentMark(int id)
{
    for (size_t i = 0; i < markCount; i++)
    {
        if (marks[i].getStudent() == id)
        {
            return &marks[i];
        }
    }
    return NULL;
}

/*
    Comparator to sort the mark array.
    */
void Subject::sortMarksByStudents()
{
    sort(marks, marks + markCount);
}

/*
    Output operator to display the marks details of every subject.
    */
ostream &operator<<(ostream &out, Subject &subject)
{
    out << subject.getId() << endl;
    for (size_t i = 0; i < subject.markCount; i++)
    {
        Mark mark = subject.marks[i];
        out << mark;
    }
    return out;
}

/*
    Markstore

    Class to store all the subjects.
*/
class Markstore
{
  private:
    static const int MAXSUBJECTS = 10;
    static const int MAXSTUDENTS = 100;

    Subject subjects[MAXSUBJECTS];
    int subjectCounter = 0;

    void loadData();

  public:
    Markstore()
    {
        loadData();
    }

    ~Markstore() {}

    static bool subjectInputVaild(string input);
    static bool studentInputVaild(int input);

    void addSubject(Subject subject);
    void searchSubject(string query);
    void searchStudent(int id);
    void displaySubjectSummary(string query);
    void saveSummaries();

    friend ostream &operator<<(ostream &out, Markstore &markstore);
};

// Input vailidations
bool Markstore::subjectInputVaild(string input)
{
    return input.length() == 7;
}

bool Markstore::studentInputVaild(int input)
{
    return input / 10000000 > 0 && input / 10000000 < 10;
}

/*
    Read the data from subjdata.txt
    */
void Markstore::loadData()
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
                Mark newMark = Mark(mark, student);
                newSubject.addMark(newMark);
            }
            newSubject.sortMarksByStudents();
            addSubject(newSubject);
        }
        file.close();
    }
    else
        cout << "Unable to open file";
};

void Markstore::addSubject(Subject subject)
{
    subjects[subjectCounter] = subject;
    subjectCounter++;
}

void Markstore::searchSubject(string query)
{
    for (size_t i = 0; i < subjectCounter; i++)
    {
        if (subjects[i].getId().compare(query) == 0)
        {
            cout << subjects[i];
            return;
        }
    }
    cout << "Given subject id not found!";
}

void Markstore::searchStudent(int id)
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

void Markstore::displaySubjectSummary(string query)
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

void Markstore::saveSummaries()
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

ostream &operator<<(ostream &out, Markstore &markstore)
{
    for (size_t i = 0; i < markstore.subjectCounter; i++)
    {
        out << markstore.subjects[i];
    }
    return out;
}

void printMenu()
{
    cout << "\n"
         << "=================================" << endl;
    cout << "Mark Store" << endl;
    cout << "1 - Display Subject" << endl;
    cout << "2 - Display Student" << endl;
    cout << "3 - Display Subject Summery" << endl;
    cout << "4 - Save Summaries" << endl;
    cout << "5 - Exit" << endl;
    cout << "================================="
         << "\n"
         << endl;
}

int main(int argc, char const *argv[])
{
    Markstore markstore = Markstore();

    bool run = true;
    int n;

    while (run)
    {
        printMenu();

        cout << "Select an option: ";

        cin >> n;
        if (n == 1)
        {
            cout << "Enter subject id: ";
            string subject;
            cin >> subject;
            if (Markstore::subjectInputVaild(subject))
                markstore.searchSubject(subject);
            else
                cout << "Enter a valid input." << endl;
        }
        else if (n == 2)
        {
            cout << "Enter student id: ";
            int student;
            cin >> student;
            if (Markstore::studentInputVaild(student))
                markstore.searchStudent(student);
            else
                cout << "Enter a valid input." << endl;
        }
        else if (n == 3)
        {
            cout << "Enter subject id: ";
            string subject;
            cin >> subject;
            if (Markstore::subjectInputVaild(subject))
                markstore.displaySubjectSummary(subject);
            else
                cout << "Enter a valid input." << endl;
        }
        else if (n == 4)
        {
            markstore.saveSummaries();
        }
        else if (n == 5)
        {
            run == false;
            break;
        }
        else
        {
            cout << "Invaild Input" << endl;
        }

        cout << "\nEnter charater to proceed...";
        char temp;
        cin >> temp;

    }

    return 0;
}
