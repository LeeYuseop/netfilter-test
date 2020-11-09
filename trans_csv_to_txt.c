#include <stdio.h>
#include <string.h>

char str[10000];

int main(int argc, char **argv)
{
    int i, cnt=-1;

    if(argc < 3){
        printf("Syntax Error!\n");
        return 0;
    }

    FILE *in, *out;
    in = fopen(argv[1], "r");
    out = fopen(argv[2], "w");
    if(argc >= 4) cnt = atoi(argv[3]);
    printf("%d %d\n", argc, cnt);

    while(fscanf(in, "%s", str) != EOF && cnt){
        for(i=0; str[i] != '\0' && str[i] != ','; i++);
        if(str[i] == '\0')
            continue;
        fprintf(out, "%s\n", str+i+1);
        cnt--;
    }

    printf("success to translate\n");

    return 0;
}