# Cpp_Algorythm_Linkedlist

C++ 템플릿으로 STL `std::list`의 주요 멤버를 직접 구현하고, 메서드별 테스트 메뉴로 동작을 확인하는 이중 연결 리스트 연습 프로젝트입니다.

## 소개

- 저장소 설명: "201904/1인/STL list 컨테이너를 따라 구현한 것 입니다." (2019년 4월, 1인 작업)
- 커밋은 2019-05-18과 2020-04-04에 있습니다. 서울디지텍고등학교 재학 시기에 해당합니다.
- `std::list`의 인터페이스를 보고 같은 이름·같은 사용법의 `list<T>`를 직접 만들어, 구현한 함수가 표준 컨테이너와 같은 결과를 내는지 콘솔 테스트로 비교하는 것이 목적입니다.

## 핵심 구현

### 자료구조: 더미 노드를 둔 이중 연결 리스트

`Node<T>`는 `pNext`, `pPrev`, `Data`를 갖습니다. `list<T>`는 값이 없는 머리(`pHead`)와 꼬리(`pTail`) 더미 노드를 항상 두고, 실제 데이터는 그 사이에 연결합니다. 더미 노드 덕분에 맨 앞/맨 뒤 삽입·삭제에서도 `nullptr` 검사 없이 같은 코드로 처리됩니다. `begin()`은 `pHead->pNext`, `end()`는 `pTail`을 가리키는 반복자입니다.

```cpp
void push_back(T _Data)
{
    Node<T> * pNewNode = new Node<T>;
    pNewNode->Data = _Data;

    pNewNode->pNext = pTail;
    pNewNode->pPrev = pTail->pPrev;

    pTail->pPrev->pNext = pNewNode;
    pTail->pPrev = pNewNode;
}
```

### 반복자

중첩 클래스 `list<T>::iterator`는 노드 포인터 하나를 감싸고 `*`, `!=`, `=`, 전위/후위 `++`·`--`, `+ n`, `- n`을 연산자 오버로딩으로 제공합니다. 그래서 `for (auto it = l.begin(); it != l.end(); it++)` 형태의 표준 순회 코드를 그대로 쓸 수 있습니다. `rbegin()`/`rend()`는 각각 마지막 노드와 `begin()`을 반환하는 단순한 형태입니다.

### 멤버 함수의 동작 방식

| 함수 | 방식 |
|---|---|
| `insert(where, value)` | `where` 노드 바로 앞에 새 노드를 연결하고 새 노드의 반복자를 반환 |
| `erase(iter)` | 앞뒤 노드를 서로 연결한 뒤 노드를 `delete`하고 다음 노드의 반복자를 반환 |
| `remove(value)`, `remove_if(pred)` | 순회하며 조건에 맞으면 `erase`가 돌려준 반복자로 이어서 진행(`std::function` 조건자) |
| `sort()`, `sort(pred)` | 이중 반복문으로 모든 쌍을 비교해 조건자가 참이면 노드의 값(`Data`)을 교환. 기본 조건자는 `A > B` |
| `reverse()` | 앞쪽과 뒤쪽에서 같은 거리의 반복자 쌍을 안쪽으로 좁히며 값을 교환 |
| `splice(...)` | 다른 리스트의 값을 `insert`로 복사한 뒤 원본 리스트에서 `erase` (노드 자체를 옮기지는 않음) |
| `merge(list)` | 다른 리스트를 뒤에 붙이고 비운 뒤 `sort()`로 정렬 |
| `unique()` | 바로 다음 노드와 값이 같으면 지움 |
| `assign`, `size`, `empty`, `front`, `back`, `clear`, `swap` | `size()`는 노드를 끝까지 세는 방식 |

소멸자 `~list()`는 머리 노드부터 꼬리 노드까지 따라가며 노드를 해제합니다.

### 테스트 메뉴

`LinkedList.cpp`에는 `Test_assign_01`, `Test_erase_02`, `Test_sort`, `Test_splice_03`, `Test_unique_02` 같은 메서드·오버로드별 테스트 함수가 20여 개 있고, `main`에서 번호를 입력(`switch`)해 하나씩 실행합니다. 각 테스트는 `std::list`로 실행했을 때의 기대 결과를 출력 문구로 함께 안내합니다.

## 프로젝트 구조

| 경로 | 설명 |
|---|---|
| `Source/LinkedList/list.h` | `Node<T>`, `list<T>`, `list<T>::iterator` 구현 전체(헤더 온리) |
| `Source/LinkedList/LinkedList.cpp` | 테스트 함수와 번호 선택 메뉴 `main` |
| `Source/LinkedList/pch.h`, `pch.cpp` | 미리 컴파일된 헤더 |
| `Source/LinkedList.sln` | Visual Studio 솔루션 |

## 기술 스택

- C++ (클래스 템플릿, 연산자 오버로딩, `std::function`)
- Visual Studio 프로젝트: 플랫폼 도구 집합 v141, Windows SDK 10.0.17763.0

## 실행 방법

1. Visual Studio와 C++ 데스크톱 개발 워크로드가 필요합니다. v141 도구 집합이 없으면 다른 버전으로 재지정합니다.
2. `Source/LinkedList.sln`을 열어 빌드한 뒤 실행하면 콘솔에서 테스트 번호를 고를 수 있습니다. `conio.h`, `Windows.h`를 사용하므로 Windows 환경 기준입니다.

빌드는 당시 환경 기준입니다.

## 현재 상태

학습용 연습 프로젝트이며 2020-04-04 이후 갱신이 없습니다. 알려진 한계는 다음과 같습니다.

- 로그 출력(`printf("%d")`)이 `int` 값을 전제로 하여 다른 타입의 `push_back` 로그는 맞지 않습니다.
- 복사 생성자 `list(list<T>&)`가 노드를 복사하지 않고 머리/꼬리 포인터를 공유하는 얕은 복사입니다.
- `sort`, `reverse`, `size`는 효율보다 단순함을 택한 구현입니다.
