#pragma once

#include "header.h"

class CatDogAsylum {
public:
	vector<int> asylum(vector<vector<int> > ope) {
		// write code here
		vector<int> result;
		for (auto& item : ope)
		{
			switch (item[0])
			{
			case 1:
				if (item[1] > 0)
				{
					dog.push(item[1]);
					dogTime.push(count++);
				}
				else
				{
					if (item[1] < 0)
					{
						cat.push(item[1]);
						catTime.push(count++);
					}
				}
				break;
			case 2:
				switch (item[1])
				{
				case 0:
					if (dog.empty() && cat.empty())
					{
						break;
					}
					else
					{
						if (dog.empty())
						{
							result.emplace_back(cat.front());
							cat.pop();
							catTime.pop();
						}
						else
						{
							if (cat.empty())
							{
								result.emplace_back(dog.front());
								dog.pop();
								dogTime.pop();
							}
							else
							{
								int d = dogTime.front();
								int c = catTime.front();
								if (d < c)
								{
									result.emplace_back(dog.front());
									dog.pop();
									dogTime.pop();
								}
								else
								{
									result.emplace_back(cat.front());
									cat.pop();
									catTime.pop();
								}
							}
						}
					}
					break;
				case 1:
					if (!dog.empty())
					{
						result.emplace_back(dog.front());
						dog.pop();
						dogTime.pop();
					}
					break;
				case -1:
					if (!cat.empty())
					{
						result.emplace_back(cat.front());
						cat.pop();
						catTime.pop();
					}
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}
		}
		return result;
	}
private:
	queue<int> cat;
	queue<int> dog;
	queue<int> catTime;
	queue<int> dogTime;
	static int count;
};
int CatDogAsylum::count = 0;
//测试用例:
//[[1, -5], [1, -1], [1, 9], [1, 9], [2, 0], [2, 1], [1, -8], [2, 1], [1, -71], [1, -92], [1, 18], [1, 91], [1, 61], [2, -1], [1, -35], [1, 95], [1, -49], [1, 9], [1, 78], [2, 0], [1, 91], [1, -96], [2, -1], [2, 0], [2, -1], [2, 1], [1, 38], [2, 0], [1, 45], [2, 0], [1, -51], [2, 1], [2, 1], [2, -1], [1, 39], [1, 59], [1, 45], [2, 0], [1, -70], [2, 0], [1, 23], [1, 88], [1, 83], [1, 69], [1, -78], [1, -3], [1, -9], [1, -20], [1, -74], [1, -62], [1, 5], [1, 55], [1, -36], [1, -21], [1, -94], [1, -27], [1, -69], [2, 0], [1, -30], [1, -84], [2, 0], [2, 0], [2, -1], [1, 92], [1, 60], [2, 1], [2, 0], [1, -63], [2, 0], [1, -87], [1, 66], [2, 0], [1, 17], [2, 0], [2, 1], [1, -41], [1, -3], [1, -29], [1, 72], [2, 1], [1, 35], [1, 81], [1, -83], [1, -17], [1, 36], [1, 99], [1, -17], [1, 8], [2, 0], [1, 80], [1, 50], [1, 80], [2, 0], [1, -48], [1, -82], [1, -63], [1, 2], [2, 1], [1, -43], [1, 59], [1, 93], [1, 55], [1, -93], [2, -1], [1, 2], [1, 13], [2, 0]]

//对应输出应该为 :
//[-5, 9, 9, -1, -8, -71, -92, -35, 18, 91, 61, 95, 9, -49, 78, 91, -96, 38, 45, -51, 39, 59, 45, -70, 23, 88, 83, 69, -78, 5, -3, -9]

//你的输出为 :
//[-5, 9, 9, 18, -5, 91, -5, 61, 95, -5, -5, 9, 78, 91, -5, -5, -5, -5, -5, 38, 45, -5, -5, -5, -5, 39, 59, -5, -5, 45, 23, -5]