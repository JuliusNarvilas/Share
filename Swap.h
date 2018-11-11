#pragma once

#include <stdint.h>
#include "SwapIntrinsic.hpp"

#define BOOST_ENDIAN_NO_INTRINSICS

namespace endian
{

	inline int8_t endian_reverse(int8_t x)
	{
		return x;
	}

	inline int16_t endian_reverse(int16_t x)
	{
# ifdef BOOST_ENDIAN_NO_INTRINSICS
		return (static_cast<uint16_t>(x) << 8)
			| (static_cast<uint16_t>(x) >> 8);
# else
		return static_cast<int16_t>(
			BOOST_ENDIAN_INTRINSIC_BYTE_SWAP_2(static_cast<uint16_t>(x)));
# endif
	}

	inline int32_t endian_reverse(int32_t x)
	{
# ifdef BOOST_ENDIAN_NO_INTRINSICS
		uint32_t step16;
		step16 = static_cast<uint32_t>(x) << 16 | static_cast<uint32_t>(x) >> 16;
		return
			((static_cast<uint32_t>(step16) << 8) & 0xff00ff00)
			| ((static_cast<uint32_t>(step16) >> 8) & 0x00ff00ff);
# else
		return static_cast<int32_t>(
			BOOST_ENDIAN_INTRINSIC_BYTE_SWAP_4(static_cast<uint32_t>(x)));
# endif
	}

	inline int64_t endian_reverse(int64_t x)
	{
# ifdef BOOST_ENDIAN_NO_INTRINSICS
		uint64_t step32, step16;
		step32 = static_cast<uint64_t>(x) << 32 | static_cast<uint64_t>(x) >> 32;
		step16 = (step32 & 0x0000FFFF0000FFFFULL) << 16
			| (step32 & 0xFFFF0000FFFF0000ULL) >> 16;
		return static_cast<int64_t>((step16 & 0x00FF00FF00FF00FFULL) << 8
			| (step16 & 0xFF00FF00FF00FF00ULL) >> 8);
# else
		return static_cast<int64_t>(
			BOOST_ENDIAN_INTRINSIC_BYTE_SWAP_8(static_cast<uint64_t>(x)));
# endif
	}

	inline uint8_t endian_reverse(uint8_t x)
	{
		return x;
	}

	inline uint16_t endian_reverse(uint16_t x)
	{
# ifdef BOOST_ENDIAN_NO_INTRINSICS
		return (x << 8)
			| (x >> 8);
# else
		return BOOST_ENDIAN_INTRINSIC_BYTE_SWAP_2(x);
# endif
	}

	inline uint32_t endian_reverse(uint32_t x)
	{
# ifdef BOOST_ENDIAN_NO_INTRINSICS
		uint32_t step16;
		step16 = x << 16 | x >> 16;
		return
			((step16 << 8) & 0xff00ff00)
			| ((step16 >> 8) & 0x00ff00ff);
# else
		return BOOST_ENDIAN_INTRINSIC_BYTE_SWAP_4(x);
# endif
	}

	inline uint64_t endian_reverse(uint64_t x)
	{
# ifdef BOOST_ENDIAN_NO_INTRINSICS
		uint64_t step32, step16;
		step32 = x << 32 | x >> 32;
		step16 = (step32 & 0x0000FFFF0000FFFFULL) << 16
			| (step32 & 0xFFFF0000FFFF0000ULL) >> 16;
		return (step16 & 0x00FF00FF00FF00FFULL) << 8
			| (step16 & 0xFF00FF00FF00FF00ULL) >> 8;
# else
		return BOOST_ENDIAN_INTRINSIC_BYTE_SWAP_8(x);
# endif
	}

}