#include "header.h"

/*有一棵无穷大的满二叉树，其结点按根结点一层一层地从左往右依次编号，根结点编号为1。现在有两个结点a，b。请设计一个算法，求出a和b点的最近公共祖先的编号。
给定两个int a,b。为给定结点的编号。请返回a和b的最近公共祖先的编号。注意这里结点本身也可认为是其祖先。*/
/*链接：https://www.nowcoder.com/questionTerminal/70e00e490b454006976c1fdf47f155d9
来源：牛客网

//思路：满二叉树的子节点与父节点之间的关系为root = child / 2 
//利用这个关系，如果a ！= b，就让其中的较大数除以2， 如此循环知道a == b， 
//即是原来两个数的最近公共祖先
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