#include "zero_string.h"
#include "stdio.h"

void test_strlen() {
    printf("----test_strlen----\n");
    char *s = "good morning"; //12
    printf("%s has %d chars\n", s, strlen(s));

}

void test_strcmp() {
    printf("----test_strcmp----\n");
    char *s1 = "hello my love";
    char *s2 = "hello my Love";
    char *s3 = "hello my lover";

    printf("s1=>%s\n", s1);
    printf("s2=>%s\n", s2);
    printf("s3=>%s\n", s3);

    int cmp_rst = strcmp(s1, s2);
    if (cmp_rst > 0) {
        printf("s1 greater than s2\n");
    } else if (cmp_rst == 0) {
        printf("s1 equal s2\n");
    } else {
        printf("s1 less than s2\n");
    }

    cmp_rst = strcmp(s1, s3);
    if (cmp_rst > 0) {
        printf("s1 greater than s3\n");
    } else if (cmp_rst == 0) {
        printf("s1 equal s3\n");
    } else {
        printf("s1 less than s3\n");
    }
}

void test_strdup() {
    printf("----test_strdup----\n");

    char *s = "hello my world";
    char *d = strdup(s);
    printf("s address:%p \n", s);
    printf("d address:%p \n", d);
    printf("s [%s] is copy string by [%s] \n", d, s);
    free(d);
}

void test_strchr() {
    printf("----test_strchr----\n");
    char *s = "this is not dream";
    char d = 'd';
    char f = 'f';
    printf("src string:%s \n", s);
    printf("target d char:%c \n", d);
    printf("target f char:%c \n", f);

    char *p = strchr(s, d);
    printf("find '%c' in '%s'-->", d, s);
    if (p) {
        printf("result is [%s] \n", p);
    } else {
        printf("not found\n");
    }
    p = strchr(s, f);
    printf("find '%c' in '%s'-->", f, s);
    if (p) {
        printf("result is [%s] \n", p);
    } else {
        printf("not found\n");
    }
}

void test_strcpy() {
    printf("----test_strcpy----\n");
    char *s = "this is not dream";
    char d[40];
    printf("d is [%s] \n", strcpy(d, s));
}

void test_strcat() {
    printf("----test_strcat----\n");
    char d[100] = "oh my god ";
    char *s = "this is amazing";

    printf("d is [%s]\n", strcat(d, s));
}

void test_strstr() {
    printf("----test_strstr----\n");
    char *s1 = "hello morning";
    char *s2 = "mor";
    printf("s1:%s\n", s1);
    printf("s2:%s\n", s2);
    char *p = strstr(s1, s2);
    printf("strstr(s1, s2)-->%s\n", p);
}

void test_strtol() {
    printf("----test_strtol----\n");
    char *s16 = "0x12";
    char *s8 = "012";
    char *s10 = "12";
    char *ss = "1245ab34";
    char *stop;
    printf("strtol('%s',NULL,0)-->%d\n", s16, strtol(s16, NULL, 0));
    printf("strtol('%s',NULL,0)-->%d\n", s10, strtol(s10, NULL, 0));
    printf("strtol('%s',NULL,0)-->%d\n", s8, strtol(s8, NULL, 0));
    printf("strtol('%s',&strp,0)-->%d,stop is '%s'\n", ss, strtol(ss, &stop, 0), stop);

}

void test_memset() {
    printf("----test_memset----\n");
    char s[] = "good morning";

    printf("orginal string is '%s' \n", s);
    char *d = (char *) memset(s, 'G', 4);
    printf("orginal string is '%s' \n", s);
    printf("memset string is '%s' \n", d);
}

void test_memmove() {
    printf("----test_memmove----\n");
    char *s = "good morning";
    char d[20];
    memmove(d, s, 4);
    d[4] = STR_END;
    printf("orginal string is '%s',memmove(d,s,4)-->'%s'\n", s, d);
}

void test_memcmp() {
    printf("----test_memcmp----\n");
    char *s1 = "hello";
    char *s2 = "helle";
    memcmp(s1, s2, 5);
    printf("s1:'%s'\n", s1);
    printf("s2:'%s'\n", s2);
    printf("memcmp(s1,s2,5) -->%d \n", memcmp(s1, s2, 5));
    printf("memcmp(s2,s1,5) -->%d \n", memcmp(s2, s1, 5));
    printf("memcmp(s2,s1,3) -->%d \n", memcmp(s2, s1, 3));

}

int main() {

    test_strlen();
    test_strcmp();
    test_strdup();
    test_strchr();
    test_strcpy();
    test_strcat();
    test_strstr();
    test_strtol();
    test_memset();
    test_memmove();
    test_memcmp();
    return 0;
}