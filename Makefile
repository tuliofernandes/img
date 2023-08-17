CC = gcc
CFLAGS = -Wall `pkg-config --cflags gtk+-3.0`
LDFLAGS = `pkg-config --libs gtk+-3.0`
TARGET = img
SRC = main.c
DESKTOP_FILE = img.desktop

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

install: $(TARGET)
	install -m 755 $(TARGET) /usr/local/bin
	install -m 644 $(DESKTOP_FILE) /usr/share/applications

clean:
	rm -f $(TARGET)
