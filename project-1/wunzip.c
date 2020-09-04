#include<stdio.h>
#include<stdlib.h>
//fails at test 3. (fixed, caused by a failed print statement)
int main(int argc, char *argv[]){
	char curr = 0;
	int count = 0;
	if(argc < 2){
		printf("wunzip: file1 [file2 ...]\n");
		exit(1);
	}
	for(int i = 1; i<argc; i++){
		FILE *fp = fopen(argv[i], "r");

	if(fp == NULL) {
		printf("[%s] file does not exist \n", argv[i]);
		exit(1);
	}
	while(1){
		int bytes = fread(&count, 1, 4, fp);
		if(bytes != 4){
			break;
		}
		fread(&curr, 1, 1, fp);{
			for(int i = 0; i < count; i++){
				fwrite(&curr, 1, 1, stdout);
			}
		}
	}
	fclose(fp);
	}
	return 0;
}