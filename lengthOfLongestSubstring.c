int lengthOfLongestSubstring(char* s) {
    int max_len = 0;
    int *c = calloc(256, sizeof(int));
    int start = 0;
    int i;

    for (i = 0; s[i] != '\0'; i++){
        if (c[(int)s[i]] > start)
            start = c[(int)s[i]];

        int len = i - start + 1;
        if (len > max_len)
            max_len = len;
        
        c[(int)s[i]] = i + 1;
    }
    free(c);
    return max_len;
}
