#include "../CL/Assert.h"
#include "ByteCode.h"
#include "Interpreter.h"

namespace JVM
{

	const char* ByteCodeString(ByteCode bytecode)
	{
		switch (bytecode) {
#define __ENUMERATE_BYTECODE(bytecode, x) \
            case ByteCode::bytecode:   \
                return #bytecode;

			ENUMERATE_BYTECODES
#undef __ENUMERATE_BYTECODE
		};

		ASSERT_NOT_REACHED();
	}

	Interpreter::Interpreter(uint8_t bytes[], size_t length)
	{
		m_pc = 0;
		m_last_val = 0;
		memcpy(m_program, bytes, length);
		m_program_size = length;
		memset(m_localVars, 0, JVM_MAX_LOCAL_VARS);
	}

	Interpreter::~Interpreter()
	{
	}

	uint8_t Interpreter::next_byte()
	{
		return m_program[m_pc++];
	}

	int8_t Interpreter::get_last_val()
	{
		return m_last_val;
	}

	void Interpreter::PrintProgram()
	{
		TODO();
	}

	ByteCode Interpreter::next_exec()
	{
		ByteCode bytecode = (ByteCode) next_byte();

		switch (bytecode)
		{
		case ByteCode::_aaload:
			ASSERT_NOT_REACHED();
		case ByteCode::_aastore:
			ASSERT_NOT_REACHED();
		case ByteCode::_aconst_null:
			ASSERT_NOT_REACHED();
		case ByteCode::_aload:
			ASSERT_NOT_REACHED();
		case ByteCode::_aload_0:
			ASSERT_NOT_REACHED();
		case ByteCode::_aload_1:
			ASSERT_NOT_REACHED();
		case ByteCode::_aload_2:
			ASSERT_NOT_REACHED();
		case ByteCode::_aload_3:
			ASSERT_NOT_REACHED();
		case ByteCode::_anewarray:
			ASSERT_NOT_REACHED();
		case ByteCode::_areturn:
			ASSERT_NOT_REACHED();
		case ByteCode::_arraylength:
			ASSERT_NOT_REACHED();
		case ByteCode::_astore:
			ASSERT_NOT_REACHED();
		case ByteCode::_astore_0:
			ASSERT_NOT_REACHED();
		case ByteCode::_astore_1:
			ASSERT_NOT_REACHED();
		case ByteCode::_astore_2:
			ASSERT_NOT_REACHED();
		case ByteCode::_astore_3:
			ASSERT_NOT_REACHED();
		case ByteCode::_athrow:
			ASSERT_NOT_REACHED();
		case ByteCode::_baload:
			ASSERT_NOT_REACHED();
		case ByteCode::_bastore:
			ASSERT_NOT_REACHED();
		case ByteCode::_bipush:
		{
			int8_t val = (int8_t)next_byte();
			m_op_stack.push(val);
			break;
		}
			ASSERT_NOT_REACHED();
		case ByteCode::_breakpoint:
			ASSERT_NOT_REACHED();
		case ByteCode::_caload:
			ASSERT_NOT_REACHED();
		case ByteCode::_castore:
			ASSERT_NOT_REACHED();
		case ByteCode::_checkcast:
			ASSERT_NOT_REACHED();
		case ByteCode::_d2f:
			ASSERT_NOT_REACHED();
		case ByteCode::_d2i:
			ASSERT_NOT_REACHED();
		case ByteCode::_d2l:
			ASSERT_NOT_REACHED();
		case ByteCode::_dadd:
			ASSERT_NOT_REACHED();
		case ByteCode::_daload:
			ASSERT_NOT_REACHED();
		case ByteCode::_dastore:
			ASSERT_NOT_REACHED();
		case ByteCode::_dcmpg:
			ASSERT_NOT_REACHED();
		case ByteCode::_dcmpl:
			ASSERT_NOT_REACHED();
		case ByteCode::_dconst_0:
			ASSERT_NOT_REACHED();
		case ByteCode::_dconst_1:
			ASSERT_NOT_REACHED();
		case ByteCode::_ddiv:
			ASSERT_NOT_REACHED();
		case ByteCode::_dload:
			ASSERT_NOT_REACHED();
		case ByteCode::_dload_0:
			ASSERT_NOT_REACHED();
		case ByteCode::_dload_1:
			ASSERT_NOT_REACHED();
		case ByteCode::_dload_2:
			ASSERT_NOT_REACHED();
		case ByteCode::_dload_3:
			ASSERT_NOT_REACHED();
		case ByteCode::_dmul:
			ASSERT_NOT_REACHED();
		case ByteCode::_dneg:
			ASSERT_NOT_REACHED();
		case ByteCode::_drem:
			ASSERT_NOT_REACHED();
		case ByteCode::_dreturn:
			ASSERT_NOT_REACHED();
		case ByteCode::_dstore:
			ASSERT_NOT_REACHED();
		case ByteCode::_dstore_0:
			ASSERT_NOT_REACHED();
		case ByteCode::_dstore_1:
			ASSERT_NOT_REACHED();
		case ByteCode::_dstore_2:
			ASSERT_NOT_REACHED();
		case ByteCode::_dstore_3:
			ASSERT_NOT_REACHED();
		case ByteCode::_dsub:
			ASSERT_NOT_REACHED();
		case ByteCode::_dup:
			ASSERT_NOT_REACHED();
		case ByteCode::_dup_x1:
			ASSERT_NOT_REACHED();
		case ByteCode::_dup_x2:
			ASSERT_NOT_REACHED();
		case ByteCode::_dup2:
			ASSERT_NOT_REACHED();
		case ByteCode::_dup2_x1:
			ASSERT_NOT_REACHED();
		case ByteCode::_dup2_x2:
			ASSERT_NOT_REACHED();
		case ByteCode::_f2d:
			ASSERT_NOT_REACHED();
		case ByteCode::_f2i:
			ASSERT_NOT_REACHED();
		case ByteCode::_f2l:
			ASSERT_NOT_REACHED();
		case ByteCode::_fadd:
			ASSERT_NOT_REACHED();
		case ByteCode::_faload:
			ASSERT_NOT_REACHED();
		case ByteCode::_fastore:
			ASSERT_NOT_REACHED();
		case ByteCode::_fcmpg:
			ASSERT_NOT_REACHED();
		case ByteCode::_fcmpl:
			ASSERT_NOT_REACHED();
		case ByteCode::_fconst_0:
			ASSERT_NOT_REACHED();
		case ByteCode::_fconst_1:
			ASSERT_NOT_REACHED();
		case ByteCode::_fconst_2:
			ASSERT_NOT_REACHED();
		case ByteCode::_fdiv:
			ASSERT_NOT_REACHED();
		case ByteCode::_fload:
			ASSERT_NOT_REACHED();
		case ByteCode::_fload_0:
			ASSERT_NOT_REACHED();
		case ByteCode::_fload_1:
			ASSERT_NOT_REACHED();
		case ByteCode::_fload_2:
			ASSERT_NOT_REACHED();
		case ByteCode::_fload_3:
			ASSERT_NOT_REACHED();
		case ByteCode::_fmul:
			ASSERT_NOT_REACHED();
		case ByteCode::_fneg:
			ASSERT_NOT_REACHED();
		case ByteCode::_frem:
			ASSERT_NOT_REACHED();
		case ByteCode::_freturn:
			ASSERT_NOT_REACHED();
		case ByteCode::_fstore:
			ASSERT_NOT_REACHED();
		case ByteCode::_fstore_0:
			ASSERT_NOT_REACHED();
		case ByteCode::_fstore_1:
			ASSERT_NOT_REACHED();
		case ByteCode::_fstore_2:
			ASSERT_NOT_REACHED();
		case ByteCode::_fstore_3:
			ASSERT_NOT_REACHED();
		case ByteCode::_fsub:
			ASSERT_NOT_REACHED();
		case ByteCode::_getfield:
			ASSERT_NOT_REACHED();
		case ByteCode::_getstatic:
			ASSERT_NOT_REACHED();
		case ByteCode::_goto:
		{
			uint8_t branchbyte1 = next_byte();
			uint8_t branchbyte2 = next_byte();
			m_pc = (branchbyte1 << 8) | branchbyte2;
			break;
		}
		case ByteCode::_goto_w:
			ASSERT_NOT_REACHED();
		case ByteCode::_i2b:
			ASSERT_NOT_REACHED();
		case ByteCode::_i2c:
			ASSERT_NOT_REACHED();
		case ByteCode::_i2d:
			ASSERT_NOT_REACHED();
		case ByteCode::_i2f:
			ASSERT_NOT_REACHED();
		case ByteCode::_i2l:
			ASSERT_NOT_REACHED();
		case ByteCode::_i2s:
			ASSERT_NOT_REACHED();
		case ByteCode::_iadd:
			ASSERT_NOT_REACHED();
		case ByteCode::_iaload:
			ASSERT_NOT_REACHED();
		case ByteCode::_iand:
			ASSERT_NOT_REACHED();
		case ByteCode::_iastore:
			ASSERT_NOT_REACHED();
		case ByteCode::_iconst_m1:
		{
			m_op_stack.push(-1);
			break;
		}
		case ByteCode::_iconst_0:
		{
			m_op_stack.push(0);
			break;
		}
		case ByteCode::_iconst_1:
		{
			m_op_stack.push(1);
			break;
		}
		case ByteCode::_iconst_2:
		{
			m_op_stack.push(2);
			break;
		}
		case ByteCode::_iconst_3:
			ASSERT_NOT_REACHED();
		case ByteCode::_iconst_4:
			ASSERT_NOT_REACHED();
		case ByteCode::_iconst_5:
			ASSERT_NOT_REACHED();
		case ByteCode::_idiv:
			ASSERT_NOT_REACHED();
		case ByteCode::_if_acmpeq:
			ASSERT_NOT_REACHED();
		case ByteCode::_if_acmpne:
			ASSERT_NOT_REACHED();
		case ByteCode::_if_icmpeq:
			ASSERT_NOT_REACHED();
		case ByteCode::_if_icmpge:
			ASSERT_NOT_REACHED();
		case ByteCode::_if_icmpgt:
			ASSERT_NOT_REACHED();
		case ByteCode::_if_icmple:
			ASSERT_NOT_REACHED();
		case ByteCode::_if_icmplt:
		{
			uint8_t branchbyte1 = next_byte();
			uint8_t branchbyte2 = next_byte();

			int value2 = m_op_stack.pop();
			int value1 = m_op_stack.pop();

			if (value1 < value2) {
				m_pc = (branchbyte1 << 8) | branchbyte2;
			}

			break;
		}
		case ByteCode::_if_icmpne:
			ASSERT_NOT_REACHED();
		case ByteCode::_ifeq:
			ASSERT_NOT_REACHED();
		case ByteCode::_ifge:
			ASSERT_NOT_REACHED();
		case ByteCode::_ifgt:
			ASSERT_NOT_REACHED();
		case ByteCode::_ifle:
			ASSERT_NOT_REACHED();
		case ByteCode::_iflt:
			ASSERT_NOT_REACHED();
		case ByteCode::_ifne:
			ASSERT_NOT_REACHED();
		case ByteCode::_ifnonnull:
			ASSERT_NOT_REACHED();
		case ByteCode::_ifnull:
			ASSERT_NOT_REACHED();
		case ByteCode::_iinc:
		{
			uint8_t index = next_byte();
			int8_t val = next_byte();
			m_localVars[index] += val;
			break;
		}
			ASSERT_NOT_REACHED();
		case ByteCode::_iload:
			ASSERT_NOT_REACHED();
		case ByteCode::_iload_0:
			ASSERT_NOT_REACHED();
		case ByteCode::_iload_1:
		{
			m_op_stack.push(m_localVars[1]);
			break;
		}
			ASSERT_NOT_REACHED();
		case ByteCode::_iload_2:
			ASSERT_NOT_REACHED();
		case ByteCode::_iload_3:
			ASSERT_NOT_REACHED();
		case ByteCode::_impdep1:
			ASSERT_NOT_REACHED();
		case ByteCode::_impdep2:
			ASSERT_NOT_REACHED();
		case ByteCode::_imul:
			ASSERT_NOT_REACHED();
		case ByteCode::_ineg:
			ASSERT_NOT_REACHED();
		case ByteCode::_instanceof:
			ASSERT_NOT_REACHED();
		case ByteCode::_invokedynamic:
			ASSERT_NOT_REACHED();
		case ByteCode::_invokeinterface:
			ASSERT_NOT_REACHED();
		case ByteCode::_invokespecial:
			ASSERT_NOT_REACHED();
		case ByteCode::_invokestatic:
			ASSERT_NOT_REACHED();
		case ByteCode::_invokevirtual:
			ASSERT_NOT_REACHED();
		case ByteCode::_ior:
			ASSERT_NOT_REACHED();
		case ByteCode::_irem:
			ASSERT_NOT_REACHED();
		case ByteCode::_ireturn:
		{
			m_last_val = m_op_stack.pop();
			break;
		}
			ASSERT_NOT_REACHED();
		case ByteCode::_ishl:
			ASSERT_NOT_REACHED();
		case ByteCode::_ishr:
			ASSERT_NOT_REACHED();
		case ByteCode::_istore:
			ASSERT_NOT_REACHED();
		case ByteCode::_istore_0:
			ASSERT_NOT_REACHED();
		case ByteCode::_istore_1:
		{
			m_localVars[1] = m_op_stack.pop();
			break;
		}
			ASSERT_NOT_REACHED();
		case ByteCode::_istore_2:
			ASSERT_NOT_REACHED();
		case ByteCode::_istore_3:
			ASSERT_NOT_REACHED();
		case ByteCode::_isub:
			ASSERT_NOT_REACHED();
		case ByteCode::_iushr:
			ASSERT_NOT_REACHED();
		case ByteCode::_ixor:
			ASSERT_NOT_REACHED();
		case ByteCode::_jsr:
			ASSERT_NOT_REACHED();
		case ByteCode::_jsr_w:
			ASSERT_NOT_REACHED();
		case ByteCode::_l2d:
			ASSERT_NOT_REACHED();
		case ByteCode::_l2f:
			ASSERT_NOT_REACHED();
		case ByteCode::_l2i:
			ASSERT_NOT_REACHED();
		case ByteCode::_ladd:
			ASSERT_NOT_REACHED();
		case ByteCode::_laload:
			ASSERT_NOT_REACHED();
		case ByteCode::_land:
			ASSERT_NOT_REACHED();
		case ByteCode::_lastore:
			ASSERT_NOT_REACHED();
		case ByteCode::_lcmp:
			ASSERT_NOT_REACHED();
		case ByteCode::_lconst_0:
			ASSERT_NOT_REACHED();
		case ByteCode::_lconst_1:
			ASSERT_NOT_REACHED();
		case ByteCode::_ldc:
			ASSERT_NOT_REACHED();
		case ByteCode::_ldc_w:
			ASSERT_NOT_REACHED();
		case ByteCode::_ldc2_w:
			ASSERT_NOT_REACHED();
		case ByteCode::_ldiv:
			ASSERT_NOT_REACHED();
		case ByteCode::_lload:
			ASSERT_NOT_REACHED();
		case ByteCode::_lload_0:
			ASSERT_NOT_REACHED();
		case ByteCode::_lload_1:
			ASSERT_NOT_REACHED();
		case ByteCode::_lload_2:
			ASSERT_NOT_REACHED();
		case ByteCode::_lload_3:
			ASSERT_NOT_REACHED();
		case ByteCode::_lmul:
			ASSERT_NOT_REACHED();
		case ByteCode::_lneg:
			ASSERT_NOT_REACHED();
		case ByteCode::_lookupswitch:
			ASSERT_NOT_REACHED();
		case ByteCode::_lor:
			ASSERT_NOT_REACHED();
		case ByteCode::_lrem:
			ASSERT_NOT_REACHED();
		case ByteCode::_lreturn:
			ASSERT_NOT_REACHED();
		case ByteCode::_lshl:
			ASSERT_NOT_REACHED();
		case ByteCode::_lshr:
			ASSERT_NOT_REACHED();
		case ByteCode::_lstore:
			ASSERT_NOT_REACHED();
		case ByteCode::_lstore_0:
			ASSERT_NOT_REACHED();
		case ByteCode::_lstore_1:
			ASSERT_NOT_REACHED();
		case ByteCode::_lstore_2:
			ASSERT_NOT_REACHED();
		case ByteCode::_lstore_3:
			ASSERT_NOT_REACHED();
		case ByteCode::_lsub:
			ASSERT_NOT_REACHED();
		case ByteCode::_lushr:
			ASSERT_NOT_REACHED();
		case ByteCode::_lxor:
			ASSERT_NOT_REACHED();
		case ByteCode::_monitorenter:
			ASSERT_NOT_REACHED();
		case ByteCode::_monitorexit:
			ASSERT_NOT_REACHED();
		case ByteCode::_multianewarray:
			ASSERT_NOT_REACHED();
		case ByteCode::_new:
			ASSERT_NOT_REACHED();
		case ByteCode::_newarray:
			ASSERT_NOT_REACHED();
		case ByteCode::_nop:
			ASSERT_NOT_REACHED();
		case ByteCode::_pop:
			ASSERT_NOT_REACHED();
		case ByteCode::_pop2:
			ASSERT_NOT_REACHED();
		case ByteCode::_putfield:
			ASSERT_NOT_REACHED();
		case ByteCode::_putstatic:
			ASSERT_NOT_REACHED();
		case ByteCode::_ret:
			ASSERT_NOT_REACHED();
		case ByteCode::_return:
			ASSERT_NOT_REACHED();
		case ByteCode::_saload:
			ASSERT_NOT_REACHED();
		case ByteCode::_sastore:
			ASSERT_NOT_REACHED();
		case ByteCode::_sipush:
			ASSERT_NOT_REACHED();
		case ByteCode::_swap:
			ASSERT_NOT_REACHED();
		case ByteCode::_tableswitch:
			ASSERT_NOT_REACHED();
		case ByteCode::_wide:
			ASSERT_NOT_REACHED();
		default:
			ASSERT_NOT_REACHED();
		}

		return bytecode;
	}
}