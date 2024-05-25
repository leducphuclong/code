#include <iostream>
#include <vector>
#include <algorithm>

struct Point {
    double x, y;
};

bool cmp(Point A, Point B) {
    return A.x < B.x || (A.x == B.x && A.y <= B.y);
}

double cross_product(Point O, Point A, Point B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

std::vector<Point> convex_hull(std::vector<Point> A) {
    int n = A.size(), k = 0;
    if (n <= 3)
        return A;
    std::vector<Point> ans(2 * n);
    std::sort(A.begin(), A.end(), cmp);
    for (int i = 0; i < n; i++) {
        while (k >= 2 && cross_product(ans[k - 2], ans[k - 1], A[i]) >= 0) {
            k--;
        }
        ans[k++] = A[i];
    }
    for (int i = n - 1, t = k + 1; i >= 0; i--) {
        while (k >= t && cross_product(ans[k - 2], ans[k - 1], A[i]) >= 0) {
            k--;
        }
        ans[k++] = A[i];
    }
    ans.resize(k - 1);
    return ans;
}

void display(std::vector<Point> p) {
    for (int i = 0; i < p.size(); i++)
        std::cout << "(" << p[i].x << ", " << p[i].y << ")" << std::endl;
}

int main() {
    std::vector<Point> points;
    int n;
    std::cout << "Enter the number of points: ";
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cout << "Enter the coordinates of point " << i << ": ";
        double x, y;
        std::cin >> x >> y;
        Point p;
        p.x = x;
        p.y = y;
        points.push_back(p);
    }
    std::vector<Point> ans = convex_hull(points);
    display(ans);

    return 0;
}