CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lm

TARGET = waveGen

SRCS = main.c wav_header.c wav_sample_gen.c wav_file_gen.c parser.c cli_parser.c

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) signal.wav