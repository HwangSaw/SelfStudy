
// /*
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
//*/


//