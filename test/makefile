CC = g++
CFLAGS = -Wall -Werror -pedantic
INCLUDE = -I..
LIBS = -L


parser_test.exe: parser_test.cpp ../shexpexception.cpp ../shexpnode.cpp\
 ../shexppanel.cpp ../pass_empty_strings.cpp ../get_token.cpp\
 ../parse_density.cpp ../parse_mach_number.cpp ../parse_pressure.cpp\
 ../parse_problem_def.cpp ../parse_geometry_point.cpp ../parse_geometry.cpp\
 ../shexpnode.hpp ../shexppanel.hpp ../shexpexception.hpp
	$(CC) -o parser_test.exe $(CFLAGS) ../shexpexception.cpp\
 ../shexpnode.cpp ../shexppanel.cpp ../pass_empty_strings.cpp ../get_token.cpp\
 ../parse_density.cpp ../parse_mach_number.cpp ../parse_pressure.cpp\
 ../parse_problem_def.cpp ../parse_geometry_point.cpp ../parse_geometry.cpp\
  parser_test.cpp