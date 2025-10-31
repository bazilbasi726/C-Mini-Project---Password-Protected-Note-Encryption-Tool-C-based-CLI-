#include "loglist.h"

LogNode *log_append(LogNode *tail, const char *message) {
    (void)tail;
    (void)message;
    return NULL;
}

void log_print(const LogNode *head) {
    (void)head;
}

void log_free(LogNode *head) {
    (void)head;
}
