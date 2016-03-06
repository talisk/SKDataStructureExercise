# 数据结构练习题 - C++实现

## 第1题 | [解题思路](https://github.com/talisk/SKDataStructureExercise/tree/master/ex001)

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

```c++
struct BSTreeNode {
  int m_nValue; // value of node
  BSTreeNode *m_pLeft; // left child of node
  BSTreeNode *m_pRight; // right child of node
};
```

## 第2题 | [解题思路](https://github.com/talisk/SKDataStructureExercise/tree/master/ex002)

设计包含min函数的栈。

定义栈的数据结构，要求添加一个min函数，能够得到栈的最小元素。

要求函数min、push以及pop的时间复杂度都是O(1)。

## 第3题 | [解题思路](https://github.com/talisk/SKDataStructureExercise/tree/master/ex003)

求子数组的最大和

输入一个整形数组，数组里有正数也有负数。数组中连续的一个或多个整数组成一个子数组，每个子数组都有一个和。求所有子数组的和的最大值。要求时间复杂度为O(n)。

例如输入的数组为1, -2, 3, 10, -4, 7, 2, -5，和最大的子数组为3, 10, -4, 7, 2，因此输出为该子数组的和18。

## 第4题 | [解题思路](https://github.com/talisk/SKDataStructureExercise/tree/master/ex004)

在二元树中找出和为某一值的所有路径

输入一个整数和一颗二元树，从树的根结点开始往下访问一直到叶结点所经过的所有结点形成一条路径。打印出和与输入整数相等的所有路径。

例如输入整数22和如下二元树：

10

|	\

5		12

|	\

4	7

则打印出两条路径：10, 12和10, 5, 7。

二元树结点的数据结构定义为：

```c++
struct BinaryTreeNode { // a node in the binary tree
	int m_nValue; // value of node
  	BinaryTreeNode *m_pLeft; // left child of node
	BinaryTreeNode *m_pRight; // right child of node
};
```

## 第5题 | [解题思路](https://github.com/talisk/SKDataStructureExercise/tree/master/ex005)

查找最小的k个元素。输入n个证书，输出其中最小的k个。

例如输入1, 2, 3, 4, 5, 6, 7, 8这八个数字，则最小的四个数字为1, 2, 3, 4, 5。

## 第6题 | [解题思路](https://github.com/talisk/SKDataStructureExercise/tree/master/ex006)

给你10分钟的时间，根据上排给出十个数，要求下排每个数都是先前上排那十个数在下排出现的次数。

上排的十个数如下：【0, 1, 2, 3, 4, 5, 6, 7, 8, 9】

举一个例子，

数值：0, 1, 2, 3, 4, 5, 6, 7, 8, 9

分配：6, 2, 1, 0, 0, 0, 1, 0, 0, 0

0在下排出现6次，1在下排出现2次……以此类推。

## 第7题 | [解题思路](https://github.com/talisk/SKDataStructureExercise/tree/master/ex007)

编程判断两个链表是否相交。给出两个单向链表的头指针，比如h1，h2，判断这两个链表是否相交。为了简化问题，我们假设两个链表均不带环。