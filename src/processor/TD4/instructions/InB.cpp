#include "../../../core/common.h"
#include "../instructions/common.h"
#include "../instructions/InB.h"

namespace TD4 {
	OVM::Assembly InB::toAssembly() const
	{
		return OVM::Assembly("In B");
	}

	bool InB::Process(::Processor& processor)
	{
		Proxy::regB(processor) = Proxy::in(processor);
		Proxy::cFlag(processor) = 0;
		++Proxy::pc(processor);
		return true;
	}
}
