#include "common.h"
#include <cstdlib>
#include "Program.h"
#include "Instruction.h"


Program::Program(size_t size)
	: insts((Instruction **)std::malloc(sizeof(Instruction *) * size))
	, size(size)
{
	OVM_ASSERT(insts != nullptr);
	
	for (size_t i = 0; i < size; ++i) {
		insts[i] = nullptr;
	}
}

Program::~Program()
{
	OVM_ASSERT(insts != nullptr);
	
	for (size_t i = 0; i < size; ++i) {
		delete insts[i];
	}
}

bool Program::isValidAddres(OVM::Address addr) const
{
	return addr != 0 && addr <= size;
}

bool Program::set(size_t addr, Instruction * inst)
{
	if (!isValidAddres(addr)) return false;
	
	delete insts[addr - 1];
	insts[addr - 1] = inst;
	
	return true;
}

Instruction * Program::get(OVM::Address addr) const
{
	if (!isValidAddres(addr)) {
		OVM_ASSERT(false);
		return nullptr;
	}
	
	return insts[addr - 1];
}