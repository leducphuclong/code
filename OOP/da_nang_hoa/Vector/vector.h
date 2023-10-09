#include <iostream>

using namespace std;

class vector {
    private:
    double* address;
    unsigned size;
    public:
        vector(unsigned = 1, double = 0);
        vector(const vector&);
        ~vector();
        friend istream& operator>>(istream&, vector&);
        friend ostream& operator<<(ostream&, const vector&);
        double& operator[](unsigned);  
        void view(); 
        const vector& operator=(const vector&);
};
