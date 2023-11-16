#include <iostream>

using namespace std;

class doctor {
    private:
        string name, id;
    public:
        doctor(string id = "Unknown", string name = "Unknown") : name(name), id(id) {};  
        void view_name();  
        void view_id();
};