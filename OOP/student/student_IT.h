#include "student.h"


class student_IT: public student {
    private:
        string major;
    public:
        student_IT(int id = 0, bool gender = 0, double score = 0, string major = "AI");
        ~student_IT();
        void get_major();
        friend ostream& operator<<(ostream&, const student_IT&);
        bool operator==(const student_IT&);
};