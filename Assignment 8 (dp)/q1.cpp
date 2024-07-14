int maxProjectValue(int N, vector<int>& values, vector<vector<string>>& required_languages, set<string>& known_languages) {
    int max_value = 0;
    
    for (int i = 0; i < N; ++i) {
        bool can_complete = true;
        for (const string& lang : required_languages[i]) {
            if (known_languages.find(lang) == known_languages.end()) {
                can_complete = false;
                break;
            }
        }
        if (can_complete) {
            max_value += values[i];
        }
    }
    
    return max_value;
}