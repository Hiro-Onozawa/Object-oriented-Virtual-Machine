#ifndef DEF_SIMPLEACC_INST_POP_H
#define DEF_SIMPLEACC_INST_POP_H

#include "../../../core/common.h"
#include "../../../core/Instruction.h"

namespace SimpleAccumulator {
	class Pop final : public Instruction {
	public:
		Pop() = default;
		virtual ~Pop() = default;

		virtual OVM::Assembly toAssembly() const override;

		virtual bool Process(::Processor& processor) override;
	};
}

#endif /* DEF_SIMPLEACC_INST_POP_H */
