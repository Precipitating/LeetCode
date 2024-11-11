#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Point
{
    int x, y;
    bool operator==(const Point& other) { return x == other.x && y == other.y; }
    bool operator!=(const Point& other) { return x != other.x || y != other.y; }
    void moveTowards(const Point& other)
    {
        x += x == other.x ? 0 : other.x > x ? 1 : -1;
        y += y == other.y ? 0 : other.y > y ? 1 : -1;
    }
};
class Solution
{
public:
    
    // returns all possible moves of a chess piece
    vector<Point> GetMoves(const string& piece, Point p)
    {
        vector<Point> result{ {p.x, p.y} };

        if (piece == "rook" || piece == "queen")
        {
            for (Point step : horizontalSteps)
            {
                int i = p.x + step.x;
                int j = p.y + step.y;

                // stay in bounds of chess table & get all possible moves
                while (i >= 0 && i < 8 && j >= 0 && j < 8)
                {
                    result.push_back({ i,j });
                    i += step.x;
                    j += step.y;
                }
            }
        }

        if (piece == "bishop" || piece == "queen")
        {
            for (Point step : diagonalSteps)
            {
                int i = p.x + step.x;
                int j = p.y + step.y;

                // stay in bounds of chess table & get all possible moves
                while (i >= 0 && i < 8 && j >= 0 && j < 8)
                {
                    result.push_back({i,j});
                    i += step.x;
                    j += step.y;
                }
            }
        }
        return result;

    }
    bool WillIntersect(Point a, Point a2, Point b, Point b2)
    {
        // move start pos to end pos and check if they intersect
        while (a != a2 || b != b2)
        {
            a.moveTowards(a2);
            b.moveTowards(b2);

            if (a == b) { return true; }
        }

        return false;
    }

    // check if destination will intersect or not
    bool IsValidDestination(vector<Point>& dest)
    {
        for (int i = 0; i < dest.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (WillIntersect(pos[i], dest[i], pos[j], dest[j])) { return false; }
            }
                
        }


        return true;
    }
    // DFS all possible moves for each piece and check if they forms a valid path
    int DFS(int i, vector<string>& pieces, vector<Point>& dest)
    {
        if (i == pieces.size())
        {
            return IsValidDestination(dest) ? 1 : 0;
        }

        int result = 0;

        for (Point move : GetMoves(pieces[i], pos[i]))
        {
            dest[i] = move;
            result += DFS(i + 1, pieces, dest);
        }

        return result;

    }
    int countCombinations(vector<string>& pieces, vector<vector<int>>& positions) 
    {
        for (size_t i = 0; i < pieces.size(); ++i)
        {
            pos.push_back({ positions[i][0] - 1, positions[i][1] - 1 });

        }
        vector<Point> dest(pieces.size());

        return DFS(0, pieces, dest);

    }

private:
    vector<Point> horizontalSteps = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
    vector<Point> diagonalSteps = { {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
    vector<Point> pos;
};

int main()
{
    Solution s;
    vector<string> pieces = { "rook" };
    vector<vector<int>> pos = { {1,1} };
    s.countCombinations(pieces, pos);
    return 0;
}