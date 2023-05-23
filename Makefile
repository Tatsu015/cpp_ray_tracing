.PHONY:out
out:
	./build/cpp_ray_tracing > out.ppm

.PHONY:build
build:
	cmake --build /workspaces/cpp_ray_tracing/build --config Debug --target all --

.PHONY:dev
dev:
	cmake --build /workspaces/cpp_ray_tracing/build --config Debug --target all --

.PHONY:build_release
build_release:
	cmake -B build -S src && cmake --build /workspaces/cpp_ray_tracing/build --config Release --target all --

.PHONY:clean
clean:
	rm -rf build && mkdir build
