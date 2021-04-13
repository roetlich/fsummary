FLAGS=-I. -Isrc -Idependencies -lm -ldl -std=c99 -O3 -Wall -Wextra -pedantic -Wstrict-prototypes -Wold-style-definition
LINKER_FLAGS=-lm -ldl
CFILES=dependencies/sds/*.c dependencies/toml/*.c src/**/*.c src/*.c ./dependencies/yasl/build/libyaslapi.a ./dependencies/lua/src/liblua.a
HEADERS=dependencies/sds/*.h dependencies/toml/*.h src/**/*.h src/*.h


build:
	cc $(FLAGS) $(CFILES) fsummary.c $(LINKER_FLAGS) -o fsummary

git-get-submodules:
	git submodule init

install-yasl: git-get-submodules
	mkdir -p dependencies/yasl/build && \
	cd dependencies/yasl/build && \
	cmake .. && cmake --build . 

install-lua:
	curl -R -O http://www.lua.org/ftp/lua-5.4.2.tar.gz && \
	mkdir -p ./dependencies/lua && \
	tar zxf lua-5.4.2.tar.gz -C ./dependencies/lua --strip-components=1 && \
	rm lua-5.4.2.tar.gz && \
	cd dependencies/lua && \
	make all test

install-dependencies: install-yasl install-lua

check: build
	 ./fsummary ./Makefile

test:
	cc $(FLAGS) $(CFILES) ./test.c $(LINKER_FLAGS) -o test && ./test

format: 
	 find src/ -iname *.h -o -iname *.c | xargs clang-format -i --style=llvm


clean:
	rm -rf dependencies/lua/ ; \
	rm dependencies/yasl/libyaslapi.a
