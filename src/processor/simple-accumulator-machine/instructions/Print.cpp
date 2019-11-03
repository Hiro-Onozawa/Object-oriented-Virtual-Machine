#include "../../../core/common.h"
#include <iostream>
#include "../instructions/common.h"
#include "../instructions/Print.h"

namespace SimpleAccumulator {
	OVM::Assembly Print::toAssembly() const
	{
		return OVM::Assembly("PRINT");
	}

	bool Print::Process(::Processor& processor)
	{
		std::cout << Proxy::acc(processor) << std::endl;
		++Proxy::pc(processor);
		return true;
	}
}
