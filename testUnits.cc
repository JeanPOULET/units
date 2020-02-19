#include "Units.h"

#include <iostream>

#include <gtest/gtest.h>

TEST(tests,first){

	using  namespace phy::literals;
	phy::Qty<phy::Metre , std::milli> mm(30);
	phy::Qty<phy::Metre , std::milli> mm2(10);

	auto nf = 30_metres;

	auto mm3 = mm +mm2;
	auto nfje = nf + mm;
	std::cout<<"mm3 = "<<mm3.value<<"\n";
	std::cout<<"mm2 = "<<mm2.value<<"\n";
	std::cout<<"mm = "<<mm.value<<"\n";
	std::cout<<"nf = "<<nf.value<<"\n";
	std::cout<<"nfje = "<<nfje.value<<"\n";
	//auto nm = phy::qtyCast <phy::Qty <phy::Metre , std::nano >>(mm3);
	EXPECT_EQ(nfje.value,30);

}



int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
