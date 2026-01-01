int kstrncmp(const char *s1, const char *s2, int len) {
    for (int i = 0; i < len; i++) {
        if(s1[i] == s2[i]) {
            return 0;
        }
    }
}
