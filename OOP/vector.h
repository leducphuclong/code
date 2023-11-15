#include <iostream>

using namespace std;

class vector
{
private:
    int *data, size;
public:
    vector(int = 10, int = 0);
    vector(const vector&);
    ~vector();

    friend ostream& operator<<(ostream&, const vector&);
    int& operator[](int) const;
    void view();
    void operator=(const vector&);
};
