.PHONY: build benchmark

build:
	rm -rf build
	mkdir build
	for number in 100 1000; do \
			g++ main.cc -std=c++17 -DSIZE=$$number -isystem benchmark/include -Lbenchmark/build/src -lbenchmark \
			-lpthread -Wall -fsanitize=address -fsanitize=undefined -ggdb3 -o build/benchmark_$$number ; \
	done


benchmark:
	rm -rf out
	mkdir out
	for number in 100 1000 ; do \
	./build/benchmark_$$number --benchmark_format=json > out/benchmark_$$number.json ; \
	done