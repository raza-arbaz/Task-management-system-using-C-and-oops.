#include<bits/stdc++.h>
using namespace std;

class Task {
public:
	string title;
	string description;
    
	bool completed;

	Task(string& title, string& description)
		: title(title), description(description), completed(false) {}
};

class TaskManager {
private: 
	vector<Task> tasks;
	

public:
	void addTask(string& name, string& description) {
		tasks.emplace_back(name, description);
	}

	void deleteTask(int index) {
		if (index >= 0 && index < tasks.size()) {
			tasks.erase(tasks.begin() + index);
		}
	}

	void markTaskAsDone(int index) {
		if (index >= 0 && index < tasks.size()) {
			tasks[index].completed = true;
		}
	}

    void sortByTitle(){
        sort(tasks.begin(), tasks.end(), [](const Task &a, const Task
        &b){return a.title < b.title;});

    }	

	void listTasks() {
		int index = 0;
		for (const auto& task : tasks) {
			cout << index << ". ";
			cout << "Title: " << task.title << ", ";
			cout << "Description: " << task.description << ", ";
			// cout << "priority: " << task.priority<< ", ";
			cout << "Status: " << (task.completed ? "Done" : "Not Done") << '\n';
			index++;
		}
	}
};

int main() {

	TaskManager obj;
	int choice;
	std::string title, description;
	do {
		cout << "Task Management Application\n";
		cout << "1. Add Task\n";
		cout << "2. Delete Task\n";
		cout << "3. Mark Task as Done\n";
		cout << "4. List Tasks\n";
		cout << "5. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter task title: ";
			cin.ignore();
			getline(std::cin, title);
			cout << "Enter task description: ";
			getline(std::cin, description);
			obj.addTask(title, description);
			break;
		case 2:
			cout << "Enter the task index to delete: ";
			int deleteIndex;
			cin >> deleteIndex;
			obj.deleteTask(deleteIndex);
			break;
		case 3:
			cout << "Enter the task index to mark as done: ";
			int doneIndex;
			cin >> doneIndex;
			obj.markTaskAsDone(doneIndex);
			break;
		case 4:
			obj.listTasks();
			break;        
		
		default:
			std::cout << "Invalid choice. Please try again.\n";
			break;
		}

	} while (choice != 5);

	return 0;
}
