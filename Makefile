# Usage:
# make        # compile all binary
# make clean  # remove ALL binaries and objects

.PHONY = all clean

# name of the executable
EXEC = main

# compiler to use
COMPILER = g++

# flags to pass to the compiler
CFLAGS = -c -Wall

# source directory
SRCDIR = src
# object directory
OBJDIR = obj

# get all the source files
SRCS := $(wildcard $(SRCDIR)/*.cpp)
# get all the object files
OBJS := $(notdir $(SRCS:.cpp=.o)) 
# get all the object file paths
OFILES := $(addprefix $(OBJDIR)/, $(OBJS))

$(EXEC): ${OFILES}
	@echo "Linking to ${EXEC}.."
	${COMPILER} -o ${EXEC} $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@echo "+ $@ ($<)"
	@${COMPILER} ${CFLAGS} $<
	@mv -f $(notdir $@) $@


clean:
	@echo "Cleaning up objects..."
	@rm -f -v $(OBJDIR)/*.o
	@echo "Cleaning up executable..."
	@rm -f -v ${EXEC}

run:${EXEC}
	@echo "Running ${EXEC}"
	@./${EXEC}