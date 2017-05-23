#ifndef _MY_LIST_H_
#define _MY_LIST_H_

#include <Windows.h>

typedef struct _NODE{
	int data;
	_NODE* pNext;
}NODE, *PNODE;

class List{
public:
	List();
	~List();

public:
	bool isEmpty();
	void clear();
	DWORD getElement(DWORD dwIndex, int& elem);
	DWORD getElementIndex(int& elem);
	DWORD find(int elem);	// 查找某个数据
	DWORD insert(DWORD dwIndex, int elem);	// 指定位置插入数据
	DWORD push_back(int elem);	// 尾部插入数据
	DWORD pop_back();			// 尾部删除数据
	DWORD remove(DWORD dwIndex);// 删除指定数据
	DWORD getSize();			// 获取链表长度

	void print();
private:
	PNODE getIndexCurNode(DWORD dwIndex);
	PNODE getIndexPrevNode(DWORD dwIndex);
	PNODE getIndexNextNode(DWORD dwIndex);
private:
	PNODE m_pListHead;
	DWORD m_dwLength;
};


#endif //_MY_LIST_H_