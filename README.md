# cpp_ray_tracing

[Ray Tracing in One Weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html)

[週末レイトレーシング](https://inzkyk.xyz/ray_tracing_in_one_weekend/)

Generate ray tracing image by C++

![out](https://github.com/Tatsu015/cpp_ray_tracing/assets/97239922/e48b87f2-db27-45bb-b9c3-4175b4b5cb2f)

## Usage

### build

Execute the following command.

~~~bash
make build_release
~~~

if you want to use debug infomation, use following command.

~~~bash
make build_dev
~~~
but debug mode is very slow compared to release mode.

### export image

Execute the following command, and generate file to ./out.ppm

~~~bash
make out
~~~

