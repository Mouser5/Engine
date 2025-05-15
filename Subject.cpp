#include "subject.h"
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>

//std::string Subject2::add_sentence_numbers1(const std::string& text) {
//    std::string result = text;
//    std::stringstream output;
//    bool add_number = true;
//    int counter = 1;
//    for (char& ch : result) {
//        if (add_number) {
//            output << counter++ << ".)";
//            if (ch != ' ') {
//                output << ch;
//            }
//            add_number = false;
//        }
//        else if (ch == '.' || ch == '!' || ch == '?') {
//            output << ch << std::endl;
//            add_number = true;
//        }
//        else {
//            output << ch;
//        }
//    }
//
//    return output.str();
//}

std::string Subject::replace_word(const std::string& text, const std::string& old_word, const std::string& new_word) {
    if (old_word.empty()) {
        return text;
    }

    std::string result = text;
    size_t pos = 0;

    while ((pos = result.find(old_word, pos)) != std::string::npos) {
        result.replace(pos, old_word.length(), new_word);
        pos += new_word.length(); 
    }

    return result;
}
std::string Subject::search_phrase(const std::string& text, const std::string& phrase) {
    return text.find(phrase) != std::string::npos ? "Phrase found" : "Phrase not found";
}

std::string Subject::capitalize_words(const std::string& text) {
    std::string result = text;
    bool capitalize = true;
    for (char& ch : result) {
        if (ch==' ') {
            capitalize = true;
        }
        else if (capitalize && std::isalpha(ch)) {
            ch = std::toupper(ch);
            capitalize = false;
        }
    }
    return result;
}

std::string Subject::capitalize_sentences(const std::string& text) {
    std::string result = text;
    bool capitalize = true;
    for (char& ch : result) {
        if (capitalize && std::isalpha(ch)) {
            ch = std::toupper(ch);
            capitalize = false;
        }
        if (ch == '.' || ch == '!' || ch == '?') {
            capitalize = true;
        }
    }
    return result;
}

std::string Subject::add_sentence_numbers(const std::string& text) {
    std::string result = text;
    std::stringstream output;
    bool add_number=true;
    int counter = 1;
    for (char& ch : result) {
        if (add_number) {
            output << counter++ << ".)";
            if (ch != ' ') {
                output << ch;
            }
            add_number = false;
        }
        else if (ch == '.' || ch == '!' || ch == '?') {
            output << ch << std::endl;
            add_number = true;
        }        
        else {
            output << ch;
        }
    }
    
    return output.str();
}

