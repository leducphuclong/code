#include <iostream>

using namespace std;

class student {
    private:
        int id;
        bool gender;
        double score;
    public:
        student(int id = 0, bool gender = true, double score = 5.0);
        virtual ~student();

        friend ostream& operator<<(ostream& out, const student& s);
        friend istream& operator>>(istream& in, student& s);

        bool operator==(const student& s) const;

};