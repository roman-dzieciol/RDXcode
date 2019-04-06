# RDXcode

These are partial Xcode libraries meant to be used just as helpers when reading actual Xcode assembly code.

The purpose of these libraries is to help understand how assembly code is generated from Objective-C code.

How it works:
1. Read the Xcode assembly
2. Write the Objective-C code that you believe was the original source code
3. Build and decompile Objective-C
4. Compare original code with what you've written
5. Repeat

Notes:
* It's best to use the same compiler version
* If custom optimisation options were used, ie PGO or hints, code may be slightly different
