.PHONY:out
out:
	./build/src/cpp_ray_tracing > out.ppm

.PHONY:build
build:
	cmake --build /workspaces/cpp_ray_tracing/build --config Debug --target all --

.PHONY:clean
clean:
	cmake --build /workspaces/cpp_ray_tracing/build --config Debug --target clean --