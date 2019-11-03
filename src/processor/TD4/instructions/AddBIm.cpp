#include "../../../core/common.h"
#include <sstream>
#include "../instructions/common.h"
#include "../instructions/AddBIm.h"

namespace TD4 {
	AddBIm::AddBIm(OVM::Byte imm)
		: imm(imm & 0x0f)
	{
	}

	OVM::Assembly AddBIm::toAssembly() const
	{
		std::ostringstream oss;
		oss << "ADD B " << static_cast<uint32_t>(imm);
		return OVM::Assembly(oss.str());
	}

	bool AddBIm::Process(::Processor& processor)
	{
		const OVM::Byte regB = Proxy::regB(processor);
		const OVM::Byte newVal = regB + imm;
		Proxy::regB(processor) = newVal & 0x0f;
		Proxy::cFlag(processor) = (newVal & ~0x0f) != 0 ? 1 : 0;
		++Proxy::pc(processor);
		return true;
	}
}
