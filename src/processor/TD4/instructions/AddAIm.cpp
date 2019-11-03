#include "../../../core/common.h"
#include <sstream>
#include "../instructions/common.h"
#include "../instructions/AddAIm.h"

namespace TD4 {
	AddAIm::AddAIm(OVM::Byte imm)
		: imm(imm & 0x0f)
	{
	}

	OVM::Assembly AddAIm::toAssembly() const
	{
		std::ostringstream oss;
		oss << "ADD A " << static_cast<uint32_t>(imm);
		return OVM::Assembly(oss.str());
	}

	bool AddAIm::Process(::Processor& processor)
	{
		const OVM::Byte regA = Proxy::regA(processor);
		const OVM::Byte newVal = regA + imm;
		Proxy::regA(processor) = newVal & 0x0f;
		Proxy::cFlag(processor) = (newVal & ~0x0f) != 0 ? 1 : 0;
		++Proxy::pc(processor);
		return true;
	}
}
