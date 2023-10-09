class Point {
    // Private
        double xVal, yVal;
        const int z;
        static int n;
        const static int m = 10;
    public: 
        Point(double = 10 , double = 10, double = 222222);
        ~Point();
        void TT(double);
        void Show();
        double Get_xVal();
        void Set_xVal(double);
    friend void ChangePoint(Point&);
    static void Print_Counters();
};
