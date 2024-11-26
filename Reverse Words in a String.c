char* reverseWords(char* s) {
        int len = strlen(s);
    if (len == 0) return s;
    int left = 0, right = len - 1;
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
    int start = 0, end = 0;
    while (end <= len) {
        if (s[end] == ' ' || s[end] == '\0') {
            int wordLeft = start, wordRight = end - 1;
            while (wordLeft < wordRight) {
                char temp = s[wordLeft];
                s[wordLeft] = s[wordRight];
                s[wordRight] = temp;
                wordLeft++;
                wordRight--;
            }
            start = end + 1;  
        }
        end++;
    }
    int i = 0, j = 0;
    while (s[j]) {
        while (s[j] == ' ') {
            j++;
        }
        while (s[j] && s[j] != ' ') {
            s[i++] = s[j++];
        }
        while (s[j] == ' ') {
            j++;
        }
        if (s[j]) {
            s[i++] = ' ';
        }
    }
    s[i] = '\0';
    return s;
}
