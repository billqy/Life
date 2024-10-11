A computer simulation created to showcase emergent phenomena amongst thousands of particles that replicate life at its lowest levels with only simple attractive forces.

Uses the open-source Raylib and Raygui libraries for shape rendering. Written in C.

Note: main.exe is compiled for 64-bit Windows computers

Compiling for windows:\
```gcc main.c quark.c controlUI.c -o Life.exe -O3 -Wall -std=c99 -Wno-missing-braces -I include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm```

<img width="511" alt="Banner" src="https://github.com/user-attachments/assets/961d3abc-e853-4ba6-8b62-34671b725921">
