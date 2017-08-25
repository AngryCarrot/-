#include "header.h"

/*��һ���������������������㰴�����һ��һ��ش����������α�ţ��������Ϊ1���������������a��b�������һ���㷨�����a��b�������������ȵı�š�
��������int a,b��Ϊ�������ı�š��뷵��a��b������������ȵı�š�ע�������㱾��Ҳ����Ϊ�������ȡ�*/
/*���ӣ�https://www.nowcoder.com/questionTerminal/70e00e490b454006976c1fdf47f155d9
��Դ��ţ����

//˼·�������������ӽڵ��븸�ڵ�֮��Ĺ�ϵΪroot = child / 2 
//���������ϵ�����a ��= b���������еĽϴ�������2�� ���ѭ��֪��a == b�� 
//����ԭ���������������������
*/
class LCA {
public:
	int getLCANB(int a, int b)
	{
		while (a != b)
		{
			if (a > b)
			{
				a <<= 1;
			}
			else
			{
				b <<= 1;
			}
		}
		return a;
	}
	int getLCA(int a, int b) {
		// write code here
		int result = this->getLCAHelper(1, a, b);
		return result;
	}
private:
	int getLCAHelper(int root, int a, int b)
	{
		if (root == a || root == b)
		{
			return root;
		}
		int l = this->getLCAHelper(2 * root, a, b);
		int r = this->getLCAHelper(2 * root + 1, a, b);
		if (-1 != l && r != -1)
		{
			return root;
		}
		else
		{
			if (-1 == l)
			{
				return r;
			}
			else
			{
				return l;
			}
		}
		return -1;
	}
};