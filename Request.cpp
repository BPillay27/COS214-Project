#include "Request.h"

Request::Request(string t) : type(t)
{

}

Request::~Request()
{

}

string Request::getType()
{
    return type;
}

MovePlant::MovePlant(string id, string dest) : Request("MovePlant"), plantId(id), destination(dest)
{

}

void MovePlant::execute()
{

}

string MovePlant::getPlantId()
{
    return plantId;
}

string MovePlant::getDestination()
{
    return destination;
}

WaterPlant::WaterPlant(string id) : Request("WaterPlant"), plantId(id)
{

}

void WaterPlant::execute()
{

}

string WaterPlant::getPlantId()
{
    return plantId;
}

AnswerQuestion::AnswerQuestion(string q) : Request("AnswerQuestion"), question(q)
{
    needsGardenerHelp = false;
}

void AnswerQuestion::execute()
{

}

string AnswerQuestion::getQuestion()
{
    return question;
}

void AnswerQuestion::setNeedsGardenerHelp(bool needs)
{
    needsGardenerHelp = needs;
}

bool AnswerQuestion::getNeedsGardenerHelp()
{
    return needsGardenerHelp;
}

ProcessPayment::ProcessPayment(double amt) : Request("ProcessPayment"), amount(amt)
{

}

void ProcessPayment::execute()
{

}

double ProcessPayment::getAmount()
{
    return amount;
}

CancelTransaction::CancelTransaction(string id) : Request("CancelTransaction"), transactionId(id)
{

}

void CancelTransaction::execute()
{

}

string CancelTransaction::getTransactionId()
{
    return transactionId;
}

TillAssistance::TillAssistance(string iss) : Request("TillAssistance"), issue(iss)
{

}

void TillAssistance::execute()
{

}

string TillAssistance::getIssue()
{
    return issue;
}
