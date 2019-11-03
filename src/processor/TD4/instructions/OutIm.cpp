#include "../../../core/common.h"
#include <sstream>
#include "../instructions/common.h"
#include "../instructions/OutIm.h"

namespace TD4 {
	OutIm::OutIm(OVM::Byte imm)
		: imm(imm)
	{
	}

	OVM::Assembly OutIm::toAssembly() const
	{
		std::ostringstream oss;
		oss << "OUT " << static_cast<uint32_t>(imm);
		return OVM::Assembly(oss.str());
	}

	bool OutIm::Process(::Processor& processor)
	{
		Proxy::out(processor) = imm;
		Proxy::cFlag(processor) = 0;
		++Proxy::pc(processor);
		return true;
	}
}
