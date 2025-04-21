#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;



#pragma region Bruteforce variadic template method
// bruteforce method, using varidiac templates
//void ReturnDifference(set<int>& first, const set<int>& second)
//{
//	vector<int> result;
//	for (auto it = first.begin(); it != first.end(); ++it)
//	{
//		if (second.find(*it) == second.end())
//		{
//			result.push_back(*it);
//		}
//
//	}
//	for (auto it = second.begin(); it != second.end(); ++it)
//	{
//		if (first.find(*it) == first.end())
//		{
//			result.push_back(*it);
//		}
//
//	}
//
//	first = set<int>(result.begin(), result.end());
//
//
//}
//
//
//
//template<typename... Vectors>
//vector<int> Solve(vector<int>& first, const Vectors&... vecs)
//{
//	vector<int> result;
//	set<int> firstSet(first.begin(), first.end());
//	set<int> otherSet;
//
//	(...,(otherSet.insert(vecs.begin(), vecs.end()),ReturnDifference(firstSet, otherSet), otherSet.clear()));
//
//
//
//	return vector<int>(firstSet.begin(), firstSet.end());
//}
#pragma endregion



#pragma region Built in C++ symmetric difference function

void ReturnDifference(vector<int>& first, const vector<int>& second)
{
	vector<int> diff;
	set_symmetric_difference(first.begin(), first.end(), second.begin(), second.end(), back_inserter(diff));
	first = std::move(diff);
}

template<typename... Vectors>
vector<int> Solve(vector<int>& first, Vectors&... vecs)
{
	vector<int> result;
	sort(first.begin(), first.end());
	first.erase(unique(first.begin(), first.end()), first.end());
	(..., (sort(vecs.begin(), vecs.end()), vecs.erase(unique(vecs.begin(), vecs.end()), vecs.end())));
	(..., ReturnDifference(first, vecs));



	return first;
}



#pragma endregion




int main()
{
	vector<int> first = { 3, 3, 3, 2, 5 };
	vector<int> second = { 2, 1, 5, 7 };
	vector<int> third = { 3, 4, 6, 6 };
	vector<int> fourth = { 1, 2, 3 };
	vector<int> fifth = { 5, 3, 9, 8 };
	vector<int> sixth = { 1 };
	Solve(first, second, third, fourth, fifth, sixth);



	return 0;
}