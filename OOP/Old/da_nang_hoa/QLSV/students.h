#include "student.h"

class students
{
private:
    student *address;
    int quantity;
public:
    students();
    ~students();
    friend ostream& operator<<(ostream&, const students&);
    friend student& operator [](const int&);
    void add(const student&);
    void insert(const student&, const int&);
    int index(const student&);
    void remove(const student&);
    void remove(const int&);
    void update(const int&, const double&);
};

students::students() {
    this->quantity = 0;
    this->address = NULL;
}

students::~students()
{
    delete this->address;
}
