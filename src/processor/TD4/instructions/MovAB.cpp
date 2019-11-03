#include "../../../core/common.h"
#include "../instructions/common.h"
#include "../instructions/MovAB.h"

namespace TD4 {
	OVM::Assembly MovAB::toAssembly() const
	{
		return OVM::Assembly("MOV A B");
	}

	bool MovAB::Process(::Processor& processor)
	{
		Proxy::regA(processor) = Proxy::regB(processor);
		Proxy::cFlag(processor) = 0;
		++Proxy::pc(processor);
		return true;
	}
}
