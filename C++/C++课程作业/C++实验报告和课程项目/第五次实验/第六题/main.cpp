//
//  main.cpp
//  six5
//
//  Created by Worlder on 2018/12/31.
//  Copyright © 2018 Worlder. All rights reserved.
//


#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <time.h>
#include <vector>

#include "split.h"

using namespace std;

typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;

Grammar read_grammar(istream& in) {
    Grammar ret;
    string line;
    
    while (getline(in, line)) {
        vector<string> entry = split(line);
        
        if (!entry.empty())
            ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
    }
    
    return ret;
}

void gen_aux(const Grammar&, const string&, vector<string>&, vector<string>&);

int nrand(int n) {
    if (n <= 0 || n > RAND_MAX)
        throw domain_error("Argument to nrand is out of range");
    
    const int bucket_size = RAND_MAX / n;
    int r;
    
    do r = rand() / bucket_size; while (r >= n);
    
    return r;
}

vector<string> gen_sentence(const Grammar& g) {
    vector<string> sentence;
    vector<string> tokens;
    tokens.push_back("<sentence>");
    
    while (!tokens.empty()) {
        string token = tokens.back();
        tokens.pop_back();
        gen_aux(g, token, sentence, tokens);
    }
    
    return sentence;
}

bool bracketed(const string& s) {
    return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

void gen_aux(const Grammar& g, const string& token,
             vector<string>& sentence, vector<string>& tokens) {
    if (!bracketed(token)) {
        sentence.push_back(token);
    } else {
        Grammar::const_iterator it = g.find(token);
        
        if (it == g.end())
            throw logic_error("empty rule");
        
        const Rule_collection& c = it->second;
        
        const Rule& r = c[nrand(c.size())];
        
        for (Rule::const_reverse_iterator i = r.rbegin(); i != r.rend(); ++i)
            tokens.push_back(*i);
    }
}

int main() {
    srand(time(NULL));
    
    vector<string> sentence = gen_sentence(read_grammar(cin));
    
    vector<string>::const_iterator it = sentence.begin();
    
    if (!sentence.empty()) {
        cout << *it;
        ++it;
    }
    
    while (it != sentence.end()) {
        cout << " " << *it;
        ++it;
    }
    
    cout << endl;
    
    return 0;
}

