#include <iostream>

using namespace std;

class student
{
private:
    int id;
    bool gender;
    double score;
public:
    student *next;
    student(int = 0, bool = 0, double = 0.0);
    ~student();
    friend ostream& operator <<(ostream&, const student&);
    friend istream& operator >>(istream&, student&);
    bool operator ==(const student&);
};


