#include <cpu.hpp>

namespace mboy {

CPU::CPU()
{
}

void CPU::cb() {  } // 0xCB

// LD R,n
void CPU::ld_b_n() { B = read_pc(); } // 0x06
void CPU::ld_c_n() { C = read_pc(); } // 0x0E
void CPU::ld_d_n() { D = read_pc(); } // 0x16
void CPU::ld_e_n() { E = read_pc(); } // 0x1E
void CPU::ld_h_n() { H = read_pc(); } // 0x26
void CPU::ld_l_n() { L = read_pc(); } // 0x2E


// LD R,R
void CPU::ld_a_a() { A = A; } // 0x7F
void CPU::ld_b_a() { B = A; } // 0x47
void CPU::ld_c_a() { C = A; } // 0x4F
void CPU::ld_d_a() { D = A; } // 0x57
void CPU::ld_e_a() { E = A; } // 0x5F
void CPU::ld_h_a() { H = A; } // 0x67
void CPU::ld_l_a() { L = A; } // 0x6F

void CPU::ld_a_b() { A = B; } // 0x78
void CPU::ld_a_c() { A = C; } // 0x79
void CPU::ld_a_d() { A = D; } // 0x7A
void CPU::ld_a_e() { A = E; } // 0x7B
void CPU::ld_a_h() { A = H; } // 0x7C
void CPU::ld_a_l() { A = L; } // 0x7D

void CPU::ld_b_b() { B = B; } // 0x40
void CPU::ld_b_c() { B = C; } // 0x41
void CPU::ld_b_d() { B = D; } // 0x42
void CPU::ld_b_e() { B = E; } // 0x43
void CPU::ld_b_h() { B = H; } // 0x44
void CPU::ld_b_l() { B = L; } // 0x45

void CPU::ld_c_b() { C = B; } // 0x48
void CPU::ld_c_c() { C = C; } // 0x49
void CPU::ld_c_d() { C = D; } // 0x4A
void CPU::ld_c_e() { C = E; } // 0x4B
void CPU::ld_c_h() { C = H; } // 0x4C
void CPU::ld_c_l() { C = L; } // 0x4D

void CPU::ld_d_b() { D = B; } // 0x50
void CPU::ld_d_c() { D = C; } // 0x51
void CPU::ld_d_d() { D = D; } // 0x52
void CPU::ld_d_e() { D = E; } // 0x53
void CPU::ld_d_h() { D = H; } // 0x54
void CPU::ld_d_l() { D = L; } // 0x55

void CPU::ld_e_b() { E = B; } // 0x58
void CPU::ld_e_c() { E = C; } // 0x59
void CPU::ld_e_d() { E = D; } // 0x5A
void CPU::ld_e_e() { E = E; } // 0x5B
void CPU::ld_e_h() { E = H; } // 0x5C
void CPU::ld_e_l() { E = L; } // 0x5D

void CPU::ld_h_b() { H = B; } // 0x60
void CPU::ld_h_c() { H = C; } // 0x61
void CPU::ld_h_d() { H = D; } // 0x62
void CPU::ld_h_e() { H = E; } // 0x63
void CPU::ld_h_h() { H = H; } // 0x64
void CPU::ld_h_l() { H = L; } // 0x65

void CPU::ld_l_b() { L = B; } // 0x68
void CPU::ld_l_c() { L = C; } // 0x69
void CPU::ld_l_d() { L = D; } // 0x6A
void CPU::ld_l_e() { L = E; } // 0x6B
void CPU::ld_l_h() { L = H; } // 0x6C
void CPU::ld_l_l() { L = L; } // 0x6D

// LD R,(RR)ß
void CPU::ld_a_hl() { A = read(HL); } // 0x7E
void CPU::ld_b_hl() { B = read(HL); } // 0x46
void CPU::ld_c_hl() { C = read(HL); } // 0x4E
void CPU::ld_d_hl() { D = read(HL); } // 0x56
void CPU::ld_e_hl() { E = read(HL); } // 0x5E
void CPU::ld_h_hl() { H = read(HL); } // 0x66
void CPU::ld_l_hl() { L = read(HL); } // 0x6E

// LD (RR),R
void CPU::ld_hl_a() { write(HL, A); } // 0x77
void CPU::ld_hl_b() { write(HL, B); } // 0x70
void CPU::ld_hl_c() { write(HL, C); } // 0x71
void CPU::ld_hl_d() { write(HL, D); } // 0x72
void CPU::ld_hl_e() { write(HL, E); } // 0x73
void CPU::ld_hl_h() { write(HL, H); } // 0x74
void CPU::ld_hl_l() { write(HL, L); } // 0x75
void CPU::ld_hl_n() { write(HL, read_pc()); } // 0x36

// LD R,(RR)
void CPU::ld_a_bc() { A = read(BC); }		// 0x0A
void CPU::ld_a_de() { A = read(DE); }		// 0x1A
void CPU::ld_a_nn() { A = read(read16_pc()); }	// 0xFA
void CPU::ld_a_n()  { A = read_pc(); }		// 0x3E

void CPU::ld_bc_a() { write(BC, A); }		// 0x02
void CPU::ld_de_a() { write(DE, A); }		// 0x12
void CPU::ld_nn_a() { write(read16_pc(), A); }	// 0xEA
void CPU::ldh_c_a() { write(0xFF00 + C, A); }	// 0xE2
void CPU::ldh_a_c() { A = read(0xFF00 + C); }	// 0xF2

void CPU::ld_a_hld() { A = read(HL); HL--; } // 0x3A
void CPU::ld_hld_a() { write(HL, A); HL--; } // 0x32
void CPU::ld_a_hli() { A = read(HL); H++; }  // 0x2A
void CPU::ld_hli_a() { write(HL, A); HL++; } // 0x22

void CPU::ldh_n_a(){ write(0xFF00 + read_pc(), A); } // 0xE0
void CPU::ldh_a_n(){ A = read(0xFF00 + read_pc()); } // 0xF0

/**************************************
 * Section 3.3.2, p. 76: 16-Bit Loads *
 **************************************/

// LD RR,nn
void CPU::ld_bc_nn()  {  BC = read16_pc(); } // 0x01
void CPU::ld_de_nn()  {  DE = read16_pc(); } // 0x11
void CPU::ld_hl_nn()  {  HL = read16_pc(); } // 0x21
void CPU::ld_sp_nn()  {  SP = read16_pc(); } // 0x31
void CPU::ld_sp_hl() { SP = HL; } // 0xF9


/* Surprisingly, this one Load-Command affects the flag register
    while all other load-command don't care for the flags */
void CPU::ldhl_sp_n() // 0xF8
{
	u8 n = read_pc();
	u32 result = SP + n;
	flags.z = false;
	flags.n = false;
	flags.c = 0x100 == ((SP ^ n ^ result) & 0x100);
	flags.h = 0x10 == ((SP ^ n ^ result) & 0x10);
	HL = result;
}

void CPU::ld_nn_sp() { write16(read16_pc(), SP); } // 0x08

void CPU::push_af() { push16(AF); } // 0xF5
void CPU::push_bc() { push16(BC); } // 0xC5
void CPU::push_de() { push16(DE); } // 0xD5
void CPU::push_hl() { push16(HL); } // 0xE5

void CPU::pop_af() { AF = pop16(); } // 0xF1
void CPU::pop_bc() { BC = pop16(); } // 0xC1
void CPU::pop_de() { DE = pop16(); } // 0xD1
void CPU::pop_hl() { HL = pop16(); } // 0xE1

/***********************************
 * Section 3.3.3, p. 80: 8-Bit ALU *
 ***********************************/

// ADD A,n
void CPU::add_a_a() { A = add8bit(A, A); } // 0x87
void CPU::add_a_b() { A = add8bit(A, B); } // 0x80
void CPU::add_a_c() { A = add8bit(A, C); } // 0x81
void CPU::add_a_d() { A = add8bit(A, D); } // 0x82
void CPU::add_a_e() { A = add8bit(A, E); } // 0x83
void CPU::add_a_h() { A = add8bit(A, H); } // 0x84
void CPU::add_a_l() { A = add8bit(A, L); } // 0x85
void CPU::add_a_hl_ref() { A = add8bit(A, read(HL)); } // 0x86
void CPU::add_a_n() { A = add8bit(A, read_pc()); } // 0xC6

// ADC A,n
void CPU::adc_a_a() { A = adc8bit(A, A); } // 0x8F
void CPU::adc_a_b() { A = adc8bit(A, B); } // 0x88
void CPU::adc_a_c() { A = adc8bit(A, C); } // 0x89
void CPU::adc_a_d() { A = adc8bit(A, D); } // 0x8A
void CPU::adc_a_e() { A = adc8bit(A, E); } // 0x8B
void CPU::adc_a_h() { A = adc8bit(A, H); } // 0x8C
void CPU::adc_a_l() { A = add8bit(A, L); } // 0x8D
void CPU::adc_a_hl_ref() { A = adc8bit(A, read(HL)); } // 0x8E
void CPU::adc_a_n() { A = adc8bit(A, read_pc()); } // 0xCE

// SUB A, n
void CPU::sub_a_a()  { A = sub8bit(A, A); } // 0x97
void CPU::sub_a_b()  { A = sub8bit(A, B); } // 0x90
void CPU::sub_a_c()  { A = sub8bit(A, C); } // 0x91
void CPU::sub_a_d()  { A = sub8bit(A, D); } // 0x92
void CPU::sub_a_e()  { A = sub8bit(A, E); } // 0x93
void CPU::sub_a_h()  { A = sub8bit(A, H); } // 0x94
void CPU::sub_a_l()  { A = sub8bit(A, L); } // 0x95
void CPU::sub_a_hl_ref() { A = sub8bit(A, read(HL)); } // 0x96
void CPU::sub_a_n()  { A = sub8bit(A, read_pc()); } // 0xD6

// SBC A, n
void CPU::sbc_a_a()  { A = sbc8bit(A, A); } // 0x9F
void CPU::sbc_a_b()  { A = sbc8bit(A, B); } // 0x98
void CPU::sbc_a_c()  { A = sbc8bit(A, C); } // 0x99
void CPU::sbc_a_d()  { A = sbc8bit(A, D); } // 0x9A
void CPU::sbc_a_e()  { A = sbc8bit(A, E); } // 0x9B
void CPU::sbc_a_h()  { A = sbc8bit(A, H); } // 0x9C
void CPU::sbc_a_l()  { A = sbc8bit(A, L); } // 0x9D
void CPU::sbc_a_hl_ref() { A = sbc8bit(A, read(HL)); } // 0x9E
void CPU::sbc_a_n()  { A = sbc8bit(A, read_pc()); } // 0xDE

// AND A, n
void CPU::and_a_a()  { A = and8bit(A, A); } // 0xA7
void CPU::and_a_b()  { A = and8bit(A, B); } // 0xA0
void CPU::and_a_c()  { A = and8bit(A, C); } // 0xA1
void CPU::and_a_d()  { A = and8bit(A, D); } // 0xA2
void CPU::and_a_e()  { A = and8bit(A, E); } // 0xA3
void CPU::and_a_h()  { A = and8bit(A, H); } // 0xA4
void CPU::and_a_l()  { A = and8bit(A, L); } // 0xA5
void CPU::and_a_hl_ref() { A = and8bit(A, read(HL)); } // 0xA6
void CPU::and_a_n()  { A = and8bit(A, read_pc()); } // 0xE6

// OR A, n
void CPU::or_a_a()  { A = or8bit(A, A); } // 0xB7
void CPU::or_a_b()  { A = or8bit(A, B); } // 0xB0
void CPU::or_a_c()  { A = or8bit(A, C); } // 0xB1
void CPU::or_a_d()  { A = or8bit(A, D); } // 0xB2
void CPU::or_a_e()  { A = or8bit(A, E); } // 0xB3
void CPU::or_a_h()  { A = or8bit(A, H); } // 0xB4
void CPU::or_a_l()  { A = or8bit(A, L); } // 0xB5
void CPU::or_a_hl_ref() { A = or8bit(A, read(HL)); } // 0xB6
void CPU::or_a_n()  { A = or8bit(A, read_pc()); } // 0xF6

// XOR A, n
void CPU::xor_a_a()  { A = xor8bit(A, A); } // 0xAF
void CPU::xor_a_b()  { A = xor8bit(A, B); } // 0xA8
void CPU::xor_a_c()  { A = xor8bit(A, C); } // 0xA9
void CPU::xor_a_d()  { A = xor8bit(A, D); } // 0xAA
void CPU::xor_a_e()  { A = xor8bit(A, E); } // 0xAB
void CPU::xor_a_h()  { A = xor8bit(A, H); } // 0xAC
void CPU::xor_a_l()  { A = xor8bit(A, L); } // 0xAD
void CPU::xor_a_hl_ref() { A = xor8bit(A, read(HL)); } // 0xAE
void CPU::xor_a_n()  { A = xor8bit(A, read_pc()); } // 0xEE

// CP A,n
/* Description of CP command on p. 87:
 * "This is basically an A - n  subtraction instruction but the results are thrown away."
 */
void CPU::cp_a_a()  { (void)sub8bit(A, A); } // 0xBF
void CPU::cp_a_b()  { (void)sub8bit(A, B); } // 0xB8
void CPU::cp_a_c()  { (void)sub8bit(A, C); } // 0xB9
void CPU::cp_a_d()  { (void)sub8bit(A, D); } // 0xBA
void CPU::cp_a_e()  { (void)sub8bit(A, E); } // 0xBB
void CPU::cp_a_h()  { (void)sub8bit(A, H); } // 0xBC
void CPU::cp_a_l()  { (void)sub8bit(A, L); } // 0xBD
void CPU::cp_a_hl_ref() { (void)sub8bit(A, read(HL)); } // 0xBE
void CPU::cp_a_n()  { (void)sub8bit(A, read_pc()); } // 0xFE

// INC R
void CPU::inc_a()  { inc(&A); } // 0x3C
void CPU::inc_b()  { inc(&B); } // 0x04
void CPU::inc_c()  { inc(&C); } // 0x0C
void CPU::inc_d()  { inc(&D); } // 0x14
void CPU::inc_e()  { inc(&E); } // 0x1C
void CPU::inc_h()  { inc(&H); } // 0x24
void CPU::inc_l()  { inc(&L); } // 0x2C
void CPU::inc_hl_ref() { u8 val = read(HL); inc(&val); write(HL, val); } // 0x34

// DEC R
void CPU::dec_a()  { dec(&A); } // 0x3D
void CPU::dec_b()  { dec(&B); } // 0x05
void CPU::dec_c()  { dec(&C); } // 0x0D
void CPU::dec_d()  { dec(&D); } // 0x15
void CPU::dec_e()  { dec(&E); } // 0x1D
void CPU::dec_h()  { dec(&H); } // 0x25
void CPU::dec_l()  { dec(&L); } // 0x2D
void CPU::dec_hl_ref() { u8 val = read(HL); dec(&val); write(HL, val); } // 0x35


/************************************
 * Section 3.3.4, p. 90: 16-Bit ALU *
 ************************************/

// ADD HL,RR
void CPU::add_hl_bc() { HL = add16bit(HL, BC); } // 0x09
void CPU::add_hl_de() { HL = add16bit(HL, DE); } // 0x19
void CPU::add_hl_hl() { HL = add16bit(HL, HL); } // 0x29
void CPU::add_hl_sp() { HL = add16bit(HL, SP); } // 0x39

// ADD SP,n
void CPU::add_sp_n() // 0xE8
{
	u8 n = read_pc();
	u32 result = SP + n;
	flags.z = false;
	flags.n = false;
	flags.c = 0x100 == ((SP ^ n ^ result) & 0x100);
	flags.h = 0x10 == ((SP ^ n ^ result) & 0x10);
	SP = result;
}

// INC RR
void CPU::inc_bc() { BC++; } // 0x03
void CPU::inc_de() { DE++; } // 0x13
void CPU::inc_hl() { HL++; } // 0x23
void CPU::inc_sp() { SP++; } // 0x33

// DEC RR
void CPU::dec_bc() { BC--; } // 0x0B
void CPU::dec_de() { DE--; } // 0x1B
void CPU::dec_hl() { HL--; } // 0x2B
void CPU::dec_sp() { SP--; } // 0x3B

/***************************************
 * Section 3.3.5, p. 94: Miscellaneous *
 ***************************************/

void CPU::swap_a() { A = swap(A); } // 0xCB 37
void CPU::swap_b() { B = swap(B); } // 0xCB 30
void CPU::swap_c() { C = swap(C); } // 0xCB 31
void CPU::swap_d() { D = swap(D); } // 0xCB 32
void CPU::swap_e() { E = swap(E); } // 0xCB 33
void CPU::swap_h() { H = swap(H); } // 0xCB 34
void CPU::swap_l() { L = swap(L); } // 0xCB 35
void CPU::swap_hl_ref() { u8 val = read(HL); A = swap(val); write(HL, val); } // 0xCB 36

void CPU::daa() // 0x27
{
	u16 correction = 0;
	if (flags.h || (!flags.n && ((A & 0x0F) > 0x09)))
		correction |= 0x06;
	if (flags.h || (!flags.n && ((A & 0xFF) > 0x99)))
		correction |= 0x60;

	A += flags.n ? -correction : +correction;

	flags.c = A > 0x99;
	flags.z = A == 0;
	flags.h = false;
}

void CPU::cpl() { A = ~A; } // 0x2F
void CPU::ccf() { flags.c = ! flags.c; } // 0x3F
void CPU::scf() { F |= 0b001'0000; } // 0x37
void CPU::nop() { } // 0x00
void CPU::halt() { halt_ = true; } // 0x76
void CPU::stop() { stop_ = true; } // 0x10
void CPU::di() { interruptable_ = false; } // 0xF3
void CPU::ei() { interruptable_ = true; } // 0xFB

/******************************************
 * Section 3.3.6, p. 99: Rotates & Shifts *
 ******************************************/

void CPU::rlca() // 0x07
{
	flags.c = (A & 0x80);
	A <<= 1;
	A |= flags.c;

	flags.z = A == 0;
	flags.n = false;
	flags.h = false;
}

void CPU::rla() // 0x17
{
	bool carry = (A & 0x80);
	A <<= 1;
	A |= flags.c;

	flags.c = carry;
	flags.z = A == 0;
	flags.n = false;
	flags.h = false;
}

void CPU::rrca() // 0x0F
{
	flags.c = A & 0x01;
	A >>= 1;
	A |= (flags.c << 7);

	flags.z = A == 0;
	flags.n = false;
	flags.h = false;
}

void CPU::rra() // 0x1F
{
	bool carry = (A & 0x01);
	A >>= 1;
	A |= (flags.c << 7);

	flags.c = carry;
	flags.z = A == 0;
	flags.n = false;
	flags.h = false;
}

// RLC n
void CPU::rlc_a() { A = rlc(A); } // 0xCB 07
void CPU::rlc_b() { B = rlc(B); } // 0xCB 00
void CPU::rlc_c() { C = rlc(C); } // 0xCB 01
void CPU::rlc_d() { D = rlc(D); } // 0xCB 02
void CPU::rlc_e() { E = rlc(E); } // 0xCB 03
void CPU::rlc_h() { H = rlc(H); } // 0xCB 04
void CPU::rlc_l() { L = rlc(L); } // 0xCB 05
void CPU::rlc_hl_ref() { u16 val = rlc(read(HL)); write(HL, val);  } // 0xCB 06

// RL n
void CPU::rl_a() { A = rl(A); } // 0xCB 17
void CPU::rl_b() { B = rl(B); } // 0xCB 10
void CPU::rl_c() { C = rl(C); } // 0xCB 11
void CPU::rl_d() { D = rl(D); } // 0xCB 12
void CPU::rl_e() { E = rl(E); } // 0xCB 13
void CPU::rl_h() { H = rl(H); } // 0xCB 14
void CPU::rl_l() { L = rl(L); } // 0xCB 15
void CPU::rl_hl_ref() { u16 val = rl(read(HL)); write(HL, val);  } // 0xCB 16

// RRC n
void CPU::rrc_a() { A = rrc(A); } // 0xCB 0F
void CPU::rrc_b() { B = rrc(B); } // 0xCB 08
void CPU::rrc_c() { C = rrc(C); } // 0xCB 09
void CPU::rrc_d() { D = rrc(D); } // 0xCB 0A
void CPU::rrc_e() { E = rrc(E); } // 0xCB 0B
void CPU::rrc_h() { H = rrc(H); } // 0xCB 0C
void CPU::rrc_l() { L = rrc(L); } // 0xCB 0D
void CPU::rrc_hl_ref() { u16 val = rrc(read(HL)); write(HL, val);  } // 0xCB 0E

// RR n
void CPU::rr_a() { A = rr(A); } // 0xCB 1F
void CPU::rr_b() { B = rr(B); } // 0xCB 18
void CPU::rr_c() { C = rr(C); } // 0xCB 19
void CPU::rr_d() { D = rr(D); } // 0xCB 1A
void CPU::rr_e() { E = rr(E); } // 0xCB 1B
void CPU::rr_h() { H = rr(H); } // 0xCB 1C
void CPU::rr_l() { L = rr(L); } // 0xCB 1D
void CPU::rr_hl_ref() { u16 val = rr(read(HL)); write(HL, val);  } // 0xCB 1E

// SLA n
void CPU::sla_a() { A = sla(A); } // 0xCB 27
void CPU::sla_b() { B = sla(B); } // 0xCB 20
void CPU::sla_c() { C = sla(C); } // 0xCB 21
void CPU::sla_d() { D = sla(D); } // 0xCB 22
void CPU::sla_e() { E = sla(E); } // 0xCB 23
void CPU::sla_h() { H = sla(H); } // 0xCB 24
void CPU::sla_l() { L = sla(L); } // 0xCB 25
void CPU::sla_hl_ref() { u8 val = sla(read(HL)); write(HL, val); } // 0xCB 26

// SRA n
void CPU::sra_a() { A = sra(A); } // 0xCB 2F
void CPU::sra_b() { B = sra(B); } // 0xCB 28
void CPU::sra_c() { C = sra(C); } // 0xCB 29
void CPU::sra_d() { D = sra(D); } // 0xCB 2A
void CPU::sra_e() { E = sra(E); } // 0xCB 2B
void CPU::sra_h() { H = sra(H); } // 0xCB 2C
void CPU::sra_l() { L = sra(L); } // 0xCB 2D
void CPU::sra_hl_ref() { u8 val = sra(read(HL)); write(HL, val); } // 0xCB 2E

// SRL n
void CPU::srl_a() { A = srl(A); } // 0xCB 3F
void CPU::srl_b() { B = srl(B); } // 0xCB 38
void CPU::srl_c() { C = srl(C); } // 0xCB 39
void CPU::srl_d() { D = srl(D); } // 0xCB 3A
void CPU::srl_e() { E = srl(E); } // 0xCB 3B
void CPU::srl_h() { H = srl(H); } // 0xCB 3C
void CPU::srl_l() { L = srl(L); } // 0xCB 3D
void CPU::srl_hl_ref() { u8 val = srl(read(HL)); write(HL, val); } // 0xCB 3E

/**************************************
 * Section 3.3.7, p. 108: Bit Opcodes *
 **************************************/

// BIT (test bit)
void CPU::bit_a_0() { bit(0, A); } // 0xCB 47
void CPU::bit_b_0() { bit(0, B); } // 0xCB 40
void CPU::bit_c_0() { bit(0, C); } // 0xCB 41
void CPU::bit_d_0() { bit(0, D); } // 0xCB 42
void CPU::bit_e_0() { bit(0, E); } // 0xCB 43
void CPU::bit_h_0() { bit(0, H); } // 0xCB 44
void CPU::bit_l_0() { bit(0, L); } // 0xCB 45
void CPU::bit_hl_ref_0() { bit(0, read(HL)); } // 0xCB 46

void CPU::bit_a_1() { bit(1, A); } // 0xCB 4F
void CPU::bit_b_1() { bit(1, B); } // 0xCB 48
void CPU::bit_c_1() { bit(1, C); } // 0xCB 49
void CPU::bit_d_1() { bit(1, D); } // 0xCB 4A
void CPU::bit_e_1() { bit(1, E); } // 0xCB 4B
void CPU::bit_h_1() { bit(1, H); } // 0xCB 4C
void CPU::bit_l_1() { bit(1, L); } // 0xCB 4D
void CPU::bit_hl_ref_1() { bit(1, read(HL)); } // 0xCB 4E

void CPU::bit_a_2() { bit(2, A); } // 0xCB 57
void CPU::bit_b_2() { bit(2, B); } // 0xCB 50
void CPU::bit_c_2() { bit(2, C); } // 0xCB 51
void CPU::bit_d_2() { bit(2, D); } // 0xCB 52
void CPU::bit_e_2() { bit(2, E); } // 0xCB 53
void CPU::bit_h_2() { bit(2, H); } // 0xCB 54
void CPU::bit_l_2() { bit(2, L); } // 0xCB 55
void CPU::bit_hl_ref_2() { bit(2, read(HL)); } // 0xCB 56

void CPU::bit_a_3() { bit(3, A); } // 0xCB 5F
void CPU::bit_b_3() { bit(3, B); } // 0xCB 58
void CPU::bit_c_3() { bit(3, C); } // 0xCB 59
void CPU::bit_d_3() { bit(3, D); } // 0xCB 5A
void CPU::bit_e_3() { bit(3, E); } // 0xCB 5B
void CPU::bit_h_3() { bit(3, H); } // 0xCB 5C
void CPU::bit_l_3() { bit(3, L); } // 0xCB 5D
void CPU::bit_hl_ref_3() { bit(3, read(HL)); } // 0xCB 5E

void CPU::bit_a_4() { bit(4, A); } // 0xCB 67
void CPU::bit_b_4() { bit(4, B); } // 0xCB 60
void CPU::bit_c_4() { bit(4, C); } // 0xCB 61
void CPU::bit_d_4() { bit(4, D); } // 0xCB 62
void CPU::bit_e_4() { bit(4, E); } // 0xCB 63
void CPU::bit_h_4() { bit(4, H); } // 0xCB 64
void CPU::bit_l_4() { bit(4, L); } // 0xCB 65
void CPU::bit_hl_ref_4() { bit(4, read(HL)); } // 0xCB 66

void CPU::bit_a_5() { bit(5, A); } // 0xCB 6F
void CPU::bit_b_5() { bit(5, B); } // 0xCB 68
void CPU::bit_c_5() { bit(5, C); } // 0xCB 69
void CPU::bit_d_5() { bit(5, D); } // 0xCB 6A
void CPU::bit_e_5() { bit(5, E); } // 0xCB 6B
void CPU::bit_h_5() { bit(5, H); } // 0xCB 6C
void CPU::bit_l_5() { bit(5, L); } // 0xCB 6D
void CPU::bit_hl_ref_5() { bit(5, read(HL)); } // 0xCB 6E

void CPU::bit_a_6() { bit(6, A); } // 0xCB 77
void CPU::bit_b_6() { bit(6, B); } // 0xCB 70
void CPU::bit_c_6() { bit(6, C); } // 0xCB 71
void CPU::bit_d_6() { bit(6, D); } // 0xCB 72
void CPU::bit_e_6() { bit(6, E); } // 0xCB 73
void CPU::bit_h_6() { bit(6, H); } // 0xCB 74
void CPU::bit_l_6() { bit(6, L); } // 0xCB 75
void CPU::bit_hl_ref_6() { bit(6, read(HL)); } // 0xCB 76

void CPU::bit_a_7() { bit(7, A); } // 0xCB 7F
void CPU::bit_b_7() { bit(7, B); } // 0xCB 78
void CPU::bit_c_7() { bit(7, C); } // 0xCB 79
void CPU::bit_d_7() { bit(7, D); } // 0xCB 7A
void CPU::bit_e_7() { bit(7, E); } // 0xCB 7B
void CPU::bit_h_7() { bit(7, H); } // 0xCB 7C
void CPU::bit_l_7() { bit(7, L); } // 0xCB 7D
void CPU::bit_hl_ref_7() { bit(7, read(HL)); } // 0xCB 7E

// RES (reset bit)
void CPU::res_a_0() { A = res(0, A); } // 0xCB 87
void CPU::res_b_0() { B = res(0, B); } // 0xCB 80
void CPU::res_c_0() { C = res(0, C); } // 0xCB 81
void CPU::res_d_0() { D = res(0, D); } // 0xCB 82
void CPU::res_e_0() { E = res(0, E); } // 0xCB 83
void CPU::res_h_0() { H = res(0, H); } // 0xCB 84
void CPU::res_l_0() { L = res(0, L); } // 0xCB 85
void CPU::res_hl_ref_0() { u8 val = res(0, read(HL)); write(HL, val); } // 0xCB 86

void CPU::res_a_1() { A = res(1, A); } // 0xCB 8F
void CPU::res_b_1() { B = res(1, B); } // 0xCB 88
void CPU::res_c_1() { C = res(1, C); } // 0xCB 89
void CPU::res_d_1() { D = res(1, D); } // 0xCB 8A
void CPU::res_e_1() { E = res(1, E); } // 0xCB 8B
void CPU::res_h_1() { H = res(1, H); } // 0xCB 8C
void CPU::res_l_1() { L = res(1, L); } // 0xCB 8D
void CPU::res_hl_ref_1() { u8 val = res(1, read(HL)); write(HL, val); } // 0xCB 8E

void CPU::res_a_2() { A = res(2, A); } // 0xCB 97
void CPU::res_b_2() { B = res(2, B); } // 0xCB 90
void CPU::res_c_2() { C = res(2, C); } // 0xCB 91
void CPU::res_d_2() { D = res(2, D); } // 0xCB 92
void CPU::res_e_2() { E = res(2, E); } // 0xCB 93
void CPU::res_h_2() { H = res(2, H); } // 0xCB 94
void CPU::res_l_2() { L = res(3, L); } // 0xCB 95
void CPU::res_hl_ref_2() { u8 val = res(2, read(HL)); write(HL, val); } // 0xCB 96

void CPU::res_a_3() { A = res(3, A); } // 0xCB 9F
void CPU::res_b_3() { B = res(3, B); } // 0xCB 98
void CPU::res_c_3() { C = res(3, C); } // 0xCB 99
void CPU::res_d_3() { D = res(3, D); } // 0xCB 9A
void CPU::res_e_3() { E = res(3, E); } // 0xCB 9B
void CPU::res_h_3() { H = res(3, H); } // 0xCB 9C
void CPU::res_l_3() { L = res(3, L); } // 0xCB 9D
void CPU::res_hl_ref_3() { u8 val = res(3, read(HL)); write(HL, val); } // 0xCB 9E

void CPU::res_a_4() { A = res(4, A); } // 0xCB A7
void CPU::res_b_4() { B = res(4, B); } // 0xCB A0
void CPU::res_c_4() { C = res(4, C); } // 0xCB A1
void CPU::res_d_4() { D = res(4, D); } // 0xCB A2
void CPU::res_e_4() { E = res(4, E); } // 0xCB A3
void CPU::res_h_4() { H = res(4, H); } // 0xCB A4
void CPU::res_l_4() { L = res(4, L); } // 0xCB A5
void CPU::res_hl_ref_4() { u8 val = res(4, read(HL)); write(HL, val); } // 0xCB A6

void CPU::res_a_5() { A = res(5, A); } // 0xCB AF
void CPU::res_b_5() { B = res(5, B); } // 0xCB A8
void CPU::res_c_5() { C = res(5, C); } // 0xCB A9
void CPU::res_d_5() { D = res(5, D); } // 0xCB AA
void CPU::res_e_5() { E = res(5, E); } // 0xCB AB
void CPU::res_h_5() { H = res(5, H); } // 0xCB AC
void CPU::res_l_5() { L = res(5, L); } // 0xCB AD
void CPU::res_hl_ref_5() { u8 val = res(5, read(HL)); write(HL, val); } // 0xCB AE

void CPU::res_a_6() { A = res(6, A); } // 0xCB B7
void CPU::res_b_6() { B = res(6, B); } // 0xCB B0
void CPU::res_c_6() { C = res(6, C); } // 0xCB B1
void CPU::res_d_6() { D = res(6, D); } // 0xCB B2
void CPU::res_e_6() { E = res(6, E); } // 0xCB B3
void CPU::res_h_6() { H = res(6, H); } // 0xCB B4
void CPU::res_l_6() { L = res(6, L); } // 0xCB B5
void CPU::res_hl_ref_6() { u8 val = res(6, read(HL));  write(HL, val);} // 0xCB B6

void CPU::res_a_7() { A = res(7, A); } // 0xCB BF
void CPU::res_b_7() { B = res(7, B); } // 0xCB B8
void CPU::res_c_7() { C = res(7, C); } // 0xCB B9
void CPU::res_d_7() { D = res(7, D); } // 0xCB BA
void CPU::res_e_7() { E = res(7, E); } // 0xCB BB
void CPU::res_h_7() { H = res(7, H); } // 0xCB BC
void CPU::res_l_7() { L = res(8, L); } // 0xCB BD
void CPU::res_hl_ref_7() { u8 val = res(7, read(HL)); write(HL, val); } // 0xCB BE

// SET (set bit)
void CPU::set_a_0() { A = set(0, A); } // 0xCB C7
void CPU::set_b_0() { B = set(0, B); } // 0xCB C0
void CPU::set_c_0() { C = set(0, C); } // 0xCB C1
void CPU::set_d_0() { D = set(0, D); } // 0xCB C2
void CPU::set_e_0() { E = set(0, E); } // 0xCB C3
void CPU::set_h_0() { H = set(0, H); } // 0xCB C4
void CPU::set_l_0() { L = set(0, L); } // 0xCB C5
void CPU::set_hl_ref_0() { u8 val = set(0, read(HL)); write(HL, val); } // 0xCB C6

void CPU::set_a_1() { A = set(1, A); } // 0xCB CF
void CPU::set_b_1() { B = set(1, B); } // 0xCB C8
void CPU::set_c_1() { C = set(1, C); } // 0xCB C9
void CPU::set_d_1() { D = set(1, D); } // 0xCB CA
void CPU::set_e_1() { E = set(1, E); } // 0xCB CB
void CPU::set_h_1() { H = set(1, H); } // 0xCB CC
void CPU::set_l_1() { L = set(1, L); } // 0xCB CD
void CPU::set_hl_ref_1() { u8 val = set(1, read(HL)); write(HL, val); } // 0xCB CE

void CPU::set_a_2() { A = set(2, A); } // 0xCB D7
void CPU::set_b_2() { B = set(2, B); } // 0xCB D0
void CPU::set_c_2() { C = set(2, C); } // 0xCB D1
void CPU::set_d_2() { D = set(2, D); } // 0xCB D2
void CPU::set_e_2() { E = set(2, E); } // 0xCB D3
void CPU::set_h_2() { H = set(2, H); } // 0xCB D4
void CPU::set_l_2() { L = set(2, L); } // 0xCB D5
void CPU::set_hl_ref_2() { u8 val = set(2, read(HL)); write(HL, val); } // 0xCB D6

void CPU::set_a_3() { A = set(3, A); } // 0xCB DF
void CPU::set_b_3() { B = set(3, B); } // 0xCB D8
void CPU::set_c_3() { C = set(3, C); } // 0xCB D9
void CPU::set_d_3() { D = set(3, D); } // 0xCB DA
void CPU::set_e_3() { E = set(3, E); } // 0xCB DB
void CPU::set_h_3() { H = set(3, H); } // 0xCB DC
void CPU::set_l_3() { L = set(4, L); } // 0xCB DD
void CPU::set_hl_ref_3() { u8 val = set(3, read(HL)); write(HL, val); } // 0xCB DE

void CPU::set_a_4() { A = set(4, A); } // 0xCB E7
void CPU::set_b_4() { B = set(4, B); } // 0xCB E0
void CPU::set_c_4() { C = set(4, C); } // 0xCB E1
void CPU::set_d_4() { D = set(4, D); } // 0xCB E2
void CPU::set_e_4() { E = set(4, E); } // 0xCB E3
void CPU::set_h_4() { H = set(4, H); } // 0xCB E4
void CPU::set_l_4() { L = set(4, L); } // 0xCB E5
void CPU::set_hl_ref_4() { u8 val = set(4, read(HL)); write(HL, val); } // 0xCB E6

void CPU::set_a_5() { A = set(5, A); } // 0xCB EF
void CPU::set_b_5() { B = set(5, B); } // 0xCB E8
void CPU::set_c_5() { C = set(5, C); } // 0xCB E9
void CPU::set_d_5() { D = set(5, D); } // 0xCB EA
void CPU::set_e_5() { E = set(5, E); } // 0xCB EB
void CPU::set_h_5() { H = set(5, H); } // 0xCB EC
void CPU::set_l_5() { L = set(5, L); } // 0xCB ED
void CPU::set_hl_ref_5() { u8 val = set(5, read(HL)); write(HL, val); } // 0xCB EE

void CPU::set_a_6() { A = set(6, A); } // 0xCB F7
void CPU::set_b_6() { B = set(6, B); } // 0xCB F0
void CPU::set_c_6() { C = set(6, C); } // 0xCB F1
void CPU::set_d_6() { D = set(6, D); } // 0xCB F2
void CPU::set_e_6() { E = set(6, E); } // 0xCB F3
void CPU::set_h_6() { H = set(6, H); } // 0xCB F4
void CPU::set_l_6() { L = set(6, L); } // 0xCB F5
void CPU::set_hl_ref_6() { u8 val = set(6, read(HL)); write(HL, val); } // 0xCB F6

void CPU::set_a_7() { A = set(7, A); } // 0xCB FF
void CPU::set_b_7() { B = set(7, B); } // 0xCB F8
void CPU::set_c_7() { C = set(7, C); } // 0xCB F9
void CPU::set_d_7() { D = set(7, D); } // 0xCB FA
void CPU::set_e_7() { E = set(7, E); } // 0xCB FB
void CPU::set_h_7() { H = set(7, H); } // 0xCB FC
void CPU::set_l_7() { L = set(7, L); } // 0xCB FD
void CPU::set_hl_ref_7() { u8 val = set(7, read(HL)); write(HL, val); } // 0xCB FE

/********************************
 * Section 3.3.8, p. 108: Jumps *
 ********************************/

void CPU::jp_nn() { PC = read16_pc(); } // 0xC3

// JP cc,nn
void CPU::jp_nz_nn() { if(!flags.z) jp_nn(); else { PC+=2; } } // 0xC2
void CPU::jp_z_nn() { if(flags.z) jp_nn();else PC+=2;}   // 0xCA
void CPU::jp_nc_nn() { if(!flags.c) jp_nn();else PC+=2;} // 0xD2
void CPU::jp_c_nn() { if(flags.c) jp_nn(); else PC+=2;}   // 0xDA

void CPU::jp_hl() { PC = HL; } // 0xE9

void CPU::jr_n() { PC += (i8)read_pc(); } // 0x18 // TODO: PC gets incremented here because of reading. Maybe decrement is needed

// JR CC,n
void CPU::jr_nz_n() {  if(!flags.z) jr_n();else PC+=1;} // 0x20
void CPU::jr_z_n() {  if(flags.z) jr_n() ;else PC+=1;}   // 0x28
void CPU::jr_nc_n() {  if(!flags.c) jr_n();else PC+=1;} // 0x30
void CPU::jr_c_n() {  if(flags.c) jr_n();else PC+=1;}   // 0x38

/********************************
 * Section 3.3.9, p. 108: Calls *
 ********************************/

void CPU::call_nn() { push16(PC + 2); jp_nn(); } // 0xCD

// CALL cc,nn
void CPU::call_nz_nn() { if(!flags.z) call_nn();  } // 0xC4
void CPU::call_z_nn() { if(flags.z) call_nn();  }   // 0xCC
void CPU::call_nc_nn() { if(!flags.c) call_nn();  } // 0xD4
void CPU::call_c_nn() { if(flags.c) call_nn();  }   // 0xDC

/************************************
 * Section 3.3.10, p. 108: Restarts *
 ************************************/

// RST, n
void CPU::rst_00() { push(PC); PC = 0x00; } // 0xC7
void CPU::rst_08() { push(PC); PC = 0x08; } // 0xCF
void CPU::rst_10() { push(PC); PC = 0x10; } // 0xD7
void CPU::rst_18() { push(PC); PC = 0x18; } // 0xDF
void CPU::rst_20() { push(PC); PC = 0x20; } // 0xE7
void CPU::rst_28() { push(PC); PC = 0x28; } // 0xEF
void CPU::rst_30() { push(PC); PC = 0x30; } // 0xF7
void CPU::rst_38() { push(PC); PC = 0x38; } // 0xFF

/************************************
 * Section 3.3.11, p. 108: Returns  *
 ************************************/

void CPU::ret() { PC = pop16(); } // 0xC9

void CPU::ret_nz() { if(!flags.z) ret(); } // 0xC0
void CPU::ret_z() { if(flags.z) ret(); }   // 0xC8
void CPU::ret_nc() { if(!flags.c) ret(); } // 0xD0
void CPU::ret_c() { if(flags.c) ret(); }   // 0xD8

void CPU::reti() { ret(); interruptable_ = true; } // 0xD9

void CPU::init_opcodes()
{
	opcodes[0x3E] = &CPU::ld_a_n;
	opcodes[0x06] = &CPU::ld_b_n;
	opcodes[0x0E] = &CPU::ld_c_n;
	opcodes[0x16] = &CPU::ld_d_n;
	opcodes[0x1E] = &CPU::ld_e_n;
	opcodes[0x26] = &CPU::ld_h_n;
	opcodes[0x2E] = &CPU::ld_l_n;
	opcodes[0x7F] = &CPU::ld_a_a;
	opcodes[0x47] = &CPU::ld_b_a;
	opcodes[0x4F] = &CPU::ld_c_a;
	opcodes[0x57] = &CPU::ld_d_a;
	opcodes[0x5F] = &CPU::ld_e_a;
	opcodes[0x67] = &CPU::ld_h_a;
	opcodes[0x6F] = &CPU::ld_l_a;
	opcodes[0x78] = &CPU::ld_a_b;
	opcodes[0x79] = &CPU::ld_a_c;
	opcodes[0x7A] = &CPU::ld_a_d;
	opcodes[0x7B] = &CPU::ld_a_e;
	opcodes[0x7C] = &CPU::ld_a_h;
	opcodes[0x7D] = &CPU::ld_a_l;
	opcodes[0x40] = &CPU::ld_b_b;
	opcodes[0x41] = &CPU::ld_b_c;
	opcodes[0x42] = &CPU::ld_b_d;
	opcodes[0x43] = &CPU::ld_b_e;
	opcodes[0x44] = &CPU::ld_b_h;
	opcodes[0x45] = &CPU::ld_b_l;
	opcodes[0x48] = &CPU::ld_c_b;
	opcodes[0x49] = &CPU::ld_c_c;
	opcodes[0x4A] = &CPU::ld_c_d;
	opcodes[0x4B] = &CPU::ld_c_e;
	opcodes[0x4C] = &CPU::ld_c_h;
	opcodes[0x4D] = &CPU::ld_c_l;
	opcodes[0x50] = &CPU::ld_d_b;
	opcodes[0x51] = &CPU::ld_d_c;
	opcodes[0x52] = &CPU::ld_d_d;
	opcodes[0x53] = &CPU::ld_d_e;
	opcodes[0x54] = &CPU::ld_d_h;
	opcodes[0x55] = &CPU::ld_d_l;
	opcodes[0x58] = &CPU::ld_e_b;
	opcodes[0x59] = &CPU::ld_e_c;
	opcodes[0x5A] = &CPU::ld_e_d;
	opcodes[0x5B] = &CPU::ld_e_e;
	opcodes[0x5C] = &CPU::ld_e_h;
	opcodes[0x5D] = &CPU::ld_e_l;
	opcodes[0x60] = &CPU::ld_h_b;
	opcodes[0x61] = &CPU::ld_h_c;
	opcodes[0x62] = &CPU::ld_h_d;
	opcodes[0x63] = &CPU::ld_h_e;
	opcodes[0x64] = &CPU::ld_h_h;
	opcodes[0x65] = &CPU::ld_h_l;
	opcodes[0x68] = &CPU::ld_l_b;
	opcodes[0x69] = &CPU::ld_l_c;
	opcodes[0x6A] = &CPU::ld_l_d;
	opcodes[0x6B] = &CPU::ld_l_e;
	opcodes[0x6C] = &CPU::ld_l_h;
	opcodes[0x6D] = &CPU::ld_l_l;
	opcodes[0x7E] = &CPU::ld_a_hl;
	opcodes[0x46] = &CPU::ld_b_hl;
	opcodes[0x4E] = &CPU::ld_c_hl;
	opcodes[0x56] = &CPU::ld_d_hl;
	opcodes[0x5E] = &CPU::ld_e_hl;
	opcodes[0x66] = &CPU::ld_h_hl;
	opcodes[0x6E] = &CPU::ld_l_hl;
	opcodes[0x77] = &CPU::ld_hl_a;
	opcodes[0x70] = &CPU::ld_hl_b;
	opcodes[0x71] = &CPU::ld_hl_c;
	opcodes[0x72] = &CPU::ld_hl_d;
	opcodes[0x73] = &CPU::ld_hl_e;
	opcodes[0x74] = &CPU::ld_hl_h;
	opcodes[0x75] = &CPU::ld_hl_l;
	opcodes[0x36] = &CPU::ld_hl_n;
	opcodes[0x0A] = &CPU::ld_a_bc;
	opcodes[0x1A] = &CPU::ld_a_de;
	opcodes[0xFA] = &CPU::ld_a_nn;
	opcodes[0x02] = &CPU::ld_bc_a;
	opcodes[0x12] = &CPU::ld_de_a;
	opcodes[0xEA] = &CPU::ld_nn_a;
	opcodes[0xE2] = &CPU::ldh_c_a;
	opcodes[0xF2] = &CPU::ldh_a_c;
	opcodes[0x3A] = &CPU::ld_a_hld;
	opcodes[0x32] = &CPU::ld_hld_a;
	opcodes[0x2A] = &CPU::ld_a_hli;
	opcodes[0x22] = &CPU::ld_hli_a;
	opcodes[0xE0] = &CPU::ldh_n_a;
	opcodes[0xF0] = &CPU::ldh_a_n;
	opcodes[0x01] = &CPU::ld_bc_nn;
	opcodes[0x11] = &CPU::ld_de_nn;
	opcodes[0x21] = &CPU::ld_hl_nn;
	opcodes[0x31] = &CPU::ld_sp_nn;
	opcodes[0xF9] = &CPU::ld_sp_hl;
	opcodes[0xF8] = &CPU::ldhl_sp_n;
	opcodes[0x08] = &CPU::ld_nn_sp;
	opcodes[0xF5] = &CPU::push_af;
	opcodes[0xC5] = &CPU::push_bc;
	opcodes[0xD5] = &CPU::push_de;
	opcodes[0xE5] = &CPU::push_hl;
	opcodes[0xF1] = &CPU::pop_af;
	opcodes[0xC1] = &CPU::pop_bc;
	opcodes[0xD1] = &CPU::pop_de;
	opcodes[0xE1] = &CPU::pop_hl;
	opcodes[0x87] = &CPU::add_a_a;
	opcodes[0x80] = &CPU::add_a_b;
	opcodes[0x81] = &CPU::add_a_c;
	opcodes[0x82] = &CPU::add_a_d;
	opcodes[0x83] = &CPU::add_a_e;
	opcodes[0x84] = &CPU::add_a_h;
	opcodes[0x85] = &CPU::add_a_l;
	opcodes[0x86] = &CPU::add_a_hl_ref;
	opcodes[0xC6] = &CPU::add_a_n;
	opcodes[0x8F] = &CPU::adc_a_a;
	opcodes[0x88] = &CPU::adc_a_b;
	opcodes[0x89] = &CPU::adc_a_c;
	opcodes[0x8A] = &CPU::adc_a_d;
	opcodes[0x8B] = &CPU::adc_a_e;
	opcodes[0x8C] = &CPU::adc_a_h;
	opcodes[0x8D] = &CPU::adc_a_l;
	opcodes[0x8E] = &CPU::adc_a_hl_ref;
	opcodes[0xCE] = &CPU::adc_a_n;
	opcodes[0x97] = &CPU::sub_a_a;
	opcodes[0x90] = &CPU::sub_a_b;
	opcodes[0x91] = &CPU::sub_a_c;
	opcodes[0x92] = &CPU::sub_a_d;
	opcodes[0x93] = &CPU::sub_a_e;
	opcodes[0x94] = &CPU::sub_a_h;
	opcodes[0x95] = &CPU::sub_a_l;
	opcodes[0x96] = &CPU::sub_a_hl_ref;
	opcodes[0xD6] = &CPU::sub_a_n;
	opcodes[0x9F] = &CPU::sbc_a_a;
	opcodes[0x98] = &CPU::sbc_a_b;
	opcodes[0x99] = &CPU::sbc_a_c;
	opcodes[0x9A] = &CPU::sbc_a_d;
	opcodes[0x9B] = &CPU::sbc_a_e;
	opcodes[0x9C] = &CPU::sbc_a_h;
	opcodes[0x9D] = &CPU::sbc_a_l;
	opcodes[0x9E] = &CPU::sbc_a_hl_ref;
	opcodes[0xDE] = &CPU::sbc_a_n;
	opcodes[0xA7] = &CPU::and_a_a;
	opcodes[0xA0] = &CPU::and_a_b;
	opcodes[0xA1] = &CPU::and_a_c;
	opcodes[0xA2] = &CPU::and_a_d;
	opcodes[0xA3] = &CPU::and_a_e;
	opcodes[0xA4] = &CPU::and_a_h;
	opcodes[0xA5] = &CPU::and_a_l;
	opcodes[0xA6] = &CPU::and_a_hl_ref;
	opcodes[0xE6] = &CPU::and_a_n;
	opcodes[0xB7] = &CPU::or_a_a;
	opcodes[0xB0] = &CPU::or_a_b;
	opcodes[0xB1] = &CPU::or_a_c;
	opcodes[0xB2] = &CPU::or_a_d;
	opcodes[0xB3] = &CPU::or_a_e;
	opcodes[0xB4] = &CPU::or_a_h;
	opcodes[0xB5] = &CPU::or_a_l;
	opcodes[0xB6] = &CPU::or_a_hl_ref;
	opcodes[0xF6] = &CPU::or_a_n;
	opcodes[0xAF] = &CPU::xor_a_a;
	opcodes[0xA8] = &CPU::xor_a_b;
	opcodes[0xA9] = &CPU::xor_a_c;
	opcodes[0xAA] = &CPU::xor_a_d;
	opcodes[0xAB] = &CPU::xor_a_e;
	opcodes[0xAC] = &CPU::xor_a_h;
	opcodes[0xAD] = &CPU::xor_a_l;
	opcodes[0xAE] = &CPU::xor_a_hl_ref;
	opcodes[0xEE] = &CPU::xor_a_n;
	opcodes[0xBF] = &CPU::cp_a_a;
	opcodes[0xB8] = &CPU::cp_a_b;
	opcodes[0xB9] = &CPU::cp_a_c;
	opcodes[0xBA] = &CPU::cp_a_d;
	opcodes[0xBB] = &CPU::cp_a_e;
	opcodes[0xBC] = &CPU::cp_a_h;
	opcodes[0xBD] = &CPU::cp_a_l;
	opcodes[0xBE] = &CPU::cp_a_hl_ref;
	opcodes[0xFE] = &CPU::cp_a_n;
	opcodes[0x3C] = &CPU::inc_a;
	opcodes[0x04] = &CPU::inc_b;
	opcodes[0x0C] = &CPU::inc_c;
	opcodes[0x14] = &CPU::inc_d;
	opcodes[0x1C] = &CPU::inc_e;
	opcodes[0x24] = &CPU::inc_h;
	opcodes[0x2C] = &CPU::inc_l;
	opcodes[0x34] = &CPU::inc_hl_ref;
	opcodes[0x3D] = &CPU::dec_a;
	opcodes[0x05] = &CPU::dec_b;
	opcodes[0x0D] = &CPU::dec_c;
	opcodes[0x15] = &CPU::dec_d;
	opcodes[0x1D] = &CPU::dec_e;
	opcodes[0x25] = &CPU::dec_h;
	opcodes[0x2D] = &CPU::dec_l;
	opcodes[0x35] = &CPU::dec_hl_ref;
	opcodes[0x09] = &CPU::add_hl_bc;
	opcodes[0x19] = &CPU::add_hl_de;
	opcodes[0x29] = &CPU::add_hl_hl;
	opcodes[0x39] = &CPU::add_hl_sp;
	opcodes[0xE8] = &CPU::add_sp_n;
	opcodes[0x03] = &CPU::inc_bc;
	opcodes[0x13] = &CPU::inc_de;
	opcodes[0x23] = &CPU::inc_hl;
	opcodes[0x33] = &CPU::inc_sp;
	opcodes[0x0B] = &CPU::dec_bc;
	opcodes[0x1B] = &CPU::dec_de;
	opcodes[0x2B] = &CPU::dec_hl;
	opcodes[0x3B] = &CPU::dec_sp;
	opcodes[0x27] = &CPU::daa;
	opcodes[0x2F] = &CPU::cpl;
	opcodes[0x3F] = &CPU::ccf;
	opcodes[0x37] = &CPU::scf;
	opcodes[0x00] = &CPU::nop;
	opcodes[0x76] = &CPU::halt;
	opcodes[0x10] = &CPU::stop;
	opcodes[0xF3] = &CPU::di;
	opcodes[0xFB] = &CPU::ei;
	opcodes[0x07] = &CPU::rlca;
	opcodes[0x17] = &CPU::rla;
	opcodes[0x0F] = &CPU::rrca;
	opcodes[0x1F] = &CPU::rra;
	opcodes[0xC3] = &CPU::jp_nn;
	opcodes[0xC2] = &CPU::jp_nz_nn;
	opcodes[0xCA] = &CPU::jp_z_nn;
	opcodes[0xD2] = &CPU::jp_nc_nn;
	opcodes[0xDA] = &CPU::jp_c_nn;
	opcodes[0xE9] = &CPU::jp_hl;
	opcodes[0x18] = &CPU::jr_n;
	opcodes[0x20] = &CPU::jr_nz_n;
	opcodes[0x28] = &CPU::jr_z_n;
	opcodes[0x30] = &CPU::jr_nc_n;
	opcodes[0x38] = &CPU::jr_c_n;
	opcodes[0xCD] = &CPU::call_nn;
	opcodes[0xC4] = &CPU::call_nz_nn;
	opcodes[0xCC] = &CPU::call_z_nn;
	opcodes[0xD4] = &CPU::call_nc_nn;
	opcodes[0xDC] = &CPU::call_c_nn;
	opcodes[0xC7] = &CPU::rst_00;
	opcodes[0xCF] = &CPU::rst_08;
	opcodes[0xD7] = &CPU::rst_10;
	opcodes[0xDF] = &CPU::rst_18;
	opcodes[0xE7] = &CPU::rst_20;
	opcodes[0xEF] = &CPU::rst_28;
	opcodes[0xF7] = &CPU::rst_30;
	opcodes[0xFF] = &CPU::rst_38;
	opcodes[0xC9] = &CPU::ret;
	opcodes[0xC0] = &CPU::ret_nz;
	opcodes[0xC8] = &CPU::ret_z;
	opcodes[0xD0] = &CPU::ret_nc;
	opcodes[0xD8] = &CPU::ret_c;
	opcodes[0xD9] = &CPU::reti;

	/* EXT (CB Prefix) */
	ext_opcodes[0x37] = &CPU::swap_a;
	ext_opcodes[0x30] = &CPU::swap_b;
	ext_opcodes[0x31] = &CPU::swap_c;
	ext_opcodes[0x32] = &CPU::swap_d;
	ext_opcodes[0x33] = &CPU::swap_e;
	ext_opcodes[0x34] = &CPU::swap_h;
	ext_opcodes[0x35] = &CPU::swap_l;
	ext_opcodes[0x36] = &CPU::swap_hl_ref;
	ext_opcodes[0x07] = &CPU::rlc_a;
	ext_opcodes[0x00] = &CPU::rlc_b;
	ext_opcodes[0x01] = &CPU::rlc_c;
	ext_opcodes[0x02] = &CPU::rlc_d;
	ext_opcodes[0x03] = &CPU::rlc_e;
	ext_opcodes[0x04] = &CPU::rlc_h;
	ext_opcodes[0x05] = &CPU::rlc_l;
	ext_opcodes[0x06] = &CPU::rlc_hl_ref;
	ext_opcodes[0x17] = &CPU::rl_a;
	ext_opcodes[0x10] = &CPU::rl_b;
	ext_opcodes[0x11] = &CPU::rl_c;
	ext_opcodes[0x12] = &CPU::rl_d;
	ext_opcodes[0x13] = &CPU::rl_e;
	ext_opcodes[0x14] = &CPU::rl_h;
	ext_opcodes[0x15] = &CPU::rl_l;
	ext_opcodes[0x16] = &CPU::rl_hl_ref;
	ext_opcodes[0x0F] = &CPU::rrc_a;
	ext_opcodes[0x08] = &CPU::rrc_b;
	ext_opcodes[0x09] = &CPU::rrc_c;
	ext_opcodes[0x0A] = &CPU::rrc_d;
	ext_opcodes[0x0B] = &CPU::rrc_e;
	ext_opcodes[0x0C] = &CPU::rrc_h;
	ext_opcodes[0x0D] = &CPU::rrc_l;
	ext_opcodes[0x0E] = &CPU::rrc_hl_ref;
	ext_opcodes[0x1F] = &CPU::rr_a;
	ext_opcodes[0x18] = &CPU::rr_b;
	ext_opcodes[0x19] = &CPU::rr_c;
	ext_opcodes[0x1A] = &CPU::rr_d;
	ext_opcodes[0x1B] = &CPU::rr_e;
	ext_opcodes[0x1C] = &CPU::rr_h;
	ext_opcodes[0x1D] = &CPU::rr_l;
	ext_opcodes[0x1E] = &CPU::rr_hl_ref;
	ext_opcodes[0x27] = &CPU::sla_a;
	ext_opcodes[0x20] = &CPU::sla_b;
	ext_opcodes[0x21] = &CPU::sla_c;
	ext_opcodes[0x22] = &CPU::sla_d;
	ext_opcodes[0x23] = &CPU::sla_e;
	ext_opcodes[0x24] = &CPU::sla_h;
	ext_opcodes[0x25] = &CPU::sla_l;
	ext_opcodes[0x26] = &CPU::sla_hl_ref;
	ext_opcodes[0x2F] = &CPU::sra_a;
	ext_opcodes[0x28] = &CPU::sra_b;
	ext_opcodes[0x29] = &CPU::sra_c;
	ext_opcodes[0x2A] = &CPU::sra_d;
	ext_opcodes[0x2B] = &CPU::sra_e;
	ext_opcodes[0x2C] = &CPU::sra_h;
	ext_opcodes[0x2D] = &CPU::sra_l;
	ext_opcodes[0x2E] = &CPU::sra_hl_ref;
	ext_opcodes[0x3F] = &CPU::srl_a;
	ext_opcodes[0x38] = &CPU::srl_b;
	ext_opcodes[0x39] = &CPU::srl_c;
	ext_opcodes[0x3A] = &CPU::srl_d;
	ext_opcodes[0x3B] = &CPU::srl_e;
	ext_opcodes[0x3C] = &CPU::srl_h;
	ext_opcodes[0x3D] = &CPU::srl_l;
	ext_opcodes[0x3E] = &CPU::srl_hl_ref;
	ext_opcodes[0x47] = &CPU::bit_a_0;
	ext_opcodes[0x40] = &CPU::bit_b_0;
	ext_opcodes[0x41] = &CPU::bit_c_0;
	ext_opcodes[0x42] = &CPU::bit_d_0;
	ext_opcodes[0x43] = &CPU::bit_e_0;
	ext_opcodes[0x44] = &CPU::bit_h_0;
	ext_opcodes[0x45] = &CPU::bit_l_0;
	ext_opcodes[0x46] = &CPU::bit_hl_ref_0;
	ext_opcodes[0x4F] = &CPU::bit_a_1;
	ext_opcodes[0x48] = &CPU::bit_b_1;
	ext_opcodes[0x49] = &CPU::bit_c_1;
	ext_opcodes[0x4A] = &CPU::bit_d_1;
	ext_opcodes[0x4B] = &CPU::bit_e_1;
	ext_opcodes[0x4C] = &CPU::bit_h_1;
	ext_opcodes[0x4D] = &CPU::bit_l_1;
	ext_opcodes[0x4E] = &CPU::bit_hl_ref_1;
	ext_opcodes[0x57] = &CPU::bit_a_2;
	ext_opcodes[0x50] = &CPU::bit_b_2;
	ext_opcodes[0x51] = &CPU::bit_c_2;
	ext_opcodes[0x52] = &CPU::bit_d_2;
	ext_opcodes[0x53] = &CPU::bit_e_2;
	ext_opcodes[0x54] = &CPU::bit_h_2;
	ext_opcodes[0x55] = &CPU::bit_l_2;
	ext_opcodes[0x56] = &CPU::bit_hl_ref_2;
	ext_opcodes[0x5F] = &CPU::bit_a_3;
	ext_opcodes[0x58] = &CPU::bit_b_3;
	ext_opcodes[0x59] = &CPU::bit_c_3;
	ext_opcodes[0x5A] = &CPU::bit_d_3;
	ext_opcodes[0x5B] = &CPU::bit_e_3;
	ext_opcodes[0x5C] = &CPU::bit_h_3;
	ext_opcodes[0x5D] = &CPU::bit_l_3;
	ext_opcodes[0x5E] = &CPU::bit_hl_ref_3;
	ext_opcodes[0x67] = &CPU::bit_a_4;
	ext_opcodes[0x60] = &CPU::bit_b_4;
	ext_opcodes[0x61] = &CPU::bit_c_4;
	ext_opcodes[0x62] = &CPU::bit_d_4;
	ext_opcodes[0x63] = &CPU::bit_e_4;
	ext_opcodes[0x64] = &CPU::bit_h_4;
	ext_opcodes[0x65] = &CPU::bit_l_4;
	ext_opcodes[0x66] = &CPU::bit_hl_ref_4;
	ext_opcodes[0x6F] = &CPU::bit_a_5;
	ext_opcodes[0x68] = &CPU::bit_b_5;
	ext_opcodes[0x69] = &CPU::bit_c_5;
	ext_opcodes[0x6A] = &CPU::bit_d_5;
	ext_opcodes[0x6B] = &CPU::bit_e_5;
	ext_opcodes[0x6C] = &CPU::bit_h_5;
	ext_opcodes[0x6D] = &CPU::bit_l_5;
	ext_opcodes[0x6E] = &CPU::bit_hl_ref_5;
	ext_opcodes[0x77] = &CPU::bit_a_6;
	ext_opcodes[0x70] = &CPU::bit_b_6;
	ext_opcodes[0x71] = &CPU::bit_c_6;
	ext_opcodes[0x72] = &CPU::bit_d_6;
	ext_opcodes[0x73] = &CPU::bit_e_6;
	ext_opcodes[0x74] = &CPU::bit_h_6;
	ext_opcodes[0x75] = &CPU::bit_l_6;
	ext_opcodes[0x76] = &CPU::bit_hl_ref_6;
	ext_opcodes[0x7F] = &CPU::bit_a_7;
	ext_opcodes[0x78] = &CPU::bit_b_7;
	ext_opcodes[0x79] = &CPU::bit_c_7;
	ext_opcodes[0x7A] = &CPU::bit_d_7;
	ext_opcodes[0x7B] = &CPU::bit_e_7;
	ext_opcodes[0x7C] = &CPU::bit_h_7;
	ext_opcodes[0x7D] = &CPU::bit_l_7;
	ext_opcodes[0x7E] = &CPU::bit_hl_ref_7;
	ext_opcodes[0x87] = &CPU::res_a_0;
	ext_opcodes[0x80] = &CPU::res_b_0;
	ext_opcodes[0x81] = &CPU::res_c_0;
	ext_opcodes[0x82] = &CPU::res_d_0;
	ext_opcodes[0x83] = &CPU::res_e_0;
	ext_opcodes[0x84] = &CPU::res_h_0;
	ext_opcodes[0x85] = &CPU::res_l_0;
	ext_opcodes[0x86] = &CPU::res_hl_ref_0;
	ext_opcodes[0x8F] = &CPU::res_a_1;
	ext_opcodes[0x88] = &CPU::res_b_1;
	ext_opcodes[0x89] = &CPU::res_c_1;
	ext_opcodes[0x8A] = &CPU::res_d_1;
	ext_opcodes[0x8B] = &CPU::res_e_1;
	ext_opcodes[0x8C] = &CPU::res_h_1;
	ext_opcodes[0x8D] = &CPU::res_l_1;
	ext_opcodes[0x8E] = &CPU::res_hl_ref_1;
	ext_opcodes[0x97] = &CPU::res_a_2;
	ext_opcodes[0x90] = &CPU::res_b_2;
	ext_opcodes[0x91] = &CPU::res_c_2;
	ext_opcodes[0x92] = &CPU::res_d_2;
	ext_opcodes[0x93] = &CPU::res_e_2;
	ext_opcodes[0x94] = &CPU::res_h_2;
	ext_opcodes[0x95] = &CPU::res_l_2;
	ext_opcodes[0x96] = &CPU::res_hl_ref_2;
	ext_opcodes[0x9F] = &CPU::res_a_3;
	ext_opcodes[0x98] = &CPU::res_b_3;
	ext_opcodes[0x99] = &CPU::res_c_3;
	ext_opcodes[0x9A] = &CPU::res_d_3;
	ext_opcodes[0x9B] = &CPU::res_e_3;
	ext_opcodes[0x9C] = &CPU::res_h_3;
	ext_opcodes[0x9D] = &CPU::res_l_3;
	ext_opcodes[0x9E] = &CPU::res_hl_ref_3;
	ext_opcodes[0xA7] = &CPU::res_a_4;
	ext_opcodes[0xA0] = &CPU::res_b_4;
	ext_opcodes[0xA1] = &CPU::res_c_4;
	ext_opcodes[0xA2] = &CPU::res_d_4;
	ext_opcodes[0xA3] = &CPU::res_e_4;
	ext_opcodes[0xA4] = &CPU::res_h_4;
	ext_opcodes[0xA5] = &CPU::res_l_4;
	ext_opcodes[0xA6] = &CPU::res_hl_ref_4;
	ext_opcodes[0xAF] = &CPU::res_a_5;
	ext_opcodes[0xA8] = &CPU::res_b_5;
	ext_opcodes[0xA9] = &CPU::res_c_5;
	ext_opcodes[0xAA] = &CPU::res_d_5;
	ext_opcodes[0xAB] = &CPU::res_e_5;
	ext_opcodes[0xAC] = &CPU::res_h_5;
	ext_opcodes[0xAD] = &CPU::res_l_5;
	ext_opcodes[0xAE] = &CPU::res_hl_ref_5;
	ext_opcodes[0xB7] = &CPU::res_a_6;
	ext_opcodes[0xB0] = &CPU::res_b_6;
	ext_opcodes[0xB1] = &CPU::res_c_6;
	ext_opcodes[0xB2] = &CPU::res_d_6;
	ext_opcodes[0xB3] = &CPU::res_e_6;
	ext_opcodes[0xB4] = &CPU::res_h_6;
	ext_opcodes[0xB5] = &CPU::res_l_6;
	ext_opcodes[0xB6] = &CPU::res_hl_ref_6;
	ext_opcodes[0xBF] = &CPU::res_a_7;
	ext_opcodes[0xB8] = &CPU::res_b_7;
	ext_opcodes[0xB9] = &CPU::res_c_7;
	ext_opcodes[0xBA] = &CPU::res_d_7;
	ext_opcodes[0xBB] = &CPU::res_e_7;
	ext_opcodes[0xBC] = &CPU::res_h_7;
	ext_opcodes[0xBD] = &CPU::res_l_7;
	ext_opcodes[0xBE] = &CPU::res_hl_ref_7;
	ext_opcodes[0xC7] = &CPU::set_a_0;
	ext_opcodes[0xC0] = &CPU::set_b_0;
	ext_opcodes[0xC1] = &CPU::set_c_0;
	ext_opcodes[0xC2] = &CPU::set_d_0;
	ext_opcodes[0xC3] = &CPU::set_e_0;
	ext_opcodes[0xC4] = &CPU::set_h_0;
	ext_opcodes[0xC5] = &CPU::set_l_0;
	ext_opcodes[0xC6] = &CPU::set_hl_ref_0;
	ext_opcodes[0xCF] = &CPU::set_a_1;
	ext_opcodes[0xC8] = &CPU::set_b_1;
	ext_opcodes[0xC9] = &CPU::set_c_1;
	ext_opcodes[0xCA] = &CPU::set_d_1;
	ext_opcodes[0xCB] = &CPU::set_e_1;
	ext_opcodes[0xCC] = &CPU::set_h_1;
	ext_opcodes[0xCD] = &CPU::set_l_1;
	ext_opcodes[0xCE] = &CPU::set_hl_ref_1;
	ext_opcodes[0xD7] = &CPU::set_a_2;
	ext_opcodes[0xD0] = &CPU::set_b_2;
	ext_opcodes[0xD1] = &CPU::set_c_2;
	ext_opcodes[0xD2] = &CPU::set_d_2;
	ext_opcodes[0xD3] = &CPU::set_e_2;
	ext_opcodes[0xD4] = &CPU::set_h_2;
	ext_opcodes[0xD5] = &CPU::set_l_2;
	ext_opcodes[0xD6] = &CPU::set_hl_ref_2;
	ext_opcodes[0xDF] = &CPU::set_a_3;
	ext_opcodes[0xD8] = &CPU::set_b_3;
	ext_opcodes[0xD9] = &CPU::set_c_3;
	ext_opcodes[0xDA] = &CPU::set_d_3;
	ext_opcodes[0xDB] = &CPU::set_e_3;
	ext_opcodes[0xDC] = &CPU::set_h_3;
	ext_opcodes[0xDD] = &CPU::set_l_3;
	ext_opcodes[0xDE] = &CPU::set_hl_ref_3;
	ext_opcodes[0xE7] = &CPU::set_a_4;
	ext_opcodes[0xE0] = &CPU::set_b_4;
	ext_opcodes[0xE1] = &CPU::set_c_4;
	ext_opcodes[0xE2] = &CPU::set_d_4;
	ext_opcodes[0xE3] = &CPU::set_e_4;
	ext_opcodes[0xE4] = &CPU::set_h_4;
	ext_opcodes[0xE5] = &CPU::set_l_4;
	ext_opcodes[0xE6] = &CPU::set_hl_ref_4;
	ext_opcodes[0xEF] = &CPU::set_a_5;
	ext_opcodes[0xE8] = &CPU::set_b_5;
	ext_opcodes[0xE9] = &CPU::set_c_5;
	ext_opcodes[0xEA] = &CPU::set_d_5;
	ext_opcodes[0xEB] = &CPU::set_e_5;
	ext_opcodes[0xEC] = &CPU::set_h_5;
	ext_opcodes[0xED] = &CPU::set_l_5;
	ext_opcodes[0xEE] = &CPU::set_hl_ref_5;
	ext_opcodes[0xF7] = &CPU::set_a_6;
	ext_opcodes[0xF0] = &CPU::set_b_6;
	ext_opcodes[0xF1] = &CPU::set_c_6;
	ext_opcodes[0xF2] = &CPU::set_d_6;
	ext_opcodes[0xF3] = &CPU::set_e_6;
	ext_opcodes[0xF4] = &CPU::set_h_6;
	ext_opcodes[0xF5] = &CPU::set_l_6;
	ext_opcodes[0xF6] = &CPU::set_hl_ref_6;
	ext_opcodes[0xFF] = &CPU::set_a_7;
	ext_opcodes[0xF8] = &CPU::set_b_7;
	ext_opcodes[0xF9] = &CPU::set_c_7;
	ext_opcodes[0xFA] = &CPU::set_d_7;
	ext_opcodes[0xFB] = &CPU::set_e_7;
	ext_opcodes[0xFC] = &CPU::set_h_7;
	ext_opcodes[0xFD] = &CPU::set_l_7;
	ext_opcodes[0xFE] = &CPU::set_hl_ref_7;
}

} /* namespace */
