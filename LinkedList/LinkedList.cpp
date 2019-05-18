// LinkedList.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include "list.h"
#include <vector>
int main()
{
	vector<int> b;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	list<int> nlist;
	for (int i = 0; i < 10; i++)
	{
		nlist.Push_back(i);
	}

	nlist.Insert(nlist.begin(), 5);
	printf(":: 일반 반복문으로 출력 ::\n");
	for (list<int>::iterator iter = nlist.begin(); iter != nlist.end(); iter++)
	{
		printf("%d\n",*iter );
	}

	printf("\n\n\n:: 범위 기반 반복문으로 출력 ::\n");
	for (auto iter : nlist)
	{
		printf("%d\n", iter);
	}
	printf("Size = %d\n", nlist.size());
	printf("Empty = %d\n", nlist.empty());
}
