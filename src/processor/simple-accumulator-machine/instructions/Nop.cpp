#include "../../../core/common.h"
#include "../instructions/common.h"
#include "../instructions/Nop.h"

namespace SimpleAccumulator {
	OVM::Assembly Nop::toAssembly() const
	{
		return OVM::Assembly("NOP");
	}

	bool Nop::Process(::Processor& processor)
	{
		++Proxy::pc(processor);
		return true;
	}
}
