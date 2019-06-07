/**
 * Author......: See docs/credits.txt
 * License.....: MIT
 */

#ifndef _HASHES_H
#define _HASHES_H

int sort_by_string       (const void *v1, const void *v2);
int sort_by_digest_p0p1  (const void *v1, const void *v2, void *v3);
int sort_by_salt         (const void *v1, const void *v2);
int sort_by_hash         (const void *v1, const void *v2, void *v3);
int sort_by_hash_no_salt (const void *v1, const void *v2, void *v3);

int hash_encode (const hashconfig_t *hashconfig, const hashes_t *hashes, const module_ctx_t *module_ctx, char *out_buf, const int out_size, const u32 salt_pos, const u32 digest_pos);

int save_hash (hashcat_ctx_t *hashcat_ctx);

void check_hash (hashcat_ctx_t *hashcat_ctx, hc_device_param_t *device_param, plain_t *plain);

int check_cracked (hashcat_ctx_t *hashcat_ctx, hc_device_param_t *device_param, const u32 salt_pos);

int hashes_init_filename  (hashcat_ctx_t *hashcat_ctx);
int hashes_init_stage1    (hashcat_ctx_t *hashcat_ctx);
void remove_dup_hash      (const hashconfig_t *hashconfig, hashes_t *hashes);
void set_new_esalt        (const hashconfig_t *hashconfig, hash_t *hashes_buf, void *esalts_buf_new, int pos);
void set_new_hooksalt     (const hashconfig_t *hashconfig, hash_t *hashes_buf, void *hook_salts_buf_new, int salts_cnt, int pos, int is_new);
void set_new_salt         (hash_t *hashes_buf, salt_t *salts_buf_new, salt_t **salt_buf, int salts_cnt, int pos);
void set_new_digest       (const hashconfig_t *hashconfig, hash_t *hashes_buf, void *digests_buf_new, int pos);
int hashes_init_stage2    (hashcat_ctx_t *hashcat_ctx);
int hashes_init_stage3    (hashcat_ctx_t *hashcat_ctx);
int hashes_init_stage4    (hashcat_ctx_t *hashcat_ctx);
int hashes_init_selftest  (hashcat_ctx_t *hashcat_ctx);
int hashes_init_benchmark (hashcat_ctx_t *hashcat_ctx);

void hashes_destroy (hashcat_ctx_t *hashcat_ctx);

void hashes_logger (hashcat_ctx_t *hashcat_ctx);

#endif // _HASHES_H
