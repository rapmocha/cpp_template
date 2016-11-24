COMPILER  = g++
CFLAGS    = -g -MMD -MP -Wall -Wextra -Winit-self \
						-Wno-missing-field-initializers -std=c++11

ifeq "$(shell getconf LONG_BIT)" "64"
	LDFLAGS = `pkg-config --libs opencv` \
						-lboost_filesystem-mt \
						-lboost_system-mt
else
	LDFLAGS =
endif
#
# LIBS      = /usr/local/lib/libboost*-mt.a
LIBS = 
INCLUDE   = -I./include \
						-I/usr/local/include \
						-I/usr/local/lib/ \
						`pkg-config --cflags opencv`
PROJNAME = $(shell basename `pwd`)
TARGET    = ./bin/$(PROJNAME)
SRCDIR    = ./source
ifeq "$(strip $(SRCDIR))" ""
	SRCDIR  = .
endif
SOURCES   = $(wildcard $(SRCDIR)/*.cpp)
OBJDIR    = ./obj
ifeq "$(strip $(OBJDIR))" ""
	OBJDIR  = .
endif
OBJECTS   = $(addprefix $(OBJDIR)/, $(notdir $(SOURCES:.cpp=.o)))
DEPENDS   = $(OBJECTS:.o=.d)

$(TARGET): $(OBJECTS) $(LIBS)
	$(COMPILER) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	-mkdir -p $(OBJDIR)
	$(COMPILER) $(CFLAGS) $(INCLUDE) -o $@ -c $<

all: clean $(TARGET)

clean:
	-rm -f $(OBJECTS) $(DEPENDS) $(TARGET)

run:
	./bin/$(PROJNAME)

-include $(DEPENDS)
