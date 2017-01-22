#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(const vector<int>& nums, int target)
    {
#if BRUTE_FORCE_APPROACH
        // Brute force approach O(n^2)
        int startIdx = 0;
        for (int i = startIdx; i < nums.size() - 1; i++)
        {
            for (int j = startIdx + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    vector<int> solutionPair;
                    solutionPair.push_back(i);
                    solutionPair.push_back(j);

                    return solutionPair;
                }
            }
        }
#else
        // Hash approach O(n)
        std::map<int, int> valueToIndexLookup;
        for (int i = 0; i < (int)nums.size(); ++i)
        {
            int value = nums[i];
            int otherValue = target - value;
            if (valueToIndexLookup.find(otherValue) != valueToIndexLookup.end())
            {
                vector<int> solutionPair = { valueToIndexLookup[otherValue], i };
                return solutionPair;
            }
            
            valueToIndexLookup[value] = i;
        }
#endif

        return vector<int>();
    }
};

TEST_CASE("TwoSum", "[tests]")
{
    Solution solution;
    vector<int> testInput;
    vector<int> solutionPair;

    SECTION("LeetCode Sample Input")
    {
        testInput = { 2, 7, 11, 15 };
        solutionPair = solution.twoSum(testInput, 9);
        REQUIRE(solutionPair.size() == 2);
        REQUIRE(solutionPair[0] == 0);
        REQUIRE(solutionPair[1] == 1);
    }

    SECTION("Empty Input")
    {
        solutionPair = solution.twoSum(testInput, 0);
        REQUIRE(solutionPair.size() == 0);
    }

    SECTION("Single Input")
    {
        testInput = { 1 };
        solutionPair = solution.twoSum(testInput, 1);
        REQUIRE(solutionPair.size() == 0);
    }

    SECTION("No Solution")
    {
        testInput = { 2, 7, 11, 15 };
        solutionPair = solution.twoSum(testInput, 1);
        REQUIRE(solutionPair.size() == 0);
    }

    SECTION("Negative Numbers")
    {
        testInput = { 1, 2, 3, 4, -4, 5 };
        solutionPair = solution.twoSum(testInput, 0);
        REQUIRE(solutionPair.size() == 2);
        REQUIRE(solutionPair[0] == 3);
        REQUIRE(solutionPair[1] == 4);
    }

    SECTION("Duplicates")
    {
        testInput = { 5, 5, 5 };
        solutionPair = solution.twoSum(testInput, 10);
        REQUIRE(solutionPair.size() == 2);
        REQUIRE(solutionPair[0] == 0);
        REQUIRE(solutionPair[1] == 1);
    }
}