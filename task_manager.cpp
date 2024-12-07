#include <iostream>
#include <vector>
#include <limits> 
#include "task.h"

void displayMenu();
void addTask(std::vector<Task>& tasks);
void viewTasks(const std::vector<Task>& tasks);
void updateTask(std::vector<Task>& tasks);
void deleteTask(std::vector<Task>& tasks);
bool promptYesNo(const std::string& message);

int main() {
    std::vector<Task> tasks;
    int choice;

    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1: addTask(tasks); break;
            case 2: viewTasks(tasks); break;
            case 3: updateTask(tasks); break;
            case 4: deleteTask(tasks); break;
            case 5: std::cout << "Exiting...\n"; break;
            default: std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    std::cout << "\n--- Task Manager ---\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. View Tasks\n";
    std::cout << "3. Update Task\n";
    std::cout << "4. Delete Task\n";
    std::cout << "5. Exit\n";
}

void addTask(std::vector<Task>& tasks) {
    std::cin.ignore();
    std::string name, description, deadline;

    std::cout << "Enter task name: ";
    std::getline(std::cin, name);
    std::cout << "Enter task description: ";
    std::getline(std::cin, description);
    std::cout << "Enter task deadline: ";
    std::getline(std::cin, deadline);

    tasks.emplace_back(name, description, deadline);
    std::cout << "Task added successfully.\n";
}

void viewTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks available.\n";
        return;
    }

    std::cout << "\n--- Task List ---\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << "Task " << i + 1 << ":\n";
        std::cout << "  Name: " << tasks[i].getName() << "\n";
        std::cout << "  Description: " << tasks[i].getDescription() << "\n";
        std::cout << "  Deadline: " << tasks[i].getDeadline() << "\n\n";
    }
}

void updateTask(std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks available to update.\n";
        return;
    }

    size_t index;
    std::cout << "Enter task number to update: ";
    std::cin >> index;

    if (index < 1 || index > tasks.size()) {
        std::cout << "Invalid task number.\n";
        return;
    }

    Task& task = tasks[index - 1];
    std::cin.ignore(); // Clear the input buffer

    if (promptYesNo("Do you want to update the task name? (y/n): ")) {
        std::string newName;
        std::cout << "Enter new task name: ";
        std::getline(std::cin, newName);
        task.setName(newName);
    }

    if (promptYesNo("Do you want to update the task description? (y/n): ")) {
        std::string newDescription;
        std::cout << "Enter new task description: ";
        std::getline(std::cin, newDescription);
        task.setDescription(newDescription);
    }

    if (promptYesNo("Do you want to update the task deadline? (y/n): ")) {
        std::string newDeadline;
        std::cout << "Enter new task deadline: ";
        std::getline(std::cin, newDeadline);
        task.setDeadline(newDeadline);
    }

    std::cout << "Task updated successfully.\n";
}

void deleteTask(std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks available to delete.\n";
        return;
    }

    size_t index;
    std::cout << "Enter task number to delete: ";
    std::cin >> index;

    if (index < 1 || index > tasks.size()) {
        std::cout << "Invalid task number.\n";
        return;
    }

    tasks.erase(tasks.begin() + index - 1);
    std::cout << "Task deleted successfully.\n";
}

bool promptYesNo(const std::string& message) {
    char choice;
    std::cout << message;
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
    return (choice == 'y' || choice == 'Y');
}
