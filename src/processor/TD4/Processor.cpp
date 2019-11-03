#include "../../core/common.h"
#ifdef OVM_DEBUG
#include <iostream>
#endif
#include "Processor.h"
#include "../../core/Program.h"
#include "../../core/Instruction.h"

namespace TD4 {
	Processor::Processor(size_t programSize)
		: pc(0)
		, regA(0)
		, regB(0)
		, cFlag(0)
		, in(0)
		, out(0)
		, program(new Program(programSize))
	{
		OVM_ASSERT(program != nullptr);
	}

	Processor::~Processor()
	{
		OVM_ASSERT(program != nullptr);

		delete program;
	}

	void Processor::reset()
	{
		pc = 0;
		regA = 0;
		regB = 0;
		cFlag = 0;
		in = 0;
		out = 0;
	}

	bool Processor::setInstruction(OVM::Address addr, Instruction * inst)
	{
		return program->set(addr + 1, inst);
	}

	Instruction * Processor::getInstruction(OVM::Address addr) const
	{
		return program->get(addr + 1);
	}

	bool Processor::step()
	{
		Instruction * cur = getInstruction(pc);
		if (cur == nullptr) return false;

#ifdef OVM_DEBUG
		std::cout << cur->toAssembly() << std::endl;
#endif

		if (!cur->Process(*this)) {
			pc = static_cast<OVM::Address>(-1);
			return false;
		}

#ifdef OVM_DEBUG
		std::cout
			<< "pc   " << static_cast<uint32_t>(pc) << ", "
			<< "regA " << static_cast<uint32_t>(regA) << ", "
			<< "regB " << static_cast<uint32_t>(regB) << ", "
			<< "c    " << static_cast<uint32_t>(cFlag)
			<< std::endl;
#endif

		return true;
	}

	bool Processor::setIn(OVM::Byte byte)
	{
		in = byte;
		return true;
	}

	OVM::Byte Processor::getOut() const
	{
		return out;
	}
}