#ifndef _HTTPD_H___
#define _HTTPD_H___

#include <stdio.h>
#include <string.h>

// Запрос клиента
extern char *method, // "GET" or "POST"
    *uri,            // "/index.html" things before '?'
    *qs,             // "a=1&b=2" things after  '?'
    *prot,           // "HTTP/1.1"
    *payload,        // for POST
    *message_log;

extern int payload_size;


// Функции управления сервером
void serve_forever(const char *PORT);

char *request_header(const char *name);

typedef struct {
  char *name, *value;
} header_t;
static header_t reqhdr[17] = {{"\0", "\0"}};
header_t *request_headers(void);

// user shall implement this function пользователь должен реализовать эту функцию

void route();
// Response Ответ
#define RESPONSE_PROTOCOL "HTTP/1.1"

#define HTTP_200 printf("%s 200 OK\n\n", RESPONSE_PROTOCOL); sprintf(message_log, "%s 200", message_log)
#define HTTP_201 printf("%s 201 Created\n\n", RESPONSE_PROTOCOL); sprintf(message_log, "%s 201", message_log)
#define HTTP_404 printf("%s 404 Not found\n\n", RESPONSE_PROTOCOL); sprintf(message_log, "%s 404", message_log)
#define HTTP_500 printf("%s 500 Internal Server Error\n\n", RESPONSE_PROTOCOL); sprintf(message_log, "%s 500", message_log)

// some interesting macro for `route()` какой-нибудь интересный макрос для
#define ROUTE_START() if (0) {
#define ROUTE(METHOD, URI)                                                     \
  }                                                                            \
  else if (strcmp(URI, uri) == 0 && strcmp(METHOD, method) == 0) {
#define GET(URI) ROUTE("GET", URI)
#define POST(URI) ROUTE("POST", URI)
#define ROUTE_END()                                                            \
  }                                                                            \
  else HTTP_500;

#endif
