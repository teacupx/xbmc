# CMAKE TOOLCHAIN FILE FOR COMPILING KODI-ARMBIAN
# (C) 2020 JMCC (JMCC@forum.armbian.com)

SET(CMAKE_SYSTEM_NAME Linux)
# Not necessary:
# SET(CMAKE_SYSTEM_VERSION 1)

# Specify Arch and ABI
if (NOT DEFINED ARCH)
  set(ARCH "arm")
# For arm64:
#   set(ARCH "aarch64")
endif ()
if (NOT DEFINED TARGET_ABI)
  set(TARGET_ABI "linux-gnueabihf")
# For arm64:
# set(TARGET_ABI "linux-gnu")
endif ()

# specify the cross compiler
SET(CMAKE_C_COMPILER   /usr/bin/${ARCH}-${TARGET_ABI}-gcc)
SET(CMAKE_CXX_COMPILER /usr/bin/${ARCH}-${TARGET_ABI}-g++)

# We need to set where the target environment containing
# the required library is. On Debian-like systems, this is
# /usr/arm-linux-gnueabihf/.
SET(CMAKE_FIND_ROOT_PATH "/usr/${ARCH}-${TARGET_ABI}")
# Ignore amd64 libs
SET(CMAKE_IGNORE_PATH "/usr/lib/x86_64-linux-gnu")


# Set additional variables
SET(CMAKE_LINKER        /usr/bin/${ARCH}-${TARGET_ABI}-ld       CACHE FILEPATH "linker")
SET(CMAKE_ASM_COMPILER  /usr/bin/${ARCH}-${TARGET_ABI}-as       CACHE FILEPATH "assembler")
SET(CMAKE_OBJCOPY       /usr/bin/${ARCH}-${TARGET_ABI}-objcopy  CACHE FILEPATH "objcopy")
SET(CMAKE_STRIP         /usr/bin/${ARCH}-${TARGET_ABI}-strip    CACHE FILEPATH "strip")
SET(CMAKE_CPP           /usr/bin/${ARCH}-${TARGET_ABI}-cpp      CACHE FILEPATH "cpp")

# Let cmakelists know we are cross-compiling
set(CMAKE_CROSSCOMPILING ON CACHE BOOL "Cross-compiling" FORCE)

