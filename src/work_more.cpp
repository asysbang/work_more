#include "work_more.h"
#include <unistd.h>  //包含了Linux C 中的函数getcwd()
#define FILEPATH_MAX (80)
using namespace std;
char* pwd;
int main(int argc, char *argv[]) {
    pwd=(char *)malloc(FILEPATH_MAX);
    getcwd(pwd,FILEPATH_MAX);
    printf("%s",pwd);
	initGui(argc,argv) ;
	return 0;
}

