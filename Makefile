DEPS = grammar DecafBaseListener.cpp DecafBaseVisitor.cpp DecafLexer.cpp DecafListener.cpp DecafParser.cpp DecafVisitor.cpp 
DEPS += SymbolTable.cpp SymbolTableEntry.cpp SymbolTableListener.cpp DataTypes.cpp
DEPS += NodeAttrs.cpp IcgInstr.cpp IcGen.cpp

all: $(DEPS)
	g++ -I /usr/local/include/antlr4-runtime -o main ./*.cpp /usr/local/lib/libantlr4-runtime.a

grammar: Decaf.g4
	antlr4 -Dlanguage=Cpp -visitor -listener Decaf.g4