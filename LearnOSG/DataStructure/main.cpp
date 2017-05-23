#include <stdio.h>
#include "Vector.h"
#include "List.h"

// struct _Node{
// 	int data;
// 	struct _Node* next;
// };
// 
// typedef struct _Node Node;
// typedef Node *List;
// 
// void CreateList()
// {
// 
// }
// 
// void print(List head)
// {
// 	Node* 
// 	while (head!=NULL)
// 	{
// 		Node node = *head->next;
// 		printf("%d\n", );
// 	}
// }

int main(int argc, char* argv[])
{
#if 0
	Vector vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(6);

	vec.print();
#else
	int* pa = (int*) malloc(sizeof(int)*5);
	memset(pa, 0, sizeof(int)*5);
	free(pa);
	List list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);
	list.print();

	list.pop_back();
	list.print();
#endif
	getchar();
	return 0;
}