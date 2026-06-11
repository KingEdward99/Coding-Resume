
# Multi-Level Cache Hardware Security Keypad

# Project Overview
This project is a physical demonstration of Computer Architecture and Organization principles. It implements a secure, embedded keypad authentication system using C++ on a Raspberry Pi microcontroller. The core objective is to physically build and benchmakr a memory hierarchy, proving how hardware-level cachine reduces access latency in security databases.

# Hardware Architecture (Bill of Materials)
Microcontroller: Raspberry Pi (Pico/Standard)
Input Interface: 4x4 Matrix Keypad
Physical Memory Hierarchy
- L1 Cache (Fastest): SPI SRAM Chip
- L2 Cache (Moderate): I2C EEPROM Chip
- Main Database (Slowest): MicroSD Card Module
Circuitry: Half-size breadboard & jumper wires
