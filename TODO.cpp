#include <iostream>
using namespace std;
#include <string>
#include <vector>

enum enAction {
    Add_Task = 1,
    Remove_Task = 2,
    Complete_Task = 3,
};

class task {
public:
    string name;
    bool completed;

    task(string n){
        name = n;
        completed = false;
    }

    void mark_complete() {
        completed = true;
    }

    void display(int index){
        cout << index << ". " << name;
        if (completed) {
            cout << "  [Completed]";
        } else {
            cout << "  [Pending]";
        }
        cout << endl;
    }
};

vector<task> tasks;

// Function to list tasks and prompt for an action
int list_tasks() {
    int action;
    cout << endl;
    cout << "============================" << endl;
    cout << "        Current Tasks        " << endl;
    cout << "============================" << endl;
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
    } else {
        for (size_t i = 0; i < tasks.size(); ++i) {
            tasks[i].display(i + 1);
        }
    }
    cout << "============================" << endl;
    cout << "Choose an action:" << endl;
    cout << "  1. Add Task" << endl;
    cout << "  2. Remove Task" << endl;
    cout << "  3. Complete Task" << endl;
    cout << "Enter your choice: ";
    cin >> action;
    cout << endl;

    if (action < 1 || action > 3) {
        cout << "Invalid action. Please try again." << endl;
        return list_tasks();
    }
    return action;
}

// Function to perform the action based on user input
void add_task(const string& task_name) {
    tasks.emplace_back(task_name);
    cout << "Task added: " << task_name << endl;
}

void remove_task(int task_number) {
    if (task_number < 1 || task_number > tasks.size()) {
        cout << "Invalid task number." << endl;
        return;
    }
    tasks.erase(tasks.begin() + task_number - 1);
    cout << "Task number " << task_number << " removed." << endl;
}

void complete_task(int task_number) {
    if (task_number < 1 || task_number > tasks.size()) {
        cout << "Invalid task number." << endl;
        return;
    }
    tasks[task_number - 1].mark_complete();
    cout << "Task marked as complete." << endl;
}

void do_action(int action){
    string task;
    int task_number;
    switch (action) {
        case Add_Task:
            cout << "Enter the task to add: ";
            cin.ignore();
            getline(cin, task);
            add_task(task);
            cout << endl;
            break;
        case Remove_Task:
            cout << "Enter the task number to remove: ";
            cin >> task_number;
            remove_task(task_number);
            cout << endl;
            break;
        case Complete_Task:
            cout << "Enter the task number to mark as complete: ";
            cin >> task_number;
            complete_task(task_number);
            cout << endl;
            break;
        default:
            cout << "Invalid action." << endl;
            cout << "----------------------------" << endl;
    }
}

void run_task_manager() {
    int action;
    while (true) {
        action = list_tasks();
        do_action(action);
    }
}

int main(){
    cout << endl;
    cout << "============================" << endl;
    cout << "Welcome to the Task Manager!" << endl;
    cout << "============================" << endl;
    cout << "This application allows you to manage your tasks." << endl;
    cout << "You can add, remove, and complete tasks." << endl;
    cout << "Please follow the prompts to manage your tasks." << endl;
    cout << endl;

    run_task_manager();

    return 0;
}
// This is a simple task manager application that allows users to add, remove, and complete tasks.