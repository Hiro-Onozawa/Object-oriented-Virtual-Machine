#include "../../../core/common.h"
#include "../instructions/common.h"
#include "../instructions/InA.h"

namespace TD4 {
	OVM::Assembly InA::toAssembly() const
	{
		return OVM::Assembly("In A");
	}

	bool InA::Process(::Processor& processor)
	{
		Proxy::regA(processor) = Proxy::in(processor);
		Proxy::cFlag(processor) = 0;
		++Proxy::pc(processor);
		return true;
	}
}
