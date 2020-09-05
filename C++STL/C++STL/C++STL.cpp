
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


// /*
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

	double Char3_MP = 10.1f;
	double Char3_SP = 20.4f;
	double MaxValue3 = Max(Char3_MP, Char3_SP);
	cout << "MP와 SP중 가장 큰 값은" << MaxValue3 << "입니다" << endl << endl;

	// 전문화 함수와 템플릿 함수둘다 호출이 가능할때 컴파일러는 전문화 버전을 먼저 호출한다.
	// 호출 순서
	// 1. 전문화된 함수와 맞는지 검사
	// 2. 템플릿 함수와 맞는지 검사
	// 3. 일바 ㄴ함수와 맞는지 검사

}
// */