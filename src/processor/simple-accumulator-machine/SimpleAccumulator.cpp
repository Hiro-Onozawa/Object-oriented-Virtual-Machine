#include "../../core/common.h"
#ifdef OVM_DEBUG
#include <iostream>
#endif
#include "SimpleAccumulator.h"
#include "../../core/Program.h"
#include "../../core/Instruction.h"
#include "../../core/Memory.h"

namespace SimpleAccumulator {
	Processor::Processor(size_t heapSize, size_t stackSize, size_t programSize)
		: pc(1)
		, sp(0)
		, acc(0)
		, heap(new Memory(heapSize))
		, stack(new Memory(stackSize))
		, program(new Program(programSize))
	{
		OVM_ASSERT(heap != nullptr);
		OVM_ASSERT(stack != nullptr);
		OVM_ASSERT(program != nullptr);
	}

	Processor::~Processor()
	{
		OVM_ASSERT(program != nullptr);
		OVM_ASSERT(stack != nullptr);
		OVM_ASSERT(heap != nullptr);

		delete program;
		delete stack;
		delete heap;
	}

	void Processor::reset()
	{
		pc = 1;
		sp = 0;
		acc = 0;
	}

	bool Processor::setInstruction(OVM::Address addr, Instruction * inst)
	{
		return program->set(addr, inst);
	}

	Instruction * Processor::getInstruction(OVM::Address addr) const
	{
		return program->get(addr);
	}

	bool Processor::step()
	{
		Instruction * cur = getInstruction(static_cast<OVM::Address>(pc));
		if (cur == nullptr) return false;

#ifdef OVM_DEBUG
		std::cout << cur->toAssembly() << std::endl;
#endif

		if (!cur->Process(*this)) {
			pc = 0;
			return false;
		}

		return true;
	}
}