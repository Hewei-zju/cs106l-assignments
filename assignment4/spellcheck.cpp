#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(std::string& source) {
    //return a set of tokens
  /* TODO: Implement this method */
    auto its = find_all(source.begin(),source.end(),[](char c){return std::isspace(static_cast<unsigned char> (c));});
    std::set<Token> tokens;
    std::transform(its.begin(),its.end()-1,its.begin() + 1,std::inserter(tokens,tokens.end()),[&source](auto begin,auto end){return Token(source,begin,end);});
    std::erase_if(tokens,[](const Token& token){return token.content.empty();});
    return tokens;
}

std::set<Misspelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  /* TODO: Implement this method */
    namespace rv = std::ranges::views;
    auto view = source 
    | rv::filter([&dictionary](const Token &token){return !dictionary.contains(token.content);})
    | rv::transform([&dictionary](const Token &token){
        //lambda function that takes in token and return corresponding Misseplling
        auto view_inner = dictionary | rv::filter([&token](const std::string &word){return levenshtein(token.content,word) <= 1;});
        std::set<std::string> suggestions(view_inner.begin(),view_inner.end());
        return Misspelling{token,suggestions};
    })
    | rv::filter([](const Misspelling &m){return !m.suggestions.empty();});
    return std::set<Misspelling>(view.begin(),view.end());
};

/* Helper methods */

#include "utils.cpp"