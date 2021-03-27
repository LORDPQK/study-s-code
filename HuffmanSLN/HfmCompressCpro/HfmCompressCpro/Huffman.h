#ifndef HUFFMAN_H
#define HUFFMAN_H

//Huffman's tree node
typedef struct  {
	int weight;
	int parent;
	int lchild;
	int rchild;

}HTNode, *HuffmanTree;

typedef char **HuffmanCode;//Huffman Code

//create huffman tree
int CreateHuffmanTree(HuffmanTree pHT, int weight[], int n);
void Select(HuffmanTree &pHT, int i, int &s1, int &s2);
int TestHuTree(HuffmanTree pHT);
int HuffmanCoding(HuffmanCode &pHC, HuffmanTree &pHT);
void TestHufCode(int root, HuffmanTree &pHT, HuffmanCode &pHC);
#endif // !HUFFMAN_H


