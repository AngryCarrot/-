#include "header.h"


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) { }
};

/*�����һ���㷨��Ѱ�Ҷ�������ָ��������һ����㣨����������ĺ�̣���
�������ĸ����ָ��TreeNode* root�ͽ���ֵint p���뷵��ֵΪp�Ľ��ĺ�̽���ֵ����֤����ֵ���ڵ�����С�ڵ���100000��û���ظ�ֵ���������ں�̷���-1��*/
class Successor {
public:
	int findSucc(TreeNode* root, int p) {
		// write code here
	}
};