#include "../../../core/common.h"
#include "../instructions/common.h"
#include "../instructions/MovBA.h"

namespace TD4 {
	OVM::Assembly MovBA::toAssembly() const
	{
		return OVM::Assembly("MOV B A");
	}

	bool MovBA::Process(::Processor& processor)
	{
		Proxy::regB(processor) = Proxy::regA(processor);
		Proxy::cFlag(processor) = 0;
		++Proxy::pc(processor);
		return true;
	}
}
