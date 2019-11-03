#ifndef DEF_SIMPLEACC_INST_PUSH_H
#define DEF_SIMPLEACC_INST_PUSH_H

#include "../../../core/common.h"
#include "../../../core/Instruction.h"

namespace SimpleAccumulator {
	class Push final : public Instruction {
	public:
		Push() = default;
		virtual ~Push() = default;

		virtual OVM::Assembly toAssembly() const override;

		virtual bool Process(::Processor& processor) override;
	};
}

#endif /* DEF_SIMPLEACC_INST_PUSH_H */
