#include <iostream>
#include <vector>
#include <string>
struct Task {
    std::string description;
    // 后续再扩展: int id; bool done; std::chrono::system_clock::time_point due;
};
void printMenu() {
    std::cout << "=== CLI Todo ===\n"
              << "1. Add\n"
              << "2. List\n"
              << "3. Exit\n> ";
}

void addTask(std::vector<Task>& tasks);   // 声明
void listTasks(const std::vector<Task>& tasks); // 声明
void addTask(std::vector<Task>& tasks) {
    std::cout << "Enter task description: ";
    std::string line;
    std::cin.ignore();                 // 清空上次残留的 '\n'
    std::getline(std::cin, line);
    tasks.push_back(Task{line});
    std::cout << "Added: " << line << "\n\n";
}
void listTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks yet.\n\n";
        return;
    }
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << tasks[i].description << '\n';
    }
    std::cout << '\n';
}
int main() {
    std::vector<Task> tasks;
    while (true) {
        printMenu();
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1: addTask(tasks);   break;
            case 2: listTasks(tasks); break;
            case 3: return 0;
            default: std::cout << "Invalid choice\n\n";
        }
    }
}