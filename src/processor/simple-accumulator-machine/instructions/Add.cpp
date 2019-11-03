#include "../../../core/common.h"
#include <iostream>
#include <sstream>
#include "../instructions/common.h"
#include "../instructions/Add.h"

namespace SimpleAccumulator {
	Add::Add(OVM::Register imm)
		: imm(imm)
	{
	}

	OVM::Assembly Add::toAssembly() const
	{
		std::ostringstream oss;
		oss << "ADD " << imm;
		return OVM::Assembly(oss.str());
	}

	bool Add::Process(::Processor & processor)
	{
		Proxy::acc(processor) += imm;
		++Proxy::pc(processor);
		return true;
	}
}
