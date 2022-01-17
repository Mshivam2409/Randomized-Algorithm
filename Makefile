.PHONY: build benchmark


install:
	git submodule update init --recursive

build:
	rm -rf build
	mkdir build
	for number in 100 1000 10000; do \
			g++ main.cc -std=c++17 -DBENCHMARK_EN -DSIZE=$$number -isystem benchmark/include -Lbenchmark/build/src -lbenchmark \
			-lpthread -Wall -ggdb3 -Ofast -march=native -o build/benchmark_$$number ; \
	done


benchmark:
	rm -rf out
	mkdir out
	for number in 100 1000 10000; do \
	./build/benchmark_$$number --benchmark_format=json > out/benchmark_$$number.json ; \
	done

test:
	rm -rf temp
	mkdir temp
	g++ test.cc -std=c++17 -I googletest/googletest/include -Lgoogletest/build/lib -lgtest -lpthread -lgtest_main -o temp/test.out
	temp/test.out
	rm -rf temp
 