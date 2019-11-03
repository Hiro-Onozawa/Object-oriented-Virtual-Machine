#ifndef DEF_SIMPLEACC_INST_COMMON_H
#define DEF_SIMPLEACC_INST_COMMON_H

#include "../../../core/common.h"
#include "../SimpleAccumulator.h"

namespace SimpleAccumulator {
	class Proxy {
		friend class Nop;
		friend class Push;
		friend class Pop;
		friend class Print;
		friend class Jez;
		friend class Add;
		friend class Load;

	private:
		// util
		static OVM::Register& pc(::Processor& processor)
		{
			Processor* pprocessor = dynamic_cast<Processor*>(&processor);
			OVM_ASSERT(pprocessor != nullptr);
			return pprocessor->pc;
		}

		static const OVM::Register& pc(const ::Processor& processor)
		{
			const Processor* pprocessor = dynamic_cast<const Processor*>(&processor);
			OVM_ASSERT(pprocessor != nullptr);
			return pprocessor->pc;
		}

		static OVM::Register& sp(::Processor& processor)
		{
			Processor* pprocessor = dynamic_cast<Processor*>(&processor);
			OVM_ASSERT(pprocessor != nullptr);
			return pprocessor->sp;
		}

		static const OVM::Register& sp(const ::Processor& processor)
		{
			const Processor* pprocessor = dynamic_cast<const Processor*>(&processor);
			OVM_ASSERT(pprocessor != nullptr);
			return pprocessor->sp;
		}

		static OVM::Register& acc(::Processor& processor)
		{
			Processor* pprocessor = dynamic_cast<Processor*>(&processor);
			OVM_ASSERT(pprocessor != nullptr);
			return pprocessor->acc;
		}

		static const OVM::Register& acc(const ::Processor& processor)
		{
			const Processor* pprocessor = dynamic_cast<const Processor*>(&processor);
			OVM_ASSERT(pprocessor != nullptr);
			return pprocessor->acc;
		}

		static Memory& heap(::Processor& processor)
		{
			Processor* pprocessor = dynamic_cast<Processor*>(&processor);
			OVM_ASSERT(pprocessor != nullptr);
			return *(pprocessor->heap);
		}

		static const Memory& heap(const ::Processor& processor)
		{
			const Processor* pprocessor = dynamic_cast<const Processor*>(&processor);
			OVM_ASSERT(pprocessor != nullptr);
			return *(pprocessor->heap);
		}

		static Memory& stack(::Processor& processor)
		{
			Processor* pprocessor = dynamic_cast<Processor*>(&processor);
			OVM_ASSERT(pprocessor != nullptr);
			return *(pprocessor->stack);
		}

		static const Memory& stack(const ::Processor& processor)
		{
			const Processor* pprocessor = dynamic_cast<const Processor*>(&processor);
			OVM_ASSERT(pprocessor != nullptr);
			return *(pprocessor->stack);
		}
	};
}

#endif /* DEF_SIMPLEACC_INST_COMMON_H */
