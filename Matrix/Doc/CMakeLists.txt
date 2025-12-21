include_directories(../Lib)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -O0 -g")
add_executable(MatrixCalculate main.c function.c)