.PHONY:out
out:
	./build/src/cpp_ray_tracing > out.ppm

.PHONY:build_dev
build_dev:
	cd build && cmake -DCMAKE_BUILD_TYPE=Debug .. && make

.PHONY:build_release
build_release:
	cd build && cmake -DCMAKE_BUILD_TYPE=Release .. && make

.PHONY:clean
clean:
	rm -rf build && mkdir build
