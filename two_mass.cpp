#include <unordered_map>
#include <vector>

std::vector<int> IntersectionOfMas(std::vector<int> a, std::vector<int> b)
{
	std::unordered_map <int, unsigned> count;
	std::vector <int> result;
	for (int elem : a)
	{
		count[elem]++;
	}

	for (int elem : b)
	{
		if (count[elem])
		{
			count[elem]--;
			result.push_back(elem);
		}
	}
	return result;
}
