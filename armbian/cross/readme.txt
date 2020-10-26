This is still under development, it won't work yet.

So far, I got the main program to cross-compile, but the dependencies still try to compile in amd64.

The cmake config line would be:

cmake -lpthread -DFFMPEG_URL=tools/depends/target/ffmpeg/4.0.4-Leia-18.4.tar.gz -DENABLE_X11=OFF -DENABLE_INTERNAL_FFMPEG=ON -DENABLE_INTERNAL_FLATBUFFERS=ON -DENABLE_VAAPI=OFF -DENABLE_VDPAU=OFF -DENABLE_OPENGLES=ON -DCORE_PLATFORM_NAME=gbm -DGBM_RENDER_SYSTEM=gles -DENABLE_OPENGL=OFF -DCPACK_GENERATOR=DEB -DDEBIAN_PACKAGE_VERSION=18.9 -DDEBIAN_PACKAGE_REVISION=0armbian-rockchip1 -DDEB_PACKAGE_ARCHITECTURE=armhf -DWITH_ARCH=arm -DWITH_CPU=cortex-a17 -DCMAKE_TOOLCHAIN_FILE=../xbmc/armbian/cross/toolchain-armhf.cmake ../xbmc
