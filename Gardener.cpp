#include "Gardener.h"

/**
 * @details Constructor for the Gardener class
 * constructor initializes the queue with 5 default gardener employees
 */
Gardener::Gardener() : Employee()
{
    for(int i = 1; i <= 5; i++)
    {
        employees.push(EmployeePerson("gardener" + to_string(i)));
    }
}

/**
 * @details Handles gardening-related requests
 * @param task The request to handle
 */
void Gardener::handle(Requests* task)
{
    string taskType = task->getType();
    
    if(taskType == "Place" || taskType == "Water" || taskType == "Fertilise" || taskType == "Prune")
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
                task->setParam(this);
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

/**
 * @details Hires a new gardener by adding a new EmployeePerson to the queue
 * @param name The name of the new gardener
 */
void Gardener::HireGardener(string name)
{
    employees.push(EmployeePerson(name));
}

/**
 * @details Updates the gardener queue by moving the front gardener to the back of the queue
 */
void Gardener::updateQueue()
{
    if(!employees.empty())
    {
        EmployeePerson current = employees.front();
        employees.pop();
        employees.push(current);
    }
}
