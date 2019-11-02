#include "common.h"
#include <cstdlib>
#include "Memory.h"

	
Memory::Memory(size_t size)
	: mem((OVM::Word *)std::malloc(sizeof(OVM::Word) * size))
	, size(size)
{
	OVM_ASSERT(mem != nullptr);
}

Memory::~Memory()
{
	OVM_ASSERT(mem != nullptr);
	
	std::free(mem);
}

bool Memory::isValidAddres(OVM::Address addr) const
{
	return addr != 0 && addr <= size;
}

OVM::Word Memory::read(OVM::Address addr) const
{
	if (!isValidAddres(addr)) {
		OVM_ASSERT(false);
		return OVM::Word(0);
	}
	
	return mem[addr];
}

bool Memory::write(OVM::Address addr, OVM::Word w)
{
	if (!isValidAddres(addr)) return false;
	
	mem[addr] = w;
	return true;
}