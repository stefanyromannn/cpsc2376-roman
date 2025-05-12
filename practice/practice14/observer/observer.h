#ifndef OBSERVER_H
#define OBSERVER_H

#include <memory>

class GradeBook;

class Observer {
public:
    virtual void update(double newGrade) = 0;
    virtual ~Observer() = default;
};

class GradeObserver : public Observer {
public:
    virtual void update(double newGrade) override = 0;
    virtual ~GradeObserver() = default;
};

#endif
