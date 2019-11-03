#include "../../../core/common.h"
#include "../instructions/common.h"
#include "../instructions/Push.h"
#include "../../../core/Memory.h"

namespace SimpleAccumulator {
	OVM::Assembly Push::toAssembly() const
	{
		return OVM::Assembly("PUSH");
	}

	bool Push::Process(::Processor& processor)
	{
		++Proxy::sp(processor);
		const bool result = Proxy::stack(processor).write(static_cast<OVM::Address>(Proxy::sp(processor)), Proxy::acc(processor));
		++Proxy::pc(processor);
		return result;
	}
}
