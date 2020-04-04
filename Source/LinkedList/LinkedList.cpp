// LinkedList.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include "list.h"
#include <stack>
#include <Windows.h>
#include <functional>
#include <conio.h>
#include "LinkedList.h"
//#include <list>
using namespace std;
list<int> nlist;

void Print()
{
	printf("\n:: 리스트 출력 ::\n");

	for (auto iter : nlist)
	{
		printf("%d\n", iter);
	}
	printf("Size = %d\n", nlist.size());
}
void Test_assign_01()
{
	printf(":: assign Test ::\n");
	printf("std::list로 동일하게 코드를 실행하면 1의 값을 가진 노드 5개 (1,1,1,1,1)가 순차적으로 할당된다.\n");

	list<int> TestList;

	nlist.assign(5, 1);

	Print();
}
void Test_assign_02()
{
	printf(":: assign Test ::\n");
	printf("std::list로 동일하게 코드를 실행하면 두 반복자의 범위의 값을 가진 노드 5개(0,1,2,3,4)가 순차적으로 할당된다.\n");

	list<int> TestList;

	for (int i = 0; i < 5; i++)
		TestList.push_back(i);

	nlist.assign(TestList.begin(), TestList.end());

	Print();
}
void Test_back()
{
	printf(":: back Test ::\n");
	printf("std::list로 동일하게 코드를 실행하면 가장 뒤에있는 노드의 데이터값이 리턴된다.\n");

	for (int i = 0; i < 5; i++)
	{
		nlist.push_back(i);
	}
	printf("back()의 값 : %d\n",nlist.back());


}
void Test_begin()
{
	printf(":: begin Test ::\n");
	printf("std::list로 동일하게 코드를 실행하면 가장 앞에있는 노드의 반복자가 리턴된다.\n\n");

	for (int i = 0; i < 5; i++)
	{
		nlist.push_back(i);
	}
	printf("\n*begin()의 값 : %d\n", *nlist.begin());


}
void Test_clear()
{
	printf(":: clear Test ::\n");
	printf("std::list로 동일하게 코드를 실행하면 모든 노드가 삭제된다.\n\n");

	for (int i = 0; i < 5; i++)
	{
		nlist.push_back(i);
	}
	nlist.clear();
	printf("\nclear()가 호출된 뒤 size()의 값 : %d\n", nlist.size());


}
void Test_empty()
{
	printf(":: empty Test ::\n");
	printf("std::list로 동일하게 코드를 실행하면 노드의 개수가 0개인지 여부를 리턴한다.\n\n");

	printf("\nempty()의 값 : %d\n\n", nlist.empty());

	for (int i = 0; i < 5; i++)
	{
		nlist.push_back(i);
	}
	printf("\nempty()의 값 : %d\n", nlist.empty());
}
void Test_end()
{
	printf(":: empty Test ::\n");
	printf("std::list로 동일하게 코드를 실행하면 가장 뒤에있는 노드의 다음 노드의 반복자를 리턴합니다.\n\n");

	for (int i = 0; i < 5; i++)
	{
		nlist.push_back(i);
	}

	printf("\n*(--end())의 값 : %d\n", *(--nlist.end() ) );
}
void Test_erase_01()
{
	printf(":: erase_01 Test ::\n");
	printf("std::list로 동일하게 코드를 실행하면 반복자가 가르키는 노드를 제거하고 그 다음 노드를 리턴합니다.\n\n");

	for (int i = 0; i < 5; i++)
	{
		nlist.push_back(i);
	}
	
	printf("\n*(erase(++begin()))의 리턴값 : %d\n", *(nlist.erase(++nlist.begin())));
	Print();
}
void Test_erase_02()
{
	printf(":: erase_02 Test ::\n");
	printf("std::list로 동일하게 코드를 실행하면 두 반복자 범위의 노드를 제거하고 그 다음 노드를 리턴합니다.\n\n");

	for (int i = 0; i < 5; i++)
	{
		nlist.push_back(i);
	}
	auto rtn = nlist.erase(nlist.begin(), --nlist.end());
	printf("\n*(erase(begin(),--end()))의값 : %d\n", *rtn);
	Print();
}
void Test_front()
{
	printf(":: front Test ::\n");
	printf("std::list로 동일하게 코드를 실행하면 가장 앞에있는 노드의 데이터를 리턴합니다.\n\n");

	for (int i = 0; i < 5; i++)
	{
		nlist.push_back(i);
	}
	printf("\nfront()의값 : %d\n", nlist.front());
	Print();
}
void Test_insert_01()
{
	printf(":: insert_01 Test ::\n");
	printf("std::list로 동일하게 코드를 실행하면 반복자가 가르키는 노드 앞에 인자로받은 데이터를 삽입하고 해당 원소를 가르키는 반복자를 리턴합니다.\n\n");

	for (int i = 0; i < 5; i++)
	{
		nlist.push_back(i);
	}
	printf("\n*insert(++begin(),10)의값 : %d\n", *nlist.insert(++nlist.begin(), 10));
	Print();
}
void Test_insert_02()
{
	printf(":: insert_02 Test ::\n");
	printf("std::list로 동일하게 코드를 실행하면 첫인자로 받은 반복자가 가르키는 곳에 나머지 두 반복자의 범위의 데이터를 삽입합니다.\n\n");

	for (int i = 0; i < 5; i++)
	{
		nlist.push_back(i);
	}
	nlist.insert(nlist.end(),nlist.begin(),--nlist.end());
	printf("\ninsert(end(),begin(),--end()) 호출");
	Print();
}
void Test_merge()
{
	printf(":: merge Test ::\n");
	printf("std::list로 동일하게 코드를 실행하면 인자로 받은 컨테이너를 삽입 - 정렬합니다.\n\n");
	
	for (int i = 0; i < 5; i++)
	{
		nlist.push_back(i);
	}

	printf("합병할 컨테이너 할당\n");
	list<int> test;
	for (int i = 0; i < 5; i++)
	{
		test.push_back(i);
	}
	
	nlist.merge(test);
	
	printf("merge(list) 호출완료");

	Print();
}
void Test_remove()
{
	printf(":: remove Test ::\n");
	printf("std::list로 동일하게 코드를 실행하면 인자로 받은 데이터값에 해당하는 모든원소를 제거합니다.\n\n");

	for (int i = 0; i < 5; i++)
	{
		nlist.push_back(i);
	}
	nlist.push_back(4);

	nlist.remove(4);
	printf("remove(4) 호출");

	Print();
}
void Test_remove_if()
{
	printf(":: remove_if Test ::\n");
	printf("std::list로 동일하게 코드를 실행하면 인자로 받은 조건자의 결과가 참인 모든원소를 제거합니다.\n\n");

	for (int i = 0; i < 5; i++)
	{
		nlist.push_back(i);
	}

	nlist.remove_if([](int A)->bool {return A > 3; });
	printf("remove([](int A)->bool {return A > 3; }) 호출");

	Print();
}
void Test_reverse()
{
	printf(":: reverse Test ::\n");
	printf("std::list로 동일하게 코드를 실행하면 모든 원소들이 역순차열로 뒤집힙니다.\n\n");

	for (int i = 0; i < 5; i++)
	{
		nlist.push_back(i);
	}

	nlist.reverse();
	printf("reverse 호출");

	Print();
}
void Test_sort()
{
	printf(":: sort Test ::\n");
	printf("std::list로 동일하게 코드를 실행하면 모든 원소들이 역순차열로 뒤집힙니다.\n\n");

	for (int i = 0; i < 5; i++)
	{
		nlist.push_back(i);
	}

	nlist.sort([](int A, int B)->bool {return A < B; });
	printf("sort([](int A, int B)->bool {return A < B; }) 호출");

	Print();
}
void Test_splice_01()
{
	printf(":: splice_01 Test ::\n");
	printf("std::list로 동일하게 코드를 실행하면 첫인자로 받은 반복자가 가르키는 위치에 두번째 인자로 받은 리스트를 잘라 붙힙니다..\n\n");

	for (int i = 0; i < 5; i++)
	{
		nlist.push_back(i);
	}
	list<int> test;
	for (int i = 0; i < 5; i++)
	{
		test.push_back(i);
	}	
	nlist.splice(nlist.begin(), test);

	printf("splice(list.begin(), test) 호출");

	Print();
}
void Test_splice_02()
{
	printf(":: splice_02 Test ::\n");
	printf("std::list로 동일하게 코드를 실행하면 첫인자로 받은 반복자가 가르키는 위치에 두번째 인자로 받은 리스트의 세번째 인자가 가르키는 원소를 잘라 붙인다. \n\n");

	for (int i = 0; i < 5; i++)
	{
		nlist.push_back(i);
	}
	list<int> test;
	for (int i = 0; i < 5; i++)
	{
		test.push_back(i);
	}
	nlist.splice(nlist.begin(), test,test.begin());

	printf("splice(list.begin(), list2,list2.begin()) 호출");

	Print();
}
void Test_splice_03()
{
	printf(":: splice_03 Test ::\n");
	printf("std::list로 동일하게 코드를 실행하면 첫인자로 받은 반복자가 가르키는 위치에 두번째 인자로 받은 리스트의 세번째 인자와 네번째 인자 범위의 데이터를 잘라 붙힙니다. \n\n");

	for (int i = 0; i < 5; i++)
	{
		nlist.push_back(i);
	}
	list<int> test;
	for (int i = 0; i < 5; i++)
	{
		test.push_back(i);
	}

	nlist.splice(nlist.begin(), test, test.begin(),test.end());

	printf("splice(list.begin(), list2,list2.begin(),list2.end()) 호출");

	Print();
}
void Test_unique_01()
{
	printf(":: unique_01 Test ::\n");
	printf("std::list로 동일하게 코드를 실행하면 인접한 원소의 값이 같다면 유일한 원소의 순차열로 만듭니다. \n\n");

	for (int i = 0; i < 5; i++)
	{
		nlist.push_back(i);
		nlist.push_back(i);
	}

	nlist.unique();

	printf("unique() 호출");

	Print();

}
void Test_unique_02()
{
	printf(":: unique_02 Test ::\n");
	printf("std::list로 동일하게 코드를 실행하면 인접한 원소가 이항 조건자의 기준에 맞다면 유일한 원소의 순차열로 만듭니다. \n\n");

	for (int i = 0; i < 5; i++)
	{
		nlist.push_back(i);
		nlist.push_back(i);
	}

	nlist.unique([](int A, int B)->bool {return A == B; });

	printf("unique() 호출");

	Print();

}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	while (1)
	{
		system("cls");
		printf("테스트하실 기능을 선택해주세요.\n\n");
		printf("(1) assign_01\n");
		printf("(2) assign_02\n");
		printf("(3) back\n");
		printf("(4) begin\n");
		printf("(5) clear\n");
		printf("(6) empty\n");
		printf("(7) end\n");
		printf("(8) erase_01\n");
		printf("(9) erase_02\n");
		printf("(10) front\n");
		printf("(11) insert_01\n");
		printf("(12) insert_02\n");
		printf("(13) merge\n");
		printf("(14) remove\n");
		printf("(15) remove_if\n");
		printf("(16) reverse\n");
		printf("(17) sort\n");
		printf("(18) splice_01\n");
		printf("(19) splice_02\n");
		printf("(20) splice_03\n");
		printf("(21) unique_01\n");
		printf("(22) unique_02\n");
		int num;
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			Test_assign_01();
			break;

		case 2:
			Test_assign_02();
			break;

		case 3:
			Test_back();
			break;

		case 4:
			Test_begin();
			break;

		case 5:
			Test_clear();
			break;

		case 6:
			Test_empty();
			break;

		case 7:
			Test_end();
			break;

		case 8:
			Test_erase_01();
			break;

		case 9:
			Test_erase_02();
			break;

		case 10:
			Test_front();
			break;

		case 11:
			Test_insert_01();
			break;

		case 12:
			Test_insert_02();
			break;

		case 13:
			Test_merge();
			break;

		case 14:
			Test_remove();
			break;

		case 15:
			Test_remove_if();
			break;

		case 16:
			Test_reverse();
			break;

		case 17:
			Test_sort();
			break;
		case 18:
			Test_splice_01();
			break;
		case 19:
			Test_splice_02();
			break;
		case 20:
			Test_splice_03();
			break;
		case 21:
			Test_unique_01();
			break;
		case 22:
			Test_unique_02();
			break;
		}
		getch();
		nlist.clear();
	}
}


