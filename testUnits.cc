#include "Units.h"

#include <iostream>

#include <gtest/gtest.h>

TEST(tests,first){

  using  namespace phy:: literals;
  auto velocity = 100000_metres / 3600_seconds;
  phy::Qty<phy::Metre , std::milli> mm(32);
  auto nm = phy::qtyCast <phy::Qty <phy::Metre , std::nano >>(mm);
  
}



int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
