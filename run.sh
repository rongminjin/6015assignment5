clang++ -fprofile-instr-generate -fcoverage-mapping main.cpp -o main
LLVM_PROFILE_FILE="main.profraw" ./main
/Applications/Xcode-9.4.1.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/llvm-profdata merge -sparse main.profraw -o main.profdata
/Applications/Xcode-9.4.1.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/llvm-cov show ./main -instr-profile=main.profdata                                                                                                                               