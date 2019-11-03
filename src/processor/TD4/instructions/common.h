#ifndef DEF_TD4_INST_COMMON_H
#define DEF_TD4_INST_COMMON_H

#include "../../../core/common.h"
#include "../Processor.h"

namespace TD4 {
	class Proxy {
		friend class Nop;
		friend class MovAIm;
		friend class MovBIm;
		friend class MovAB;
		friend class MovBA;
		friend class AddAIm;
		friend class AddBIm;
		friend class InA;
		friend class InB;
		friend class OutIm;
		friend class OutB;
		friend class Jmp;
		friend class Jnc;

	private:
		// util
		static OVM::Address& pc(::Processor& processor)
		{
			Processor* pprocessor = dynamic_cast<Processor*>(&processor);
			OVM_ASSERT(pprocessor != nullptr);
			return pprocessor->pc;
		}

		static const OVM::Address& pc(const ::Processor& processor)
		{
			const Processor* pprocessor = dynamic_cast<const Processor*>(&processor);
			OVM_ASSERT(pprocessor != nullptr);
			return pprocessor->pc;
		}

		static OVM::Byte& regA(::Processor& processor)
		{
			Processor* pprocessor = dynamic_cast<Processor*>(&processor);
			OVM_ASSERT(pprocessor != nullptr);
			return pprocessor->regA;
		}

		static const OVM::Byte& regA(const ::Processor& processor)
		{
			const Processor* pprocessor = dynamic_cast<const Processor*>(&processor);
			OVM_ASSERT(pprocessor != nullptr);
			return pprocessor->regA;
		}

		static OVM::Byte& regB(::Processor& processor)
		{
			Processor* pprocessor = dynamic_cast<Processor*>(&processor);
			OVM_ASSERT(pprocessor != nullptr);
			return pprocessor->regB;
		}

		static const OVM::Byte& regB(const ::Processor& processor)
		{
			const Processor* pprocessor = dynamic_cast<const Processor*>(&processor);
			OVM_ASSERT(pprocessor != nullptr);
			return pprocessor->regB;
		}

		static OVM::Byte& cFlag(::Processor& processor)
		{
			Processor* pprocessor = dynamic_cast<Processor*>(&processor);
			OVM_ASSERT(pprocessor != nullptr);
			return pprocessor->cFlag;
		}

		static const OVM::Byte& cFlag(const ::Processor& processor)
		{
			const Processor* pprocessor = dynamic_cast<const Processor*>(&processor);
			OVM_ASSERT(pprocessor != nullptr);
			return pprocessor->cFlag;
		}

		static OVM::Byte& in(::Processor& processor)
		{
			Processor* pprocessor = dynamic_cast<Processor*>(&processor);
			OVM_ASSERT(pprocessor != nullptr);
			return pprocessor->in;
		}

		static const OVM::Byte& in(const ::Processor & processor)
		{
			const Processor* pprocessor = dynamic_cast<const Processor*>(&processor);
			OVM_ASSERT(pprocessor != nullptr);
			return pprocessor->in;
		}

		static OVM::Byte& out(::Processor& processor)
		{
			Processor* pprocessor = dynamic_cast<Processor*>(&processor);
			OVM_ASSERT(pprocessor != nullptr);
			return pprocessor->out;
		}

		static const OVM::Byte& out(const ::Processor & processor)
		{
			const Processor* pprocessor = dynamic_cast<const Processor*>(&processor);
			OVM_ASSERT(pprocessor != nullptr);
			return pprocessor->out;
		}
	};
}

#endif /* DEF_TD4_INST_COMMON_H */
