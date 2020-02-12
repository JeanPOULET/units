#ifndef UNITS_H
#define UNITS_H

#include <cstdint>
#include <ratio>

namespace phy {

<<<<<<< HEAD
  /*
   * A unit defined in terms of the base units
   */
  template<int Metre, int Kilogram, int Second, int Ampere, int Kelvin, int Mole, int Candela>
  struct Unit {
=======
/*
* A unit defined in terms of the base units
*/
template<int Metre, int Kilogram, int Second, int Ampere, int Kelvin, int Mole, int Candela>
struct Unit {
>>>>>>> d493dfc63198de63f390c5fba403e170097df85e
	static constexpr int metre    = Metre;
	static constexpr int kilogram = Kilogram;
	static constexpr int second   = Second;
	static constexpr int ampere   = Ampere;
	static constexpr int kelvin   = Kelvin;
	static constexpr int mole     = Mole;
	static constexpr int candela  = Candela;
<<<<<<< HEAD
  };

  /*
   * Various type aliases
   */

  using Metre     = Unit<1,0,0,0,0,0,0>;
  using Kilogram  = Unit<0,1,0,0,0,0,0>;
  using Second    = Unit<0,0,1,0,0,0,0>;
  using Ampere    = Unit<0,0,0,1,0,0,0>;
  using Kelvin    = Unit<0,0,0,0,1,0,0>;
  using Mole      = Unit<0,0,0,0,0,1,0>;
  using Candela   = Unit<0,0,0,0,0,0,1>;
  using Radian    = Unit<0,0,0,0,0,0,0>;

  /*
   * A quantity is a value associated with a unit and a ratio
   */
  template<class U, class R = std::ratio<1>>
  struct Qty {
=======
};

/*
* Various type aliases
*/

using Metre     = Unit<1,0,0,0,0,0,0>;
using Kilogram  = Unit<0,1,0,0,0,0,0>;
using Second    = Unit<0,0,1,0,0,0,0>;
using Ampere    = Unit<0,0,0,1,0,0,0>;
using Kelvin    = Unit<0,0,0,0,1,0,0>;
using Mole      = Unit<0,0,0,0,0,1,0>;
using Candela   = Unit<0,0,0,0,0,0,1>;
using Radian    = Unit<0,0,0,0,0,0,0>;

/*
* A quantity is a value associated with a unit and a ratio
*/
template<class U, class R = std::ratio<1>>
struct Qty {
>>>>>>> d493dfc63198de63f390c5fba403e170097df85e
	using Unit  = U;
	using Ratio = R;

	intmax_t value;

	Qty(intmax_t v);

	template<typename ROther>
	Qty& operator+=(Qty<U, ROther> other);

	template<typename ROther>
	Qty& operator-=(Qty<U, ROther> other);

<<<<<<< HEAD
	template<typename ROther>
	Qty& operator*=(Qty<U, ROther> other);

  };

  /*
   * Various quantities
   */

  using Length            = Qty<Metre>;
  using Mass              = Qty<Kilogram>;
  using Time              = Qty<Second>;
  using Current           = Qty<Ampere>;
  using Temperature       = Qty<Kelvin>;
  using Amount            = Qty<Mole>;
  using LuminousIntensity = Qty<Candela>;

  /*
   * Some weird quantities
   */

  using Mile = /**/;
  using Yard = /* implementation defined */;
  using Foot = /* implementation defined */;
  using Inch = /* implementation defined */;

  /*
   * Comparison operators
   */

  template<typename U, typename R1, typename R2>
  bool operator==(Qty<U, R1> q1, Qty<U, R2> q2);

  template<typename U, typename R1, typename R2>
  bool operator!=(Qty<U, R1> q1, Qty<U, R2> q2);

  template<typename U, typename R1, typename R2>
  bool operator<(Qty<U, R1> q1, Qty<U, R2> q2);

  template<typename U, typename R1, typename R2>
  bool operator<=(Qty<U, R1> q1, Qty<U, R2> q2);

  template<typename U, typename R1, typename R2>
  bool operator>(Qty<U, R1> q1, Qty<U, R2> q2);

  template<typename U, typename R1, typename R2>
  bool operator>=(Qty<U, R1> q1, Qty<U, R2> q2);

  /*
   * Arithmetic operators
   */
    
	namespace details{
		template<class qt1, class qt2>
		class addition{
			public:
			using res = Unit<qt1::metre,qt1::kilogram,qt1::second,qt1::ampere,qt1::kelvin,qt1::mole,qt1::candela>;
			return res;
		};

	};


  template<typename U, typename R1, typename R2>
  details::addition operator+(Qty<U, R1> q1, Qty<U, R2> q2);

  template<typename U, typename R1, typename R2>
  details operator-(Qty<U, R1> q1, Qty<U, R2> q2);
=======
};

/*
* Various quantities
*/

using Length            = Qty<Metre>;
using Mass              = Qty<Kilogram>;
using Time              = Qty<Second>;
using Current           = Qty<Ampere>;
using Temperature       = Qty<Kelvin>;
using Amount            = Qty<Mole>;
using LuminousIntensity = Qty<Candela>;

/*
* Some weird quantities
*/

using Mile = Qty<Metre, std::ratio<1609, 1>>;
using Yard = Qty<Metre, std::ratio<9, 10>>;
using Foot = Qty<Metre, std::ratio<3, 10>>;
using Inch = Qty<Metre, std::ratio<2, 100>>;

namespace details{
	template<class Unit1, class Unit2>
	class division{
		using unit_div = <Unit1::metre - Unit2::metre, Unit1::kilogram - Unit2::kilogram,  Unit1::Second - Unit2::Second, Unit1::Ampere - Unit2::Ampere,  Unit1::Kelvin - Unit2::Kelvin,  Unit1::Mole - Unit2::Mole,  Unit1::Candela - Unit2::Candela>;
	};

	template<class Unit1, class Unit2>
	class multiplication{
		using unit_div = <Unit1::metre + Unit2::metre, Unit1::kilogram + Unit2::kilogram,  Unit1::Second + Unit2::Second, Unit1::Ampere + Unit2::Ampere,  Unit1::Kelvin + Unit2::Kelvin,  Unit1::Mole + Unit2::Mole,  Unit1::Candela + Unit2::Candela>;
	};
}

/*
* Comparison operators
*/

template<typename U, typename R1, typename R2>
bool operator==(Qty<U, R1> q1, Qty<U, R2> q2);

template<typename U, typename R1, typename R2>
bool operator!=(Qty<U, R1> q1, Qty<U, R2> q2);

template<typename U, typename R1, typename R2>
bool operator<(Qty<U, R1> q1, Qty<U, R2> q2);

template<typename U, typename R1, typename R2>
bool operator<=(Qty<U, R1> q1, Qty<U, R2> q2);

template<typename U, typename R1, typename R2>
bool operator>(Qty<U, R1> q1, Qty<U, R2> q2);

template<typename U, typename R1, typename R2>
bool operator>=(Qty<U, R1> q1, Qty<U, R2> q2);

/*
* Arithmetic operators
*/

template<typename U, typename R1, typename R2>
Qty<U, std::ratio_add<R1, R2>> operator+(Qty<U, R1> q1, Qty<U, R2> q2);

template<typename U, typename R1, typename R2>
Qty<U, std::ratio_subtract<R1, R2>> operator-(Qty<U, R1> q1, Qty<U, R2> q2);
>>>>>>> d493dfc63198de63f390c5fba403e170097df85e

template<typename U1, typename R1, typename U2, typename R2>
Qty<details::division<U1, U2>, std::ratio_multiply<R1, R2>> operator*(Qty<U1, R1> q1, Qty<U2, R2> q2);

template<typename U1, typename R1, typename U2, typename R2>
Qty<details::division<U1, U2>, std::ratio_divide<R1, R2>> operator/(Qty<U1, R1> q1, Qty<U2, R2> q2); 


/*
* Cast function between two quantities
*/
template<typename ResQty, typename U, typename R>
ResQty qtyCast(Qty<U,R>);

	namespace literals {

		/*
		* Some user-defined literals
		*/

		Length operator "" _metres(unsigned long long int val);
		Mass operator "" _kilograms(unsigned long long int val);
		Time operator "" _seconds(unsigned long long int val);
		Current operator "" _amperes(unsigned long long int val);
		Temperature operator "" _kelvins(unsigned long long int val);
		Amount operator "" _moles(unsigned long long int val);
		LuminousIntensity operator "" _candelas(unsigned long long int val);

	}

}

#endif // UNITS_H
