
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

# Phase 1: Authentication Firmware
The base software operates as a secure access controller:
- Users input a multi-digit employee ID followed by a secure pin via the matrix keypad
- The system queries the database to authenticate the credentials
- The firmware handles input debouncing, pin mapping, and basic security lockouts

# Phase 2: Cache Performance Benchmarking
This phase tests the physical performance differences between single-tier and multi-tier memory access.
- Test A (1-Level Cache): The system checks the fast SRAM (L1). On a cache miss, it fetches data directly from the slow MicroSD Module (Main DB)
- Test B (2-Level Cache): The system checks the SRAM (L1). On a miss, it checks the EEPROM (L2). Only if both miss does it access the MicroSD Module.
- Eviction Logic: Implements an LRU (Least Recently Used) algorithm to keep the most active shift workers in the fastest memory
- Metrics: Calculates and logs the Average System Access Time (Ts) over the serial monitor to prove the hardware acceleration

# Core Concepts Applied
- Memory Hierarchy & Access Latency
- Hit/Miss Ratios and the Cache Miss Penalty
- Spatial & Temporal Locality
- Hardware Communication Protocols (SPI & I2C)