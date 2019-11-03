#ifndef DEF_TD4_INST_MOVAB_H
#define DEF_TD4_INST_MOVAB_H

#include "../../../core/common.h"
#include "../../../core/Instruction.h"

namespace TD4 {
	class MovAB final : public Instruction {
	public:
		MovAB() = default;
		virtual ~MovAB() = default;

		OVM::Assembly toAssembly() const override;

		bool Process(::Processor& processor) override;
	};
}

#endif /* DEF_TD4_INST_MOVAB_H */
