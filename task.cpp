#include "task.h"

Task::Task(const std::string& name, const std::string& description, const std::string& deadline)
    : name(name), description(description), deadline(deadline) {}

std::string Task::getName() const { return name; }
std::string Task::getDescription() const { return description; }
std::string Task::getDeadline() const { return deadline; }

void Task::setName(const std::string& name) { this->name = name; }
void Task::setDescription(const std::string& description) { this->description = description; }
void Task::setDeadline(const std::string& deadline) { this->deadline = deadline; }
