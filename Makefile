.PHONY:clean
clean:
	rm -rf build/*

.PHONY:build
build:
	cd build && make

.PHONY:run
run:
	cd build && make && ./cpp_ray_tracing > out.ppm

.PHONY:setup
setup:
	cmake -S src -B build
