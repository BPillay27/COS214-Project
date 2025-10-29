#include "Gardener.h"

Gardener::Gardener() : Employee()
{
    for(int i = 1; i <= 5; i++)
    {
        employees.push(EmployeePerson("gardener" + to_string(i)));
    }
}

void Gardener::handle(Request* task)
{
    string taskType = task->getType();
    
    if(taskType == "MovePlant" || taskType == "WaterPlant" || taskType == "TillAssistance" || taskType == "AnswerQuestion")
    {
        int queueSize = employees.size();
        bool handled = false;
        
        for(int i = 0; i < queueSize && !handled; i++)
        {
            EmployeePerson current = employees.front();
            
            if(current.isAvailable)
            {
                current.isAvailable = false;
                employees.pop();
                employees.push(current);
                
                task->execute();
                
                queue<EmployeePerson> tempQueue;
                while(!employees.empty())
                {
                    EmployeePerson person = employees.front();
                    employees.pop();
                    if(person.name == current.name)
                    {
                        person.isAvailable = true;
                    }
                    tempQueue.push(person);
                }
                employees = tempQueue;
                
                handled = true;
            }
            else
            {
                employees.pop();
                employees.push(current);
            }
        }
        
        if(!handled && next != nullptr)
        {
            next->handle(task);
        }
    }
    else if(next != nullptr)
    {
        next->handle(task);
    }
}

void Gardener::HireGardener(string name)
{
    employees.push(EmployeePerson(name));
}

void Gardener::updateQueue()
{
    if(!employees.empty())
    {
        EmployeePerson current = employees.front();
        employees.pop();
        employees.push(current);
    }
}
