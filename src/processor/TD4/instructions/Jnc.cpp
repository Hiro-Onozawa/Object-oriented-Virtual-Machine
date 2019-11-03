#include "../../../core/common.h"
#include <sstream>
#include "../instructions/common.h"
#include "../instructions/Jnc.h"

namespace TD4 {
	Jnc::Jnc(OVM::Address imm)
		: imm(imm)
	{
	}

	OVM::Assembly Jnc::toAssembly() const
	{
		std::ostringstream oss;
		oss << "JNC " << imm;
		return OVM::Assembly(oss.str());
	}

	bool Jnc::Process(::Processor& processor)
	{
		const OVM::Byte cFlag = Proxy::cFlag(processor);
		Proxy::cFlag(processor) = 0;
		if (cFlag == 0) Proxy::pc(processor) = imm;
		else ++Proxy::pc(processor);
		return true;
	}
}
