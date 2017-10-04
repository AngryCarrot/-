#include "header.h"

/*��Ŀ����
��һ���Ź�����ַ������飬���������в�����һЩ���ַ����������һ���㷨���ҳ������ַ�����λ�á��㷨�Ĳ��Ҳ��ֵĸ��Ӷ�Ӧ��Ϊlog����
����һ��string����str,ͬʱ���������Сn����Ҫ���ҵ�string x���뷵�ظô���λ��(λ�ô��㿪ʼ)��
����������["a","b","","c","","d"],6,"c"
���أ�3
*/

/*Ψһ�Ĺ�ע���ǵ�str[mid] == ""ʱ�Ĵ�����ʱ��ͨ��str[mid] == ""���޷��ж�Ŀ��λ��mid��߻����ұߡ�
������Ҫ�������ҵ���һ�����ǿյ�λ�ã�����������Ԫ�ض�Ϊ�գ���ֱ����left = mid + 1;*/
class Finder {
public:
	int findString(vector<string> str, int n, string x) {
		// write code here
		int left = 0;
		int right = n - 1;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (str[mid] == "")
			{
				int i = mid;
				while (i >= left && str[i].length() == 0)
				{
					--i;
				}
				if (i < left)
				{
					left = mid + 1;
				}
				else
				{
					if (str[i] == x)
					{
						return i;
					}
					else
					{
						if (str[i] < x)
						{
							left = mid + 1;
						}
						else
						{
							right = mid - 1;
						}
					}
				}
			}
			else
			{
				if (str[mid] == x)
				{
					return mid;
				}
				else
				{
					if (str[mid] < x)
					{
						left = mid + 1;
					}
					else
					{
						right = mid - 1;
					}
				}
			}
		}
		return -1;
	}
};

int main11_5()
{
	return 0;
}