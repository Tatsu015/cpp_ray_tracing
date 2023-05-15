.PHONY:out
out:
	./build/src/cpp_ray_tracing > out.ppm

.PHONY:build
build:
	cmake -B build -S src && cmake --build /workspaces/cpp_ray_tracing/build --config Debug --target all --

.PHONY:build
dev:
	cmake --build /workspaces/cpp_ray_tracing/build --config Debug --target all -- && ./build/cpp_ray_tracing > out.ppm

.PHONY:clean
clean:
	rm -rf build && mkdir build
