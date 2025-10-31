#ifndef NOTE_LOGLIST_H
#define NOTE_LOGLIST_H

#include <stddef.h>

typedef struct LogNode {
    char message[128];
    struct LogNode *next;
} LogNode;

LogNode *log_append(LogNode *tail, const char *message);
void log_print(const LogNode *head);
void log_free(LogNode *head);

#endif /* NOTE_LOGLIST_H */
