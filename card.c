#define LINE_LEN 19
#define CARD_LEN 16
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void remove_spaces(char* s) {
    const char* d = s;
    do {
        while (*d == ' ') {
            ++d;
        }
    } while (*s++ = *d++);
}
int charToInt(char c){

return c - '0';
}
int check(char *card){
	int i;
	int sum=0;
	int temp=0;
	char tmp[2];
	for(i=CARD_LEN-1;i>=0;i--){
		temp=charToInt(*(card+i));
		if(i%2==0){
			temp*=2;
			if(temp>9){
				sprintf(tmp, "%d", temp);
				temp=0;
				temp+=charToInt(tmp[0]);
				temp+=charToInt(tmp[1]);
			}
		}
		sum+=temp;
	}
	if(sum%10==0){
		return 1;
	}
	return 0;
}
int main(){
	char *s=(char*)(malloc(LINE_LEN));

	FILE *fp = fopen("kartlar.txt", "r");
      if(fp == NULL) {
          perror("Unable to open file!");
          exit(1);
      }
 
     char chunk[128];

     while(fgets(chunk, sizeof(chunk), fp) != NULL) {
         strncpy(s,chunk,LINE_LEN);
         remove_spaces(s);
         chunk[strcspn(chunk, "\n")] = 0;
         printf("Kart: %s - ",chunk);
         if(check(s)){
         	printf("Gecerli.\n");
		 }
		 else{
		 	printf("Gecersiz.\n");
		 }
    }
    fclose(fp);
	free(s);
	return 0;
}
