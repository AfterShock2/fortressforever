
// ff_lualib_math.cpp

//---------------------------------------------------------------------------
// includes
//---------------------------------------------------------------------------
// includes
#include "cbase.h"
#include "ff_lualib.h"
#include "ff_utils.h"

// Lua includes
extern "C"
{
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
}

#include "luabind/luabind.hpp"
#include "luabind/operator.hpp"
#include "luabind/object.hpp"
#include "luabind/iterator_policy.hpp"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

//---------------------------------------------------------------------------
using namespace luabind;

// Valve, you fucking suck
//std::ostream& operator<<(std::ostream&s, const Vector&v)
//{
//	s << v.x << " " << v.y << " " << v.z;
//	return s;
//}

//---------------------------------------------------------------------------
void CFFLuaLib::InitMath(lua_State* L)
{
	ASSERT(L);

	module(L)
	[
		class_<Vector>("Vector")
			//.def(tostring(const_self))
			.def(constructor<>())
			.def(constructor<float, float, float>())
			.def_readwrite("x",			&Vector::x)
			.def_readwrite("y",			&Vector::y)
			.def_readwrite("z",			&Vector::z)
			.def("IsValid",				&Vector::IsValid)
			.def("IsZero",				&Vector::IsZero)
			.def("DistTo",				&Vector::DistTo)
			.def("DistToSq",			&Vector::DistToSqr)
			.def("Dot",					&Vector::Dot)
			.def("Length",				&Vector::Length)
			.def("LengthSqr",			&Vector::LengthSqr)
			.def("Normalize",			&Vector::NormalizeInPlace)
			.def("ClampToAABB",			&Vector::ClampToAABB)
			.def("Negate",				&Vector::Negate),

		class_<QAngle>("QAngle")
			.def(constructor<>())
			.def(constructor<float, float, float>())
			.def_readwrite("x",			&QAngle::x)
			.def_readwrite("y",			&QAngle::y)
			.def_readwrite("z",			&QAngle::z)
			.def("IsValid",				&QAngle::IsValid)
			.def("Length",				&QAngle::Length)
			.def("LengthSqr",			&QAngle::LengthSqr),

		class_<Color>("Color")
			.def(constructor<>())
			.def(constructor<int, int, int>())
			.def(constructor<int, int, int, int>())
			.def("r",					&Color::r)
			.def("g",					&Color::g)
			.def("b",					&Color::b)
			.def("a",					&Color::a)
			.def("SetColor",			&Color::SetColor)
			.def("GetColor",			&Color::GetColor)
	];
};
