
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
	//double MaxValue1 = Max(Char1_MP, Char1_SP);
	//cout << "MP와 SP중 가장 큰 값은" << MaxValue1 << "입니다" << endl << endl;

}
*/