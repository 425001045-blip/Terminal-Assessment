#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_CAPACITY = 50;

struct Student {
    int id;
    string name;
};

// ================= FUNCTION PROTOTYPES =================

int searchStudent(
    const Student roster[],
    int count,
    int targetId,
    int &comparisons
);

bool addStudent(
    Student roster[],
    int &count,
    int id,
    const string &name
);

bool updateStudent(
    Student roster[],
    int count,
    int targetId,
    const string &newName
);

bool deleteStudent(
    Student roster[],
    int &count,
    int targetId
);

bool inspectRecord(
    const Student roster[],
    int count,
    int index,
    Student &outStudent
);

void displayStudents(
    const Student roster[],
    int count
);

void displayResources(
    int count
);

void processMatrix(
    const Student roster[],
    int count
);

void generateReport(
    const Student roster[],
    int count
);


// ================= MAIN FUNCTION =================

int main() {

    Student roster[MAX_CAPACITY];
    int currentCount = 0;
    int choice = 0;

    do {

        cout << "\n=========================================\n";
        cout << "       NTC CC105: STUDENT ROSTER\n";
        cout << "=========================================\n";
        cout << "1. Add Student Record\n";
        cout << "2. Search Student by ID\n";
        cout << "3. Update Student Record\n";
        cout << "4. Delete Student by ID\n";
        cout << "5. Safe Inspect Record by Index\n";
        cout << "6. Display Full Roster\n";
        cout << "7. Display Resources\n";
        cout << "8. Process Student Matrix\n";
        cout << "9. Generate Report\n";
        cout << "10. Exit\n";
        cout << "Enter selection [1-10]: ";
        cin >> choice;


        // ================= ADD STUDENT =================

        if (choice == 1) {

            int id;
            string name;

            cout << "\nEnter Student ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Student Name: ";
            getline(cin, name);

            if (addStudent(
                    roster,
                    currentCount,
                    id,
                    name)) {

                cout << "Student added successfully!\n";
            }
            else {

                cout << "Unable to add student.\n";
                cout << "ID may already exist or roster is full.\n";
            }
        }


        // ================= SEARCH STUDENT =================

        else if (choice == 2) {

            int targetId;
            int comparisons = 0;

            cout << "\nEnter Student ID to search: ";
            cin >> targetId;

            int position = searchStudent(
                roster,
                currentCount,
                targetId,
                comparisons
            );

            if (position != -1) {

                cout << "\nStudent Found!\n";
                cout << "ID: "
                     << roster[position].id << endl;

                cout << "Name: "
                     << roster[position].name << endl;

                cout << "Comparisons made: "
                     << comparisons << endl;
            }
            else {

                cout << "\nStudent not found.\n";

                cout << "Comparisons made: "
                     << comparisons << endl;
            }
        }


        // ================= UPDATE STUDENT =================

        else if (choice == 3) {

            int targetId;
            string newName;

            cout << "\nEnter Student ID to update: ";
            cin >> targetId;

            cin.ignore();

            cout << "Enter New Student Name: ";
            getline(cin, newName);

            if (updateStudent(
                    roster,
                    currentCount,
                    targetId,
                    newName)) {

                cout << "Student updated successfully!\n";
            }
            else {

                cout << "Student ID not found.\n";
            }
        }


        // ================= DELETE STUDENT =================

        else if (choice == 4) {

            int targetId;

            cout << "\nEnter Student ID to delete: ";
            cin >> targetId;

            if (deleteStudent(
                    roster,
                    currentCount,
                    targetId)) {

                cout << "Student deleted successfully!\n";
            }
            else {

                cout << "Student ID not found.\n";
            }
        }


        // ================= INSPECT RECORD =================

        else if (choice == 5) {

            int index;
            Student student;

            cout << "\nEnter record index (0-"
                 << currentCount - 1 << "): ";
            cin >> index;

            if (inspectRecord(
                    roster,
                    currentCount,
                    index,
                    student)) {

                cout << "\nRecord Found!\n";
                cout << "Index: " << index << endl;
                cout << "ID: " << student.id << endl;
                cout << "Name: "
                     << student.name << endl;
            }
            else {

                cout << "Invalid index. "
                     << "Record does not exist.\n";
            }
        }


        // ================= DISPLAY STUDENTS =================

        else if (choice == 6) {

            displayStudents(
                roster,
                currentCount
            );
        }


        // ================= DISPLAY RESOURCES =================

        else if (choice == 7) {

            displayResources(currentCount);
        }


        // ================= PROCESS MATRIX =================

        else if (choice == 8) {

            processMatrix(
                roster,
                currentCount
            );
        }


        // ================= GENERATE REPORT =================

        else if (choice == 9) {

            generateReport(
                roster,
                currentCount
            );
        }


        // ================= EXIT =================

        else if (choice == 10) {

            cout << "\nExiting system.\n";
        }


        // ================= INVALID CHOICE =================

        else {

            cout << "\nInvalid selection. "
                 << "Please choose 1-10.\n";
        }

    } while (choice != 10);

    return 0;
}


// ======================================================
// FUNCTION 1: SEARCH STUDENT
// ======================================================

int searchStudent(
    const Student roster[],
    int count,
    int targetId,
    int &comparisons
) {

    comparisons = 0;

    for (int i = 0; i < count; i++) {

        comparisons++;

        if (roster[i].id == targetId) {
            return i;
        }
    }

    return -1;
}


// ======================================================
// FUNCTION 2: ADD STUDENT
// ======================================================

bool addStudent(
    Student roster[],
    int &count,
    int id,
    const string &name
) {

    if (count >= MAX_CAPACITY) {
        return false;
    }

    int comparisons;

    if (searchStudent(
            roster,
            count,
            id,
            comparisons) != -1) {

        return false;
    }

    roster[count].id = id;
    roster[count].name = name;

    count++;

    return true;
}


// ======================================================
// FUNCTION 3: UPDATE STUDENT
// ======================================================

bool updateStudent(
    Student roster[],
    int count,
    int targetId,
    const string &newName
) {

    int comparisons;

    int position = searchStudent(
        roster,
        count,
        targetId,
        comparisons
    );

    if (position == -1) {
        return false;
    }

    roster[position].name = newName;

    return true;
}


// ======================================================
// FUNCTION 4: DELETE STUDENT
// ======================================================

bool deleteStudent(
    Student roster[],
    int &count,
    int targetId
) {

    int comparisons;

    int position = searchStudent(
        roster,
        count,
        targetId,
        comparisons
    );

    if (position == -1) {
        return false;
    }

    for (int i = position; i < count - 1; i++) {
        roster[i] = roster[i + 1];
    }

    count--;

    return true;
}


// ======================================================
// FUNCTION 5: INSPECT RECORD
// ======================================================

bool inspectRecord(
    const Student roster[],
    int count,
    int index,
    Student &outStudent
) {

    if (index < 0 || index >= count) {
        return false;
    }

    outStudent = roster[index];

    return true;
}


// ======================================================
// FUNCTION 6: DISPLAY STUDENTS
// ======================================================

void displayStudents(
    const Student roster[],
    int count
) {

    if (count == 0) {

        cout << "\nRoster is empty.\n";
        return;
    }

    cout << "\n================ STUDENT ROSTER ================\n";

    cout << left
         << setw(10) << "Index"
         << setw(15) << "Student ID"
         << setw(30) << "Name"
         << endl;

    cout << "-------------------------------------------------\n";

    for (int i = 0; i < count; i++) {

        cout << left
             << setw(10) << i
             << setw(15) << roster[i].id
             << setw(30) << roster[i].name
             << endl;
    }

    cout << "=================================================\n";

    cout << "Total Students: "
         << count << endl;
}


// ======================================================
// FUNCTION 7: DISPLAY RESOURCES
// ======================================================

void displayResources(
    int count
) {

    int availableSlots = MAX_CAPACITY - count;

    cout << "\n=========================================\n";
    cout << "          SYSTEM RESOURCES\n";
    cout << "=========================================\n";

    cout << "Maximum Capacity : "
         << MAX_CAPACITY << endl;

    cout << "Current Students : "
         << count << endl;

    cout << "Available Slots  : "
         << availableSlots << endl;

    if (availableSlots == 0) {
        cout << "Roster Status    : FULL\n";
    }
    else {
        cout << "Roster Status    : AVAILABLE\n";
    }

    cout << "=========================================\n";
}


// ======================================================
// FUNCTION 8: PROCESS MATRIX
// ======================================================

void processMatrix(
    const Student roster[],
    int count
) {

    if (count == 0) {

        cout << "\nNo student records to process.\n";
        return;
    }

    cout << "\n=========================================\n";
    cout << "        PROCESSED STUDENT MATRIX\n";
    cout << "=========================================\n";

    cout << left
         << setw(10) << "Row"
         << setw(15) << "Student ID"
         << setw(30) << "Name"
         << endl;

    cout << "-------------------------------------------------\n";

    for (int i = 0; i < count; i++) {

        cout << left
             << setw(10) << i
             << setw(15) << roster[i].id
             << setw(30) << roster[i].name
             << endl;
    }

    cout << "=========================================\n";

    cout << "Matrix processing completed.\n";
}


// ======================================================
// FUNCTION 9: GENERATE REPORT
// ======================================================

void generateReport(
    const Student roster[],
    int count
) {

    cout << "\n=========================================\n";
    cout << "          STUDENT ROSTER REPORT\n";
    cout << "=========================================\n";

    cout << "Total Students: "
         << count << endl;

    cout << "Maximum Capacity: "
         << MAX_CAPACITY << endl;

    cout << "Available Slots: "
         << MAX_CAPACITY - count << endl;

    cout << "\nStudent Records:\n";

    if (count == 0) {

        cout << "No student records available.\n";
    }
    else {

        for (int i = 0; i < count; i++) {

            cout << i + 1 << ". "
                 << roster[i].id
                 << " - "
                 << roster[i].name
                 << endl;
        }
    }

    cout << "\n=========================================\n";
    cout << "Report generation completed.\n";
    cout << "=========================================\n";
}
