#include <stdio.h>
int multiplyby8(int a){
	return a * 8;
}
int main(){
	int a = 12;
	int b =	multiplyby8(a);
	printf("%d \n", b);
	return 0;
}
