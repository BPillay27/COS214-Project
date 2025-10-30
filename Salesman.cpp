#include "Salesman.h"

Salesman::Salesman() : Employee()
{
    for(int i = 1; i <= 5; i++)
    {
        employees.push(EmployeePerson("salesman" + to_string(i)));
    }
}

void Salesman::handle(Request* task)
{
    string taskType = task->getType();
    
    if(taskType == "AnswerQuestion" || taskType == "ProcessPayment" || taskType == "CancelTransaction")
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
                
                if(taskType == "AnswerQuestion")
                {
                    AnswerQuestion* question = dynamic_cast<AnswerQuestion*>(task);
                    if(question && question->getNeedsGardenerHelp())
                    {
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
                        
                        if(next != nullptr)
                        {
                            next->handle(task);
                        }
                        return;
                    }
                }
                
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

void Salesman::HireSalesman(string name)
{
    employees.push(EmployeePerson(name));
}

void Salesman::updateQueue()
{
    if(!employees.empty())
    {
        EmployeePerson current = employees.front();
        employees.pop();
        employees.push(current);
    }
}
