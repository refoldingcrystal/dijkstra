CFLAGS = -Wall -Wextra -std=c11
TARGET = dijkstra
OBJS = main.c graph.c dijkstra.c

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

run: $(TARGET)
	./$(TARGET) graph.txt 1 5
