#ifndef REQUEST_H
#define REQUEST_H

#include <string>

using namespace std;

class Request {
protected:
    string type;

public:
    Request(string t);
    virtual ~Request();
    string getType();
    virtual void execute() = 0;
};

class MovePlant : public Request {
private:
    string plantId;
    string destination;

public:
    MovePlant(string id, string dest);
    void execute();
    string getPlantId();
    string getDestination();
};

class WaterPlant : public Request {
private:
    string plantId;

public:
    WaterPlant(string id);
    void execute();
    string getPlantId();
};

class AnswerQuestion : public Request {
private:
    string question;
    bool needsGardenerHelp;

public:
    AnswerQuestion(string q);
    void execute();
    string getQuestion();
    void setNeedsGardenerHelp(bool needs);
    bool getNeedsGardenerHelp();
};

class ProcessPayment : public Request {
private:
    double amount;

public:
    ProcessPayment(double amt);
    void execute();
    double getAmount();
};

class CancelTransaction : public Request {
private:
    string transactionId;

public:
    CancelTransaction(string id);
    void execute();
    string getTransactionId();
};

class TillAssistance : public Request {
private:
    string issue;

public:
    TillAssistance(string iss);
    void execute();
    string getIssue();
};

#endif