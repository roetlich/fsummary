FLAGS=-I. -Isrc -Isrc/dependencies -lm -ldl -std=c99 -O3 -Wall -Wextra -pedantic -Wstrict-prototypes -Wold-style-definition
LINKER_FLAGS=-lm -ldl
CFILES=src/dependencies/sds/*.c src/dependencies/toml/*.c src/**/*.c src/*.c ./src/dependencies/yasl/libyaslapi.a ./src/dependencies/lua/src/liblua.a
HEADERS=src/dependencies/sds/*.h src/dependencies/toml/*.h src/**/*.h src/*.h


build:
	cc $(FLAGS) $(CFILES) fsummary.c $(LINKER_FLAGS) -o fsummary

git-get-submodules:
	git submodule init

install-yasl: git-get-submodules
	cd src/dependencies/yasl && cmake --configure . && cmake --build .

install-lua:
	curl -R -O http://www.lua.org/ftp/lua-5.4.2.tar.gz && \
	mkdir -p ./src/dependencies/lua && \
	tar zxf lua-5.4.2.tar.gz -C ./src/dependencies/lua --strip-components=1 && \
	rm lua-5.4.2.tar.gz && \
	cd src/dependencies/lua && \
	make all test

install-dependencies: install-yasl install-lua

check: build
	 ./fsummary ./Makefile

test:
	cc $(FLAGS) $(CFILES) ./test.c $(LINKER_FLAGS) -o test && ./test

format: 
	 clang-format -i --style=llvm $(CFILES) $(HEADERS)
