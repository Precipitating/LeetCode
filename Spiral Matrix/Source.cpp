#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
    enum DIR
    {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        DIR dir = RIGHT;
        vector<int> result;
        int column = 0, row = -1;
        int maxSteps = matrix.size() * matrix[0].size();
        int currSteps = 0;
        // decrease by 1 every cycle so it goes in a spiral inwards.
        int cycleCount = 1;
        result.reserve(maxSteps);

        while (currSteps != maxSteps)
        {
            // LEFT -> DOWN TRANSITION
            if (row == matrix[0].size() - cycleCount && dir == RIGHT) { dir = DOWN; }
            // DOWN -> LEFT TRANSITION
            if (column == matrix.size() - cycleCount && dir == DOWN) { dir = LEFT; }
            // LEFT -> UP TRANSITION
            if (row == (-1 + cycleCount) && dir == LEFT) { dir = UP; ++cycleCount; }
            // UP -> RIGHT TRANSITION
            if (column == (-1 + cycleCount) && dir == UP) { dir = RIGHT; }

            switch (dir)
            {
            case RIGHT: ++row; break;
            case DOWN: ++column; break;
            case LEFT: --row; break;
            case UP: --column; break;
            }
            result.push_back(matrix[column][row]);

            
            ++currSteps;



        }


        
        return result;
        
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16},{17,18,19,20},{21,22,23,24} };
    s.spiralOrder(matrix);
    return 0;
}