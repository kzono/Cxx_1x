TARGET = hello

# Directories
SRCDIR = ./srcs
OBJDIR = ./objs

SRCS = $(wildcard ${SRCDIR}/*.cpp)
OBJS = $(addprefix ${OBJDIR}/, $(notdir $(SRCS:.cpp=.o)))
DEPS = $(addprefix ${OBJDIR}/, $(notdir $(SRCS:.cpp=.d)))

# for preprocesser
INCLUDES =
CPPFLAGS =

# for C++ compiler
CXX = g++
CXXFLAGS = -g -Wall -MMD -MP

# for linker
LD = ${CXX}
LIBDIRS =
LIBS =
LDFLAGS = ${LIBDIRS} ${LIBS}

all: ${TARGET}

${TARGET}: ${OBJS}
	${LD} -o $@ $^ ${LDFLAGS}

${OBJDIR}/%.o: ${SRCDIR}/%.cpp
	if [ ! -d ${OBJDIR} ]; then \
		mkdir ${OBJDIR}; \
	fi
	@ [ -d ${OBJDIR} ]
	${CXX} ${CXXFLAGS} -o $@ -c $<

.PHONY: all clean

clean:
	${RM} ${TARGET} ${OBJS} ${DEPS}

-include ${DEPS}
