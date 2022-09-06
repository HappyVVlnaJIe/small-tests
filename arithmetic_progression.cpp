#include <vector>
#include <unordered_map>

struct ProgressionResult
{
	int start, end, step = 0, number; //где number это добавленное число
};

ProgressionResult ProgressioтAnalysis(std::vector<int> list)
{
	ProgressionResult result;
	result.start = list[0];
	result.end = list[0];
	std::unordered_map<int, int> count;
	for (size_t i = 0; i < list.size(); i++)
	{
		if (result.start > list[i])
		{
			result.start = list[i];
		}

		if (result.end < list[i])
		{
			result.end = list[i];
		}
		count[list[i]]++;
		if (count[list[i]] > 1)
		{
			result.number = list[i];
		}
	}
	if (list.size() != 2)
	{
		result.step = (result.end - result.start) / (list.size() - 2); // -1 т.к. К списку добавили одно число, уже имеющееся в нем
	}
	return result;
}

int main()
{
	ProgressionResult result = ProgressioтAnalysis({ 1,1 });
	return 0;
}