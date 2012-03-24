/*
USER: fanzeyi1
LANG: C++
TASK: NKU 2197 Linux Shell
*/
/*
 * =====================================================================================
 * 
 *       Filename:  2197.cc
 *        Created:  2012年03月21日 04時07分32秒
 *       Compiler:  g++
 *         Author:  Zeray Rice, fanzeyi1994@gmail.com
 * 
 * =====================================================================================
 */
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#define MAX_NAME 255
#define MAX_FILE 1000
#define MAX_CHILD 1000
#define MAX_PATH 1000
#define MAX_ARGS 1000
#ifndef DEBUG
#define fin stdin
#define fout stdout
#endif
// CHOOSE CMD RETURN VALUE
#define CMD_NOTFOUND -1
#define CMD_CD 1
#define CMD_LS 2
#define CMD_RM 3
#define CMD_CAT 4
#define CMD_PWD 5
#define CMD_ECHO 6
#define CMD_MKDIR 7

// TODO: add /dev/null support to cat

typedef struct File {
    char name[MAX_NAME]; 
    char *content; 
    struct File *father; 
    struct File *child[MAX_CHILD]; 
    int child_count; 
    bool folder; 
} File; 

char PWD[MAX_PATH]; 
File *root; 
File *home; 
File *now; 

void strip(char *str) {
    if(!strlen(str)) {
        return; 
    }
    char *tmp = str; 
    while(*tmp == ' ') {
        tmp++; 
    }
    memcpy(str, tmp, strlen(tmp));
    str[strlen(tmp)] = '\0'; 
    tmp = &str[strlen(str)-1]; 
    while(*tmp == ' ') {
        tmp--; 
    }
    tmp++; 
    *tmp = '\0'; 
}

File *make_file(const char *name, char *content, File *father, bool folder) {
    File *p; 
    p = (File*)malloc(sizeof(File)); 
    memcpy(p->name, name, strlen(name)); 
    p->child_count = 0; 
    p->father = father; 
    p->folder = folder; 
    if(!folder) {
        p->content = (char*)calloc(sizeof(char), MAX_FILE); 
        memcpy(p->content, content, strlen(content)); 
    }
    return p; 
}

File *make_folder(const char *name, File *father) {
    return make_file(name, NULL, father, true); 
}

File *add_child(File *father, File *child) {
    if(father->child_count == 0) {
        father->child[father->child_count++] = child;
        return child; 
    }
    int check_p; 
    bool created = false; 
    // check first
    if(father->child_count) {
        check_p = strcmp(father->child[0]->name, child->name); 
        if(check_p == 0) {
            return child; 
        }
        if(check_p > 0)  {
            for(int j = father->child_count + 1; j > 0; j--) {
                father->child[j] = father->child[j-1]; 
            }
            father->child[0] = child; 
            created = true; 
        }else{
            for(int i = 1; i < father->child_count; i++) {
                check_p = strcmp(father->child[i]->name, child->name); 
                if(strcmp(father->child[i-1]->name, child->name) < 0 && check_p > 0) {
                    for(int j = father->child_count + 1; j > i; j--) {
                        father->child[j] = father->child[j-1]; 
                    }
                    father->child[i] = child; 
                    created = true; 
                    break; 
                }
            }
        }
    }
    if(!created) {
        father->child[father->child_count] = child; 
    }
    father->child_count = father->child_count + 1; 
    return child; 
}

void init_env() {
    // Make Root fs
    File *tmp; 
    root = make_folder("", NULL); 
    // Make Home Folder
    tmp = add_child(root, make_folder("home", root)); 
    // Make $HOME
    now = add_child(tmp, make_folder("user", tmp)); 
    memcpy(&PWD, "/home/user", strlen("/home/user")); 
    home = now; 
}

char *pwd_cmd() {
    // no args
    return PWD; 
}

void cd_cmd(char *argv, char *new_pwd, File *cd_path) {
    char filename[MAX_NAME] = {0}; 
    int fp = 0; 
    if(argv[0] == '.' && argv[1] == '.') {
        for(int i = strlen(new_pwd) - 1; i >= 0; i--) {
            if(new_pwd[i] == '/') {
                new_pwd[i] = '\0'; 
                break; 
            }
        }
        if(argv[3] == '\0'){
            memset(PWD, 0, strlen(PWD)); 
            memcpy(PWD, new_pwd, strlen(new_pwd)); 
            now = cd_path->father; 
            return; 
        } else {
            cd_cmd(&argv[3], new_pwd, cd_path->father); 
        }
        return; 
    }
    while(*argv != '/' && *argv != '\0') {
        filename[fp++] = *argv; 
        argv++; 
    }
    for(int i = 0; i < cd_path->child_count; i++) {
        if(strcmp(cd_path->child[i]->name, filename) == 0) {
            sprintf(new_pwd, "%s/%s", new_pwd, filename); 
            if(*argv != '\0') {
                argv++; 
                cd_cmd(argv, new_pwd, cd_path->child[i]); 
                break; 
            } else {
                now = cd_path->child[i]; 
                memset(PWD, 0, strlen(PWD)); 
                memcpy(PWD, new_pwd, strlen(new_pwd)); 
                return; 
            }
        }
    }
}

void parse_cd_cmd(char *argv) {
    char new_pwd[MAX_PATH] = {0}; 
    if(argv[0] == '/') {
        // abs path
        cd_cmd(&argv[1], new_pwd, root); 
    } else if (argv[0] == '~') {
        // expand $HOME
        memcpy(&new_pwd, "/home/user", strlen("/home/user")); 
        if(argv[1] == '/') {
            cd_cmd(&argv[2], new_pwd, home); 
        } else {
            // for `cd ~`
            memset(PWD, 0, strlen(PWD)); 
            memcpy(PWD, &new_pwd, strlen(new_pwd)); 
            now = home; 
            return; 
        }
    } else if(argv[0] == '.' && argv[1] == '.') {
        // last
        memcpy(&new_pwd, PWD, strlen(PWD)); 
        for(int i = strlen(new_pwd) - 1; i >= 0; i--) {
            if(new_pwd[i] == '/') {
                new_pwd[i] = '\0'; 
                break; 
            }
        }
        if(argv[3] == '\0'){
            memset(PWD, 0, strlen(PWD)); 
            memcpy(PWD, &new_pwd, strlen(new_pwd)); 
            now = now->father; 
            return; 
        } else {
            cd_cmd(&argv[3], new_pwd, now->father); 
        }
    } else {
        memcpy(&new_pwd, PWD, strlen(PWD)); 
        if(argv[0] == '.' && argv[1] == '/') {
            cd_cmd(&argv[2], new_pwd, now); 
        } else {
            cd_cmd(&argv[0], new_pwd, now); 
        }
    }
}

char *ls_cmd() {
    char *result = (char*)malloc(sizeof(char) * MAX_PATH); 
    for(int i = 0; i < now->child_count; i++) {
        if(i == 0) {
            sprintf(result, "%s", now->child[i]->name); 
        } else {
            sprintf(result, "%s  %s", result, now->child[i]->name); 
        }
    }
    return result; 
}

char *echo_cmd(char *argv) {
    return argv; 
}

char *cat_cmd(char *argv) {
    for(int i = 0; i < now->child_count; i++) {
        if(now->child[i]->folder == false && strcmp(now->child[i]->name, argv) == 0) {
            return now->child[i]->content; 
        }
    }
}

File *mkdir_cmd(char *argv) {
    if(argv[0] == '\0') {
        return NULL; 
    }
    return add_child(now, make_folder(argv, now)); 
}

void rm_recursive(File *here) {
    for(int i = 0; i < here->child_count; i++) {
        if(here->child[i]->folder) {
            rm_recursive(here->child[i]); 
        }
        free(here->child[i]); 
    }
}

void rm_cmd(char *argv, bool recursive = false) {
    for(int i = 0; i < now->child_count; i++) {
        if(strcmp(now->child[i]->name, argv) == 0) {
            if(now->child[i]->folder && recursive) {
                // if folder 
                rm_recursive(now->child[i]); 
                free(now->child[i]); 
            } else if(!now->child[i]->folder){
                // if file
                free(now->child[i]); 
            }
            for(int j = i; j < now->child_count; j++) {
                now->child[j] = now->child[j+1]; 
            }
            now->child_count = now->child_count - 1; 
        }
    }
    return; 
}

int choose_cmd(char *cmd) {
    size_t len = strlen(cmd); 
    switch(len) {
        case 2:
            // `cd` / `ls` / `rm`
            if(cmd[0] == 'c' && cmd[1] == 'd') {
                return CMD_CD; 
            }
            if(cmd[0] == 'l' && cmd[1] == 's') {
                return CMD_LS; 
            }
            if(cmd[0] == 'r' && cmd[1] == 'm') {
                return CMD_RM; 
            }break; 
        case 3:
            // `cat` / `pwd`
            if(cmd[0] == 'c' && cmd[1] == 'a' && cmd[2] == 't') {
                return CMD_CAT; 
            }
            if(cmd[0] == 'p' && cmd[1] == 'w' && cmd[2] == 'd') {
                return CMD_PWD; 
            }break; 
        case 4:
            // `echo`
            if(cmd[0] == 'e' && cmd[1] == 'c' && cmd[2] == 'h' && cmd[3] == 'o') {
                return CMD_ECHO; 
            }break; 
        case 5:
            // `mkdir`
            if(cmd[0] == 'm' && cmd[1] == 'k' && cmd[2] == 'd' && cmd[3] == 'i' && cmd[4] == 'r') {
                return CMD_MKDIR; 
            }break; 
    }
    return CMD_NOTFOUND; 
}

void parse_output(char *output, char *outputfilename, bool out_add) {
    bool created; 
    if(strcmp(outputfilename, "/dev/stdout") == 0) {
        fprintf(stdout, "%s\n", output); 
    }else if(strcmp(outputfilename, "/dev/null") == 0) {
        // output to null
    }else if(outputfilename[0] != '\0') {
        // output to file
        created = false; 
        for(int i = 0; i < now->child_count; i++) {
            if(!now->child[i]->folder && strcmp(outputfilename, now->child[i]->name) == 0) {
                if(out_add) {
                    // for >> 
                    now->child[i]->content[strlen(now->child[i]->content)] = '\n'; 
                    memcpy(&now->child[i]->content[strlen(now->child[i]->content)], output, strlen(output)); 
                    created = true; 
                } else {
                    // for >
                    memset(now->child[i]->content, 0, strlen(now->child[i]->content)); 
                    memcpy(now->child[i]->content, output, strlen(output)); 
                    created = true; 
                }
            }
        }
        if(!created) {
            add_child(now, make_file(outputfilename, output, now, false)); 
        }
    }else{
        fprintf(stdout, "%s\n", output); 
    }
}

void parse_cmd(char *input_line) {
    char cmd[6] = {0}; 
    char args[MAX_ARGS] = {0}; 
    char inputfilename[MAX_NAME] = {0};
    char outputfilename[MAX_NAME] = {0}; 
    char *output; 
    bool out_add = false; 
    int p = 0; 
    while(*input_line != ' ' && *input_line != '\0') {
        cmd[p++] = *input_line; 
        input_line++; 
    }
    p = 0; 
    input_line++; 
    while(*input_line != '\0' && *input_line != '<' && *input_line != '>')  {
        if(*input_line == '\\') {
            input_line++; 
        }
        args[p++] = *input_line++; 
    }
    p = 0; 
    while(*input_line != '\0') {
        if(*input_line == '\\') {
            input_line++; 
        }
        if(*input_line == '>') {
            input_line++; 
            if(*input_line == '>') {
                // for >> 
                input_line++; 
                out_add = true; 
            }
            p = 0; 
            while(*input_line != '<' && *input_line != '\0') {
                if(*input_line == '\\') {
                    input_line++; 
                }
                outputfilename[p++] = *input_line++; 
            }
        }
        if(*input_line == '<') {
            input_line++; 
            p = 0; 
            while(*input_line != '\0' && *input_line != '>') {
                if(*input_line == '\\') {
                    input_line++; 
                }
                inputfilename[p++] = *input_line++; 
            }
        }
        input_line++; 
    }
    strip(cmd); 
    strip(inputfilename); 
    strip(outputfilename); 
    strip(args); 
    switch(choose_cmd(cmd)) {
        case CMD_LS:
            // cmd `ls` 
            // output only; 
            output = ls_cmd();
            parse_output(output, outputfilename, out_add); 
            break; 
        case CMD_CD:
            // cmd `cd`
            // no input/output 
            parse_cd_cmd(args); 
            break; 
        case CMD_RM:
            rm_cmd(args); 
            break; 
        case CMD_CAT:
            // cmd `cat`
            // input & output
            // inputfile if not args else args
            if(strcmp(args, "/dev/null") == 0) {
                output = ""; 
            }else if(args[0] != '\0') {
                output = cat_cmd(args); 
            }else{
                output = cat_cmd(inputfilename); 
            }
            parse_output(output, outputfilename, out_add); 
            break; 
        case CMD_PWD:
            // cmd `pwd`
            // output only
            output = pwd_cmd(); 
            parse_output(output, outputfilename, out_add); 
            break; 
        case CMD_ECHO:
            // cmd `echo`
            // output only
            output = echo_cmd(args); 
            parse_output(output, outputfilename, out_add); 
            break; 
        case CMD_MKDIR:
            // cmd `mkdir`
            // no input/output
            mkdir_cmd(args); 
            break; 
    }
#ifdef DEBUGA
    printf("Input: %s\n", origin); 
    printf("Call command: %s\n", cmd); 
    printf("Args: %s\n", args); 
    printf("Input filename: %s\n", inputfilename); 
    printf("Output filename: %s\n", outputfilename); 
    printf("Output Add? : %d\n", out_add); 
#endif
}

int main() {
#ifdef DEBUG
    FILE *fin = fopen("2197.in", "r"); 
    FILE *fout = fopen("2197.out", "w"); 
#endif
    char cmd[10000]; 
    init_env(); 
    while(gets(cmd)) {
        parse_cmd(cmd); 
        memset(cmd, 0, strlen(cmd)); 
    }
    return 0; 
}
