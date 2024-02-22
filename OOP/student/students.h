#include <iostream>
#include "student.h"

using namespace std;

class students {
    private:
        student* list;
        int count;
    public:
        explicit students();
        ~students();

        friend ostream& operator<<(ostream&, const students& ss);
        student& operator[](const int& index);

        void add(const student& s);
        void replace(student& s, const int& index);
        int indexOf(const student&);
        void remove(const student&);
        void removeAt(const int& index);
        void update(const int& index);
};