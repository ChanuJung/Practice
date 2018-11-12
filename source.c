// 2017030255_정찬우_System_programming

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
	// 아무것도 입력되지 않았을 때.	
	if(argc < 2) {
		printf("잘못된 입력입니다.\n");
		return 0;
	}
	// 입력된 첫 번째 단어가 ls가 아닌 경우에 대한 예외처리
	if(strcmp(argv[1], "ls")) {
		printf("잘못된 입력입니다.\n");
		return 0;
	}

	execv("/bin/ls", &(argv[1]));
	return 0;
}
