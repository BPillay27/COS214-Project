#ifndef SUBJECT_H
#define SUBJECT_H

class Requests;
class Subject{
    public:
        Subject(){};
        virtual void notify(Requests* request)=0;
};

#endif