/*********************************************************
 *           Created by manparvesh on 3/6/18.
 *********************************************************/

enum logging_level {
    ERROR,
    INFO,
    WARN
};


void LOG(enum logging_level level, char *file_name, const char *function_name, char *message){
#ifdef DEBUG
    switch (level) {
        case ERROR:
            fprintf(stderr, "%s#%s [ERROR]: %s", file_name, function_name, message);
            break;

        case INFO:
            printf("%s#%s [INFO]: %s", file_name, function_name, message);
            break;

        case WARN:
            fprintf(stderr, "%s#%s [WARN]: %s", file_name, function_name, message);
            break;
    }
#endif
}
