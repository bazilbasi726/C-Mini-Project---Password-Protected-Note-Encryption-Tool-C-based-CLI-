#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "loglist.h"

LogNode *loglist_append(LogNode *head, const char *message) {
    LogNode *node = (LogNode *)malloc(sizeof(LogNode));
    if (!node) {
        return head;
    }

    strncpy(node->message, message, sizeof(node->message) - 1);
    node->message[sizeof(node->message) - 1] = '\0';
    node->next = NULL;

    if (!head) {
        return node;
    }

    LogNode *tail = head;
    while (tail->next) {
        tail = tail->next;
    }
    tail->next = node;
    return head;
}

void loglist_print(const LogNode *head) {
    const LogNode *current = head;
    while (current) {
        puts(current->message);
        current = current->next;
    }
}

void loglist_free(LogNode *head) {
    LogNode *current = head;
    while (current) {
        LogNode *next = current->next;
        free(current);
        current = next;
    }
#include "loglist.h"

void log_event(const char *message) {
    (void)message;
}
