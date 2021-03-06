# 题目

把二元查找树转变成排序的双向链表

输入一棵二元查找树，将该二元查找树转换成一个排序的双向链表。要求不能创建任何新的结点，只调整指针的指向。

10

|	\

6		14

|	\	|	\

4	8	12	16

转换成双向链表

4=6=8=10=12=14=16。

首先我们定义的二元查找树 节点的数据结构如下：

``` c++
struct BSTreeNode {
  int m_nValue; // value of node
  BSTreeNode *m_pLeft; // left child of node
  BSTreeNode *m_pRight; // right child of node
};
```

# 解题思路

二叉查找树是二叉树的一种，每个结点的值不重复，其性质就是左子树的值均小于根的值，右子树的值均大于根的值，其子树也遵循这一性质。

我们采用中序遍历的方式建树，从而会发现，这一顺序正是二叉查找树由小到大的遍历顺序，所以我们可以利用这一方式让每一次遍历到的结点直接进队，最后的拿到的队列就是排序链表。这里偷懒一下，直接用STL的deque了。

