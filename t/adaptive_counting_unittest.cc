#include "ccard_common.h"
#include "adaptive_counting.h"
#include "gtest/gtest.h"

/**
 * Tests estimate.
 *
 * <p>
 * From 1 to 500000 distinct elements print estimated value every 50000.
 * Use AdaptiveCounting and LogLogCounting algorithm
 * </p>
 * */
TEST(AdaptiveCounting, RawCounting)
{
    int rc;
    int64_t i, esti;
    adp_cnt_ctx_t *ctx1 = adp_cnt_raw_init(NULL, 16, CCARD_HASH_LOOKUP3);
    EXPECT_NE(ctx1, (adp_cnt_ctx_t *)NULL);
    adp_cnt_ctx_t *ctx2 = adp_cnt_raw_init(NULL, 16, CCARD_HASH_MURMUR);
    EXPECT_NE(ctx2, (adp_cnt_ctx_t *)NULL);

    printf("Adaptive Counting with Lookup3hash:\n");
    for (i = 1; i <= 500000L; i++) {
        rc = adp_cnt_offer(ctx1, &i, sizeof(int64_t));
        EXPECT_GE(rc, 0);

        if (i % 50000 == 0) {
            esti = adp_cnt_card(ctx1);
            EXPECT_GT(esti, 0);
            printf("actual: %9lu, estimated: %9lu, error: %+7.2f%%\n",
                   (long unsigned int)i, (long unsigned int)esti, (double)(esti - i) / i * 100);
        }
    }
    printf("\n");

    rc = adp_cnt_reset(ctx1);
    EXPECT_EQ(rc, 0);

    printf("Loglog Counting with Lookup3hash:\n");
    for (i = 1; i <= 500000L; i++) {
        rc = adp_cnt_offer(ctx1, &i, sizeof(int64_t));
        EXPECT_GE(rc, 0);

        if (i % 50000 == 0) {
            esti = adp_cnt_card_loglog(ctx1);
            EXPECT_GT(esti, 0);
            printf("actual: %9lu, estimated: %9lu, error: %+7.2f%%\n",
                   (long unsigned int)i, (long unsigned int)esti, (double)(esti - i) / i * 100);
        }
    }
    printf("\n");

    printf("Adaptive Counting with Murmurhash:\n");
    for (i = 1; i <= 500000L; i++) {
        rc = adp_cnt_offer(ctx2, &i, sizeof(int64_t));
        EXPECT_GE(rc, 0);

        if (i % 50000 == 0) {
            esti = adp_cnt_card(ctx2);
            EXPECT_GT(esti, 0);
            printf("actual: %9lu, estimated: %9lu, error: %+7.2f%%\n",
                   (long unsigned int)i, (long unsigned int)esti, (double)(esti - i) / i * 100);
        }
    }
    printf("\n");

    rc = adp_cnt_reset(ctx2);
    EXPECT_EQ(rc, 0);

    printf("Loglog Counting with Murmurhash:\n");
    for (i = 1; i <= 500000L; i++) {
        rc = adp_cnt_offer(ctx2, &i, sizeof(int64_t));
        EXPECT_GE(rc, 0);

        if (i % 50000 == 0) {
            esti = adp_cnt_card_loglog(ctx2);
            EXPECT_GT(esti, 0);
            printf("actual: %9lu, estimated: %9lu, error: %+7.2f%%\n",
                   (long unsigned int)i, (long unsigned int)esti, (double)(esti - i) / i * 100);
        }
    }
    printf("\n");

    rc = adp_cnt_fini(ctx2);
    EXPECT_EQ(rc, 0);
    rc = adp_cnt_fini(ctx1);
    EXPECT_EQ(rc, 0);
}

/**
 * Tests estimate.
 *
 * <p>
 * From 1 to 500000 distinct elements print estimated value every 50000.
 * Use AdaptiveCounting and LogLogCounting algorithm
 * </p>
 * */
TEST(AdaptiveCounting, Counting)
{
    int rc;
    int64_t i, esti;
    adp_cnt_ctx_t *ctx1 = adp_cnt_init(NULL, 16, CCARD_HASH_LOOKUP3);
    EXPECT_NE(ctx1, (adp_cnt_ctx_t *)NULL);
    adp_cnt_ctx_t *ctx2 = adp_cnt_init(NULL, 16, CCARD_HASH_MURMUR);
    EXPECT_NE(ctx2, (adp_cnt_ctx_t *)NULL);

    printf("Adaptive Counting with Lookup3hash:\n");
    for (i = 1; i <= 500000L; i++) {
        rc = adp_cnt_offer(ctx1, &i, sizeof(int64_t));
        EXPECT_GE(rc, 0);

        if (i % 50000 == 0) {
            esti = adp_cnt_card(ctx1);
            EXPECT_GT(esti, 0);
            printf("actual: %9lu, estimated: %9lu, error: %+7.2f%%\n",
                   (long unsigned int)i, (long unsigned int)esti, (double)(esti - i) / i * 100);
        }
    }
    printf("\n");

    rc = adp_cnt_reset(ctx1);
    EXPECT_EQ(rc, 0);

    printf("Loglog Counting with Lookup3hash:\n");
    for (i = 1; i <= 500000L; i++) {
        rc = adp_cnt_offer(ctx1, &i, sizeof(int64_t));
        EXPECT_GE(rc, 0);

        if (i % 50000 == 0) {
            esti = adp_cnt_card_loglog(ctx1);
            EXPECT_GT(esti, 0);
            printf("actual: %9lu, estimated: %9lu, error: %+7.2f%%\n",
                   (long unsigned int)i, (long unsigned int)esti, (double)(esti - i) / i * 100);
        }
    }
    printf("\n");

    printf("Adaptive Counting with Murmurhash:\n");
    for (i = 1; i <= 500000L; i++) {
        rc = adp_cnt_offer(ctx2, &i, sizeof(int64_t));
        EXPECT_GE(rc, 0);

        if (i % 50000 == 0) {
            esti = adp_cnt_card(ctx2);
            EXPECT_GT(esti, 0);
            printf("actual: %9lu, estimated: %9lu, error: %+7.2f%%\n",
                   (long unsigned int)i, (long unsigned int)esti, (double)(esti - i) / i * 100);
        }
    }
    printf("\n");

    rc = adp_cnt_reset(ctx2);
    EXPECT_EQ(rc, 0);

    printf("Loglog Counting with Murmurhash:\n");
    for (i = 1; i <= 500000L; i++) {
        rc = adp_cnt_offer(ctx2, &i, sizeof(int64_t));
        EXPECT_GE(rc, 0);

        if (i % 50000 == 0) {
            esti = adp_cnt_card_loglog(ctx2);
            EXPECT_GT(esti, 0);
            printf("actual: %9lu, estimated: %9lu, error: %+7.2f%%\n",
                   (long unsigned int)i, (long unsigned int)esti, (double)(esti - i) / i * 100);
        }
    }
    printf("\n");

    rc = adp_cnt_fini(ctx2);
    EXPECT_EQ(rc, 0);
    rc = adp_cnt_fini(ctx1);
    EXPECT_EQ(rc, 0);
}

/**
 * Tests serialize, unserialize and merge.
 *
 * <ol>
 * <li>Current context contains 1 to 20000</li>
 * <li>Tbm1 that contains 10000 to 30000 be serialized as buf1</li>
 * <li>Tbm2 that contains 20000 to 40000 be serialized as buf2</li>
 * <li>Merges buf1 and buf2 into current context</li>
 * </ol>
 * */
TEST(AdaptiveCounting, RawMerge)
{
    int rc;
    int64_t i, esti;
    adp_cnt_ctx_t *ctx = adp_cnt_raw_init(NULL, 16, CCARD_HASH_LOOKUP3);
    EXPECT_NE(ctx, (adp_cnt_ctx_t *)NULL);
    adp_cnt_ctx_t *tbm1 = adp_cnt_raw_init(NULL, 16, CCARD_HASH_LOOKUP3);
    EXPECT_NE(tbm1, (adp_cnt_ctx_t *)NULL);
    adp_cnt_ctx_t *tbm2 = adp_cnt_raw_init(NULL, 16, CCARD_HASH_LOOKUP3);
    EXPECT_NE(tbm2, (adp_cnt_ctx_t *)NULL);
    int32_t m = 1 << 16;
    uint8_t buf1[m + 3], buf2[m + 3];
    uint32_t len1 = m + 3, len2 = m + 3;

    for (i = 1; i <= 20000L; i++) {
        rc = adp_cnt_offer(ctx, &i, sizeof(uint64_t));
        EXPECT_GE(rc, 0);
    }
    for (i = 10000L; i <= 30000L; i++) {
        rc = adp_cnt_offer(tbm1, &i, sizeof(uint64_t));
        EXPECT_GE(rc, 0);
    }
    rc = adp_cnt_get_raw_bytes(tbm1, buf1, &len1);
    EXPECT_EQ(rc, 0);
    for (i = 20000L; i <= 40000L; i++) {
        rc = adp_cnt_offer(tbm2, &i, sizeof(uint64_t));
        EXPECT_GE(rc, 0);
    }
    rc = adp_cnt_get_raw_bytes(tbm2, buf2, &len2);
    EXPECT_EQ(rc, 0);

    rc = adp_cnt_merge_raw_bytes(ctx, buf1, len1, buf2, len2, NULL);
    EXPECT_EQ(rc, 0);
    esti = adp_cnt_card(ctx);
    EXPECT_GT(esti, 0);
    printf("actual:40000, estimated: %9lu, error: %+7.2f%%\n",
           (long unsigned int)esti, (double)(esti - 40000) / 40000 * 100);

    rc = adp_cnt_fini(tbm2);
    EXPECT_EQ(rc, 0);
    rc = adp_cnt_fini(tbm1);
    EXPECT_EQ(rc, 0);
    rc = adp_cnt_fini(ctx);
    EXPECT_EQ(rc, 0);
}

/**
 * Tests serialize, unserialize and merge.
 *
 * <ol>
 * <li>Current context contains 1 to 20000</li>
 * <li>Tbm1 that contains 10000 to 30000 be serialized as buf1</li>
 * <li>Tbm2 that contains 20000 to 40000 be serialized as buf2</li>
 * <li>Merges buf1 and buf2 into current context</li>
 * </ol>
 * */
TEST(AdaptiveCounting, Merge)
{
    int rc;
    int64_t i, esti;
    adp_cnt_ctx_t *ctx = adp_cnt_init(NULL, 16, CCARD_HASH_LOOKUP3);
    EXPECT_NE(ctx, (adp_cnt_ctx_t *)NULL);
    adp_cnt_ctx_t *tbm1 = adp_cnt_init(NULL, 16, CCARD_HASH_LOOKUP3);
    EXPECT_NE(tbm1, (adp_cnt_ctx_t *)NULL);
    adp_cnt_ctx_t *tbm2 = adp_cnt_init(NULL, 16, CCARD_HASH_LOOKUP3);
    EXPECT_NE(tbm2, (adp_cnt_ctx_t *)NULL);
    int32_t m = 1 << 16;
    uint8_t buf1[m + 3], buf2[m + 3];
    uint32_t len1 = m + 3, len2 = m + 3;

    for (i = 1; i <= 20000L; i++) {
        rc = adp_cnt_offer(ctx, &i, sizeof(uint64_t));
        EXPECT_GE(rc, 0);
    }
    for (i = 10000L; i <= 30000L; i++) {
        rc = adp_cnt_offer(tbm1, &i, sizeof(uint64_t));
        EXPECT_GE(rc, 0);
    }
    rc = adp_cnt_get_bytes(tbm1, buf1, &len1);
    EXPECT_EQ(rc, 0);
    for (i = 20000L; i <= 40000L; i++) {
        rc = adp_cnt_offer(tbm2, &i, sizeof(uint64_t));
        EXPECT_GE(rc, 0);
    }
    rc = adp_cnt_get_bytes(tbm2, buf2, &len2);
    EXPECT_EQ(rc, 0);

    rc = adp_cnt_merge_bytes(ctx, buf1, len1, buf2, len2, NULL);
    EXPECT_EQ(rc, 0);
    esti = adp_cnt_card(ctx);
    EXPECT_GT(esti, 0);
    printf("actual:40000, estimated: %9lu, error: %+7.2f%%\n",
           (long unsigned int)esti, (double)(esti - 40000) / 40000 * 100);

    rc = adp_cnt_fini(tbm2);
    EXPECT_EQ(rc, 0);
    rc = adp_cnt_fini(tbm1);
    EXPECT_EQ(rc, 0);
    rc = adp_cnt_fini(ctx);
    EXPECT_EQ(rc, 0);
}

/**
 * Do some statistics on the bitmap buckets
 * */
TEST(AdaptiveCounting, BucketStats)
{
    int rc;
    int64_t i, esti;
    uint32_t len;
    uint8_t *bytes;
    int k = 13;
    adp_cnt_ctx_t *ctx = adp_cnt_init(NULL, k, CCARD_HASH_MURMUR);
    EXPECT_NE(ctx, (adp_cnt_ctx_t *)NULL);
    for(i = 1; i <= 10000L; i++) {
        rc = adp_cnt_offer(ctx, &i, sizeof(i));
        EXPECT_GE(rc, 0);
        if (i % 100 == 0) {
            int ucnt = 0;
            int exp_size;
            esti = adp_cnt_card(ctx);
            EXPECT_GT(esti, 0);

            // Count used buckets in bitmap
            rc = adp_cnt_get_raw_bytes(ctx, NULL, &len);
            EXPECT_EQ(rc, 0);
            bytes = (uint8_t *)calloc(len, 1);
            rc = adp_cnt_get_raw_bytes(ctx, bytes, &len);
            EXPECT_EQ(rc, 0);
            for(int j = 0; j < (int)len; j++) {
                if(bytes[j] != 0) {
                    ucnt++;
                }
            }

            // Calculate sparse storage costs: u*(log2(m)/8+1)
            exp_size = ((int)(k / 8.0 + 0.5) + 1) * ucnt;
            printf("actual: %6lu, estimated: %6lu, error: %+6.2f%%, "\
                   "used buckets: %6d, used bucket ratio: %+6.2f%%, "\
                   "expect sparse storage: %6d, expect bmp ratio: %+6.2f%%\n",
                   (long unsigned int)i, (long unsigned int)esti,
                   (double)(esti - i) / i * 100,
                   ucnt, (double)ucnt / len * 100,
                   exp_size, (double)exp_size / len * 100);
        }
    }
    rc = adp_cnt_fini(ctx);
    EXPECT_EQ(rc, 0);
}

// vi:ft=c ts=4 sw=4 fdm=marker et

