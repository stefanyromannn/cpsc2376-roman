#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <vector>
#include <memory>
#include "observer.h"

class GradeBook {
public:
    void addObserver(std::shared_ptr<GradeObserver> observer);
    void setGrade(double grade);
    void notifyObservers(double grade);

private:
    std::vector<std::shared_ptr<GradeObserver>> observers;
    double grade;
};

class Averager : public GradeObserver {
public:
    void update(double newGrade) override;
};

class Notifier : public GradeObserver {
public:
    void update(double newGrade) override;
};

#endif
