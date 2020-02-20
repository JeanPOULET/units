#include "Units.h"

#include <iostream>

#include <gtest/gtest.h>

TEST(IdenticTypes_add,Meters_milli){

	using  namespace phy::literals;
	phy::Qty<phy::Metre , std::milli> mm(30);
	phy::Qty<phy::Metre , std::milli> mm2(10);

	auto mm3 = mm + mm2;

	EXPECT_EQ(mm3.value,40);

}

TEST(IdenticTypes_add,Meters_Nano){

	using  namespace phy::literals;
	phy::Qty<phy::Metre , std::nano> mm(1730);
	phy::Qty<phy::Metre , std::nano> mm2(142);

	auto mm3 = mm + mm2;

	EXPECT_EQ(mm3.value,1730+142);

}

TEST(IdenticTypes_add,Meters_centi){

	using  namespace phy::literals;
	phy::Qty<phy::Metre , std::centi> mm(200);
	phy::Qty<phy::Metre , std::centi> mm2(1);

	auto mm3 = mm + mm2;

	EXPECT_EQ(mm3.value,201);

}

TEST(IdenticTypes_add,Meters_centi_milli){

	using  namespace phy::literals;
	phy::Qty<phy::Metre , std::centi> mm(200);
	phy::Qty<phy::Metre , std::milli> mm2(20);

	auto mm3 = mm + mm2;

	EXPECT_EQ(mm3.value,202);

}

TEST(IdenticTypes_add,Meters_metre_nano){

	using  namespace phy::literals;
	phy::Qty<phy::Metre> mm(10);
	phy::Qty<phy::Metre , std::nano> mm2(20);

	auto mm3 = mm + mm2;

	EXPECT_EQ(mm3.value,10);

}

TEST(IdenticTypes_add,Meters_mill_centi){

	using  namespace phy::literals;
	phy::Qty<phy::Metre , std::milli> mm(20);
	phy::Qty<phy::Metre , std::centi> mm2(20);

	auto mm3 = mm + mm2;

	EXPECT_EQ(mm3.value,22);

}


int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
