#include "../../../core/common.h"
#include "../instructions/common.h"
#include "../instructions/OutB.h"

namespace TD4 {
	OVM::Assembly OutB::toAssembly() const
	{
		return OVM::Assembly("Out B");
	}

	bool OutB::Process(::Processor& processor)
	{
		Proxy::out(processor) = Proxy::regB(processor);
		Proxy::cFlag(processor) = 0;
		++Proxy::pc(processor);
		return true;
	}
}
