#include "fcgiapp.h"

int main() {
    FCGX_Init();
    FCGX_Request req;
    int sockfd = FCGX_OpenSocket("127.0.0.1:8080", 0);
    FCGX_InitRequest(&req, sockfd, 0);
    while (FCGX_Accept_r(&req) >= 0) {
        FCGX_FPrintF(req.out, "Content-Type: text/html\n\n");
        FCGX_FPrintF(req.out, "Hello World!");
        FCGX_Finish_r(&req);
    }
    return 0;
}
