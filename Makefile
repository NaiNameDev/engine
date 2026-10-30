CXX = g++
STD = -std=c++20
FLGS = -O3 -flto
DEF = -DGLM_FORCE_INTRINSICS -DGLM_FORCE_DEFAULT_ALIGNED_GENTYPES -DGLM_ENABLE_EXPERIMENTAL
LIBS = -I./include -L./lib/glad -lglfw -lglad
SRC = main.cpp src/engine/*.cpp src/engine/ui/*.cpp
PREC_PATH = ./build/precompile_headers.hpp

a.elf: main.cpp
	$(CXX) $(STD) $(FLGS) $(DEF) $(SRC) -include $(PREC_PATH) -o ./build/a.out $(LIBS)

.PHONY = ctdbg gen_prec

ctdbg: main.cpp
	$(CXX) $(STD) $(FLGS) $(DEF) $(SRC) -include $(PREC_PATH) -o ./build/a.out $(LIBS)
	./build/a.out
	rm ./build/a.out

gen_prec: ./include/engine/ ./lib/glad/
	echo "#pragma once" > $(PREC_PATH)
	grep -r "#include" | awk -F':' '{print $$2}' | grep -vE "\"|engine|karavanum|win" | tr -d "*" | tr -d " " | grep ^[#] | sort -u >> $(PREC_PATH)
	#g++ ./include/glad/glad.c -c -o ./lib/glad/libglad.so -I./include/
	$(CXX) $(STD) $(FLGS) $(DEF) -x c++-header $(PREC_PATH) -I./include
