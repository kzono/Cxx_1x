//#include "iutest.hpp"
#include "../../iutest-master/include/iutest.hpp"


// テスト対象クラス
class X{
	int m_a;
	int m_b;
	int sub(){return m_a - m_b; }
public:
	X(int a, int b):m_a(a), m_b(b){}
	int add(){return m_a + m_b; }
};

// 以下、テストコード
//
// テスト準備
// テストしたい private メンバをアクセスできるように設定。
IUTEST_MAKE_PEEP(int X::*, X, m_a);
IUTEST_MAKE_PEEP(int X::*, X, m_b);
IUTEST_MAKE_PEEP(int (X::*)(), X, sub);


IUTEST(Case01, Test01){
	X x(1,2);
	IUTEST_ASSERT_EQ(3, x.add());
}

IUTEST(Case01, Test02){
	X x(1,2);
	// pravate なメンバの値を変更。
	IUTEST_PEEP_GET(x, X, m_a) = 3;
	IUTEST_PEEP_GET(x, X, m_b) = 4;

	IUTEST_ASSERT_EQ(7, x.add());
}

IUTEST(Case01, Test03){
	X x(1,2);
	IUTEST_ASSERT_EQ(-1, IUTEST_PEEP_GET(x, X, sub)());
}


int main(int argc, char** argv){
	IUTEST_INIT(&argc, argv);
	IUTEST_RUN_ALL_TESTS();
	return 0;
}

