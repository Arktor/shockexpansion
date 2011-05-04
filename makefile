CC = g++
CFLAGS = -Wall -Werror -pedantic
INCLUDE = -I..
LIBS = -L


shockexpansion.exe: main.cpp solve_shock.cpp solve_expansion.cpp\
 shexpexception.cpp shexpnode.cpp shexppanel.cpp pass_empty_strings.cpp\
 get_token.cpp parse_density.cpp parse_mach_number.cpp parse_pressure.cpp\
 parse_problem_def.cpp parse_geometry_point.cpp parse_geometry.cpp\
 solver_out.cpp parser_out.cpp shexpnode.hpp shexppanel.hpp\
 shexpexception.hpp
	$(CC) -o shockexpansion.exe $(CFLAGS) shexpexception.cpp\
 shexpnode.cpp shexppanel.cpp pass_empty_strings.cpp get_token.cpp\
 parse_density.cpp parse_mach_number.cpp parse_pressure.cpp\
 parse_problem_def.cpp parse_geometry_point.cpp parse_geometry.cpp\
 main.cpp solve_shock.cpp solve_expansion.cpp solver_out.cpp\
 parser_out.cpp