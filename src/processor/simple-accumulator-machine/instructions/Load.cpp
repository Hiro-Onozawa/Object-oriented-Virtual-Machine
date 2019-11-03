#include "../../../core/common.h"
#include <sstream>
#include "../instructions/common.h"
#include "../instructions/Load.h"

namespace SimpleAccumulator {
	Load::Load(OVM::Register imm)
		: imm(imm)
	{
	}

	OVM::Assembly Load::toAssembly() const
	{
		std::ostringstream oss;
		oss << "LOAD " << imm;
		return OVM::Assembly(oss.str());
	}

	bool Load::Process(::Processor & processor)
	{
		Proxy::acc(processor) = imm;
		++Proxy::pc(processor);
		return true;
	}
}
