#include "Units.h"

#include <iostream>

#include <gtest/gtest.h>


													/*********************************************
													 * 				SAME TYPE ADD				 *
													 * ******************************************/
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

TEST(IdenticTypes_assign_add,Meters_metre_metre){

	using  namespace phy::literals;
	phy::Qty<phy::Metre> mm(20);
	phy::Qty<phy::Metre> mm2(20);

	mm += mm2;
	EXPECT_EQ(mm.value,40);

}

													/*********************************************
													 * 			NOT SAME TYPE ADD				 *
													 * ******************************************/

TEST(NotIdenticTypes_add,Meters_metre_milli){

	using  namespace phy::literals;
	phy::Qty<phy::Metre> mm(20);
	phy::Qty<phy::Metre , std::milli> mm2(2000);

	auto mm3 = mm + mm2;

	EXPECT_EQ(mm3.value,22);
}


TEST(NotIdenticTypes_add,Meters_centi_milli){

	using  namespace phy::literals;
	phy::Qty<phy::Metre , std::centi> mm(200);
	phy::Qty<phy::Metre , std::milli> mm2(20);

	auto mm3 = mm + mm2;

	EXPECT_EQ(mm3.value,202);

}

TEST(NotIdenticTypes_add,Meters_metre_nano){

	using  namespace phy::literals;
	phy::Qty<phy::Metre> mm(10);
	phy::Qty<phy::Metre , std::nano> mm2(20);

	auto mm3 = mm + mm2;

	EXPECT_EQ(mm3.value,10);

}

TEST(NotIdenticTypes_add,Meters_mill_centi){

	using  namespace phy::literals;
	phy::Qty<phy::Metre , std::milli> mm(20);
	phy::Qty<phy::Metre , std::centi> mm2(20);

	auto mm3 = mm + mm2;

	EXPECT_EQ(mm3.value,22);

}

TEST(NotIdenticTypes_assign_add,Meters_metre_centi_){

	using  namespace phy::literals;
	phy::Qty<phy::Metre> mm(20);
	phy::Qty<phy::Metre,std::centi> mm2(200);

	mm += mm2;

	EXPECT_EQ(mm.value,22);

}

TEST(NotIdenticTypes_assign_add,Seconds_minutes_seconds){

	using  namespace phy::literals;
	auto ss = 45_seconds;
	phy::Qty<phy::Second,std::milli> milli(1700);

	ss += milli;

	EXPECT_EQ(ss.value,46);
}

													/*********************************************
													 * 				SAME TYPE SUB				 *
													 * ******************************************/

TEST(IdenticTypes_sub,Meters_milli){

	using  namespace phy::literals;
	phy::Qty<phy::Metre , std::milli> mm(30);
	phy::Qty<phy::Metre , std::milli> mm2(10);

	auto mm3 = mm - mm2;

	EXPECT_EQ(mm3.value,20);

}

TEST(IdenticTypes_assign_sub,Meters_metre_metre){

	using  namespace phy::literals;
	phy::Qty<phy::Metre> mm(20);
	phy::Qty<phy::Metre> mm2(20);

	mm -= mm2;
	EXPECT_EQ(mm.value,0);

}

													/*********************************************
													 * 			NOT SAME TYPE SUB				 *
													 * ******************************************/

TEST(NotIdenticTypes_sub,Meters_metre_nano){

	using  namespace phy::literals;
	phy::Qty<phy::Metre> mm(10);
	phy::Qty<phy::Metre , std::nano> mm2(20);

	auto mm3 = mm - mm2;

	EXPECT_EQ(mm3.value,10);

}

TEST(NotIdenticTypes_assign_sub,Meters_metre_centi_){

	using  namespace phy::literals;
	phy::Qty<phy::Metre> mm(20);
	phy::Qty<phy::Metre,std::centi> mm2(200);

	mm -= mm2;

	EXPECT_EQ(mm.value,18);

}

<<<<<<< HEAD
TEST(IdenticTypes_assign_add,Seconds_seconds_milli){
=======
TEST(NotIdenticTypes_assign_sub,Seconds_minutes_seconds){
>>>>>>> fe82713e104f04476b5ab55e7a2ed4995b0abf7a

	using  namespace phy::literals;
	auto ss = 45_seconds;
	phy::Qty<phy::Second,std::milli> milli(1700);

	ss -= milli;

	EXPECT_EQ(ss.value,44);
}

TEST(IdenticTypes_assign_add,Ampere_ampere_mega){

	using  namespace phy::literals;
	auto ss = 45_amperes;
	phy::Qty<phy::Ampere,std::mega> milli(40);

	ss += milli;

	EXPECT_EQ(ss.value,40);

}

TEST(Types_mult,Metre_metre_metre){

	using  namespace phy::literals;
	auto m = 20_metres;
	phy::Qty<phy::Metre> mm(20);

	auto ss = m * mm;

	EXPECT_EQ(ss.value,400);

}

TEST(Types_mult,Metre_metre_centi){

	using  namespace phy::literals;
	auto m = 20_metres;
	phy::Qty<phy::Metre,std::centi> mm(20);

	auto ss = m * mm;

	EXPECT_EQ(ss.value,40000);

}

TEST(Types_mult,Metre_centi_metre){

	using  namespace phy::literals;
	auto m = 20_metres;
	phy::Qty<phy::Metre,std::centi> mm(20);

	auto ss = mm * m;

	EXPECT_EQ(ss.value,40000);

}

TEST(Types_mult,Metre_metre_x_seconds){

	using  namespace phy::literals;
	auto m = 20_metres;
	auto s = 20_seconds;

	auto ss = m * s;

	EXPECT_EQ(ss.value,400);

}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
