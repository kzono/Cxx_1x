// square.cpp
#include "square.h"

template <typename T>
T square(const T &x){
	return x*x;
}
template int square<int>(const int&);
template float square<float>(const float&);
template double square<double>(const double&);
