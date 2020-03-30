# Copyright (c) 2019, University of Washington All rights reserved.
#
# Redistribution and use in source and binary forms, with or without modification,
# are permitted provided that the following conditions are met:
#
# Redistributions of source code must retain the above copyright notice, this list
# of conditions and the following disclaimer.
#
# Redistributions in binary form must reproduce the above copyright notice, this
# list of conditions and the following disclaimer in the documentation and/or
# other materials provided with the distribution.
#
# Neither the name of the copyright holder nor the names of its contributors may
# be used to endorse or promote products derived from this software without
# specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
# ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
# ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


# HARDWARE_PATH: The path to the hardware folder in BSG F1
ifndef HARDWARE_PATH
$(error $(shell echo -e "$(RED)BSG MAKE ERROR: HARDWARE_PATH is not defined$(NC)"))
endif

ifndef __HARDWARE_MEMSYS_AXI4_F1_MK
__HARDWARE_MEMSYS_AXI4_F1_MK := 1

# is this axi4 f1?
ifneq ($(filter axi4, $(subst _, ,$(CL_MANYCORE_MEM_CFG))),)
ifneq ($(filter f1,   $(subst _, ,$(CL_MANYCORE_MEM_CFG))),)

CL_MANYCORE_MEMSYS_ID := "AXI4" # AXI4

# are we using the AXI or the micron memory model?
ifneq ($(filter dram, $(subst _, ,$(CL_MANYCORE_MEM_CFG))),)
DISABLE_MICRON_MEMORY_MODEL := no

VINCLUDES += $(HDK_SHELL_DESIGN_DIR)/ip/axi_register_slice/hdl
VSOURCES += $(HDK_SHELL_DESIGN_DIR)/ip/axi_register_slice/sim/axi_register_slice.v
VSOURCES += $(HDK_SHELL_DESIGN_DIR)/ip/axi_clock_converter_0/hdl/axi_clock_converter_v2_1_vl_rfs.v
VSOURCES += $(HDK_SHELL_DESIGN_DIR)/ip/axi_clock_converter_0/hdl/fifo_generator_v13_2_rfs.v
VSOURCES += $(HDK_SHELL_DESIGN_DIR)/ip/axi_clock_converter_0/sim/axi_clock_converter_0.v
# Encrypted, Used in AWS DDR Model for SH BFM
VFLISTS += $(HDK_COMMON_DIR)/verif/tb/filelists/ddr.vcs.f

endif

endif
endif

endif
