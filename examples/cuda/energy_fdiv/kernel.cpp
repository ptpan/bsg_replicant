//This kernel adds 2 vectors 

#include <bsg_manycore.h>
#include <bsg_set_tile_x_y.h>
#include <bsg_tile_group_barrier.hpp>

bsg_barrier<bsg_tiles_X, bsg_tiles_Y> barrier;

extern "C" __attribute__ ((noinline))
int kernel_energy_fdiv(int *A, int *B, int *C, int N, int block_size) {
  //------------------------------------
  __asm__ __volatile__ (
                         "addi sp, sp, -48;"
                         "sw   s0, 44(sp);"
                         "sw   s1, 40(sp);"
                         "sw   s2, 36(sp);"
                         "sw   s3, 32(sp);"
                         "sw   s4, 28(sp);"
                         "sw   s5, 24(sp);"
                         "sw   s6, 20(sp);"
                         "sw   s7, 16(sp);"
                         "sw   s8, 12(sp);"
                         "sw   s9, 8(sp);"
                         "sw   s10, 4(sp);"
                         "sw   s11, 0(sp);"
                        );
  __asm__ __volatile__ (
                         "lui t0,0xe39c;"
                         "lui t1,0x95e93;"
                         "lui t2,0x896f8;"
                         "lui s0,0x55f11;"
                         "lui s1,0xe2161;"
                         "lui a0,0x8813b;"
                         "lui a1,0xb5c8b;"
                         "lui a2,0xedcb2;"
                         "lui a3,0x144dd;"
                         "lui a4,0x72316;"
                         "lui a5,0x2b181;"
                         "lui a6,0x5e89a;"
                         "lui a7,0xf0591;"
                         "lui s2,0x687f;"
                         "lui s3,0x976;"
                         "lui s4,0x12cd3;"
                         "lui s5,0x6233c;"
                         "lui s6,0x6ebd9;"
                         "lui s7,0xcf00;"
                         "lui s8,0xf49fb;"
                         "lui s9,0xe10b6;"
                         "lui s10,0x2288f;"
                         "lui s11,0xcfa37;"
                         "lui t3,0xd7341;"
                         "lui t4,0xcca30;"
                         "lui t5,0xfd95d;"
                         "lui t6,0x7c8e3;"
                         "fcvt.s.w ft0,t0;"
                         "fcvt.s.w ft1,t1;"
                         "fcvt.s.w ft2,t2;"
                         "fcvt.s.w ft3,s0;"
                         "fcvt.s.w ft4,s1;"
                         "fcvt.s.w ft5,a0;"
                         "fcvt.s.w ft6,a1;"
                         "fcvt.s.w ft7,a2;"
                         "fcvt.s.w fs0,a3;"
                         "fcvt.s.w fs1,a4;"
                         "fcvt.s.w fa0,a5;"
                         "fcvt.s.w fa1,a6;"
                         "fcvt.s.w fa2,a7;"
                         "fcvt.s.w fa3,s2;"
                         "fcvt.s.w fa4,s3;"
                         "fcvt.s.w fa5,s4;"
                         "fcvt.s.w fa6,s5;"
                         "fcvt.s.w fa7,s6;"
                         "fcvt.s.w fs2,s7;"
                         "fcvt.s.w fs3,s8;"
                         "fcvt.s.w fs4,s9;"
                         "fcvt.s.w fs5,s10;"
                         "fcvt.s.w fs6,s11;"
                         "fcvt.s.w fs7,t3;"
                         "fcvt.s.w fs8,t4;"
                         "fcvt.s.w fs9,t5;"
                         "fcvt.s.w fs10,t6;"
                       );
  //------------------------------------
  bsg_saif_start();
  //------------------------------------
  // 100 back to back adds
  __asm__ __volatile__ (
                        "fdiv.s ft0, ft1, ft2;"
                        "fdiv.s ft1, ft2, ft3;"
                        "fdiv.s ft2, ft3, ft4;"
                        "fdiv.s ft3, ft4, ft5;"
                        "fdiv.s ft4, ft5, ft6;"
                        "fdiv.s ft5, ft6, ft7;"
                        "fdiv.s ft6, ft7, fs0;"
                        "fdiv.s ft7, fs0, fs1;"
                        "fdiv.s fs0, fs1, fa0;"
                        "fdiv.s fs1, fa0, fa1;"
                        "fdiv.s fa0, fa1, fa2;"
                        "fdiv.s fa1, fa2, fa3;"
                        "fdiv.s fa2, fa3, fa4;"
                        "fdiv.s fa3, fa4, fa5;"
                        "fdiv.s fa4, fa5, fa6;"
                        "fdiv.s fa5, fa6, fa7;"
                        "fdiv.s fa6, fa7, fs2;"
                        "fdiv.s fa7, fs2, fs3;"
                        "fdiv.s fs2, fs3, fs4;"
                        "fdiv.s fs3, fs4, fs5;"
                        "fdiv.s ft0, ft1, ft2;"
                        "fdiv.s ft1, ft2, ft3;"
                        "fdiv.s ft2, ft3, ft4;"
                        "fdiv.s ft3, ft4, ft5;"
                        "fdiv.s ft4, ft5, ft6;"
                        "fdiv.s ft5, ft6, ft7;"
                        "fdiv.s ft6, ft7, fs0;"
                        "fdiv.s ft7, fs0, fs1;"
                        "fdiv.s fs0, fs1, fa0;"
                        "fdiv.s fs1, fa0, fa1;"
                        "fdiv.s fa0, fa1, fa2;"
                        "fdiv.s fa1, fa2, fa3;"
                        "fdiv.s fa2, fa3, fa4;"
                        "fdiv.s fa3, fa4, fa5;"
                        "fdiv.s fa4, fa5, fa6;"
                        "fdiv.s fa5, fa6, fa7;"
                        "fdiv.s fa6, fa7, fs2;"
                        "fdiv.s fa7, fs2, fs3;"
                        "fdiv.s fs2, fs3, fs4;"
                        "fdiv.s fs3, fs4, fs5;"
                        "fdiv.s ft0, ft1, ft2;"
                        "fdiv.s ft1, ft2, ft3;"
                        "fdiv.s ft2, ft3, ft4;"
                        "fdiv.s ft3, ft4, ft5;"
                        "fdiv.s ft4, ft5, ft6;"
                        "fdiv.s ft5, ft6, ft7;"
                        "fdiv.s ft6, ft7, fs0;"
                        "fdiv.s ft7, fs0, fs1;"
                        "fdiv.s fs0, fs1, fa0;"
                        "fdiv.s fs1, fa0, fa1;"
                        "fdiv.s fa0, fa1, fa2;"
                        "fdiv.s fa1, fa2, fa3;"
                        "fdiv.s fa2, fa3, fa4;"
                        "fdiv.s fa3, fa4, fa5;"
                        "fdiv.s fa4, fa5, fa6;"
                        "fdiv.s fa5, fa6, fa7;"
                        "fdiv.s fa6, fa7, fs2;"
                        "fdiv.s fa7, fs2, fs3;"
                        "fdiv.s fs2, fs3, fs4;"
                        "fdiv.s fs3, fs4, fs5;"
                        "fdiv.s ft0, ft1, ft2;"
                        "fdiv.s ft1, ft2, ft3;"
                        "fdiv.s ft2, ft3, ft4;"
                        "fdiv.s ft3, ft4, ft5;"
                        "fdiv.s ft4, ft5, ft6;"
                        "fdiv.s ft5, ft6, ft7;"
                        "fdiv.s ft6, ft7, fs0;"
                        "fdiv.s ft7, fs0, fs1;"
                        "fdiv.s fs0, fs1, fa0;"
                        "fdiv.s fs1, fa0, fa1;"
                        "fdiv.s fa0, fa1, fa2;"
                        "fdiv.s fa1, fa2, fa3;"
                        "fdiv.s fa2, fa3, fa4;"
                        "fdiv.s fa3, fa4, fa5;"
                        "fdiv.s fa4, fa5, fa6;"
                        "fdiv.s fa5, fa6, fa7;"
                        "fdiv.s fa6, fa7, fs2;"
                        "fdiv.s fa7, fs2, fs3;"
                        "fdiv.s fs2, fs3, fs4;"
                        "fdiv.s fs3, fs4, fs5;"
                        "fdiv.s ft0, ft1, ft2;"
                        "fdiv.s ft1, ft2, ft3;"
                        "fdiv.s ft2, ft3, ft4;"
                        "fdiv.s ft3, ft4, ft5;"
                        "fdiv.s ft4, ft5, ft6;"
                        "fdiv.s ft5, ft6, ft7;"
                        "fdiv.s ft6, ft7, fs0;"
                        "fdiv.s ft7, fs0, fs1;"
                        "fdiv.s fs0, fs1, fa0;"
                        "fdiv.s fs1, fa0, fa1;"
                        "fdiv.s fa0, fa1, fa2;"
                        "fdiv.s fa1, fa2, fa3;"
                        "fdiv.s fa2, fa3, fa4;"
                        "fdiv.s fa3, fa4, fa5;"
                        "fdiv.s fa4, fa5, fa6;"
                        "fdiv.s fa5, fa6, fa7;"
                        "fdiv.s fa6, fa7, fs2;"
                        "fdiv.s fa7, fs2, fs3;"
                        "fdiv.s fs2, fs3, fs4;"
                        "fdiv.s fs3, fs4, fs5;"
                       );
  //------------------------------------
  bsg_saif_end();
  //------------------------------------
  __asm__ __volatile__ (
                         "lw   s0, 44(sp);"
                         "lw   s1, 40(sp);"
                         "lw   s2, 36(sp);"
                         "lw   s3, 32(sp);"
                         "lw   s4, 28(sp);"
                         "lw   s5, 24(sp);"
                         "lw   s6, 20(sp);"
                         "lw   s7, 16(sp);"
                         "lw   s8, 12(sp);"
                         "lw   s9, 8(sp);"
                         "lw   s10, 4(sp);"
                         "lw   s11, 0(sp);"
                         "addi sp, sp, 48;"
                        );
	barrier.sync();

	return 0;
}
