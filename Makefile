.PHONY:clean
clean:
	rm -rf build/*

.PHONY:build
build:
	cmake -S src -B build && cd build && make

.PHONY:run
run:
	cd build && make && ./cpp_ray_tracing > out.ppm
