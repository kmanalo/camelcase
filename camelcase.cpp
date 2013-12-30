#include <iostream>
#include <string>
#include <boost/regex.hpp>
 
int main()
{
    std::string s = "Some people, when confronted with a problem, think "
        "\"I know, I'll use regular expressions.\" "
        "Now they have two problems.";
 
    boost::regex self_regex("REGULAR EXPRESSIONS",
        boost::regex_constants::ECMAScript | 
        boost::regex_constants::icase);
    if (boost::regex_search(s, self_regex)) {
        std::cout << "Text contains the phrase 'regular expressions'\n";
    }
 
    boost::regex word_regex("(\\S+)");
    auto words_begin = 
        boost::sregex_iterator(s.begin(), s.end(), word_regex);
    auto words_end = boost::sregex_iterator();
 
    std::cout << "Found "
        << std::distance(words_begin, words_end)
        << " words\n";
 
    const int N = 6;
    std::cout << "Words greater than " << N << " characters:\n";
    for (boost::sregex_iterator i = words_begin; i != words_end; ++i) {
        boost::smatch match = *i;
        std::string match_str = match.str();
        if (match_str.size() > N) {
            std::cout << "  " << match_str << '\n';
        }
    }
 
    boost::regex long_word_regex("(\\w{7,})");
    std::string new_s = boost::regex_replace(s, long_word_regex, "[$&]");
    std::cout << new_s << '\n';
}
