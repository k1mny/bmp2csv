#include "bitmap.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX_WIDTH 128
#define MAX_HEIGHT 128

int main(int argc, char *argv[])
{
	if(argc != 3){
		fprintf(stderr, "Usage: program <inputfile> <outputfile>\n");
		exit(1);
	}

	Image *colorimg;
	FILE *fp;

	fp = fopen(argv[2], "w");
  	if(fp == NULL){
    	printf("%sファイルが開けません¥n", argv[2]);
    	exit(1);
  	}

	if((colorimg = Read_Bmp(argv[1])) == NULL){
		exit(1);
	}

	printf("width:%d height:%d\n", colorimg->width, colorimg->height);
	
	if(colorimg->width <= MAX_WIDTH && colorimg->height <= MAX_HEIGHT) {
		int i, j;

		for (int i = 0; i < MAX_WIDTH; ++i) {
			fprintf(fp,"{");
			for (int j = 0; j < MAX_HEIGHT; ++j) {
				fprintf(fp,"%d", colorimg->data[(MAX_HEIGHT-j-1)*MAX_WIDTH + i].r);
				fprintf(fp,"%d", colorimg->data[(MAX_HEIGHT-j-1)*MAX_WIDTH + i].g);
				if(j + 1 == MAX_WIDTH)	fprintf(fp,"%d", colorimg->data[(MAX_HEIGHT-j-1)*MAX_WIDTH + i].b);
				else	fprintf(fp,"%d,", colorimg->data[(MAX_HEIGHT-j-1)*MAX_WIDTH + i].b);
			}
			fprintf(fp,"},\n");
		}

	} else {
		printf("画像のサイズは128×128以下にしてください\n");
	}

	Free_Image(colorimg);

	return 0;
}

