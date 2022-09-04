// author: Siddharthan Praaksh

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void populate_sandpile(int arr[23][23], int argc, char *argv[], int init) {
    int i, j;
    int r, c, v;
    for(i = 0; i < 23; i++) {
        for(j = 0; j < 23; j++) {
            arr[i][j] = 0;
        }
    }
    
    while(init < argc - 1) {
        r =  atoi(argv[++init]);
        c =  atoi(argv[++init]);
        v =  atoi(argv[++init]);
        arr[r][c] = v;
    }
}

void print_sandpile(int arr[23][23]) {
    int i, j;
    for(i = 0; i < 23; i++) {
        for(j = 0; j < 23; j++) {
            if(arr[i][j] == -1) {
                printf("# ");
            }
            else {
                printf("%d ", arr[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void sand_spil(int arr[23][23], int i, int j) {
    if(arr[i][j] <= 8) {
        return;
    }
    else {
        int l, m;
        arr[i][j] -= 8;
        for(l = -1; l <= 1; l++) {
            for(m = -1; m <= 1; m++) {
                //if current block, sink or out of bounds then skip
                if((l == 0 && m == 0) || arr[i + l][j + m] == -1 || i + l >= 23 || j + m >= 23 || i + l < 0 || j + m < 0) {
                    continue;
                }
                else {
                    arr[i + l][j + m]++;
                }
            }
        }

        for(l = -1; l <= 1; l++) {
            for(m = -1; m <= 1; m++) {
                //if current block, sink or out of bounds then skip
                if((l == 0 && m == 0) || arr[i + l][j + m] == -1 || i + l >= 23 || j + m >= 23 || i + l < 0 || j + m < 0) {
                    continue;
                }
                else {
                    sand_spil(arr, i + l, j + m);
                }
            }
        }
        
    }
}

void add_sand(int arr[23][23], int fps) {
    int i;

    if(arr[11][11] > 8) {
        sand_spil(arr, 11, 11);
    }

    for(i = 0; i < 100; i++) {
    // while(i) {
        unsigned int mSec = fps;
        usleep(mSec);
        print_sandpile(arr);
        arr[11][11]++;
        if(arr[11][11] > 8) {
            sand_spil(arr, 11, 11);
        }
    }

}

int main(int argc, char *argv[]) {
    int arr[23][23];
    int fps, i;

    fps = 1000000;
    i = 0;
    if(argc > 2) {
        if(strcmp(argv[1], "--fps") == 0) {
            fps = 1000000 / (atoi(argv[2]));
            i = 2;
        }
    }

    populate_sandpile(arr, argc, argv, i);

    if(arr[11][11] == -1) {
        printf("Sink at the center is invalid");
        return -1;
    }

    add_sand(arr, fps);

    return 0;
}