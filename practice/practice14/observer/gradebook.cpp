#include "gradebook.h"
#include <iostream>

void GradeBook::addObserver(std::shared_ptr<GradeObserver> observer) {
    observers.push_back(observer);
}

void GradeBook::setGrade(double grade) {
    this->grade = grade;
    notifyObservers(grade);
}

void GradeBook::notifyObservers(double grade) {
    for (auto& observer : observers) {
        observer->update(grade);
    }
}

void Averager::update(double newGrade) {
    std::cout << "New grade for Averager: " << newGrade << std::endl;
}

void Notifier::update(double newGrade) {
    std::cout << "New grade for Notifier: " << newGrade << std::endl;
}
