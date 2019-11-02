#ifndef DEF_COMMON_H
#define DEF_COMMON_H

#include <cstdint>
#include <string>

#if defined(_MSC_VER) && !defined(_DEBUG)

#ifndef NDEBUG
#define NDEBUG
#endif /* NDEBUG */

#endif /* defined(_MSC_VER) && defined(_DEBUG) */

#if !defined(NDEBUG)

#ifndef OVM_DEBUG
#define OVM_DEBUG
#endif /* OVM_DEBUG */

#ifdef OVM_NDEBUG
#undef OVM_NDEBUG
#endif /* OVM_NDEBUG */

#else

#ifndef OVM_NDEBUG
#define OVM_NDEBUG
#endif /* OVM_NDEBUG */

#ifdef OVM_DEBUG
#undef OVM_DEBUG
#endif /* OVM_DEBUG */

#endif /* !defined(NDEBUG) */

#ifdef OVM_DEBUG
#include <cassert>
#define OVM_ASSERT(expr) assert((expr))
#else
#define OVM_ASSERT(expr) do { } while (false)
#endif /* OVM_DEBUG */

namespace OVM {
	typedef uint8_t Byte;
	typedef uint32_t Word;
	
	typedef uint32_t Address;
	typedef uint32_t Binary;
	typedef std::string Assembly;
	
	typedef Word Register;
}

#endif /* DEF_COMMON_H */
