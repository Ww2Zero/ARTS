#include "zero_string.h"

/**
 * 获取字符串的长度
 * @param str 字符串的指针
 * @return 字符串的长度
 */
int strlen(const char *str) {
    int n;
    for (n = 0; *str != STR_END; str++) {
        n++;
    }
    return n;
}

/**
 * 字符串p与字符串q的比较，比较字符串中每一位的ascii码
 * @param p
 * @param q
 * @return 大于0 则字符串p > 字符串q
 *         等于0 则字符串p = 字符串q
 *         小于0 则字符串p < 字符串q
 */
int strcmp(const char *p, const char *q) {
    //遍历相同的字符，向后移动指针
    while (*p && *p == *q) {
        p++;
        q++;
    }
    // 转为ascii进行比较
    return (int) ((unsigned char) *p - (unsigned char) *q);
}

/**
 * 复制字符串
 * @param src
 * @return 被复制字符串存放的指针
 */
char *strdup(const char *src) {

    if (!src) {
        return NULL;
    }
    char *p;
    p = malloc(strlen(src) + 1);
    if (!p) {
        return NULL;
    }

    return strcpy(p, src);
}

/**
 * 返回字符串src中字符c第一次出现位置
 * @param src
 * @param c
 * @return 目标字符第一次出现位置之后的字符串
 */
char *strchr(const char *src, char c) {
    while (*src) {
        if (*src == c) {
            return (char *) src;
        } else {
            src++;
        }
    }
    return NULL;
}

/**
 * 字符串复制
 * 调用前请确认目的和源指针是否都存在（不能为Null），请确认目标指针空间是否大于源字符串的空间。
 * @param dst
 * @param src
 * @return
 */
char *strcpy(char *dst, const char *src) {
    char *cp = dst;
    while ((*cp++ = *src++) != STR_END);
    return dst;
}

/**
 * 字符串拼接
 * 目标指针空间必须有足够的存储空间。
 * @param dst
 * @param src
 * @return
 */
char *strcat(char *dst, const char *src) {
    char *p = dst;
    while (*p) {
        p++;
    }
    while ((*p++ = *src++) != STR_END);
    return dst;
}

/**
 * 查找 str1中第一次包含str2字符串的位置指针。
 * @param str1
 * @param str2
 * @return
 */
char *strstr(const char *str1, const char *str2) {

    char *ret = NULL;
    while (*str1 != STR_END) {
        char *pdst = (char *) str1;
        char *psrc = (char *) str2;
        while (*pdst != *psrc) {
            pdst++;
        }
        ret = pdst;
        while (*pdst == *psrc) {
            pdst++;
            psrc++;
        }
        if (*psrc == STR_END) {
            return ret;
        }
        str1++;
    }
    return NULL;
}

/**
 * 字符串转化为数字
 * 将字符串str按照base的进制转为数字。
 * 若参数endptr不为NULL，则会将遇到不合条件而终止的str中的字符指针由endptr返回。
 * @param str
 * @param endptr
 * @param base
 * @return
 */
long strtol(const char *str, char **endptr, int base) {
    int neg = 0;
    long val = 0;
    // 去除空格
    while (*str == ' ' || *str == '\t') {
        str++;
    }
    // 获取符号，正数或负数
    if (*str == '+') {
        str++;
    } else if (*str == '-') {
        str++;
        neg = 1;
    }
    // 获取进制
    if ((base == 0 || base == 16) && (str[0] == '0' && str[1] == 'x')) {
        str += 2;
        base = 16;
    } else if (base == 0 && str[0] == '0') {
        str++;
        base = 8;
    } else {
        base = 10;
    }
    while (1) {
        int dig;
        if (*str >= '0' && *str <= '9') {
            dig = *str - '0';
        } else if (*str > 'a' && *str <= 'f') {
            dig = *str - 'a' + 10;
        } else if (*str > 'A' && *str <= 'F') {
            dig = *str - 'A' + 10;
        } else {
            break;
        }
        if (dig >= base) {
            break;
        }
        str++;
        val = val * base + dig;
    }
    if (endptr) {
        *endptr = (char *) str;
    }
    return (neg ? -val : val);
}


/**
 * 设置内存位置v开始的n个元素的值为c
 * @param dst 内存地址指针
 * @param val 设置的默认值
 * @param count 内存偏移量
 * @return
 */
void *memset(void *dst, int val, size_t count) {
    char *p = dst;
    char v = (char) val;
    while (count--) {
        *p++ = v;
    }
    return dst;

}

/**
 * 内存拷贝
 * 将src所指内存区域复制n个字节到dst所指到内存区域。
 * src和dst所指到内存区域可以重叠，但拷贝后src的内容会被修改。
 * @param dst
 * @param src
 * @param n
 * @return dst的指针
 */
void *memmove(void *dst, const void *src, size_t n) {
    const char *tmp_str = src;
    char *tmp_dst = dst;
    if (tmp_str < tmp_dst && tmp_str + n > tmp_dst) {
        tmp_str += n;
        tmp_dst += n;
        while (n--) {
            *(--tmp_dst) = *(--tmp_str);
        }
    } else {
        while (n--) {
            *(tmp_dst++) = *(tmp_str++);
        }
    }
    return dst;
}

/**
 * 内存比较前n个字节
 * @param p
 * @param q
 * @param n
 * @return
 */
int memcmp(const void *p, const void *q, size_t n) {

    const uint8_t *s1 = (const uint8_t *) p;
    const uint8_t *s2 = (const uint8_t *) q;
    while (n--) {
        if (*s1 != *s2) {
            return (int) *s1 - (int) *s2;
        }
        s1++;
        s2++;
    }
    return 0;
}