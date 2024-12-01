#include <iostream>
#include <vector>
#include <algorithm>

//Task 1--------------------------
int gainMaxValue(std::vector<int>& securityVal, int k) {
    size_t n = securityVal.size();
    int max_sum = INT_MIN;

    for (int start = 0; start < n; ++start) {
        int currentSum = 0;
        int currentNode = start;

        // Iterate through the network
        while (currentNode < n) {
            currentSum += securityVal[currentNode];
            currentNode += k; 
        }

        max_sum = std::max(max_sum, currentSum);
    }

    return max_sum;
}
//!Task1--------------------------

//Task 2--------------------------
struct Vector2 {
    int x;
    int y;

    Vector2(int x, int y) : x(x), y(y) {}

    long squaredDistance(const Vector2& other) const {
        long dx = x - other.x;
        long dy = y - other.y;
        return dx * dx + dy * dy;
    }
};

long closestSquaredDistance(const std::vector<Vector2>& points) {
    size_t n = points.size();
    long minDistance = LONG_MAX;
    
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            long distance_squared = points[i].squaredDistance(points[j]);
            minDistance = std::min(minDistance, distance_squared);
        }
    }

    return minDistance;
}
//!Task2--------------------------


int main() {

    //Task 1
    std::vector<int> securityVal = { 2, -3, 4, 6, 1 };
    int k = 2;
    std::cout << "Maximum security value sum: " << gainMaxValue(securityVal, k) << std::endl;
    //!Task 1
    
    std::cout << "------------------------------------\n";

    //Task 2
    std::vector<Vector2> points = { Vector2(0, 0), Vector2(1, 1), Vector2(2, 2) };
    std::cout << "Closest squared distance: " << closestSquaredDistance(points) << std::endl;
    //!Task 2

    return 0;
}
