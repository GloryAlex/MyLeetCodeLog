#include "LeetCode.h"
using namespace std;

class Solution
{
private:
    inline int getArea(const vector<int> &rectangle)
    {
        return (rectangle[2] - rectangle[0]) * (rectangle[3] - rectangle[1]);
    }
    inline vector<pair<int, int>> generateAllSide(const vector<int> &r)
    {
        return {
            {r[0], r[1]}, {r[0], r[3]}, {r[2], r[1]}, {r[2], r[3]}};
    }

public:
    struct pair_hash
    {
        inline std::size_t operator()(const std::pair<int, int> &v) const
        {
            return v.first * 31 + v.second;
        }
    };
    bool isRectangleCover(vector<vector<int>> &rectangles)
    {
        //first, get the 4 points of the big rectangle
        vector<int> bigRect = {INT_MAX, INT_MAX, INT_MIN, INT_MIN};
        unordered_set<pair<int, int>, pair_hash> dict;

        int totalArea = 0;
        for (auto &i : rectangles)
        {
            //check area
            totalArea += getArea(i);
            auto allPoints = generateAllSide(i);
            //check points
            for (auto i : allPoints)
            {
                if (dict.count(i))
                    dict.erase(i);
                else
                    dict.insert(i);
            }
            //caculate big rectangle
            for (int j = 0; j < 2; j++)
            {
                bigRect[j] = min(bigRect[j], i[j]);
                bigRect[j + 2] = max(bigRect[j + 2], i[j + 2]);
            }
        }
        //remove last four points
        auto bigRecPoints = generateAllSide(bigRect);
        for (auto i : bigRecPoints){
                if (dict.count(i))
                    dict.erase(i);
                else
                    dict.insert(i);
        }

        return dict.empty() && totalArea == getArea(bigRect);
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str;
        in >> str;
        auto matrix = getMatrix(str);
        print(Solution().isRectangleCover(matrix));
    }
}