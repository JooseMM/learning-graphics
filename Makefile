CC = gcc
CFLAGS = -Wall -g $(shell sdl2-config --cflags)
LDFLAGS = $(shell sdl2-config --libs)

TARGET = ./target/program
OBJDIR = ./target

SOURCES = main.c window/window.c controllers/controllers.c draw/draw.c
OBJECTS = $(SOURCES:.c=.o)
OBJECTS := $(addprefix $(OBJDIR)/, $(OBJECTS))

all: $(TARGET)

# Ensure output directory exists and link object files
$(TARGET): $(OBJECTS)
	@mkdir -p $(dir $@)
	$(CC) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

# Compile source files to target directory
$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

run: 
	$(TARGET)

