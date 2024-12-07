#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
public:
    Task(const std::string& name, const std::string& description, const std::string& deadline);

    std::string getName() const;
    std::string getDescription() const;
    std::string getDeadline() const;

    void setName(const std::string& name);
    void setDescription(const std::string& description);
    void setDeadline(const std::string& deadline);

private:
    std::string name;
    std::string description;
    std::string deadline;
};

#endif 
