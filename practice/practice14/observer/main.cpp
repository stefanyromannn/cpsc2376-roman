#include <iostream>
#include <vector>
#include <memory>

class Observer {
public:
    virtual void update(float grade) = 0;
};

class GradeBook {
private:
    std::vector<std::shared_ptr<Observer>> observers;
    float grade;
    
public:
    void addObserver(std::shared_ptr<Observer> observer) {
        observers.push_back(observer);
    }

    void setGrade(float newGrade) {
        grade = newGrade;
        notifyObservers();
    }

    float getGrade() const {
        return grade;
    }

    void notifyObservers() {
        for (auto& observer : observers) {
            observer->update(grade);
        }
    }
};

class Averager : public Observer {
private:
    float total;
    int count;

public:
    Averager() : total(0), count(0) {}

    void update(float grade) override {
        total += grade;
        count++;
        std::cout << "Running average: " << total / count << std::endl;
    }
};

class Notifier : public Observer {
private:
    float threshold;

public:
    Notifier(float threshold) : threshold(threshold) {}

    void update(float grade) override {
        if (grade < threshold) {
            std::cout << "Email sent to student@example.com" << std::endl;
        }
    }
};

int main() {

    GradeBook gradeBook;
    auto averager = std::make_shared<Averager>();
    auto notifier = std::make_shared<Notifier>(60.0f);

    gradeBook.addObserver(averager);
    gradeBook.addObserver(notifier);

    float newGrade;
    while (true) {
        std::cout << "Enter grade (or -1 to quit): ";
        std::cin >> newGrade;
        if (newGrade == -1) {
            break;
        }

        gradeBook.setGrade(newGrade);
    }

    return 0;
}
