#include <iostream>

using namespace std;

class patient {
    private:
        string name, id;
    public:
        patient(string id = "Unknown", string name = "Unknown") : name(name), id(id) {};  
        void view_name();
        void view_id();
};