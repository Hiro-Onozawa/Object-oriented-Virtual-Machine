#include "../../../core/common.h"
#include <sstream>
#include "../instructions/common.h"
#include "../instructions/MovAIm.h"

namespace TD4 {
	MovAIm::MovAIm(OVM::Byte imm)
		: imm(imm)
	{
	}

	OVM::Assembly MovAIm::toAssembly() const
	{
		std::ostringstream oss;
		oss << "MOV A " << imm;
		return OVM::Assembly(oss.str());
	}

	bool MovAIm::Process(::Processor& processor)
	{
		Proxy::regA(processor) = imm;
		Proxy::cFlag(processor) = 0;
		++Proxy::pc(processor);
		return true;
	}
}
