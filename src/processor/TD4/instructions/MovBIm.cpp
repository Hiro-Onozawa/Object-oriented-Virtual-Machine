#include "../../../core/common.h"
#include <sstream>
#include "../instructions/common.h"
#include "../instructions/MovBIm.h"

namespace TD4 {
	MovBIm::MovBIm(OVM::Byte imm)
		: imm(imm)
	{
	}

	OVM::Assembly MovBIm::toAssembly() const
	{
		std::ostringstream oss;
		oss << "MOV B " << imm;
		return OVM::Assembly(oss.str());
	}

	bool MovBIm::Process(::Processor& processor)
	{
		Proxy::regB(processor) = imm;
		Proxy::cFlag(processor) = 0;
		++Proxy::pc(processor);
		return true;
	}
}
