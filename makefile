build:
	clang++ --std=c++23 -Wall -Wextra -Werror main.cpp -o out

run:
	clang++ --std=c++23 -Wall -Wextra -Werror main.cpp -o out && ./out