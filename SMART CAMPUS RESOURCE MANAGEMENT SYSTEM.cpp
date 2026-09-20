#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_STUDENTS = 50;
const int MAX_RESOURCES = 50;

const int MATRIX_ROWS = 4;
const int MATRIX_COLS = 4;


// ========================================================
// STRUCTURES
// ========================================================

struct Student
{
    int id;
    string name;
};

struct Resource
{
    int id;
    string name;
    int quantity;
};


// ========================================================
// FUNCTION PROTOTYPES
// ========================================================

// students
void addStudent(Student* students, int& studentCount);
void displayStudents(Student* students, int studentCount);
void searchStudent(Student* students, int studentCount);
void updateStudent(Student* students, int studentCount);
void deleteStudent(Student* students, int& studentCount);

// resources
void manageResources(Resource* resources, int& resourceCount);
void displayResources(Resource* resources, int resourceCount);

// array traversals
void arrayTraversal(Student* students, int studentCount,
                    Resource* resources, int resourceCount);

// matrix
void processMatrix(const int matrix[MATRIX_ROWS][MATRIX_COLS]);

// summaries
void summaryReport(Student* students, int studentCount,
                   Resource* resources, int resourceCount);


// ========================================================
// MAIN
// ========================================================

int main()
{
    // ========================================================
    // DYNAMIC MEMORY ALLOCATION
    // ========================================================

    Student* students;
    Resource* resources;

    students = new Student[MAX_STUDENTS];
    resources = new Resource[MAX_RESOURCES];

    int studentCount = 0;
    int resourceCount = 0;

    int choice;


    // ========================================================
    // MATRIX DATA
    // ========================================================

    int matrix[MATRIX_ROWS][MATRIX_COLS] =
    {
        {10, 20, 15, 25},
        {15, 10, 20, 30},
        {20, 25, 10, 15},
        {30, 20, 25, 10}
    };


    // ========================================================
    // SYSTEM MENU
    // ========================================================

    do
    {
        cout << "\n============================================\n";
        cout << "        STUDENT RESOURCE SYSTEM\n";
        cout << "============================================\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Manage Resources\n";
        cout << "7. Display Resources\n";
        cout << "8. Array Traversal\n";
        cout << "9. Process Matrix\n";
        cout << "10. Generate Summary Report\n";
        cout << "11. Exit\n";
        cout << "============================================\n";
        cout << "Enter your choice: ";
        cin >> choice;


        switch(choice)
        {
            case 1:
                addStudent(students, studentCount);
                break;

            case 2:
                displayStudents(students, studentCount);
                break;

            case 3:
                searchStudent(students, studentCount);
                break;

            case 4:
                updateStudent(students, studentCount);
                break;

            case 5:
                deleteStudent(students, studentCount);
                break;

            case 6:
                manageResources(resources, resourceCount);
                break;

            case 7:
                displayResources(resources, resourceCount);
                break;

            case 8:
                arrayTraversal(students, studentCount,
                               resources, resourceCount);
                break;

            case 9:
                processMatrix(matrix);
                break;

            case 10:
                summaryReport(students, studentCount,
                              resources, resourceCount);
                break;

            case 11:
                cout << "\nExiting system...\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while(choice != 11);


    // ========================================================
    // PROPER DEALLOCATION
    // ========================================================

    delete[] students;
    delete[] resources;

    cout << "\nDynamic memory successfully released.\n";

    return 0;
}


// ========================================================
// ADD STUDENT
// ========================================================

void addStudent(Student* students, int& studentCount)
{
    if(studentCount >= MAX_STUDENTS)
    {
        cout << "\nStudent storage is full.\n";
        return;
    }

    cout << "\n========== ADD STUDENT ==========\n";

    cout << "Enter Student ID: ";
    cin >> students[studentCount].id;

    cin.ignore();

    cout << "Enter Student Name: ";
    getline(cin, students[studentCount].name);

    studentCount++;

    cout << "\nStudent added successfully!\n";
}


// ========================================================
// DISPLAY STUDENTS
// ========================================================

void displayStudents(Student* students, int studentCount)
{
    cout << "\n========== DISPLAY STUDENTS ==========\n";

    if(studentCount == 0)
    {
        cout << "No students available.\n";
        return;
    }

    cout << left
         << setw(10) << "ID"
         << setw(25) << "Name"
         << endl;

    cout << "-----------------------------------\n";

    for(int i = 0; i < studentCount; i++)
    {
        cout << left
             << setw(10) << students[i].id
             << setw(25) << students[i].name
             << endl;
    }
}


// ========================================================
// SEARCH STUDENT
// ========================================================

void searchStudent(Student* students, int studentCount)
{
    int id;
    bool found = false;

    cout << "\n========== SEARCH STUDENT ==========\n";

    if(studentCount == 0)
    {
        cout << "No students available.\n";
        return;
    }

    cout << "Enter Student ID: ";
    cin >> id;

    for(int i = 0; i < studentCount; i++)
    {
        if(students[i].id == id)
        {
            cout << "\nStudent Found!\n";
            cout << "Student ID   : " << students[i].id << endl;
            cout << "Student Name : " << students[i].name << endl;

            found = true;
            break;
        }
    }

    if(!found)
    {
        cout << "\nStudent not found.\n";
    }
}


// ========================================================
// UPDATE STUDENT
// ========================================================

void updateStudent(Student* students, int studentCount)
{
    int id;
    bool found = false;

    cout << "\n========== UPDATE STUDENT ==========\n";

    if(studentCount == 0)
    {
        cout << "No students available.\n";
        return;
    }

    cout << "Enter Student ID: ";
    cin >> id;

    for(int i = 0; i < studentCount; i++)
    {
        if(students[i].id == id)
        {
            cin.ignore();

            cout << "Enter new name: ";
            getline(cin, students[i].name);

            cout << "\nStudent updated successfully!\n";

            found = true;
            break;
        }
    }

    if(!found)
    {
        cout << "\nStudent not found.\n";
    }
}


// ========================================================
// DELETE STUDENT
// ========================================================

void deleteStudent(Student* students, int& studentCount)
{
    int id;
    bool found = false;

    cout << "\n========== DELETE STUDENT ==========\n";

    if(studentCount == 0)
    {
        cout << "No students available.\n";
        return;
    }

    cout << "Enter Student ID: ";
    cin >> id;

    for(int i = 0; i < studentCount; i++)
    {
        if(students[i].id == id)
        {
            for(int j = i; j < studentCount - 1; j++)
            {
                students[j] = students[j + 1];
            }

            studentCount--;

            cout << "\nStudent deleted successfully!\n";

            found = true;
            break;
        }
    }

    if(!found)
    {
        cout << "\nStudent not found.\n";
    }
}


// ========================================================
// MANAGE RESOURCES
// ========================================================

void manageResources(Resource* resources, int& resourceCount)
{
    if(resourceCount >= MAX_RESOURCES)
    {
        cout << "\nResource storage is full.\n";
        return;
    }

    cout << "\n========== MANAGE RESOURCE ==========\n";

    cout << "Enter Resource ID: ";
    cin >> resources[resourceCount].id;

    cin.ignore();

    cout << "Enter Resource Name: ";
    getline(cin, resources[resourceCount].name);

    cout << "Enter Quantity: ";
    cin >> resources[resourceCount].quantity;

    resourceCount++;

    cout << "\nResource added successfully!\n";
}


// ========================================================
// DISPLAY RESOURCES
// ========================================================

void displayResources(Resource* resources, int resourceCount)
{
    cout << "\n========== DISPLAY RESOURCES ==========\n";

    if(resourceCount == 0)
    {
        cout << "No resources available.\n";
        return;
    }

    cout << left
         << setw(10) << "ID"
         << setw(25) << "Resource"
         << setw(10) << "Quantity"
         << endl;

    cout << "---------------------------------------------\n";

    for(int i = 0; i < resourceCount; i++)
    {
        cout << left
             << setw(10) << resources[i].id
             << setw(25) << resources[i].name
             << setw(10) << resources[i].quantity
             << endl;
    }
}


// ========================================================
// ARRAY TRAVERSAL
// ========================================================

void arrayTraversal(Student* students, int studentCount,
                    Resource* resources, int resourceCount)
{
    cout << "\n========== ARRAY TRAVERSAL ==========\n";

    cout << "\nStudents:\n";

    for(int i = 0; i < studentCount; i++)
    {
        cout << "Student[" << i << "] = "
             << students[i].name << endl;
    }

    cout << "\nResources:\n";

    for(int i = 0; i < resourceCount; i++)
    {
        cout << "Resource[" << i << "] = "
             << resources[i].name << endl;
    }
}


// ========================================================
// PROCESS MATRIX
// ========================================================

void processMatrix(const int matrix[MATRIX_ROWS][MATRIX_COLS])
{
    string depts[MATRIX_ROWS] =
    {
        "D1-IT Dept.",
        "D2-Engineering",
        "D3-Business",
        "D4-Education"
    };

    cout << "\n";
    cout << "       Resource Utilization Matrix (Hours/Week)\n\n";

    cout << left
         << setw(20) << "Department"
         << setw(10) << "R-01"
         << setw(10) << "R-02"
         << setw(10) << "R-03"
         << setw(10) << "R-04"
         << setw(10) << "Total"
         << endl;

    cout << "-----------------------------------------------------------------\n";

    int colTotals[MATRIX_COLS] = {0};

    for(int i = 0; i < MATRIX_ROWS; i++)
    {
        int rowTotal = 0;

        cout << left << setw(20) << depts[i];

        for(int j = 0; j < MATRIX_COLS; j++)
        {
            cout << setw(10) << matrix[i][j];

            rowTotal += matrix[i][j];
            colTotals[j] += matrix[i][j];
        }

        cout << rowTotal << endl;
    }

    cout << "\n";

    cout << left << setw(20) << "Column Totals:";

    for(int j = 0; j < MATRIX_COLS; j++)
    {
        cout << setw(10) << colTotals[j];
    }

    cout << endl;
}


// ========================================================
// SUMMARY REPORT
// ========================================================

void summaryReport(Student* students, int studentCount,
                   Resource* resources, int resourceCount)
{
    cout << "\n============================================\n";
    cout << "              SUMMARY REPORT\n";
    cout << "============================================\n";

    cout << "Total Students  : " << studentCount << endl;
    cout << "Total Resources : " << resourceCount << endl;

    cout << "\nStudent List:\n";

    for(int i = 0; i < studentCount; i++)
    {
        cout << i + 1 << ". "
             << students[i].id << " - "
             << students[i].name << endl;
    }

    cout << "\nResource List:\n";

    for(int i = 0; i < resourceCount; i++)
    {
        cout << i + 1 << ". "
             << resources[i].name
             << " (Qty: "
             << resources[i].quantity
             << ")" << endl;
    }

    cout << "============================================\n";
}
