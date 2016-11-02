//#include "iutest.hpp"
#include "../../iutest-master/include/iutest.hpp"


IUTEST(CaseNo1, TestNo01){
	int x = 0;
	IUTEST_ASSERT_EQ(0, x);
}

IUTEST(CaseNo1, TestNo02){
	int x = 0;
	//IUTEST_ASSERT_EQ(1, x);
	IUTEST_EXPECT_EQ(1, x);
}

IUTEST(CaseNo1, TestNo03){
	int x = 1;
	IUTEST_ASSERT_EQ(1, x);
}

int main(int argc, char** argv){
	IUTEST_INIT(&argc, argv);
	IUTEST_RUN_ALL_TESTS();
	return 0;
}

