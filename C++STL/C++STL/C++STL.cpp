
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

// /*
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

// */







