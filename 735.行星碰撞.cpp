#include "lib/leetcode.h"
using namespace std;

/*
 * @lc app=leetcode.cn id=735 lang=cpp
 *
 * [735] 行星碰撞
 */

// @lc code=start
class Solution {
   public:
    vector<int> asteroidCollision(vector<int> &asteroids) {
        auto willCollide = [](int a, int b) { return a > 0 && b < 0; };
        auto remains = vector<int>();
        for (int asteroid : asteroids) {
            while (!remains.empty() && willCollide(remains.back(), asteroid)) {
                auto collider = remains.back();
                remains.pop_back();

                if (abs(collider) > abs(asteroid))
                    asteroid = collider;
                else if (abs(collider) == abs(asteroid))
                    asteroid = 0;
            }
            if (asteroid) remains.push_back(asteroid);
        }
        return remains;
    }
};
// @lc code=end
int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto arr = j.get<vector<int>>();
        print(Solution().asteroidCollision(arr));
    }
}