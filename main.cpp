#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

/* The const ensures the list of tasks is not modified and the & ensures
 * that the list is not copied (improves efficiency) */
void showTasks(const vector<string> &allTasks) {
    cout << "To-Do List:" << endl;

    for (int i = 1; i <= allTasks.size(); ++i) {
        cout << i << ". " << allTasks[i] << endl;
    }
}

int main() {
    vector<string> allTasks;
    string task;
    char choice;

    ifstream infile("tasks.txt");

    if (!infile.is_open()) {
        cout << "Error opening file" << endl;
        exit(1);
    }

    while (getline(infile, task)) {
        // Appends each task to the 'tasks' vector
        allTasks.push_back(task);
    }
    infile.close();

    /* This do-while loop continues until the user enters Q or q 
     * The loop will always run atleast once. The switch statement 
     * evaluates the value of choice and directs the program flow based
     * on the cases written. */
    do {
        cout << "A - Add a task" << endl;
        cout << "V - View tasks" << endl;
        cout << "Q - Quit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;

        switch (choice) {
        case 'A':
        case 'a':
            cout << "Enter a task: " << endl;
            cin.ignore();
            getline(cin, task);
            allTasks.push_back(task);
            break;
        
        case 'V':
        case 'v':
            showTasks(allTasks);
            break;
        }
    } while (choice != 'Q' && choice != 'q');

    ofstream outFile("tasks.txt");

    /* This is a range-based for loop to iterate over each element in the
     * allTasks vector. const auto &t means a unchanged reference to 
     * each elemnt in allTasks. The 'auto' allows the compiler to 
     * automatically discern the type of t based on the elements in allTasks
     * which is a vector<string>. */
    // for (const auto &t : allTasks) {
    //     outFile << t << endl;
    // }

    for (vector<string>::const_iterator it = allTasks.begin(); it != allTasks.end(); ++it) {
    outFile << *it << endl;
}
    outFile.close();

    return 0;
}