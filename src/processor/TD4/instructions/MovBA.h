#ifndef DEF_TD4_INST_MOVBA_H
#define DEF_TD4_INST_MOVBA_H

#include "../../../core/common.h"
#include "../../../core/Instruction.h"

namespace TD4 {
	class MovBA final : public Instruction {
	public:
		MovBA() = default;
		virtual ~MovBA() = default;

		OVM::Assembly toAssembly() const override;

		bool Process(::Processor& processor) override;
	};
}

#endif /* DEF_TD4_INST_MOVBA_H */
