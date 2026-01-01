#ifndef OSSL_DOWNGRADE_STORE_H
#define OSSL_DOWNGRADE_STORE_H

#include <openssl/ssl.h>

/* User-requested alert + reason numbers */
#define TLS1_AD_DOWNGRADE_DETECTED        169
#define SSL_R_TLS13_DOWNGRADE_DETECTED    1025

/* Structure stored in SSL_CTX ex_data */
typedef struct {
    int      last_version;
    uint32_t last_cipher_id;
    int      last_cipher_bits;
} DOWNGRADE_STORE;

/* Helper prototypes */
int get_downgrade_ex_index(void);
DOWNGRADE_STORE *ssl_ctx_get_store(SSL_CTX *ctx, int create);

#endif