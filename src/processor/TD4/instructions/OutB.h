#ifndef DEF_TD4_INST_OUTB_H
#define DEF_TD4_INST_OUTB_H

#include "../../../core/common.h"
#include "../../../core/Instruction.h"

namespace TD4 {
	class OutB final : public Instruction {
	public:
		OutB() = default;
		virtual ~OutB() = default;

		OVM::Assembly toAssembly() const override;

		bool Process(::Processor& processor) override;
	};
}

#endif /* DEF_TD4_INST_OUTB_H */
