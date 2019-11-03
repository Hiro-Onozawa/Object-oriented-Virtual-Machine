#include "../../../core/common.h"
#include <sstream>
#include "../instructions/common.h"
#include "../instructions/Jmp.h"

namespace TD4 {
	Jmp::Jmp(OVM::Address imm)
		: imm(imm)
	{
	}

	OVM::Assembly Jmp::toAssembly() const
	{
		std::ostringstream oss;
		oss << "JMP " << imm;
		return OVM::Assembly(oss.str());
	}

	bool Jmp::Process(::Processor& processor)
	{
		Proxy::cFlag(processor) = 0;
		Proxy::pc(processor) = imm;
		return true;
	}
}
