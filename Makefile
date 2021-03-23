FLAGS=-I. -Isrc -Isrc/dependencies -lm -ldl -std=c99 -O3 -Wall -Wextra -pedantic -Wstrict-prototypes -Wold-style-definition
LINKER_FLAGS=-lm -ldl
CFILES=src/dependencies/sds/*.c src/dependencies/toml/*.c src/**/*.c src/*.c ./src/dependencies/yasl/libyaslapi.a
HEADERS=src/dependencies/sds/*.h src/dependencies/toml/*.h src/**/*.h src/*.h


build:
	cc $(FLAGS) $(CFILES) fsummary.c $(LINKER_FLAGS) -o fsummary

install-dependencies:
	git submodule init && cd src/dependencies/yasl && cmake --configure . && cmake --build .

check: build
	 ./fsummary ./Makefile

test:
	cc $(FLAGS) $(CFILES) ./test.c $(LINKER_FLAGS) -o test && ./test

format: 
	 clang-format -i --style=llvm $(CFILES) $(HEADERS)
