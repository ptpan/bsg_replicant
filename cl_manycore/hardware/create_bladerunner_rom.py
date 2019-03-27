#!/usr/bin/python

MC_VERSION_ID = 0x00200200
COMPILATION_DATA = 0x03272019
NETWORK_ADDR_WIDTH = 0x28
NETWORK_DATA_WIDTH = 0x32
NETWORK_DIMENSION_X = 4
NETWORK_DIMENSION_Y = 5
HOST_INTERFACE_COORD_X = 3
HOST_INTERFACE_COORD_Y = 0
DESCRIPTION_PTR = 0
BSG_IP_CORES_HASH = 0x47e23d7
BSG_MANYCORE_HASH = 0xFFFFFFFF
BSG_F1_HASH = 0xFFFFFFFF

def print_item(item):
  print("{:032b}".format(item))
    
print_item(MC_VERSION_ID)
print_item(COMPILATION_DATA)
print_item(NETWORK_ADDR_WIDTH)
print_item(NETWORK_DATA_WIDTH)
print_item(NETWORK_DIMENSION_X)
print_item(NETWORK_DIMENSION_Y)
print_item(HOST_INTERFACE_COORD_X)
print_item(HOST_INTERFACE_COORD_Y)
print_item(DESCRIPTION_PTR)
print_item(BSG_IP_CORES_HASH)
print_item(BSG_MANYCORE_HASH)
print_item(BSG_F1_HASH)
 
