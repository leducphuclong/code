#include <bits/stdc++.h>
using namespace std;

class Point{
    public:
        double x, y;
        Point(double x, double y){
            this->x = x;
            this->y = y;
        }
        Point(){

        }

};

int cross_product(Point O, Point A, Point B){
    int x = (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
    if(x == 0) return 0;
    else if(x > 0) return 1;
    else return 2;
}

vector<Point> Convex_Hull(vector<Point> A){
    int n = A.size();
    if (n < 3) return A;
    vector<Point> hull;

    Point startPoint = A[0];
    for(int i = 0; i < n; i++){
        if(A[i].x < startPoint.x || (A[i].x == startPoint.x && A[i].y < startPoint.y)){
            startPoint = A[i];
        }
    }
    sort(A.begin(), A.end(), [&](Point a, Point b) {
        int o = cross_product(startPoint, a, b);
        if (o == 0) {
            return (a.x - startPoint.x) * (a.x - startPoint.x) + (a.y - startPoint.y) * (a.y - startPoint.y) <
                   (b.x - startPoint.x) * (b.x - startPoint.x) + (b.y - startPoint.y) * (b.y - startPoint.y);
        }
        return (o == 2);
    });
    hull.push_back(startPoint);
    hull.push_back(A[1]);

    for (int i = 2; i < n; i++) {
        while (hull.size() >= 2 && cross_product(hull[hull.size() - 2], hull[hull.size() - 1], A[i]) != 2) {
            hull.pop_back();
        }
        hull.push_back(A[i]);
    }

    return hull;

}

int main(){
    vector<Point> points;
 
    points.push_back({ 0, 3 });
    points.push_back({ 0, 0 });
    points.push_back({ 3, 0 });
    points.push_back({ 3, 3 });
 
    vector<Point> ans = Convex_Hull(points);
 
    for (int i = 0; i < ans.size(); i++)
        cout << "(" << ans[i].x << ", " << ans[i].y << ")"
             << endl;
 
    return 0;
}