#ifndef _SUBJECT_H_
#define _SUBJECT_H_

class Observer;

class Subject
{
public:
    Subject() {};
    virtual ~Subject() {}

    virtual void registerObject(Observer *)=0;
    virtual void removeObject(Observer *)=0;
    virtual void notify() const=0;
};

#endif
