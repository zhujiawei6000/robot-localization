conan install . --build=missing --settings=build_type=Debug -pr linux_ubuntu_gcc11.4
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE="Debug/generators/conan_toolchain.cmake" -DCMAKE_BUILD_TYPE=Debug
cmake --build . --config Debug
