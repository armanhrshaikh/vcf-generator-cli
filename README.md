# VCF Contact Generator
#### *A Lightweight C Program to Convert Text Lists to VCard Files*

---

## Table of Contents
- [ Features](#-features)  
- [ Quick Start](#-quick-start)  

---

## Features
**Simple Conversion** - Transform text lists into standard VCF (vCard) files  
**Memory Efficient** - Dynamic memory allocation handles large contact lists  
**Cross-Platform** - Works on Linux, Windows (WSL), and macOS  
**Error Handling** - Validates input file matching and file operations  

---

## Quick Start  
```bash
# Compile the program
gcc vcf_generator.c -o vcfgen

# Run with sample files
./vcfgen names.txt numbers.txt contacts.vcf
