#include "../../../core/common.h"
#include "../instructions/common.h"
#include "../instructions/Pop.h"
#include "../../../core/Memory.h"

namespace SimpleAccumulator {
	OVM::Assembly Pop::toAssembly() const
	{
		return OVM::Assembly("POP");
	}

	bool Pop::Process(::Processor& processor)
	{
		Proxy::acc(processor) = Proxy::stack(processor).read(static_cast<OVM::Address>(Proxy::sp(processor)));
		--Proxy::sp(processor);
		++Proxy::pc(processor);
		return true;
	}
}
