#include "test.h"

START_TEST(s21_sub_1) {
  // -20507891368628113
  s21_decimal dec_1 = {{0x8c1e8f91, 0x48dbd1, 0x0, 0x80000000}};
  // 0.9189605063
  s21_decimal dec_2 = {{0x23be3ec7, 0x2, 0x0, 0xa0000}};
  // -20507891368628113.9189605063
  s21_decimal dec_check = {{0x1ad662c7, 0x2ffecc5b, 0xa9a326, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_2) {
  // 0.32507
  s21_decimal dec_1 = {{0x7efb, 0x0, 0x0, 0x50000}};
  // 31254352697817658
  s21_decimal dec_2 = {{0xe3cfa3a, 0x6f09ab, 0x0, 0x0}};
  // -31254352697817657.67493
  s21_decimal dec_check = {{0xcb504145, 0x6e20a299, 0xa9, 0x80050000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_3) {
  // -0.88729208172
  s21_decimal dec_1 = {{0xa8ac456c, 0x14, 0x0, 0x800b0000}};
  // -4399198091507995
  s21_decimal dec_2 = {{0x1f8a791b, 0xfa10c, 0x0, 0x80000000}};
  // 4399198091507994.11270791828
  s21_decimal dec_check = {{0x3f863294, 0xa3d959d1, 0x16be4a4, 0xb0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_4) {
  // 141371636.59
  s21_decimal dec_1 = {{0x4aa3ff8b, 0x3, 0x0, 0x20000}};
  // 75452
  s21_decimal dec_2 = {{0x126bc, 0x0, 0x0, 0x0}};
  // 141296184.59
  s21_decimal dec_check = {{0x4a30de1b, 0x3, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_5) {
  // 590316983739395
  s21_decimal dec_1 = {{0xe21ee403, 0x218e3, 0x0, 0x0}};
  // 9280629745491121780
  s21_decimal dec_2 = {{0x27ec1674, 0x80cb6b95, 0x0, 0x0}};
  // -9280039428507382385
  s21_decimal dec_check = {{0x45cd3271, 0x80c952b1, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_6) {
  // -7602174672765
  s21_decimal dec_1 = {{0x4ebbf7d, 0x6ea, 0x0, 0x80000000}};
  // 28786223871562741.63545
  s21_decimal dec_2 = {{0x8b4af59, 0xce92186, 0x9c, 0x50000}};
  // -28793826046235506.63545
  s21_decimal dec_check = {{0x41c4cb79, 0x1775f748, 0x9c, 0x80050000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_7) {
  // 653631616354.11798348
  s21_decimal dec_1 = {{0xd329294c, 0x8b189932, 0x3, 0x80000}};
  // 67.032017667621
  s21_decimal dec_2 = {{0x1b9a0625, 0x3cf7, 0x0, 0xc0000}};
  // 653631616287.085965812379
  s21_decimal dec_check = {{0x5c43229b, 0x70e01461, 0x8a69, 0xc0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_8) {
  // -964706959748769
  s21_decimal dec_1 = {{0x57a5eea1, 0x36d65, 0x0, 0x80000000}};
  // 2289385498156476678484496505.0
  s21_decimal dec_2 = {{0xb093a4ba, 0x61082311, 0x49f95a5d, 0x10000}};
  // -2289385498157441385444245274.0
  s21_decimal dec_check = {{0x1d0ef704, 0x612a6907, 0x49f95a5d, 0x80010000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_9) {
  // 2
  s21_decimal dec_1 = {{0x2, 0x0, 0x0, 0x0}};
  // -196074.16049754786
  s21_decimal dec_2 = {{0x4c9be2a2, 0x45a8d7, 0x0, 0x800b0000}};
  // 196076.16049754786
  s21_decimal dec_check = {{0xdd89b2a2, 0x45a905, 0x0, 0xb0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_10) {
  // -71
  s21_decimal dec_1 = {{0x47, 0x0, 0x0, 0x80000000}};
  // -188800206762.68749433
  s21_decimal dec_2 = {{0x41077279, 0x6034ec6, 0x1, 0x80080000}};
  // 188800206691.68749433
  s21_decimal dec_check = {{0x99d60b79, 0x6034ec4, 0x1, 0x80000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_11) {
  // 9441670.50102549289997759
  s21_decimal dec_1 = {{0xed0195bf, 0x65f9f8d7, 0xc7ef, 0x110000}};
  // 34529922439447457748
  s21_decimal dec_2 = {{0xe50e2fd4, 0xdf32ed82, 0x1, 0x0}};
  // -34529922439438016077.498974507
  s21_decimal dec_check = {{0x9af8812b, 0x3acfcd25, 0x6f927b7e, 0x80090000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_12) {
  // -8347659054993587160597
  s21_decimal dec_1 = {{0x35c1c615, 0x870a82b9, 0x1c4, 0x80000000}};
  // -42927
  s21_decimal dec_2 = {{0xa7af, 0x0, 0x0, 0x80000000}};
  // -8347659054993587117670
  s21_decimal dec_check = {{0x35c11e66, 0x870a82b9, 0x1c4, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_13) {
  // -85.327074228082361921
  s21_decimal dec_1 = {{0xa03cc641, 0xa026a9ed, 0x4, 0x80120000}};
  // -773662218127544961240486
  s21_decimal dec_2 = {{0xc6dc8da6, 0x50191ce4, 0xa3d4, 0x80000000}};
  // 773662218127544961240400.67293
  s21_decimal dec_check = {{0x492138dd, 0x51b695f0, 0xf9fbd6b8, 0x50000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_14) {
  // 1704736
  s21_decimal dec_1 = {{0x1a0320, 0x0, 0x0, 0x0}};
  // -6041993524016691544730.0
  s21_decimal dec_2 = {{0x2ed81a04, 0x5f0a6665, 0xccb, 0x80010000}};
  // 6041993524016693249466.0
  s21_decimal dec_check = {{0x2fdc3944, 0x5f0a6665, 0xccb, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_15) {
  // 6200605787336
  s21_decimal dec_1 = {{0xb0e7c4c8, 0x5a3, 0x0, 0x0}};
  // 6928.830
  s21_decimal dec_2 = {{0x69b9be, 0x0, 0x0, 0x30000}};
  // 6200605780407.170
  s21_decimal dec_check = {{0x8eef382, 0x16076b, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_16) {
  // 79228162514264337593088819637
  s21_decimal dec_1 = {{0xe4df41b5, 0xffffffff, 0xffffffff, 0x0}};
  // 7420231
  s21_decimal dec_2 = {{0x713947, 0x0, 0x0, 0x0}};
  // 79228162514264337593081399406
  s21_decimal dec_check = {{0xe46e086e, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_17) {
  // 1754
  s21_decimal dec_1 = {{0x6da, 0x0, 0x0, 0x0}};
  // 82025
  s21_decimal dec_2 = {{0x14069, 0x0, 0x0, 0x0}};
  // -80271
  s21_decimal dec_check = {{0x1398f, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_18) {
  // 65523939366770536549364
  s21_decimal dec_1 = {{0x4f8f0bf4, 0xf53ad5e, 0xde0, 0x0}};
  // 8100549735.315
  s21_decimal dec_2 = {{0xe63b393, 0x75e, 0x0, 0x30000}};
  // 65523939366762435999628.685
  s21_decimal dec_check = {{0xb862fd8d, 0xdedd3108, 0x36333b, 0x30000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_19) {
  // -4490958440729209960652.6806835
  s21_decimal dec_1 = {{0xf00bcb33, 0xfd88544a, 0x911c5668, 0x80070000}};
  // -86164425122
  s21_decimal dec_2 = {{0xfccc9a2, 0x14, 0x0, 0x80000000}};
  // -4490958440643045535530.6806835
  s21_decimal dec_check = {{0x53520e33, 0xf1932769, 0x911c5668, 0x80070000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_20) {
  // 25217629530077100166
  s21_decimal dec_1 = {{0xe9a57886, 0x5df70472, 0x1, 0x0}};
  // -46465176974206100869344.29305
  s21_decimal dec_2 = {{0x83103e79, 0x1a0ecefa, 0xf038265, 0x80050000}};
  // 46490394603736177969510.29305
  s21_decimal dec_check = {{0xa017b639, 0x2538a6be, 0xf059866, 0x50000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_21) {
  // -229093865842444193.12
  s21_decimal dec_1 = {{0x1ffcfaf0, 0x3dee7db8, 0x1, 0x80020000}};
  // 5373088832865928843451033
  s21_decimal dec_2 = {{0x58bd5a99, 0xbab1eed9, 0x471cb, 0x0}};
  // -5373089061959794685895226.12
  s21_decimal dec_check = {{0xc9f45eb4, 0x2b6fca9e, 0x1bc7396, 0x80020000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_22) {
  // 0.6
  s21_decimal dec_1 = {{0x6, 0x0, 0x0, 0x10000}};
  // -40990399.9263136480908270
  s21_decimal dec_2 = {{0x5e7253ee, 0xf0b92d5b, 0x56cc, 0x80100000}};
  // 40990400.5263136480908270
  s21_decimal dec_check = {{0x3b1953ee, 0xf0ce7e53, 0x56cc, 0x100000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_23) {
  // 9964269669976
  s21_decimal dec_1 = {{0xfcc10e58, 0x90f, 0x0, 0x0}};
  // -69197040090269
  s21_decimal dec_2 = {{0x30fe7c9d, 0x3eef, 0x0, 0x80000000}};
  // 79161309760245
  s21_decimal dec_check = {{0x2dbf8af5, 0x47ff, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_24) {
  // -8273498661
  s21_decimal dec_1 = {{0xed239225, 0x1, 0x0, 0x80000000}};
  // 3254806328.39867
  s21_decimal dec_2 = {{0xdd806ebb, 0x12805, 0x0, 0x50000}};
  // -11528304989.39867
  s21_decimal dec_check = {{0x446023db, 0x4187e, 0x0, 0x80050000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_25) {
  // -9623251831622477034857.51354
  s21_decimal dec_1 = {{0x8780203a, 0xb60ab704, 0x31c0448, 0x80050000}};
  // 7352201422754
  s21_decimal dec_2 = {{0xd15aa7a2, 0x6af, 0x0, 0x0}};
  // -9623251838974678457611.51354
  s21_decimal dec_check = {{0x7b89b17a, 0xc03ebdd7, 0x31c0448, 0x80050000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_26) {
  // -78223319980140134
  s21_decimal dec_1 = {{0xf0916666, 0x115e7b1, 0x0, 0x80000000}};
  // 83521951384
  s21_decimal dec_2 = {{0x724bd698, 0x13, 0x0, 0x0}};
  // -78223403502091518
  s21_decimal dec_check = {{0x62dd3cfe, 0x115e7c5, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_27) {
  // -938.18185
  s21_decimal dec_1 = {{0x5978d49, 0x0, 0x0, 0x80050000}};
  // 4427207830046911370
  s21_decimal dec_2 = {{0xa8c62b8a, 0x3d709a10, 0x0, 0x0}};
  // -4427207830046912308.18185
  s21_decimal dec_check = {{0x67c6ff89, 0xf115ab87, 0x5dbf, 0x80050000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_28) {
  // 3734568991833402935.5537573
  s21_decimal dec_1 = {{0xf3a7d4a5, 0xe8391b75, 0x1ee441, 0x70000}};
  // -7411.6770698
  s21_decimal dec_2 = {{0x41b42b8a, 0x11, 0x0, 0x80070000}};
  // 3734568991833410347.2308271
  s21_decimal dec_check = {{0x355c002f, 0xe8391b87, 0x1ee441, 0x70000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_29) {
  // -6604689102050011992
  s21_decimal dec_1 = {{0xc395ab58, 0x5ba891be, 0x0, 0x80000000}};
  // -913444396186910.798083644973
  s21_decimal dec_2 = {{0xa9a5de2d, 0xf084e6f1, 0x2f3955f, 0x800c0000}};
  // -6603775657653825081.2019163550
  s21_decimal dec_check = {{0x28f7c19e, 0x514d2edd, 0xd56126e5, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_30) {
  // -240089518
  s21_decimal dec_1 = {{0xe4f79ae, 0x0, 0x0, 0x80000000}};
  // 64521930998.34466171
  s21_decimal dec_2 = {{0x69dc1f7b, 0x598acb70, 0x0, 0x80000}};
  // -64762020516.34466171
  s21_decimal dec_check = {{0x1d540d7b, 0x59e01774, 0x0, 0x80080000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_31) {
  // -6351374102692
  s21_decimal dec_1 = {{0xcb65b0a4, 0x5c6, 0x0, 0x80000000}};
  // -102010113712628651
  s21_decimal dec_2 = {{0x6f56a3ab, 0x16a69a8, 0x0, 0x80000000}};
  // 102003762338525959
  s21_decimal dec_check = {{0xa3f0f307, 0x16a63e1, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_32) {
  // -934642647878930481366627353
  s21_decimal dec_1 = {{0x751af419, 0x7765cbdb, 0x3051e47, 0x80000000}};
  // 1947158
  s21_decimal dec_2 = {{0x1db616, 0x0, 0x0, 0x0}};
  // -934642647878930481368574511
  s21_decimal dec_check = {{0x7538aa2f, 0x7765cbdb, 0x3051e47, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_33) {
  // -164
  s21_decimal dec_1 = {{0xa4, 0x0, 0x0, 0x80000000}};
  // -475534076
  s21_decimal dec_2 = {{0x1c5812fc, 0x0, 0x0, 0x80000000}};
  // 475533912
  s21_decimal dec_check = {{0x1c581258, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_34) {
  // 792610.9
  s21_decimal dec_1 = {{0x78f15d, 0x0, 0x0, 0x10000}};
  // 6620223416.6
  s21_decimal dec_2 = {{0x69f5ed36, 0xf, 0x0, 0x10000}};
  // -6619430805.7
  s21_decimal dec_check = {{0x697cfbd9, 0xf, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_35) {
  // 801033603402754586148432740
  s21_decimal dec_1 = {{0x43356b64, 0xa6f3d25b, 0x2969976, 0x0}};
  // 1785347
  s21_decimal dec_2 = {{0x1b3e03, 0x0, 0x0, 0x0}};
  // 801033603402754586146647393
  s21_decimal dec_check = {{0x431a2d61, 0xa6f3d25b, 0x2969976, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_36) {
  // -6276339594
  s21_decimal dec_1 = {{0x7619578a, 0x1, 0x0, 0x80000000}};
  // -41435050783740982677000873439
  s21_decimal dec_2 = {{0xd076e5df, 0xd6c6017d, 0x85e2454b, 0x80000000}};
  // 41435050783740982670724533845
  s21_decimal dec_check = {{0x5a5d8e55, 0xd6c6017c, 0x85e2454b, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_37) {
  // 0
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x0}};
  // 132256437945882719
  s21_decimal dec_2 = {{0x9305d85f, 0x1d5de87, 0x0, 0x0}};
  // -132256437945882719
  s21_decimal dec_check = {{0x9305d85f, 0x1d5de87, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_38) {
  // -27731914452991267305325691
  s21_decimal dec_1 = {{0xa6fe847b, 0x184877a6, 0x16f076, 0x80000000}};
  // 11811
  s21_decimal dec_2 = {{0x2e23, 0x0, 0x0, 0x0}};
  // -27731914452991267305337502
  s21_decimal dec_check = {{0xa6feb29e, 0x184877a6, 0x16f076, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_39) {
  // 4230407454366901797583262120
  s21_decimal dec_1 = {{0xc21f11a8, 0xa04ce5df, 0xdab4f9f, 0x0}};
  // 239.47405
  s21_decimal dec_2 = {{0x16d688d, 0x0, 0x0, 0x50000}};
  // 4230407454366901797583261880.5
  s21_decimal dec_check = {{0x9536a735, 0x4300fabd, 0x88b11c3c, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_40) {
  // -626197096379384657.1995992401
  s21_decimal dec_1 = {{0x1e679151, 0x2639f47f, 0x143bc7ee, 0x800a0000}};
  // -1842.3932361
  s21_decimal dec_2 = {{0x4a26e5c9, 0x4, 0x0, 0x80070000}};
  // -626197096379382814.8063631401
  s21_decimal dec_check = {{0x7675f829, 0x2639e3bd, 0x143bc7ee, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_41) {
  // 55
  s21_decimal dec_1 = {{0x37, 0x0, 0x0, 0x0}};
  // -138708962722778921812978
  s21_decimal dec_2 = {{0x399fc3f2, 0x6d8d3cc9, 0x1d5f, 0x80000000}};
  // 138708962722778921813033
  s21_decimal dec_check = {{0x399fc429, 0x6d8d3cc9, 0x1d5f, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_42) {
  // 171570794933976818179403
  s21_decimal dec_1 = {{0xe5aadd4b, 0xdf160b6b, 0x2454, 0x0}};
  // 9010043402987100350996797041
  s21_decimal dec_2 = {{0xc4bbd671, 0x95da7c4f, 0x1d1ceee7, 0x0}};
  // -9009871832192166374178617638
  s21_decimal dec_check = {{0xdf10f926, 0xb6c470e3, 0x1d1cca92, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_43) {
  // -3581170614377
  s21_decimal dec_1 = {{0xce670069, 0x341, 0x0, 0x80000000}};
  // -8401196489422831708735
  s21_decimal dec_2 = {{0xf2a56a3f, 0x6e05afae, 0x1c7, 0x80000000}};
  // 8401196485841661094358
  s21_decimal dec_check = {{0x243e69d6, 0x6e05ac6d, 0x1c7, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_44) {
  // 9774334378992557
  s21_decimal dec_1 = {{0x909363ad, 0x22b9b4, 0x0, 0x0}};
  // 79228162514264337591414963455
  s21_decimal dec_2 = {{0x811a3cff, 0xffffffff, 0xffffffff, 0x0}};
  // -79228162514254563257035970898
  s21_decimal dec_check = {{0xf086d952, 0xffdd464a, 0xffffffff, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_45) {
  // -469935.34
  s21_decimal dec_1 = {{0x2cd107e, 0x0, 0x0, 0x80020000}};
  // -609396.864195113389877216
  s21_decimal dec_2 = {{0x78b67e0, 0x785f3e7e, 0x810b, 0x80120000}};
  // 139461.524195113389877216
  s21_decimal dec_check = {{0xf68d67e0, 0x3970aca1, 0x1d88, 0x120000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_46) {
  // -9460946
  s21_decimal dec_1 = {{0x905cd2, 0x0, 0x0, 0x80000000}};
  // 9356253122980143
  s21_decimal dec_2 = {{0x6fd2e92f, 0x213d76, 0x0, 0x0}};
  // -9356253132441089
  s21_decimal dec_check = {{0x70634601, 0x213d76, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_47) {
  // -55988501237915
  s21_decimal dec_1 = {{0xd6ba509b, 0x32eb, 0x0, 0x80000000}};
  // 7161690
  s21_decimal dec_2 = {{0x6d475a, 0x0, 0x0, 0x0}};
  // -55988508399605
  s21_decimal dec_check = {{0xd72797f5, 0x32eb, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_48) {
  // 488315
  s21_decimal dec_1 = {{0x7737b, 0x0, 0x0, 0x0}};
  // 878557765036.11748292
  s21_decimal dec_2 = {{0xbe36fc4, 0xc33e6b40, 0x4, 0x80000}};
  // -878557276721.11748292
  s21_decimal dec_check = {{0x93ad54c4, 0xc33e3ed6, 0x4, 0x80080000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_49) {
  // -872565386
  s21_decimal dec_1 = {{0x34024a8a, 0x0, 0x0, 0x80000000}};
  // 678548993789247646591201596
  s21_decimal dec_2 = {{0xce45b13c, 0xa9036052, 0x2314856, 0x0}};
  // -678548993789247647463766982
  s21_decimal dec_check = {{0x247fbc6, 0xa9036053, 0x2314856, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_50) {
  // 33.489027956
  s21_decimal dec_1 = {{0xcc1a0374, 0x7, 0x0, 0x90000}};
  // -65422446498812980267406
  s21_decimal dec_2 = {{0x79ca898e, 0x8ed493b1, 0xdda, 0x80000000}};
  // 65422446498812980267439.489028
  s21_decimal dec_check = {{0xbb6a0004, 0x2a9ed0a2, 0xd3642deb, 0x60000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_51) {
  // -2056907193769293774839
  s21_decimal dec_1 = {{0x9453fff7, 0x815252c5, 0x6f, 0x80000000}};
  // 9748569586909567
  s21_decimal dec_2 = {{0xbb4bc17f, 0x22a245, 0x0, 0x0}};
  // -2056916942338880684406
  s21_decimal dec_check = {{0x4f9fc176, 0x8174f50b, 0x6f, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_53) {
  // -3
  s21_decimal dec_1 = {{0x3, 0x0, 0x0, 0x80000000}};
  // 86031.6
  s21_decimal dec_2 = {{0xd209c, 0x0, 0x0, 0x10000}};
  // -86034.6
  s21_decimal dec_check = {{0xd20ba, 0x0, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_54) {
  // 785646553717315827225
  s21_decimal dec_1 = {{0x72757619, 0x97094212, 0x2a, 0x0}};
  // 9754997775735
  s21_decimal dec_2 = {{0x432d5d77, 0x8df, 0x0, 0x0}};
  // 785646543962318051490
  s21_decimal dec_check = {{0x2f4818a2, 0x97093933, 0x2a, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_55) {
  // -64817.03497015479957203808141
  s21_decimal dec_1 = {{0xa9c96f8d, 0xa4bfefff, 0x14f18a1a, 0x80170000}};
  // -5255062777575.1
  s21_decimal dec_2 = {{0x65805507, 0x2fcb, 0x0, 0x80010000}};
  // 5255062712758.0650298452004280
  s21_decimal dec_check = {{0xc70cdb8, 0xdc247406, 0xa9ccdc24, 0x100000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_56) {
  // -150486070
  s21_decimal dec_1 = {{0x8f83c36, 0x0, 0x0, 0x80000000}};
  // 2.49
  s21_decimal dec_2 = {{0xf9, 0x0, 0x0, 0x20000}};
  // -150486072.49
  s21_decimal dec_check = {{0x80f78611, 0x3, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_57) {
  // 157400456290024588668975002.4
  s21_decimal dec_1 = {{0x18ae2c08, 0x54761b66, 0x515fc6e, 0x10000}};
  // -69
  s21_decimal dec_2 = {{0x45, 0x0, 0x0, 0x80000000}};
  // 157400456290024588668975071.4
  s21_decimal dec_check = {{0x18ae2eba, 0x54761b66, 0x515fc6e, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_58) {
  // 758735559393297017953619721
  s21_decimal dec_1 = {{0x3d148f09, 0x1780ea8d, 0x2739c81, 0x0}};
  // 7186027.838309
  s21_decimal dec_2 = {{0x20a2fb65, 0x689, 0x0, 0x60000}};
  // 758735559393297017946433693.16
  s21_decimal dec_check = {{0xb132dd64, 0x2e5b9f2b, 0xf529226d, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_59) {
  // -46261083.1
  s21_decimal dec_1 = {{0x1b92e18f, 0x0, 0x0, 0x80010000}};
  // -80770074184655208033112146
  s21_decimal dec_2 = {{0x40e55052, 0x7ec18e47, 0x42cfba, 0x80000000}};
  // 80770074184655207986851062.9
  s21_decimal dec_check = {{0x6d6241a5, 0xf38f8ec8, 0x29c1d48, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_60) {
  // 659373715497938.474342861116
  s21_decimal dec_1 = {{0xd1a0c93c, 0xbdbb092e, 0x2216bd0, 0xc0000}};
  // -7054.55
  s21_decimal dec_2 = {{0xac3af, 0x0, 0x0, 0x80020000}};
  // 659373715504993.024342861116
  s21_decimal dec_check = {{0x3c6da53c, 0xbdd41942, 0x2216bd0, 0xc0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_61) {
  // -3021.59562
  s21_decimal dec_1 = {{0x120296ca, 0x0, 0x0, 0x80050000}};
  // -65111899565455744155869545815
  s21_decimal dec_2 = {{0x19a48557, 0x2d1f03c2, 0xd2634d0c, 0x80000000}};
  // 65111899565455744155869542793
  s21_decimal dec_check = {{0x19a47989, 0x2d1f03c2, 0xd2634d0c, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_62) {
  // 128728804782492423
  s21_decimal dec_1 = {{0x796bcb07, 0x1c9562a, 0x0, 0x0}};
  // 13560675844000
  s21_decimal dec_2 = {{0x57443fa0, 0xc55, 0x0, 0x0}};
  // 128715244106648423
  s21_decimal dec_check = {{0x22278b67, 0x1c949d5, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_63) {
  // -826054225265961326380
  s21_decimal dec_1 = {{0xac21d72c, 0xc7ce2541, 0x2c, 0x80000000}};
  // -0.3097
  s21_decimal dec_2 = {{0xc19, 0x0, 0x0, 0x80040000}};
  // -826054225265961326379.6903
  s21_decimal dec_check = {{0xe9e51aa7, 0xe48f5553, 0x6d53c, 0x80040000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_64) {
  // -765136.83
  s21_decimal dec_1 = {{0x48f8193, 0x0, 0x0, 0x80020000}};
  // 545511035750326995.25064
  s21_decimal dec_2 = {{0xc5a397c8, 0x38a3dd5b, 0xb8d, 0x50000}};
  // -545511035751092132.08064
  s21_decimal dec_check = {{0x9635be00, 0x38a3dd6d, 0xb8d, 0x80050000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_65) {
  // 36814963811
  s21_decimal dec_1 = {{0x9257c463, 0x8, 0x0, 0x0}};
  // -67837302267966
  s21_decimal dec_2 = {{0x9a4de03e, 0x3db2, 0x0, 0x80000000}};
  // 67874117231777
  s21_decimal dec_check = {{0x2ca5a4a1, 0x3dbb, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_66) {
  // -428077524749211430
  s21_decimal dec_1 = {{0x9f015726, 0x5f0d63d, 0x0, 0x80000000}};
  // 66602642598979653715806298458
  s21_decimal dec_2 = {{0xf05ea15a, 0xf457f63e, 0xd7346a29, 0x0}};
  // -66602642599407731240555509888
  s21_decimal dec_check = {{0x8f5ff880, 0xfa48cc7c, 0xd7346a29, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_67) {
  // 1886763796834006052
  s21_decimal dec_1 = {{0x3d5bb424, 0x1a2f21ad, 0x0, 0x0}};
  // 923677
  s21_decimal dec_2 = {{0xe181d, 0x0, 0x0, 0x0}};
  // 1886763796833082375
  s21_decimal dec_check = {{0x3d4d9c07, 0x1a2f21ad, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_68) {
  // 43.973417014788905815582
  s21_decimal dec_1 = {{0x52c4ce1e, 0xcdc021cd, 0x94f, 0x150000}};
  // 3511258543578565.209831461802
  s21_decimal dec_2 = {{0xb4c353aa, 0xe28b183, 0xb5871eb, 0xc0000}};
  // -3511258543578521.2364144470131
  s21_decimal dec_check = {{0x789f6873, 0x8d955f35, 0x7174732e, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_69) {
  // -913999349300658459856
  s21_decimal dec_1 = {{0xe3ec54d0, 0x8c49fd9c, 0x31, 0x80000000}};
  // -9070516909059193296
  s21_decimal dec_2 = {{0x35a5b9d0, 0x7de0f312, 0x0, 0x80000000}};
  // -904928832391599266560
  s21_decimal dec_check = {{0xae469b00, 0xe690a8a, 0x31, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_70) {
  // 3917269
  s21_decimal dec_1 = {{0x3bc5d5, 0x0, 0x0, 0x0}};
  // 83981760305262
  s21_decimal dec_2 = {{0x86fd986e, 0x4c61, 0x0, 0x0}};
  // -83981756387993
  s21_decimal dec_check = {{0x86c1d299, 0x4c61, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_71) {
  // 674.0100
  s21_decimal dec_1 = {{0x66d884, 0x0, 0x0, 0x40000}};
  // -19282693552913434473340
  s21_decimal dec_2 = {{0x283af37c, 0x51212649, 0x415, 0x80000000}};
  // 19282693552913434474014.0100
  s21_decimal dec_check = {{0x7f2df444, 0x1ee789b3, 0x9f80b1, 0x40000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_72) {
  // 0.90547433
  s21_decimal dec_1 = {{0x565a4e9, 0x0, 0x0, 0x80000}};
  // 4335132026.43
  s21_decimal dec_2 = {{0xef6683d3, 0x64, 0x0, 0x20000}};
  // -4335132025.52452567
  s21_decimal dec_check = {{0xfb94b5d7, 0x60425f5, 0x0, 0x80080000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_73) {
  // 53
  s21_decimal dec_1 = {{0x35, 0x0, 0x0, 0x0}};
  // -5557599194852530
  s21_decimal dec_2 = {{0x65d02cb2, 0x13be9b, 0x0, 0x80000000}};
  // 5557599194852583
  s21_decimal dec_check = {{0x65d02ce7, 0x13be9b, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_74) {
  // 8787561247971585398071438316
  s21_decimal dec_1 = {{0x2a1d2bec, 0xcb85da26, 0x1c64e679, 0x0}};
  // -5898212733486105422547
  s21_decimal dec_2 = {{0x50cead3, 0xbe250f09, 0x13f, 0x80000000}};
  // 8787567146184318884176860863
  s21_decimal dec_check = {{0x2f2a16bf, 0x89aae92f, 0x1c64e7b9, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_75) {
  // -661744747
  s21_decimal dec_1 = {{0x27716c6b, 0x0, 0x0, 0x80000000}};
  // -25143.41717880381030366300
  s21_decimal dec_2 = {{0x65fd7c5c, 0xbcd64ad9, 0x2146e, 0x80140000}};
  // -661719603.58282119618969633700
  s21_decimal dec_check = {{0xc1b283a4, 0xe75961f9, 0xd5d029a6, 0x80140000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_76) {
  // -4841484768.0167526129
  s21_decimal dec_1 = {{0xc707bef1, 0x9fe41773, 0x2, 0x800a0000}};
  // 11337
  s21_decimal dec_2 = {{0x2c49, 0x0, 0x0, 0x0}};
  // -4841496105.0167526129
  s21_decimal dec_check = {{0xc99bc2f1, 0x9fe47e8f, 0x2, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_77) {
  // -359135
  s21_decimal dec_1 = {{0x57adf, 0x0, 0x0, 0x80000000}};
  // 748916385635147185841
  s21_decimal dec_2 = {{0x5c67feb1, 0x994d7cce, 0x28, 0x0}};
  // -748916385635147544976
  s21_decimal dec_check = {{0x5c6d7990, 0x994d7cce, 0x28, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_78) {
  // 7400870417
  s21_decimal dec_1 = {{0xb9205211, 0x1, 0x0, 0x0}};
  // 9171234.065
  s21_decimal dec_2 = {{0x22a5ed11, 0x2, 0x0, 0x30000}};
  // 7391699182.935
  s21_decimal dec_check = {{0x39aa557, 0x6b9, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_79) {
  // -649096508781418
  s21_decimal dec_1 = {{0x8ed4b36a, 0x24e59, 0x0, 0x80000000}};
  // -89909283242049514340333546
  s21_decimal dec_2 = {{0xbafbb7ea, 0x2c92d8e, 0x4a5f08, 0x80000000}};
  // 89909283241400417831552128
  s21_decimal dec_check = {{0x2c270480, 0x2c6df35, 0x4a5f08, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_80) {
  // -97198
  s21_decimal dec_1 = {{0x17bae, 0x0, 0x0, 0x80000000}};
  // 69387249
  s21_decimal dec_2 = {{0x422c3f1, 0x0, 0x0, 0x0}};
  // -69484447
  s21_decimal dec_check = {{0x4243f9f, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_81) {
  // 881002465650
  s21_decimal dec_1 = {{0x1fd6c972, 0xcd, 0x0, 0x0}};
  // -8867
  s21_decimal dec_2 = {{0x22a3, 0x0, 0x0, 0x80000000}};
  // 881002474517
  s21_decimal dec_check = {{0x1fd6ec15, 0xcd, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_82) {
  // 98
  s21_decimal dec_1 = {{0x62, 0x0, 0x0, 0x0}};
  // 15
  s21_decimal dec_2 = {{0xf, 0x0, 0x0, 0x0}};
  // 83
  s21_decimal dec_check = {{0x53, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_83) {
  // -38982191261930508535153.07424
  s21_decimal dec_1 = {{0xcb75a9a0, 0x45abc9b1, 0xc988802, 0x80050000}};
  // 7410768012357
  s21_decimal dec_2 = {{0x7431e445, 0x6bd, 0x0, 0x0}};
  // -38982191269341276547510.07424
  s21_decimal dec_check = {{0x6c6572c0, 0x4ff49f1e, 0xc988802, 0x80050000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_84) {
  // 405447556467113126311
  s21_decimal dec_1 = {{0x2068e9a7, 0xfab71474, 0x15, 0x0}};
  // 5.384
  s21_decimal dec_2 = {{0x1508, 0x0, 0x0, 0x30000}};
  // 405447556467113126305.616
  s21_decimal dec_check = {{0x99d09f50, 0x5b27e59e, 0x55db, 0x30000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_85) {
  // 24.9
  s21_decimal dec_1 = {{0xf9, 0x0, 0x0, 0x10000}};
  // -673689261677
  s21_decimal dec_2 = {{0xdb02566d, 0x9c, 0x0, 0x80000000}};
  // 673689261701.9
  s21_decimal dec_check = {{0x8e17613b, 0x620, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_86) {
  // -629.6392935611436864323064210
  s21_decimal dec_1 = {{0x87ca1192, 0xfb0997eb, 0x14584110, 0x80190000}};
  // 26033722
  s21_decimal dec_2 = {{0x18d3e3a, 0x0, 0x0, 0x0}};
  // -26034351.639293561143686432306
  s21_decimal dec_check = {{0xb458632, 0x54247ac8, 0x541f1c66, 0x80150000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_87) {
  // -76
  s21_decimal dec_1 = {{0x4c, 0x0, 0x0, 0x80000000}};
  // 40.15711465483996
  s21_decimal dec_2 = {{0xaf6baedc, 0xe4444, 0x0, 0xe0000}};
  // -116.15711465483996
  s21_decimal dec_check = {{0x93b6aedc, 0x29446d, 0x0, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_88) {
  // -33176282340817890375
  s21_decimal dec_1 = {{0x7483ec47, 0xcc69d503, 0x1, 0x80000000}};
  // 9672883895040.103483162703717
  s21_decimal dec_2 = {{0xaca73765, 0xa8fe0b67, 0x1f4138d6, 0xf0000}};
  // -33176292013701785415.103483163
  s21_decimal dec_check = {{0xee5f0d1b, 0xd03e2627, 0x6b32c919, 0x80090000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_89) {
  // -8281879926504342282012
  s21_decimal dec_1 = {{0x1189df1c, 0xf62c19e0, 0x1c0, 0x80000000}};
  // -904177
  s21_decimal dec_2 = {{0xdcbf1, 0x0, 0x0, 0x80000000}};
  // -8281879926504341377835
  s21_decimal dec_check = {{0x117c132b, 0xf62c19e0, 0x1c0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_90) {
  // 0.2429973716114811089452
  s21_decimal dec_1 = {{0xff37722c, 0xbaa8dc40, 0x83, 0x160000}};
  // 0.8
  s21_decimal dec_2 = {{0x8, 0x0, 0x0, 0x10000}};
  // -0.5570026283885188910548
  s21_decimal dec_check = {{0xf5c88dd4, 0xf3a491ed, 0x12d, 0x80160000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_91) {
  // 37
  s21_decimal dec_1 = {{0x25, 0x0, 0x0, 0x0}};
  // -4533182357911.05
  s21_decimal dec_2 = {{0x606a1f01, 0x19c4a, 0x0, 0x80020000}};
  // 4533182357948.05
  s21_decimal dec_check = {{0x606a2d75, 0x19c4a, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_92) {
  // 5374104983295414702676
  s21_decimal dec_1 = {{0x23c31254, 0x54b04914, 0x123, 0x0}};
  // -60.6524840273455
  s21_decimal dec_2 = {{0x91a6e62f, 0x227a1, 0x0, 0x800d0000}};
  // 5374104983295414702736.6524840
  s21_decimal dec_check = {{0x344d37a8, 0x6eb92d9, 0xada58df5, 0x70000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_93) {
  // -4663220147407213
  s21_decimal dec_1 = {{0x8c65496d, 0x10912c, 0x0, 0x80000000}};
  // -79
  s21_decimal dec_2 = {{0x4f, 0x0, 0x0, 0x80000000}};
  // -4663220147407134
  s21_decimal dec_check = {{0x8c65491e, 0x10912c, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_94) {
  // 61960.918041306969505
  s21_decimal dec_1 = {{0xf131b5a1, 0x5be166ac, 0x3, 0xf0000}};
  // -48174815833885720339886327
  s21_decimal dec_2 = {{0x683d30f7, 0xffd2bda2, 0x27d969, 0x80000000}};
  // 48174815833885720339948287.918
  s21_decimal dec_check = {{0x32b8b7ae, 0x4f34c267, 0x9ba9460f, 0x30000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_95) {
  // -494256797407548
  s21_decimal dec_1 = {{0x20d6593c, 0x1c186, 0x0, 0x80000000}};
  // -68866.02893400480
  s21_decimal dec_2 = {{0x2f2b99a0, 0x187754, 0x0, 0x800b0000}};
  // -494256797338681.97106599520
  s21_decimal dec_check = {{0x135ac660, 0x779a86b8, 0x28e24b, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_96) {
  // 5892249892865708
  s21_decimal dec_1 = {{0x55cac6ac, 0x14eef8, 0x0, 0x0}};
  // 62029384299562
  s21_decimal dec_2 = {{0x576ab42a, 0x386a, 0x0, 0x0}};
  // 5830220508566146
  s21_decimal dec_check = {{0xfe601282, 0x14b68d, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_97) {
  // -891260
  s21_decimal dec_1 = {{0xd997c, 0x0, 0x0, 0x80000000}};
  // -351
  s21_decimal dec_2 = {{0x15f, 0x0, 0x0, 0x80000000}};
  // -890909
  s21_decimal dec_check = {{0xd981d, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_98) {
  // 0.26
  s21_decimal dec_1 = {{0x1a, 0x0, 0x0, 0x20000}};
  // -457674772903061
  s21_decimal dec_2 = {{0xb642f495, 0x1a040, 0x0, 0x80000000}};
  // 457674772903061.26
  s21_decimal dec_check = {{0x32278a4e, 0xa29947, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_99) {
  // -6.4380093446178
  s21_decimal dec_1 = {{0xa899b822, 0x3a8d, 0x0, 0x800d0000}};
  // 614763099355465526
  s21_decimal dec_2 = {{0x1e19c736, 0x88813c8, 0x0, 0x0}};
  // -614763099355465532.43800934462
  s21_decimal dec_check = {{0x44f3983e, 0x6cf361a0, 0xc6a402ff, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_100) {
  // 21418667661
  s21_decimal dec_1 = {{0xfca6ee8d, 0x4, 0x0, 0x0}};
  // -514820608847732853003714
  s21_decimal dec_2 = {{0xb09155c2, 0x7b2b2e86, 0x6d04, 0x80000000}};
  // 514820608847754271671375
  s21_decimal dec_check = {{0xad38444f, 0x7b2b2e8b, 0x6d04, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(fail_s21_sub_7) {
  // -864031796017116631
  s21_decimal dec_1 = {{0x343e35d7, 0xbfda857, 0x0, 0x80000000}};
  // 79228162514264337593223685674
  s21_decimal dec_2 = {{0xece9262a, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

Suite *s21_sub_cases(void) {
  Suite *c = suite_create("s21_sub_cases");
  TCase *tc = tcase_create("s21_sub_tc");

  tcase_add_test(tc, s21_sub_1);
  tcase_add_test(tc, s21_sub_2);
  tcase_add_test(tc, s21_sub_3);
  tcase_add_test(tc, s21_sub_4);
  tcase_add_test(tc, s21_sub_5);
  tcase_add_test(tc, s21_sub_6);
  tcase_add_test(tc, s21_sub_7);
  tcase_add_test(tc, s21_sub_8);
  tcase_add_test(tc, s21_sub_9);
  tcase_add_test(tc, s21_sub_10);
  tcase_add_test(tc, s21_sub_11);
  tcase_add_test(tc, s21_sub_12);
  tcase_add_test(tc, s21_sub_13);
  tcase_add_test(tc, s21_sub_14);
  tcase_add_test(tc, s21_sub_15);
  tcase_add_test(tc, s21_sub_16);
  tcase_add_test(tc, s21_sub_17);
  tcase_add_test(tc, s21_sub_18);
  tcase_add_test(tc, s21_sub_19);
  tcase_add_test(tc, s21_sub_20);
  tcase_add_test(tc, s21_sub_21);
  tcase_add_test(tc, s21_sub_22);
  tcase_add_test(tc, s21_sub_23);
  tcase_add_test(tc, s21_sub_24);
  tcase_add_test(tc, s21_sub_25);
  tcase_add_test(tc, s21_sub_26);
  tcase_add_test(tc, s21_sub_27);
  tcase_add_test(tc, s21_sub_28);
  tcase_add_test(tc, s21_sub_29);
  tcase_add_test(tc, s21_sub_30);
  tcase_add_test(tc, s21_sub_31);
  tcase_add_test(tc, s21_sub_32);
  tcase_add_test(tc, s21_sub_33);
  tcase_add_test(tc, s21_sub_34);
  tcase_add_test(tc, s21_sub_35);
  tcase_add_test(tc, s21_sub_36);
  tcase_add_test(tc, s21_sub_37);
  tcase_add_test(tc, s21_sub_38);
  tcase_add_test(tc, s21_sub_39);
  tcase_add_test(tc, s21_sub_40);
  tcase_add_test(tc, s21_sub_41);
  tcase_add_test(tc, s21_sub_42);
  tcase_add_test(tc, s21_sub_43);
  tcase_add_test(tc, s21_sub_44);
  tcase_add_test(tc, s21_sub_45);
  tcase_add_test(tc, s21_sub_46);
  tcase_add_test(tc, s21_sub_47);
  tcase_add_test(tc, s21_sub_48);
  tcase_add_test(tc, s21_sub_49);
  tcase_add_test(tc, s21_sub_50);
  tcase_add_test(tc, s21_sub_51);
  tcase_add_test(tc, s21_sub_53);
  tcase_add_test(tc, s21_sub_54);
  tcase_add_test(tc, s21_sub_55);
  tcase_add_test(tc, s21_sub_56);
  tcase_add_test(tc, s21_sub_57);
  tcase_add_test(tc, s21_sub_58);
  tcase_add_test(tc, s21_sub_59);
  tcase_add_test(tc, s21_sub_60);
  tcase_add_test(tc, s21_sub_61);
  tcase_add_test(tc, s21_sub_62);
  tcase_add_test(tc, s21_sub_63);
  tcase_add_test(tc, s21_sub_64);
  tcase_add_test(tc, s21_sub_65);
  tcase_add_test(tc, s21_sub_66);
  tcase_add_test(tc, s21_sub_67);
  tcase_add_test(tc, s21_sub_68);
  tcase_add_test(tc, s21_sub_69);
  tcase_add_test(tc, s21_sub_70);
  tcase_add_test(tc, s21_sub_71);
  tcase_add_test(tc, s21_sub_72);
  tcase_add_test(tc, s21_sub_73);
  tcase_add_test(tc, s21_sub_74);
  tcase_add_test(tc, s21_sub_75);
  tcase_add_test(tc, s21_sub_76);
  tcase_add_test(tc, s21_sub_77);
  tcase_add_test(tc, s21_sub_78);
  tcase_add_test(tc, s21_sub_79);
  tcase_add_test(tc, s21_sub_80);
  tcase_add_test(tc, s21_sub_81);
  tcase_add_test(tc, s21_sub_82);
  tcase_add_test(tc, s21_sub_83);
  tcase_add_test(tc, s21_sub_84);
  tcase_add_test(tc, s21_sub_85);
  tcase_add_test(tc, s21_sub_86);
  tcase_add_test(tc, s21_sub_87);
  tcase_add_test(tc, s21_sub_88);
  tcase_add_test(tc, s21_sub_89);
  tcase_add_test(tc, s21_sub_90);
  tcase_add_test(tc, s21_sub_91);
  tcase_add_test(tc, s21_sub_92);
  tcase_add_test(tc, s21_sub_93);
  tcase_add_test(tc, s21_sub_94);
  tcase_add_test(tc, s21_sub_95);
  tcase_add_test(tc, s21_sub_96);
  tcase_add_test(tc, s21_sub_97);
  tcase_add_test(tc, s21_sub_98);
  tcase_add_test(tc, s21_sub_99);
  tcase_add_test(tc, s21_sub_100);
  tcase_add_test(tc, fail_s21_sub_7);

  suite_add_tcase(c, tc);
  return c;
}