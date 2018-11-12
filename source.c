// 2017030255_정찬우_System_programming

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
	// 실행파일 이름 외에 아무것도 입력되지 않은 경우에 대한 예외처리
	if(argc < 2) {
		printf("잘못된 입력입니다.\n");
		return 0;
	}
	// 입력된 첫 번째 단어가 ls가 아닌 경우에 대한 예외처리
	if(strcmp(argv[1], "ls")) {
		printf("잘못된 입력입니다.\n");
		return 0;
	}

	// argv[0]는 실행파일 이므로 argv[1]부터 넣는다.
	execv("/bin/ls", &(argv[1]));
	return 0;
}
