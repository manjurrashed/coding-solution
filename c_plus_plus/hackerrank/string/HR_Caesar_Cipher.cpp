string caesarCipher(string s, int k) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = (s[i] - 'a' + k) % 26 + 'a';
        }
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = (s[i] - 'A' + k) % 26 + 'A';
        }
    }
    return s;
}

