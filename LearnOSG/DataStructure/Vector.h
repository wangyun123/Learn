#ifndef _MY_VECTOR_H_
#define _MY_VECTOR_H_

#include <Windows.h>

class Vector{
public:
	Vector();
	Vector(DWORD dwSize);
	~Vector();

public:
	void at(DWORD dwIndex, int* pEle);
	void push_back(int elem);
	void pop_back();
	void insert(DWORD dwIndex, int elem);
	void erase(DWORD dwIndex);
	
	void clear();
	bool empty();
	DWORD size();
	void capacity();

	void print();
private:
	void expend();

private:
	DWORD m_dwIndex;	//当前索引号
	DWORD m_dwLength;	//当前数组长度
	DWORD m_dwInitLen;	//初始化数组长度
	DWORD m_dwIncrement;//默认扩容长度

	int* m_pVecotr;		//数组指针
};
#endif //_MY_VECTOR_H_