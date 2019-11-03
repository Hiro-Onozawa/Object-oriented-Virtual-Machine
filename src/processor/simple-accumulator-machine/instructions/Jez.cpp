#include "../../../core/common.h"
#include <sstream>
#include "../instructions/common.h"
#include "../instructions/Jez.h"

namespace SimpleAccumulator {
	Jez::Jez(OVM::Register pc)
		: pc(pc)
	{
	}

	OVM::Assembly Jez::toAssembly() const
	{
		std::ostringstream oss;
		oss << "JEZ " << pc;
		return OVM::Assembly(oss.str());
	}

	bool Jez::Process(::Processor& processor)
	{
		if (Proxy::acc(processor) == 0) Proxy::pc(processor) = pc;
		else ++Proxy::pc(processor);
		return true;
	}
}
