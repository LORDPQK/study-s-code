#include<iostream>
#include<string>
#include"stack.h"
#include"Tree.h"
using namespace std;

int main() {
	BTree<char> tree = BTree<char>("A(B(E(G(N,H),F(I,J)),C(K,D(L,M))),)");
	cout << "树的括号表示法：" << tree.getatree() << "\n中序遍历：";
	tree.InOrderNotRe();
	cout << "前序遍历:";
	tree.PreOrderNotRe();
	cout << "后序遍历：";
	tree.PostOrderNotRe(tree.GetBTNode());
	tree.FindAllAncenstor('G');
	return 0;
}