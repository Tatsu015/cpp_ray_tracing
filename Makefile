.PHONEY run:
run:
	cd build && make && ./cpp_ray_tracing > out.ppm

.PHONEY setup:
setup:
	cmake -S src -B build
