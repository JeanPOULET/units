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

	EXPECT_EQ(mm3.value,20+(20*10));

}


TEST(NotIdenticTypes_add,Meters_mill_centi_nega){

	using  namespace phy::literals;
	phy::Qty<phy::Metre , std::milli> mm(20);
	phy::Qty<phy::Metre , std::centi> mm2(-30);

	auto mm3 = mm + mm2;

	EXPECT_EQ(mm3.value,20-(30*10));

}

TEST(NotIdenticTypes_assign_add,Meters_metre_centi_){

	using  namespace phy::literals;
	phy::Qty<phy::Metre> mm(20);
	phy::Qty<phy::Metre,std::centi> mm2(200);

	mm += mm2;

	EXPECT_EQ(mm.value,22);

}

TEST(NotIdenticTypes_assign_add,Seconds_milli){

	using  namespace phy::literals;
	auto ss = 45_seconds;
	phy::Qty<phy::Second,std::milli> milli(1700);

	ss += milli;

	EXPECT_EQ(ss.value,46);
}

TEST(NotIdenticTypes_assign_add,Seconds_milli_seconds){

	using  namespace phy::literals;
	auto ss = 45_seconds;
	phy::Qty<phy::Second,std::milli> milli(1700);

	milli += ss;

	EXPECT_EQ(milli.value,(45*1000)+1700);
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

TEST(IdenticTypes_sub,Meters_milli_nega){

	using  namespace phy::literals;
	phy::Qty<phy::Metre , std::milli> mm(10);
	phy::Qty<phy::Metre , std::milli> mm2(30);

	auto mm3 = mm - mm2;

	EXPECT_EQ(mm3.value,-20);

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

TEST(NotIdenticTypes_assign_sub,Seconds_minutes_seconds){

	using  namespace phy::literals;
	auto ss = 45_seconds;
	phy::Qty<phy::Second,std::milli> milli(1700);

	ss -= milli;

	EXPECT_EQ(ss.value,44);
}

TEST(IdenticTypes_assign_add,Ampere_ampere_mega){

	using  namespace phy::literals;
	auto ss = 45_amperes;
	phy::Qty<phy::Ampere,std::mega> mega(40);

	ss += mega;

	EXPECT_EQ(ss.value,40000045);

}

TEST(IdenticTypes_assign_add,Ampere_mega_ampere){

	using  namespace phy::literals;
	auto ss = 45_amperes;
	phy::Qty<phy::Ampere,std::mega> mega(50);

	mega += ss;

	EXPECT_EQ(mega.value,50);

}

													/*********************************************
													 * 			       TYPE MULT				 *
													 * ******************************************/

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







													/*********************************************
													 * 			 SAME TYPE COMPA				 *
													 * ******************************************/

TEST(IdenticTypes_comparaison_less,Meters_metre){

	using  namespace phy::literals;
	phy::Qty<phy::Metre> mm(20);
	phy::Qty<phy::Metre> mm2(30);

	EXPECT_TRUE(mm<mm2);
}

TEST(IdenticTypes_comparaison_less_equal_different,Meters_metre){

	using  namespace phy::literals;
	phy::Qty<phy::Metre> mm(20);
	phy::Qty<phy::Metre> mm2(30);

	EXPECT_TRUE(mm<=mm2);
}

TEST(IdenticTypes_comparaison_less_equal_same,Meters_metre){

	using  namespace phy::literals;
	phy::Qty<phy::Metre> mm(20);

	EXPECT_TRUE(mm<=mm);
}

TEST(IdenticTypes_comparaison_greater,Meters_metre){

	using  namespace phy::literals;
	phy::Qty<phy::Metre> mm(20);
	phy::Qty<phy::Metre> mm2(30);

	EXPECT_TRUE(mm2>mm);
}

TEST(IdenticTypes_comparaison_greater_equal_different,Meters_metre){

	using  namespace phy::literals;
	phy::Qty<phy::Metre> mm(20);
	phy::Qty<phy::Metre> mm2(30);

	EXPECT_TRUE(mm2>=mm);
}

TEST(IdenticTypes_comparaison_greater_equal_same,Meters_metre){

	using  namespace phy::literals;
	phy::Qty<phy::Metre> mm(20);

	EXPECT_TRUE(mm>=mm);
}

TEST(IdenticTypes_comparaison_equal,Meters_metre){

	using  namespace phy::literals;
	phy::Qty<phy::Metre> mm(20);

	EXPECT_TRUE(mm==mm);
}


TEST(IdenticTypes_comparaison_different,Meters_metre){

	using  namespace phy::literals;
	phy::Qty<phy::Metre> mm(20);
	phy::Qty<phy::Metre> mm2(30);

	EXPECT_TRUE(mm!=mm2);
}

													/*********************************************
													 * 			NOT SAME TYPE COMPA				 *
													 * ******************************************/

TEST(IdenticTypes_comparaison_less,Meters_metre_centi_){

	using  namespace phy::literals;
	phy::Qty<phy::Metre> mm(2000);
	phy::Qty<phy::Metre, std::centi> mm2(30);

	EXPECT_TRUE(mm2<mm);
}

TEST(IdenticTypes_comparaison_less_equal_different,Meters_metre_centi_){

	using  namespace phy::literals;
	phy::Qty<phy::Metre> mm(2000);
	phy::Qty<phy::Metre, std::centi> mm2(20);

	EXPECT_TRUE(mm2<=mm);
}

TEST(IdenticTypes_comparaison_less_equal_equal,Meters_metre_centi_){

	using  namespace phy::literals;
	phy::Qty<phy::Metre> mm(20);
	phy::Qty<phy::Metre, std::centi> mm2(2000);

	EXPECT_TRUE(mm<=mm);
}

TEST(IdenticTypes_comparaison_greater,Meters_metre_centi_){

	using  namespace phy::literals;
	phy::Qty<phy::Metre> mm(20);
	phy::Qty<phy::Metre, std::centi> mm2(30);

	EXPECT_TRUE(mm>mm2);
}

TEST(IdenticTypes_comparaison_greater_equal_different,Meters_metre_centi_){

	using  namespace phy::literals;
	phy::Qty<phy::Metre> mm(20);
	phy::Qty<phy::Metre, std::centi> mm2(30);

	EXPECT_TRUE(mm>=mm2);
}

TEST(IdenticTypes_comparaison_greater_equal_same,Meters_metre_centi_){

	using  namespace phy::literals;
	phy::Qty<phy::Metre> mm(20);
	phy::Qty<phy::Metre, std::centi> mm2(2000);

	EXPECT_TRUE(mm>=mm);
}

TEST(IdenticTypes_comparaison_equal,Meters_metre_centi_){

	using  namespace phy::literals;
	phy::Qty<phy::Metre> mm(20);
	phy::Qty<phy::Metre, std::centi> mm2(2000);

	EXPECT_TRUE(mm==mm2);
}


TEST(IdenticTypes_comparaison_different,Meters_metre_centi_){

	using  namespace phy::literals;
	phy::Qty<phy::Metre> mm(20);
	phy::Qty<phy::Metre, std::centi> mm2(3000);

	EXPECT_TRUE(mm!=mm2);

}


													/*********************************************
													 * 			NOT SAME TYPE DIV				 *
													 * ******************************************/



TEST(IdenticTypes_division,Meters_metre_metre){

	using  namespace phy::literals;
	phy::Qty<phy::Metre> mm(100);
	phy::Qty<phy::Metre> mm2(5);
	auto res = mm/mm2;
	EXPECT_EQ(res.value,20);

}

TEST(IdenticTypes_division,Seconds_second_second){

	using  namespace phy::literals;
	phy::Qty<phy::Second> mm(100);
	auto mm2 = 5_seconds;
	auto res = mm/mm2;
	EXPECT_EQ(res.value,20);

}

TEST(IdenticTypes_division,Seconds_megasecond_second){

	using  namespace phy::literals;
	phy::Qty<phy::Second,std::mega> mm(10);
	auto mm2 = 5_seconds;
	auto res = mm/mm2;
	EXPECT_EQ(res.value,2000000);

}

TEST(IdenticTypes_division,Seconds_second_megaSecond){

	using  namespace phy::literals;
	phy::Qty<phy::Second,std::mega> mm(10);
	auto mm2 = 5_seconds;
	auto res = mm2/mm;
	EXPECT_EQ(res.value,0);

}

TEST(NotIdenticTypes_division,Metre_metre_second){

	using  namespace phy::literals;
	phy::Qty<phy::Metre> mm(100);
	auto mm2 = 5_seconds;
	auto res = mm/mm2;
	EXPECT_EQ(res.value,20);

}

TEST(NotIdenticTypes_division,Ampere_metre_second){

	using  namespace phy::literals;
	auto mm = 100_metres;
	auto mm2 = 5_seconds;
	auto amp = 14_amperes;
	auto res = mm/mm2*amp;
	EXPECT_EQ(res.value,(20*14));

}

TEST(NotIdenticTypes_division,Ampere_metre_0){

	using  namespace phy::literals;
	auto mm = 100_metres;
	auto mm2 = 0_seconds;
	auto mm3 = 5_seconds;
	auto res = mm/mm2;
	auto res2 = mm/mm3;
	res += res2;
	EXPECT_EQ(res.value,20);

}

TEST(QtyCast,Metre_milli){

	using  namespace phy::literals;
	auto mm = 100_metres;
	auto res = phy::qtyCast<phy::Qty<phy::Metre,std::milli>>(mm);
	EXPECT_EQ(res.value,100000);

}

TEST(QtyCast,Kilogram_nano){

	using  namespace phy::literals;
	auto mm = 100_kilograms;
	auto res = phy::qtyCast<phy::Qty<phy::Kilogram,std::nano>>(mm);
	EXPECT_EQ(res.value,100000000000);

}

TEST(QtyCast,MegaAmpere_milli){

	using  namespace phy::literals;
	phy::Qty<phy::Ampere,std::mega> amp(15);
	auto res = phy::qtyCast<phy::Qty<phy::Ampere,std::milli>>(amp);
	EXPECT_EQ(res.value,15000000000);

}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
