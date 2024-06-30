conan install . --build=missing --settings=build_type=Debug
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE="generators/conan_toolchain.cmake" -DCMAKE_BUILD_TYPE=Debug
cmake --build . --config Debug
