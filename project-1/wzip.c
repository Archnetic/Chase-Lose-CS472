#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	
	if(argc < 2){
		printf("wzip: file1 [file2 ...]\n");
		exit(1);
	}

	for(int i = 1; i < argc; i++){
		FILE *fp = fopen(argv[i], "rb");
		char prev = 0;
		char curr = 0;
		int count = 0;


		if(fp == NULL){
			printf("[%s] file does not exist, exiting program.. \n", argv[i]);
			exit(1);
		}
		while(1){
			curr = fgetc(fp);
			if(curr == EOF){
				if(count > 0){
					fwrite(&count, 1, 4, stdout);
					fwrite(&prev, 1, 1, stdout);
				}
				break;
			}
			if(curr != prev){
				if(count > 0){
					fwrite(&count, 1, 4, stdout);
					fwrite(&prev, 1, 1, stdout);
				}
				count = 0;
			}

			count++;
			prev = curr;
		}
		fclose(fp);
	}
	return 0;
}