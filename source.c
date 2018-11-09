// 2017030255_정찬우_System_programming

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
	char s[1000];	// 입력받을 char[]
	char *arg[4];	// ls, option, path
	printf("Enter a command: ");
	fgets(s, sizeof(s), stdin);	// line 단위로 입력

	char *str = strtok(s, " \n");	// 예상 문자열: ls, 공백과 줄바꿈을 기준으로 구분
	strcpy(arg[0], str);
	
	// 입력된 첫 번째 단어가 ls가 아닌 경우에 대한 예외처리
	if(arg[0][0] != 'l' || arg[0][1] != 's') {
		printf("잘못된 입력입니다.\n");
		return 0;
	}

	str = strtok(NULL, " \n");	// 예상 문자열: [option] or [path]
	
	int i = 0;
	while(str != NULL){
		i++;
		
		// 입력된 단어의 개수가 3개 이상인 경우에 대한 예외처리
		if(i == 3){
			printf("잘못된 입력입니다.\n");
			return 0;
		}
		strcpy(arg[i], str);
		str = strtok(NULL, " \n");
	}
	
	// 입력된 단어가 1개이며, ls 일 경우
	if(i == 0) {
		arg[1] = (char*)0;
		execv("/bin/ls", arg);
		return 0;
	}

	// 입력된 두 번째 단어가 [option]일 경우
	else if(arg[1][0] == '-'){

		// 입력된 단어가 2개이며, ls [option]일 경우
		if(i == 1){
			arg[2] = (char*)0;
			execv("/bin/ls", arg);
			return 0;
		}

		// 입력된 단어가 3개이며, ls [option] [path]일 경우
		else{
			arg[3] = (char*)0;
			execv("/bin/ls", arg);
			return 0;
		}
	}

	// 입력된 단어가 2개이며, ls [path]일 경우
	else {
		arg[2] = (char*)0;
		execv("/bin/ls", arg);
		return 0;
	}

	return 0;
}

