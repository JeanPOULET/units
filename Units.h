#ifndef UNITS_H
#define UNITS_H

#include <cstdint>
#include <ratio>

namespace phy {

/*
* A unit defined in terms of the base units
*/
template<int Metre, int Kilogram, int Second, int Ampere, int Kelvin, int Mole, int Candela>
struct Unit {
	static constexpr int metre    = Metre;
	static constexpr int kilogram = Kilogram;
	static constexpr int second   = Second;
	static constexpr int ampere   = Ampere;
	static constexpr int kelvin   = Kelvin;
	static constexpr int mole     = Mole;
	static constexpr int candela  = Candela;
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
	using Unit  = U;
	using Ratio = R;

	intmax_t value;

	Qty(){
		value = 0;
	}

	Qty(intmax_t v){
		value = v;
	}

	template<typename ROther>
	Qty& operator+=(Qty<U, ROther> other){
		if(this.U != other.U){
			return this;
		}
		Qty<U,R>res;
		res.value = value*R::value + other.value*R::value;
		return res;
	}

	template<typename ROther>
	Qty& operator-=(Qty<U, ROther> other){
		if(this.U != other.U){
			return this;
		}
		Qty<U,R>res;
		res.value = value*R::value - other.value*R::value;
		return res;
	}

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
	template<class Unit1>
	class addition{
		public:
		using unit_plus = Unit<Unit1::Metre,Unit1::Kilogram,Unit1::Second,Unit1::Ampere,Unit1::Kelvin,Unit1::Mole,Unit1::Candela>;
	
	};

	template<class Unit1, class Unit2>
	class division{
		public:
		using unit_div = Unit<Unit1::metre - Unit2::metre, Unit1::kilogram - Unit2::kilogram,  Unit1::second - Unit2::second, Unit1::ampere - Unit2::ampere,  Unit1::kelvin - Unit2::kelvin,  Unit1::mole - Unit2::mole,  Unit1::candela - Unit2::candela>;
	};

	template<class Unit1, class Unit2>
	struct multiplication{
		
		using unit_mult = Unit<Unit1::metre + Unit2::metre, Unit1::kilogram + Unit2::kilogram,  Unit1::second + Unit2::second, Unit1::ampere + Unit2::ampere,  Unit1::kelvin + Unit2::kelvin,  Unit1::mole + Unit2::mole,  Unit1::candela + Unit2::candela>;

	};
}

/*
* Comparison operators
*/

template<typename U, typename R1, typename R2>
bool operator==(Qty<U, R1> q1, Qty<U, R2> q2){
	if(std::ratio_equal<R1, R2>::value){
 		return q1.value == q2.value;
	}
	return q1.value == q2.value*R2::den;
}		  

template<typename U, typename R1, typename R2>
bool operator!=(Qty<U, R1> q1, Qty<U, R2> q2){
	if(std::ratio_equal<R1, R2>::value){
 		return q1.value != q2.value;
	}
	return q1.value != q2.value*R2::den;
}	

template<typename U, typename R1, typename R2>
bool operator<(Qty<U, R1> q1, Qty<U, R2> q2){
	if(std::ratio_equal<R1, R2>::value){
 		return q1.value < q2.value;
	}
	return q1.value < q2.value*R2::den;
}	

template<typename U, typename R1, typename R2>
bool operator<=(Qty<U, R1> q1, Qty<U, R2> q2){
	if(std::ratio_equal<R1, R2>::value){
 		return q1.value <= q2.value;
	}
	return q1.value <= q2.value*R2::den;
}	

template<typename U, typename R1, typename R2>
bool operator>(Qty<U, R1> q1, Qty<U, R2> q2){
	if(std::ratio_equal<R1, R2>::value){
 		return q1.value > q2.value;
	}
	return q1.value > q2.value*R2::den;
}	

template<typename U, typename R1, typename R2>
bool operator>=(Qty<U, R1> q1, Qty<U, R2> q2){
	if(std::ratio_equal<R1, R2>::value){
 		return q1.value >= q2.value;
	}
	return q1.value >= q2.value*R2::den;
}	

/*
* Arithmetic operators
*/

template<typename U, typename R1, typename R2>
Qty<U, R1> operator+(Qty<U, R1> q1, Qty<U, R2> q2){
	if(std::ratio_less<R1, R2>::value){
		Qty<U,R2> ty;
		ty.value = ((q1.value*(R1::num/R1::den)) + (q2.value*(R2::num/R2::den)));
		return ty;
	}else{
		Qty<U,R1> ty;
		ty.value = ((q1.value*(R1::num/R1::den)) + (q2.value*(R2::num/R2::den)));
		return ty;
	}
	
}

template<typename U, typename R1, typename R2>
Qty<U, R1> operator-(Qty<U, R1> q1, Qty<U, R2> q2){
	if(std::ratio_less<R1, R2>::value){
		Qty<U,R2> ty;
		ty.value = ((q1.value*(R1::num/R1::den)) - (q2.value*(R2::num/R2::den)));
		return ty;
	}else{
		Qty<U,R1> ty;
		ty.value = ((q1.value*(R1::num/R1::den)) - (q2.value*(R2::num/R2::den)));
		return ty;
	}

}

template<typename U1, typename R1, typename U2, typename R2>
Qty<details::multiplication<U1, U2>, std::ratio_multiply<R1, R2>> operator*(Qty<U1, R1> q1, Qty<U2, R2> q2){
	 
	Qty<details::multiplication<U1, U2>,std::ratio_multiply<R1, R2>> ty;
	ty.value = ((q1.value*(R1::num/R1::den)) * (q2.value*(R2::num/R2::den)));
	return ty;
}

template<typename U1, typename R1, typename U2, typename R2>
Qty<details::division<U1, U2>, std::ratio_divide<R1, R2>> operator/(Qty<U1, R1> q1, Qty<U2, R2> q2){
	Qty<details::division<U1, U2>,std::ratio_divide<R1, R2>> ty;
	ty.value = ((q1.value*(R1::num/R1::den)) / (q2.value*(R2::num/R2::den)));
	return ty;
}


/*
* Cast function between two quantities
*/
template<typename ResQty, typename U, typename R>
ResQty qtyCast(Qty<U,R> qt){
	ResQty new_qt;

	new_qt.value = qt.value*(R::num/R::den);

	return new_qt;
}

	namespace literals {

		/*
		* Some user-defined literals
		*/

		Length operator "" _metres(unsigned long long int val){
			Qty<Metre,std::ratio<1>> re(val);
			return re;
		}
		Mass operator "" _kilograms(unsigned long long int val){
			Qty<Kilogram,std::ratio<1>> re(val);
			return re;
		}
		Time operator "" _seconds(unsigned long long int val){
			Qty<Second,std::ratio<1>> re(val);
			return re;
		}
		Current operator "" _amperes(unsigned long long int val){
			Qty<Ampere,std::ratio<1>> re(val);
			return re;
		}
		Temperature operator "" _kelvins(unsigned long long int val){
			Qty<Kelvin,std::ratio<1>> re(val);
			return re;
		}
		Amount operator "" _moles(unsigned long long int val){
			Qty<Mole,std::ratio<1>> re(val);
			return re;
		}
		LuminousIntensity operator "" _candelas(unsigned long long int val){
			Qty<Candela,std::ratio<1>> re(val);
			return re;
		}

	}

}

#endif // UNITS_H
