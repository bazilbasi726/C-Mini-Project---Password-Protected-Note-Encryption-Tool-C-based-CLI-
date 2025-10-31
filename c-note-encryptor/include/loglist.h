#ifndef C_NOTE_ENCRYPTOR_LOGLIST_H
#define C_NOTE_ENCRYPTOR_LOGLIST_H

#include <stddef.h>

typedef struct LogNode {
    char message[128];
    struct LogNode *next;
} LogNode;

LogNode *loglist_append(LogNode *head, const char *message);
void loglist_print(const LogNode *head);
void loglist_free(LogNode *head);

#endif /* C_NOTE_ENCRYPTOR_LOGLIST_H */
