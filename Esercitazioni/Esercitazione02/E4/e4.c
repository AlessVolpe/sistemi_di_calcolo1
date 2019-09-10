// scrivere la soluzione qui...
int count_substrings(const char* s, const char* sub) {
    int sub_len = 0;
    while(sub[sub_len] != 0)
        sub_len++;

    int s_len = 0;
    while(s[s_len] != 0)
        s_len++;

    int i = 0;
    int j = 0;
    int counter = 0;
    while(i != s_len) {
        for(j; j < sub_len; j++) {
            s[i] == sub[j];
        }
        counter++;
        i++;
    }
    return counter;
}
