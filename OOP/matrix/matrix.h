#include <iostream>

using namespace std;

class matrix {
    private:
        int NoRow, NoColumn, **data;
        static int GarbageValue;
    public:
        explicit matrix(int row = 2, int column = 2, int = GarbageValue);
        ~matrix();

        void display() const;

        friend ostream& operator<<(ostream&, const matrix&);
        int& operator()(int iRow, int iCol);    
};
