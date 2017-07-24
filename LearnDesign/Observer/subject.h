#ifndef _SUBJECT_H_
#define _SUBJECT_H_

class Object;

class Subject
{
public:
    Subject() {};
    virtual ~Subject() {}

    virtual void registerObject(Object *)=0;
    virtual void removeObject(Object *)=0;
    virtual void notify()=0;
};

#endif
