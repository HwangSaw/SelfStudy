﻿
/*

// 2.5  
#include <iostream>
using namespace std;

// 템플릿으로 만든 값을 비교하는  Max 함수  (1)
//template <typename T> T Max(T a, T b)
//{
//	return a > b ? a : b;
//}

// 템플릿으로 만든 값을 비교하는  Max 함수  (2)
// 함수의 인자전달을 참조로 수정해서 빠르게 한다.
template <typename T> const T& Max(const T& a, const T& b)
{
	return a > b ? a : b;
}

// class 와 template <typename T> const T& Max(const T& a, const T& b) 은 동일한데 템플릿이 표준이 되면서 typename 이 타입을 추상화하다는 의미를 명확하게
// 표시하므로 typename을 쓰는게 좋다. C++ 표준화 전후에 만들어진 컴파일러에서는 class를 사용해야지만 작동한다. 
//template <class T> const T& Max(const T& a, const T& b)
//{
//	return a > b ? a : b;
//}

void main()
{
	int Char1_HP = 300;
	int Char2_HP = 400;
	int MaxCharHP = Max(Char1_HP, Char2_HP);
	cout << "HP중 가장 큰 값은" << MaxCharHP << "입니다." << endl << endl;

	float Char1_Exp = 250.0f;
	float Char2_Exp = 250.57f;
	float MaxCharExp = Max(Char1_Exp, Char2_Exp);
	cout << "경험치 중 가장 큰 값은" << MaxCharExp << "입니다." << endl << endl;

}
*/

/*
// 2.6 하나의 T (typename)을 가진 탬플릿은 두가지 타입을 인식하지 못한다. 
#include <iostream>
using namespace std;

template <typename T> const T& Max(const T& a, const T& b)
{
	return a > b ? a : b;
}

// [리스트 2-3]의 Max 함수 템플릿을 사용한다.
void main()
{
	int Char1_MP = 300;
	double Char1_SP = 400.25;
	// 아래 구문은 컴파일러가 int와 double이라는 두가지타입이 있기때문에 현재 Max 로는 T를 어떤걸로 정할지 알수없어서 
	// no instance of function template "Max" matches the argument list 에러를 발생. 
	// 2.7의 예제를( typename을 복수개 사용) 통해서 해결가능
	//double MaxValue1 = Max(Char1_MP, Char1_SP);
	//cout << "MP와 SP중 가장 큰 값은" << MaxValue1 << "입니다" << endl << endl;

}
*/

/*
// 2.7 typename 을 하나가 아닌 복수 개 사용하면 된다. 
#include<iostream>
using namespace std;

template <typename T1, typename T2> const T1& Max(const T1& a, const T2& b)
{
	return a > b ? a : b;
}

void main()
{
	int Char1_MP = 300;
	double Char1_SP = 400.24;
	double MaxValue1 = Max(Char1_MP, Char1_SP);
	cout << "MP와 SP중 가장 큰 값은" << MaxValue1 << "입니다" << endl << endl;


	// 기대 값 : MP와 SP중 가장 큰 값은 400.24입니다. 
	// 실제 값 :  MP와 SP중 가장 큰 값은 400 입니다. 
	// 기대 값과 실제값이 다른 원인은 typename T1을 반환하는데 T2는 double이기에 int 로 반환시 소수점이 잘린다. 
	// 그래서 이렇게 서로 다른 타입을 사용하는 경우에는 반환 값을 조심해야한다. 
}
*/


/*
// 2.8 함수 템플릿의 전문화 라는 것이 있다. 
#include<iostream>
using namespace std;

// 템플릿으로 만든값을 비교하는 Max함수
template <typename T1, typename T2> const T1& Max(const T1& a, const T2& b)
{
	cout << "Max(const T& a,  const T& b) 템플릿 버전 사용" << endl;
	return a > b ? a : b;
}

// 전문화 시킨 Max함수
template <> const double& Max(const double& a, const double& b)
{
	cout << "Max(const double& a, const double& b) 전문화 버전 사용" << endl;
	return a > b ? a : b;
}

void main()
{
	double Char1_MP = 300;
	double Char1_SP = 400.25;
	double MaxValue1 = Max(Char1_MP, Char1_SP);
	cout << "MP와 SP중 가장 큰 값은 " << MaxValue1 << "입니다." << endl << endl;

	int Char2_MP = 300;
	double Char2_SP = 400.25;
	double MaxValue2 = Max(Char2_MP, Char2_SP);
	cout << "MP와 SP중 가장 큰 값은 " << MaxValue2 << "입니다" << endl << endl;

	// 실행결과 
	// Max<const double& a, const double& b> 전문화 버전 사용
	// MP 와 SP 중 가장 큰 값은 400.25 입니다. 
	//
	// Max<const T& a, cosnt T& b> 템플릿 버전 사용
	// MP 와 SP 중 가장 큰 값은 400 입니다.


	// 질문 : Max(10.1, 20.4)를 호출한다면 Max(T, T) 가 호출될까? 아니면 Max(double, double)이 호출될까? 
	double Char3_MP = 10.1f;
	double Char3_SP = 20.4f;
	double MaxValue3 = Max(Char3_MP, Char3_SP);
	cout << "MP와 SP중 가장 큰 값은" << MaxValue3 << "입니다" << endl << endl;

	// 실행결과
	// Max<const double& a, const double& b> 전문화 버전 사용 

	// 전문화 함수와 템플릿 함수둘다 호출이 가능할때 컴파일러는 전문화 버전을 먼저 호출한다.
	// 호출 순서
	// 1. 전문화된 함수와 맞는지 검사
	// 2. 템플릿 함수와 맞는지 검사
	// 3. 일반 함수와 맞는지 검사
}
*/

/*
// 2.9 난-타입(non-type) 함수 템플릿
#include<iostream>
using namespace std;

// 지정된 값만큼 더해준다.
template <typename T, int VAL> T AddValue(T const& CurValue)
{
	return CurValue + VAL;
}

const int EVENT_ADD_HP_VALUE = 50; // 이벤트에 의해 추가 될 HP값
const int EVENT_ADD_EXP_VALUE = 30; // 이벤트에 의해 추가될 경험치  
const int EVENT_ADD_MONEY_VALUE = 10000; // 이벤트에 의해 추가 될 돈

void main()
{
	int Char_HP = 250;
	cout << Char_HP << "에서 이벤트에 의해 " << AddValue < int, EVENT_ADD_HP_VALUE>(Char_HP) << "로 변경" << endl;

	float Char_EXP = 378.89f;
	cout << Char_EXP << "에서 이벤트에 의해" << AddValue<float, EVENT_ADD_EXP_VALUE>(Char_EXP) << "로 변경" << endl;

	__int64 Char_MONEY = 34567890;
	cout << Char_MONEY << "에서 이벤트에 의해" << AddValue<__int64, EVENT_ADD_MONEY_VALUE>(Char_MONEY) << "로 변경" << endl;

	// 실행 결과
	// 250 에서 이벤트에 의해 300로 변경
	// 378.89 에서 이벤트에 의해 408.89 로 변경
	// 34567890에서 이벤트에 의해 34577890 로 변경 

}
 */

// 3.1 경험치 변경 이력 저장
/*
#include <iostream>

// 경험치를 저장할 수 있는 최대 개수
const int MAX_EXP_COUNT = 100;

// 경험치 저장 스택 클래스
class ExpStack
{
public:
	ExpStack()
	{
		Clear();
	}

	// 초기화 한다.
	void Clear()
	{
		m_Count = 0;
	}

	// 스택에 저장된 개수
	int Count()
	{
		return m_Count;
	}

	// 저장된 데이터가 없는가? 
	bool IsEmpty()
	{
		return 0 == m_Count ? true : false;
	}

	// 경험치를 저장한다.
	bool push(float Exp)
	{
		// 저장할 수 있는 개수를 넘는지 조사한다.
		if (m_Count >= MAX_EXP_COUNT)
		{
			return false;
		}

		// 경험치를 저장 후 개수를 하나 늘린다.
		m_aData[m_Count] = Exp;
		++m_Count;
		return true;
	}

	// 스택에서 경험치를 빼낸다.
	float pop()
	{
		// 저장된 것이 없다면 0.0f를 반환한다.
		if (m_Count < 1)
		{
			return 0.0f;
		}

		// 개수를 하나 감소 후 반환한다.
		--m_Count;
		return m_aData[m_Count];
	}

private:
	float m_aData[MAX_EXP_COUNT];
	int m_Count;
};

#include<iostream>
using  namespace std;

void main()
{
	ExpStack kExpStack;

	cout << "첫번째 게임 종료 - 현재 경험치 145.5f" << endl;
	kExpStack.push(145.5f);

	cout << "두번째 게임 종료 - 현재 경험치 183.24f" << endl;
	kExpStack.push(183.25f);

	int Count = kExpStack.Count();
	for (int i = 0; i < Count; ++i)
	{
		cout << "현재 경험치 ->" << kExpStack.pop() << endl;
	}

}
*/

/*
// 3.2 게임 돈 변경 이력도 저장해 주세요. 
#include  <iostream>

//돈은 저장할 수 있는 최대 개수
const int MAX_MONEY_COUNT = 100;

// 돈 저장 스택 클래스
class MoneyStack
{
public :
	MoneyStack() {
		Clear();
	}

	// 초기화 한다.
	void Clear()
	{
		m_Count = 0;
	}

	// 스택에 저장된 개수
	int Count()
	{
		return m_Count;
	}

	// 저장된 데이터가 없는가?
	bool IsEmpty()
	{
		return 0 == m_Count ? true : false;
	}

	// 돈을 저장한다.
	bool push(__int64 Money)
	{
		// 저장 할 수 있는 개수를 넘는지 조사한다.
		if (m_Count >= MAX_MONEY_COUNT)
		{
			return false;
		}

		// 저장 후 개수를 하나 늘린다.
		m_aData[m_Count] = Money;
		++m_Count;
		return true;
	}

	// 스택에서 돈을 빼낸다.
	__int64 pop()
	{
		// 저장된 것이 없다면  0을 반환한다.
		if (m_Count < 1)
		{
			return 0;
		}

		// 개수를 하나 감소 후 반환한다.
		--m_Count;
		return m_aData[m_Count];		
	}

private:
	__int64 m_aData[MAX_MONEY_COUNT];
	int m_Count;
		
};

*/


/*
// 3.4 Stack 템플릿 클래스
// 지금 까지 만들었더 ExpStack과 MoneyStack을 클래스 템플릿으로 만든 코드
#include <iostream>
using namespace std;

const int MAX_COUNT = 100;

template <typename T>
class Stack
{
public:
	Stack()
	{
		Clear();
	}

	// 초기화 한다.
	void  Clear()
	{
		m_Count = 0;
	}

	// 스택에 저장딘 개수
	int Count()
	{
		return m_Count;
	}

	// 저장된 데이터가 없는가?
	bool IsEmpty()
	{
		return 0 == m_Count ? true : false;
	}

	// 데이터를 저장한다.
	bool push(T data)
	{
		// 저장 할 수있는 개수를 넘는지 조사한다.
		if (m_Count >= MAX_COUNT)
		{
			return false;
		}

		// 저장 후 개수를 하나 늘린다.
		m_aData[m_Count] = data;
		++m_Count;
		return true;
	}

	// 스택에서 빼낸다.
	T pop()
	{
		// 저장된 것이 없다면 0을 반환한다.
		if (m_Count < 1)
		{
			return 0;
		}

		//개수를 하나 감소 후 반환한다.
		--m_Count;
		return m_aData[m_Count];
	}
private:
	T m_aData[MAX_COUNT];
	int m_Count;
};

void main()
{
	Stack<double> kStackExp;

	cout << "첫번째 게임 종료- 현재 경험치 145.5f" << endl;
	kStackExp.push(145.5f);

	cout << "두번째 게임 종료- 현재 경험치 183.25f" << endl;
	kStackExp.push(183.25f);

	cout << "세번째 게임 종료- 현재 경험치 162.3f" << endl;
	kStackExp.push(162.3f);
	
	int Count = kStackExp.Count();
	for (int i = 0; i < Count; ++i)
	{
		cout << "현재 경험치->" << kStackExp.pop() << endl;
	}
	
	cout << endl << endl;
	Stack<__int64> kStackMoney;

	cout << "첫번째 게임 종료- 현재 돈 1000023" << endl;
	kStackMoney.push(1000023);
	
	cout << "두번째 게임 종료- 현재 돈 1000234" << endl;
	kStackMoney.push(1000234);
	
	cout << "세번째 게임 종료- 현재 돈 1000145" << endl;
	kStackMoney.push(1000145);

	Count = kStackMoney.Count();
	for (int i = 0; i < Count; ++i)
	{
		cout << "현재 돈->" << kStackMoney.pop() << endl;
	}
}
*/

/*
// 3.5 클래스 템플릿에서 non-type 파라미터 사용

#include<iostream>
using namespace std;

// 템플릿 파라미터중 int  size가 non-type 파라미터다
template <typename T, int Size>
class Stack
{
public:
	Stack()
	{
		Clear();
	}

	// 초기화 한다.
	void Clear()
	{
		m_Count = 0;
	}

	// 스택에 저장된 개수
	int Count()
	{
		return m_Count;
	}

	// 저장된 데이터가 없는가?
	bool IsEmpty()
	{
		return 0 == m_Count ? true : false;
	}

	// 데이터를 담을 수 있는 최대 개수
	int GetStackSize()
	{
		return Size;
	}

	// 데이터를 저장한다.
	bool push(T data)
	{
		// 저장할 수 있는 개수를 넘는지 조사한다.
		if (m_Count >= Size)
		{
			return false;
		}

		// 저장 후 개수를 하나 늘린다.
		m_aData[m_Count] = data;
		++m_Count;

		return true;
	}

	// 스택에서 빼낸다.
	T pop()
	{
		// 저장된 것이 없다면 0 을 반환한다.
		if (m_Count < 1)
		{
			return 0;
		}

		// 개수를 하나 감소 후 반환한다.
		--m_Count;
		return m_aData[m_Count];
	}

private :
	T m_aData[Size];
	int m_Count;
};

void main()
{
	Stack<int, 100> kStack1;
	cout << "스택의 크기는?" << kStack1.GetStackSize() << endl;

	Stack<double, 60> kStack2;
	cout << "스택의 크기는?" << kStack2.GetStackSize() << endl;

}
 */

 /*
// 3.6 템플릿 파라미터 디폴트 값 사용
// 템플릿 파라미터 중 int Size가 non-type 파라미터다.
// Size의 디폴트 값을 100으로 한다. 
#include<iostream>
using namespace std;
template <typename T, int Size=100>
class Stack
{
public:
	Stack()
	{
		Clear();
	}

	// 초기화 한다.
	void Clear()
	{
		m_Count = 0;
	}

	// 스택에 저장된 개수
	int Count()
	{
		return m_Count;
	}

	// 저장된 데이터가 없는가?
	bool IsEmpty()
	{
		return 0 == m_Count ? true : false;
	}

	// 데이터를 담을 수 있는 최대 개수
	int GetStackSize()
	{
		return Size;
	}

	// 데이터를 저장한다.
	bool push(T data)
	{
		// 저장할 수 있는 개수를 넘는지 조사한다.
		if (m_Count >= Size)
		{
			return false;
		}

		// 저장 후 개수를 하나 늘린다.
		m_aData[m_Count] = data;
		++m_Count;

		return true;
	}

	// 스택에서 빼낸다.
	T pop()
	{
		// 저장된 것이 없다면 0 을 반환한다.
		if (m_Count < 1)
		{
			return 0;
		}

		// 개수를 하나 감소 후 반환한다.
		--m_Count;
		return m_aData[m_Count];
	}

private:
	T m_aData[Size];
	int m_Count;
};

void main()
{
	Stack<int, 64> kStack1;
	cout << "스택의 크기는?" << kStack1.GetStackSize() << endl;

	Stack<double> kStack2;
	cout << "스택의 크기는?" << kStack2.GetStackSize() << endl;

}
 */

/*
// 3.7 스택 클래스의 크기를 클래스 생성자에서 지정
template<typename T, int Size = 100> class Stack
{
public:
	explicit Stack(int size)
	{
		m_Size = size;
		m_aData = new T[m_Size];

		Clear();
	}

	~Stack()
	{
		delete[] m_aData;
	}

	// 초기화 한다.
	void Clear()
	{
		m_Count = 0;
	}

	// 스택에 저장된 개수
	int Count()
	{
		return m_Count;
	}

	// 저장된 데이터가 없는가?
	bool IsEmpty()
	{
		return 0 == m_Count ? true : false;
	}

	// 데이터를 담을 수 있는 최대 개수
	int GetStackSize()
	{
		return m_Size;
	}

	// 데이터를 저장한다.
	bool push(T data)
	{
		// 저장할 수 있는 개수를 넘는지 조사한다.
		if (m_Count >= m_Size)
		{
			return false;
		}

		// 저장 후 개수를 하나 늘린다.
		m_aData[m_Count] = data;
		++m_Count;

		return true;
	}

	// 스택에서 빼낸다.
	T pop()
	{
		// 저장된 것이 없다면 0을 반환한다.
		if (m_Count < 1)
		{
			return 0;
		}

		// 개수를 하나 감소 후 반환한다.
		--m_Count;
		return m_aData[m_Count];
	}

private:
	T* m_aData;
	int m_Count;

	int m_Size;
};

#include<iostream>
using namespace std;

void main()
{
	Stack<int> kStack1(64);
	cout << "스택의 크기는?" << kStack1.GetStackSize() << endl;

}
*/

/*

// 3.8 클래스 템플릿 전문화

// ID 문자열의 최대 길이 (null 문자 포함 )
const int MAX_ID_LENGTH = 21;

template<typename T> class Stack
{
public:
	explicit Stack(int size)
	{
		m_Size = size;
		m_aData = new T[m_Size];
	
		Clear();
	}

	~Stack()
	{
		delete[] m_aData;
	}

	// 초기화 한다.
	void Clear()
	{
		m_Count = 0;
	}

	// 스택에 저장된 개수
	int Count()
	{
		return m_Count;
	}

	// 저장된 데이터가 없는가?
	bool IsEmpty()
	{
		return 0 == m_Count ? true : false;
	}

	// 데이터를 담을 수 있는 최대 개수
	int GetStackSize()
	{
		return m_Size;
	}

	// 데이터를 저장한다.
	bool push(T data)
	{
		// 저장할 수 있는 개수를 넘는지 조사한다.
		if (m_Count >= m_Size)
		{
			return false;
		}

		// 저장 후 개수를 하나 늘린다.
		m_aData[m_Count] = data;
		++m_Count;

		return true;
	}

	// 스택에서 빼낸다.
	T pop()
	{
		// 저장된 것이 없다면 0을 반환한다.
		if (m_Count < 1)
		{
			return 0;
		}

		// 개수를 하나 감소 후 반환한다.
		--m_Count;
		return m_aData[m_Count];

	}

private:
	T* m_aData;
	int m_Count;

	int m_Size;
};

#include<string>
// 아래의 코드는 문자열을 저장하기 위해 char* 으로 전문화한 Stack클래스입니다.
template<> class Stack<char*>
{
public:
	explicit Stack(int size)
	{
		m_Size = size;

		m_ppData = new char* [m_Size];
		for (int i = 0; i < m_Size; ++i)
		{
			m_ppData[i] = new char[MAX_ID_LENGTH];
		}

		Clear();
	}

	~Stack()
	{
		for (int i = 0; i < m_Size; ++i)
		{
			delete[] m_ppData[i];
		}

		delete[] m_ppData;
	}

	// 초기화 한다.
	void Clear()
	{
		m_Count = 0;
	}

	// 스택에 저장된 개수
	int Count()
	{
		return m_Count;
	}

	// 저장된 데이터가 없는가? 
	bool IsEmpty()
	{
		return 0 == m_Count ? true : false;
	}

	// 데이터를 담을 수 있는 최대 개수
	int GetStackSize()
	{
		return m_Size;
	}

	// 데이터를 저장한다.
	bool push(char* pID)
	{
		// 저장할 수 있는 개수를 넘는지 조사한다.
		if (m_Count >= m_Size)
		{
			return false;
		}

		// 저장 후 개수를 하나 늘린다.
		strncpy_s(m_ppData[m_Count], MAX_ID_LENGTH, pID, MAX_ID_LENGTH - 1);
		m_ppData[m_Count][MAX_ID_LENGTH - 1] = '\0';

		++m_Count;

		return true;
	}

	// 스택에서 빼낸다.
	char* pop()
	{
		// 저장된 것이 없다면 0을 반환한다.
		if (m_Count < 1)
		{
			return 0;
		}

		// 개수를 하나 감소 후 반환한다.
		--m_Count;
		return m_ppData[m_Count];
	}

private:
	char** m_ppData;
	int m_Count;
	
	int m_Size;
};

#include<iostream>
using namespace std;

void main()
{
	Stack<int> kStack1(64);
	cout << "스택의 크기는?" << kStack1.GetStackSize() << endl;
	kStack1.push(10);
	kStack1.push(11);
	kStack1.push(12);

	int Count1 = kStack1.Count();
	for (int i = 0; i < Count1; ++i)
	{
		cout << "유저의 레벨 변화 -> " << kStack1.pop() << endl;
	}

	cout << endl;

	char GameID1[MAX_ID_LENGTH] = "NiceChoi";
	char GameID2[MAX_ID_LENGTH] = "SuperMan";
	char GameID3[MAX_ID_LENGTH] = "Attom";

	// Stack 클래스 템플릿의 char* 전문화 버전을 생성한다.
	Stack<char*> kStack2(64);
	kStack2.push(GameID1);
	kStack2.push(GameID2);
	kStack2.push(GameID3);

	int Count2 = kStack2.Count();
	for (int i = 0; i < Count2; ++i)
	{
		cout << "같이 게임을 한 유저의 ID ->" << kStack2.pop() << endl;
	}


}
*/


/*
// 3.9 클래스 템플릿 부분 전문화 
// 일반 템플릿

#include<iostream>
using namespace std;

template< typename T1, typename T2>
class Test
{
public:
	T1 Add(T1 a, T2 b)
	{
		cout << " 일반 템플릿을 사용했습니다." << endl;
		return a;
	}
};


template<typename T>
class TestP
{
public :
	void Add()
	{
		cout << "일반 템플릿을 사용했습니다." << endl;
	}
};

// T를 T*로 부분 전문화
template< typename T >
class TestP<T*>
{
public:
	void Add()
	{
		cout << "포인터를 사용한 부분 전문화 템플릿을 사용했습니다." << endl;
	}
};


// T2를 float으로 구체화한 Test의 부분 전문화 템플릿
template< typename T1>
class Test<T1, float>
{
public :
	T1 Add(T1 a, float b)
	{
		cout << " 부분 전문화 템플릿을 사용했습니다." << endl;
		return a;
	}
};

void main()
{
	Test<int, int > test1;
	test1.Add(2, 3);
	
	Test<int, float> test2;
	test2.Add(2, 5.8f);


	// --- 아래부터 포인터 템플릿 
	TestP<int> test3;
	test3.Add();

	TestP<int*> test4;
	test4.Add();
}

*/



// 3.10 싱글톤 템플릿 클래스
// /*
// 파라미터 T를 싱글톤이 되도록 정의한다.
#include<iostream>
using namespace std;

template <typename T>
class MySingleton
{
public:
	MySingleton() {}
	virtual ~MySingleton() {}

	// 이 멤버를 통해서만 생성이 가능하다.
	static T* GetSingleton()
	{
		//  아직 생성이 되어 있지 않으면 생성한다.
		if (NULL == _Singleton)
		{
			_Singleton = new T;
		}

		return (_Singleton);
	}

	static void Release()
	{
		delete _Singleton;
		_Singleton = NULL;
	}

private:
	static T* _Singleton;
};

template< typename T> T* MySingleton<T>::_Singleton = NULL;

// 싱글톤 클래스 템플릿을 상속 받으면서 파라미터에 본 클래스를 넘긴다. 
class MyObject : public MySingleton<MyObject>
{
public :
	MyObject() : _nValue(10) {}

	void SetValue(int Value) { _nValue = Value; }
	int GetValue() { return _nValue; }
private:
	int _nValue;
};

void main()
{
	MyObject* MyObj1 = MyObject::GetSingleton();

	cout << MyObj1->GetValue() << endl;

	// MyObj2 는 MyObj1과 동일한 객체이다.
	MyObject* MyObj2 = MyObject::GetSingleton();
	MyObj2->SetValue(20);

	cout << MyObj1->GetValue() << endl;
	cout << MyObj2->GetValue() << endl;
}



// */ 






















