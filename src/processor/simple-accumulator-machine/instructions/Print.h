#ifndef DEF_SIMPLEACC_INST_PRINT_H
#define DEF_SIMPLEACC_INST_PRINT_H

#include "../../../core/common.h"
#include "../../../core/Instruction.h"

namespace SimpleAccumulator {
	class Print final : public Instruction {
	public:
		Print() = default;
		virtual ~Print() = default;

		virtual OVM::Assembly toAssembly() const override;

		virtual bool Process(::Processor& processor) override;
	};
}

#endif /* DEF_SIMPLEACC_INST_PRINT_H */
