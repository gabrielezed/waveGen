# waveGen

Just a little program that generate a wave file from given frequencies.

Input:
You can write audio frequencies like this:
```
800.0 400.0 950.0
400.0
1200.0 800.0
800.0 723.5 
```

Usage example:
```
./waveGen -i file.txt -o dubstep.wav -a 16000 -s 44100 -n 4
```

Given command will produce a file named dubstep.wav generating audio with an amplitude of 16000, in a 44100Hz sample rate playing 4 notes every second from file.txt.


I implemented the RIFF/WAVE header that you can see on Wikipedia: https://en.wikipedia.org/wiki/WAV#WAV_file_header

The code need some cleaning.