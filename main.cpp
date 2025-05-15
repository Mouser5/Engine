#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include "subject.h"
#include "engine.h"

std::string read_file(const std::string& file_path) {
    std::ifstream file(file_path);
    if (!file) {
        std::cerr << "Failed to open the file: " << file_path << std::endl;
        return "";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::cout << "Input text: \n" << buffer.str() << std::endl;
    return buffer.str();
}

class Application {
private:
    Subject subject;
    Wrapper wrapper1;
    Wrapper wrapper2;
    Wrapper wrapper3;
    Wrapper wrapper4;
    Wrapper wrapper5;
    Engine engine;
    std::string text;

    int show_menu() {
        int choice = 0;
        while (true) {
            std::cout << "Choose a command:\n";
            std::cout << "1. Replace word\n";
            std::cout << "2. Search phrase\n";
            std::cout << "3. Capitalize words\n";
            std::cout << "4. Capitalize sentences\n";
            std::cout << "5. Add sentence numbers\n";
            std::cout << "6. Exit\n";
            std::cout << "Your choice: ";
            std::cin >> choice;

            if (choice < 1 || choice > 6) {
                std::cout << "Invalid input. Please enter a number between 1 and 6.\n\n";
            }
            else {
                return choice;
            }
        }
    }

    ArgsMap collect_args(int command) {
        ArgsMap args;
        std::string input1, input2;

        switch (command) {
        case 1:
            std::cout << "Enter word to replace: ";
            std::cin >> input1;
            std::cout << "Enter new word: ";
            std::cin >> input2;
            args = { {"sentence", text}, {"old_word", input1}, {"new_word", input2} };
            break;
        case 2:
            std::cin.ignore();
            std::cout << "Enter phrase to search: ";
            std::getline(std::cin, input1);
            args = { {"sentence", text}, {"phrase", input1} };
            break;
        case 3:
            args = { {"sentence", text} };
            break;
        case 4:
            args = { {"text", text} };
            break;
        case 5:
            args = { {"text", text} };
            break;
        default:
            break;
        }

        return args;
    }
public:
    Application(): 
        wrapper1(&subject, &Subject::replace_word, { {"sentence", ""}, {"old_word", ""}, {"new_word", ""} }),
        wrapper2(&subject, &Subject::search_phrase, { {"sentence", ""}, {"phrase", ""} }),
        wrapper3(&subject, &Subject::capitalize_words, { {"sentence", ""} }),
        wrapper4(&subject, &Subject::capitalize_sentences, { {"text", ""} }),
        wrapper5(&subject, &Subject::add_sentence_numbers, { {"text", ""} }) {
    }

    void run() {
        engine.registration(&wrapper1, "command1");
        engine.registration(&wrapper2, "command2");
        engine.registration(&wrapper3, "command3");
        engine.registration(&wrapper4, "command4");
        engine.registration(&wrapper5, "command5");

        text = read_file("text_r.txt");
        if (text.empty()) return;

        while (true) {
            int choice = show_menu();
            if (choice == 6) break;

            ArgsMap args = collect_args(choice);
            if (!args.empty()) {
                std::string result = engine.execute("command" + std::to_string(choice), args);
                std::cout << "\n--- Result ---\n" << result << "\n\n";
            }
        }
    }
};

int main() {
    Application app;
    app.run();
    return 0;
}
