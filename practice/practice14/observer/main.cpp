#include "gradebook.h"
#include <memory>

int main() {
    std::shared_ptr<GradeBook> gradeBook = std::make_shared<GradeBook>();
    std::shared_ptr<Averager> averager = std::make_shared<Averager>();
    std::shared_ptr<Notifier> notifier = std::make_shared<Notifier>();

    gradeBook->addObserver(averager);
    gradeBook->addObserver(notifier);

    gradeBook->setGrade(95.5);
    gradeBook->setGrade(87.0);

    return 0;
}
