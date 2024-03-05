if exist build\ (
  cd build
) else (
  mkdir build && cd build
)
cmake ..
cmake --build .
ctest
cd ..