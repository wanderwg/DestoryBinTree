#include "BinTree.h"
#include <malloc.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "Queue.h"


BTNode* CopyBinTree(BTNode* pRoot) {
	BTNode* newpRoot = NULL;
	if (pRoot == NULL)
		return NULL;
	newpRoot = BuyBinTreeNode(pRoot->_data);
	newpRoot->_pLeft = CopyBinTree(pRoot->_pLeft);
	newpRoot->_pRight = CopyBinTree(pRoot->_pRight);
	return newpRoot;
}

void DestoryBinTree(BTNode** pRoot) {
	if (*pRoot) {
		DestoryBinTree(&(*pRoot)->_pLeft);
		DestoryBinTree(&(*pRoot)->_pRight);
		free(*pRoot);
		*pRoot = NULL;
	}
}

